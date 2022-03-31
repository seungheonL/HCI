#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase = imread("image/briefcase.jpg", 1); // briefcase.jpg �̹��� �ε�

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����
	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	result = cgeometry.GS_affineRotate(briefcase, -45, 1); // ������ �߽����� �ð�������� 45�� ȸ��

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_45.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}