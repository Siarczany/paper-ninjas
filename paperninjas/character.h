#pragma once
//#include "attack.h"
#include "stats.h"
#include "armour.h"
#include <vector>
#include <string>

class attack;

class character
{
private:
    std::string texture_file_path; // image path for the character
                                   // I kinda am running a little bit forward because it probably would be smart to add this when we switch over to qt

    bool alive;

    int x;      //
    int y;      // character position as well as their size on the screen
    int width;  //
    int height; //

    stats stat; // this represents their max hp and such

    std::vector<armour*> eq; // vector of their equipment that they have on themselves
    struct max_equipabble // if you want to be able to equip 2 of the same type of equipment
    {
        std::string type;
        int max_number;
    };
    std::vector<max_equipabble> max_eq; // if you want to equip 2 rings default number is 1

    int hp;    //
    int mana;  // stats that change during battle
    int konda; //

    std::vector<attack*> skills; // skills

public:
    void set_alive_status(bool is_alive); // unalive or alive xd
    void update_alive_status(); // if hp is 0 than unalive

    void set_hp(int health_points);           //
    void set_max_hp(int max_health_points);   //
    void set_mana(int mana_points);           // character stats
    void set_max_mana(int max_mana_points);   //
    void set_konda(int konda_points);         //
    void set_max_konda(int max_konda_points); //
    void set_knowledge(int knowledge);        //
    void set_power(int power);                //
    void set_strength(int strength);          //
    void set_agility(int agility);            //

    //int get_eq_stat()
    int get_hp();        //
    int get_max_hp();    //
    int get_mana();      // getting character stats
    int get_max_mana();  //
    int get_konda();     //
    int get_max_konda(); //
    int get_knowledge(); //
    int get_power();     //
    int get_strength();  //
    int get_agility();   //

    void set_equipabble_limit(std::string type, int number); // if you don't set anything the assumed value is 1
    void set_equipabble_limit_test();

    void add_armour(armour &piece); // adds armour
    void add_armour_test();

    void remove_armour(armour &piece); // hmm idk

    //void hit(character& enemy, std::string attack_name);

    bool is_alive();

};
