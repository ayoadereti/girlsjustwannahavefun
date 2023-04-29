// Game Engine
// Machine Used: 2020 MacBook Pro (13-inch)
// Operating System: Mac OS Monterey Version 12.1
// Software Used: Visual Studio Code 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

// Data Structures for World Builder and Game Engine programs 

struct User
{
    string userName;
    string quest;
    string nonsense;
    char userMap;
    int userRow;
    int userCol;
};

struct Creature
{
    string creatureName;
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

// Game Engine Program

void myName()
{
    cout << "Ayobami Adereti" << endl; // Name
    cout << "CS 1337.502" << endl; // Section Information
    cout << "Program 4" << endl; // Assignment
    cout << "11/02/2022" << endl; // Date
    cout << "_______________" << endl;
}

void loadFile(User *userPtr, vector <Creature> *creatures, vector <Grid> *grid)
{

    ifstream saveFile;
    saveFile.open("Save.txt");

    string loadFile;
    int creatureMax;
    int creatureLoop;
    int squareMax;
    int squareLoop;


    getline(saveFile, userPtr->userName, ','); // Get the name 
    
    getline(saveFile, userPtr->quest, ','); // Get the quest 
    
    getline(saveFile, userPtr->nonsense, ','); // Get the answer to the random question
    
    getline(saveFile, loadFile, ',');
    userPtr->userMap = loadFile[0];
    
    getline(saveFile, loadFile, ','); // Get the row
    userPtr->userRow = stoi(loadFile); // Convert the string to an int value
    
    getline(saveFile, loadFile, '\n'); // Get the column  
    userPtr->userCol = stoi(loadFile);


    //Load the Creatures
	getline(saveFile, loadFile);

	/*cout << "[" << loadFile << "]" << endl;*/
	creatureMax = stoi(loadFile);

	Creature *creaturePtr = nullptr;

	for (creatureLoop = 0; creatureLoop < creatureMax; creatureLoop++)
	{
		creaturePtr = new Creature(); //Dynamic allocation

		getline(saveFile, loadFile, ',');
		creaturePtr->creatureName = loadFile;

		getline(saveFile, loadFile, ',');
		creaturePtr->creatureMap = loadFile[0];

		getline(saveFile, loadFile, ',');
		creaturePtr->creatureRow = stoi(loadFile);

		getline(saveFile, loadFile, '\n');
		creaturePtr->creatureCol = stoi(loadFile);

		creatures->push_back(*creaturePtr);
	}


	//Load Grid

	getline(saveFile, loadFile);

	/*cout << "[" << loadFile << "]" << endl;*/
	squareMax = stoi(loadFile);

	Grid *squarePtr = nullptr;

	for (squareLoop = 0; squareLoop < squareMax; squareLoop++)
	{
		squarePtr = new Grid(); //Dynamic allocation

		getline(saveFile, loadFile, ',');
		squarePtr->gridMap = loadFile[0];

		getline(saveFile, loadFile, ',');
		squarePtr->gridRow = stoi(loadFile);

		getline(saveFile, loadFile, '\n');
		squarePtr->gridCol = stoi(loadFile);

		grid->push_back(*squarePtr);
	}

	saveFile.close();

}

void displayImage(User userVar, vector <Creature> creatureVec, vector <Grid> gridVec)
{
    // Loading the 2D array 

    char twoD[10][10]; // Create 10 by 10 2D 

    for (int i = 0; i < 10; i++) // Initialize all values of array to period 
    {
        for (int j = 0; j < 10; j++)
        {
            twoD[i][j] = '.';
        }
    }

    for (int i = 0; i < gridVec.size(); i++) // for each member of grid vector 
    {
        twoD[gridVec[i].gridRow][gridVec[i].gridCol] = gridVec[i].gridMap;
    }

    for (int i = 0; i < creatureVec.size(); i++) // for each member of creature vector
    {
        twoD[creatureVec[i].creatureRow][creatureVec[i].creatureCol] = creatureVec[i].creatureMap;
    }

    twoD[userVar.userRow][userVar.userCol] = userVar.userMap; // for user info 
    

    // Showing the 2D array 

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << twoD[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // Show Creatures 

    for (int i = 0; i < creatureVec.size(); i++)
    {
        cout << creatureVec[i].creatureMap << ": " << creatureVec[i].creatureName << endl;
    }
    cout << endl;

    // Show User

    cout << userVar.userMap << ": " << userVar.userName << endl;
    cout << "User Quest: " << userVar.quest << endl;
    cout << "User Answer to Random Question: " << userVar.nonsense << endl;



}

int main()
{
    User userVar;
    vector <Creature> creatureVec;
    vector <Grid> gridVec;

    myName();
    cout << endl;

    loadFile(&userVar, &creatureVec, &gridVec);

    displayImage(userVar, creatureVec, gridVec);

    return 0;
}
