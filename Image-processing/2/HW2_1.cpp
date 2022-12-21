/*******************************************************/
/*             HW#2_1 : Power Law                      */
/*  작성자 : 유수형          날짜 : 2022년 4월 1일     */
/*                                                     */
/* 문제 정의 : 거듭 제곱 변환을 통해 감마 조절을 하여  */
/*             영상의 밝기를 조절해준다.               */
/*             p=1 : 입력 r과 s가 동일                 */
/*             p<1 : 로그변환과 유사                   */
/*             p>1 : 역로그(inverse log) 변환과 유사   */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("Fig0308(a)(fractured_spine).tif", IMREAD_GRAYSCALE); // 소스코드 내의 파일에 있는 이미지 읽어 옴
	if (srcImage.empty())
		return -1;

	Mat fImage;
	srcImage.convertTo(fImage, CV_32F);    // 지수 계산하기 위해 CV_32F 자료형으로 변환

	double power = 1;
	// 감마 값 조절
	// double power = 0.3;
	// double power = 0.4;
	// double power = 0.6;
	Mat powImage;
	pow(fImage, power, powImage);  // 거듭제곱변환 : powImage = fImage ^ power


	double minVal, maxVal;
	minMaxLoc(powImage, &minVal, &maxVal);
	cout << "Before normalizing in powImage" << endl;
	cout << "minVal=" << minVal << endl;
	cout << "maxVal=" << maxVal << endl;

	normalize(powImage, powImage, 0, 1.0, NORM_MINMAX);
	minMaxLoc(powImage, &minVal, &maxVal);
	cout << "After normalizing in powImage" << endl;
	cout << "minVal=" << minVal << endl;
	cout << "maxVal=" << maxVal << endl;

	powImage.convertTo(powImage, 8U, 255.0 / (maxVal - minVal));
	imshow("powImage", powImage);

	waitKey();

	return 0;
}
