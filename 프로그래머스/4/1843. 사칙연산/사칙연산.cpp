#include <iostream>
#include <vector>
#include <string>
#include <limits>

int max_val = std::numeric_limits<int>::max();
int min_val = std::numeric_limits<int>::min();

using namespace std;

int solution(vector<string> arr)
{
    int n = (arr.size() + 1) / 2; // 숫자 개수

    vector<int> nums;
    vector<char> ops;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0) nums.push_back(stoi(arr[i]));
        else ops.push_back(arr[i][0]);
    }

    // dp 테이블
    vector<vector<int>> dp_max(n, vector<int>(n, min_val));
    vector<vector<int>> dp_min(n, vector<int>(n, max_val));

    // 한 숫자만 있을 때는 그대로
    for (int i = 0; i < n; ++i) 
    {
        dp_max[i][i] = nums[i];
        dp_min[i][i] = nums[i];
    }

    // 길이 2 이상부터 계산
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            for (int k = i; k < j; k++)
            {
                char op = ops[k];
                int a = dp_max[i][k];
                int b = dp_min[i][k];
                int c = dp_max[k + 1][j];
                int d = dp_min[k + 1][j];

                // 덧셈은 큰 수 끼리, 뺄셈은 큰 수 - 작은 수 => 최댓값
                if (op == '+') 
                {
                    dp_max[i][j] = max(dp_max[i][j], a + c);
                    dp_min[i][j] = min(dp_min[i][j], b + d);
                }
                else 
                {
                    dp_max[i][j] = max(dp_max[i][j], a - d);
                    dp_min[i][j] = min(dp_min[i][j], b - c);
                }
            }
        }
    }

    return dp_max[0][n - 1];
}