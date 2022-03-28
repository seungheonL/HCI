#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_S = imread("result/jenny_S.png", 0); // jenny_S.png 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = cpixel.GS_histeq(jenny_S); // jenny의 S 채널 이미지를 equalization해준다.

	Mat jenny_H = imread("result/jenny_H.png", 0); // jenny_H.png 이미지 로드
	Mat jenny_S_equalized = imread("result/jenny_S_equalized.png", 0); // jenny_S_equalized.png 이미지 로드
	Mat jenny_V = imread("result/jenny_V.png", 0); // jenny_V.png 이미지 로드

	Mat jenny_HSV_composited; // Output 이미지를 저장하기 위한 Mat 변수

	cv::merge(new Mat[3]{ jenny_H, jenny_S_equalized, jenny_V }, 3, jenny_HSV_composited); // 각각의 H, S', V 이미지를 모아 HS'V로 합친다.

	cvtColor(jenny_HSV_composited, result, COLOR_HSV2BGR); // HSV 이미지를 BGR로 변환

	imshow("result", result); // Output 이미지 출력

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
