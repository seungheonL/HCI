#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_V = imread("result/jenny_V.png", 0); // jenny_V.png 이미지 로드

	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = cpixel.GS_histeq(jenny_V); // jenny의 V 채널 이미지를 equalization해준다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_V_equalized.png", result); // Output 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
