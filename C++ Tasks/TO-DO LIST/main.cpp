#include <bits/stdc++.h>
using namespace std;

/*TASK 4
TO-DO LIST
4 / 9 / 2023
A simple console-based to-do list manager
that allows users to add, view, and delete tasks.
 */

vector <pair<string,string>> tasks; // list of tasks.

void Add(const string& task){
    tasks.emplace_back(task,"Pending"); // add task to list.
}

//________________________________________________________________

void View(){
    int count =1;
    for (const auto& i : tasks) {
        cout <<"Task " << count <<" : "<< i.first << "\nStatus : "<< i.second << endl;
        cout <<"________________________________\n";
        count ++;
    }
}

//________________________________________________________________

void Completed(int taskNumber){
    tasks[taskNumber-1].second="Completed";
}

//________________________________________________________________

void Delete(int taskNumber){
    taskNumber -=1;
    tasks.erase(tasks.begin()+taskNumber);
}

//________________________________________________________________

void Save(){
    fstream out;
    out.open("task.csv", ios::out | ios::trunc);    // trunc --> to override the file.
    for (const auto& i : tasks){
        out << i .first<<","<<i.second<<'\n';
    }
    out.close();

}

//________________________________________________________________

void Load(){
    tasks.clear();
    fstream in;
    in.open("task.csv");
    string row,firstWord,secondWord;

    // Read and store the first and second words in a vector of pairs
    while (getline(in, row)) {
        istringstream iss(row);
        // Use getline with ',' as the delimiter to extract both words
        if (getline(iss, firstWord, ',') and getline(iss, secondWord, ',')) {
            tasks.emplace_back(firstWord, secondWord);
        }
        else {
            cerr << "Error parsing row: " << row << endl;
        }
    }
    in.close();
}

//________________________________________________________________

void Program(){
    Load();
    cout << "Welcome to TO-DO LIST Program :) "<<endl;
    cout << "-----------------------------------\n";

    //----------------------------------------------------------------

    int input = 1,taskNum;
    string task;

    //----------------------------------------------------------------

    while(input){
        cout << "Your Currently Tasks are :\n";
        View();
        cout << "-----------------------------------\n";
        cout << "Choose an Option :\n1.Add new task.\n2.Mark a task as completed.\n3.Delete a task.\n0.exit\n";

        //----------------------------------------------------------------

        cin>>input;

        //----------------------------------------------------------------

        if (input == 1){

            cout << "Enter Your Task :\n";
            cin.ignore();
            getline(cin,task);
            Add(task);
            cout<<"Task Added Successfully :)\n";
        }

        //----------------------------------------------------------------

        else if ((input >0 and input <4) and !tasks.empty()){

            cout<<"Enter task number :\n";
            cin>>taskNum;

            //-------------------

            while(taskNum>tasks.size() or taskNum <= 0 ){
                cout <<"Invalid task number !!! Enter a valid number :\n";
                cin>>taskNum;
            }
            //---------------------

            if(input == 2){

                Completed(taskNum);
                cout<<"Task Updated successfully :)\n";
            }

            //-----------------------

            else{

                Delete(taskNum);
                cout<<"Task Deleted successfully :)\n";

            }
        }

        //----------------------------------------------------------------

        else if (input !=0){

            cout <<"Invalid Choice !!!\n";

        }

        //----------------------------------------------------------------

        Save();
    }
    cout<<"Thanks for using TO-DO LIST Program \n";
}
int main() {
    Program();
}
