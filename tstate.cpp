#include <iostream>
#include "tstate.h"

using namespace std; 
tstate::tstate(int max_nst)
{
	max_num_state = max_nst;
	states = new state[max_num_state];
	num_state = 0;
	cout << "\nThe constructor of the tstate class is called:";
	cout << "\n selected objects - " << max_num_state;
	cout << "\n loaded state - " << num_state << endl;
}

tstate::~tstate()
{
	max_num_state = 0;
	delete[] states;
	num_state = 0;
	cout << "\nThe destructor of the tstate class is called:";
	cout << "\n allocated memory is freed";
}

void tstate::operator+=(const state& astate)
{
	if (num_state < max_num_state)
	{
		states[num_state] = astate;
		num_state++;
	}
}

void tstate::operator-=(const state& astate)
{
	if (num_state < 0)
		return;
	int index = -1;
	for (int i = 0; i < num_state; i++)
		if (states[i] == astate)
			index = i;
	if (index == -1)
		return;
	if (index != num_state - 1)
		states[index] = states[num_state - 1];
	num_state--;

}

ostream& operator<<(ostream& stream, const tstate& cstate)
{
	stream << "\n THE WHOLE RANGE OF THE STATE:\n";
	for (int i = 0; i < cstate.num_state; i++)
	{
		stream << "=========== state " << i + 1 << " ============== \n";
		stream << cstate.states[i] << endl;
	}
	return stream;
}

void tstate::read_from_file(string filename)
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
	{
		cout << "\n\nFile not found!" << endl;
		system("pause");
		exit(1);
	}
	int N;
	infile >> N;
	infile.get();
	for (int i = 0; i < N; i++)
	{
		state new_state;
		infile >> new_state;
		this -> operator+= (new_state);
		
	}
	infile.close();
	cout << "\nLoaded data from file " << filename << ":";
	cout << "\n number of loaded state - " << num_state<<endl;
}

void tstate::write_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	outfile << num_state << endl;
	for (int i = 0; i < num_state; i++)
		outfile << states[i];
	outfile.close();
	cout << "\nData written to file " << filename << ":";
	cout << "\n number of written state - " << num_state;
}


void tstate::Sum(string acontinent)
{
	cout << "\n+Enter the continent : " << acontinent;
	float sumarea = 0;
	int sumpop = 0;
	for (int i = 0; i < num_state; i++)
	{
		if (states[i].get_continent() == acontinent)
		{
			sumarea += states[i].get_area();
			sumpop += states[i].get_population();
		}
	}
	cout << "\nSum area : " << sumarea << endl;
	cout << "Sum population : " << sumpop << endl;

}

void tstate::find(string lang)
{
	int max = states[0].get_population();
	int j = 0;
	for (int i = 1; i <= num_state; i++)
	{
		if (states[i].get_lang() == lang)
		{
			if (max < states[i].get_population())
			{
				max = states[i].get_population();
				j = i;
			}
		}
	}
	cout << "\nName and capital of the largest state in terms of population :" << endl;
	cout << "Country : " << states[j].get_country() << endl;
	cout << "Capital : " << states[j].get_capital() << endl;
}