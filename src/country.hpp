#ifndef COUNTRY_HEADER
#define COUNTRY_HEADER

#include <map>           //dictionary, hash
#include <unordered_set> //hashset
#include <iostream>
#include "building.hpp"
#include "research.hpp"

using std::map;
using std::string;
using std::unordered_set;

class Country
{
public:
  //constructor
  Country();

  //update money, population, etc
  void on_turn_end();

  int get_max_population();

  void build(Building building_type, int count);

  void research(Research research_type);

  void show_info();

private:
  int _research_points;
  int _money = 100;
  int _population = 0;
  map<Building, int> _buildings;
  unordered_set<Research> _research;
  int get_building_cost(const Building building_type);
  bool has_research(const Research research_type);
};
#endif