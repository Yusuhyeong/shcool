/*******************************************************/
/*             HW#2_1 : Power Law                      */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 1��     */
/*                                                     */
/* ���� ���� : �ŵ� ���� ��ȯ�� ���� ���� ������ �Ͽ�  */
/*             ������ ��⸦ �������ش�.               */
/*             p=1 : �Է� r�� s�� ����                 */
/*             p<1 : �α׺�ȯ�� ����                   */
/*             p>1 : ���α�(inverse log) ��ȯ�� ����   */
/*******************************************************/


#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat srcImage = imread("Fig0308(a)(fractured_spine).tif", IMREAD_GRAYSCALE); // �ҽ��ڵ� ���� ���Ͽ� �ִ� �̹��� �о� ��
	if (srcImage.empty())
		return -1;

	Mat fImage;
	srcImage.convertTo(fImage, CV_32F);    // ���� ����ϱ� ���� CV_32F �ڷ������� ��ȯ

	double power = 1;
	// ���� �� ����
	// double power = 0.3;
	// double power = 0.4;
	// double power = 0.6;
	Mat powImage;
	pow(fImage, power, powImage);  // �ŵ�������ȯ : powImage = fImage ^ power


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
