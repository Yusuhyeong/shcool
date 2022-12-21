/*******************************************************/
/*             HW#4-2 : Gaussian Smoothing Filtering   */
/*  작성자 : 유수형          날짜 : 2022년 4월 27일    */
/*                                                     */
/* 문제 정의 : 임의로 받은 영상에 대하여 윈도우u       */
/*             마스크에 대해 가우시안 스무딩 필터링    */
/*             을 적용시킨다.                          */
/*             이때 OpenCV에서 제공하는 함수를 사용한다*/
/*******************************************************/


#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("./lena.jpg", IMREAD_GRAYSCALE); // 이미지 흑백으로 불러오기

	if (srcImage.empty())
		return -1;

	// 마스크에 대한 커널 사이즈 설정 (홀수 설정)
	int ksize1 = 3;
	int ksize2 = 5;
	int ksize3 = 7;
	int ksize4 = 9;

	Mat dstImage1;
	Mat dstImage2;
	Mat dstImage3;
	Mat dstImage4;

	GaussianBlur(srcImage, dstImage1, Size(ksize1, ksize1), 0.0); // 3*3 크기의 Sigma = 0인 가우시안 필터 적용
	imshow("ksize = 3, sigmaX = sigmaY = 0.0", dstImage1);
	GaussianBlur(srcImage, dstImage1, Size(ksize1, ksize1), 1, 1); // ksize > 2 * sigma +1의 최소 홀수
	imshow("ksize = 3, sigmaX = 1, sigmaY = 1", dstImage1);

	GaussianBlur(srcImage, dstImage2, Size(ksize2, ksize2), 0.0); // 3*3 크기의 Sigma = 0인 가우시안 필터 적용
	imshow("ksize = 5, sigmaX = sigmaY = 0.0", dstImage2);
	GaussianBlur(srcImage, dstImage2, Size(ksize2, ksize2), 2, 2); // ksize > 2 * sigma +1의 최소 홀수
	imshow("ksize = 5, sigmaX = 2, sigmaY = 2", dstImage2);

	GaussianBlur(srcImage, dstImage3, Size(ksize3, ksize3), 0.0); // 3*3 크기의 Sigma = 0인 가우시안 필터 적용
	imshow("ksize = 7, sigmaX = sigmaY = 0.0", dstImage3);
	GaussianBlur(srcImage, dstImage3, Size(ksize3, ksize3), 3, 3); // ksize > 2 * sigma +1의 최소 홀수
	imshow("ksize = 7, sigmaX = 3, sigmaY = 3", dstImage3);


	Mat kx = getGaussianKernel(ksize4, 0.0);	// 9*1, SigmaX = 0의 1D 가우시안 커널 생성
	Mat ky = getGaussianKernel(ksize4, 0.0);	// 9*1, SigmaY = 0의 1D 가우시안 커널 생성
	Mat kxy = kx * ky.t();						// 9*9, SigmaX=SigmaY= 0 의 2D 가우시안 커널 생성

	filter2D(srcImage, dstImage4, -1, kxy);		//9*9, SigmaX=SigmaY= 0 의 2D 가우시안 필터로 컨볼루션
	imshow("ksize = 9", dstImage4);

	waitKey();

	return 0;
}