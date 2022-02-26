//include libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//global variable declaration
char shown[10][10];
char hidden[10][10];

//function declaration
void createHidden();
void createShown();
void fillAround(int row, int col);
void printGrid();
int check (int row, int col);
void flag (int row, int col);
int checkWin();


int main() {
    //ensures for random mine placement for every run
    srand(time(NULL));
    //local variable declaration
    char command;
    int row = 0;
    int col = 0;
    int mineHit = 1;
    int won = 0;



    //creates the hidden and shown grids, and prints the shown grid
    createHidden();
    createShown();
    printGrid();


    //while loop to make sure the game will continue until a win or lose condition
    while (1) {
        //prompt user for input
        printf("\nEnter 'c' for check cell, 'f' for flag cell.\n");
        printf("Enter command & cell row col:");
        scanf("%s %d %d", &command, &row, &col);

        //if the user wishes to check, check function is called, and it's return value is assigned to mineHit
        if (command == 'c') {
            mineHit = check(row, col);
            printGrid();
        }
        //if the user wishes to flag the flag function is called
        if (command == 'f') {
            flag(row, col);
            printGrid();
        }

        //assigns won to the returned value of checkWin
        won = checkWin();

        //if the checkWin value returned a 1 (win condition)
        if (won == 1) {
            printf("\nCongratulations! You win!");
            break;
        }
        //if the check function returned a 0 (a mine was hit)
        if (mineHit == 0) {
            printf("\nYou hit a mine, game over.");
            break;
        }
    }
}

void createHidden(){
    //for loop to initialize hidden grid M's
    for (int i = 0; i<10;i++) {
        //randomizes x and y values
        int x = rand() % 10;
        int y = rand() % 10;
        //sets the random index to equal an M if it isn't already an M
        if (hidden[x][y] != 'M') {
            hidden[x][y] = 'M';
            //if an M was already at that index, the for loop is run +1 more time
        }else{
            i -= 1;
        }
    }
    //declare count variable
    int mineCount = 0;
    //for loop to place numbers between the two end columns
    for (int i = 0; i<10;i++) {
        for (int j = 1; j < 9; j++) {
            //goes through every 2D array index (not the left and right columns) and checks around it (8 other indexes).
            // Each time an index around the current index is an 'M' mineCount is increased.
            mineCount = 0;
            if(hidden[i+1][j]=='M')
                mineCount+=1;
            if(hidden[i][j+1]=='M')
                mineCount+=1;
            if(hidden[i-1][j]=='M')
                mineCount+=1;
            if(hidden[i][j-1]=='M')
                mineCount+=1;
            if(hidden[i+1][j+1]=='M')
                mineCount+=1;
            if(hidden[i-1][j-1]=='M')
                mineCount+=1;
            if(hidden[i+1][j-1]=='M')
                mineCount+=1;
            if(hidden[i-1][j+1]=='M')
                mineCount+=1;
            //Assigns the value of mineCount to the appropriate value (unless the current index is an 'M')
            if (hidden[i][j]=='M')
                hidden[i][j]='M';
            else if (mineCount == 0){
                hidden[i][j]='0';
            }else if (mineCount == 1){
                hidden[i][j]='1';
            }else if (mineCount == 2){
                hidden[i][j]='2';
            }else if (mineCount == 3){
                hidden[i][j]='3';
            } else if (mineCount == 4) {
                hidden[i][j] = '4';
            } else if (mineCount == 5) {
                hidden[i][j] = '5';
            } else if (mineCount == 6) {
                hidden[i][j] = '6';
            } else if (mineCount == 7) {
                hidden[i][j] = '7';
            } else if (mineCount == 8) {
                hidden[i][j] = '8';
            }
        }
    }

    //for loop to place numbers in the first column
    //Same thing as above but for the left most column
    for (int i = 0; i < 10; i++) {
        mineCount = 0;
        if (hidden[i + 1][0] == 'M')
            mineCount += 1;
        if (hidden[i + 1][1] == 'M')
            mineCount += 1;
        if (hidden[i][1] == 'M')
            mineCount += 1;
        if (hidden[i - 1][1] == 'M')
            mineCount += 1;
        if (hidden[i - 1][0] == 'M')
            mineCount += 1;
        if (hidden[i][0] == 'M')
            hidden[i][0] = 'M';
        else if (mineCount == 0) {
            hidden[i][0] = '0';
        } else if (mineCount == 1) {
            hidden[i][0] = '1';
        } else if (mineCount == 2) {
            hidden[i][0] = '2';
        } else if (mineCount == 3) {
            hidden[i][0] = '3';
        } else if (mineCount == 4) {
            hidden[i][0] = '4';
        } else if (mineCount == 5) {
            hidden[i][0] = '5';
        } else if (mineCount == 6) {
            hidden[i][0] = '6';
        } else if (mineCount == 7) {
            hidden[i][0] = '7';
        } else if (mineCount == 8) {
            hidden[i][0] = '8';
        }
    }
    //for loop to place numbers in the last column
    //Same thing as above but for the right most column
    for (int i = 0; i < 10; i++) {
        mineCount = 0;
        if (hidden[i+1][9] == 'M')
            mineCount += 1;
        if (hidden[i+1][8] == 'M')
            mineCount += 1;
        if (hidden[i][8] == 'M')
            mineCount += 1;
        if (hidden[i-1][8] == 'M')
            mineCount += 1;
        if (hidden[i-1][9] == 'M')
            mineCount += 1;
        if (hidden[i][9] == 'M')
            hidden[i][9] = 'M';
        else if (mineCount == 0) {
            hidden[i][9] = '0';
        } else if (mineCount == 1) {
            hidden[i][9] = '1';
        } else if (mineCount == 2) {
            hidden[i][9] = '2';
        } else if (mineCount == 3) {
            hidden[i][9] = '3';
        } else if (mineCount == 4) {
            hidden[i][9] = '4';
        } else if (mineCount == 5) {
            hidden[i][9] = '5';
        } else if (mineCount == 6) {
            hidden[i][9] = '6';
        } else if (mineCount == 7) {
            hidden[i][9] = '7';
        } else if (mineCount == 8) {
            hidden[i][9] = '8';
        }
    }
}

void createShown(){
    //for loop to initialize shown grid
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            shown[i][j] = '*';
        }
    }
}

void fillAround(int row, int col){
    //sets the shown grid to equal the hidden grid around the given index (not the left and right columns)
    //Does not fill zeros
    if (col==0){
        for (int i = -1; i <= 1; i++){
            for (int j = 0; j <= 1; j++){
                if (hidden[row+i][col+j]!='0')
                    shown[row+i][col+j]=hidden[row+i][col+j];
            }
        }
        //Does the same but for the right column
    }else if (col==9){
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 0; j++){
                if (hidden[row+i][col+j]!='0')
                    shown[row+i][col+j]=hidden[row+i][col+j];
            }
        }
        //does the same but for the left column
    }else{
        for (int i = -1; i <= 1; i++){
            for (int j = -1; j <= 1; j++){
                if (hidden[row+i][col+j]!='0')
                    shown[row+i][col+j]=hidden[row+i][col+j];
            }
        }
    }
}


void printGrid(){
    //prints the current grid. Every 10 characters a new line is printed to create 10x10 grid.
    for (int i = 0; i<10;i++){
        printf("\n");
        for (int j = 0; j<10;j++){
            printf("%c  ",shown[i][j]);
        }
    }
}

int check (int row, int col) {
    //if a mine is hit return 0 and reveal that index
    if (hidden[row][col] == 'M') {
        shown[row][col] = hidden[row][col];
        return 0;
        //if the chosen index is not a zero, return 1 and reveal that index
    } else if (hidden[row][col] != '0') {
        shown[row][col] = hidden[row][col];
        return 1;
    }
    //if the value is a zero, reveal that value and call fill around function.
    //Then call check function recursively if the index around the current index has a hidden value of zero and a shown value of '*'
    //Does this for left column, then right column, then middle columns.
    if (hidden[row][col] == '0') {
        shown[row][col] = hidden[row][col];
        fillAround(row, col);
        //left column
        if (col == 0) {
            if (hidden[row - 1][col] == '0' && shown[row - 1][col] == '*') {
                check(row - 1, col);
            }
            if (hidden[row+1][col] == '0' && shown[row+1][col] == '*') {
                check(row+1, col);
            }
            if (hidden[row][col+1] == '0' && shown[row][col+1] == '*') {
                check(row, col+1);
            }
            if (hidden[row+1][col+1] == '0' && shown[row+1][col+1] == '*') {
                check(row+1, col+1);
            }
            if (hidden[row - 1][col+1] == '0' && shown[row - 1][col+1] == '*') {
                check(row - 1, col+1);
            }
            //right column
        } else if (col == 9) {
            if (hidden[row - 1][col] == '0' && shown[row - 1][col] == '*') {
                check(row - 1, col);
            }
            if (hidden[row][col - 1] == '0' && shown[row][col - 1] == '*') {
                check(row, col - 1);
            }
            if (hidden[row+1][col] == '0' && shown[row+1][col] == '*') {
                check(row+1, col);
            }
            if (hidden[row - 1][col - 1] == '0' && shown[row - 1][col - 1] == '*') {
                check(row - 1, col - 1);
            }
            if (hidden[row+1][col - 1] == '0' && shown[row+1][col - 1] == '*') {
                check(row+1, col - 1);
            }
            //middle columns
        } else {
            if (hidden[row - 1][col] == '0' && shown[row - 1][col] == '*') {
                check(row - 1, col);
            }
            if (hidden[row][col - 1] == '0' && shown[row][col - 1] == '*') {
                check(row, col - 1);
            }
            if (hidden[row+1][col] == '0' && shown[row+1][col] == '*') {
                check(row+1, col);
            }
            if (hidden[row][col+1] == '0' && shown[row][col+1] == '*') {
                check(row, col+1);
            }
            if (hidden[row - 1][col - 1] == '0' && shown[row - 1][col - 1] == '*') {
                check(row - 1, col - 1);
            }
            if (hidden[row+1][col+1] == '0' && shown[row+1][col+1] == '*') {
                check(row+1, col+1);
            }
            if (hidden[row - 1][col+1] == '0' && shown[row - 1][col+1] == '*') {
                check(row - 1, col+1);
            }
            if (hidden[row+1][col - 1] == '0' && shown[row+1][col - 1] == '*') {
                check(row+1, col - 1);
            }
        }
        //returns 1 as a mine was not hit
        return 1;
    }
}



void flag (int row, int col){
    //sets the shown value at the given index to equal 'F'
    if (shown[row][col]=='*') {
        shown[row][col] = 'F';
    }
}

int checkWin(){
    //assumes a win unless proven to be a loss
    int won = 1;
    for (int i = 0; i<10;i++){
        for (int j = 0; j<10;j++){
            //returns 0 (loss) if there is a star or flag at an index that is not a mine
            if ((shown[i][j]=='*' || shown[i][j]=='F') && hidden[i][j]!='M')
                won = 0;
        }
    }
    //returns the value of won
    return won;
}
