#pragma once

#include <string>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <ranges>

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

template<typename T>
concept Printable = requires(std::ostream& os, const T& t) {
    {os << t} -> std::same_as<std::ostream&>;
};

template<std::ranges::range Range>
requires Printable<typename std::decay_t<Range>::value_type>
void print(const Range& range) {
    if constexpr(requires {typename Range::key_type; typename Range::mapped_type;}) {
        for(const auto& [key, value] : range) {
            std::cout << key << ": " << value << ", ";
        }
    }
    else {
        for(const auto& el : range) {
            std::cout << el << ", ";
        }
        std::cout << std::endl;
    }
}

} //namespace utility