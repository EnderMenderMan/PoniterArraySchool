#pragma once
#include <iostream>
#include "PointerArray3Inputs.h"

int main()
{
	std::cout << "(Unsorted)\n";
	PointerArray3Inputs<int, std::string, char, 10> multiArray;
	multiArray.AddToAll(90);
	multiArray.AddToAll(50);
	multiArray.GetArray<int>().Add(95);
	multiArray.GetArray<std::string>().Replace(3, "Hello World!");
	multiArray.PrintAll();
	
	std::cout << "\n\n(Sorted)\n";
	multiArray.SortAll();
	multiArray.PrintAll();
}

/* EXAMPLE 1
std::cout << "(Unsorted)\n";
PointerArray3Inputs<int, std::string, char, 10> multiArray;
multiArray.AddToAll(90);
multiArray.AddToAll(50);
multiArray.GetArray<int>().Add(95);
multiArray.GetArray<std::string>().Replace(3, "Hello World!");
multiArray.PrintAll();

std::cout << "\n\n(Sorted)\n";
multiArray.SortAll();
multiArray.PrintAll();
*/

/* EXAMPLE 2
PointerArray<double, 10> pArray;
for (int i = 0; i < 15; i++) {
	if (!pArray.Add(0.1f + i + 1))
		break;
}
pArray.PrintAll();
*/