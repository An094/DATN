#ifndef COMMON_HPP
#define COMMON_HPP

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>


class Common {
public:
	static std::string get_file_contents(const char* filename);
};



#endif // !COMMON_H