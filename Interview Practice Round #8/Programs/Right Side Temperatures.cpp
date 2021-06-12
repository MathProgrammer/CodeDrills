#include<vector>
#include <map>
#include <algorithm>
#include <iostream>

#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
#define all(v) (v).begin(), (v).end()

using namespace std;
class RightSideSmallerTemperatures 
{
	public:
	
	vector <int> sum_tree;
	
	int get_sum(int n, int left, int right, int query_left, int query_right)
	{
		if(query_right < left || right < query_left || query_right < query_left || right < left)
		{
			return 0;
		}
		
		if(query_left <= left && right <= query_right)
		{
			return sum_tree[n];
		}
		
		int mid = (left + right)/2;
		int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
		int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);
		
		return (left_sum + right_sum);
	}
	
	void update(int n, int left, int right, int position, int value)
	{
		if(position < left || right < position || right < left)
		{
			return;
		}
		
		if(left == right)
		{
			sum_tree[n] += value;
			return;
		}
		
		int mid = (left + right)/2;
		update(LEFT(n), left, mid, position, value);
		update(RIGHT(n), mid + 1, right, position, value);
		
		sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
	}
	
	void compress_coordinates(vector <int> &A)
	{
		vector <int> sorted_A(A.size());
		for(int i = 0; i < A.size(); i++)
		{
			sorted_A[i] = A[i];
		}
		
		sort(all(sorted_A));
		
		map <int, int> label;
		label[sorted_A[0]] = 1;
		for(int i = 1; i < sorted_A.size(); i++)
		{
			if(A[i] != A[i - 1])
			{
				label[sorted_A[i]] = label[sorted_A[i - 1]] + 1;
			}
		}
		
		for(int i = 0; i < A.size(); i++)
		{
			A[i] = label[A[i]];
		}  
	}
					  
	vector<int> getSmallerTemperaturesCount(vector<int> A) 
	{
		compress_coordinates(A);
		
		cout << "n = " << A.size() << "\n";
		
		int n = A.size();
		sum_tree.resize(4*n + 1, 0);
		
		vector <int> inversions(n, 0);
		for(int i = n - 1; i >= 0; i--)
		{
			inversions[i] = get_sum(1, 1, n, 1, A[i] - 1);
			
			update(1, 1, n, A[i], 1);
		}
		
		return inversions;
	}
};
