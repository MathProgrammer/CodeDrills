#include<vector>

using namespace std; 
class MoneyHeist
{
public:
	int robMaximumMoney(vector<int> A) 
	{
		vector <int> maximum_money(A.size(), 0);
		for(int i = 0; i < A.size(); i++)
		{
			if(i == 0)
			{
				maximum_money[i] = A[i];
				continue;
			}
			else if(i == 1)
			{
				maximum_money[i] = max(maximum_money[i - 1], A[i]);
				continue;
			}
			
			maximum_money[i] = max(maximum_money[i - 1], A[i] + maximum_money[i - 2]);
		}
		
		return (maximum_money.size() == 0 ? -1 : maximum_money.back());
	}
};
