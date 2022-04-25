#include <opencv2/opencv.hpp>

using namespace cv;

const int CAM_WIDTH = 600;
const int CAM_HEIGHT = 400;

void Center_of_mass(Mat& frame, int* pX, int* pY)
{
	int cnt = 0;
	int mx = 0;
	int my = 0;

	for (int i = 0; i < frame.size().height; i++)
	{
		for (int j = 0; j < frame.size().width; j++)
		{
			if (frame.at<uchar>(i, j) > 200)
			{
				cnt++;
				mx += j;
				my += i;
			}
		}
	}

	if (cnt == 0)
	{
		cnt = 1;
	}

	if (cnt > 0)
	{
		*pX = mx / cnt;
		*pY = my / cnt;
	}
}

int main()
{
	VideoCapture cam(0);

	cam.set(CV_CAP_PROP_FRAME_WIDTH, CAM_WIDTH);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);

	Mat Origin_frame;
	Mat HAND_MASK = imread("./1.png");

	if (!cam.isOpened())
	{
		printf("--(!) Error opening video cam\n");
		return -1;
	}

	while (cam.read(Origin_frame))
	{
		if (Origin_frame.empty())
		{
			printf("--(!) No camd frame -- Break!");
			break;
		}

		imshow("original_img", Origin_frame);

		resize(HAND_MASK, HAND_MASK, Size(Origin_frame.cols, Origin_frame.rows), 0, 0, CV_INTER_LINEAR);
		imshow("HAND_MASK", HAND_MASK);

		Mat Mask = Origin_frame + HAND_MASK;
		//imshow("mask", Mask);

		Mat YCrCb;
		cvtColor(Mask, YCrCb, CV_BGR2YCrCb);
		//imshow("YCrCb", YCrCb);

		if (waitKey(1) == 27)
		{
			break;
		}

		Mat Skin_Area;
		inRange(YCrCb, Scalar(0, 130, 90), Scalar(255, 168, 130), Skin_Area);
		//imshow("range", Skin_Area);

		Mat Mask_gray;
		cvtColor(Mask, Mask_gray, CV_BGR2GRAY);
		//imshow("Origin_gray", Mask_gray);

		Mat Skin_gray = Mask_gray + (~Skin_Area);
		//imshow("Skin_gray", Skin_gray);

		Mat thrsh_skin_gray;
		threshold(Skin_gray, thrsh_skin_gray, 200, 255, THRESH_BINARY);
		//imshow("thrsh_skin_gray", thrsh_skin_gray);
		Mat tild_thrsh_skin_gray = ~thrsh_skin_gray;

		erode(tild_thrsh_skin_gray, tild_thrsh_skin_gray, Mat(3, 3, CV_8U, Scalar(1)), Point(-1, -1), 2);

		int cX, cY;
		Center_of_mass(tild_thrsh_skin_gray, &cX, &cY);

		Point center(cX, cY);

		int radius = 40;
		circle(Origin_frame, center, (int)(radius + 0.5), Scalar(130, 255, 100), 2);
		//imshow("Origin_frame", Origin_frame);

		Mat Skin_gray_clone = Skin_gray.clone();
		circle(Skin_gray_clone, center, (int)(radius + 0.5), Scalar(0, 0, 0), -1);
		imshow("Skin_gray_clone", Skin_gray_clone);

		Mat Sub = Skin_gray - Skin_gray_clone;
		//imshow("Sub", Sub);

		Mat CannyEdge;
		Canny(Sub, CannyEdge, 40, 110);
		imshow("CannyEdge", CannyEdge);

		circle(CannyEdge, center, (int)(radius + 0.5), Scalar(0, 0, 0), 4);
		imshow("Result", CannyEdge);
	}

	return 0;
}