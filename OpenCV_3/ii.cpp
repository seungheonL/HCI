#pragma once
#include <opencv2/opencv.hpp>
#include "Filter.h"

using namespace cv;

int main()
{
	Mat lenna = imread("result/lenna_gray.png", 1); // lenna_gray.png 이미지 로드
	Mat jenny = imread("result/jenny_gray.png", 1); // jenny_gray.png 이미지 로드

	CFilter cfilter; // 제공되는 여러가지 함수들을 사용하기 위한 CFilter 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	result = cfilter.GS_blurring(lenna, 0, 1); // lenna_gray를 blurring해준다. 3번째 매개변수 method를 1로 하여 5x5 필터를 적용하였다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/lenna_blurred.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cfilter.GS_blurring(jenny, 0, 1); // jenny_gray를 blurring해준다. 3번째 매개변수 method를 1로 하여 5x5 필터를 적용하였다.

	imshow("result", result); // Output 이미지 출력
	imwrite("result/jenny_blurred.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}
