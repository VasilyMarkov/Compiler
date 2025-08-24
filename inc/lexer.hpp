#pragma once
#include <FlexLexer.h>
#include <sstream>
namespace yy {

class Lexer final : public yyFlexLexer {
public:
    Lexer(): 
        yyFlexLexer() {}

    int yylex() override {
        int token = yyFlexLexer::yylex();
        return token;
    };
};

} //namespace yy

class Driver final {
public:
    explicit Driver(std::stringstream& file):
        lexer_(std::make_unique<yy::Lexer>())
    {
        lexer_->switch_streams(file, std::cout);
    }
    void parse() {
        while (lexer_->yylex() != 0) {}
    }
private:
    std::unique_ptr<yy::Lexer> lexer_;
};

