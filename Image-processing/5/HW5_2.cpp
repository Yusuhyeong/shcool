/*******************************************************/
/*             HW#5_2 : 대각선 검출                    */
/*  작성자 : 유수형          날짜 : 2022년 5월 9일     */
/*                                                     */
/* 문제 정의 : 수직, 수평이 아닌 각도를 조절하여 다양  */
/*             한 각도에 대한 edge검출을 해본다.       */
/*             이때 검출하려는 방식을 sobel연산자의    */
/*             변형을 통해 마스크를 생성하여 적용해    */
/*             본다.                                   */
/*******************************************************/
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//// Sobel 연산자 알고리즘/////////
int main()
{
	Mat srcImage = imread("5_2.jpg", IMREAD_GRAYSCALE);
	if (srcImage.empty())
		return -1;

	resize(srcImage, srcImage, Size(540, 480));		//사진 크기 변경 540x480 사이즈
	imshow("srcImage", srcImage);
	
	int ksize = 3;
	int ddepth = CV_32F; // 깊이에 대한 자료형 변경
	
	Mat dstImage1;

	double maskdata[3][3] = { // 45도 마스크 생성
 		{2, -1, -1},
		{-1, 2, -1},
		{-1, -1, 2}
	};

	Mat mask = Mat(3, 3, CV_64FC1, maskdata);  //3x3, 64비트 float, 마스크(데이터)로 행렬 생성
	//filter2D를 이용하여 필터링함, 입력 이미지, 출력이미지, ddepth, Inputarray Kernel 순으로 파라미터 지정함
	filter2D(srcImage, dstImage1, -1, mask);
	imshow("45 degree", dstImage1);

	Mat dstImage2;

	double maskdata1[3][3] = { // -45도 마스크 생성
		{-1, -1, 2},
		{-1, 2, -1},
		{2, -1, -1}
	};

	Mat mask2 = Mat(3, 3, CV_64FC1, maskdata1);  //3x3, 64비트 float, 마스크(데이터)로 행렬 생성
	//filter2D를 이용하여 필터링함, 입력 이미지, 출력이미지, ddepth, Inputarray Kernel 순으로 파라미터 지정함
	filter2D(srcImage, dstImage2, -1, mask2);
	imshow("-45 degree", dstImage2);

	waitKey();
	return 0;
}