#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny_R_equalized = imread("result/jenny_R_equalized.png", 0); // jenny_R_equalized.JPG 이미지 로드
	Mat jenny_G_equalized = imread("result/jenny_G_equalized.png", 0); // jenny_G_equalized.JPG 이미지 로드
	Mat jenny_B_equalized = imread("result/jenny_B_equalized.png", 0); // jenny_B_equalized.JPG 이미지 로드

	CColor ccolor; // 제공되는 여러가지 함수들을 사용하기 위한 CColor 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = ccolor.GS_compositeRGB(new Mat[3]{ jenny_B_equalized, jenny_G_equalized, jenny_R_equalized }); // R', G', B'로 분리되었던 이미지 3개를 합쳐 하나의 RGB 이미지로 합친다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_RGB_equalized.png", result); // Output 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
