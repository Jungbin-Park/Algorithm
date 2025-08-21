#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void dfs(int start, const vector<vector<int>>& computers)
{
	visited[start] = true;

	for (int i = 0; i < computers[start].size(); i++)
	{
		if (computers[start][i] && !visited[i])
		{
			dfs(i, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int result = 0;

	visited.resize(n, false);

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i, computers);
			result++;
		}
	}

	return result;
}