/*******************************************************/
/*             HW#6_2 : ���ϴ� ���� ���ֱ�             */
/*  �ۼ��� : ������          ��¥ : 2022�� 5�� 26��    */
/*                                                     */
/* ���� ���� : �������� ����� ����Ͽ� ���ϴ� ������  */
/*             ������ ����.                            */
/*             ppt�� �����ִ� ���� ��� �̿ܿ� �ٸ� �� */
/*             ������ �̿��Ͽ� �����Ͽ� ����.          */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-2.jpg", IMREAD_GRAYSCALE); // ���ϴ� ���� ���ֱ�
	if (srcImage.empty())
		return -1;

	//resize(srcImage, srcImage, Size(250, 250));
	imshow("srcImage", srcImage);


	Size size1(3, 3); // Ŀ���� ũ��� �����Ϸ��� �������� Ŀ���Ѵ�.
	Size size2(3, 1);
	Size size4(7, 7);
	Size size5(7, 1);
	Size size7(15, 15);
	Size size8(15, 1);
	Size size6(45, 45);

	Mat Kernel1 = getStructuringElement(MORPH_RECT, size1);  // 3 x 3 �������� Ÿ���� ������� ����(������ 1�� ��ũ�� ����)
	cout << "ellipseKernel=" << Kernel1 << endl;

	Mat Kernel2 = getStructuringElement(MORPH_RECT, size2);
	cout << "Kernel2=" << Kernel2 << endl;

	Mat Kernel4 = getStructuringElement(MORPH_RECT, size4);
	cout << "Kernel4=" << Kernel4 << endl;

	Mat Kernel5 = getStructuringElement(MORPH_RECT, size5);
	cout << "Kernel5=" << Kernel5 << endl;

	Mat Kernel6 = getStructuringElement(MORPH_RECT, size6);
	cout << "Kernel6=" << Kernel6 << endl;

	Mat Kernel7 = getStructuringElement(MORPH_RECT, size7);
	cout << "Kernel7=" << Kernel7 << endl;

	Mat Kernel8 = getStructuringElement(MORPH_RECT, size8);
	cout << "Kernel8=" << Kernel8 << endl;


	int iterations = 1;	// �������� ó�� Ƚ��

	Point anchor(-1, -1);	// Ŀ���� �߽��� ����

	Mat dstImage1;
	morphologyEx(srcImage, dstImage1, MORPH_OPEN, Kernel1, anchor, iterations); // �ּ� ���� ���� ����
	imshow("�ּ� ���� ���� ����", dstImage1);

	Mat dstImage2;
	morphologyEx(srcImage, dstImage2, MORPH_OPEN, Kernel2, anchor, iterations);
	imshow("�ּ� ���� �밢�� ����", dstImage2);

	Mat dstImage4;
	morphologyEx(srcImage, dstImage4, MORPH_OPEN, Kernel4, anchor, iterations); // �ִ� ���� ������ ������ ��� ���� ����
	imshow("ppt2��°", dstImage4);

	Mat dstImage5;
	morphologyEx(srcImage, dstImage5, MORPH_OPEN, Kernel5, anchor, iterations);
	imshow("�밢�� ����", dstImage5);
	
	Mat dstImage6;
	morphologyEx(srcImage, dstImage6, MORPH_OPEN, Kernel6, anchor, iterations); // ���μ��� �����ϰ� ��� ����
	imshow("ppt4��°", dstImage6);

	Mat dstImage7;
	morphologyEx(srcImage, dstImage7, MORPH_OPEN, Kernel7, anchor, iterations); // ��� ���� ����
	imshow("ppt3��°", dstImage7);

	Mat dstImage8;
	morphologyEx(srcImage, dstImage8, MORPH_OPEN, Kernel8, anchor, iterations); // ���μ��� �����ϰ� ��� ����
	imshow("���μ��� �����ϰ� ��� ����", dstImage8);

	waitKey();
	return 0;
}