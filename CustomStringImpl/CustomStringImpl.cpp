// CustomStringImpl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sltbench/Bench.h"
#include "CustomString.h"
#include "DumbString.h"

void my_function()
{
	 std::srand(std::time(nullptr)); // use current time as seed for random generator
	
	CustomString string1 = {"sssssss"};
	CustomString string2 = {"sdsdsd"};

	for (int n=0; n != 20; ++n)
	{
		const char* str = new char[]{static_cast<char>(std::rand())};
		string1.AppendToThis(str);
	}
}

void my_dumb_function()
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	DumbString string1 = {"sssssss"};
	DumbString string2 = {"sdsdsd"};
	for (int n = 0; n != 20; ++n)
	{
		const char* str = new char[]{static_cast<char>(std::rand())};
		string1.AppendToThis(str);
	}
}

void my_str_function()
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	auto string1 = std::string{"sssssss"};
	auto string2 = std::string{"sdsdsd"};

	for (int n = 0; n != 20; ++n)
	{
		const char* str = new char[]{static_cast<char>(std::rand())};
		string1.append(str);
	}
}

SLTBENCH_FUNCTION(my_function);
SLTBENCH_FUNCTION(my_dumb_function);
SLTBENCH_FUNCTION(my_str_function);

SLTBENCH_MAIN();