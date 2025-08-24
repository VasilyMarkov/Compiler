#pragma once
#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>

namespace utility {

inline std::stringstream readFile(const std::filesystem::path& filePath) 
{
    if (!std::filesystem::exists(filePath)) {
        throw std::runtime_error(std::string("File does not exist: ") + filePath.string());
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error(std::string("Failed to open file: ") + filePath.string());
    }

    std::string line;
    std::stringstream stream;
    while (std::getline(file, line)) {
        stream << line << std::endl;
    }
    file.close();
    return stream;
}

} //namespace utility