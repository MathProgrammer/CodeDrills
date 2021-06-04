#include<string>
#include<vector>

using namespace std;

class CommonCharacters 
{
public:
	vector<string> getCommonCharacters(vector<string> A) 
	{
		const int NO_OF_ALPHABETS = 26, oo = 1e6; 
		vector <int> minimum_frequency(NO_OF_ALPHABETS, oo);
		for(int i = 0; i < A.size(); i++)
		{
			for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
			{
				int frequency = 0;
				
				for(int j = 0; j < A[i].size(); j++)
				{
					frequency += (A[i][j] == alpha + 'a');
				}
				
				minimum_frequency[alpha] = min(minimum_frequency[alpha], frequency);
			}
		}
		
		vector <string> answer; 
		for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
		{
			for(int i = 0; i < minimum_frequency[alpha]; i++)
			{
				string here;
				
				here += (char)('a' + alpha);
				
				answer.push_back(here);
			}
		}
		
		return answer;
	}
};
