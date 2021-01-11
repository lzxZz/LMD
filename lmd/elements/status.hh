#pragma once

namespace lzx::lmd{

enum class SyntaxStatus{
    Init,                   //  初始空状态
    Title,                  //  匹配到标题
    TitleContent,           //  匹配标题正文 
    Plain,                  //  普通文本
};

} //namespace lzx::lmd