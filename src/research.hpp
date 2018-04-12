#ifndef RESEARCH_HEADER
#define RESEARCH_HEADER
#include <iostream>
using std::string;

enum Research
{
    InvalidResearchType,
    CheaperBuildings,
    FasterPopulationGrowth
};

int get_research_cost(Research research);

Research string_to_research(const string &input);
string research_to_string(const Research research_type);

#endif