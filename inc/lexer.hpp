#pragma once

#include <FlexLexer.h>
#include <sstream>
#include "parser.hpp"
#include "utility.hpp"

namespace yy {

class Lexer final : public yyFlexLexer {
public:
    Lexer(): yyFlexLexer() {}
};

} //namespace yy

namespace compiler {

class FrontEnd final {
public:
    explicit FrontEnd(std::stringstream& file): lexer_(std::make_unique<yy::Lexer>())
    {
        lexer_->switch_streams(file, std::cout);
    }
    void parse() {
        while (yylex() != tokens::token_t::END) {}
        parser_.parse();
    }

    tokens::token_t yylex() {
        auto token = static_cast<tokens::token_t>(lexer_->yylex());
        parser_.addToken(createToken(token));
        return token;
    }

    std::unique_ptr<tokens::Token> createToken(tokens::token_t token) {
        switch (token)
        {
        case tokens::token_t::PLUS:
            return std::make_unique<tokens::PlusToken>();
        case tokens::token_t::MINUS:
            return std::make_unique<tokens::MinusToken>();
        case tokens::token_t::NUMBER:
            return std::make_unique<tokens::NumberToken>(std::stoi(lexer_->YYText()));
        }
    }

private:
    std::unique_ptr<yy::Lexer> lexer_;
    Parser parser_;
};

} //namespace compiler