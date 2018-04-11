#include <map>
#include <iostream>
#include "country.hpp"
#include "building.hpp"
#include "constants.hpp"

using std::cout;
using std::map;
using std::string;

//constructor
Country::Country()
{
    _buildings = map<Building, int>(); //todo need to release in destructor?
}

//update money, population, etc
void Country::on_turn_end()
{
    _money += _population * 2;
    _population += 2 + _population / 10;
}

int Country::get_max_population()
{
    auto houses = _buildings[Building::House];
    return houses * 10;
}

void Country::build(Building building_type, int count)
{
    auto need = count * c_building_cost;
    if (_money < need)
    {
        cout << "not enough money!" << c_newline;
        return;
    }
    _money -= need;

    auto search = _buildings.find(building_type);
    if (search != _buildings.end())
    {
        auto have_now = _buildings[building_type];
        _buildings[building_type] = have_now + count;
    }
    else
    {
        _buildings[building_type] = count;
    }
}

//show country state
void Country::show_info()
{
    cout << "Your country info:";
    cout << "Money: " << _money << c_newline;
    cout << "Population: " << _population << c_newline;
    cout << "Max population (build more houses to increase): " << get_max_population() << c_newline;
    cout << "Buildings count:" << c_newline;
    cout << "- House: " << _buildings[Building::House] << c_newline;
    cout << "- School: " << _buildings[Building::School] << c_newline;
    cout << "- Church: " << _buildings[Building::Church] << c_newline;
}
