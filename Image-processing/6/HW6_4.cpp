/*******************************************************/
/*             HW#6_4 : Edge 검출하기                  */
/*  작성자 : 유수형          날짜 : 2022년 5월 26일    */
/*                                                     */
/* 문제 정의 : 모폴로지 기법을 적용하여 결과를 확인한  */
/*             다.                                     */
/*             팽창-침식연산에 대한 결과에 대해 함수   */
/*             를 통하여 결과를 도출한다.              */
/*******************************************************/

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-4.jpg", IMREAD_GRAYSCALE); // Edge 검출하기 (형태학적 기울기 연산)
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	Size size(2, 2); // 커널 크기에 따라 에지 두께가 달라진다

	Mat Kernel = getStructuringElement(MORPH_RECT, size);  // 사각형 구조요소 생성
	cout << "Kernel=" << Kernel << endl;

	int iterations = 1;	// 모폴로지 처리 횟수

	Point anchor(-1, -1);	// 커널의 중심점 설정


	Mat erodil_Image;
	dilate(srcImage, erodil_Image, Kernel, anchor, iterations);
	imshow("팽창 Image", erodil_Image);

	Mat erodeImage;
	erode(srcImage, erodeImage, Kernel, anchor, iterations);
	imshow("침식 Image", erodeImage);

	Mat dstImage;
	morphologyEx(srcImage, dstImage, MORPH_GRADIENT, Kernel, anchor, iterations); // 팽창 연산과 침식 연산 수행한 결과를 차 연산
	imshow("dstImage", dstImage);


	waitKey();
	return 0;
}