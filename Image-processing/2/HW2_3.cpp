/*******************************************************/
/*             HW#2_3 : Bit Plane Slicing              */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 1��     */
/*                                                     */
/* ���� ���� : bit-slicing�� ���� ���ϴ� ��Ʈ�� ������ */
/*             �� �� �������ν� ���� ��Ʈ �� ���� ��   */
/*             �� ����� ������� �� �� �ִ�.          */
/*******************************************************/


#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

char print(int i) {
	char temp = (char)(i + '0');
	return temp;
}

int main()
{
	Mat m1 = imread("Fig0314(a)(100-dollars).tif", IMREAD_GRAYSCALE);
	imshow("Original", m1);
	int cols, rows, x, y;
	cols = m1.cols;
	rows = m1.rows;
	printf("%d %d \n", m1.rows, m1.cols);
	Mat out[8]; // 8���� ��Ʈ�� ������ ���� ��


	for (int i = 0; i < 8; i++) { // 8���� ��Ʈ ���ҵ� ����
		out[i] = Mat(rows, cols, CV_8UC1, Scalar(0));
	}

	for (int i = 0; i < 8; i++) { // ���ҵ� ���� ��������
		for (int x = 0; x < rows; x++) {
			for (int y = 0; y < cols; y++) {
				out[i].at<uchar>(x, y) = (m1.at<uchar>(x, y) & uchar(pow(2, i))) ? uchar(255) : uchar(0);
			}
		}
		string s = "dstImage";
		s += print(i);
		imshow(s, out[i]);
	}

	waitKey(0);

	return 0;
}