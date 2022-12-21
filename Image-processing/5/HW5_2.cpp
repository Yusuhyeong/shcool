/*******************************************************/
/*             HW#5_2 : �밢�� ����                    */
/*  �ۼ��� : ������          ��¥ : 2022�� 5�� 9��     */
/*                                                     */
/* ���� ���� : ����, ������ �ƴ� ������ �����Ͽ� �پ�  */
/*             �� ������ ���� edge������ �غ���.       */
/*             �̶� �����Ϸ��� ����� sobel��������    */
/*             ������ ���� ����ũ�� �����Ͽ� ������    */
/*             ����.                                   */
/*******************************************************/
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//// Sobel ������ �˰���/////////
int main()
{
	Mat srcImage = imread("5_2.jpg", IMREAD_GRAYSCALE);
	if (srcImage.empty())
		return -1;

	resize(srcImage, srcImage, Size(540, 480));		//���� ũ�� ���� 540x480 ������
	imshow("srcImage", srcImage);
	
	int ksize = 3;
	int ddepth = CV_32F; // ���̿� ���� �ڷ��� ����
	
	Mat dstImage1;

	double maskdata[3][3] = { // 45�� ����ũ ����
 		{2, -1, -1},
		{-1, 2, -1},
		{-1, -1, 2}
	};

	Mat mask = Mat(3, 3, CV_64FC1, maskdata);  //3x3, 64��Ʈ float, ����ũ(������)�� ��� ����
	//filter2D�� �̿��Ͽ� ���͸���, �Է� �̹���, ����̹���, ddepth, Inputarray Kernel ������ �Ķ���� ������
	filter2D(srcImage, dstImage1, -1, mask);
	imshow("45 degree", dstImage1);

	Mat dstImage2;

	double maskdata1[3][3] = { // -45�� ����ũ ����
		{-1, -1, 2},
		{-1, 2, -1},
		{2, -1, -1}
	};

	Mat mask2 = Mat(3, 3, CV_64FC1, maskdata1);  //3x3, 64��Ʈ float, ����ũ(������)�� ��� ����
	//filter2D�� �̿��Ͽ� ���͸���, �Է� �̹���, ����̹���, ddepth, Inputarray Kernel ������ �Ķ���� ������
	filter2D(srcImage, dstImage2, -1, mask2);
	imshow("-45 degree", dstImage2);

	waitKey();
	return 0;
}