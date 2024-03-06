#pragma once
//#include "character.h"
#include <string>
#include <random>

class character;

class attack
{
private:
    std::string name;  // name of the attack
    double chance;     // chance to hit
    double multiplier; // multiplies the character dmg

    std::normal_distribution<double>* normal_chance = nullptr;        //
    std::uniform_real_distribution<double>* uniform_chance = nullptr; //
    std::normal_distribution<double>* normal_dmg = nullptr;           // rng
    std::uniform_real_distribution<double>* uniform_dmg = nullptr;    //
    std::default_random_engine* gen = nullptr;                        //

    std::string dmg_distribution_name;    //
    int dmg_distribution_int;             // which distribution use when calculating dmg and chance
    std::string chance_distribution_name; //
    int chance_distribution_int;          //

    attack* next_attack = nullptr; // next attack to perform on the enemy

    double random_dmg_spread();    //
    double random_chance_spread(); // implementing this one into the hit function would require to word on character in order to give them statistics of some kind

    bool is_this(std::string attack_name); // maybe usefull in the future idk
public:
    void set_name(std::string attack_name);       //
    void set_chance(double percentage);           // set attack stats
    void set_dmg_przelicznik(double przelicznik); //

    void set_random_generator(std::default_random_engine* generator);                                                                             //
    void set_dmg_distribution(std::string dist);                                                                                                  //
    void set_chance_distribution(std::string dist);                                                                                               // settings for rng in the attack
    void set_chance_distributions(std::normal_distribution<double>* normal = nullptr, std::uniform_real_distribution<double>* uniform = nullptr); //
    void set_dmg_distributions(std::normal_distribution<double>* normal = nullptr, std::uniform_real_distribution<double>* uniform = nullptr);    //

    void set_next_attack(attack* att); // if we want to chain attacks but I kinda decided that this class is for dealing damage only so kinda redundant I think

    void hit(character& attacker, character& victim); // function that deals damage

};
