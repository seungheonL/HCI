#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_R = imread("result/jenny_R.png", 1); // jenny_R.JPG 이미지 로드
	Mat jenny_G = imread("result/jenny_G.png", 1); // jenny_G.JPG 이미지 로드
	Mat jenny_B = imread("result/jenny_B.png", 1); // jenny_B.JPG 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = cpixel.GS_imhist(jenny_R); // R 채널 이미지의 히스토그램 변환

	imshow("result", result); // R 채널 이미지 히스토그램 출력
	imwrite("result/jenny_R_hist.png", result); // 히스토그램 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cpixel.GS_imhist(jenny_G); // G 채널 이미지의 히스토그램 변환

	imshow("result", result); // G 채널 이미지 히스토그램 출력
	imwrite("result/jenny_G_hist.png", result); // 히스토그램 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cpixel.GS_imhist(jenny_B); // B 채널 이미지의 히스토그램 변환

	imshow("result", result); // B 채널 이미지 히스토그램 출력
	imwrite("result/jenny_B_hist.png", result); // 히스토그램 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
