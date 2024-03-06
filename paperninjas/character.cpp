#include "character.h"
#include <random>
#include <iostream> // testing

bool character::is_alive()
{
    return alive;
}

void character::set_alive_status(bool is_alive)
{
    alive = is_alive;
}

void character::set_hp(int health_points)
{
    hp = health_points;
}

void character::set_max_hp(int max_health_points)
{
    stat.hp = max_health_points;
}

void character::set_mana(int mana_points)
{
    mana = mana_points;
}

void character::set_max_mana(int max_mana_points)
{
    stat.mana = max_mana_points;
}

void character::set_konda(int konda_points)
{
    konda = konda_points;
}

void character::set_max_konda(int max_konda_points)
{
    stat.konda = max_konda_points;
}

void character::set_knowledge(int knowledge)
{
    stat.knowledge = knowledge;
}

void character::set_power(int power)
{
    stat.power = power;
}
void character::set_strength(int strength)
{
    stat.strength = strength;
}
void character::set_agility(int agility)
{
    stat.agility = agility;
}


int character::get_hp()
{
    return hp;
}

int character::get_max_hp()
{
    return stat.hp;
}

int character::get_mana()
{
    return mana;
}

int character::get_max_mana()
{
    return stat.mana;
}

int character::get_konda()
{
    return konda;
}

int character::get_max_konda()
{
    return stat.konda;
}

int character::get_knowledge()
{
    return stat.knowledge;
}
int character::get_power()
{
    return stat.power;
}
int character::get_strength()
{
    return stat.strength;
}
int character::get_agility()
{
    return stat.agility;
}




void character::update_alive_status()
{
    if(hp <= 0)
    {
        alive = false;
    }
    else
    {
        alive = true;
    }
}

void character::set_equipabble_limit(std::string type, int number)
{
    bool is_there = false;
    int index;
    for(int i = 0; i<(int)max_eq.size(); i++)
    {
        if(type == max_eq[i].type)
        {
            index = i;
            is_there = true;
        }
        /*if(type == max_eq[i].type)
        {
            if(number != 1)
            {
                max_eq[i].max_number = number;
            }
            else
            {
                max_eq.erase(max_eq.begin()+i);
            }
        }//*/
    }
    if(number != 1)
    {
        if(is_there)
        {
            max_eq[index].max_number = number;
        }
        else
        {
            character::max_equipabble temp;
            temp.max_number = number;
            temp.type = type;
            max_eq.push_back(temp);
        }
    }
    else
    {
        if(is_there)
        {
            max_eq.erase(max_eq.begin()+index);
        }
    }
}

void character::set_equipabble_limit_test()
{
    for(int i = 0; i<(int)max_eq.size(); i++)
    {
        std::cout << max_eq[i].type << ": " << max_eq[i].max_number << "\n";
    }
    std::cout << "\n\n";
}

void character::add_armour(armour &piece)
{
    // if none of the type are equipped than equip
    // if the type is equipped then check how much can be

    //
    // how many of the same type is already equipped
    //

    int type_equipped = 0;

    for(int i = 0; i<(int)eq.size(); i++)
    {
        if(eq[i]->type == piece.type)
        {
            type_equipped++;
        }
    }

    int max_number_equipabble = 1;

    for(int i = 0; i<(int)max_eq.size(); i++)
    {
        if(max_eq[i].type == piece.type)
        {
            max_number_equipabble = max_eq[i].max_number;
        }
    }

    if(max_number_equipabble <= type_equipped)
    {
        //eq.push_back(piece);
        //can_be_equipped = false;
        return;
    }

    if(piece.the_equipped_one != nullptr)
    {
        return;
    }

    piece.the_equipped_one = this;
    eq.push_back(&piece);
}

void character::add_armour_test()
{
    for(int i = 0; i<(int)eq.size(); i++)
    {
        std::cout << eq[i]->type << " " << eq[i]->name << "\n";
    }
    std::cout << "\n\n";
}


