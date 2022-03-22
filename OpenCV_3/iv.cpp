#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"

using namespace cv;

int main()
{
	Mat lenna_gray = imread("result/lenna_gray.png", 1); // lenna_gray.png �̹��� �ε�
	Mat jenny_gray = imread("result/jenny_gray.png", 1); // jenny_gray.png �̹��� �ε�

	Mat lenna_subtracted = imread("result/lenna_subtracted.png", 1); // lenna_subtracted.png �̹��� �ε�
	Mat jenny_subtracted = imread("result/jenny_subtracted.png", 1); // jenny_subtracted.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_add_image(lenna_gray, lenna_subtracted); // lenna_gray�� lenna_subtracted�� ���Ѵ�. 

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_added.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_add_image(jenny_gray, jenny_subtracted); //jenny_gray�� jenny_subtracted�� ���Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_added.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
