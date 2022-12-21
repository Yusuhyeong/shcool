/*******************************************************/
/*             HW#2_3 : Bit Plane Slicing              */
/*  작성자 : 유수형          날짜 : 2022년 4월 1일     */
/*                                                     */
/* 문제 정의 : bit-slicing을 통해 원하는 비트의 영상을 */
/*             볼 수 있음으로써 상위 비트 일 수록 원   */
/*             래 영상과 비슷함을 알 수 있다.          */
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
	Mat out[8]; // 8개의 비트의 영상을 가져 옴


	for (int i = 0; i < 8; i++) { // 8개의 비트 분할된 영상
		out[i] = Mat(rows, cols, CV_8UC1, Scalar(0));
	}

	for (int i = 0; i < 8; i++) { // 분할된 영상 가져오기
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