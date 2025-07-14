#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) 
{
    int n = matrix_sizes.size();
    // dp[i][j] : i번쨰 행렬부터 j번째 행렬까지 곱할 때 드는 최소 연산 횟수
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len < n; ++len)
    {
        for (int i = 0; i + len < n; ++i)
        {
            int j = i + len;
            dp[i][j] = numeric_limits<int>::max();

            for (int k = i; k < j; ++k)
            {
                int cost = dp[i][k] + dp[k + 1][j] 
                    + matrix_sizes[i][0] * matrix_sizes[k][1] * matrix_sizes[j][1];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}