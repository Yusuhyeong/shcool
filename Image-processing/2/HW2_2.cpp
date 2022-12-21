/*******************************************************/
/*             HW#2_2 : Piecewise-Linear Transform     */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 1��     */
/*                                                     */
/* ���� ���� : ��ϵ��� Ư�� �Լ��� ���� �����ϰ�      */
/*             ����� ���󿡼��� ����� ���� �� ��   */
/*             �����ϰ� ���̰� �Ѵ�                    */
/*******************************************************/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Gray-level Slicing
uchar computeOutput(uchar x, int A, int s1, int B, int s2, int option = 0);

int main() {
	Mat src = imread("Fig0310(b)(washed_out_pollen_image).tif", 0);
	Mat newImage1 = src.clone();
	Mat newImage2 = src.clone();
	int s;
	int A = 8, s1 = 8, B = 128, s2 = 128;
	for (int x = 0; x < src.rows; x++) {
		for (int y = 0; y < src.cols; y++) {
			s = computeOutput(src.at<uchar>(x, y), A, s1, B, s2, 2);
			newImage1.at<uchar>(x, y) = saturate_cast<uchar>(s);
			s = computeOutput(src.at<uchar>(x, y), A, s1, B, s2, 2);
			newImage2.at<uchar>(x, y) = saturate_cast<uchar>(s);
		}
	}
	double th2 = threshold(src, newImage2, 120, 255, THRESH_BINARY + THRESH_OTSU);
	imshow("src", src);
	imshow("result1", newImage1);
	imshow("result2", newImage2);
	waitKey(0);
	return 0;
}



uchar computeOutput(uchar x, int A, int s1, int B, int s2, int option) {
	uchar result = 0;
	switch (option) {
	case 0:
		if (A < x && x <= B) result = s2;
		else result = s1;
		break;
	case 1:
		if (A < x && x <= B) result = s2;
		else result = x;
		break;
	case 2: // r1~r2 ������ ���� 3, ������ ������ ���� 0.5
			// r2�̻��� ������ r1������ ������ �������� 2.5��ŭ y������ �����̵� ��Ų ����

		if (A < x && x <= B) result = 3 * x - 5;
		else if (A < x) result = 0.5 * x;
		else result = 0.5 * x + 2.5;
		break;
	}
	return result;
}