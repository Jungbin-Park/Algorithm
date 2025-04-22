#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void Hanoi(int n, int start, int via, int dest)
{
    // 1인 경우 경로 저장 후 리턴
    if (n == 1)
    {
        answer.push_back({ start + 1, dest + 1 });
        return;
    }

    // 가장 작은 디스크 부터 움직여야 하므로 재귀 호출

    // 이전 디스크를 보조 지점으로
    Hanoi(n - 1, start, dest, via);
    // 현재 디스크를 목적지로
    answer.push_back({ start + 1, dest + 1 });
    // 보조 지점에 있던 이전 디스크를 목적지로 탑을 쌓기
    Hanoi(n - 1, via, start, dest);
}

vector<vector<int>> solution(int n) 
{
    Hanoi(n, 0, 1, 2);

    return answer;
}