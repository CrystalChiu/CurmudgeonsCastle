#include "hunter_guard.h"
#include <cmath>   

#ifndef HUNTERCLASS
#define HUNTERCLASS

HunterGuard::HunterGuard(const Position& initPos, const Innocent& hero) : Guard(initPos, 'H')
{
    heroObj = &hero;
}

void HunterGuard::move(const char move)
{
    int hunterX = pos->x;
    int hunterY = pos->y;
    int heroX = heroObj->getPosition().x;
    int heroY = heroObj->getPosition().y;
    char dir;

    if(abs(hunterY - heroY) == abs(hunterX - heroX))
    {
        dir = (pos->getRandomCoord(1,2) == 1) ? 'Y' : 'X'; //random selection of X or Y if equidistant
    }
    if((abs(hunterY - heroY) < abs(hunterX - heroX)  || dir == 'Y' || (hunterX - heroX == 0))
        && abs(hunterY - heroY) != 0) //closer in Y dir
    {
        dir = (heroY > hunterY) ? 's' : 'n';
    }
    else if((abs(hunterX - heroX) < abs(hunterY - heroY)  || dir == 'X' || (hunterY - heroY == 0))
            && abs(hunterX - heroX) != 0 ) // closer in X dir
    {
        dir = (heroX > hunterX) ? 'e' : 'w';
    }

    Position(*pos, dir);
}

#endif