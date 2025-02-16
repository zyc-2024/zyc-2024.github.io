#include <iostream>
using namespace std;

// ANSI转义代码
const std::string skyblue = "\033[36m";//天蓝色
const std::string purple = "\033[35m";//紫色
const std::string red = "\033[31m";      // 红色
const std::string green = "\033[32m";    // 绿色
const std::string yellow = "\033[33m";   // 黄色
const std::string darkblue = "\033[34m";     // 深蓝色
const std::string reset = "\033[0m";     // 重置颜色

int main() {
	// 打印彩色文本
	//cout<<"*****"<<endl;//白色
	//cout << green << "*****" << reset << endl;
	//cout << yellow << "*****" << reset << endl;
	//cout << skyblue << "*****" << reset << endl;
	//cout << darkblue << "*****" << reset << endl;
	//cout << purple << "*****" << reset << endl;
	cout << red << "*************************************" << reset << endl;
	cout << red << "*************************************" << reset << endl;
	cout<<red<<"*********"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"***************************"<<reset<<endl;
	cout << red << "*************************************" << reset << endl;
	cout<<red<<"***"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"********"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"************************"<<reset<<endl;
	cout<<red<<"*"<<reset;
	cout<<yellow<<"*****"<<reset;
	cout<<red<<"******"<<reset;
	cout<<red<<"*"<<reset;
	cout<<red<<"************************"<<reset<<endl;
	cout<<red<<"**"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"*"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"********************************"<<reset<<endl;
	cout<<red<<"************"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"************************"<<reset<<endl;
	cout<<red<<"*************************************"<<reset<<endl;
	cout<<red<<"*********"<<reset;
	cout<<yellow<<"*"<<reset;
	cout<<red<<"***************************"<<reset<<endl;
	cout << red << "*************************************" << reset << endl;
	cout << red << "*************************************" << reset << endl;
	cout<<red<<"中国奥运队"<<reset<<endl;
	cout<<yellow<<"绽放在巴黎"<<reset<<endl;
	cout<<skyblue<<"愿中奥队勇往直前"<<reset;
	return 0;
}