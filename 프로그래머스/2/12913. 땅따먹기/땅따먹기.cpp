#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int n = land.size();
    int m = land[0].size();


    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int maxNum = 0;
            for (int k = 0; k < m; k++)
            {
                if (k != j)
                    maxNum = max(maxNum, land[i - 1][k]);
            }

            land[i][j] = land[i][j] + maxNum;
        }
    }

    return *max_element(land[n-1].begin(), land[n-1].end());
}