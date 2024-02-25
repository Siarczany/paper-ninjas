#include "attack.h"
#include "character.h" // idk if infinite loop of includes exists now idk to much brain power needed
#include <iostream>

void attack::set_name(std::string attack_name)
{
    name = attack_name;
}

void attack::set_chance(double percentage)
{
    chance = percentage;
}

void attack::set_dmg_przelicznik(double przelicznik)
{
    multiplier = przelicznik;
}

void attack::set_random_generator(std::default_random_engine* generator)
{
    gen = generator;
}

void attack::set_next_attack(attack* att)
{
    next_attack = att;
}

double attack::random_dmg_spread()
{
    double returning;
    switch(dmg_distribution_int)
    {
    case 1:
        {
            returning = (*normal_dmg)(*gen);
            break;
        }
    case 2:
        {
            returning = (*uniform_dmg)(*gen);
            break;
        }
    default:
        {
            returning = 0;
        }
    }
    return returning;
}

double attack::random_chance_spread()
{
    double returning;
    switch(chance_distribution_int)
    {
    case 1:
        {
            returning = (*normal_chance)(*gen);
            break;
        }
    case 2:
        {
            returning = (*uniform_chance)(*gen);
            break;
        }
    default:
        {
            returning = 0;
        }
    }
    return returning;
}

void attack::set_dmg_distribution(std::string dist)
{
    dmg_distribution_name = dist;
    if(dist == "normal")
    {
        dmg_distribution_int = 1;
    }
    else if(dist == "uniform")
    {
        dmg_distribution_int = 2;
    }
    else
    {
        dmg_distribution_int = 1;
    }
}

void attack::set_chance_distribution(std::string dist)
{
    chance_distribution_name = dist;
    if(dist == "normal")
    {
        chance_distribution_int = 1;
    }
    else if(dist == "uniform")
    {
        chance_distribution_int = 2;
    }
    else
    {
        dmg_distribution_int = 1;
    }
}

void attack::hit(character& attacker, character& victim)
{
    if(attacker.is_alive() && victim.is_alive())
    {
        //std::cout << "mo¿na";
        double temp = /*attacker.get_dmg() * */ multiplier;
        temp = temp + temp * random_dmg_spread()/100;
        //std::cout << random_spread() << "\n";
        int damage = (int)temp;
        victim.set_hp(victim.get_hp() - damage);
        std::cout << "dealt " << damage << "\n";
        victim.update_alive_status();
    }
}

