#include <iostream>
#include <print>
#include "lexer.hpp"  // Include the generated lexer
#include "utility.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << argc << std::endl;
		std::cerr << "Wrong arguments!" << std::endl;
		return 1;
	}
	try {
		fs::path filePath = argv[1];
		auto file = utility::readFile(filePath);
		Driver driver(file);
		driver.parse();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}



	return 0;
}