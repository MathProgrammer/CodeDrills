#include <vector>
#include <iostream>
#include <map>

using namespace std;
class CountPairsWithXOR {
public:
	const int NO_OF_BITS = 31;
	map <string, int> prefix_frequency;
	
	int is_bit_set(int n, int bit)
	{
		return ( ( n & (1 << bit) ) != 0);
	}
	
	void insert(int x)
	{
		string prefix;
		
		for(int bit = NO_OF_BITS; bit >= 0; bit--)
		{
			prefix += (is_bit_set(x, bit) ? "1" : "0");
			
			prefix_frequency[prefix]++;
		}
	}
	
	int count_less_than(int N, int x)
	{
		int count = 0;
		
		string prefix; 
		
		for(int bit = NO_OF_BITS; bit >= 0; bit--)
		{
			string current_prefix = prefix; 
			
			if(is_bit_set(N, bit))
			{
				current_prefix += (is_bit_set(x, bit) ? "1" : "0"); 
				
				count += prefix_frequency[current_prefix];
			}
			
			prefix += (is_bit_set(N, bit) == is_bit_set(x, bit) ? "0" : "1");
		}
		
		return count;
	}
	
	int getCountOfPairs(vector<int> A, int L, int R) 
	{	
		int pairs = 0;
		for(int i = 0; i < A.size(); i++)
		{
			pairs += count_less_than(R + 1, A[i]) - count_less_than(L, A[i]);
			
			insert(A[i]);
		}
		
		return pairs;
	}
};
