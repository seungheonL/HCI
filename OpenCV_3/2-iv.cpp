#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny = imread("image/jenny.JPG", 1); // jenny.JPG 이미지 로드

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	cvtColor(jenny, result, COLOR_BGR2HSV); // BGR 이미지를 HSV로 변환한다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_HSV.png", result); // Output 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
