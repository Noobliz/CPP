
#include "replaceOcc.hpp"
// ifstream = input file stream to read from a file
// ofstream = output file "" to write and create file
// c_str to convert string to str because of c++98
int main (int argc, char **argv)
{

	if (argc != 4)
	{
		std::cerr << "expected input: ./replace <filename> <s1> <s2>" <<std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	 if (!input.is_open()) {
        std::cerr << "Error: Cannot open input file: "<< argv[1] << std::endl;
        return 1;
    }

	std::string outFile = std::string(argv[1]) + ".replace";
	std::ofstream output(outFile.c_str());
    if (!output.is_open()) {
        std::cerr << "Error: Cannot create output file" << std::endl;
		input.close();
        return 1;
    }

	std::string result;
	while (std::getline(input, result)){
		output<<replaceOcc(result, argv[2], argv[3]);
		if (!input.eof())
			output<<std::endl;
	}
	input.close();
	output.close();
	return 0;
}