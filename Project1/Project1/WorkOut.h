#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <regex>
#include "Work.h"
class WorkOut {
public:
	 Work h;
WorkOut() {
		doblur();
		docut();
		dofind();
	}
void doblur();
	void docut();
	void dofind();
	void domask(cv::Scalar);
	

	
};