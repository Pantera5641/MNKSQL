#pragma once
#include <string>
#include <typeindex>


inline const std::string MYINT {"INT"};
inline const std::string STRING {"STRING"};
inline const std::string NONE {"NONE"};

inline const std::type_index INT_TYPE {typeid(int)};
inline const std::type_index STRING_TYPE {typeid(std::string)};

inline const std::string NO_DIGITS {"NO_DIGITS"};