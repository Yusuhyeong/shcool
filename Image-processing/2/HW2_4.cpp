/*******************************************************/
/*             HW#2_4 : Subtraction                    */
/*  작성자 : 유수형          날짜 : 2022년 4월 1일     */
/*                                                     */
/* 문제 정의 : 뺄셈 연산을 통해 두  영상을 비교하고    */
/*             영상의 뺀값에 대한 비교 영상에 대해 대비*/
/*             를 증가시켜 더 뚜렷하게 비교한다.       */
/*******************************************************/


#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("Fig0228(a)(angiography_mask_image).tif", IMREAD_GRAYSCALE);
	Mat image2 = imread("Fig0228(b)(angiography_live_ image).tif", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	double alpha = 0.6, beta = 0.7;

	Mat sub_img = abs(image1 - image2); // 영상 2개를 비교하기 위한 뺄셈 연산

	imshow("image1", image1), imshow("image2", image2);
	imshow("sub_img", sub_img);

	CV_Assert(sub_img.data); // 영상 예외처리

	// 대비 증가 처리
	Scalar avg = mean(sub_img) / 2.0; // 원본 영상 화소 평균의 절반
	Mat dst4 = sub_img * 2.0 - avg[0]; // 영상 평균 이용 대비 증가

	imshow("대비증가", dst4);

	waitKey(0);
}

