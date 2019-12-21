#include "Work.h"
void Work::SetData() {
	static int j = 0;
	string Value;
	string buff;
	ifstream File;
	try {
		File.open("..\\Testers\\tut\\WorkFile.txt");
	}
	catch (const exception &e)
	{
		std::cout << e.what() << endl;
		system("pause");
		exit(1);
	}
	getline(File, Value);
	m = Polygon(data,Value);
	getline(File, Value);
	smatch result;
	regex regular("(\\d{1,3})");
	while (j != 6) {
		while (regex_search(Value, result, regular)) {
			


			buff = result.str(1);

				if (j == 0) RGB1_1 = atoi(buff.c_str());
				if (j == 1) RGB1_2 = atoi(buff.c_str());
				if (j == 2) RGB1_3 = atoi(buff.c_str());
				if (j == 3) RGB2_1 = atoi(buff.c_str());
				if (j == 4) RGB2_2 = atoi(buff.c_str());
				if (j == 5)  RGB2_3 = atoi(buff.c_str());


				Value = result.suffix().str();
				j++;
			
		}
	}
	getline(File, Value);
	Culture = Value;
	getline(File, Value);
	ImageTitle = Value;
	File.close();
}
int Work::Polygon(vector<Point>& data,string Value) {
	static int count;count = 0;
	pair<int, int> xy;
	static int j = 0;
	string buff = "";
	smatch result;
	regex regular("(\\d{1,4})");
	while (std::regex_search(Value, result, regular)) {
		buff = result.str(1);
		
		if (j == 0) {
			xy.first = atoi(buff.c_str());
		}
		if (j == 1) {
			xy.second = atoi(buff.c_str());
		}
		std::cout << std::endl;
		Value = result.suffix().str();
		j++;
		if (j == 2) {
			data.push_back(Point(xy.first, xy.second));
			j = 0;
			count++;
		}
	}
	return count;
}
void Work::GetData(double ResultDamage)
{
	ofstream File;
	string path = "..\\Testers\\tut\\tut_v\\ResultFile.txt";
	File.open(path);

	File << "color flow (RGB): " << " Min (" << RGB1_1 << ":" << RGB1_2 << ":" << RGB1_3 << ")" << " Max (" << RGB2_1 << ":" << RGB2_2 << ":" << RGB2_3 << ")" << endl;
	File << "Reference: " << Culture << endl;
	File << "Field polygon: " << endl;
	for (auto a:data)
	{
		File << "x: " << a.x << "|  y: " << a.y << endl;

	}
	File << "Damage: " << ResultDamage << "%" << endl;

	File.close();
}

Work::Work() {
	SetData();
	img = cv::imread(ImageTitle);
}