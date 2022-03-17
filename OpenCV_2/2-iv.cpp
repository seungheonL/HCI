#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna_gray = imread("result/lenna_gray.png", 0); // lenna_gray.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_adaptive_threshold(lenna_gray, 150, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY); // adaptive method�� ����Ͽ� ����ȭ�Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_gray_adaptive_threshold.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}