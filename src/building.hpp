#ifndef BUILDING_HEADER
#define BUILDING_HEADER
#include <iostream>

enum Building
{
    InvalidBuildingType,
    House,
    School,
    Church
};

//todo use optional
Building string_to_building(const std::string &name);
#endif