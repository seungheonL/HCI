#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna = imread("image/lenna.png", 1); // lenna.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	// lenna
	Mat lenna_gray; // lenna�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(lenna, lenna_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�

	imshow("lenna_gray", lenna_gray); // Output �̹��� ���
	imwrite("result/lenna_gray.png", lenna_gray); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
