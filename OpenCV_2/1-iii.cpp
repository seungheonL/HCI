#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna_gray_eq = imread("result/lenna_gray_eq.png", 1); // lenna_gray_eq.png �̹��� �ε�
	Mat stuff_color_1_gray_eq = imread("result/stuff_color_1_gray_eq.png", 1); // stuff_color_1_gray_eq.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	// lenna
	result = cpixel.GS_imhist(lenna_gray_eq); // lenna_gray_eq�� ������׷��� ���Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_gray_eq_histogram.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	// stuff_color_1
	result = cpixel.GS_imhist(stuff_color_1_gray_eq); // stuff_color_1_gray_eq�� ������׷��� ���Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/stuff_color_1_gray_eq_histogram.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}