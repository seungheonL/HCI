#pragma once
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace cv;

int main()
{
	CPixel cpixel; // �����Ǵ� �������� �Լ����� ����ϱ� ���� CPixel �ν��Ͻ� ����

	Mat result; // Output �̹����� �����ϱ� ���� Mat ����

	Mat stuff_color_1 = imread("image/stuff_color_1.png", 1); // stuff_color_1.png �̹��� �ε�
	Mat stuff_color_2 = imread("image/stuff_color_2.png", 1); // stuff_color_2.png �̹��� �ε�
	Mat lenna = imread("image/lenna.png", 1); // lenna.png �̹��� �ε�
	Mat orange = imread("image/orange.jpg", 1); // orange.jpg �̹��� �ε�

	// 1-i
	result = cpixel.GS_add_image(stuff_color_1, stuff_color_2); // stuff_color_1�� stuff_color_2�� �����Ǵ� �ȼ����� ���� ����� ����

	imshow("Addition with two images", result); // Output �̹��� ���
	imwrite("result/result1-i.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 1-ii
	result = cpixel.GS_add_image(lenna, orange); // lenna�� orange�� �����Ǵ� �ȼ����� ���� ����� ����

	imshow("Addition with two images", result); // Output �̹��� ���
	imwrite("result/result1-ii.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 2-iii
	result = cpixel.GS_subtract_image(stuff_color_1, stuff_color_2); // stuff_color_1�� stuff_color_2�� �����Ǵ� �ȼ����� �� ����� ����

	imshow("Subtraction with two images", result); // Output �̹��� ���
	imwrite("result/result2-iii.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 2-iv
	result = cpixel.GS_subtract_image(lenna, orange); // lenna�� orange�� �����Ǵ� �ȼ����� �� ����� ����

	imshow("Subtraction with two images", result); // Output �̹��� ���
	imwrite("result/result2-iv.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 3-i
	// stuff_color_1�� stuff_color_2�� ������ ���´�.
	// ���̴� ������ GS_blending_effect() �Լ��� �Ű����� alpha�� ���ؼ� �����ȴ�.
	// alpha�� ���� ������ [0, 1]�̶�� �������� ��, alpha�� ���� 0�� �������� image2�� ������ ��������, 1�� �������� image1�� ������ ��������.
	result = cpixel.GS_blending_effect(stuff_color_1, stuff_color_2, 0.5);

	imshow("Blending with two images", result); // Output �̹��� ���
	imwrite("result/result3-i.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 3-ii
	// lenna�� orange�� ������ ���´�.
	// ���̴� ������ GS_blending_effect() �Լ��� �Ű����� alpha�� ���ؼ� �����ȴ�.
	// alpha�� ���� ������ [0, 1]�̶�� �������� ��, alpha�� ���� 0�� �������� image2�� ������ ��������, 1�� �������� image1�� ������ ��������.
	result = cpixel.GS_blending_effect(lenna, orange, 0.5);

	imshow("Blending with two images", result); // Output �̹��� ���
	imwrite("result/result3-ii.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 4-i
	Mat stuff_color_1_gray; // stuff_color_1�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(stuff_color_1, stuff_color_1_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�.
	result = cpixel.GS_LUT_basic_contrast_brightness(stuff_color_1_gray, 2.4, 5); // contrast�� brightness�� ��ġ�� ������ �����Ͽ� LUT�� ���� �� �̹����� ��ȯ�Ѵ�.

	imshow("Contrast & brightness adjustment by LUT", result); // Output �̹��� ���
	imwrite("result/result4-i.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	// 4-ii
	Mat lenna_gray; // lenna�� ��� �̹����� �����ϱ� ���� Mat ���� ����
	cvtColor(lenna, lenna_gray, COLOR_BGR2GRAY); // cvtColor() �Լ��� �̿��Ͽ� gray-scale�� ��ȯ���ش�.
	result = cpixel.GS_LUT_basic_contrast_brightness(lenna_gray, 1.6, 10); // contrast�� brightness�� ��ġ�� ������ �����Ͽ� LUT�� ���� �� �̹����� ��ȯ�Ѵ�.

	imshow("Contrast & brightness adjustment by LUT", result); // Output �̹��� ���
	imwrite("result/result4-ii.png", result); // Output �̹����� �� ������Ʈ�� ������ ����

	waitKey(); // Output �̹������� �� �徿 ���� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}