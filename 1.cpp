#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>result;
        int i = 0, j = 0;
        int flag = 0;
        for (int k = 0; k < mat.size()* mat[0].size(); k++)
        {
        
            if (flag == 0)
            {
                 result.push_back( mat[i][j]);
                 cout << mat[i][j] << " ";
                 i--;
                 j++;
            }
            else if (flag == 1)
            {
                result.push_back(mat[i][j]);
                cout << mat[i][j] << " ";
                i++;
                j--;
            }
            if (j == mat[0].size())
            {
                flag = 1;
                i += 2;
                j--;
            }
            else if (i < 0)
            {
                flag = 1;
                i++;
            }
            if (i == mat.size())
            {
                flag = 0;
                j += 2;
                i--;
            }
            else if (j < 0)
            {
                 flag = 0;
                 j++;               
            }
            
        }
        return result;
    }
};

int main()
{
    vector<vector<int>>arr{ {1, 2, 3},{ 4, 5, 6},{ 7, 8, 9} };
    Solution s;
    s.findDiagonalOrder(arr);
	return 0;
}