%option c++
%option noyywrap

WS      [ \t\n\v]+
DIGIT   [0-9]
DIGIT1  [1-9]
ID      [a-zA-Z_][a-zA-Z0-9_]*

%%
{WS}              /* skip blanks and tabs */
"+"               std::cout << "+";
"-"               std::cout << "-";
{DIGIT1}{DIGIT}*  std::cout << std::stoi(yytext);
{DIGIT}           std::cout << std::stoi(yytext);
";"               std::cout << std::endl;
%%