#pragma once
#include <opencv2/opencv.hpp>
#include "Filter.h"

using namespace cv;

int main()
{
	Mat lenna = imread("result/lenna_gray.png", 1); // lenna_gray.png �̹��� �ε�
	Mat jenny = imread("result/jenny_gray.png", 1); // jenny_gray.png �̹��� �ε�

	CFilter cfilter; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CFilter �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	result = cfilter.GS_blurring(lenna, 0, 1); // lenna_gray�� blurring���ش�. 3��° �Ű����� method�� 1�� �Ͽ� 5x5 ���͸� �����Ͽ���.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_blurred.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cfilter.GS_blurring(jenny, 0, 1); // jenny_gray�� blurring���ش�. 3��° �Ű����� method�� 1�� �Ͽ� 5x5 ���͸� �����Ͽ���.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/jenny_blurred.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
