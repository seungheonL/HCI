#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase = imread("image/briefcase.jpg", 1); // briefcase.jpg �̹��� �ε�

	Mat result = briefcase; // Output �̹������� �����ϱ� ���� Mat ����

	CGeometry cgeometry; // �����Ǵ� ���� �Լ����� ����ϱ� ���� CGeometry ��ü ����

	for (int i = 0; i < 6; i++) // �Ʒ� ������ 6�� �ݺ�(5�� �̻�)
	{
		for (int i = 0; i < 12; i++) // 12�� �ݺ� ȸ��
		{
			result = cgeometry.GS_affineRotate(result, -30, 1); // ���� �߽����� �ð� �������� 30�� ȸ��
		}
	}

	imshow("result", result); // �̹��� ���
	imwrite("result/briefcase_30_11_6.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}