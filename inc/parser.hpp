#pragma once
#include <vector>
#include <iostream>
#include "tokens.hpp"

namespace compiler {

class Parser {
    using TokensVec = std::vector<tokens::token_t>;
public:
    explicit Parser() {}
    void addToken(tokens::token_t token) { tokens_.push_back(token); }
    const TokensVec& getTokens() const { return tokens_; }
    void parse() {
        for(auto&& el : tokens_) {
            std::cout << (int)el << std::endl;
        }
    }
private:
    TokensVec tokens_;
};

} //namespace compiler