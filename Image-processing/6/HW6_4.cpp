/*******************************************************/
/*             HW#6_4 : Edge �����ϱ�                  */
/*  �ۼ��� : ������          ��¥ : 2022�� 5�� 26��    */
/*                                                     */
/* ���� ���� : �������� ����� �����Ͽ� ����� Ȯ����  */
/*             ��.                                     */
/*             ��â-ħ�Ŀ��꿡 ���� ����� ���� �Լ�   */
/*             �� ���Ͽ� ����� �����Ѵ�.              */
/*******************************************************/

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-4.jpg", IMREAD_GRAYSCALE); // Edge �����ϱ� (�������� ���� ����)
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	Size size(2, 2); // Ŀ�� ũ�⿡ ���� ���� �β��� �޶�����

	Mat Kernel = getStructuringElement(MORPH_RECT, size);  // �簢�� ������� ����
	cout << "Kernel=" << Kernel << endl;

	int iterations = 1;	// �������� ó�� Ƚ��

	Point anchor(-1, -1);	// Ŀ���� �߽��� ����


	Mat erodil_Image;
	dilate(srcImage, erodil_Image, Kernel, anchor, iterations);
	imshow("��â Image", erodil_Image);

	Mat erodeImage;
	erode(srcImage, erodeImage, Kernel, anchor, iterations);
	imshow("ħ�� Image", erodeImage);

	Mat dstImage;
	morphologyEx(srcImage, dstImage, MORPH_GRADIENT, Kernel, anchor, iterations); // ��â ����� ħ�� ���� ������ ����� �� ����
	imshow("dstImage", dstImage);


	waitKey();
	return 0;
}