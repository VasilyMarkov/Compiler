#pragma once
#include <string_view>
#include <unordered_map>

namespace tokens {

enum class token_t: uint8_t {
    END,
    PLUS,
    MINUS,
    NUMBER,
    SCOLON,
    ERROR,
};

inline std::string_view tokenEnumToString(token_t token) {
    const static std::unordered_map<token_t, std::string_view> tokens_map = {
        {token_t::END, "END"},
        {token_t::PLUS, "PLUS"},
        {token_t::MINUS, "MINUS"},
        {token_t::NUMBER, "NUMBER"},
        {token_t::SCOLON, "SCOLON"},
        {token_t::ERROR, "ERROR"}
    };
    return tokens_map.at(token);
}

class Token {
public:
    Token(token_t type) noexcept :type_(type) {}
    virtual ~Token() = default;
    virtual std::string asString() const = 0;
protected:
    token_t type_{};
};

class PlusToken: public Token {
public:
    PlusToken() noexcept: Token(token_t::PLUS) {}
    std::string asString() const override {
        return {"PlusToken"};
    };
};

class MinusToken: public Token {
public:
    MinusToken() noexcept: Token(token_t::MINUS) {}
    std::string asString() const override {
        return {"MinusToken"};
    };
};

class NumberToken: public Token {
public:
    NumberToken(int value) noexcept: Token(token_t::NUMBER), value_(value) {}
    std::string asString() const override {
        return std::string{"NumberToken: "} + std::to_string(value_);
    };
private:
    int value_;
};

} //namespace tokens