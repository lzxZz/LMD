#include "../test.hh"

#include "lmd/lmd.hh"

#pragma region "词法分析"

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

TEST(TITLE, TOKENS_FULL){
    vector<Token> tokens;
    string source = "# Title\n";

    {   // build example data
        tokens.push_back(Token('#', TokenType::NumSign));
        tokens.push_back(Token(' ', TokenType::Space));
        tokens.push_back(Token('T', TokenType::Text));
        tokens.push_back(Token('i', TokenType::Text));
        tokens.push_back(Token('t', TokenType::Text));
        tokens.push_back(Token('l', TokenType::Text));
        tokens.push_back(Token('e', TokenType::Text));
        tokens.push_back(Token('\n', TokenType::Cr));
    }
    ASSERT_EQ(tokens, lexer(source));
}

#pragma endregion


#pragma region "语法分析"

using lzx::lmd::Element;
using lzx::lmd::Title;



TEST(TITLE, SYNTAX_ONE_LINE){
    vector<Token>  tokens = lexer("# H1 Title\n");

    std::vector<std::shared_ptr<Element>>  elements;

    { // build eaxmple data
        std::shared_ptr<Element> e = std::make_shared<Title>(1, "H1 Title");
        elements.push_back(e);
    }
    std::vector<std::shared_ptr<Element>> result = syntax(tokens);

    ASSERT_EQ(elements, result);
}

TEST(TITLE, SYNTAX_MULTI_LINE){
    string str  = R"(# H1 Title
        #### H4)";
    vector<Token>  tokens = lexer(str);

    std::vector<std::shared_ptr<Element>>  elements;

    { // build eaxmple data
        std::shared_ptr<Element> e1 = std::make_shared<Title>(1, "H1 Title");
        std::shared_ptr<Element> e2 = std::make_shared<Title>(4, "H4");
        elements.push_back(e1);
        elements.push_back(e2);
    }
    std::vector<std::shared_ptr<Element>> result = syntax(tokens);

    ASSERT_EQ(elements, result);
}

TEST(TITLE, SYNTAX_FILE_END){
    vector<Token>  tokens = lexer("# H1 Title"); // 模拟最后一行没有换行符的情况

    std::vector<std::shared_ptr<Element>>  elements;

    { // build eaxmple data
        std::shared_ptr<Element> e = std::make_shared<Title>(1, "H1 Title");
        elements.push_back(e);
    }
    std::vector<std::shared_ptr<Element>> result = syntax(tokens);

    ASSERT_EQ(elements, result);
}

#pragma endregion