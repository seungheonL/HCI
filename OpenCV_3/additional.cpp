#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_S = imread("result/jenny_S.png", 0); // jenny_S.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_histeq(jenny_S); // jenny�� S ä�� �̹����� equalization���ش�.

	Mat jenny_H = imread("result/jenny_H.png", 0); // jenny_H.png �̹��� �ε�
	Mat jenny_S_equalized = imread("result/jenny_S_equalized.png", 0); // jenny_S_equalized.png �̹��� �ε�
	Mat jenny_V = imread("result/jenny_V.png", 0); // jenny_V.png �̹��� �ε�

	Mat jenny_HSV_composited; // Output �̹����� �����ϱ� ���� Mat ����

	cv::merge(new Mat[3]{ jenny_H, jenny_S_equalized, jenny_V }, 3, jenny_HSV_composited); // ������ H, S', V �̹����� ��� HS'V�� ��ģ��.

	cvtColor(jenny_HSV_composited, result, COLOR_HSV2BGR); // HSV �̹����� BGR�� ��ȯ

	imshow("result", result); // Output �̹��� ���

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
