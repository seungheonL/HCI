#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny_H = imread("result/jenny_H.png", 0); // jenny_H.png 이미지 로드
	Mat jenny_S = imread("result/jenny_S.png", 0); // jenny_S.png 이미지 로드
	Mat jenny_V_equalized = imread("result/jenny_V_equalized.png", 0); // jenny_V_equalized.png 이미지 로드

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	cv::merge(new Mat[3]{ jenny_H, jenny_S, jenny_V_equalized }, 3, result); // 각각의 H, S, V' 이미지를 모아 HSV'로 합친다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_HSV_composited.png", result); // Output 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
