#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) 
{
    // dp[i] : 금액 i를 만드는 방법의 수
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int coin : money)
    {
        for (int i = coin; i <= n; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[n];
}