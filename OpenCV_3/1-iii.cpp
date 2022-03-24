#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny_R_equalized = imread("result/jenny_R_equalized.png", 0); // jenny_R_equalized.JPG �̹��� �ε�
	Mat jenny_G_equalized = imread("result/jenny_G_equalized.png", 0); // jenny_G_equalized.JPG �̹��� �ε�
	Mat jenny_B_equalized = imread("result/jenny_B_equalized.png", 0); // jenny_B_equalized.JPG �̹��� �ε�

	CColor ccolor; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CColor �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = ccolor.GS_compositeRGB(new Mat[3]{ jenny_B_equalized, jenny_G_equalized, jenny_R_equalized }); // R', G', B'�� �и��Ǿ��� �̹��� 3���� ���� �ϳ��� RGB �̹����� ��ģ��.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_RGB_equalized.png", result); // Output �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
