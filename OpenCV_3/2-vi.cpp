#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_V = imread("result/jenny_V.png", 0); // jenny_V.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_histeq(jenny_V); // jenny�� V ä�� �̹����� equalization���ش�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_V_equalized.png", result); // Output �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
