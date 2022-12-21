/*******************************************************/
/*             HW#3 : compareHistogram                 */
/*  작성자 : 유수형          날짜 : 2022년 4월 14일    */
/*                                                     */
/* 문제 정의 : 2개의 히스토 그램 H1과 H2을 method      */
/*             방법으로 비교하여 d(H1, H2)를 반환한다  */
/*             각 method에 대한 비교방법에 따라 무엇   */
/*             을 의미하는지 작성한다                  */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void drawHistogram(Mat& image, Mat hist); // image에 대한 입력으로 output으로 histogram을 출력하는 함수

int main()
{
	// 비교할 이미지 사진 2개
	Mat srcImage1 = imread("imageEq1.jpg", IMREAD_GRAYSCALE);
	if (srcImage1.empty())
		return -1;
	Mat srcImage2 = imread("imageEq2.jpg", IMREAD_GRAYSCALE);
	if (srcImage2.empty())
		return -1;

	//비교 이미지 출력
	imshow("imageEq1", srcImage1);
	imshow("imageEq2", srcImage2);

	int histSize = 256;	// binsize를 256로 구성
	float  valueRange[] = { 0, 256 }; // 화소값 범위 0부터 256까지
	const  float* ranges[] = { valueRange };
	int channels = 0; // grayscale 반영
	int dims = 1; // 1차원 계산

	Mat H1;
	calcHist(&srcImage1, 1, &channels, Mat(), H1, dims, &histSize, ranges);
	// 입력 이미지는 imageEq1.jpg로 이 이미지에 대한 히스토 그램을 계산 후 H1에 출력한다.
	// 등간격으로 srcImage1의 모든 화소를 계산한다.
	normalize(H1, H1, 1, 0, NORM_L1, CV_32F);
	// H1에 대해 모든 확률의 합이 1이 나오도록 정규화 시킨다.

	Mat H2;
	calcHist(&srcImage2, 1, &channels, Mat(), H2, dims, &histSize, ranges);
	// 입력 이미지는 imageEq2.jpg로 이 이미지에 대한 히스토 그램을 계산 후 H2에 출력한다.
	// 등간격으로 srcImage2의 모든 화소를 계산한다
	normalize(H2, H2, 1, 0, NORM_L1, CV_32F);
	// H2에 대한 모든 확률의 합이 1이 나오도록 정규화 시킨다.

	//히스토그램 비교(method에 따른 결과 비교)
	double distl = compareHist(H1, H2, HISTCMP_CORREL); // method = CV_COMP_CORREL로 두 히스토그램의 상관관계를 나타낸다.
	cout << "distl = " << distl << endl; // dist1 = 1 : 동일함, 0 : 관계 없음, -1 : 다름

	double dist2 = compareHist(H1, H2, HISTCMP_CHISQR); // method = CV_COMP_CHISQR로 두 히스토그램의 카이제곱을 비교한다.
	cout << "dist2 = " << dist2 << endl; // dist2 = 0 : 동일함, infinity : 다름

	double dist3 = compareHist(H1, H2, HISTCMP_INTERSECT); // method = CV_COMP_INTERSECT로 두 히스토그램의 교차점을 나타낸다.
	cout << "dist3 = " << dist3 << endl; // dist3 = 값이 클 수록 유사

	double dist4 = compareHist(H1, H2, HISTCMP_BHATTACHARYYA);// method = CV_COMP_BHATTACHARYYA로 두 히스토그램의 bhattacharyya 거리를 나타낸다.
	cout << "dist4 = " << dist4 << endl; // dist = 0 : 동일함, 값이 작을 수록 유사

	// 두 히스토그램을 출력
	Mat histImage1; // srcimage1에 대응하는 histImage1
	drawHistogram(histImage1, H1);
	imshow("histImage1", histImage1);

	Mat histImage2; // srcimage2에 대응하는 histImage2
	drawHistogram(histImage2, H2);
	imshow("histImage2", histImage2);

	waitKey();
	return 0;
}

// 히스토그램 출력 함수
void drawHistogram(Mat& image, Mat hist)
{
	if (image.empty())
		image.create(450, 450, CV_8U); // 히스토그램을 450*450크기로 출력

	normalize(hist, hist, 0, image.rows, NORM_MINMAX, CV_32F); // 0부터 image.rows의 범위, NORM_MINMAX로 지정된 범위를 정규화 시킴

	image = Scalar(255);//이미지 배경 = 하얀색
	int binW = cvRound((double)image.cols / hist.rows);
	int x1, y1, x2, y2;
	for (int i = 0; i < hist.rows; i++)
	{
		x1 = i * binW;
		y1 = image.rows;
		x2 = (i + 1) * binW;
		y2 = image.rows - cvRound(hist.at<float>(i));
		rectangle(image, Point(x1, y1), Point(x2, y2), Scalar(0), -1); // fill black
	}
}