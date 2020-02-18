#pragma once
#include <algorithm>
template<class C>
class vec {
	int size;
	int currpos;
	C* arr;
	typedef C* iterator;
	typedef const C* const_iterator;
public:
	iterator begin() { return &(*arr); }
	const_iterator begin() const { return &(*arr); }
	iterator end() { return &(*(arr+currpos+1)); }
	const_iterator end() const { return &(*(arr + currpos + 1)); }

	vec(const int &num = 0) : size(num), currpos(num - 1)
	{
		if (size < 0) {
			std::cerr << "Error: you're too dumb to use this class";
			abort();
		}
		arr = new C[size];
	}
	void addBack(const C &value) {
		if (++currpos >= size) {
			C* newArr = new C[size + 50];
			/*for (int i = 0; i < size; i++) {
				newArr[i] = arr[i];
			}
			int i = 0;
			for (C* pc = arr, *pl = arr + size; pc < pl; ++pc, ++i) {
				*(newArr + i) = *pc;
			}
			//realloc(arr, (size+50)*sizeof(*arr));*/
			memcpy(newArr, arr, size*sizeof(*arr));
			delete[] arr;
			arr = newArr;
			size += 50;
		}
		*(arr + currpos) = value;
		size++;
	}
	void deleteBack() {
		*(arr + currpos--) = NULL;
	}
	const int& length() {
		return currpos + 1;
	}
	const int& reserved() {
		return size;
	}
	void reserve(const int &newSize) {
		if (newSize < 0) {
			std::cerr << "\nError: can't reserve a negative number";
			return; 
		}
		C* newArr = new C[currpos + 1 + newSize];
		memcpy(newArr, arr, size * sizeof(*arr));
		delete[] arr;
		arr = newArr;
		size = newSize;
	}
	const int& find(const C &value, const int &startOrEnd = 0) {
		if (startOrEnd >= 0)
			for (C *pc = arr, *pl = arr + currpos + 1; pc < pl; ++pc) {
				if (*pc == value)
					return pc - arr;
			}
		else
			for (C *pc = arr + currpos + 1, *pl = arr; pc >= pl; pc--) {
				if (*pc == value)
					return pc - arr;
			}
		return -1;
	}
	~vec() {
		delete[] arr;
	}
	void arrSort(const int &type = 0) {
		std::sort(arr, arr + currpos + 1, [&](const C& a, const C& b) -> bool
			{
				return ((type >= 0) ? a > b : a < b);
			});
	}
	C& operator[](const int &index) {
		try {
			if (index <= currpos && index >= 0)
				return *(arr + index);
			else if (index < 0 && currpos >= -index)
				return *(arr + currpos + index + 1);
			else
				throw (std::string)"\nError: wrong access to memory";
		}
		catch (std::string e) {
			std::cerr << e;
			abort();
		}
		catch (...) {
			std::cerr << "\nError: unidentified error";
			abort();
		}
	}
	vec<C>& operator=(const vec<C> &vector) {
		this->size = vector.size;
		this->arr = new C[size];
		this->currpos = vector.currpos;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const vec& thes) {
		std::string sus(typeid(thes.arr[0]).name());
		std::string sis(sus, 0, (sus.length() > 9) ? 9 : sus.length());
		if(sis == "class vec")
			for (int i = 0; i < thes.currpos; i++) {
				std::string sos(typeid(thes.arr[i]).name());//dunno what to do about this
				std::string sas(sos, 0, (sos.length() > 9) ? 9 : sos.length());//as long as it works for me
				out << thes.arr[i] << ((sas == "class vec") ? "" : ", ");//this shit will be there
			}
		else
			for (int i = 0; i < thes.currpos; i++) {
				out << thes.arr[i] << ", ";
			}
		out << thes.arr[thes.currpos] << std::endl;
		return out;
	}
};
template<>
void vec<char>::arrSort(const int &type) {
	std::sort(arr, arr + currpos + 1, [&](char a, char b) -> bool
		{ 
			if ((int)(a) >= 65 && (int)(a) <= 90) a += 32;
			if ((int)(b) >= 65 && (int)(b) <= 90) b += 32;
			return ((type >= 0) ? a < b : a > b);
		});
}
void vec<std::string>::arrSort(const int &type) {
	std::sort(arr, arr + currpos + 1, [&](std::string a, std::string b) -> bool
		{
			for (int i = 0; i < a.length(); i++)
				if ((int)(a[i]) >= 65 && (int)(a[i]) <= 90) a[i] += 32;
			for (int i = 0; i < b.length(); i++)
				if ((int)(b[i]) >= 65 && (int)(b[i]) <= 90) b[i] += 32;
			return ((type >= 0) ? a < b : a > b);
		});
}