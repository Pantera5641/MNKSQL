#pragma once
#include <string>
#include <typeindex>

inline const char SPACE {' '};
inline const char COMMA {','};
inline const char HYPHEN {'-'};
inline const char EQUALS_SIGN {'='};
inline const char LEFT_PARENTHESIS {'('};
inline const char RIGHT_PARENTHESIS {')'};
inline const char LEFT_SQUARE_BRACKET {'['};
inline const char RIGHT_SQUARE_BRACKET {']'};
inline const char VERTICAL_BAR {'|'};

inline const std::string INT {"INT"};
inline const std::string STRING {"STRING"};

inline const std::type_index INT_TYPE {typeid(int)};
inline const std::type_index STRING_TYPE {typeid(std::string)};

inline const std::string NONE {"NONE"};