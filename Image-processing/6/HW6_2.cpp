/*******************************************************/
/*             HW#6_2 : 원하는 선분 없애기             */
/*  작성자 : 유수형          날짜 : 2022년 5월 26일    */
/*                                                     */
/* 문제 정의 : 모폴로지 기법을 사용하여 원하는 선분을  */
/*             제거해 본다.                            */
/*             ppt에 나와있는 실행 방법 이외에 다른 방 */
/*             법들을 이용하여 실행하여 본다.          */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-2.jpg", IMREAD_GRAYSCALE); // 원하는 선분 없애기
	if (srcImage.empty())
		return -1;

	//resize(srcImage, srcImage, Size(250, 250));
	imshow("srcImage", srcImage);


	Size size1(3, 3); // 커널의 크기는 제거하려는 잡음보다 커야한다.
	Size size2(3, 1);
	Size size4(7, 7);
	Size size5(7, 1);
	Size size7(15, 15);
	Size size8(15, 1);
	Size size6(45, 45);

	Mat Kernel1 = getStructuringElement(MORPH_RECT, size1);  // 3 x 3 사이즈의 타원형 구조요소 생성(반지름 1의 디스크와 유사)
	cout << "ellipseKernel=" << Kernel1 << endl;

	Mat Kernel2 = getStructuringElement(MORPH_RECT, size2);
	cout << "Kernel2=" << Kernel2 << endl;

	Mat Kernel4 = getStructuringElement(MORPH_RECT, size4);
	cout << "Kernel4=" << Kernel4 << endl;

	Mat Kernel5 = getStructuringElement(MORPH_RECT, size5);
	cout << "Kernel5=" << Kernel5 << endl;

	Mat Kernel6 = getStructuringElement(MORPH_RECT, size6);
	cout << "Kernel6=" << Kernel6 << endl;

	Mat Kernel7 = getStructuringElement(MORPH_RECT, size7);
	cout << "Kernel7=" << Kernel7 << endl;

	Mat Kernel8 = getStructuringElement(MORPH_RECT, size8);
	cout << "Kernel8=" << Kernel8 << endl;


	int iterations = 1;	// 모폴로지 처리 횟수

	Point anchor(-1, -1);	// 커널의 중심점 설정

	Mat dstImage1;
	morphologyEx(srcImage, dstImage1, MORPH_OPEN, Kernel1, anchor, iterations); // 최소 굵기 선분 제거
	imshow("최소 굵기 선분 제거", dstImage1);

	Mat dstImage2;
	morphologyEx(srcImage, dstImage2, MORPH_OPEN, Kernel2, anchor, iterations);
	imshow("최소 굵기 대각선 제거", dstImage2);

	Mat dstImage4;
	morphologyEx(srcImage, dstImage4, MORPH_OPEN, Kernel4, anchor, iterations); // 최대 굵기 선분을 제외한 모든 선분 제거
	imshow("ppt2번째", dstImage4);

	Mat dstImage5;
	morphologyEx(srcImage, dstImage5, MORPH_OPEN, Kernel5, anchor, iterations);
	imshow("대각선 제거", dstImage5);
	
	Mat dstImage6;
	morphologyEx(srcImage, dstImage6, MORPH_OPEN, Kernel6, anchor, iterations); // 가로선을 제외하고 모두 제거
	imshow("ppt4번째", dstImage6);

	Mat dstImage7;
	morphologyEx(srcImage, dstImage7, MORPH_OPEN, Kernel7, anchor, iterations); // 모든 선분 제거
	imshow("ppt3번째", dstImage7);

	Mat dstImage8;
	morphologyEx(srcImage, dstImage8, MORPH_OPEN, Kernel8, anchor, iterations); // 가로선을 제외하고 모두 제거
	imshow("가로선을 제외하고 모두 제거", dstImage8);

	waitKey();
	return 0;
}