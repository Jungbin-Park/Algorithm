#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, int _Index, int _sum, const int& _target)
{
    if (_Index == numbers.size())
    {
        if (_sum == _target) answer++;
        return;
    }
      
    dfs(numbers, _Index + 1, _sum + numbers[_Index], _target);
    dfs(numbers, _Index + 1, _sum - numbers[_Index], _target);
}

int solution(vector<int> numbers, int target) 
{
    dfs(numbers, 0, 0, target);

    return answer;
}