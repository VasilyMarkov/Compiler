%option c++
%option noyywrap


%{
#include "tokens.hpp"
%}

WS      [ \t\n\v]+
DIGIT   [0-9]
DIGIT1  [1-9]
ID      [a-zA-Z_][a-zA-Z0-9_]*

%%
{WS}              /* skip blanks and tabs */
"+"               return static_cast<int>(tokens::token_t::PLUS);
"-"               return static_cast<int>(tokens::token_t::MINUS);
{DIGIT1}{DIGIT}*  return static_cast<int>(tokens::token_t::NUMBER);
{DIGIT}           return static_cast<int>(tokens::token_t::NUMBER);
";"               return static_cast<int>(tokens::token_t::SCOLON);
.
%%