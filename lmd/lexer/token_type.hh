#pragma once



namespace lzx::lmd{

enum class TokenType{
    Text,           // 普通文本
    NumSign,        // #
    Star,           // *
    Space,          // 空格
    UnKnown,

}; // TokenType

} // namespace lzx::lmd