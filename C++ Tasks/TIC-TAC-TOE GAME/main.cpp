#include <bits/stdc++.h>
using namespace std;
/*
TASK 3
3 / 9 / 2023
TIC-TAC-TOE GAME
A simple console-based Tic-Tac-Toe game that
allows two players to play against each other.
 */

char Board [3][3];
char player = 'X';
int Turns = 0;

//________________________________________________________________

void GameBoard(){   // initialize the game.
    char num ='1';
    for (auto & i : Board)
    {
        for (char & j : i){
            j = num;
            num++;
        }
    }
    Turns = 0;
}

//________________________________________________________________

void DisplayBoard(){    // Display the board.
    for (auto & i : Board){
        for (char j : i)
            cout << "| " << j << " ";

        cout <<"|\n+---+---+---+\n";
    }
}

//________________________________________________________________

bool UpdateBoard(int choice){   // Update the game board.
    for (auto & i : Board)
    {
        for (char & j : i){
            if (j == choice+'0')
            {
                j = player;
                return true;
            }
        }
    }
    return false;
}

//________________________________________________________________________

void SwitchPlayer(){    // switch turns.
    player == 'X' ? player = 'O' : player = 'X';
}

//________________________________________________________________________

bool DisplayResult(){   // Display the result of the game.

    if(Board [0][0] == Board[1][1] and Board[1][1] == Board[2][2]or ( Board [0][2] == Board[1][1] and Board[1][1] == Board [2][0])){
        if (player == 'O')
        {
            cout <<"Player 1 Won !!!" << endl;
        }
        else{
            cout <<"Player 2 Won !!!" << endl;
        }
        return true;
    }

//----------------------------------------------------------------

    for(int i = 0; i < 3; i++){
        if(Board[i][0] == Board[i][1] and Board[i][1]== Board[i][2] or (Board[0][i] == Board[1][i] and Board[1][i] == Board[2][i] )){
            if (player == 'O')
            {
                cout <<"Player 1 Won !!!" << endl;
            }
            else{
                cout <<"Player 2 Won !!!" << endl;
            }
            return true;
        }
    }

//----------------------------------------------------------------

    if (Turns == 9){
        cout<<"TIE !!!"<<endl;
        return true;
    }

//----------------------------------------------------------------

    return false;

}

//________________________________________________________________________

void game (){
    cout << "Welcome to TIC-TAC-TOE GAME :)" << endl;
    int choice;
    f1 :
    GameBoard();
    while(!DisplayResult()){
        DisplayBoard();
        if (player == 'X'){
            cout<< "Player 1 Turn"<< endl;
        }
        else {
            cout<< "Player 2 Turn"<< endl;
        }
        cin >> choice;

        while(!UpdateBoard(choice)){
            DisplayBoard();
            cout<< "Invalid Choice !!!, Try again..."<<endl;
            cin>>choice;
        }
        SwitchPlayer();
        Turns++;
    }
    DisplayBoard();
    cout<<"If you want to continue Playing enter 1 ... enter any number to end the game."<<endl;    // check if the user wants to play again.
    cin >> choice;
    if (choice == 1)
    {
        goto f1;    // return to the beginning of the game.
    }
    cout<<"Thanks for playing TIC-TAC-TOE GAME :)"<<endl;   // msg shown in the end of the game.

}

//________________________________________________________________________

int main() {
    game();
}
