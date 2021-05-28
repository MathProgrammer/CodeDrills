#include <string>
#include <stack>
#include <vector>

using namespace std;
class LongestValidParentheses {
public:
	int getLongestValidParentheses(string S) {
		// Code here
		
		vector <int> ending_index(S.size(), -1);
		stack <int> index;
		for(int i = 0; i < S.size(); i++)
		{
			switch(S[i])
			{
				case '(': index.push(i); break;
				case ')': if(!index.empty())
						    {
								ending_index[index.top()] = i;
								index.pop();
							}
			}
		}
		
		int answer = 0;
		vector <int> length(S.size(), 0);
		for(int i = S.size() - 1; i >= 0; i--)
		{
			if(S[i] == '(' && ending_index[i] != -1)
			{
				length[i] = ending_index[i]  - i + 1;
				
				int next = ending_index[i] + 1;
				
				if(next < S.size() && S[next] == '(')
				{
					length[i] += length[next];
				}
			}
			
			answer = max(answer, length[i]);
		}
		
		return answer;
	}
};
