#include <bits/stdc++.h>
using namespace std;
/*
TASK 1
NUMBER GUESSING GAME
2/9/2023
A program that generates a random number and asks the
user to guess it then provides feedback on whether the guess is too
high or too low until the user guesses the correct number.
*/

int random_number(){
    return max(rand() % 100,1);     // returns a random number between 0 and 100.
}

void game (){
    int input = 0, number = random_number(),tries=0;
    cout << "Welcome to NUMBER GUESSING GAME!" << endl;
    cout << "--------------------------------"<<endl;
    cout <<"Please, guess a number less than 100 : " << endl;

    //________________________________

    while (input != number){    // will take a number from the user till the user guesses the right number.
        cin>>input;
        if(input <= 0 or input >= 100)
        {
            cout << "Please, guess a number between 0 and 100"<<endl;
        }
        else if(input > number and input - number > 20)
        {
            cout << input << " --> Your guess is too high"<<endl;
        }
        else if (input > number and input - number <=20)
        {
            cout << input << " --> Your guess is high"<<endl;
        }
        else if (input < number and number - input >20)
        {
            cout << input <<" --> Your guess is too low"<<endl;
        }
        else
        {
            cout << input << " --> Your guess is low"<<endl;
        }
        tries++;
    }

    //______________________

    cout << "Well done you guessed the number in "<<tries;
    (tries>1) ? cout << " turns" << endl : cout <<" turn"<< endl;   // to detect whether we use the Singular or the Plural Form of the word.
    cout << "--------------------------------"<<endl;
}
int main() {
    game();
}
