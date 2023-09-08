/*
TASK 2
STUDENT GRADE CALCULATOR
7 / 9 / 2023
Take marks obtained (out of 100) in each subject.
Sum up the marks obtained in all subjects.
 Divide the total marks by the total number of subjects to get the
average percentage.
Assign grades based on the average percentage achieved.
Show the total marks, average percentage, and the corresponding grade to the user
 */

import java.util.Scanner;

class calculator {
    private static final Scanner scanner = new Scanner(System.in);

    public static void calculate() {
        System.out.println("Welcome to Student Grade Calculator :)");
        System.out.println("****************************************************************");
        System.out.println("Please enter the number of subjects :");
        int subjectsNumber = scanner.nextInt();
        float marks;
        float total = 0.0f;
        int i = 0;
        String grade;
        //______________________________________________________________________________________________________________
        while (i++ != subjectsNumber) {   // Getting the marks from the user.
            System.out.println("Enter the marks of the subject out of 100 :");
            marks = scanner.nextFloat();
            //__________________________________________________________________________________________________________
            // Validate the marks.
            while (marks < 0 || marks > 100) {
                System.out.println("Invalid Mark !!!");
                marks = scanner.nextFloat();
            }
            //___________________________________________________________________________________________________________
            total += marks; // getting the total marks of all subjects.
            System.out.println("Remaining Subjects: " + (subjectsNumber - i)); // Display the number of remaining subjects.
        }
        //______________________________________________________________________________________________________________
        float avgPercentage = total / subjectsNumber;   // Calculate Average Percentage.
        //______________________________________________________________________________________________________________
        //Grade Calculation.
        if (avgPercentage >= 90) {
            grade = "A+";   // Omar Mohamed & Mohamed Amir favourite grade.
        } else if (avgPercentage >= 85) {
            grade = "A";
        } else if (avgPercentage >= 80) {
            grade = "B+";
        } else if (avgPercentage >= 75) {
            grade = "B";
        } else if (avgPercentage >= 70) {
            grade = "C+";
        } else if (avgPercentage >= 65) {
            grade = "C";
        } else if (avgPercentage >= 60) {
            grade = "D+";
        } else if (avgPercentage >= 50) {
            grade = "D";
        } else {
            grade = "F";
        }
        //______________________________________________________________________________________________________________
        // Display Results.
        System.out.print(
                """
                        +-------+----------------------+-------+
                        | Total | Average Percentage | Grade |
                        +-------+----------------------+-------+
                        """
        );
        System.out.printf("| %-5s | %10s %10s| %-5s |\n", total, avgPercentage, "",grade);  // Format the output.
        System.out.println("+-------+----------------------+-------+");
    }
}
//______________________________________________________________________________________________________________________
public class Main {
    public static void main(String[] args) {
        calculator.calculate();
    }
}