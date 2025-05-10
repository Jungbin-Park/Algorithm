#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(const vector<int>& arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        // 배열 원소 중 하나라도 나누어 떨어지지 않으면
        if (num % arr[i] != 0)
        {
            return false;
        }
    }

    // 통과되면 true 반환
    return true;
}

int solution(vector<int> arr)
{
    int answer = 0;
    int max = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= max) max = arr[i];
    }


    int i = 1;
    while (true)
    {
        answer = max * i;

        if (isValid(arr, answer)) return answer;

        i++;
    }
}