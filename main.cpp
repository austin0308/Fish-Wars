//
//  main.cpp
//  Fish War, Method
//
//  Created by Austin Le on 9/11/19.
//  Copyright © 2019 Austin Le. All rights reserved.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

//function prototypes
int CompareValues(int &, int &);
int computerTurn();
void AddValuesToVector();
void SearchAndDelete(int);

//vectors for user and cpu
vector<int> userDeck(13);
vector<int> cpuDeck(13);



int main(int argc, const char * argv[]) {
    
    //variable initialization
    int ai = 0;
    int player = 0;
    int cpuBattlePoints = 0;
    int playerPoints = 0;
    int cpuPoints = 0;
    int playerBattlePoints = 0;
    const int TOTALROUND = 13;
    int roundCounter = 1;
    
    //calls the function to add values
    //to the vector
    AddValuesToVector();

    //for loop for the game until it hits round 13
    for(int i = 1; i <= TOTALROUND; i++)
    {
        //displays the current round
        cout << "**********\n*ROUND " << roundCounter << " *\n**********\n\n" << endl;
        
        //displays the cards
        cout << "PICK YOUR CARD \n------------------------------------------------------------------" << endl;
        
        //loop to go through the vectors to display cards for user
        for (int i = 0; i < userDeck.size(); i++)
        {
            if(userDeck.at(i) == 11 || (userDeck.at(i) == 12)) {
                cout << "Peace Card" << "  ";
            }
            else if(userDeck.at(i) == 13) {
                cout << "Shark Card" << "  ";
            }
            else {
               cout << userDeck.at(i) << "  ";
            }
        }
        
        cout << "\n------------------------------------------------------------------\n" << endl;
        
        //takes in the player input
        cin >> player;
        
        //calls the function to search and delete the
        //input from the customers
        SearchAndDelete(player);

        //call the AI turn function and returns a
        //value the AI chose
        ai = computerTurn();
        
        //if statements for if the AI randomly chose 11, 12, or 13
        //11 and 12 display "Peace Cards", 13 displays
        //"Shark Card"
        if (ai == 11 || ai == 12)
        {
            cout << "\nAI PLAYED PEACE CARD\n" << endl;
        }
        else if (ai == 13)
        {
            cout << "\nAI PLAYED PEACE CARD\n" << endl;
        }
        //or it displays the number other than 11,12,13
        else
        {
            cout << "\nAI PLAYED " << ai << endl;
        }
        
        //calls the compareValue function to
        //compare values with the user input
        //and AI input
        int winner = CompareValues(ai, player);
        
        //displays scores
        //if the winner returns 1, AI wins that round
        //if it is 2, Player wins,
        //if it returns 0, no one wins that round
        if (winner == 1)
        {
            cout << "\n\nAI WINS\n" << endl;
            cpuPoints++;
            cpuBattlePoints++;
            cout << "***********************\n* AI SCORE: " << cpuPoints << "         *"<< " \n* AI BATTLE POINTS: " << cpuBattlePoints << " *\n***********************\n" << endl;
            cout << "***************************\n* PLAYER SCORE: " << playerPoints << "         *"<< " \n* PLAYER BATTLE POINTS: " << playerBattlePoints << " *\n***************************\n" << endl;
        }
        else if (winner == 2)
        {
            cout << "\n\nPLAYER WINS\n" << endl;
            playerPoints++;
            playerBattlePoints++;
            cout << "***********************\n* AI SCORE: " << cpuPoints << "         *"<< " \n* AI BATTLE POINTS: " << cpuBattlePoints << " *\n***********************\n" << endl;
            cout << "***************************\n* PLAYER SCORE: " << playerPoints << "         *"<< " \n* PLAYER BATTLE POINTS: " << playerBattlePoints << " *\n***************************\n" << endl;
        }
        else
        {
            cout << "\n\nNO ONE WINS\n\n" << endl;
            cout << "***********************\n* AI SCORE: " << cpuPoints << "         *"<< " \n* AI BATTLE POINTS: " << cpuBattlePoints << " *\n***********************\n" << endl;
            cout << "***************************\n* PLAYER SCORE: " << playerPoints << "         *"<< " \n* PLAYER BATTLE POINTS: " << playerBattlePoints << " *\n***************************\n" << endl;
        }
        
        //increments the round counter
        roundCounter++;
        
    }
    
    
    //decides who wins the game.
    //outputs result
    if (cpuPoints > playerPoints)
    {
        cout << "************\n* AI WINS! *\n************" <<endl;
    }
    else
    {
        cout << "\n\n\n****************\n* PLAYER WINS! *\n****************\n\n\n" << endl;
    }
    
    return 0;
}

//function compares values from cpu and player
int CompareValues(int &CPUCard, int &PlayerCard)
{
    int decideWinner = 0;
    
    //returns 1 if cpu wins
    if (CPUCard > PlayerCard)
    {
        decideWinner = 1;
    }
    //returns 2 if player wins
    else if (PlayerCard > CPUCard)
    {
        decideWinner = 2;
    }
    //returns 3 if no one wins
    else
    {
        decideWinner = 0;
    }
    
    //returns value
    return decideWinner;
}


//Pass in the cpus deck then picks a random value
int computerTurn()
{
    srand(time(0));
    
    int size = cpuDeck.size();
    int randChoice = (rand() % size) + 1;
    
    for (int i = 0; i < cpuDeck.size(); i++)
    {
        if (randChoice == cpuDeck[i])
        {
            randChoice = (rand() % size) + 1;
        }
        else
        {
            break;
        }
    }
    //switch statement that deletes the value from array
    switch (randChoice)
    {
            //based on number randomly created, 1-13,
            //it will delete that value from the vector
        case 1:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 2:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 3:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 4:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 5:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 6:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 7:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 8:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 9:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 10:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 11:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 12:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
        case 13:
        {
            cpuDeck.erase(remove(cpuDeck.begin(), cpuDeck.end(), randChoice), cpuDeck.end());
            break;
        }
    }
    
    //returns the randomly
    //generated value
    return randChoice;
}


void AddValuesToVector()
{
    //goes through a loop and puts in the
    //values for the vector
    for (int i = 0; i < 13; i++)
    {
        userDeck[i] = (i+ 1);
        cpuDeck[i] = (i + 1);
    }
}

void SearchAndDelete(int playerCard)
{
    //switch statement that deletes the value from array
    //based on the users input
    switch (playerCard)
    {
        case 1:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 2:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 3:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 4:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 5:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 6:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 7:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 8:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 9:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 10:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 11:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 12:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
        case 13:
        {
            userDeck.erase(remove(userDeck.begin(), userDeck.end(), playerCard), userDeck.end());
            break;
        }
    }
}
