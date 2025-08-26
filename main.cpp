#include <iostream>
#include <print>
#include "lexer.hpp"
#include "utility.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::println("Wrong arguments!");
		return 1;
	}
	try {
		fs::path filePath = argv[1];
		auto file = utility::readFile(filePath);
		compiler::FrontEnd frontend(file);
		frontend.parse();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}



	return 0;
}