#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase = imread("image/briefcase.jpg", 1); // briefcase.jpg �̹��� �ε�
	Mat briefcase_30_11 = imread("result/briefcase_30_11.png", 1); // briefcase_30_11.png �̹��� �ε�

	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	CPixel cpixel; // �����Ǵ� ���� �Լ��� ����ϱ� ���� CPixel ��ü ����

	result = cpixel.GS_subtract_image(briefcase, briefcase_30_11); // �� �̹����� ���� ���ش�.

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_30_11_subtracted.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}