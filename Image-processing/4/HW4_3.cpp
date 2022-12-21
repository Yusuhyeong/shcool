/*******************************************************/
/*             HW#4-3 : Noise Removal                  */
/*  작성자 : 유수형          날짜 : 2022년 4월 27일    */
/*                                                     */
/* 문제 정의 : 임의로 받은 영상에 대하여               */
/*             salt-and-pepper, gaussian noise를 생성  */
/*             해보고 노이즈가 생긴 영상에 대해 어떤   */
/*             필터가 노이즈를 잘 제거할 수 있는지 분  */
/*             석해 본다.                              */
/*******************************************************/

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h> // srand 함수 사용을 위해서
#include <time.h> // time 함수 사용을 위해서
#include <iostream>

using namespace cv;
using namespace std;

void salt_pepper(Mat image, int n) // Salt-and-Pepper 영상 추가 함수
{
	int i, j;
	srand((int)time(NULL));

	for (int k = 0; k < n; k++)
	{
		i = rand() % image.cols; // 이미지의 열크기 내에서 랜덤 수 생성, x 좌표값
		j = rand() % image.rows; // 이미지의 행크기 내에서 랜덤 수 생성, y 좌표값

		cout << "at (" << j << ", " << i << "), add salt or pepper!" << endl; // 랜덤하게 결정된 픽셀 위치 출력, (x, y)

		int salt_or_pepper = (rand() % 2) * 255; // 랜덤하게 0 또는 255, 0이면 후추, 255면 소금

		if (image.type() == CV_8UC1) // 그레이레벨 영상이라면
		{
			image.at<uchar>(j, i) = salt_or_pepper; // 랜덤하게 선택된 픽셀에 0 또는 255을 대입 
		}
	}
}

int main()
{
	Mat src = imread("./lena.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	//가우시안 잡음 생성
	Mat dst;

	imshow("lena", src); // 원본 이미지

	int stddev = 30; //표준편차 = 30
	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, stddev);
	add(src, noise, dst, Mat(), CV_8U);
	imshow("gaussian noise, 표준편차 = " + to_string(stddev), dst); // gaussian noise

	boxFilter(src, dst, -1, Size(5, 5));
	imshow("평균필터 at gaussian noise, 표준편차 = " + to_string(stddev), dst);

	bilateralFilter(src, dst, -1, 10, 10);
	imshow("양방향필터 at gaussian noise, 표준편차 = " + to_string(stddev), dst);

	GaussianBlur(src, dst, Size(7, 7), 0.0);
	imshow("7*7, 표준편차=0 가우시안필터 at gaussian noise, 표준편차 = " + to_string(stddev), dst);

	medianBlur(src, dst, (5, 5));
	imshow("5*5, 중앙값필터 at gaussian noise, 표준편차 = " + to_string(stddev), dst);

	salt_pepper(src, 5000);
	imshow("salt and pepper noise3", src); // salt and pepper noise

	boxFilter(src, dst, -1, Size(5, 5));
	imshow("평균필터 at salt and pepper noise", dst);

	bilateralFilter(src, dst, -1, 10, 10);
	imshow("양방향필터 at salt and pepper noise", dst);

	GaussianBlur(src, dst, Size(7, 7), 0.0);
	imshow("7*7, 표준편차=0 가우시안필터 at salt and pepper noise", dst);

	medianBlur(src, dst, (5, 5));
	imshow("5*5, 중앙값필터 at salt and pepper noise", dst);

	waitKey();

	return 0;
}