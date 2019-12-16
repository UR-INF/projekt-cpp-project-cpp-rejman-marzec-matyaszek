#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
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

	int time() {
		String^ m = min;
		std::string minute = msclr::interop::marshal_as<std::string>(m);
		String^ s = sec;
		std::string secunde = msclr::interop::marshal_as<std::string>(s);

		int mInt = std::stoi(minute);
		int sInt = std::stoi(secunde);

		mInt = mInt * 60;
		return mInt + sInt;
	}

};

