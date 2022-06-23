#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int projectionArea(vector<vector<int>>& grad)
	{
		int r = 0;
		for (int i = 0; i < grad.size(); i++)
		{
			int maxx = 0;
			int maxy = 0;
			for (int j = 0; j < grad[0].size(); j++)
			{
				if (grad[i][j] != 0)
				{
					r++;
				}
				maxx = max(maxx, grad[i][j]);
				maxy = max(maxy, grad[j][i]);
			}
			r += maxx;
			r += maxy;
		}
		return r;
	}
};
int main()
{
	return 0;
}