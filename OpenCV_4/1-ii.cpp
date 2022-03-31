#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

int main()
{
	Mat jenny_gray = imread("result/jenny_gray.png", 0); // jenny_gray.png �̹��� �ε�
	Mat rice_gray = imread("result/rice_gray.png", 0); // rice_gray.png �̹��� �ε�

	CEdge cedge; // �����Ǵ� ���� �Լ��� ����ϱ� ���� CEdge ��ü ����

	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	result = cedge.GS_sobel_edge_Sobel(jenny_gray); // sobel edge ����

	imshow("result", result); // �̹��� ���
	imwrite("result/jenny_sobel.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cedge.GS_sobel_edge_Sobel(rice_gray); // sobel edge ����

	imshow("result", result); // �̹��� ���
	imwrite("result/rice_sobel.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}