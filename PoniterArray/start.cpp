#pragma once
#include <iostream>
#include "PointerArrayFree.h"
//#include "PointerArray.h"
//#include "PointerArray3Inputs.h"
int main()
{
	PointerArrayFree<10,int,float,std::string> freeArray;
	freeArray.Add<float>(10);
	freeArray.Add<std::string>("YWY");
	freeArray.Add<float>(1);
	freeArray.Add<int>(90);
	freeArray.Add<int>(15);
	freeArray.Replace<float>(8, 50);
	std::cout << "--Unsorted--\n";
	freeArray.PrintAll();
	freeArray.Sort();

	std::cout << "\n\n--Sorted--\n";
	freeArray.PrintAll();
}
/* EXAMPLE 1 - PointerArrayFree
PointerArrayFree<10,int,float,std::string> freeArray;
freeArray.Add<float>(10);
freeArray.Add<std::string>("YWY");
freeArray.Add<float>(1);
freeArray.Add<int>(90);
freeArray.Add<int>(15);
freeArray.Replace<float>(8, 50);
std::cout << "--Unsorted--\n";
freeArray.PrintAll();
freeArray.Sort();

std::cout << "\n\n--Sorted--\n";
freeArray.PrintAll();
*/
/* EXAMPLE 2 - PointerArray3Inputs
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

/* EXAMPLE 3 - PointerArray
PointerArray<double, 10> pArray;
for (int i = 0; i < 15; i++) {
	if (!pArray.Add(0.1f + i + 1))
		break;
}
pArray.PrintAll();
*/