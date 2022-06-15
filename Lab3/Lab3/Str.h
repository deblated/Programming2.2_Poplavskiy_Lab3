#pragma once
#include <string>

class Str {
private:
	std::string str;

	int length;

	std::string StrGen(int size);

public:
	Str(std::string str) : str(str) { this->length = str.length();};

	Str() :Str("") {};

	void SetValue(std::string str);

	void SetValueRand();

	std::string GetStr();

	int GetLength();

	Str& operator=(const Str& other);
};

void ArrGen(Str* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i].SetValueRand();
	}
}

void CopyArray(Str* CopyFrom, Str* CopyTo, int size) {
	for (int i = 0; i < size; i++)
		CopyTo[i] = CopyFrom[i];
}


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

void Str::SetValue(std::string str) {
	this->str = str;
	this->length = str.length();
}

void Str::SetValueRand() {
	this->SetValue(StrGen(rand() % 10 + 1));
}

std::string Str::GetStr() {
	return this->str;
}

int Str::GetLength() {
	return this->length;
}

Str& Str::operator=(const Str& other) {
	this->str = other.str;
	this->length = other.length;
	return *this;
}

