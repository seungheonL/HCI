#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny_H = imread("result/jenny_H.png", 0); // jenny_H.png �̹��� �ε�
	Mat jenny_S = imread("result/jenny_S.png", 0); // jenny_S.png �̹��� �ε�
	Mat jenny_V_equalized = imread("result/jenny_V_equalized.png", 0); // jenny_V_equalized.png �̹��� �ε�

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	cv::merge(new Mat[3]{ jenny_H, jenny_S, jenny_V_equalized }, 3, result); // ������ H, S, V' �̹����� ��� HSV'�� ��ģ��.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_HSV_composited.png", result); // Output �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
