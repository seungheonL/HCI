#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase = imread("image/briefcase.jpg", 1); // briefcase.jpg �̹��� �ε�

	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����

	result = cgeometry.GS_affineRotate(briefcase, -30, 1); // ���� �߽����� �ð� �������� 30�� ȸ��

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_30.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}