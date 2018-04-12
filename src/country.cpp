#include <map>
#include <iostream>
#include "country.hpp"
#include "building.hpp"
#include "constants.hpp"
#include "research.hpp"

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
    auto multi = c_population_growth_multiplier;
    auto researched_faster_growth = has_research(Research::FasterPopulationGrowth);
    if (researched_faster_growth)
        multi *= 2; //if researched then growth is twice faster!

    _money += _population * 2;
    _population += (int)((float)2 + (float)_population * multi);

    _research_points += 10 * _buildings[Building::School];
}

int Country::get_max_population()
{
    auto houses = _buildings[Building::House];
    return houses * 10;
}

void Country::build(Building building_type, int count)
{
    auto need = count * get_building_cost(building_type);
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

int Country::get_building_cost(const Building building_type)
{
    if (has_research(Research::CheaperBuildings))
        return c_building_cost / 2;
    return c_building_cost;
}
bool Country::has_research(const Research research_type)
{
    return _research.find(research_type) != _research.end();
}

void Country::research(const Research research_type)
{
    bool already_researched = has_research(research_type);
    if (already_researched)
    {
        cout << "already has researched this!" << c_newline;
        return;
    }

    auto cost = get_research_cost(research_type);
    if (cost > _research_points)
    {
        cout << "not enough research points. you need: " << _research_points << " to research this!" << c_newline;
        return;
    }
    _research_points -= cost;

    _research.insert(research_type);
    cout << "researched: " << research_to_string(research_type);
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
    cout << "Research points::" << _research_points << c_newline;
    cout << "Researched: " << c_newline;
    for (const Research r : _research)
    {
        cout << "- " << research_to_string(r) << c_newline;
    }
}
