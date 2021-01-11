#include "title.hh"

namespace lzx::lmd{
    bool operator==(const Title &lhs, const Title &rhs){
        return lhs.level_ == rhs.level_ && lhs.content_ == rhs.content_;
    }
    bool operator!=(const Title &lhs, const Title &rhs){
        return ! (lhs == rhs);
    }
} //namespace lzx::lmd