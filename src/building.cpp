#include "building.hpp"
#include <iostream>
#include "constants.hpp"


//todo use optional
Building string_to_building(const std::string &name)
{
  if (name == "house")
    return Building::House;
  if (name == "school")
    return Building::School;
  if (name == "church")
    return Building::Church;
  std::cout << "invalid building name! : " << name << c_newline;
  return Building::InvalidBuildingType;
}