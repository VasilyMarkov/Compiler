#pragma once

#include <FlexLexer.h>
#include <sstream>
#include "parser.hpp"
#include "utility.hpp"

namespace yy {

class Lexer final : public yyFlexLexer {
public:
    Lexer(): yyFlexLexer() {}

    int yylex() override {
        return yyFlexLexer::yylex();
    };
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
        while (yylex() != 0) {}
        parser_.parse();
    }

    int yylex() {
        auto token = static_cast<tokens::token_t>(lexer_->yylex());
        parser_.addToken(token);
        return static_cast<int>(token);
    }
private:
    std::unique_ptr<yy::Lexer> lexer_;
    Parser parser_;
};

} //namespace compiler