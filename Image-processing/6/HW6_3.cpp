/*******************************************************/
/*             HW#6_3 : 노이즈라 생각되는 영역 지우기  */
/*  작성자 : 유수형          날짜 : 2022년 5월 26일    */
/*                                                     */
/* 문제 정의 : 절차 형식의 모폴로지 기법을 실행하여    */
/*             결과를 확인해 본다.                     */
/*             이때 잡음이 제거되는 방향을 잘 본다.    */
/*******************************************************/

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-3.jpg", IMREAD_GRAYSCALE); // 노이즈라 생각되는 영역 지우기 (형태학적 스무딩 연산)
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	Size size(3, 3);
	Size size2(5, 5);
	Size size3(7, 7);

	Mat Kernel1 = getStructuringElement(MORPH_ELLIPSE, size);  // 3 x 3 사이즈의 타원형 구조요소 생성(반지름 1인 디스크 구조요소와 유사)
	cout << "Kernel1=" << Kernel1 << endl;

	Mat Kernel2 = getStructuringElement(MORPH_ELLIPSE, size2);  // 5 x 5 사이즈의 타원형 구조요소 생성(반지름 2인 디스크 구조요소와 유사)
	cout << "Kernel2=" << Kernel2 << endl;

	Mat Kernel3 = getStructuringElement(MORPH_ELLIPSE, size3);  // 7 x 7 사이즈의 타원형 구조요소 생성(반지름 3인 디스크 구조요소와 유사)
	cout << "Kernel3=" << Kernel3 << endl;


	int iterations = 1;	// 모폴로지 처리 횟수

	Point anchor(-1, -1);	// 커널의 중심점 설정

	// 각 커널에 대해 열림-닫힘 연산 수행

	Mat dstImage;
	morphologyEx(srcImage, dstImage, MORPH_OPEN, Kernel1, anchor, iterations);
	morphologyEx(dstImage, dstImage, MORPH_CLOSE, Kernel1, anchor, iterations);
	imshow("dstImage", dstImage);

	Mat dstImage2;
	morphologyEx(srcImage, dstImage2, MORPH_OPEN, Kernel2, anchor, iterations);
	morphologyEx(dstImage2, dstImage2, MORPH_OPEN, Kernel2, anchor, iterations);
	imshow("dstImage2", dstImage2);

	Mat dstImage3;
	morphologyEx(srcImage, dstImage3, MORPH_OPEN, Kernel3, anchor, iterations);
	morphologyEx(dstImage3, dstImage3, MORPH_OPEN, Kernel3, anchor, iterations);
	imshow("dstImage3", dstImage3);


	waitKey();
	return 0;
}