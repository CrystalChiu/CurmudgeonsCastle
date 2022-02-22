#include "roving_guard.h"

#ifndef ROVINGCLASS
#define ROVINGCLASS

RovingGuard::RovingGuard(const Position& initPos) : Guard(initPos, 'R'){}

void RovingGuard::move(char move)
{
    randomMove(*pos);
}

#endif