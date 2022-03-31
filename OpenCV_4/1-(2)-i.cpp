#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase = imread("image/briefcase.jpg", 1); // briefcase.jpg �̹��� �ε�

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����
	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	result = cgeometry.GS_affineRotate(briefcase, 0, 1.5); // 1.5�� Ȯ��

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_1.5.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}