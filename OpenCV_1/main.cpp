#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	CPixel cpixel;

	Mat stuff_color_1 = imread("image/stuff_color_1.png", 1); //0이면 흑백, 1이면 컬러
	Mat stuff_color_2 = imread("image/stuff_color_2.png", 1); //0이면 흑백, 1이면 컬러

	Mat result = cpixel.GS_add_image(stuff_color_1, stuff_color_2);
	imshow("Addition with two images", result);
	imwrite("result/result1.png", result);

	waitKey();

	return 0;
}