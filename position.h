#include <stddef.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef POSITION_H
#define POSITION_H

struct Position
{
    size_t x;
    size_t y;

    int getRandomCoord(int min, int max)
    {
      return(rand() % max + min);
    }

    Position(size_t x, size_t y) //constructor
    {
        this->x = x;
        this->y = y;
    }

    Position(Position& other, char move) //Copy constructor; use for moving the sprites by passing in a new position
    {
        int SIZE = 8;

        switch(move)
        {
          case 's':
            if(other.y < SIZE - 1)
            {
                ++other.y;
            }
            else
            {
                try{throw std::invalid_argument("Illegal Move.");}
                catch(std::invalid_argument){break;}
            }
            break;
          case 'n':
            if(other.y > 0)
                --(other.y);
            else   
            {
                try{throw std::invalid_argument("Illegal Move.");}
                catch(std::invalid_argument){break;}
            }
            break;
          case 'w':
            if(other.x > 0)
                --(other.x);
            else
            {
                try{throw std::invalid_argument("Illegal Move.");}
                catch(std::invalid_argument){break;}
            }
            break;
          case 'e':
            if(other.x < SIZE - 1)
                ++(other.x);
            else
            {
                try{throw std::invalid_argument("Illegal Move.");}
                catch(std::invalid_argument){break;}
            }
            break;
          default: //Pause
            break;
        }
    } 
};

#endif