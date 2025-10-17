/**
  @file Chatbot.h
  @author Adrija Ignataviciute
  @date 2025-03-19
  @brief Defines the Chatbot class for user interaction.

  This file declares the Chatbot class, which handles user input, processes responses, 
  provides mood and running interactions and maintains the chat session.
*/



#ifndef CHATBOT_H
#define CHATBOT_H

#include <string>
#include <chrono>
#include "User.h"
#include "ChatException.h"

/**
  @class Chatbot
  @brief Handles user interactions and conversations.

  The Chatbot class is responsible for engaging in conversations with the user, 
  processing input, responding accordingly, and encouraging breaks when necessary.
*/
class Chatbot {
public:
    void encourageRelaxation(int responseTime, User& user);
    std::string extractName(const std::string& input);
    bool wantsToExit(const std::string& input);
    void handleMood(User& user);
    void handleRunning(User& user);
    void startChat();
};

#endif 
