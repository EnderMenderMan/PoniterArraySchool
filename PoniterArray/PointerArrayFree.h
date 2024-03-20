#pragma once
//@brief PointerArrayFree<int maxSize,Type, . . .> Add all types than you should be able to use in the PointerArrayFree
template <int size, typename... Ts>
class PointerArrayFree
{
private:

	template <typename T, typename T2>
	void CompareType(int& index, bool& isFound);
	template <typename T>
	int GetTypeIndex();
	void PrintElement(int arrayIndex);
	template <int index>
	void SortHidden(int sortArray[], int &placeIndex);
	// Checks
	template <typename T>
	void CheckIfTExist();
	void CheckIndexBounds(int index);
	struct
	{
		void* Pointer = nullptr;
		int Type;
	} arrayT[size] = {};
	int count = 0;
public:
	//@brief Get the current count of elements in the array.
	int GetCount();

	//@brief Get the maximum size of the array.
	int GetMaxSize();

	//@brief Add an element to the array.
	//@return True if the element was added successfully, false otherwise.
	template <typename T>
	bool Add(T element);

	//@brief Replace the element at the given index with a new element.
	template <typename T>
	void Replace(int index, T element);

	//@brief Remove the first occurrence of the specified element from the array.
	template <typename T>
	void Remove(T element);

	//@brief Remove all occurrences of the specified element from the array.
	template <typename T>
	void RemoveAll(T element);
	//@brief Remove all occurrences of the specified type from the array.
	template <typename T>
	void RemoveAll();

	//@brief Remove the element at the specified index from the array.
	void RemoveAt(int index);

	//@brief Check if the specified element exists in the array.
	//@return True if the element exists, false otherwise.
	template <typename T>
	bool Exist(T element);

	//@brief Check if an element exists at the specified index in the array.
	//@return True if an element exists at the index, false otherwise.
	bool ExistElementAt(int index);

	//@brief Removing all elements in the array.
	void Clear();

	//@brief Pushes all none NULL elemets to the start of the array.
	void Stack();

	//@brief Sort the elements of the array.
	void Sort();

	//@brief Reverse the order of elements in the array.
	void Reverse();

	//@brief Print all elements of the array.
	void PrintAll();

	//@brief Get the element at the specified index.
	template <typename T>
	auto GetAtIndex(int index);
	//@brief Get the Nth element of the type given
	template <typename T>
	auto GetElement(int NthPlace);
};

// Functions
template <int size, typename... Ts>
int PointerArrayFree<size, Ts...>::GetCount() {
	return count;
}
template <int size, typename... Ts>
int PointerArrayFree<size, Ts...>::GetMaxSize() {
	return size;
}
template <int size, typename... Ts>
template <typename T>
bool PointerArrayFree<size, Ts...>::Add(T element) {
	CheckIfTExist<T>();

	for (int i = 0; i < size; i++) {
		if (arrayT[i].Pointer == nullptr)
		{
			count++;
			arrayT[i].Pointer = new T(element);
			arrayT[i].Type = GetTypeIndex<T>();
			return true;
		}
	}
	return false;
}
template <int size, typename... Ts>
template <typename T>
void PointerArrayFree<size, Ts...>::Replace(int index, T element) {
	CheckIndexBounds(index);
	CheckIfTExist<T>();
	if (arrayT[index].Pointer != nullptr)
		delete arrayT[index].Pointer;
	else
		count++;

	arrayT[index].Pointer = new T(element);
	arrayT[index].Type = GetTypeIndex<T>();
}
template <int size, typename... Ts>
template <typename T>
void PointerArrayFree<size, Ts...>::Remove(T element) {
	CheckIfTExist<T>();

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
template <int size, typename... Ts>
template <typename T>
void PointerArrayFree<size, Ts...>::RemoveAll(T element) {
	CheckIfTExist<T>();
	int Tindex = GetTypeIndex<T>();
	for (int i = 0; i < size; i++)
	{
		if (!(Tindex == arrayT[i].Type && *(T*)arrayT[i].Pointer == element))
			continue;
		delete arrayT[i].Pointer;
		arrayT[i].Pointer = nullptr;
		count--;

	}
}
template <int size, typename... Ts>
template <typename T>
void PointerArrayFree<size, Ts...>::RemoveAll() {
	CheckIfTExist<T>();
	int Tindex = GetTypeIndex<T>();
	for (int i = 0; i < size; i++)
	{
		if (Tindex != arrayT[i].Type)
			continue;

		delete arrayT[i].Pointer;
		arrayT[i].Pointer = nullptr;
		count--;
	}
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::RemoveAt(int index) {
	CheckIndexBounds(index);

	if (arrayT[index].Pointer == nullptr)
		return;

	delete arrayT[index].Pointer;
	arrayT[index].Pointer = nullptr;
	count--;
}
template <int size, typename... Ts>
template <typename T>
bool PointerArrayFree<size, Ts...>::Exist(T elemnt) {
	CheckIfTExist<T>();
	int Tindex = GetTypeIndex<T>();

	for (int i = 0; i < size; i++) {
		if (arrayT[i].Pointer != nullptr && Tindex == arrayT[i].Type && elemnt == *(T*)arrayT[i].Pointer)
			return true;
	}
	return false;
}
template <int size, typename... Ts>
bool PointerArrayFree<size, Ts...>::ExistElementAt(int index) {
	CheckIndexBounds(index);
	if (arrayT[index].Pointer == nullptr)
		return false;
	return true;
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::Clear() {

	for (int i = 0; i < size; i++) {
		if (arrayT[i].Pointer == nullptr)
			continue;

		delete arrayT[i].Pointer;
		arrayT[i].Pointer = nullptr;
		count--;

		if (count == 0)
			break;
	}
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::Stack() {
	if (count <= 1)
		return;
	int placeIndex = 0;

	for (int i = 0; i < size; i++) {
		if (arrayT[i].Pointer == nullptr)
			continue;

		if (i == placeIndex)
		{
			placeIndex++;
		}
		else
		{
			arrayT[placeIndex] = arrayT[i];
			arrayT[i].Pointer = nullptr;
			placeIndex++;
		}
	}
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::Sort() {
	if (count <= 1)
		return;
	Stack();
	int sortArray[sizeof...(Ts)];
	for (int i = 0; i < sizeof...(Ts); i++)
	{
		sortArray[i] = 0;
		for (int j = 0; j < count; j++)
		{
			if (arrayT[j].Pointer != nullptr && arrayT[j].Type == i)
				sortArray[i]++;
		}
	}
	int placeIndex = 0;
	SortHidden<0>(sortArray, placeIndex);
}
template <int size, typename... Ts>
template <int index>
void PointerArrayFree<size, Ts...>::SortHidden(int sortArray[], int& placeIndex) {
	if constexpr (index < sizeof...(Ts)) {
		using ElementType = std::tuple_element_t<index, std::tuple<Ts...>>;
		ElementType* sortingT = new ElementType[sortArray[index]];

		// set T valus
		int sortingTIndex = 0;
		for (int i = 0; i < count; i++) {
			if (arrayT[i].Type == index) {
				sortingT[sortingTIndex] = *(ElementType*)(arrayT[i].Pointer);
				++sortingTIndex;
				if (sortingTIndex == sortArray[index])
					break;
			}
		}
		// buble sort
		for (int i = 0; i < sortArray[index]; i++) {
			for (int j = 0; j < sortArray[index] - 1 - i; j++) {
				if (sortingT[j] > sortingT[j + 1]) {
					auto tempValue = sortingT[j + 1];
					sortingT[j + 1] = sortingT[j];
					sortingT[j] = tempValue;
				}
			}
		}

		SortHidden<index + 1>(sortArray, placeIndex);

		// push to array
		for (int i = 0; i < sortArray[index]; i++) {
			arrayT[placeIndex].Pointer = &sortingT[i];
			arrayT[placeIndex].Type = index;
			placeIndex++;
		}
	}
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::Reverse() {
	for (int i = 0; i < size / 2; i++) {
		auto tempValue = arrayT[size - 1 - i];
		arrayT[size - 1 - i] = arrayT[i];
		arrayT[i] = tempValue;
	}
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::PrintAll() {
	for (int i = 0; i < size; i++) {
		if (arrayT[i].Pointer == nullptr)
			continue;
		PrintElement(i);
	}
}
template <int size, typename... Ts>
template <typename T>
auto PointerArrayFree<size, Ts...>::GetAtIndex(int index) {
	CheckIfTExist<T>();
	CheckIndexBounds(index);
	int Tindex = GetTypeIndex<T>();
	if (Tindex != arrayT[index].Type) {
		std::cout << "\"" << typeid(T).name()<<"\" is not the type at index " << index << std::endl;
		exit(0);
	}

	return *(T*)arrayT[index].Pointer;
}
template <int size, typename... Ts>
template <typename T>
auto PointerArrayFree<size, Ts...>::GetElement(int place) {
	CheckIfTExist<T>();
	CheckIndexBounds(place);
	int Tindex = GetTypeIndex<T>();
	int currentPlace = 0;
	for (int i = 0; i < size; i++)
	{
		if (arrayT[i].Pointer == nullptr)
			continue;

		if  (Tindex == arrayT[i].Type) {
			if (currentPlace == place-1)
				return *(T*)arrayT[i].Pointer;
			else
				currentPlace++;
		}
	}
	return (T)NULL;
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::CheckIndexBounds(int index) {
	if (index < 0 || index >= size)
	{
		std::cout << "\nIndex out of bounds! inputed index: " << index << " Max index: " << size - 1 << " \n";
		std::exit(0);
	}
}
template <int size, typename... Ts>
template <typename T>
int PointerArrayFree<size, Ts...>::GetTypeIndex() {
	int index = 0;
	bool isFound = false;

	(CompareType<T,Ts>(index,isFound), ...);

	if (index == sizeof...(Ts))
		index = -1;
	return index;
}
template <int size, typename... Ts>
template <typename T, typename T2>
void PointerArrayFree<size, Ts...>::CompareType(int &index,bool &isFound) {
	if (isFound)
		return;

	if constexpr (std::is_same_v<T, T2>)
		isFound = true;
	else
		index++;
}
template <int size, typename... Ts>
template <typename T>
void PointerArrayFree<size, Ts...>::CheckIfTExist() {
	if (GetTypeIndex<T>() == -1)
	{
		std::cout << "Type: \"" << typeid(T).name() << "\" have not been declared in the PointerArrayFree\nSolution Example: PointerArrayFree<15,long>\n";
		exit(0);
	}
}
template <int size, typename... Ts>
void PointerArrayFree<size, Ts...>::PrintElement(int arrayIndex) {
	int index = 0;
	([&]
	{
			if (index == arrayT[arrayIndex].Type)
			{
				if (typeid(std::string) == typeid(Ts))
					std::cout <<"[" << arrayIndex << "] (string) " << *(Ts*)arrayT[arrayIndex].Pointer << std::endl;
				else
					std::cout << "[" << arrayIndex << "] (" << typeid(Ts).name() << ") " << *(Ts*)arrayT[arrayIndex].Pointer<< std::endl;
			}
		index++;

	} (), ...);
}
//*(decltype(std::tuple_element_t<index, std::tuple<Ts...>>)*)arrayT[arrayIndex].Pointer;