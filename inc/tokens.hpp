#pragma once
#include <string>

namespace tokens {

enum class token_t {
    PLUS = 1, //(FIXME: yylex returns 0 when ends to evaluate string line)
    MINUS,
    NUMBER,
    SCOLON
};

class AbsToken {
    virtual ~AbsToken() {}
    virtual std::string asString() const = 0;
protected:
    token_t type_{};
};

} //namespace tokens