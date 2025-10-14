#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "tokens.hpp"

namespace compiler {

class Parser final {
    using TokensVec = std::vector<std::unique_ptr<tokens::Token>>;
public:
    Parser() = default;

    void addToken(std::unique_ptr<tokens::Token> token){ 
        tokens_.push_back(std::move(token)); 
    }

    const TokensVec& getTokens() const { return tokens_; }

    void parse() {
        for(const auto& el : tokens_) {
            std::cout << el->asString() << std::endl;
        }
    }
private:
    TokensVec tokens_;
};

} //namespace compiler