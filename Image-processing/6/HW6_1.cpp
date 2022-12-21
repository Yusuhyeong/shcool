/*******************************************************/
/*             HW#6_1 : �������� �����ϱ�              */
/*  �ۼ��� : ������          ��¥ : 2022�� 5�� 26��    */
/*                                                     */
/* ���� ���� : �������� ����� �����Ͽ� ����� Ȯ����  */
/*             ��.                                     */
/*             �̶� ������ ����� ���� ������ 2���� �� */
/*             �츦 ���� ����.                       */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-1.jpg", IMREAD_GRAYSCALE); // �������� �����ϱ�(��ü �ܺ� ����� salt ���� ����)
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	Size size(3, 3); // Ŀ���� ũ��� �����Ϸ��� �������� Ŀ���Ѵ�.

	Mat rectKernel = getStructuringElement(MORPH_RECT, size);  // 3 x 3 �������� �簢�� ������� ����
	cout << "rectKernel=" << rectKernel << endl;

	Mat crossKernel = getStructuringElement(MORPH_CROSS, size);  // 3 x 3 �������� ������ ������� ����
	cout << "crossKernel=" << crossKernel << endl;

	Mat ellipseKernel = getStructuringElement(MORPH_ELLIPSE, size);  // 3 x 3 �������� Ÿ���� ������� ����
	cout << "ellipseKernel=" << ellipseKernel << endl;

	int iterations = 1;	// �������� ó�� Ƚ��

	Point anchor(-1, -1);	// Ŀ���� �߽��� ����

	// ���� ������ ���� �ܺ� �������� �� ������ ����� ũ�⸦ ����

	Mat erodeImage;
	erode(srcImage, erodeImage, crossKernel, anchor, iterations);  // ħ�� ����
	imshow("ħ��", erodeImage);

	Mat erodil_Image;
	dilate(erodeImage, erodil_Image, crossKernel, anchor, iterations);  // ħ�� �� ��â(����), Ŀ�κ��� ���� ���� ������ ���
	imshow("ħ�� - ��â Image", erodil_Image);

	Mat opendil_Image;
	dilate(erodil_Image, opendil_Image, crossKernel, anchor, iterations);  // ���� �� ��â
	imshow("ħ�� - ��â - ��â Image", opendil_Image);

	Mat open_close_Image;
	erode(opendil_Image, open_close_Image, crossKernel, anchor, iterations);  // ���� �� ����, ��ο� ������ ���
	imshow("ħ�� - ��â - ��â - ħ�� Image", open_close_Image);

	Mat openImage;
	morphologyEx(srcImage, openImage, MORPH_OPEN, crossKernel, anchor, iterations); // ���� ���� �Լ�, Ŀ�κ��� ���� ���� ������ ���
	imshow("���� mage", openImage);

	Mat openclose_Image;
	morphologyEx(openImage, openclose_Image, MORPH_CLOSE, crossKernel, anchor, iterations); // ���� ���� �Լ�, ��ο� ������ ���
	imshow("���� - ���� Image", openclose_Image);

	waitKey();
	return 0;
}