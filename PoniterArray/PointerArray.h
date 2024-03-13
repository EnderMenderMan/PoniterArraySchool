#pragma once
//@brief PointerArray<type, int maxSize>
template <typename T,int size>
class PointerArray
{
private:

	struct Deref {
		PointerArray& a;
		int index;
		Deref(PointerArray& a, int index) : a(a), index(index) {}

		operator T() {
			if (a.arrayT[index] == nullptr)
				return NULL; // mabe nullptr is better?
			return *a.arrayT[index];
		}

		T& operator=(const T& other) {
			if (a.arrayT[index] == nullptr)
				a.Replace(index, 0);
			return *a.arrayT[index] = other;
		}
	};

	void CheckIndexBounds(int index);
	T* arrayT[size] = {};
	int count = 0;
public:
	 //@brief Get the current count of elements in the array.
	int GetCount();

	 //@brief Get the maximum size of the array.
	int GetMaxSize();

	 //@brief Add an element to the array.
	 //@return True if the element was added successfully, false otherwise.
	bool Add(T element);

	//@brief Replace the element at the given index with a new element.
	void Replace(int index, T element);

	//@brief Remove the first occurrence of the specified element from the array.
	void Remove(T element);

	//@brief Remove all occurrences of the specified element from the array.
	void RemoveAll(T element);

	//@brief Remove the element at the specified index from the array.
	void RemoveAt(int index);

	//@brief Check if the specified element exists in the array.
	//@return True if the element exists, false otherwise.
	bool Exist(T element);

	//@brief Check if an element exists at the specified index in the array.
	//@return True if an element exists at the index, false otherwise.
	bool ExistElementAt(int index);

	//@brief Removing all elements in the array.
	void Clear();

	//@brief Sort the elements of the array.
	void Sort();

	//@brief Reverse the order of elements in the array.
	void Reverse();

	//@brief Print all elements of the array.
	void PrintAll();

	//@brief Get the element at the specified index.
	T GetAtIndex(int index);
	Deref operator[](int index) {
		return Deref(*this, index);
	}
};

// Functions
template <typename T, int size>
int PointerArray<T, size>::GetCount() {
	return count;
}
template <typename T, int size>
int PointerArray<T, size>::GetMaxSize() {
	return size;
}
template <typename T, int size>
bool PointerArray<T, size>::Add(T element) {

	for (int i = 0; i < size; i++) {
		if (arrayT[i] == nullptr)
		{
			count++;
			arrayT[i] = new T(element);
			return true;
		}
	}
	return false;
}
template <typename T, int size>
void PointerArray<T, size>::Replace(int index, T element) {
	CheckIndexBounds(index);

	if (arrayT[index] != nullptr)
		delete arrayT[index];
	else
		count++;
	
	arrayT[index] = new T(element);
}
template <typename T, int size>
void PointerArray<T, size>::Remove(T element) {
	for (int i = 0; i < size; i++)
	{
		if (arrayT[i] != element)
			continue;

		delete arrayT[i];
		arrayT[i] == nullptr;
		count--;
		break;

	}
}
template <typename T, int size>
void PointerArray<T, size>::RemoveAll(T element) {
	for (int i = 0; i < size; i++)
	{
		if (arrayT[i] != element)
			continue;

		delete arrayT[i];
		arrayT[i] == nullptr;
		count--;

	}
}
template <typename T, int size>
void PointerArray<T, size>::RemoveAt(int index) {
	CheckIndexBounds(index);

	if (arrayT[index] == nullptr)
		return;

	delete arrayT[index];
	arrayT[index] = nullptr;
	count--;
}
template <typename T, int size>
bool PointerArray<T, size>::Exist(T elemnt) {
	for (int i = 0; i < size; i++) {
		if (arrayT[i] != nullptr && elemnt == *arrayT[i])
			return true;
	}
	return false;
}
template <typename T, int size>
bool PointerArray<T, size>::ExistElementAt(int index) {
	if (arrayT[index] == nullptr)
		return false;
	return true;
}
template <typename T, int size>
void PointerArray<T, size>::Clear() {

	for (int i = 0; i < size; i++) {
		if (arrayT[i] == nullptr)
			continue;

		delete arrayT[i];
		arrayT[i] = nullptr;
		count--;

		if (count == 0)
			break;
	}
}
template <typename T, int size>
void PointerArray<T, size>::Sort() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1-i; j++) {
			if (*arrayT[j] > *arrayT[j + 1]) {
				T* tempValue = arrayT[j + 1];
				arrayT[j + 1] = arrayT[j];
				arrayT[j] = tempValue;
			}
		}
	}
}
template <typename T, int size>
void PointerArray<T, size>::Reverse() {
	for (int i = 0; i < size/2; i++) {
		T* tempValue = arrayT[size-1-i];
		arrayT[size - 1 - i] = arrayT[i];
		arrayT[i] = tempValue;
	}
}
template <typename T, int size>
void PointerArray<T, size>::PrintAll() {
	for (int i = 0; i < size; i++) {
		if (arrayT[i] == nullptr)
			continue;
		std::cout << *arrayT[i] << std::endl;
	}
}
template <typename T, int size>
T PointerArray<T, size>::GetAtIndex(int index) {
	CheckIndexBounds(index);
	return *arrayT[index];
}
template <typename T, int size>
void PointerArray<T, size>::CheckIndexBounds(int index) {
	if (index < 0 || index >= size)
	{
		std::cout << "\nIndex out of bounds! inputed index: " << index << " Max index: " << size - 1 << " \n";
		std::exit(0);
	}
}