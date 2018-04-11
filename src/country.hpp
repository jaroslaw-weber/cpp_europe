#ifndef COUNTRY_HEADER
#define COUNTRY_HEADER

#include <map>
#include "building.hpp"

using std::map;

class Country
{
public:
  //constructor
  Country();

  //update money, population, etc
  void on_turn_end();

  int get_max_population();

  void build(Building building_type, int count);

  void show_info();

private:
  int _money = 100;
  int _population = 0;
  map<Building, int> _buildings;
};
#endif