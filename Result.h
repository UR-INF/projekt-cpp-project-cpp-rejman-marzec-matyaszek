#pragma once
#include <string>
using namespace System;
ref class Result
{
public:
	String^ name;
	String^ min;
	String^ sec;

public:

	
	Result(String^ name, String^ min, String^ sec)
	{
		this->name = name;
		if (min->Length == 1) min = "0" + min;
		this->min = min;
		if (sec->Length == 1) sec = "0" + sec;
		this->sec = sec;
	}

private:

};

