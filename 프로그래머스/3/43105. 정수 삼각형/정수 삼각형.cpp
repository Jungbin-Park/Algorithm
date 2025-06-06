#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));


    // dp 테이블 맨 아랫쪽 초기화
    for (int i = 0; i < n; ++i)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    // 아래부터 올라가면서 dp 테이블 채우기
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            dp[i][j] = triangle[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];
}