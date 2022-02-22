#include "castle.h"
#include <cmath>

#ifndef CASTLECLASS
#define CASTLECLASS

Castle::Castle()
{
    srand(time(NULL));

    hasWife = false;
    Position heroCoord(0,0);
    hero = new Innocent(heroCoord, 'Y');
    Position wifeCoord(heroCoord.getRandomCoord(2,3), heroCoord.getRandomCoord(2,3)); //using position object to call randomCoord method
    wife = new Innocent(wifeCoord, 'W');

    //Initialize the guard array
    for(int i = 0; i < 11; ++i)
    {
        Position init(heroCoord.getRandomCoord(1, SIZE-1), heroCoord.getRandomCoord(1, SIZE-1));

        if(i < 5)
        guards.emplace_back(new IndenturedGuard(init));
        else if(i >= 5 && i < 9)
        guards.emplace_back(new RovingGuard(init));
        else
        guards.emplace_back(new HunterGuard(init, *hero));
    }
}

void Castle::move(char move) //only moves hero
{
    if(move == 'c')
        carry();
    else//FIX HERE
        Position(*hero->pos, move); //calls copy constructor
}

void Castle::carry()
{
    if(hero->pos->x == wife->pos->x && 
        hero->pos->y == wife->pos->y)
        hasWife = true;
}

std::ostream& operator<<(std::ostream& out, const Castle& game)
{
    bool hasI = false;
    bool hasH = false;
    bool hasR = false;
    char type;

    out << "Welcome to the Curmudgeon's Castle" << std::endl;
    out << "-------------------------" << std::endl;

    for(int y = 0; y < game.SIZE; ++y)
    {
        out << "| ";

        for(int x = 0; x < game.SIZE; ++x)
        {
            if(game.hero->getPosition().x == x && game.hero->getPosition().y == y)
                out << "Y";
            if(game.wife->getPosition().x == x && game.wife->getPosition().y == y)
                out << "W";
            for(int i = 0; i < 11; ++i)
            {
                if(game.guards[i]->getPosition().x == x
                && game.guards[i]->getPosition().y == y)
                {
                    type = game.guards[i]->getType();

                    if(type == 'I' && hasI == false)
                    {
                        out << 'I';
                        hasI = true;
                    }
                    else if(type == 'R' && hasR == false)
                    {
                        out << 'R';
                        hasR = true;
                    }
                    else if(type == 'H' && hasH == false)
                    {
                        out << 'H';
                        hasH = true;;
                    }
                }
            }
            out << " | ";
        }
        hasI = false; 
        hasR = false;
        hasH = false;
        out << "\n-------------------------" << std::endl;
    }
    return out;
}

int Castle::getStatus()
{
    enum status{INPLAY = 1, WIN = 2, LOSE = 3};

    if(hero->pos->x + hero->pos->y == 0 && hasWife)
        return WIN;

    for(int i = 0; i < 11; ++i)
    {
        if(*hero == *guards[i])
        {
            return LOSE;
        }

        if(guards[i]->getType() == 'H')
        {
            if( std::abs((int)(hero->pos->x - guards[i]->pos->x))
            + std::abs((int)(hero->pos->y - guards[i]->pos->y)) == 1)
            {
                return LOSE;
            }
        }
    }
    return INPLAY;
}

Castle::~Castle()
{
    delete hero;
    delete wife;

    while(!guards.empty())
    {
        Guard* guard = guards.back();
        guards.pop_back();
        delete guard;
    }
}

#endif