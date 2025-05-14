#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;

int n = 0, answer = 0;

void dfs(const vector<int>& info, vector<int> cur)
{
    int sheep = 0, wolf = 0;

    // 현재 경로에서 카운팅
    for (int c : cur)
    {
        if (info[c] == 1) wolf++;
        else sheep++;
    }

    // 늑대가 같거나 많으면 리턴
    if (sheep <= wolf) return;

    answer = max(answer, sheep);

    for (int i = 0; i < cur.size(); i++)
    {
        int node = cur[i];

        for (int neighbor : tree[node])
        {
            if (visited[neighbor]) continue;

            visited[neighbor] = true;
            cur.push_back(neighbor);
            dfs(info, cur);
            cur.pop_back();
            visited[neighbor] = false;
        }
    }
    
}

int solution(vector<int> info, vector<vector<int>> edges) 
{
    n = info.size();

    tree.resize(n);
    visited.resize(n);

    for (int i = 0; i < edges.size(); i++)
    {
        int node = edges[i][0];
        int neighbor = edges[i][1];

        tree[node].push_back(neighbor);
    }

    visited[0] = true;
    dfs(info, { 0 });

    return answer;
}