#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny_HSV = imread("result/jenny_HSV.png", 1); // jenny_HSV.png �̹��� �ε�

	Mat* result = new Mat[3]; // Output �̹������� �����ϱ� ���� Mat �迭

	cv::split(jenny_HSV, result); // HSV �̹����� H, S, V�� ���� �и�

	imshow("result", result[0]); // H ä�� �̹��� ���
	imwrite("result/jenny_H.png", result[0]); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	imshow("result", result[1]); // S ä�� �̹��� ���
	imwrite("result/jenny_S.png", result[1]); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	imshow("result", result[2]); // V ä�� �̹��� ���
	imwrite("result/jenny_V.png", result[2]); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
