/*******************************************************/
/*             HW#5_1 : Edge Detector                  */
/*  �ۼ��� : ������          ��¥ : 2022�� 5�� 9��     */
/*                                                     */
/* ���� ���� : ���� ���Ͽ� �ٸ� �����ڵ鿡 ���� �˰� */
/*             ������ �̿��Ͽ� � ������� �ٸ���    */
/*             ������ ����.                            */
/*             ��� ���� : sobel, laplacian, marr-hil  */
/*             reth�� ���� edge����                    */
/*******************************************************/

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void ZeroCrossing(Mat& src, Mat& dst, int threshold); // 0���� ��ġ ����

int main()
{
	Mat srcImage = imread("5_1.jpg", IMREAD_GRAYSCALE);
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	int ksize = 3;
	int ddepth = CV_32F; // ���̿� ���� �ڷ��� ����
	Mat dstGx, dstGy;
	Sobel(srcImage, dstGx, ddepth, 1, 0, ksize); // dx
	Sobel(srcImage, dstGy, ddepth, 0, 1, ksize); // dy

	int dtype = CV_8U;
	Mat dstImageGx;
	normalize(abs(dstGx), dstImageGx, 0, 255, NORM_MINMAX, dtype); // normalize�� ���� dstGx���밪

	int thresh = 100;
	threshold(abs(dstGx), dstImageGx, thresh, 255, THRESH_BINARY);
	imshow("dstImageGx", dstImageGx);

	Mat dstImageGy;
	normalize(abs(dstGy), dstImageGy, 0, 255, NORM_MINMAX, dtype); // normalize�� ���� dstGy���밪
	threshold(abs(dstGy), dstImageGy, thresh, 255, THRESH_BINARY);
	imshow("dstImageGy", dstImageGy);

	Mat dstMag;
	magnitude(dstGx, dstGy, dstMag);  // dstGx, dstGy ���밪�� ���� ��
	Mat dstImageGxy;
	normalize(dstMag, dstImageGxy, 0, 255, NORM_MINMAX, dtype);
	threshold(dstMag, dstImageGxy, thresh, 255, THRESH_BINARY);
	imshow("dstImageGxy", dstImageGxy);

	//////////////Laplacian & LOG////////////////
	ksize = 15;		//k size 15�� ����

	Mat lapImage0;		//Laplacian ������
	Laplacian(srcImage, lapImage0, CV_32F, ksize);
	imshow("Laplacian", lapImage0); //Laplacian �����ڸ� ������ ���

	// LOG(Laplacian of Gaussian) - Marr-Hildreth ���� ���� �˰���
	Mat blurImage;
	GaussianBlur(srcImage, blurImage, Size(ksize, ksize), 0.0);  // srcImage�� 15 x 15�� ����þ� ���ͷ� ������

	Mat lapImage;
	Laplacian(blurImage, lapImage, CV_32F, ksize);  // ����þ� ������ �� ���� ���� ���ö�þ� ���͸� ����

	Mat dstImage;
	ZeroCrossing(lapImage, dstImage, 10);  // ���ö�þ� ����� ���� �������� üũ

	imshow("Marr-Hildreth", dstImage);  //Marr-Hildreth ���� ���� �˰����� ������ ���

	waitKey();

	return 0;
}


// Laplacian�� ���� ���͸��� ���� ���� ����, ���� ���⿡ ���� �̿��� �����ϰ� ��ȣ�� �����Ǵ� 0���� ��ġ�� �����Ѵ�.
// ���̿� ���� ���밪�� �����ϰ� threshold�� ��ȣ�� ����Ǵ� ��ġ�� edge�� �����Ͽ� ���� �̹����� �ݿ��Ѵ�.
void ZeroCrossing(Mat& src, Mat& dst, int th)
{
	int x, y;
	double a, b;

	Mat zeroCrossH(src.size(), CV_32F, Scalar::all(0));  // ���� ������ 0���� ����
	 // src�� ������ ũ����, CV_32F�� �ڷ����� 0���� �ʱ�ȭ�� ��� ����

	Mat_<float> _src(src);	// src�� �����Ͽ� _src ����

	for (x = 1; x < src.rows - 1; x++)
	{
		for (y = 1; y < src.cols - 1; y++)
		{

			// (+.-), (-,+), (+,0,-), (-,0,+) �� ��츦 �����Ͽ� �����ϴ� ������ zeroCrossH�� ����

			a = _src(x, y); // ���� ������ ������ �� �ȼ� ����
			b = _src(x, y + 1);

			if (a == 0) // �ش� �ȼ��� ���� 0 �̸� �� ������ �ȼ��� �ٽ� ����.
						// (+,0,-) �Ǵ� (-,0,+)�� ��츦 �����ϱ� ����
				a = _src(x, y - 1);

			if (a * b < 0) // ���� ������ ������ �� �ȼ��� ��ȣ�� �ٸ��ٸ�
						   // �� �ȼ��� ���밪�� ���� ����
				zeroCrossH.at<float>(x, y) = fabs(a) + fabs(b);

			else // ���� ������ ������ �� �ȼ��� ��ȣ�� ������ 0 ����
				zeroCrossH.at<float>(x, y) = 0;
		}
	}

	Mat zeroCrossV(src.size(), CV_32F, Scalar::all(0)); // ���� ������ 0���� ����
	for (x = 1; x < src.rows - 1; x++)
	{
		for (y = 1; y < src.cols - 1; y++)
		{
			a = _src(x, y);
			b = _src(x + 1, y);

			if (a == 0)
				a = _src(x - 1, y);
			if (a * b < 0)
				zeroCrossV.at<float>(x, y) = fabs(a) + fabs(b);
			else
				zeroCrossV.at<float>(x, y) = 0;
		}
	}
	Mat zeroCross(src.size(), CV_32F, Scalar::all(0));
	add(zeroCrossH, zeroCrossV, zeroCross);  // zeroCross = zeroCrossH + zeroCrossV
	threshold(zeroCross, dst, th, 255, THRESH_BINARY);
}
