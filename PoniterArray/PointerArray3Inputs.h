#pragma once
#include "PointerArray.h"
#include <string>

//@brief PointerArray3Inputs<type, type, type, int arrayMaxSizes>
template <typename T1,typename T2,typename T3, int size>
class PointerArray3Inputs
{
public:
	PointerArray3Inputs() {
		if (typeid(T1) == typeid(T2) || typeid(T1) == typeid(T3) || typeid(T2) == typeid(T3))
		{
			std::cout << "Can't have multiple of the same typename declaration!!! \nError: PointerArray3Inputs<" << typeid(T1).name() << ", " << typeid(T2).name() << ", " << typeid(T3).name() << ">\nFunctional example: PointerArray3Inputs<bool, double, int>\n";
			exit(0);
		}
	};
	//@brief add a int value to all arrays even if it's not a int array.
	void AddToAll(int value) {
		AddValue<T1>(value);
		AddValue<T2>(value);
		AddValue<T3>(value);
	}
	//@brief Sort all arrays in ascending order.
	void SortAll() {
		array1.Sort();
		array2.Sort();
		array3.Sort();
	}
	//@brief Reverse the order of the elements in all arrays.
	void ReverseAll() {
		array1.Reverse();
		array2.Reverse();
		array3.Reverse();
	}
	//@brief Print all elements in all arrays.
	void PrintAll() {
		if (array1.GetCount() > 0) {
			WriteLable<T1>();
			array1.PrintAll();
		}
		if (array2.GetCount() > 0) {
			WriteLable<T2>();
			array2.PrintAll();
		}
		if (array3.GetCount() > 0) {
			WriteLable<T3>();
			array3.PrintAll();
		}
	}
	//@return The array of given type
	template<typename T> PointerArray<T, size>& GetArray() { return GetType<T>(); }
private:

	PointerArray<T1, size> array1;
	PointerArray<T2, size> array2;
	PointerArray<T3, size> array3;

	template<typename T>
	PointerArray<T, size>& GetType() {

		if constexpr (std::is_same_v<T, T1>)
			return array1;
		else if constexpr (std::is_same_v<T, T2>)
			return array2;
		else if constexpr (std::is_same_v<T, T3>)
			return array3;
		std::cout << "PointerArray3Inputs<"<<typeid(T1).name()<<", "<< typeid(T2).name() <<", "<< typeid(T3).name() << "> does not contain a definition for " << typeid(T).name()<<std::endl;
		exit(0);
	};
	template<typename T>
	void WriteLable() {

		if constexpr (std::is_same_v<T, std::string>)
			std::cout << "--string--" << std::endl;
		else
			std::cout << "--" << typeid(T).name() << "--" << std::endl;
	};
	template<typename T>
	void AddValue(int value) {

		if constexpr (std::is_same_v<T, std::string>)
			GetType<T>().Add(std::to_string(value));
		else
			GetType<T>().Add(value);
	};

};