#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"

using namespace cv;
using namespace std;

int main() {
	cv::VideoCapture videoCapture(0); // ��ķ �Կ��� �� �ִ� ��ü

	CImageAnalysis cImageAnalysis; // template matching�� ����ϱ� ���� ��ü

	Mat templateImg = imread("result/template.png", 1); // �̸� �������� template�� �о�´�

	Mat img;
	Mat result;

	while (true)
	{
		videoCapture >> img; // ���� ��Ʈ�� ����

		result = cImageAnalysis.GS_templateMatching(img, templateImg); // �������κ��� template matching�Ѵ�.

		imshow("result", result); // template matching�� ��� ���

		if (waitKey(1) == 27) // ESC ������ ����
		{
			break;
		}
	}

	imwrite("result/1_ii_original.png", img); // ���� �̹��� ����
	imwrite("result/1_ii_temMat.png", result); // template matching�� �̹��� ����

	return 0;
}