#pragma once

#include "element.hh"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
namespace lzx::lmd{

class Title : public Element{

public:
    Title(): Title(0,""){}
    Title(int level, const std::string &content) : level_(level), content_(content) {}

    std::string ToString() const{
        std::ostringstream out;
        out << "<h" << level_ << ">" <<  content_ << "</h" << level_ << ">";
        return out.str();
    }
    std::string ClassName() const{
        return "Title";
    }
    bool Equal(const Element *ohs){
        if (this->ClassName() == ohs->ClassName()){
            Title *e = dynamic_cast<Title*>(const_cast<Element*>(ohs));
            return this->level_ == e->level_ && this->content_ == e->content_;
        }else{
            return false;
        }    
    }

    virtual bool operator==(const Element &ohs){
        if (ohs.ClassName() == this->ClassName()){
            Title *t = (Title*)&ohs;
            return t->level_ == this->level_ && t->content_ == this->content_;
        }else{
            return false;
        }
    }
    virtual bool operator!=(const Element &ohs){
        return !(*this == ohs);
    }

    friend bool operator==(const Title &lhs, const Title &rhs);    
    friend bool operator!=(const Title &lhs, const Title &rhs);

    void SetLevel(int level){
        level_ = level;
    }
    int GetLevel() const{
        return level_;
    }
    void SetContent(const std::string &content){
        content_ = content;
    }
    std::string GetConetnt() const{
        return content_;
    }

    void FinishCharPush(){
        char arr[chars_.size()];
        for (size_t i = 0; i < chars_.size(); i++){
            arr[i] = chars_.at(i);
        }
        content_ = std::string{arr, 0, chars_.size()};
    }
    void PushChar(const char &c){   
        chars_.push_back(c);
    }
private:
    std::vector<char> chars_;
    int level_;
    std::string content_;
};

} //namespace lzx::lmd