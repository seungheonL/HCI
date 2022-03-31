#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat jenny = imread("image/jenny.JPG", 1); // jenny.JPG �̹��� �ε�
	Mat rice = imread("image/rice.png", 1); // rice.png �̹��� �ε�

	Mat result; // Output �̹������� �����ϱ� ���� Mat ����

	cvtColor(jenny, result, COLOR_BGR2GRAY); // jenny�� gray_scale�� ��ȯ

	imshow("result", result); // �̹��� ���
	imwrite("result/jenny_gray.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	cvtColor(rice, result, COLOR_BGR2GRAY); // rice�� gray_scale�� ��ȯ

	imshow("result", result); // �̹��� ���
	imwrite("result/rice_gray.png", result); // �̹��� ����

	waitKey(); // Output �̹����� �����ϱ� ���� ������ �Է��� ���� ������ ��ٸ���.

	return 0;
}