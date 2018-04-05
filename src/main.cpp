#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::getline;



class Country
{
public:
  int GetMoney()
  {
    return _money;
  }
  int GetPopulation()
  {
    return _population;
  }
  void OnTurnEnd()
  {
    _money += _population * 2;
    _population += 2 + _population / 10;
  }

private:
  int _money = 0;
  int _population = 0;
};

int main()
{

    auto newline = "\n";

    Country country;//created new country
    auto money = country.GetMoney();
    cout << "Country money: " << money << newline;

    cout << "Hello world!" << newline;
    string input;
    while(true)
    {
        getline(cin, input);
        cout << "you typed:" << input << newline;
    }
}

