#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/imgcodecs.hpp"

#include "opencv2/highgui/highgui.hpp"

#include <iostream>

#include <opencv2/core/core.hpp>

#include <string>

using namespace cv;
using namespace std;

void type_a(Mat ini, Mat medi);
void type_b(Mat ini, Mat medi);
void type_c(Mat ini, Mat medi_1, Mat medi_2);
void type_d(Mat ini, Mat medi, Mat final);
void type_e(Mat ini, Mat medi, Mat final);
void type_f(Mat ini, Mat medi_1, Mat medi_2, Mat final);

void type_a(Mat ini, Mat medi) //아, 에
{
	Mat dst = cv::Mat::zeros(Size(500, 500), CV_8U);
	cvtColor(dst, dst, COLOR_GRAY2RGB);
	dst = ~dst;

	resize(ini, ini, Size(250, 500), INTER_AREA);
	resize(medi, medi, Size(250, 500), INTER_AREA);

	threshold(ini, ini, 170, 255, THRESH_BINARY_INV);
	threshold(medi, medi, 170, 255, THRESH_BINARY_INV);

	std::vector<vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	//초성
	findContours(ini, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0));

	//종성
	findContours(medi, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(250, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(250, 0));

	//이미지 보여주기
	imshow("font_Composing_type_a", dst);

	waitKey();
	destroyAllWindows();

}

void type_b(Mat ini, Mat medi) //오, 우
{
	Mat dst = cv::Mat::zeros(Size(500, 500), CV_8U);
	cvtColor(dst, dst, COLOR_GRAY2RGB);
	dst = ~dst;

	resize(ini, ini, Size(500, 250), INTER_AREA);
	resize(medi, medi, Size(500, 250), INTER_AREA);

	threshold(ini, ini, 170, 255, THRESH_BINARY_INV);
	threshold(medi, medi, 170, 255, THRESH_BINARY_INV);

	std::vector<vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	//초성
	findContours(ini, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0));

	//종성
	findContours(medi, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 250));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(0, 250));

	//이미지 보여주기
	imshow("font_Composing_type_b", dst);

	waitKey();
	destroyAllWindows();

}

void type_c(Mat ini, Mat medi_1, Mat medi_2) //와, 워
{
	Mat dst = cv::Mat::zeros(Size(500, 500), CV_8U);
	cvtColor(dst, dst, COLOR_GRAY2RGB);
	dst = ~dst;

	resize(ini, ini, Size(250, 250), INTER_AREA);
	resize(medi_1, medi_1, Size(250, 250), INTER_AREA);
	resize(medi_2, medi_2, Size(250, 500), INTER_AREA);

	threshold(ini, ini, 170, 255, THRESH_BINARY_INV);
	threshold(medi_1, medi_1, 170, 255, THRESH_BINARY_INV);
	threshold(medi_2, medi_2, 170, 255, THRESH_BINARY_INV);

	std::vector<vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	//초성
	findContours(ini, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0));

	//중성 1
	findContours(medi_1, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 250));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(0, 250));

	//중성 2
	findContours(medi_2, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(250, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(250, 0));

	//이미지 보여주기
	imshow("font_Composing_type_c", dst);

	waitKey();
	destroyAllWindows();

}

void type_d(Mat ini, Mat medi, Mat fin) //앙, 엥
{
	Mat dst = cv::Mat::zeros(Size(500, 500), CV_8U);
	cvtColor(dst, dst, COLOR_GRAY2RGB);
	dst = ~dst;

	resize(ini, ini, Size(250, 250), INTER_AREA);
	resize(medi, medi, Size(250, 250), INTER_AREA);
	resize(fin, fin, Size(500, 200), INTER_AREA);

	threshold(ini, ini, 170, 255, THRESH_BINARY_INV);
	threshold(medi, medi, 170, 255, THRESH_BINARY_INV);
	threshold(fin, fin, 170, 255, THRESH_BINARY_INV);

	std::vector<vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	//초성
	findContours(ini, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0));

	//중성
	findContours(medi, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(250, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(250, 0));

	//종성
	findContours(fin, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 250));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(0, 250));

	//이미지 보여주기
	imshow("font_Composing_type_d", dst);

	waitKey();
	destroyAllWindows();

}

void type_e(Mat ini, Mat medi, Mat fin) //옹,웅
{
	Mat dst = cv::Mat::zeros(Size(500, 500), CV_8U);
	cvtColor(dst, dst, COLOR_GRAY2RGB);
	dst = ~dst;

	resize(ini, ini, Size(400, 200), INTER_AREA);
	resize(medi, medi, Size(500, 100), INTER_AREA);
	resize(fin, fin, Size(400, 200), INTER_AREA);

	threshold(ini, ini, 170, 255, THRESH_BINARY_INV);
	threshold(medi, medi, 170, 255, THRESH_BINARY_INV);
	threshold(fin, fin, 170, 255, THRESH_BINARY_INV);

	std::vector<vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	//초성
	findContours(ini, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0));

	//중성
	findContours(medi, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 200));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(0, 200));

	//종성
	findContours(fin, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(50, 300));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(50, 300));

	//이미지 보여주기
	imshow("font_Composing_type_e", dst);

	waitKey();
	destroyAllWindows();

}

void type_f(Mat ini, Mat medi_1, Mat medi_2 , Mat fin) //왕,웡
{
	Mat dst = cv::Mat::zeros(Size(500, 500), CV_8U);
	cvtColor(dst, dst, COLOR_GRAY2RGB);
	dst = ~dst;

	resize(ini, ini, Size(250, 150), INTER_AREA);
	resize(medi_1, medi_1, Size(250, 150), INTER_AREA);
	resize(medi_2, medi_2, Size(250, 300), INTER_AREA);
	resize(fin, fin, Size(500, 200), INTER_AREA);

	threshold(ini, ini, 170, 255, THRESH_BINARY_INV);
	threshold(medi_1, medi_1, 170, 255, THRESH_BINARY_INV);
	threshold(medi_2, medi_2, 170, 255, THRESH_BINARY_INV);
	threshold(fin, fin, 170, 255, THRESH_BINARY_INV);

	std::vector<vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	//초성
	findContours(ini, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0));

	//중성 1
	findContours(medi_1, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 150));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(0, 150));

	//중성 2
	findContours(medi_2, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(250, 0));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(250, 0));

	//종성
	findContours(fin, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i< contours.size(); i++)
	{
		Scalar color = Scalar(0, 0, 0);
		drawContours(dst, contours, i, color, 2, 8, hierarchy, 0, Point(0, 300));
	}
	cv::fillPoly(dst, contours, cv::Scalar(0, 0, 0), cv::LINE_8, 0, Point(0, 300));

	//이미지 보여주기
	imshow("font_Composing_type_f", dst);

	waitKey();
	destroyAllWindows();

}

int main()
{
	Mat one = imread("1.jpg", IMREAD_GRAYSCALE); //ㄱ
	Mat two = imread("2.jpg", IMREAD_GRAYSCALE); //ㅏ
	Mat three = imread("3.jpg", IMREAD_GRAYSCALE); //ㅗ
	Mat four = imread("4.jpg", IMREAD_GRAYSCALE); //ㅇ

	type_a(one, two); //가
	type_b(one, three); //고
	type_c(one, three, two); //과
	type_d(one, two, four); //강
	type_e(one, three, four); //공
	type_f(one, three, two, four); //광

	waitKey();
	destroyAllWindows();

	return 0;

}