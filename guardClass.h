#include "guard.h"

#ifndef GUARDCLASS
#define GUARDCLASS

Guard::Guard(const Position& initPos, char type) : Person(initPos, type){}

void Guard::randomMove(Position& pos)
{
    int choice;
    bool valid = false;
    const int SIZE = 8;

    do
    {
        choice = pos.getRandomCoord(1,4);
        
        switch(choice)
        {
            case 1: //down
                if(pos.y < SIZE - 1)
                {
                    valid = true;
                    ++pos.y;
                }
                break;
            case 2: //up
                if(pos.y > 0)
                {
                    valid = true;
                    --pos.y;
                }
                break;
            case 3: //east
                if(pos.x > SIZE - 1)
                {
                    valid = true;
                    ++pos.x;
                }
                break;
            case 4: //west
                if(pos.x > 0)
                {
                    valid = true;
                    --pos.x;
                }
                break;
        } //end switch case
    } while(!valid);
}

#endif