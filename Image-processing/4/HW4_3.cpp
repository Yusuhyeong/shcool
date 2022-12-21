/*******************************************************/
/*             HW#4-3 : Noise Removal                  */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 27��    */
/*                                                     */
/* ���� ���� : ���Ƿ� ���� ���� ���Ͽ�               */
/*             salt-and-pepper, gaussian noise�� ����  */
/*             �غ��� ����� ���� ���� ���� �   */
/*             ���Ͱ� ����� �� ������ �� �ִ��� ��  */
/*             ���� ����.                              */
/*******************************************************/

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdlib.h> // srand �Լ� ����� ���ؼ�
#include <time.h> // time �Լ� ����� ���ؼ�
#include <iostream>

using namespace cv;
using namespace std;

void salt_pepper(Mat image, int n) // Salt-and-Pepper ���� �߰� �Լ�
{
	int i, j;
	srand((int)time(NULL));

	for (int k = 0; k < n; k++)
	{
		i = rand() % image.cols; // �̹����� ��ũ�� ������ ���� �� ����, x ��ǥ��
		j = rand() % image.rows; // �̹����� ��ũ�� ������ ���� �� ����, y ��ǥ��

		cout << "at (" << j << ", " << i << "), add salt or pepper!" << endl; // �����ϰ� ������ �ȼ� ��ġ ���, (x, y)

		int salt_or_pepper = (rand() % 2) * 255; // �����ϰ� 0 �Ǵ� 255, 0�̸� ����, 255�� �ұ�

		if (image.type() == CV_8UC1) // �׷��̷��� �����̶��
		{
			image.at<uchar>(j, i) = salt_or_pepper; // �����ϰ� ���õ� �ȼ��� 0 �Ǵ� 255�� ���� 
		}
	}
}

int main()
{
	Mat src = imread("./lena.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	//����þ� ���� ����
	Mat dst;

	imshow("lena", src); // ���� �̹���

	int stddev = 30; //ǥ������ = 30
	Mat noise(src.size(), CV_32SC1);
	randn(noise, 0, stddev);
	add(src, noise, dst, Mat(), CV_8U);
	imshow("gaussian noise, ǥ������ = " + to_string(stddev), dst); // gaussian noise

	boxFilter(src, dst, -1, Size(5, 5));
	imshow("������� at gaussian noise, ǥ������ = " + to_string(stddev), dst);

	bilateralFilter(src, dst, -1, 10, 10);
	imshow("��������� at gaussian noise, ǥ������ = " + to_string(stddev), dst);

	GaussianBlur(src, dst, Size(7, 7), 0.0);
	imshow("7*7, ǥ������=0 ����þ����� at gaussian noise, ǥ������ = " + to_string(stddev), dst);

	medianBlur(src, dst, (5, 5));
	imshow("5*5, �߾Ӱ����� at gaussian noise, ǥ������ = " + to_string(stddev), dst);

	salt_pepper(src, 5000);
	imshow("salt and pepper noise3", src); // salt and pepper noise

	boxFilter(src, dst, -1, Size(5, 5));
	imshow("������� at salt and pepper noise", dst);

	bilateralFilter(src, dst, -1, 10, 10);
	imshow("��������� at salt and pepper noise", dst);

	GaussianBlur(src, dst, Size(7, 7), 0.0);
	imshow("7*7, ǥ������=0 ����þ����� at salt and pepper noise", dst);

	medianBlur(src, dst, (5, 5));
	imshow("5*5, �߾Ӱ����� at salt and pepper noise", dst);

	waitKey();

	return 0;
}