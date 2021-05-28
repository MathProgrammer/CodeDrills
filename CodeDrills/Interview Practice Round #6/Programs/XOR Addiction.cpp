#include<vector>

using namespace std;

class XorAddiction {
public:
	vector<int> xorAddictionQueries(vector<int> A, vector<vector<int>> queries) {
		// Code here
		
		vector <int> prefix_xor(A.size(), 0);
		prefix_xor[0] = A[0];
		for(int i = 1; i < A.size(); i++)
		{
			prefix_xor[i] = prefix_xor[i - 1]^A[i];
		}
		
		vector <int> answer(queries.size());
		for(int i = 0; i < queries.size(); i++)
		{
			int L = queries[i][0] - 1, R = queries[i][1] - 1;
			
			answer[i] = (L == 0 ? prefix_xor[R] : prefix_xor[R]^prefix_xor[L - 1]);
		}
		
		return answer;
	}
};
