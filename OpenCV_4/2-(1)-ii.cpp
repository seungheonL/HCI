#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase_30 = imread("result/briefcase_30.png", 1); // briefcase_30.png �̹��� �ε�

	Mat result = briefcase_30; // Output �̹������� �����ϱ� ���� Mat ����

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����

	for (int i = 0; i < 11; i++) // 11�� �ݺ�
	{
		result = cgeometry.GS_affineRotate(result, -30, 1); // ���� �߽����� �ð� �������� 30�� ȸ��
	}

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_30_11.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}