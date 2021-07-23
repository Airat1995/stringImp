// CustomStringImpl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "sltbench/Bench.h"
#include "CustomString.h"

void my_function()
{
	CustomString string1 = {"sssssss"};
	CustomString string2 = {"sdsdsd"};
		
	string1.AssignLinkedStringToThis(&string2);
	string1.AppendToThis("asdasdas");
}

void my_str_function()
{
	auto string1 = std::string {"sssssss"};
	auto string2 = std::string {"sdsdsd"};
		
	string1.append(string2);
	string1.append("asdasdas");		
}

SLTBENCH_FUNCTION(my_function);
SLTBENCH_FUNCTION(my_str_function);

SLTBENCH_MAIN();