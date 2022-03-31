#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase_1_5 = imread("result/briefcase_1.5.png", 1); // briefcase_1.5.png �̹��� �ε�

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����
	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	result = cgeometry.GS_affineRotate(briefcase_1_5, -45, 1); // ������ �߽����� �ð�������� 45�� ȸ��

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_1.5_45.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}