#include "castleClassdupe.h"
#include "innocentClass.h"
#include "indenturedClass.h"
#include "hunterClass.h"
#include "rovingClass.h"

char getChoice();
void clearScreen();

int main()
{
    Castle game;
    char choice; 

    do
    {
        clearScreen();
        std::cout << game; 

        choice = getChoice(); //taking user input
        game.move(choice);
        
        for(int i = 0; i < 11; ++i) //moving guards
        {
          game.guards[i]->move();
        }
        if(game.hasWife == true) //moves hero with wife
        { 
            game.wife->pos->x = game.hero->pos->x;
            game.wife->pos->y = game.hero->pos->y;
        }

        if(game.getStatus() == 3) //Losing conditions
        {
          std::cout << "\nYou Lose!" << std::endl;
          break;
        }
        if(game.getStatus() == 2) //Winning conditions
        {
          std::cout << "\nYou Win!" << std::endl;
          break;
        }
    } while(game.getStatus() == 1);
    
    std::cout << game;
}

char getChoice()
{
    std::string rawInput = " ";
    char move = 'a';
    bool validChoice = false;

    std::cout << "Your move [N,S,W,E,P,C]: ";
    do
    {
        std::cin.clear();
        std::cin >> rawInput;

        if(rawInput.length() == 1)
        {
            move = static_cast<char>(rawInput[0]);
            move = tolower(move);

            if(move == 'n' || move == 's' || move == 'e' || move == 'w' || move == 'p' || move == 'c')
            {
            validChoice = true;
            return move;
            }
        }
        else
        {
            std::cout << "Invalid choice.";
        }
    } while(validChoice == false);

    return move;
}

#define WINDOWS false
void clearScreen()
{    
    if(WINDOWS)        
        system("CLS");    
    else        
        system("clear");
}

