#include "state.h"
#include <iostream>
using namespace std;
state::state(string cou, string cap, string gov, string lag, string rel, string con, float are, int pop)
{
	country = cou;
	capital = cap;
	government = gov;
	language = lag;
	religion = rel;
	continent = con;
	area = are;
	population = pop;
}

string state::get_continent()
{
	return continent;
}
string state::get_lang()
{
	return language;

}
string state::get_country()
{
	return country;
}
string state::get_capital()
{
	return capital;
}
float state::get_area()
{
	return area;
}
int state::get_population()
{
	return population;
}

bool state::operator ==(state another)
{
	if (country != another.country) return false;
	if (capital != another.capital) return false;
	if (government != another.government) return false;
	if (language != another.language) return false;
	if (religion != another.religion) return false;
	if (continent != another.continent) return false;
	if (area != another.area) return false;
	if (population != another.population) return false;
	return true;
}

ostream& operator<<(ostream& stream, const state& astate)
{
	stream << "Country: " << astate.country << endl;
	stream << "Capital: " << astate.capital << endl;
	stream << "Government : " << astate.government << endl;
	stream << "Language : " << astate.language << endl;
	stream << "Religion : " << astate.religion << endl;
	stream << "Continent : " << astate.continent << endl;
	stream << "Area : " << astate.area << endl;
	stream << "Population : " << astate.population << endl;
	return stream;
}

istream& operator>>(istream& stream,state& astate)
{
	getline(stream, astate.country);
	getline(stream, astate.capital);
	getline(stream, astate.government);
	getline(stream, astate.language);
	getline(stream, astate.religion);
	getline(stream, astate.continent);
	stream >> astate.area;
	stream >> astate.population;
	stream.get();
	return stream;
}

ofstream& operator<<(ofstream& stream, const state& astate)
{
	stream << astate.country << endl;
	stream << astate.capital << endl;
	stream << astate.government << endl;
	stream << astate.language << endl;
	stream << astate.religion << endl;
	stream << astate.continent << endl;
	stream << astate.area << endl;
	stream << astate.population << endl;
	return stream;
}

ifstream& operator>>(ifstream& stream, state& astate)
{

	getline(stream, astate.country);
	getline(stream, astate.capital);
	getline(stream, astate.government);
	getline(stream, astate.language);
	getline(stream, astate.religion);
	getline(stream, astate.continent);
	stream >> astate.area;
	stream >> astate.population;
	stream.get();
	return stream;
}