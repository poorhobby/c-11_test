//============================================================================
// Name        : right_reference.cpp
// Author      : paul.pu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class RightReference
{
public:
	RightReference();
	virtual ~RightReference();
	// this is not needed, define a copy constructor instead.
	RightReference(RightReference &&other);
	RightReference(const RightReference &other);
	RightReference& operator=(const RightReference &other);
	RightReference& operator=(RightReference &&other);
	void Print();

};

RightReference::RightReference()
{
	std::cout << "[RR]constructor" << std::endl;
}

RightReference::~RightReference()
{

}

RightReference::RightReference( const RightReference &other)
{
	std::cout << "[RR]using copy constructor..." << std::endl;
}
void RightReference::Print()
{
	std::cout << "[RR]xxx" << std::endl;
}

RightReference& RightReference::operator=(const RightReference &other)
{
	std::cout << "[RR]using operator=(X &)..." << std::endl;
	return *this;
}

RightReference& RightReference::operator=(RightReference &&other)
{
	std::cout << "[RR]using operator=(X &&).." << std::endl;
	return *this;
}

RightReference::RightReference(RightReference &&other)
{
	std::cout << "[RR]using RightReference(RightReference &&other)" << std::endl;
}

RightReference Generate()
{
	RightReference rr;
	return rr;
}

int main() {
	RightReference rr;

	RightReference rrr;

	std::cout << "this will use operator=( X&&)" << std::endl;
	rr = Generate();

	rr.Print();

	std::cout << "this will use operator=(X &&), too" << std::endl;
	rrr = std::move(rr);

	std::cout << "this will use RightReference(RightReference &&other)" << std::endl;
	RightReference rrrr(std::move(rrr));

	std::cout << "this will use copy constructor" << std::endl;
	RightReference rrrrr(Generate());

	std::cout << "this will use operator=(X&)" << std::endl;
	rrrrr  =  rrr;

	// shouldn't use this any more
	// if the RightReference has some data pointer,
	// its reference should be moved to rrr,
	// now it should be nullptr.
//	rr.Print();

	return 0;
}
