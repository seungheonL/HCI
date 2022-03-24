#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny_HSV_composited = imread("result/jenny_HSV_composited.png", 1); // jenny_H.png 이미지 로드

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	cvtColor(jenny_HSV_composited, result, COLOR_HSV2BGR); // HSV 이미지를 BGR로 변환

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_RGB_converted.png", result); // Output 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
