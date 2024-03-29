//
//  life.hpp
//  tiealg
//
//  Created by Eetu Koskelainen on 06/09/2019.
//  Copyright © 2019 Eetu Koskelainen. All rights reserved.
//

#ifndef life_hpp
#define life_hpp

#include <stdio.h>

#endif /* life_hpp */

const int maxrow = 20, maxcol = 60;    //  grid dimensions

class Life {
public:
    void initialize();
    void print();
    void update();
private:
    int grid[maxrow + 2][maxcol + 2];  //  allows for two extra rows and columns
    int neighbor_count(int row, int col);
};
