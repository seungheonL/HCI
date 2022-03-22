#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"

using namespace cv;

int main()
{
	Mat lenna_gray = imread("result/lenna_gray.png", 1); // lenna_gray.png �̹��� �ε�
	Mat jenny_gray = imread("result/jenny_gray.png", 1); // jenny_gray.png �̹��� �ε�

	Mat lenna_blurred = imread("result/lenna_blurred.png", 1); // lenna_blurred.png �̹��� �ε�
	Mat jenny_blurred = imread("result/jenny_blurred.png", 1); // jenny_blurred.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_subtract_image(lenna_gray, lenna_blurred); // lenna_gray���� lenna_blurred�� ���ش�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_subtracted.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_subtract_image(jenny_gray, jenny_blurred); //jenny_gray���� jenny_blurred�� ���ش�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_subtracted.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
