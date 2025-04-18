#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<int>> adjList;
unordered_set<int> visited;

void dfs(int node)
{
	visited.insert(node);

	for (const int& neighbor : adjList[node])
	{
		if (visited.find(neighbor) == visited.end())
		{
			dfs(neighbor);
		}
	}
}

int solution(int _computerCount, int _pairCount)
{
	dfs(1);

	return visited.size() - 1;
}

int main()
{
	int computerCount, pairCount;
	
	cin >> computerCount >> pairCount;

	for (int i = 0; i < pairCount; i++)
	{
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	cout << solution(computerCount, pairCount);

	return 0;
}