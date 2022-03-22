#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"

using namespace cv;

int main()
{
	Mat lenna_gray = imread("result/lenna_gray.png", 1); // lenna_gray.png 이미지 로드
	Mat jenny_gray = imread("result/jenny_gray.png", 1); // jenny_gray.png 이미지 로드

	Mat lenna_subtracted = imread("result/lenna_subtracted.png", 1); // lenna_subtracted.png 이미지 로드
	Mat jenny_subtracted = imread("result/jenny_subtracted.png", 1); // jenny_subtracted.png 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = cpixel.GS_add_image(lenna_gray, lenna_subtracted); // lenna_gray와 lenna_subtracted를 더한다. 

	imshow("result", result); // Output 이미지 출력
	imwrite("result/lenna_added.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cpixel.GS_add_image(jenny_gray, jenny_subtracted); //jenny_gray와 jenny_subtracted를 더한다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_added.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
