#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
class MissingNumbers {
public:
	vector<int> getMissingNumbers(vector<int> array) 
	{
		for(int i = 0; i < array.size(); i++)
		{
			if(array[abs(array[i]) - 1] > 0)
			{
				array[abs(array[i]) - 1] *= -1; 
			}
		}
		
		vector <int> missing; 
		for(int i = 0; i < array.size(); i++)
		{
			if(array[i] > 0)
				missing.push_back(i + 1);
		}
		
		return missing;
	}
};
