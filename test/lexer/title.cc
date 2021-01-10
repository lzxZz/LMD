#include "../test.hh"

#include "lmd/lmd.hh"

using lzx::lmd::lexer;
using lzx::lmd::Token;
using lzx::lmd::TokenType;

TEST(TITLE, TOKENS_BASIC){
    vector<Token> tokens;
    string source = "# T";

    {   // build example data
        tokens.push_back(Token('#', TokenType::NumSign));
        tokens.push_back(Token(' ', TokenType::Space));
        tokens.push_back(Token('T', TokenType::Text));
        
    }
    ASSERT_EQ(tokens, lexer(source));
}

TEST(TITLE, TOKENS_MULTI_SYMBOL){
    vector<Token> tokens;
    string source = "### T";

    {   // build example data
        tokens.push_back(Token('#', TokenType::NumSign));
        tokens.push_back(Token('#', TokenType::NumSign));
        tokens.push_back(Token('#', TokenType::NumSign));
        tokens.push_back(Token(' ', TokenType::Space));
        tokens.push_back(Token('T', TokenType::Text));
        
    }
    ASSERT_EQ(tokens, lexer(source));
}

TEST(TITLE, TOKENS_MULTI_TEXT){
    vector<Token> tokens;
    string source = "# Title";

    {   // build example data
        tokens.push_back(Token('#', TokenType::NumSign));
        tokens.push_back(Token(' ', TokenType::Space));
        tokens.push_back(Token('T', TokenType::Text));
        tokens.push_back(Token('i', TokenType::Text));
        tokens.push_back(Token('t', TokenType::Text));
        tokens.push_back(Token('l', TokenType::Text));
        tokens.push_back(Token('e', TokenType::Text));
        
    }
    ASSERT_EQ(tokens, lexer(source));
}