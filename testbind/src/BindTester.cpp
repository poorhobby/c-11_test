/*
 * BindTester.cpp
 *
 *  Created on: 2016年5月9日
 *      Author: paul
 */

#include "BindTester.h"
#include "functional"
#include "iostream"
//#include ""

using namespace std;

BindTester::BindTester() {
	// TODO Auto-generated constructor stub

}

BindTester::~BindTester() {
	// TODO Auto-generated destructor stub
}

void BindTester::Test()
{
	std::function<void()> func = std::bind(&BindTester::BindFunction, this);
	func();
}

void BindTester::BindFunction()
{
	std::cout << __func__ << std::endl;
}

