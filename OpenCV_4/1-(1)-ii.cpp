#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase_45 = imread("result/briefcase_45.png", 1); // briefcase_45.png �̹��� �ε�

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����
	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	result = cgeometry.GS_affineRotate(briefcase_45, 0, 1.5); // 1.5�� Ȯ��

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_45_1.5.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}