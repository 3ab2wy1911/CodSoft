/*
TASK 1
NUMBER GAME
7 / 9 / 2023
1. Generate a random number within a specified range, such as 1 to 100.
2. Prompt the user to enter their guess for the generated number.
3. Compare the user's guess with the generated number and provide feedback on whether the guess
is correct, too high, or too low.
4. Repeat steps 2 and 3 until the user guesses the correct number.
5. Limit the number of attempts the user has to guess the number.
6. Add the option for multiple rounds, allowing the user to play again.
7. Display the user's score, which can be based on the number of attempts taken or rounds won.
NUMBER GAME
*/

import java.util.Random;
import java.util.Scanner;

class randomNumber{
    public
     static int generate(){
        Random random = new Random();
        return random.nextInt(1,100);
     }
}
class game{
    static int attempts = 0;   // number of attempts to play.
    static int number = randomNumber.generate();    // The number to be guessed.
    Scanner scanner = new Scanner(System.in);
    int input;

    public boolean playGame(){
        System.out.println("Please enter a number between 1 and 100, Attempts left: " + (10-attempts));
        input = scanner.nextInt();
        //________________________________________________________________
        while (input <1 || input > 100){    // to make sure that the user enter a number between 1 and 100.
            System.out.println("Invalid Number !!! Please enter a number between 1 and 100 : ");
            input = scanner.nextInt();
        }
        //_________________________________________________________________
        // Compare the input of the user with the number
        if (number == input){
            System.out.println("Well done you guessed the number in " + attempts + " attempts");
        }
        else if(input > number && input - number > 20)
        {
            System.out.println(" --> Your guess is too high");
        }
        else if (input > number && input - number <=20)
        {
            System.out.println( " --> Your guess is high");
        }
        else if (input < number && number - input >20)
        {
            System.out.println( " --> Your guess is too low");
        }
        else
        {
            System.out.println(" --> Your guess is low");
        }
        return input == number ;    // return whether the user guessed the number correctly or not.
    }
//______________________________________________________________________
    public void startGame ()
    {
        attempts = 0; // initialize attempts to 0.
        System.out.println("Welcome to Number Game :)");
        System.out.println("--------------------------------");
        while (!playGame() && attempts <10){   // while user still has attempts to play.
            attempts++; // increase attempts of the user by 1
        }
        //________________________________________________________________
        if (attempts ==10){  // If the user failed to guess the number.
            System.out.println("Game Over, the number was " + number);
        }
        //________________________________________________________________
        System.out.println("Current Score = " + (10-attempts) + ", Do You want to play Again ?");
        System.out.println("1.Yes 2.No");
        input = scanner.nextInt();
        if (input == 1){
            playAgain();    // call the function to play again.
        }
        else if (input == 2){
            System.out.println("Thanks for playing Number Game!");  // the exit msg.
        }
    }

//_________________________________________________________________________
    public void playAgain (){
        startGame();
    }
}


public class Main {
    public static void main(String[] args) {
        game newGame = new game();
        newGame.startGame();
    }
}