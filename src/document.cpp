
#include "../include/term.h"
#include "../include/read.h"
#include <regex>



using std::regex;

void Document::setContent(string str)
{
    content = str;
}

string Document::parse()
{
    vector<string> lines;
    SplitString(content, lines, "\n");

    ContinueType continuetype = NOTHING;

    //开始处理每一行数据

    string continueContent = "";

    std::ostringstream outstr;
    for (auto line : lines)
    {
        switch (continuetype)
        {
        case NOTHING:
            if (regex_match(line, title_reg))
            {
                Title title;
                title.setContent(line);
                outstr << title.parse() << std::endl;
            }
            else if (regex_match(line, split_reg))
            {
                outstr << "\n<hr />\n"
                       << std::endl;
            }
            else if (regex_match(line, math_reg))
            {
                Math math;
                math.setContent(line);
                outstr << math.parse() << std::endl;
            }
            else if (regex_match(line, image_reg))
            {
                Image image;
                image.setContent(line);
                outstr << image.parse() << std::endl;
            }
            else if (regex_match(line, list_reg))
            {
                continuetype = LIST;
                continueContent = line;
            }
            else if (regex_match(line, order_reg))
            {
                continuetype = ORDER;
                continueContent = line;
            }
            else if (regex_match(line, quot_reg))
            {
                continuetype = QUOT;
                continueContent = line;
            }
            else if (regex_match(line, code_reg_start))
            {
                continuetype = CODE;
                continueContent = line;
            }else if(regex_match(line,table_reg_start)){
                continuetype = TABLE;
                continueContent = line;
            }
            else{
                Text text;
                text.setContent(line);
                outstr << text.parse() << std::endl;
            }
            break;
        case LIST:
            if (regex_match(line,space_line_reg)){
                List list;
                list.setContent(continueContent);
                continueContent = "";
                outstr << list.parse() << std::endl;
            }else{
                continueContent += line;
            }

            break;
        case ORDER:
            if (regex_match(line,space_line_reg)){
                Order order;
                order.setContent(continueContent);
                continueContent = "";
                outstr << order.parse() << std::endl;
            }else{
                continueContent += line;
            }

            break;
        case QUOT:
            if (regex_match(line,space_line_reg)){
                Quot quot;
                quot.setContent(continueContent);
                continueContent = "";
                outstr << quot.parse() << std::endl;
            }else{
                continueContent += line;
            }

            break;
        case CODE:
            if (regex_match(line,space_line_reg)){
                Code code;
                code.setContent(continueContent);
                continueContent = "";
                outstr << code.parse() << std::endl;
            }else{
                continueContent += line;
            }

            
            break;
        case TABLE:
            if (regex_match(line,table_reg_end)){
                Table table;
                table.setContent(continueContent);
                continueContent = "";
                outstr << table.parse() << std::endl;
            }else{
                continueContent += line;
            }
            //    break;
        }
    }

    return outstr.str();
}
