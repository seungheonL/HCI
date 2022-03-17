#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna_gray = imread("result/lenna_gray.png", 0); // lenna_gray.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_threshold(lenna_gray, 0, THRESH_BINARY | THRESH_OTSU); // OTSU �˰����� ����Ͽ� ����ȭ�Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_gray_threshold_OTSU.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}