/*******************************************************/
/*             HW#2_4 : Subtraction                    */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 1��     */
/*                                                     */
/* ���� ���� : ���� ������ ���� ��  ������ ���ϰ�    */
/*             ������ ������ ���� �� ���� ���� ���*/
/*             �� �������� �� �ѷ��ϰ� ���Ѵ�.       */
/*******************************************************/


#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("Fig0228(a)(angiography_mask_image).tif", IMREAD_GRAYSCALE);
	Mat image2 = imread("Fig0228(b)(angiography_live_ image).tif", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	double alpha = 0.6, beta = 0.7;

	Mat sub_img = abs(image1 - image2); // ���� 2���� ���ϱ� ���� ���� ����

	imshow("image1", image1), imshow("image2", image2);
	imshow("sub_img", sub_img);

	CV_Assert(sub_img.data); // ���� ����ó��

	// ��� ���� ó��
	Scalar avg = mean(sub_img) / 2.0; // ���� ���� ȭ�� ����� ����
	Mat dst4 = sub_img * 2.0 - avg[0]; // ���� ��� �̿� ��� ����

	imshow("�������", dst4);

	waitKey(0);
}

