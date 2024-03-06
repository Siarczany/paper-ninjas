#pragma once
#include "stats.h"
//#include "character.h"
#include <string>

class character;

class armour
{
public:
    std::string type;
    std::string name;

    stats stat;

    character* the_equipped_one = nullptr;
};
