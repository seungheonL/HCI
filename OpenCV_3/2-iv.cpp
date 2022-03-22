#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny = imread("image/jenny.JPG", 0); // jenny.JPG 이미지 로드

	CColor ccolor; // 제공되는 여러가지 함수들을 사용하기 위한 CColor 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	ccolor.GS_rgb2hsv(&jenny, &result);

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_HSV.png", result); // Output 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
