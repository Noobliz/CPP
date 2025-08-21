
#include "replaceOcc.hpp"


std::string replaceOcc(const std::string &line, const std::string &s1, const std::string &s2){
	size_t start = 0;
	size_t pos;
	std::string result;
	if (s1.empty())
		return result;
	while ((pos = line.find(s1, start)) != std::string::npos){
		if (pos > line.size())
			break;
		result += line.substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
	}
	if (start <= line.size())
		result += line.substr(start);
	return result;
}