#include "token.hh"

namespace lzx::lmd{

    std::vector<Token> lexer(std::string str){
        std::vector<Token> result;

        const int length = str.size();
        int index = 0;
        
        while (index < length){
            const char c = str.at(index);
            if (c == '#'){
                result.push_back(Token{'#', TokenType::NumSign});
            }else if (c == ' '){
                result.push_back(Token{' ', TokenType::Space});
            }else {     // 所有条件不满足则是普通字符
                result.push_back(Token{c, TokenType::Text});
            }
            index++;
        }


        // result.push_back(Token("#", TokenType::NumSign));
        // result.push_back(Token(" ", TokenType::Space));
        // result.push_back(Token('T', TokenType::Text));

        return result;;

    }



    bool operator==(const Token &ltoken, const Token &rtoken){
        return ltoken.unit == rtoken.unit && ltoken.type == rtoken.type;
    }
    bool operator!=(const Token &ltoken, const Token &rtoken){
        return ltoken == rtoken;
    }


} // namespace lzx::lmd