#pragma once
#include <exception>
#include <string>
class EmptyPtr :public std::exception  {

	std::string str;
public:
	EmptyPtr(const char* temp): str(temp) {}
	const char* what() {
		return str.c_str();
	}
};