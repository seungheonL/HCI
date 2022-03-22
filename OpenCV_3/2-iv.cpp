#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny = imread("image/jenny.JPG", 0); // jenny.JPG �̹��� �ε�

	CColor ccolor; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CColor �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	ccolor.GS_rgb2hsv(&jenny, &result);

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_HSV.png", result); // Output �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
