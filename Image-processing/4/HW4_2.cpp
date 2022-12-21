/*******************************************************/
/*             HW#4-2 : Gaussian Smoothing Filtering   */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 27��    */
/*                                                     */
/* ���� ���� : ���Ƿ� ���� ���� ���Ͽ� ������u       */
/*             ����ũ�� ���� ����þ� ������ ���͸�    */
/*             �� �����Ų��.                          */
/*             �̶� OpenCV���� �����ϴ� �Լ��� ����Ѵ�*/
/*******************************************************/


#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("./lena.jpg", IMREAD_GRAYSCALE); // �̹��� ������� �ҷ�����

	if (srcImage.empty())
		return -1;

	// ����ũ�� ���� Ŀ�� ������ ���� (Ȧ�� ����)
	int ksize1 = 3;
	int ksize2 = 5;
	int ksize3 = 7;
	int ksize4 = 9;

	Mat dstImage1;
	Mat dstImage2;
	Mat dstImage3;
	Mat dstImage4;

	GaussianBlur(srcImage, dstImage1, Size(ksize1, ksize1), 0.0); // 3*3 ũ���� Sigma = 0�� ����þ� ���� ����
	imshow("ksize = 3, sigmaX = sigmaY = 0.0", dstImage1);
	GaussianBlur(srcImage, dstImage1, Size(ksize1, ksize1), 1, 1); // ksize > 2 * sigma +1�� �ּ� Ȧ��
	imshow("ksize = 3, sigmaX = 1, sigmaY = 1", dstImage1);

	GaussianBlur(srcImage, dstImage2, Size(ksize2, ksize2), 0.0); // 3*3 ũ���� Sigma = 0�� ����þ� ���� ����
	imshow("ksize = 5, sigmaX = sigmaY = 0.0", dstImage2);
	GaussianBlur(srcImage, dstImage2, Size(ksize2, ksize2), 2, 2); // ksize > 2 * sigma +1�� �ּ� Ȧ��
	imshow("ksize = 5, sigmaX = 2, sigmaY = 2", dstImage2);

	GaussianBlur(srcImage, dstImage3, Size(ksize3, ksize3), 0.0); // 3*3 ũ���� Sigma = 0�� ����þ� ���� ����
	imshow("ksize = 7, sigmaX = sigmaY = 0.0", dstImage3);
	GaussianBlur(srcImage, dstImage3, Size(ksize3, ksize3), 3, 3); // ksize > 2 * sigma +1�� �ּ� Ȧ��
	imshow("ksize = 7, sigmaX = 3, sigmaY = 3", dstImage3);


	Mat kx = getGaussianKernel(ksize4, 0.0);	// 9*1, SigmaX = 0�� 1D ����þ� Ŀ�� ����
	Mat ky = getGaussianKernel(ksize4, 0.0);	// 9*1, SigmaY = 0�� 1D ����þ� Ŀ�� ����
	Mat kxy = kx * ky.t();						// 9*9, SigmaX=SigmaY= 0 �� 2D ����þ� Ŀ�� ����

	filter2D(srcImage, dstImage4, -1, kxy);		//9*9, SigmaX=SigmaY= 0 �� 2D ����þ� ���ͷ� �������
	imshow("ksize = 9", dstImage4);

	waitKey();

	return 0;
}