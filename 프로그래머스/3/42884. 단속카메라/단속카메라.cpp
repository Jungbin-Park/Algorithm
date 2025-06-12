#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) 
{
    int answer = 1;
    
    // 진출 시점 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), Compare);

    int out = routes[0][1];

    for (const auto& route : routes)
    {
        if (out >= route[0] && out <= route[1]) continue;
        else
        {
            out = route[1];
            answer++;
        }
    }

    return answer;
}