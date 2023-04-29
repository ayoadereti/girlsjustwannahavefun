// World Builder
// Machine Used: 2020 MacBook Pro (13-inch)
// Operating System: Mac OS Monterey Version 12.1
// Software Used: Visual Studio Code 

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

// Data Structures for World Builder program

struct User
{
    string uName;
    string quest;
    string nonsense;
    char userMap;
    int userRow;
    int userCol;
};

struct Creature
{
    string cName;
    char creatureMap;
    int creatureRow;
    int creatureCol;
};

struct Grid
{
    char gridMap;
    int gridRow;
    int gridCol;
};

// World Builder Program

void createUser(User *userVar)
{
    string name1;
    string quest1;
    string answer;
    char symbol;
    int row;
    int col;

    cout << "What is your name?" << endl;
    getline(cin, name1);
    cin.ignore(10000, '\n');
    cout << endl;

    cout << "What is your quest?" << endl;
    getline(cin, quest1);
    cin.ignore(10000, '\n');
    
    vector<string> randomQuestion{ "What is your favorite color?", "Waht is the capital of Assyria?", "What is the airspeed velocity of an unladen swallow?" };

    int questNum = rand() % 3;
    cout << randomQuestion[questNum] << endl;
    getline(cin, answer);
    cin.ignore(10000, '\n');
    
    cout << "What is your symbol?" << endl;
    cin >> symbol;
    cout << endl;

    cout << "What row are you in?" << endl;
    cin >> row;
    cout << endl;

    cout << "What column are you in?" << endl;
    cin >> col;
    cout << endl;
     
    
    userVar->uName = name1;
    userVar->quest = quest1;
    userVar->nonsense = answer;
    userVar->userMap = symbol;
    userVar->userRow = row;
    userVar->userCol = col;
    
    

}

void createCreature(vector <Creature> *creatureVec)
{
    string name2;
    char symbol;
    int row;
    int col;

    cout << "What is its name?" << endl;
    getline(cin, name2);
    cin.ignore(10000, '\n');
    cout << endl;

    cout << "What is its symbol?" << endl;
    cin >> symbol;
    cout << endl;

    cout << "What row is it in?" << endl;
    cin >> row;
    cout << endl;

    cout << "What column is it in?" << endl;
    cin >> col;
    cout << endl;
    
    Creature *creaturePtr;
    creaturePtr = new Creature;
    
    creaturePtr->cName = name2;
    creaturePtr->creatureMap = symbol;
    creaturePtr->creatureRow = row;
    creaturePtr->creatureCol = col;
    

    creatureVec->push_back(*creaturePtr);

}

void createTerrain(vector <Grid> *gridVec)
{
    int row;
    string tenChar;

    cout << "What row will this be?" << endl;
    cin >> row;
    cout << endl;

    cout << "Please type 10 characters" << endl;
    cin >> tenChar;
    cout << endl;

    cout << "Thank you. Processing..." << endl;
    cout << endl;

    if (tenChar.size() == 10)
    {
        for (int i = 0; i < tenChar.size(); i++)
        {
            Grid *gridPtr = nullptr;
            gridPtr = new Grid;

            gridPtr->gridRow = row;
            gridPtr->gridCol = i;
            gridPtr->gridMap = tenChar[i];

            gridVec->push_back(*gridPtr);
        }
 
    }
}

void saveFile(User userVar, vector <Creature> creatureVec, vector <Grid> gridVec)
{
    ofstream saveFile;
    saveFile.open("Save.txt");

    if (saveFile.is_open())
    {
        saveFile << userVar.uName << "," << userVar.quest << "," << userVar.nonsense;
        saveFile << "," << userVar.userMap << "," << userVar.userRow << "," << userVar.userCol << endl;
    
        saveFile << creatureVec.size() << endl;

        for (int i = 0; i < creatureVec.size(); i++)
        {
            saveFile << creatureVec[i].cName << "," << creatureVec[i].creatureMap;
            saveFile << "," << creatureVec[i].creatureRow << "," << creatureVec[i].creatureCol << endl;
        }

        saveFile << gridVec.size() << endl;

        for (int i = 0; i < gridVec.size(); i++)
        {
            saveFile << gridVec[i].gridMap << "," << gridVec[i].gridRow << ",";
            saveFile << gridVec[i].gridCol << endl;
        }

    }

    saveFile.close();
}

void myName()
{
    cout << "Ayobami Adereti" << endl; // Name
    cout << "CS 1337.502" << endl; // Section Information
    cout << "Program 4" << endl; // Assignment
    cout << "11/02/2022" << endl; // Date

}

void menu()
{
    vector <Grid> gridVec;
    vector <Creature> creatureVec;
    User userVar;
    int userSelect;

    while (userSelect!=5)
    {
        cout << "1. Create User" << endl;
        cout << "2. Create Creature" << endl;
        cout << "3. Create a row of terrain" << endl;
        cout << "4. Save File" << endl;
        cout << "5. Quit" << endl;
        cout << "__________________________" << endl;
        cout << endl;

        cout << "Choose a selection from the menu" << endl;
        cin >> userSelect;
        cout << endl;

        switch (userSelect)
        {
            case 1:
                createUser(&userVar);
                break;
            case 2:
                createCreature(&creatureVec);
                break;
            case 3:
                createTerrain(&gridVec);
                break;
            case 4:
                saveFile(userVar, creatureVec, gridVec);
                break;
            case 5:
                break;
            default:
                cout << "The number you enter was invalid. Please try again" << endl;
                break;
        }
    
    }


}


int main()
{
    srand(time(0));

    myName();
    cout << endl;

    menu();

    return 0;
}


