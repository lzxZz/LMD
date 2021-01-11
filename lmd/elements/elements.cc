#include "element.hh"

#include <iostream>

#include "lmd/lexer/token.hh"
#include "title.hh"
#include "status.hh"

using std::vector;
using std::shared_ptr;
using std::string;

using std::cout;
using std::cerr;
using std::endl;

namespace lzx::lmd{

vector<shared_ptr<Element>> syntax(vector<Token> &tokens){
    
    std::vector<std::shared_ptr<Element>>  elements;
    if (tokens.size() == 0){
        return elements;
    }
    Token *token = nullptr;
    std::size_t index = 0;
    SyntaxStatus status = SyntaxStatus::Init;
    Element *element = nullptr;
    while (index < tokens.size()){
        token = &(tokens.at(index));
        switch (status){
            case SyntaxStatus::Init:{
                if (token->type == TokenType::NumSign){
                    element = new Title{};
                    Title *t = dynamic_cast<Title*>(element);
                    t->SetLevel(t->GetLevel() + 1);  // 匹配到第一个#, 等级+1
                    status = SyntaxStatus::Title;
                }else{

                }
                break;
            }
            case SyntaxStatus::Title:{ 
                // 匹配到换行符结束标签, 匹配到空格结束标题等级
                if (token->type == TokenType::NumSign){
                    Title *t = dynamic_cast<Title*>(element);
                    t->SetLevel(t->GetLevel() + 1);  // 匹配到#, 等级+1
                }else if (token->type == TokenType::Space){ 
                    // 匹配到空格, 结束标签头的匹配
                    // 修改状态机的状态为标题正文.
                    status = SyntaxStatus::TitleContent;
                }else {
                    // 出错 
                    cerr << "Syntax Title 匹配错误, # 后期待 '#' 或 ` ` !" << endl;
                }
                break;
            }
            case SyntaxStatus::TitleContent:{
                if (token->type == TokenType::Cr){
                    // 匹配到换行, 匹配到完整标题, 结束匹配.
                    Title *t = dynamic_cast<Title*>(element);
                    t->FinishCharPush();
                    cout << t->ToString() << endl;
                    elements.push_back(std::shared_ptr<Element>{element});
                    status = SyntaxStatus::Init;
                    element = nullptr;
                }else if (token->type == TokenType::Text){
                    Title *t = dynamic_cast<Title*>(element);
                    t->PushChar(token->unit);
                    // 追加文本
                }else if (token->type == TokenType::Space){
                    Title *t = dynamic_cast<Title*>(element);
                    t->PushChar(token->unit);
                    // 标题中的空格
                }else{
                    cerr << "Syntax Title 匹配错误, 标题正文不允许" << token->unit << endl;
                }
                break;
            }
            default:{
                break;
            }
        }
        index++;
    }
    // 处理没有换行符的情况
    if (element != nullptr){
        std::string type = element->ClassName();
        if ("Title" == type){
            Title *t = dynamic_cast<Title*>(element);
            t->FinishCharPush();
            elements.push_back(std::shared_ptr<Element>(element));
            element = nullptr;
        }
    }
    return elements;
}

bool operator==(const std::vector<std::shared_ptr<Element>> &lhs, const std::vector<std::shared_ptr<Element>> &rhs){
    if (lhs.size() != rhs.size()){
        return false;
    }
    for (std::size_t i = 0; i< lhs.size(); i++){
        Element *le = lhs.at(i).get();
        Element *re = rhs.at(i).get();
        if ( (*le) != (*re)){
            return false;
        }
    }
    return true;
}

bool operator!=(const std::vector<std::shared_ptr<Element>> &lhs, const std::vector<std::shared_ptr<Element>> &rhs){
    return !(lhs == rhs);
}

bool operator==(const Element &lhs, const Element &rhs){
    if (lhs.ClassName() == rhs.ClassName()){
        return lhs.ToString() == rhs.ToString();
    }
}
bool operator!=(const Element &lhs, const Element &rhs){
    return !(lhs == rhs);
}
} // namespace lzx::lmd