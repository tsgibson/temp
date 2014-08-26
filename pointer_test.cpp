#include <iostream>
#include <string>

using namespace std;

void test(char* i_data, char* o_data)
{
	string input(i_data);
	int num_elements = input.length();
	char r[num_elements];
	string* rotations = new string[num_elements];
	for (int i=0; i<num_elements; i++)
	{
		for (int j=0; j<num_elements; j++)
		{
			r[j] = i_data[(i+j) % num_elements];
		}
		string str(r, num_elements);
		rotations[i] = str;
	}

	sort(rotations, rotations + num_elements);

	for (int i=0; i<num_elements; i++)
	{
		o_data[i] = rotations[i].back();
	}
}

int main(void)
{
	char array[10] = {'e','e','c','f','a','g','h','a','b','d'};
//	char array[10] = {'a','b','c','d','e','f','g','h','i','j'};

	char* bwt_array = new char[10];
	test(array, bwt_array);

	cout << "bwt_array: " << bwt_array << endl;

	return 0;
}
