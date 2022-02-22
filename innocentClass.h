#include "innocent.h"

#ifndef INNOCENTCLASS
#define INNOCENTCLASS

Innocent::Innocent(const Position& pos, char type) : Person(pos, type){}

void Innocent::move(const char move)
{
    Position(*pos, move);
}

#endif
