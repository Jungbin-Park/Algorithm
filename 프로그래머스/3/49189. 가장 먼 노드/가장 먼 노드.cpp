#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
queue<int> q;

void bfs(int start)
{
    visited[start] = 1;
    q.push(1);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int neighbor : graph[now])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1 + visited[now];
                q.push(neighbor);
            }
        }
    }

}

int solution(int n, vector<vector<int>> edge) 
{
    int answer = 0;
    graph.resize(n + 1);
    visited.resize(n + 1, 0);

    // 그래프 생성
    for (int i = 0; i < edge.size(); i++)
    {
        int node = edge[i][0];
        int neighbor = edge[i][1];

        graph[node].push_back(neighbor);
        graph[neighbor].push_back(node);
    }

    bfs(1);

    // 최단 경로 = 최댓값
    int maxValue = 0;
    if (!visited.empty())
    {
        maxValue = *max_element(visited.begin(), visited.end());
    }

    // 최단 경로 개수 구하기
    answer = count(visited.begin(), visited.end(), maxValue);

    return answer;
}