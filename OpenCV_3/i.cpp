#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna = imread("image/lenna.png", 1); // lenna.png �̹��� �ε�
	Mat jenny = imread("image/jenny.JPG", 1); // jenny.JPG �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	// lenna
	Mat lenna_gray; // lenna�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(lenna, lenna_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�

	imshow("lenna_gray", lenna_gray); // Output �̹��� ���
	imwrite("result/lenna_gray.png", lenna_gray); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	// jenny
	Mat jenny_gray; // jenny�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(jenny, jenny_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�

	imshow("jenny_gray", jenny_gray); // Output �̹��� ���
	imwrite("result/jenny_gray.png", jenny_gray); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}
