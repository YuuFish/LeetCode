#include <iostream>
#include <vector>

#include "util.h"

using namespace std;

void print_1d_vector(const vector<int>& vec)
{
	for(const auto& item : vec)
	{
		cout << item << " ";
	}
	cout << endl;
}
