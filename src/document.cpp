
#include "../include/term.h"
#include "../include/read.h"
#include <regex>



using std::regex;

// void Document::setContent(string str)
// {
//     content = str;
// }

string Document::parse()
{
    vector<string> lines;
    SplitString(content, lines, "\n");

    ContinueType continuetype = NOTHING;

    //开始处理每一行数据

    string continueContent = "";
    Section *sec = nullptr;

    std::ostringstream outstr;
    for (auto line : lines)
    {
SRART:
        //std::cout<< line << std::endl;
        switch (continuetype)
        {
        case NOTHING:
            if (regex_match(line,space_line_reg)){
                continue;
            }
            if (regex_match(line, title_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec= nullptr;
                }
                    sec = new Title();
                    sec->setContent(line);
                    outstr << sec->parse() << std::endl;
                    
                    delete(sec);
                    sec = nullptr;
            }
            else if (regex_match(line, split_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                outstr << "\n<hr />\n" << std::endl;
            }
            else if (regex_match(line, math_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                sec = new Math();
                sec->setContent(line);
                outstr << sec->parse() << std::endl;
                delete(sec);
                sec = nullptr;
            }
            else if (regex_match(line, image_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                sec = new Image();
             
                sec->setContent(line);
                outstr << sec->parse() << std::endl;
                delete(sec);
                sec = nullptr;
            }
            else if (regex_match(line, list_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                continuetype = LIST;
                continueContent = line + "\n";
            }
            else if (regex_match(line, order_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                continuetype = ORDER;
                continueContent = line + "\n";
            }
            else if (regex_match(line, quot_reg))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                continuetype = QUOT;
                continueContent = line + "\n";
                //std::cout << "QUOT" << line << std::endl;
            }
            else if (regex_match(line, code_reg_start))
            {
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                continuetype = CODE;
                continueContent = line + "\n";
            }else if(regex_match(line,table_reg_start)){
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                    sec = nullptr;
                }
                continuetype = TABLE;
                continueContent = line + "\n";
            }
            else{
                if (sec != nullptr){                    
                    outstr << sec->parse() << std::endl;
                    delete(sec);
                }
                sec = new Text();
                sec->setContent(line);
                outstr << sec->parse() << std::endl;
                delete(sec);
                sec = nullptr;
            }
            break;
        case LIST:
            if(regex_match(line,list_reg)){
                 continueContent += line + "\n";
            }
            else{
                sec = new List();
                sec->setContent(continueContent);
                continueContent = "";
                continuetype = NOTHING;
                goto SRART;
            }

            break;
        case ORDER:
            
            if(regex_match(line,order_reg) 
                || regex_match(line,indent_reg)
                || regex_match(line,tab_reg) ){
                continueContent += line + "\n";
            }
            else{
                sec = new Order();
                sec->setContent(continueContent);
                continueContent = "";
                continuetype = NOTHING;
                goto SRART;
            }


            break;
        case QUOT:
            
            if(regex_match(line,quot_reg) 
                || regex_match(line,indent_reg)
                || regex_match(line,tab_reg) ){
                 continueContent += line + "\n";
            }
            else{
                sec = new Quot();
                sec->setContent(continueContent);
                continueContent = "";
                continuetype = NOTHING;
                goto SRART;
            }


            break;
        case CODE:
            if (regex_match(line,code_reg_end)){
                Code code;
                code.setContent(continueContent);
                continueContent = "";
                continuetype = NOTHING;
                outstr << code.parse() << std::endl;
                
                
            }else{
                continueContent += line + "\n";
            }

            
            break;
        case TABLE:
            if (regex_match(line,table_reg_end)){
                Table table;
                table.setContent(continueContent);
                continueContent = "";
                continuetype = NOTHING;
                outstr << table.parse() << std::endl;
            }else{
                continueContent += line + "\n";
            }
            //    break;
        }
    }

    return outstr.str();
}
