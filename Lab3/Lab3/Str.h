#pragma once
#include <string>
///String class
class Str {
private:
	///String
	std::string str;
	///Length of string
	int length;
	std::string StrGen(int size);

public:
	/*!
	\brief Constructor that creates object with particular text
	*/
	Str(std::string str) : str(str) { this->length = str.length();};
	/*!
	\brief Default constructor that creates object with empty text
	*/
	Str() :Str("") {};
	void SetValue(std::string str);
	void SetValueRand();
	std::string GetStr();
	int GetLength();
	Str& operator=(const Str& other);
};

/*!
\brief Creates an array filled with random values
\param[in] arr - Array to fill
\param[in] size - Size of array to fill
*/
void ArrGen(Str* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i].SetValueRand();
	}
}
/*!
\brief Creates an array filled with random values
\param[in] CopyFrom - Array from which we will copy the data
\param[in] CopyTo - Array to which we will copy the data
\param[in] size - Size of these arrays
*/
void CopyArray(Str* CopyFrom, Str* CopyTo, int size) {
	for (int i = 0; i < size; i++) {
		CopyTo[i] = CopyFrom[i];
	}
}
/*!
\brief Creates a random string
\param[in] size - Size of string to generate
*/
std::string Str::StrGen(int size) {
	std::string str;
	str.reserve(size);
	char ch;
	for (int i = 0; i < size; i++) {
		ch = rand() % 26 + 'A';
		str.push_back(ch);
	}
	return str;
}
/*!
\brief Setter for object
\param[in] str - String to copy
*/
void Str::SetValue(std::string str) {
	this->str = str;
	this->length = str.length();
}
/*!
\brief Setter with random string
*/
void Str::SetValueRand() {
	this->SetValue(StrGen(rand() % 10 + 1));
}
/*!
\brief Getter for string
*/
std::string Str::GetStr() {
	return this->str;
}
/*!
\brief Getter for length
*/
int Str::GetLength() {
	return this->length;
}
/*!
\brief Operator "="
\param[in] other - Object from which we will take the information
*/
Str& Str::operator=(const Str& other) {
	this->str = other.str;
	this->length = other.length;
	return *this;
}

