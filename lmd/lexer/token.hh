#pragma once

#include <string>
#include <vector>

#include "token_type.hh"

namespace lzx::lmd{

class Token{
public:
    char unit;              //词素数据
    TokenType type;         //词素类型
    Token(){
        unit = ' ';
        type = TokenType::UnKnown;
    }
    Token(char content, TokenType _type) : unit(content), type(_type){} 
};

bool operator==(const Token &ltoken, const Token &rtoken);
bool operator!=(const Token &ltoken, const Token &rtoken);

//将输入的字符串转换为词法单元集合.
std::vector<Token> lexer(std::string);

} //namespace lzx::lmd