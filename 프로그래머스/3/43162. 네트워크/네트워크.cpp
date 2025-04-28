#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 모든 컴퓨터가 간접적으로 연결되어 있으면 하나의 네트워크
// dfs 로 방문체크 하면서 순환 -> dfs 횟수 = 네트워크 개수

bool visited[200];
int answer = 0;

void dfs(const vector<vector<int>>& computers, int startNode)
{
    if (visited[startNode]) return;

    visited[startNode] = true;

    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[startNode][i])
        {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) 
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(computers, i);
            answer++;
        }
    }

    return answer;
}