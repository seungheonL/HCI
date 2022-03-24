#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny_HSV = imread("result/jenny_HSV.png", 1); // jenny_HSV.png 이미지 로드

	Mat* result = new Mat[3]; // Output 이미지들을 저장하기 위한 Mat 배열

	cv::split(jenny_HSV, result); // HSV 이미지를 H, S, V로 각각 분리

	imshow("result", result[0]); // H 채널 이미지 출력
	imwrite("result/jenny_H.png", result[0]); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	imshow("result", result[1]); // S 채널 이미지 출력
	imwrite("result/jenny_S.png", result[1]); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	imshow("result", result[2]); // V 채널 이미지 출력
	imwrite("result/jenny_V.png", result[2]); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
