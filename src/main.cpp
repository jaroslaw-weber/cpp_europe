#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <map>
#include "building.hpp"
#include "constants.hpp"
#include "country.hpp"

using std::cin;
using std::cout;
using std::getline;
using std::map;
using std::string;
using std::vector;

using boost::is_any_of;
using boost::starts_with;

vector<string> split_to_words(const string s)
{
  vector<string> words;

  split(words, s, is_any_of(" "));
  return words;
}

string get_last_word(const string s)
{
  auto index = s.find_last_of(' ');
  string last_word = s.substr(++index);
  return last_word;
}
bool is_number(const string &s)
{
  string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it))
    ++it;
  return !s.empty() && it == s.end();
}

//todo innovations & research
//todo more buildings

//end of turn
void cmd_next_turn(Country &country)
{
  cout << "next turn!" << c_newline;
  country.on_turn_end();
}

//skipping multiple turns
void cmd_skip_turns(Country &country, const string &input)
{

  auto turns_string = get_last_word(input);
  if (is_number(turns_string))
  {
    auto turns = std::stoi(turns_string);
    for (int i = 0; i < turns; ++i)
    {
      country.on_turn_end();
    }
    cout << "skipped " << turns << " turns!" << c_newline;
  }
  else
  {
    cout << "command invalid! example command: skip turns 5" << c_newline;
  }
}

//building houses, schools, etc
void cmd_build(Country &country, const string &input)
{

  auto words = split_to_words(input);
  bool valid_command = words.size() == 3;
  if (!valid_command)
  {
    cout << "invalid command! 'build' command needs two parameters" << c_newline;
    return;
  }
  auto second = words[1];
  auto third = words[2];
  auto building_type = string_to_building(second);
  valid_command = is_number(third) && building_type != Building::InvalidBuildingType;

  if (!valid_command)
  {
    cout << "invalid command! building type: " << building_type << c_newline;
    return;
  }

  auto count = std::stoi(third);
  country.build(building_type, count);
}

int main()
{

  //create new country
  Country country;

  cout << "Hello you! This is a command line strategy game in c++" << c_newline << c_newline;
  cout << "Build some houses to increase max population!" << c_newline << c_newline;
  //todo add tutorial?
  string input;
  while (true)
  {
    getline(cin, input);

    //closure: check if input begins with "command_name"
    auto cmd_check = [input](string command_name) { return starts_with(input, command_name); };

    //cout << "you typed:" << input << c_newline;
    if (cmd_check("next turn"))
    {
      ::cmd_next_turn(country);
    }
    else if (cmd_check("skip turns"))
    {
      ::cmd_skip_turns(country, input);
    }
    else if (cmd_check("build"))
    {
      ::cmd_build(country, input);
    }
    else if (cmd_check("info"))
    {
      country.show_info();
    }
    else if (cmd_check("help"))
    {
      cout << "available commands: info, help, build 'building_name' 'count', next turn, skip turns 'count'" << c_newline;
    }
    else if (cmd_check("research"))
    {
      auto research_name = input.substr(input.find(" ") + 1);
      auto research_type = string_to_research(research_name);
      if(research_type == Research::InvalidResearchType)
      {
          cout << "invalid research type" << c_newline;
          continue;
      }
      country.research(research_type);
    }
    else
    {
      cout << "unknown command. type 'help' command to get more info." << c_newline;
    }
    cout << c_newline;
  }
}