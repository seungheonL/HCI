#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_R = imread("result/jenny_R.png", 1); // jenny_R.JPG �̹��� �ε�
	Mat jenny_G = imread("result/jenny_G.png", 1); // jenny_G.JPG �̹��� �ε�
	Mat jenny_B = imread("result/jenny_B.png", 1); // jenny_B.JPG �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cpixel.GS_imhist(jenny_R); // R ä�� �̹����� ������׷� ��ȯ

	imshow("result", result); // R ä�� �̹��� ������׷� ���
	imwrite("result/jenny_R_hist.png", result); // ������׷� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_imhist(jenny_G); // G ä�� �̹����� ������׷� ��ȯ

	imshow("result", result); // G ä�� �̹��� ������׷� ���
	imwrite("result/jenny_G_hist.png", result); // ������׷� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_imhist(jenny_B); // B ä�� �̹����� ������׷� ��ȯ

	imshow("result", result); // B ä�� �̹��� ������׷� ���
	imwrite("result/jenny_B_hist.png", result); // ������׷� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
