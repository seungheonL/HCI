#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny_R = imread("result/jenny_R.png", 0); // jenny_R.JPG �̹��� �ε�
	Mat jenny_G = imread("result/jenny_G.png", 0); // jenny_G.JPG �̹��� �ε�
	Mat jenny_B = imread("result/jenny_B.png", 0); // jenny_B.JPG �̹��� �ε�

	CColor ccolor; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CColor �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = ccolor.GS_compositeRGB(new Mat[3]{ jenny_B, jenny_G, jenny_R }); // R, G, B�� �и��Ǿ��� �̹��� 3���� ���� �ϳ��� RGB �̹����� ��ģ��.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_RGB.png", result); // Output �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
