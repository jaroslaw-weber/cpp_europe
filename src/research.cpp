#include "research.hpp"
#include <iostream>
#include "constants.hpp"

int get_research_cost(Research research)
{
    switch (research)
    {
    case Research::CheaperBuildings:
        return 1000;
    case Research::FasterPopulationGrowth:
        return 1500;
    }
    std::cout << "research type not implemented" << c_newline;

    return 999999;
}

Research string_to_research(const string &input)
{
    if (input == "cheaper buildings")
        return Research::CheaperBuildings;
    if (input == "faster population growth")
        return Research::FasterPopulationGrowth;
    std::cout << "research name invalid. try: `cheaper buildings` or `faster population growth` ";
    return Research::InvalidResearchType;
}

//todo create two-way hash
string research_to_string(const Research research_type)
{
    switch (research_type)
    {
    case Research::CheaperBuildings:
        return "cheaper buildings";
    case Research::FasterPopulationGrowth:
        return "faster population growth";
    }
    return "!invalid!";
}