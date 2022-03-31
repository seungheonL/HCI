#include <opencv2/opencv.hpp>
#include "Geometry.h"
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat briefcase_45_1_5 = imread("result/briefcase_45_1.5.png", 1); // briefcase_45_1.5.png �̹��� �ε�
	Mat briefcase_1_5_45 = imread("result/briefcase_1.5_45.png", 1); // briefcase_1.5_45.png �̹��� �ε�

	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	CPixel cpixel; // �����Ǵ� ���� �Լ��� ����ϱ� ���� CPixel ��ü ����

	result = cpixel.GS_subtract_image(briefcase_45_1_5, briefcase_1_5_45); // �� �̹����� ���ش�.

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_subtracted.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}