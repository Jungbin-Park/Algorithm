#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int nodeCount = 0;

void dfs(int node)
{
    nodeCount++;

    for (const auto& neighbor : tree[node])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            dfs(neighbor);
            visited[neighbor] = false;
        }
    }

    return;
}

int solution(int n, vector<vector<int>> wires) 
{
    tree.resize(n + 1);
    visited.resize(n + 1);

    int answer = 100;

    for (int i = 0; i < wires.size(); i++)
    {
        int node = wires[i][0];
        int neighbor = wires[i][1];
        tree[node].push_back(neighbor);
        tree[neighbor].push_back(node);
    }

    for (const auto& wire : wires)
    {
        int node1 = wire[0];
        int node2 = wire[1];

        // 연결 삭제
        tree[node1].erase(remove(tree[node1].begin(), tree[node1].end(), node2));
        tree[node2].erase(remove(tree[node2].begin(), tree[node2].end(), node1));

        // 노드 개수 세기
        nodeCount = 0;
        visited[1] = true;
        dfs(1);
        visited[1] = false;

        int diff = n - nodeCount;

        if (diff > nodeCount) diff -= nodeCount;
        else diff = nodeCount - diff;

        answer = min(answer, diff);

        // 연결 복구
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }


    return answer;
}