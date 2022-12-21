/*******************************************************/
/*             HW#3 : compareHistogram                 */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 14��    */
/*                                                     */
/* ���� ���� : 2���� ������ �׷� H1�� H2�� method      */
/*             ������� ���Ͽ� d(H1, H2)�� ��ȯ�Ѵ�  */
/*             �� method�� ���� �񱳹���� ���� ����   */
/*             �� �ǹ��ϴ��� �ۼ��Ѵ�                  */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void drawHistogram(Mat& image, Mat hist); // image�� ���� �Է����� output���� histogram�� ����ϴ� �Լ�

int main()
{
	// ���� �̹��� ���� 2��
	Mat srcImage1 = imread("imageEq1.jpg", IMREAD_GRAYSCALE);
	if (srcImage1.empty())
		return -1;
	Mat srcImage2 = imread("imageEq2.jpg", IMREAD_GRAYSCALE);
	if (srcImage2.empty())
		return -1;

	//�� �̹��� ���
	imshow("imageEq1", srcImage1);
	imshow("imageEq2", srcImage2);

	int histSize = 256;	// binsize�� 256�� ����
	float  valueRange[] = { 0, 256 }; // ȭ�Ұ� ���� 0���� 256����
	const  float* ranges[] = { valueRange };
	int channels = 0; // grayscale �ݿ�
	int dims = 1; // 1���� ���

	Mat H1;
	calcHist(&srcImage1, 1, &channels, Mat(), H1, dims, &histSize, ranges);
	// �Է� �̹����� imageEq1.jpg�� �� �̹����� ���� ������ �׷��� ��� �� H1�� ����Ѵ�.
	// ������� srcImage1�� ��� ȭ�Ҹ� ����Ѵ�.
	normalize(H1, H1, 1, 0, NORM_L1, CV_32F);
	// H1�� ���� ��� Ȯ���� ���� 1�� �������� ����ȭ ��Ų��.

	Mat H2;
	calcHist(&srcImage2, 1, &channels, Mat(), H2, dims, &histSize, ranges);
	// �Է� �̹����� imageEq2.jpg�� �� �̹����� ���� ������ �׷��� ��� �� H2�� ����Ѵ�.
	// ������� srcImage2�� ��� ȭ�Ҹ� ����Ѵ�
	normalize(H2, H2, 1, 0, NORM_L1, CV_32F);
	// H2�� ���� ��� Ȯ���� ���� 1�� �������� ����ȭ ��Ų��.

	//������׷� ��(method�� ���� ��� ��)
	double distl = compareHist(H1, H2, HISTCMP_CORREL); // method = CV_COMP_CORREL�� �� ������׷��� ������踦 ��Ÿ����.
	cout << "distl = " << distl << endl; // dist1 = 1 : ������, 0 : ���� ����, -1 : �ٸ�

	double dist2 = compareHist(H1, H2, HISTCMP_CHISQR); // method = CV_COMP_CHISQR�� �� ������׷��� ī�������� ���Ѵ�.
	cout << "dist2 = " << dist2 << endl; // dist2 = 0 : ������, infinity : �ٸ�

	double dist3 = compareHist(H1, H2, HISTCMP_INTERSECT); // method = CV_COMP_INTERSECT�� �� ������׷��� �������� ��Ÿ����.
	cout << "dist3 = " << dist3 << endl; // dist3 = ���� Ŭ ���� ����

	double dist4 = compareHist(H1, H2, HISTCMP_BHATTACHARYYA);// method = CV_COMP_BHATTACHARYYA�� �� ������׷��� bhattacharyya �Ÿ��� ��Ÿ����.
	cout << "dist4 = " << dist4 << endl; // dist = 0 : ������, ���� ���� ���� ����

	// �� ������׷��� ���
	Mat histImage1; // srcimage1�� �����ϴ� histImage1
	drawHistogram(histImage1, H1);
	imshow("histImage1", histImage1);

	Mat histImage2; // srcimage2�� �����ϴ� histImage2
	drawHistogram(histImage2, H2);
	imshow("histImage2", histImage2);

	waitKey();
	return 0;
}

// ������׷� ��� �Լ�
void drawHistogram(Mat& image, Mat hist)
{
	if (image.empty())
		image.create(450, 450, CV_8U); // ������׷��� 450*450ũ��� ���

	normalize(hist, hist, 0, image.rows, NORM_MINMAX, CV_32F); // 0���� image.rows�� ����, NORM_MINMAX�� ������ ������ ����ȭ ��Ŵ

	image = Scalar(255);//�̹��� ��� = �Ͼ��
	int binW = cvRound((double)image.cols / hist.rows);
	int x1, y1, x2, y2;
	for (int i = 0; i < hist.rows; i++)
	{
		x1 = i * binW;
		y1 = image.rows;
		x2 = (i + 1) * binW;
		y2 = image.rows - cvRound(hist.at<float>(i));
		rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0), -1); // fill black
	}
}