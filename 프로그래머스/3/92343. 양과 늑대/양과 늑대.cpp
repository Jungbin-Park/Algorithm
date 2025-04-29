#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;

int answer = 0;

void dfs(const vector<int>& info, vector<int> cur)
{
    int sheep = 0, wolf = 0;

    for (int c : cur)
    {
        if(info[c] == 1) wolf++;
        else sheep++;
    }

    if (wolf >= sheep) return;

    answer = max(answer, sheep);

    for (int i = 0; i < cur.size(); i++)
    {
        int curNode = cur[i];

        for (const auto& neighbor : tree[curNode])
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
    tree.resize(info.size());
    visited.resize(info.size());

    for (const auto& e : edges)
    {
        tree[e[0]].push_back(e[1]);
    }

    visited[0] = true;
    dfs(info, { 0 });

    return answer;
}