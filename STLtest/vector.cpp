/*
 * @Author: your name
 * @Date: 2020-11-22 21:48:09
 * @LastEditTime: 2021-01-18 23:01:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \PocoTset\STLtest\vector.cpp
 */
/*
 * @Author: your name
 * @Date: 2020-03-28 22:49:41
 * @LastEditTime: 2020-11-22 21:46:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \PocoTset\main.cpp
 */


#include  <stdio.h>           
#include "unistd.h" 
#include <iostream>
#include "DeflatingStream.h"

#include <vector>
#include <fstream>
#include <fcntl.h>
#include <sstream>
#include "/usr/include/string.h"
#include <string.h>


using namespace std;
using namespace Poco;

char buff1[] = {"12345688888889"};
char buff2[] = {"BAAAAAAAAAAAAAAAAB"};

int intbuff[] = {1,2,3,4,5};

std::string name;
std::string age;

int urlexpere = 0;

int main()
{
    vector<std::string> strevctor;


    // vector<uint16_t> uintevctor;

	strevctor.resize(1024);



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

