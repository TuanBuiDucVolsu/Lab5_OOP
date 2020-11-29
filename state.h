#ifndef STATE_H
#define STATE_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class state
{
private:
    string country;
    string capital;
    string government;
    string language;
    string religion;
    string continent;
    float area;
    int population;
public:
    state() : country(""), capital(""), government(""), language(""), religion(""), continent(""), area(0), population(0) {};
    state(string, string, string, string, string, string, float, int);
    string get_continent();
    string get_lang();
    string get_country();
    string get_capital();
    float get_area();
    int get_population();
    bool operator ==(state another);
    friend ostream& operator<<(ostream& stream, const state& astate);
    friend istream& operator>>(istream& stream, state& astate);
    friend ofstream& operator<<(ofstream& stream, const state& astate);
    friend ifstream& operator>>(ifstream& stream, state& astate);

};

#endif
