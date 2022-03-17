#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat lenna = imread("image/lenna.png", 1); // lenna.png �̹��� �ε�
	Mat stuff_color_1 = imread("image/stuff_color_1.png", 1); // stuff_color_1.png �̹��� �ε�

	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	// lenna
	Mat lenna_gray; // lenna�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(lenna, lenna_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�

	imshow("lenna_gray", lenna_gray); // Output �̹��� ���
	imwrite("result/lenna_gray.png", lenna_gray); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_histeq(lenna_gray); // lenna_gray�� histogram equalization�� ���Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/lenna_gray_eq.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	// stuff_color_1
	Mat stuff_color_1_gray; // stuff_color_1_gray�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(stuff_color_1, stuff_color_1_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�

	imshow("stuff_color_1_gray", stuff_color_1_gray); // Output �̹��� ���
	imwrite("result/stuff_color_1_gray.png", stuff_color_1_gray); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cpixel.GS_histeq(stuff_color_1_gray); // stuff_color_1_gray�� histogram equalization�� ���Ѵ�.

	imshow("result", result); // Output �̹��� ���
	imwrite("result/stuff_color_1_gray_eq.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}