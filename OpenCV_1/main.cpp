#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	CPixel cpixel; // 제공되는 여러가지 함수들을 사용하기 위한 CPixel 인스턴스 생성

	Mat result; // Output 이미지를 저장하기 위한 Mat 변수

	Mat stuff_color_1 = imread("image/stuff_color_1.png", 1); // stuff_color_1.png 이미지 로드
	Mat stuff_color_2 = imread("image/stuff_color_2.png", 1); // stuff_color_2.png 이미지 로드
	Mat lenna = imread("image/lenna.png", 1); // lenna.png 이미지 로드
	Mat orange = imread("image/orange.jpg", 1); // orange.jpg 이미지 로드

	// 1-i
	result = cpixel.GS_add_image(stuff_color_1, stuff_color_2); // stuff_color_1과 stuff_color_2의 대응되는 픽셀값을 더한 결과를 저장

	imshow("Addition with two images", result); // Output 이미지 출력
	imwrite("result/result1-i.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 1-ii
	result = cpixel.GS_add_image(lenna, orange); // lenna와 orange의 대응되는 픽셀값을 더한 결과를 저장

	imshow("Addition with two images", result); // Output 이미지 출력
	imwrite("result/result1-ii.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 2-iii
	result = cpixel.GS_subtract_image(stuff_color_1, stuff_color_2); // stuff_color_1과 stuff_color_2의 대응되는 픽셀값을 뺀 결과를 저장

	imshow("Subtraction with two images", result); // Output 이미지 출력
	imwrite("result/result2-iii.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 2-iv
	result = cpixel.GS_subtract_image(lenna, orange); // lenna와 orange의 대응되는 픽셀값을 뺀 결과를 저장

	imshow("Subtraction with two images", result); // Output 이미지 출력
	imwrite("result/result2-iv.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 3-i
	// stuff_color_1과 stuff_color_2를 적절히 섞는다.
	// 섞이는 비율은 GS_blending_effect() 함수의 매개변수 alpha에 의해서 결정된다.
	// alpha의 값의 범위가 [0, 1]이라고 가정했을 때, alpha의 값이 0에 가까울수록 image2의 비율이 높아지고, 1에 가까울수록 image1의 비율이 높아진다.
	result = cpixel.GS_blending_effect(stuff_color_1, stuff_color_2, 0.5);

	imshow("Blending with two images", result); // Output 이미지 출력
	imwrite("result/result3-i.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 3-ii
	// lenna와 orange를 적절히 섞는다.
	// 섞이는 비율은 GS_blending_effect() 함수의 매개변수 alpha에 의해서 결정된다.
	// alpha의 값의 범위가 [0, 1]이라고 가정했을 때, alpha의 값이 0에 가까울수록 image2의 비율이 높아지고, 1에 가까울수록 image1의 비율이 높아진다.
	result = cpixel.GS_blending_effect(lenna, orange, 0.5);

	imshow("Blending with two images", result); // Output 이미지 출력
	imwrite("result/result3-ii.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 4-i
	Mat stuff_color_1_gray; // stuff_color_1의 흑백 이미지를 저장하기 위한 Mat 변수 생성
	cvtColor(stuff_color_1, stuff_color_1_gray, COLOR_BGR2GRAY); // cvtColor() 함수를 이용하여 gray-scale로 변환해준다.
	result = cpixel.GS_LUT_basic_contrast_brightness(stuff_color_1_gray, 2.4, 5); // contrast와 brightness의 수치를 적절히 결정하여 LUT를 만든 후 이미지를 변환한다.

	imshow("Contrast & brightness adjustment by LUT", result); // Output 이미지 출력
	imwrite("result/result4-i.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	// 4-ii
	Mat lenna_gray; // lenna의 흑백 이미지를 저장하기 위한 Mat 변수 생성
	cvtColor(lenna, lenna_gray, COLOR_BGR2GRAY); // cvtColor() 함수를 이용하여 gray-scale로 변환해준다.
	result = cpixel.GS_LUT_basic_contrast_brightness(lenna_gray, 1.6, 10); // contrast와 brightness의 수치를 적절히 결정하여 LUT를 만든 후 이미지를 변환한다.

	imshow("Contrast & brightness adjustment by LUT", result); // Output 이미지 출력
	imwrite("result/result4-ii.png", result); // Output 이미지를 내 프로젝트에 별도로 저장

	waitKey(); // Output 이미지들을 한 장씩 보기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}