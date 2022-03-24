#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_R = imread("result/jenny_R.png", 0); // jenny_R.JPG �̹��� �ε�
	Mat jenny_G = imread("result/jenny_G.png", 0); // jenny_G.JPG �̹��� �ε�
	Mat jenny_B = imread("result/jenny_B.png", 0); // jenny_B.JPG �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_histeq(jenny_R); // R ä�� �̹����� equalization ��ȯ

	imshow("result", result); // R ä�� �̹��� equalization �Ͽ� ���
	imwrite("result/jenny_R_equalized.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_histeq(jenny_G); // G ä�� �̹����� equalization ��ȯ

	imshow("result", result); // G ä�� �̹��� equalization �Ͽ� ���
	imwrite("result/jenny_G_equalized.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_histeq(jenny_B); // B ä�� �̹����� equalization ��ȯ

	imshow("result", result); // B ä�� �̹��� equalization �Ͽ� ���
	imwrite("result/jenny_B_equalized.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
