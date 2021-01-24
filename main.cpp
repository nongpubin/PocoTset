/*
 * @Author: your name
 * @Date: 2020-03-28 22:49:41
 * @LastEditTime: 2021-01-24 10:55:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \PocoTset\main.cpp
 */


#include  <stdio.h>           
#include "unistd.h" 
#include <iostream>
#include <vector>
#include <fstream>
#include <fcntl.h>
#include <sstream>
#include "/usr/include/string.h"
#include <string.h>


using namespace std;
// using namespace Poco;

char buff1[] = {"12345688888889"};
char buff2[] = {"BAAAAAAAAAAAAAAAAB"};

int intbuff[] = {1,2,3,4,5};

class FdsUrl
{
private:
	/* data */
public:
	std::string mUrl;
	int mTime = 0;
	FdsUrl() {
		std::cout << "默认构造函数执行" << std::endl;
	}
	FdsUrl(std::string url, int time);
	~FdsUrl();
};

FdsUrl::FdsUrl(std::string url, int time)
:mUrl(url),mTime(time)
{
	std::cout << "构造函数执行" << std::endl;
}

FdsUrl::~FdsUrl()
{
	std::cout << "析构函数执行" << std::endl;
}

namespace UrlType
{
	enum type {
		MAP_URL = 0,
		PATH_URL = 1
	};
};



int main()
{
	vector<class FdsUrl> urlVector(10, FdsUrl("init", 0));

	cout << "MAP_URL time = " << urlVector[UrlType::MAP_URL].mTime << endl;
	cout << "MAP_URL url = " << urlVector[UrlType::MAP_URL].mUrl << endl;

	cout << "MAP_URL time = " << urlVector[UrlType::PATH_URL].mTime << endl;
	cout << "MAP_URL url = " << urlVector[UrlType::PATH_URL].mUrl << endl;

	cout << "look at me, init !!! " << endl;

	urlVector[UrlType::MAP_URL].mUrl = "change ha ha !!! ";
	urlVector[UrlType::MAP_URL].mTime = 12345678;

	cout << "MAP_URL time = " << urlVector[UrlType::MAP_URL].mTime << endl;
	cout << "MAP_URL url = " << urlVector[UrlType::MAP_URL].mUrl << endl;

	urlVector[UrlType::PATH_URL].mUrl = "i know you  !!! ";
	urlVector[UrlType::PATH_URL].mTime = 63215888;

	cout << "PATH_URL time = " << urlVector[UrlType::PATH_URL].mTime << endl;
	cout << "PATH_URL url = " << urlVector[UrlType::PATH_URL].mUrl << endl;


	cout  << "容器元素个数， size = " << urlVector.size() << endl;
	
	return 0;

#if 0
	vector<char> myevctor;
	myevctor.resize(1024);
	int length = sizeof(buff1) / sizeof(buff1[0]) - 1;
	cout << "length = " << length << endl;
	cout << sizeof(buff1) / sizeof(buff1[0]) - 1 << endl;

	cout << "size() = " << myevctor.size() << endl;
	// memcpy(&myevctor[0], buff1, length);

	myevctor.assign(&buff1[0], &buff1[length]);
	
	cout << "myevctor[0] = " << myevctor[0] << endl;
	cout << "size() = " << myevctor.size() << endl;

	int length2 = sizeof(buff2) / sizeof(buff2[0]) - 1;
	// memcpy(&myevctor[length], buff2, length2);
	// myevctor.push_back( &buff2[0],  &buff2[length2]);
	myevctor.insert(myevctor.end(), &buff2[0], &buff2[length2]);
	cout << "size() = " << myevctor.size() << endl;

	cout << buff1 << endl;
	cout << myevctor.capacity() << endl;
	cout << myevctor.data() << endl;

	std::stringstream ss;
	DeflatingOutputStream deflater(ss, DeflatingStreamBuf::STREAM_GZIP);
	deflater << myevctor.data();
	deflater.close();
	myevctor.clear();

	ofstream ofs;
	ofs.open("./haha", std::ios_base::out | std::ios_base::binary);
	ofs.write(ss.str().c_str(), ss.str().length());
	ofs.close();
#endif
}

