/*******************************************************/
/*             HW#2_5 : Logic Operation                */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 1��     */
/*                                                     */
/* ���� ���� : ��Ʈ ������ ���� �� ������ ���ϰ�     */
/*             ����� ������ ���� ���ϴ� �κ��� ������ */
/*             Ȯ���Ѵ�.                               */
/*******************************************************/

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("Fig0230(a)(dental_xray).tif", IMREAD_GRAYSCALE); // ȯ���� ġ��
	Mat image2 = imread("Fig0230(b)(dental_xray_mask).tif", IMREAD_GRAYSCALE); // ȯ���� ġ�Ƹ� Ȯ���� �� �̹���
	CV_Assert(!(image1.empty() || image2.empty()));

	Mat sub_img = image1 & image2; // and���� ����
	imshow("sub_img", sub_img);

	waitKey(0);
}