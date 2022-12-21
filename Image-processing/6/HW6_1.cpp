/*******************************************************/
/*             HW#6_1 : 지문영상 개선하기              */
/*  작성자 : 유수형          날짜 : 2022년 5월 26일    */
/*                                                     */
/* 문제 정의 : 모폴로지 기법을 적용하여 결과를 확인한  */
/*             다.                                     */
/*             이때 연산한 결과가 같게 나오는 2가지 경 */
/*             우를 비교해 본다.                       */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("HW6-1.jpg", IMREAD_GRAYSCALE); // 지문영상 개선하기(객체 외부 배경의 salt 잡음 제거)
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	Size size(3, 3); // 커널의 크기는 제거하려는 잡음보다 커야한다.

	Mat rectKernel = getStructuringElement(MORPH_RECT, size);  // 3 x 3 사이즈의 사각형 구조요소 생성
	cout << "rectKernel=" << rectKernel << endl;

	Mat crossKernel = getStructuringElement(MORPH_CROSS, size);  // 3 x 3 사이즈의 십자형 구조요소 생성
	cout << "crossKernel=" << crossKernel << endl;

	Mat ellipseKernel = getStructuringElement(MORPH_ELLIPSE, size);  // 3 x 3 사이즈의 타원형 구조요소 생성
	cout << "ellipseKernel=" << ellipseKernel << endl;

	int iterations = 1;	// 모폴로지 처리 횟수

	Point anchor(-1, -1);	// 커널의 중심점 설정

	// 열림 연산을 통해 외부 잡음제거 및 지문의 형상과 크기를 보존

	Mat erodeImage;
	erode(srcImage, erodeImage, crossKernel, anchor, iterations);  // 침식 연산
	imshow("침식", erodeImage);

	Mat erodil_Image;
	dilate(erodeImage, erodil_Image, crossKernel, anchor, iterations);  // 침식 후 팽창(열림), 커널보다 작은 밝은 디테일 억압
	imshow("침식 - 팽창 Image", erodil_Image);

	Mat opendil_Image;
	dilate(erodil_Image, opendil_Image, crossKernel, anchor, iterations);  // 열림 후 팽창
	imshow("침식 - 팽창 - 팽창 Image", opendil_Image);

	Mat open_close_Image;
	erode(opendil_Image, open_close_Image, crossKernel, anchor, iterations);  // 열림 후 닫힘, 어두운 디테일 억압
	imshow("침식 - 팽창 - 팽창 - 침식 Image", open_close_Image);

	Mat openImage;
	morphologyEx(srcImage, openImage, MORPH_OPEN, crossKernel, anchor, iterations); // 열림 연산 함수, 커널보다 작은 밝은 디테일 억압
	imshow("열림 mage", openImage);

	Mat openclose_Image;
	morphologyEx(openImage, openclose_Image, MORPH_CLOSE, crossKernel, anchor, iterations); // 열림 연산 함수, 어두운 디테일 억압
	imshow("열림 - 닫힘 Image", openclose_Image);

	waitKey();
	return 0;
}