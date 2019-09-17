//
//  utility.h
//  tiealg
//
//  Created by Eetu Koskelainen on 06/09/2019.
//  Copyright © 2019 Eetu Koskelainen. All rights reserved.
//

#ifndef utility_h
#define utility_h


#endif /* utility_h */

#include <iostream>
using namespace std;

void instructions()
/*
 Pre:  None.
 Post: Instructions for using the Life program have been printed.
 */

{
    cout << "Welcome to Conway's game of Life." << endl;
    cout << "This game uses a grid of size "
    << maxrow << " by " << maxcol << " in which" << endl;
    cout << "each cell can either be occupied by an organism or not." << endl;
    cout << "The occupied cells change from generation to generation" << endl;
    cout << "according to the number of neighboring cells which are alive."
    << endl;
}

bool user_says_yes()
{
    int c;
    bool initial_response = true;
    
    do {  //  Loop until an appropriate input is received.
        if (initial_response)
            cout << " (y,n)? " << flush;
        
        else
            cout << "Respond with either y or n: " << flush;
        
        do { //  Ignore white space.
            c = cin.get();
        } while (c == '\n' || c ==' ' || c == '\t');
        initial_response = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
    return (c == 'y' || c == 'Y');
}

int ask_seconds(){
    int secs = 0;
    string input;
    bool error = false;
    do {
        error = false;
        cout << "Set delay between generations:" << endl;
        cin >> input;
        try{
            secs = stoi(input);
        }catch(...){
            cout << "Error, try again:" << endl;
            error = true;
        }
    }while(error);
    return secs;
}
