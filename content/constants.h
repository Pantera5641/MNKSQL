#pragma once
#include <string>
#include <typeindex>

const char SPACE {' '};
const char COMMA {','};
const char HYPHEN {'-'};
const char EQUALS_SIGN {'='};
const char LEFT_PARENTHESIS {'('};
const char RIGHT_PARENTHESIS {')'};
const char LEFT_SQUARE_BRACKET {'['};
const char RIGHT_SQUARE_BRACKET {']'};
const char VERTICAL_BAR {'|'};

const std::string& INT {"INT"};
const std::string& STRING {"STRING"};

const std::type_index INT_TYPE {typeid(int)};
const std::type_index STRING_TYPE {typeid(std::string)};

const std::string& NONE {"NONE"};