#include <vector>
#include <algorithm>
using namespace std;

class MaxPairSum 
{
	public:
	int pairSum(vector<int> A, int target) 
	{
		// Code here
		sort(A.begin(), A.end());
		
		int answer = -1;
		for(int i = 0, j = A.size() - 1; i < j;)
		{
			while(A[i] + A[j] >= target)
			{
				j--;
			}
			
			if(A[i] + A[j] < target && i < j)
			{
				answer = max(answer, A[i] + A[j]);
				
				i++;
			}
		}
		
		return answer;
	}
};
