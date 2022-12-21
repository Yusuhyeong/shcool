/*******************************************************/
/*             HW#4-1 : Convolution                    */
/*  �ۼ��� : ������          ��¥ : 2022�� 4�� 27��    */
/*                                                     */
/* ���� ���� : ���Ƿ� ���� ���� ���Ͽ� ������u       */
/*             ����ũ�� �ڽ�, ����þ�, ������, ����   */
/*             ����, ���� ����, ����� ������� ����   */
/*******************************************************/


#include <opencv2/opencv.hpp>
#include <string.h>

using namespace cv;
using namespace std;

int main()
{
    Mat srcImage = imread("./lena.jpg", IMREAD_GRAYSCALE); // �̹��� �б�
    if (srcImage.empty())
        return -1;

    imshow("lena", srcImage); // �����̹��� ���


    // ������ ����ũ�� �Է�
    Mat boxMask = (Mat_<float>(3, 3) << 1. / 9., 1. / 9., 1. / 9.,              //�ڽ� ����ũ
        1. / 9., 1. / 9., 1. / 9.,
        1. / 9., 1. / 9., 1. / 9.);

    Mat gaussianMask = (Mat_<float>(5, 5) << 0., 0., .0002, 0., 0.,             //����þ� ����ũ
        0., .0113, .0837, .0113, 0.,
        .0002, .0837, .6187, .0837, .0002,
        0., .0113, .0837, .0113, 0.,
        0., 0., .0002, 0., 0.);

    Mat sharpeningMask = (Mat_<float>(3, 3) << 0., -1., 0.,                     //������ ����ũ
        -1., 5., -1.,
        0., -1., 0.);


    Mat horizontalMask = (Mat_<float>(3, 3) << 1., 1., 1.,                      //���� ����ũ
        0., 0., 0.,
        -1., -1., -1.);

    Mat verticalMask = (Mat_<float>(3, 3) << 1., 0., -1.,                       //���� ����ũ
        1., 0., -1.,
        1., 0., -1.);

    Mat motionMask = (Mat_<float>(5, 5) << .0304, .0501, 0, 0, 0,               //��� ����ũ
        .0501, .1771, .0519, 0, 0,
        0, .0519, .1771, .0519, 0,
        0, 0, .0519, .1771, .0501,
        0, 0, 0, .0501, .0304);

    //����ũ ���� �ڷ��� ��ȯ
    boxMask.convertTo(boxMask, CV_32F);
    gaussianMask.convertTo(gaussianMask, CV_32F);
    sharpeningMask.convertTo(sharpeningMask, CV_32F);
    horizontalMask.convertTo(horizontalMask, CV_32F);
    verticalMask.convertTo(verticalMask, CV_32F);
    motionMask.convertTo(motionMask, CV_32F);

    Mat dstImage; //����ũ ���� ���� �̹���

    //����ũ ���͸� ���� ������� ����
    filter2D(srcImage, dstImage, -1, boxMask);
    imshow("Box Mask", dstImage);
    filter2D(srcImage, dstImage, -1, gaussianMask);
    imshow("Gaussian Mask", dstImage);
    filter2D(srcImage, dstImage, -1, sharpeningMask);
    imshow("Sharpening Mask", dstImage);
    filter2D(srcImage, dstImage, -1, horizontalMask);
    imshow("Horizontal Mask", dstImage);
    filter2D(srcImage, dstImage, -1, verticalMask);
    imshow("Vertical Mask", dstImage);
    filter2D(srcImage, dstImage, -1, motionMask);
    imshow("Motion Mask", dstImage);

    waitKey();

    return 0;
}