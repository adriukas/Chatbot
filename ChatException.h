/**
  @file ChatException.h
  @author Adrija Ignataviciute
  @date 2025-03-19
  @brief Defines exception handling for the chatbot.
  
  This file declares a custom exception class to handle errors that may occur 
  during chatbot interactions, such as invalid input or unexpected issues.
*/


#ifndef CHATEXCEPTION_H
#define CHATEXCEPTION_H

#include <exception>
#include <string>

/**
  @class ChatException
  @brief Custom exception class for chatbot-related errors.

  The ChatException class extends the standard std::exception class and 
  provides a way to handle errors occurring during chatbot interactions.
*/
class ChatException : public std::exception {
private:
    std::string message; 

public:  
    explicit ChatException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif 
