#pragma once

namespace lzx::lmd{

enum class TokenType{
    Text,           // 普通文本
    NumSign,        // #
    Star,           // *
    Space,          // 空格
    Cr,             // 换行符
    UnKnown,

}; // TokenType

} // namespace lzx::lmd