/*******************************************************/
/*             HW#5_1 : Edge Detector                  */
/*  작성자 : 유수형          날짜 : 2022년 5월 9일     */
/*                                                     */
/* 문제 정의 : 영상에 대하여 다른 연산자들에 대한 알고 */
/*             리즘을 이용하여 어떤 방식으로 다른지    */
/*             구별해 본다.                            */
/*             사용 연산 : sobel, laplacian, marr-hil  */
/*             reth를 통한 edge검출                    */
/*******************************************************/

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void ZeroCrossing(Mat& src, Mat& dst, int threshold); // 0교차 위치 검출

int main()
{
	Mat srcImage = imread("5_1.jpg", IMREAD_GRAYSCALE);
	if (srcImage.empty())
		return -1;
	imshow("srcImage", srcImage);

	int ksize = 3;
	int ddepth = CV_32F; // 깊이에 대한 자료형 변경
	Mat dstGx, dstGy;
	Sobel(srcImage, dstGx, ddepth, 1, 0, ksize); // dx
	Sobel(srcImage, dstGy, ddepth, 0, 1, ksize); // dy

	int dtype = CV_8U;
	Mat dstImageGx;
	normalize(abs(dstGx), dstImageGx, 0, 255, NORM_MINMAX, dtype); // normalize에 대한 dstGx절대값

	int thresh = 100;
	threshold(abs(dstGx), dstImageGx, thresh, 255, THRESH_BINARY);
	imshow("dstImageGx", dstImageGx);

	Mat dstImageGy;
	normalize(abs(dstGy), dstImageGy, 0, 255, NORM_MINMAX, dtype); // normalize에 대한 dstGy절대값
	threshold(abs(dstGy), dstImageGy, thresh, 255, THRESH_BINARY);
	imshow("dstImageGy", dstImageGy);

	Mat dstMag;
	magnitude(dstGx, dstGy, dstMag);  // dstGx, dstGy 절대값에 대한 합
	Mat dstImageGxy;
	normalize(dstMag, dstImageGxy, 0, 255, NORM_MINMAX, dtype);
	threshold(dstMag, dstImageGxy, thresh, 255, THRESH_BINARY);
	imshow("dstImageGxy", dstImageGxy);

	//////////////Laplacian & LOG////////////////
	ksize = 15;		//k size 15로 설정

	Mat lapImage0;		//Laplacian 연산자
	Laplacian(srcImage, lapImage0, CV_32F, ksize);
	imshow("Laplacian", lapImage0); //Laplacian 연산자만 적용한 결과

	// LOG(Laplacian of Gaussian) - Marr-Hildreth 에지 검출 알고리즘
	Mat blurImage;
	GaussianBlur(srcImage, blurImage, Size(ksize, ksize), 0.0);  // srcImage를 15 x 15의 가우시안 필터로 스무딩

	Mat lapImage;
	Laplacian(blurImage, lapImage, CV_32F, ksize);  // 가우시안 스무딩 된 영상에 대해 라플라시안 필터링 수행

	Mat dstImage;
	ZeroCrossing(lapImage, dstImage, 10);  // 라플라시안 결과에 대해 영교차점 체크

	imshow("Marr-Hildreth", dstImage);  //Marr-Hildreth 에지 검출 알고리즘을 적용한 결과

	waitKey();

	return 0;
}


// Laplacian에 대해 필터린된 영상에 대해 가로, 세로 방향에 대한 이웃을 조사하고 부호가 결정되는 0교차 위치를 검출한다.
// 차이에 대한 절대값을 저장하고 threshold로 부호가 변경되는 위치를 edge로 설정하여 변경 이미지에 반영한다.
void ZeroCrossing(Mat& src, Mat& dst, int th)
{
	int x, y;
	double a, b;

	Mat zeroCrossH(src.size(), CV_32F, Scalar::all(0));  // 가로 방향의 0교차 검출
	 // src와 동일한 크기의, CV_32F의 자료형에 0으로 초기화된 행렬 생성

	Mat_<float> _src(src);	// src를 복사하여 _src 생성

	for (x = 1; x < src.rows - 1; x++)
	{
		for (y = 1; y < src.cols - 1; y++)
		{

			// (+.-), (-,+), (+,0,-), (-,0,+) 인 경우를 검출하여 교차하는 정도를 zeroCrossH에 저장

			a = _src(x, y); // 가로 방향의 인접한 두 픽셀 선택
			b = _src(x, y + 1);

			if (a == 0) // 해당 픽셀의 값이 0 이면 그 왼쪽의 픽셀을 다시 선택.
						// (+,0,-) 또는 (-,0,+)인 경우를 검출하기 위함
				a = _src(x, y - 1);

			if (a * b < 0) // 가로 방향의 인접한 두 픽셀의 부호가 다르다면
						   // 두 픽셀의 절대값의 합을 저장
				zeroCrossH.at<float>(x, y) = fabs(a) + fabs(b);

			else // 가로 방향의 인접한 두 픽셀의 부호가 같으면 0 저장
				zeroCrossH.at<float>(x, y) = 0;
		}
	}

	Mat zeroCrossV(src.size(), CV_32F, Scalar::all(0)); // 세로 방향의 0교차 검출
	for (x = 1; x < src.rows - 1; x++)
	{
		for (y = 1; y < src.cols - 1; y++)
		{
			a = _src(x, y);
			b = _src(x + 1, y);

			if (a == 0)
				a = _src(x - 1, y);
			if (a * b < 0)
				zeroCrossV.at<float>(x, y) = fabs(a) + fabs(b);
			else
				zeroCrossV.at<float>(x, y) = 0;
		}
	}
	Mat zeroCross(src.size(), CV_32F, Scalar::all(0));
	add(zeroCrossH, zeroCrossV, zeroCross);  // zeroCross = zeroCrossH + zeroCrossV
	threshold(zeroCross, dst, th, 255, THRESH_BINARY);
}
