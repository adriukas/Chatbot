/**
  @file User.h
  @author Adrija Ignataviciute
  @date 2025-03-19
  @brief Defines the User class for chatbot interactions.

  This file declares the User class, which manages user-related data, such as 
  storing the user's name and tracking interaction counts.
*/


#ifndef USER_H
#define USER_H

#include <stdexcept> 
#include "ChatException.h" 


/**
  @class User
  @brief Represents a user interacting with the chatbot.

  The User class stores user details such as their name and the number of 
  consecutive interactions. It provides methods to retrieve and modify these values.
*/
class User {
private:
    std::string name;  
    int continueCount; 

public:
    User();  
    User(const std::string& userName);  

    std::string getName() const;  

    void increaseContinueCount();
    void setContinueCount(int count);
    int getContinueCount() const;
};

#endif 
