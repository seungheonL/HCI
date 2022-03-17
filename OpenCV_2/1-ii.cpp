#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna = imread("image/lenna.png", 1); // lenna.png 이미지 로드
	Mat stuff_color_1 = imread("image/stuff_color_1.png", 1); // stuff_color_1.png 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	// lenna
	Mat lenna_gray; // lenna의 흑백 이미지를 저장하기 위한 Mat 변수 생성
	cvtColor(lenna, lenna_gray, COLOR_BGR2GRAY); // cvtColor() 함수를 이용하여 gray-scale로 변환해준다

	imshow("lenna_gray", lenna_gray); // Output 이미지 출력
	imwrite("result/lenna_gray.png", lenna_gray); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cpixel.GS_histeq(lenna_gray); // lenna_gray에 histogram equalization을 취한다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/lenna_gray_eq.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	// stuff_color_1
	Mat stuff_color_1_gray; // stuff_color_1_gray의 흑백 이미지를 저장하기 위한 Mat 변수 생성
	cvtColor(stuff_color_1, stuff_color_1_gray, COLOR_BGR2GRAY); // cvtColor() 함수를 이용하여 gray-scale로 변환해준다

	imshow("stuff_color_1_gray", stuff_color_1_gray); // Output 이미지 출력
	imwrite("result/stuff_color_1_gray.png", stuff_color_1_gray); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cpixel.GS_histeq(stuff_color_1_gray); // stuff_color_1_gray에 histogram equalization을 취한다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/stuff_color_1_gray_eq.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}