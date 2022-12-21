/*******************************************************/
/*             HW#6_3 : ������� �����Ǵ� ���� �����  */
/*  �ۼ��� : ������          ��¥ : 2022�� 5�� 26��    */
/*                                                     */
/* ���� ���� : ���� ������ �������� ����� �����Ͽ�    */
/*             ����� Ȯ���� ����.                     */
/*             �̶� ������ ���ŵǴ� ������ �� ����.    */
/*******************************************************/

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-3.jpg", IMREAD_GRAYSCALE); // ������� �����Ǵ� ���� ����� (�������� ������ ����)
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	Size size(3, 3);
	Size size2(5, 5);
	Size size3(7, 7);

	Mat Kernel1 = getStructuringElement(MORPH_ELLIPSE, size);  // 3 x 3 �������� Ÿ���� ������� ����(������ 1�� ��ũ ������ҿ� ����)
	cout << "Kernel1=" << Kernel1 << endl;

	Mat Kernel2 = getStructuringElement(MORPH_ELLIPSE, size2);  // 5 x 5 �������� Ÿ���� ������� ����(������ 2�� ��ũ ������ҿ� ����)
	cout << "Kernel2=" << Kernel2 << endl;

	Mat Kernel3 = getStructuringElement(MORPH_ELLIPSE, size3);  // 7 x 7 �������� Ÿ���� ������� ����(������ 3�� ��ũ ������ҿ� ����)
	cout << "Kernel3=" << Kernel3 << endl;


	int iterations = 1;	// �������� ó�� Ƚ��

	Point anchor(-1, -1);	// Ŀ���� �߽��� ����

	// �� Ŀ�ο� ���� ����-���� ���� ����

	Mat dstImage;
	morphologyEx(srcImage, dstImage, MORPH_OPEN, Kernel1, anchor, iterations);
	morphologyEx(dstImage, dstImage, MORPH_CLOSE, Kernel1, anchor, iterations);
	imshow("dstImage", dstImage);

	Mat dstImage2;
	morphologyEx(srcImage, dstImage2, MORPH_OPEN, Kernel2, anchor, iterations);
	morphologyEx(dstImage2, dstImage2, MORPH_OPEN, Kernel2, anchor, iterations);
	imshow("dstImage2", dstImage2);

	Mat dstImage3;
	morphologyEx(srcImage, dstImage3, MORPH_OPEN, Kernel3, anchor, iterations);
	morphologyEx(dstImage3, dstImage3, MORPH_OPEN, Kernel3, anchor, iterations);
	imshow("dstImage3", dstImage3);


	waitKey();
	return 0;
}