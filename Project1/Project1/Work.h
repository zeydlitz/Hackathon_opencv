#pragma once
#include<iostream>
#include <string>
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <regex>
using namespace cv;
using namespace std;
class WorkOut;
//класс с данными
class Work
{
private:
	//диапазон цвета
	short int RGB1_1;
	short int RGB1_2;
	short int RGB1_3;
	short int RGB2_1;
	short int RGB2_2;
	short int RGB2_3;
	string Culture;//выращиваемая культура
	vector<Point> data;//координаты вершин
	string ImageTitle;//путь к картинке
	cv::Mat img;//входная картинка
	cv::Mat test;
	int m;
	

public:
	Work( );
	void SetData();
	int Polygon(vector<Point>&,string);
	void GetData(double ResultDamage);
    friend class WorkOut;
};