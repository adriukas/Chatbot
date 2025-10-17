/**
  @file main.cpp
  @author Adrija Ignataviciute
  @date 2025-03-19
  @brief Entry point for the chatbot program.
  
  This file initializes and starts the chatbot, handling any exceptions that may occur 
  during execution to ensure smooth user interaction.

  @version 3.0
*/



#include "Chatbot.h"
#include "ChatException.h" 
#include <iostream>


/**
  @brief Main function to start the chatbot program.
  
  This function creates a Chatbot instance and starts the conversation. 
  It also handles exceptions using the custom ChatException class.

  @return int Returns 0 upon successful execution.
*/
int main() {
    try {
        Chatbot chatbot;
        chatbot.startChat();
    } catch (const ChatException& e) {
        std::cout << "Problem: " << e.what();
    }
    return 0;
}
