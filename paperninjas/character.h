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
    std::string texture_file_path;

    bool alive;

    int x;
    int y;
    int width;
    int height;

    stats stat;

    std::vector<armour> eq;
    struct max_equipabble
    {
        std::string type;
        int max_number;
    };
    std::vector<max_equipabble> max_eq; // if you want to equip 2 rings default number is 1

    int hp;
    int mana;
    int konda;

    std::vector<attack*> skills;

public:
    void set_alive_status(bool is_alive);
    void update_alive_status();

    void set_hp(int health_points);
    void set_max_hp(int max_health_points);
    void set_mana(int mana_points);
    void set_max_mana(int max_mana_points);
    void set_konda(int konda_points);
    void set_max_konda(int max_konda_points);

    int get_hp();
    int get_max_hp();
    int get_mana();
    int get_max_mana();
    int get_konda();
    int get_max_konda();

    void set_equipabble_limit(std::string type, int number);
    void set_equipabble_limit_test();
    void add_armour(armour &piece);
    void add_armour_test();
    void remove_armour(armour &piece);

    //void hit(character& enemy, std::string attack_name);

    bool is_alive();

};
