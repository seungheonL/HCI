#pragma once
#include <opencv2/opencv.hpp>
#include "Color.h"

using namespace cv;

int main()
{
	Mat jenny = imread("image/jenny.JPG", 1); // jenny.JPG �̹��� �ε�

	CColor ccolor; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CColor �ν��Ͻ� ����

	Mat* result = new Mat[3]; // Output �̹������� �����ϱ� ���� Mat �迭 

	ccolor.GS_splitRGB(jenny, result); // RGB�� �̷���� jenny �̹����� B, G, R�� �и��Ѵ�.

	imshow("result", result[0]); // B ä�� �̹��� ���
	imwrite("result/jenny_B.png", result[0]); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	imshow("result", result[1]); // G ä�� �̹��� ���
	imwrite("result/jenny_G.png", result[1]); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	imshow("result", result[2]); // Rä�� �̹��� ���
	imwrite("result/jenny_R.png", result[2]); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
