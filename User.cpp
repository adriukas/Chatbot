/**
  @file User.cpp
  @author Adrija Ignataviciute
  @date 2025-03-19
  @brief Implements the User class for chatbot interaction.

  This file defines the User class methods for managing user data such as
  tracking names and conversation continuation counts.
*/


#include "User.h"

// constructor initializes name and continue count
User::User() : name("Friend"), continueCount(0) {}

User::User(const std::string& userName) : name(userName), continueCount(0) {} 

// getting name
std::string User::getName() const {
    return name;
}

// counting how many times user wants to continue conversation
void User::increaseContinueCount() {
    continueCount++;
}

// reset continue count
void User::setContinueCount(int count) {
    continueCount = count;
}

// getting the number of interactions
int User::getContinueCount() const {
    return continueCount;
}
