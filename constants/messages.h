#pragma once
#include <string>

//general messages
inline const std::string WELCOME_MESSAGE {"Welcome in MNKSQL. To see all commands type: \"HELP\""};
inline const std::string DATA_SAVED_MESSAGE {"Data saved"};
inline const std::string DATA_LOADED_MESSAGE {"Data loaded"};

//column messages
inline const std::string COLUMN_ADDED_MESSAGE {"Column added in database"};
inline const std::string INSUFFICIENT_COLUMNS_ERROR {"ERROR: At least 1 column is needed to create a row"};
inline const std::string INVALID_ROW_NUMBER_ERROR {"ERROR: Invalid number of row"};


//database messages
inline const std::string CONFIRM_DATABASE_DELETE_PROMPT {"This will delete all data from the database. Are you sure?(Y/N)"};
inline const std::string DATABASE_CLEARED_MESSAGE {"Database cleared"};

//file messages
inline const std::string DATA_SAVED_TO_PATH_MESSAGE {"Your data has been saved to: "};
inline const std::string DATA_LOADED_FROM_PATH_MESSAGE {"Your data has been load from: "};
inline const std::string TABLE_DELETED_MESSAGE {"This table was deleted: "};
inline const std::string EXTENSION_NOT_ALLOWED_ERROR {"ERROR: You cannot use this extension"};
inline const std::string FILE_NOT_FOUND_ERROR {"ERROR: File does not exist"};

//password messages
inline const std::string PASSWORD_SET_MESSAGE {"Password set to: "};
inline const std::string PASSWORD_CHANGED_MESSAGE {"Password changed to: "};
inline const std::string INCORRECT_PASSWORD_ERROR {"ERROR: Incorrect password"};
inline const std::string FILE_ALREADY_HAS_PASSWORD_ERROR {"ERROR: This file already has a password, use the EDIT command to change it"};

//row messages
inline const std::string VALUE_ERROR_MESSAGE {"Error in value: "};
inline const std::string ROW_ADDED_MESSAGE {"Row added in database"};
inline const std::string ROW_REWRITTEN_MESSAGE {"Row was rewrite"};
inline const std::string ROW_DELETED_MESSAGE {"Row was deleted"};

//error messages
inline const std::string SYNTAX_ERROR {"ERROR: Syntax error"};
inline const std::string UNKNOWN_COMMAND_ERROR {"ERROR: Unknown command"};
inline const std::string UNKNOWN_OPERATOR_ERROR {"ERROR: Unknown operator"};

inline const std::string INVALID_ARGUMENTS_ERROR {"ERROR: Invalid arguments"};

inline const std::string COMMAND_NOT_IMPLEMENTED_ERROR {"ERROR: Command not implemented"};
inline const std::string OPERATION_NOT_IMPLEMENTED_ERROR {"ERROR: Operation not implemented"};