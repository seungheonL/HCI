#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny_HSV_composited = imread("result/jenny_HSV_composited.png", 1); // jenny_H.png �̹��� �ε�

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	cvtColor(jenny_HSV_composited, result, COLOR_HSV2BGR); // HSV �̹����� BGR�� ��ȯ

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_RGB_converted.png", result); // Output �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
