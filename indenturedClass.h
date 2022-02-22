#include "indentured_guard.h"

#ifndef INDENTUREDCLASS
#define INDENTUREDCLASS

IndenturedGuard::IndenturedGuard(const Position& initPos) : Guard(initPos, 'I'){}

void IndenturedGuard::move(char move)
{
    int randomNum = pos->getRandomCoord(0, 100);
    
    if(randomNum < 15)
      randomMove(*pos);
}

#endif