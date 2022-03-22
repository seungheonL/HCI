#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"

using namespace cv;

int main()
{
	Mat lenna_gray = imread("result/lenna_gray.png", 1); // lenna_gray.png 이미지 로드
	Mat jenny_gray = imread("result/jenny_gray.png", 1); // jenny_gray.png 이미지 로드

	Mat lenna_blurred = imread("result/lenna_blurred.png", 1); // lenna_blurred.png 이미지 로드
	Mat jenny_blurred = imread("result/jenny_blurred.png", 1); // jenny_blurred.png 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = cpixel.GS_subtract_image(lenna_gray, lenna_blurred); // lenna_gray에서 lenna_blurred을 빼준다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/lenna_subtracted.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cpixel.GS_subtract_image(jenny_gray, jenny_blurred); //jenny_gray에서 jenny_blurred를 빼준다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_subtracted.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
