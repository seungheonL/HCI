#include <opencv2/opencv.hpp>
#include "Filter.h"
#include "Edge.h"
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_gray = imread("result/jenny_gray.png", 0); // jenny_gray.png �̹��� �ε�
	Mat rice_gray = imread("result/rice_gray.png", 0); // rice_gray.png �̹��� �ε�

	CFilter cfilter; // �����Ǵ� ���� �Լ��� ����ϱ� ���� CFilter ��ü ����
	CEdge cedge; // �����Ǵ� ���� �Լ��� ����ϱ� ���� CEdge ��ü ����

	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	result = cfilter.GS_gaussian_smoothing_filtering(jenny_gray, 2); // ����þ� ���͸� ����
	result = cedge.GS_laplacian_edge_Laplacian(result); // ���ö�þ� ���� ����

	imshow("result", result); // �̹��� ���
	imwrite("result/jenny_laplacian_of_gaussian.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	result = cfilter.GS_gaussian_smoothing_filtering(rice_gray, 2); // ����þ� ���͸� ����
	result = cedge.GS_laplacian_edge_Laplacian(result); // ���ö�þ� ���� ����

	imshow("result", result); // �̹��� ���
	imwrite("result/rice_laplacian_of_gaussian.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}