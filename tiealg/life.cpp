#include "life.hpp"
#include <iostream>
using namespace std;

int Life::neighbor_count(int row, int col)
/*
 Pre:  The Life object contains a configuration, and the coordinates
 row and col define a cell inside its hedge.
 Post: The number of living neighbors of the specified cell is returned.
 */

{
    int i, j;
    int count = 0;
    for (i = row - 1; i <= row + 1; i++)
        for (j = col - 1; j <= col + 1; j++)
            count += grid[i][j];  //  Increase the count if neighbor is alive.
    count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.
    return count;
}

void Life::update()
/*
 Pre:  The Life object contains a configuration.
 Post: The Life object contains the next generation of configuration.
 */

{
    int row, col;
    int new_grid[maxrow + 2][maxcol + 2];
    
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)) {
                case 2:
                    new_grid[row][col] = grid[row][col];  //  Status stays the same.
                    break;
                case 3:
                    new_grid[row][col] = 1;                //  Cell is now alive.
                    break;
                default:
                    new_grid[row][col] = 0;                //  Cell is now dead.
            }
    
    for (row = 1; row <= maxrow; row++)
        for (col = 1; col <= maxcol; col++)
            grid[row][col] = new_grid[row][col];
}



/*void Life::initialize()
 //Pre:  None.
 //Post: The Life object contains a configuration specified by the user.
 

{
    int row, col;
    for (row = 0; row <= maxrow+1; row++)
        for (col = 0; col <= maxcol+1; col++)
            grid[row][col] = 0;
    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;
    cin >> row >> col;
    
    while (row != -1 || col != -1) {
        if (row >= 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range." << endl;
            else
                cout << "Row " << row << " is out of range." << endl;
        cin >> row >> col;
    }
}*/

void Life::initialize(){
    int row, col;
    string userRow = "";
    bool error = false;
    
    // Zero coords
    for (row = 0; row <= maxrow+1; row++)
        for (col = 0; col <= maxcol+1; col++)
            grid[row][col] = 0;
    
    cout << "List " << maxcol << " coords as x and - for each row:" << endl;
    for (row = 1; row <= maxrow; row++){
        do{
            error = false;
        cout << "Row" << row << ":";
        cin >> userRow;
        
        for (int i = 0; i < userRow.size(); i++){
            if (userRow.size() > maxcol){
                cout << "Too many characters!" << endl;
                error = true;
                break;
            }
            if ((char)userRow[i] == '-'){
                grid[row][i] = 0;
            }else if ((char)userRow[i] == 'x'){
                grid[row][i] = 1;
            }else{
                cout << "Wrong character in row. Try again:" << endl;
                error = true;
                break;
            }
        }
        }while(error);
    }
}


void Life::print()
/*
 Pre:  The Life object contains a configuration.
 Post: The configuration is written for the user.
 */

{
    int row, col;
    cout << "\nThe current Life configuration is:" <<endl;
    for (row = 1; row <= maxrow; row++) {
        for (col = 1; col <= maxcol; col++)
            if (grid[row][col] == 1) cout << '*';
            else cout << ' ';
        cout << endl;
    }
    cout << endl;
}



