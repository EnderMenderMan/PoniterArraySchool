#pragma once
#include <iostream>
#include "PointerArray3Inputs.h"

int main()
{
	PointerArray3Inputs<int, std::string, char, 10> multiArray;
	multiArray.AddToAll(90);
	multiArray.GetArray<char>().Add('Y');
	multiArray.GetArray<std::string>().Replace(3, "Hello World!");
	multiArray.PrintAll();
}

/* EXAMPLE 1
PointerArray3Inputs<int, std::string, char, 10> multiArray;
multiArray.AddToAll(90);
multiArray.GetArray<char>().Add('Y');
multiArray.GetArray<std::string>().Replace(3, "Hello World!");
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