#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna_gray_eq = imread("result/lenna_gray_eq.png", 1); // lenna_gray_eq.png 이미지 로드
	Mat stuff_color_1_gray_eq = imread("result/stuff_color_1_gray_eq.png", 1); // stuff_color_1_gray_eq.png 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	// lenna
	result = cpixel.GS_imhist(lenna_gray_eq); // lenna_gray_eq의 히스토그램을 구한다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/lenna_gray_eq_histogram.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	// stuff_color_1
	result = cpixel.GS_imhist(stuff_color_1_gray_eq); // stuff_color_1_gray_eq의 히스토그램을 구한다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/stuff_color_1_gray_eq_histogram.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}