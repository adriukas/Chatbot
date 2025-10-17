/**
  @file Chatbot.cpp
  @author Adrija Ignataviciute
  @date 2025-03-19
  @brief Implements the Chatbot class for user interaction.

  This file defines the Chatbot class, which facilitates user conversations, 
  manages mood-related interactions, encourages relaxation and provides running-related discussions.

  @version 3.0 
  
  @copyright (c) 2025 Adrija Ignataviciute
  
  @dependencies:
  - Standard Library: <iostream>, <string>, <chrono>
  - Project Headers: "Chatbot.h", "ChatException.h"
  
  @limitations:
  - Currently supports only English interactions.
 */


#include "Chatbot.h"
#include "ChatException.h"
#include <iostream>


using namespace std;

/**
  @brief Encourages the user to take breaks if the conversation becomes lengthy.
  
  @param responseTime The time (in seconds) the user took to respond.
  @param user Reference to the User object, which tracks conversation length.

  @return void
 */
void Chatbot::encourageRelaxation(int responseTime, User& user) {
    if (responseTime > 0 && responseTime <= 5) { 
        cout << "\n* And also, You answered so fast. I hope You gave Your answer some thought.";
    }
    int count = user.getContinueCount();
    if (count == 3) {
        cout << "\n* We talked quite some time. Maybe it's a good time for a short break? A peek outside the window or some deep breaths could be refreshing!";
    } else if (count == 4) { 
        cout << "\n* We are talking for a long time now... Maybe it's a good time for a longer break? A gaze through the window or some breathing practices could be refreshing!";
    } else if (count == 5) { 
        cout << "\n* Hey, " << user.getName() << ", we've been chatting for a while now. Maybe it's a good time to take a break from computer? Stretch a little, grab a drink or just breathe deeply for a moment. You'll feel refreshed!";
        user.setContinueCount(0);
    }
}


/**
  @brief Extracts the user's name from their input.
  
  @param input The user's response.
  @return Extracted name or "Friend" if not found.
*/
string Chatbot::extractName(const string &input) {
    if (input.empty()) return "Friend";
    if (input.find("my name is ") == 0) {
        string name = input.substr(11);
        return name.empty() ? "Friend" : name;
    }
    if (input.find("I'm ") == 0) {
        string name = input.substr(4);
        return name.empty() ? "Friend" : name;
    }
    if (input.find("I am ") == 0) {
        string name = input.substr(5);
        return name.empty() ? "Friend" : name;
    }
    return input;  
}


/**
  @brief Determines if the user wants to exit the conversation.
  
  @param input The user's response.
  @return True if the user wants to exit, false otherwise.
*/
bool Chatbot::wantsToExit(const string &input) {
    return input == "bye" || input == "adios";
}


/**
  @brief Handles mood-related conversation with the user.
  
  @param user Reference to the User object tracking conversation state.

  @return void
*/
void Chatbot::handleMood(User& user) {
    chrono::steady_clock::time_point start, end; 
    string input;
    int responseTime = 0;
    
    user.increaseContinueCount();


    cout << "\n* How are You feeling at the moment?\n";
    start = chrono::steady_clock::now(); 
    cout << "< ";
    getline(cin, input);
    end = chrono::steady_clock::now();
    responseTime = chrono::duration_cast<chrono::seconds>(end - start).count();

    //choices: bye/sad/happy/random answer
    if (wantsToExit(input)) {
        return; 

    //if feeling sad
    } else if ((input.find("bad") != string::npos || input.find("sad") != string::npos || 
    input.find("down") != string::npos || input.find("disappointed") != string::npos || 
    input.find("not good") != string::npos || input.find("unhappy") != string::npos ||
    input.find("upset") != string::npos || input.find("stressed") != string::npos ||
    input.find("frustrated") != string::npos || input.find("tired") != string::npos || 
    input.find("overwhelmed") != string::npos || input.find("depressed") != string::npos ||
    input.find("anxious") != string::npos || input.find("worried") != string::npos ||
    input.find("angry") != string::npos || input.find("not okay") != string::npos ||
    input.find("not ok") != string::npos || input.find("hopeless") != string::npos ||
    input.find("exhausted") != string::npos || input.find("burned out") != string::npos ||
    input.find("heartbroken") != string::npos || input.find("devastated") != string::npos)) {
        cout << "\n* I'm sorry to hear that, " << user.getName() << ". Sometimes a little break, a walk or even just some deep breaths can help.";
        encourageRelaxation(responseTime, user);
        cout << "\n* I want to tell You a bit more about relaxation strategies to help to get Your mind off. Do You want to hear it? (yes/no)\n";
        cout << "< ";
        getline(cin, input);
        //choice: bye/yes/no/random answer
        if (input == "bye" || input == "adios") {
            cout << "\n* Understood, hope You will feel better soon. Bye!\n";
        } else if (input == "yes") {
            cout << "\n* Try listening to calming music, doodling in a notebook, or moving to Your favorite song. Even a short walk outside can help!"; 
        } else if (input == "no") {
            cout << "\n* Understood, hope You will feel better soon. Take Your time!";
        } else {
            cout << "* I didn't understand that...\n";
        }
    //if feeling happy
    } else if (input.find("good") != string::npos || input.find("happy") != string::npos || 
    input.find("great") != string::npos || input.find("fantastic") != string::npos || 
    input.find("amazing") != string::npos || input.find("excited") != string::npos ||
    input.find("joyful") != string::npos || input.find("nice") != string::npos ||
    input.find("ok") != string::npos || input.find("relaxed") != string::npos ||
    input.find("energetic") != string::npos || input.find("motivated") != string::npos ||
    input.find("confident") != string::npos || input.find("proud") != string::npos ||
    input.find("peaceful") != string::npos || input.find("wonderful") != string::npos ||
    input.find("grateful") != string::npos || input.find("hopeful") != string::npos ||
    input.find("strong") != string::npos || input.find("well") != string::npos) {
        cout << "\n* That's great to hear, " << user.getName() << "! Keep enjoying the moment!";
    encourageRelaxation(responseTime, user);
    //if other feelings
    } else {
        cout << "\n* Could You tell me more, " << user.getName() << "?\n";
        cout << "< ";
        getline(cin, input);
        if (wantsToExit(input)) {
            return; 
        } else {
            cout << "\n* I hear You, " << user.getName() << ". Life makes us feel so many different emotions and it's all part of the journey.";
        encourageRelaxation(responseTime, user);
        }
    } 
}


/**
  @brief Manages discussions about running.
  
  @param user Reference to the User object tracking conversation state.

  @return void
 */
void Chatbot::handleRunning(User& user) {
    string input;

    user.increaseContinueCount();

    cout << "\n* Okay, let's talk about running! What aspect interests You the most? (shoes/pace/mindset/workouts/endurance)\n";
    cout << "< ";
    getline(cin, input);
         
    if (wantsToExit(input)){
        return; 
    } else if (input == "shoes") {
        cout << "\n* The best running shoes depend on Your foot type and running style. There is a possibility to do a foot test to get to know which shoes fit You the best. Brands like Nike, Adidas and Asics have great options!";
    } else if (input == "pace") {
        cout << "\n* Improving speed requires interval training, proper form and consistency. Sprint drills help a lot!";
    } else if (input == "mindset") {
        cout << "\n* A strong mindset is key! Setting goals, staying disciplined and embracing challenges make You a better runner.";
    } else if (input == "workouts") {
        cout << "\n* Strength training is essential for runners! Squats, lunges, deadlifts and core exercises like planks help improve power, endurance and injury prevention.";
    } else if (input == "endurance") {
        cout << "\n* To build endurance, gradually increase Your running distance while maintaining a steady pace. Incorporate interval training and strength exercises to improve stamina and efficiency.";
    } else {
        cout << "* That’s not a valid option. Please choose one from (shoes/pace/mindset/workouts/endurance).!";
    }
    encourageRelaxation(0, user);
    }


/**
  @brief Starts the chatbot interaction with the user.
  
  @throws ChatException If an error occurs in chatbot operations.
  @throws std::exception If an unexpected error occurs.

  @return void
*/
void Chatbot::startChat() {
    try {
    string input;
   
    //help message
    cout << "======================================================\n";
    cout << "* Welcome to Bot-friend!                              *\n";
    cout << "* This chatbot can talk with You about Your mood,     *\n";
    cout << "* give relaxation tips and discuss running topics.    *\n";
    cout << "* Just type Your responses in lower case!             *\n";
    cout << "* Type 'bye' or 'adios' anytime to exit the chat.     *\n";
    cout << "======================================================\n\n";

    cout << "* Hi! I'm Bot-friend. Tell me Your name.\n";
    cout << "< ";
    getline(cin, input);
    User user(extractName(input));
    
    //introduction
    cout << "\n* Okay, " << user.getName() << ", nice to meet You, let's chat. Also know that if You don't want to talk anymore, You can just type 'adios' or 'bye' to exit.";
    
    //action
    while (true) {
        cout << "\n* What do You want to chat about, " << user.getName() << "? (mood/running/help)\n";
        cout << "< ";
        getline(cin, input);

        //options: bye/help/mood/running/random answer
        if (wantsToExit(input)) {
            break; 
        //help message
        } else if (input == "help"){
            cout << "======================================================\n";
            cout << "* This chatbot can talk about:                       *\n";
            cout << "* Your mood and running.                             *\n";
            cout << "* Type 'bye' or 'adios' anytime to exit the chat.    *\n";
            cout << "======================================================\n\n"; 
        // choosing mood
        } else if (input == "mood") {
            handleMood(user);
        //chosing running
        } else if (input == "running") {
            handleRunning(user);
        //random answer
        } else {
            cout << "* I didn't understand that...\n";
        }
    
        //keeping the conversation going
        cout << "\n* Would You like to continue our conversation? (yes/no)\n";
        cout << "< ";
        getline(cin, input);

        if (input == "yes") {
            user.increaseContinueCount();
            encourageRelaxation(0, user); 
        } else if (input == "no" || wantsToExit(input)) {
            cout << "\n* Alright, " << user.getName() << ", ciao!\n";
            break;
        } else {
            throw ChatException("Invalid response! But I got You - the answer was not yes...");
        }
    
    }
}
    
    catch (const ChatException& e) {
    cout << "\nError: " << e.what() << endl;
    } catch (const exception& e) {
    cout << "\nUnexpected error: " << e.what();
    }
}