#include "life.hpp"
#include "utility.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


int main()  //  Program to play Conway's game of Life.
/*
 Pre:  The user supplies an initial configuration of living cells.
 Post: The program prints a sequence of pictures showing the changes in
 the configuration of living cells according to the rules for
 the game of Life.
 Uses: The class Life and its methods initialize(), print(), and update().
 The functions  instructions(),  user_says_yes().
 */

{
    int seconds = 0;
    Life configuration;
    instructions();
    seconds = ask_seconds();
    configuration.initialize();
    configuration.print();
    cout << "Continue viewing new generations? " << endl;
    if(seconds != 0){
        while(1){
            cout << "New generation:" << endl;
            configuration.update();
            configuration.print();
            std::this_thread::sleep_for(std::chrono::seconds(seconds));
        }
    }else{
        while (user_says_yes()) {
            configuration.update();
            configuration.print();
            cout << "Continue viewing new generations? " << endl;
        }
    }
    
}

