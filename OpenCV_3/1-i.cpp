#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny = imread("image/jenny.JPG", 1); // jenny.JPG 이미지 로드

	CColor ccolor; // 제공되는 여러가지 함수들을 사용하기 위한 CColor 인스턴스 생성

	Mat* result = new Mat[3]; // Output 이미지들을 저장하기 위한 Mat 배열 

	ccolor.GS_splitRGB(jenny, result); // RGB로 이루어진 jenny 이미지를 B, G, R로 분리한다.

	imshow("result", result[0]); // B 채널 이미지 출력
	imwrite("result/jenny_B.png", result[0]); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	imshow("result", result[1]); // G 채널 이미지 출력
	imwrite("result/jenny_G.png", result[1]); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	imshow("result", result[2]); // R채널 이미지 출력
	imwrite("result/jenny_R.png", result[2]); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
