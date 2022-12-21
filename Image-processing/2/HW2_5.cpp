/*******************************************************/
/*             HW#2_5 : Logic Operation                */
/*  작성자 : 유수형          날짜 : 2022년 4월 1일     */
/*                                                     */
/* 문제 정의 : 비트 연산을 통해 두 영상을 비교하고     */
/*             연산된 영상을 통해 원하는 부분의 영상을 */
/*             확인한다.                               */
/*******************************************************/

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1 = imread("Fig0230(a)(dental_xray).tif", IMREAD_GRAYSCALE); // 환자의 치아
	Mat image2 = imread("Fig0230(b)(dental_xray_mask).tif", IMREAD_GRAYSCALE); // 환자의 치아만 확인할 곳 이미지
	CV_Assert(!(image1.empty() || image2.empty()));

	Mat sub_img = image1 & image2; // and연산 적용
	imshow("sub_img", sub_img);

	waitKey(0);
}