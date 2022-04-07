#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	VideoCapture videoCapture(0); // ��ķ �Կ��� �� �ִ� ��ü

	Mat img;

	while (true)
	{
		videoCapture >> img; // ���� ��Ʈ�� ����

		imshow("camera", img); // ���� ���

		if (waitKey(1) == 27) // ESC ������ ����
		{
			break;
		}
	}

	imshow("result", img); // ���������� ���� ������ ���
	imwrite("result/airpod.png", img); // ���������� ���� ������ ����

	waitKey();

	return 0;
}