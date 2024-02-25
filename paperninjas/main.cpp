#include <iostream>
#include <ctime>
#include "character.h"
#include "attack.h"

using namespace std;

int main()
{

    std::default_random_engine generator(time(NULL));

    std::normal_distribution<double> normal05(0, 5);
    //*
    character a;
    a.set_alive_status(true);
    a.set_max_hp(100);
    a.set_hp(100);

    character b;
    b.set_alive_status(true);
    b.set_max_hp(100);
    b.set_hp(100);

    armour helm;
    helm.type = "helmet";
    helm.name = "czepek byka i myszy";

    armour pelka;
    pelka.type = "cape";
    pelka.name = "peleryna burzy";

    a.set_equipabble_limit("helmet", 2);
    a.add_armour(helm);
    a.add_armour(helm);
    a.add_armour(pelka);
    a.add_armour(helm);
    a.add_armour(pelka);

    a.add_armour_test();

    /*
    std::cout << "postac a hp: " << a.get_hp() << "/" << a.get_max_hp() << "\n";
    std::cout << "postac b hp: " << b.get_hp() << "/" << b.get_max_hp() << "\n";

    att.hit(a, b);

    std::cout << "postac a hp: " << a.get_hp() << "/" << a.get_max_hp() << "\n";
    std::cout << "postac b hp: " << b.get_hp() << "/" << b.get_max_hp() << "\n";
    //*/
    //cout << "Hello world!" << endl;
    //*/
    return 0;
}
