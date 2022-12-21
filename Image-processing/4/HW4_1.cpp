/*******************************************************/
/*             HW#4-1 : Convolution                    */
/*  작성자 : 유수형          날짜 : 2022년 4월 27일    */
/*                                                     */
/* 문제 정의 : 임의로 받은 영상에 대하여 윈도우u       */
/*             마스크인 박스, 가우시안, 샤프닝, 수평   */
/*             에지, 수직 에지, 모션을 적용시켜 본다   */
/*******************************************************/


#include <opencv2/opencv.hpp>
#include <string.h>

using namespace cv;
using namespace std;

int main()
{
    Mat srcImage = imread("./lena.jpg", IMREAD_GRAYSCALE); // 이미지 읽기
    if (srcImage.empty())
        return -1;

    imshow("lena", srcImage); // 원본이미지 출력


    // 각각의 마스크들 입력
    Mat boxMask = (Mat_<float>(3, 3) << 1. / 9., 1. / 9., 1. / 9.,              //박스 마스크
        1. / 9., 1. / 9., 1. / 9.,
        1. / 9., 1. / 9., 1. / 9.);

    Mat gaussianMask = (Mat_<float>(5, 5) << 0., 0., .0002, 0., 0.,             //가우시안 마스크
        0., .0113, .0837, .0113, 0.,
        .0002, .0837, .6187, .0837, .0002,
        0., .0113, .0837, .0113, 0.,
        0., 0., .0002, 0., 0.);

    Mat sharpeningMask = (Mat_<float>(3, 3) << 0., -1., 0.,                     //샤프닝 마스크
        -1., 5., -1.,
        0., -1., 0.);


    Mat horizontalMask = (Mat_<float>(3, 3) << 1., 1., 1.,                      //수평 마스크
        0., 0., 0.,
        -1., -1., -1.);

    Mat verticalMask = (Mat_<float>(3, 3) << 1., 0., -1.,                       //수직 마스크
        1., 0., -1.,
        1., 0., -1.);

    Mat motionMask = (Mat_<float>(5, 5) << .0304, .0501, 0, 0, 0,               //모션 마스크
        .0501, .1771, .0519, 0, 0,
        0, .0519, .1771, .0519, 0,
        0, 0, .0519, .1771, .0501,
        0, 0, 0, .0501, .0304);

    //마스크 필터 자료형 변환
    boxMask.convertTo(boxMask, CV_32F);
    gaussianMask.convertTo(gaussianMask, CV_32F);
    sharpeningMask.convertTo(sharpeningMask, CV_32F);
    horizontalMask.convertTo(horizontalMask, CV_32F);
    verticalMask.convertTo(verticalMask, CV_32F);
    motionMask.convertTo(motionMask, CV_32F);

    Mat dstImage; //마스크 필터 적용 이미지

    //마스크 필터를 통한 컨볼루션 수행
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