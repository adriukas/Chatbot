# Chatbot

A simple, console-based **chatbot application** implemented in C++.

This project demonstrates core object-oriented programming (OOP) principles and basic user interaction handling. 

---

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a C++ compiler (like g++ or clang) and a build system (like CMake or simply compiling with the command line).

* **C++ Compiler:** [Specify minimum required standard, e.g., C++17]

### Installation and Compilation

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/yourusername/Chatbot.git](https://github.com/yourusername/Chatbot.git)
    cd Chatbot
    ```

2.  **Compile the files:**
    Assuming you are using a standard g++ compiler, you can compile the files like this:
    ```bash
    g++ -std=c++17 main.cpp Chatbot.cpp User.cpp -o ChatbotApp
    ```
    *(**Note:** Adjust the flag `-std=c++17` if your required standard is different. Include any necessary libraries if you have them.)*

3.  **Run the application:**
    ```bash
    ./ChatbotApp
    ```


---

Understood! You want the complete **"Usage and Features"** section again, formatted for your GitHub README.

Here it is:

---

## Usage and Features

**Bot-friend** is an engaging and supportive conversational agent focusing on two key areas: well-being and fitness.

### Core Conversation Flow

* **Personalized Start:** The chatbot asks for your name and uses it throughout the session for a personal touch.
* **Topic Selection:** The main loop prompts the user to choose a topic: **`mood`** or **`running`**.
* **Graceful Exit:** The user can type **`bye`** or **`adios`** at almost any prompt to end the session.
* **Case Handling:** All commands are expected in **lower case** for simplified processing.

### Feature 1: Mood and Relaxation 

The `mood` topic is designed to provide empathetic interaction and mental health support:

* **Sentiment Recognition:** The bot detects a wide range of keywords to categorize the user's input as **positive** (e.g., "great," "motivated," "relaxed") or **negative** (e.g., "stressed," "overwhelmed," "disappointed").
* **Supportive Dialogue:** If the user expresses negative feelings, the bot offers supportive words and an optional prompt to share specific **relaxation strategies** (e.g., listening to music, deep breathing).
* **Screen Break Encouragement:** The chatbot actively monitors the duration of the conversation. If the session becomes lengthy, it proactively suggests taking a short **break** (e.g., stretching or gazing out a window) to prevent screen fatigue.

### Feature 2: Running Discussions 

The `running` topic provides informational and motivational dialogue for runners:

* **Specific Sub-Topics:** After selecting `running`, the user is prompted to choose a more specific area of interest to get focused advice:
    * **`shoes`**: Advice on foot tests and major brands.
    * **`pace`**: Tips on interval training and speed drills.
    * **`mindset`**: The importance of setting goals and embracing challenges.
    * **`workouts`**: Essential strength training (squats, planks, core) for endurance and injury prevention.
    * **`endurance`**: Guidance on gradually increasing distance and incorporating diverse training.

---
