#pragma once

#include <memory>
#include <string>
#include <vector>

#include "lmd/lexer/token.hh"

namespace lzx::lmd{

class Element{
public:    
    virtual std::string ToString() const = 0;
    virtual std::string ClassName() const {
        return "Element";
    }
    virtual bool Equals(Element *ohs) const{
        return this->ClassName() == ohs->ClassName();
    }
    virtual ~Element(){}
protected:
    std::vector<std::shared_ptr<Element>> childs;
};

bool operator==(const Element &lhs, const Element &rhs);
bool operator!=(const Element &lhs, const Element &rhs);

bool operator==(const std::vector<std::shared_ptr<Element>> &lhs, const std::vector<std::shared_ptr<Element>> &rhs);
bool operator!=(const std::vector<std::shared_ptr<Element>> &lhs, const std::vector<std::shared_ptr<Element>> &rhs);

// 语法分析
std::vector<std::shared_ptr<Element>> syntax(std::vector<Token>& tokens);

} // namespace lzx::lmd