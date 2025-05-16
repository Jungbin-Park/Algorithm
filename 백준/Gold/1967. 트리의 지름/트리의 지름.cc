#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visited;
int maxDist = 0, farNode = 0;

void dfs(int node, int dist)
{
	visited[node] = true;

	if (dist >= maxDist)
	{
		maxDist = dist;
		farNode = node;
	}

	for (const pair<int, int> pair : tree[node])
	{
		int neighbor = pair.first;
		int weight = pair.second;

		if (!visited[neighbor])
		{
			dfs(neighbor, dist + weight);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	tree.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int p, c, w;
		cin >> p >> c >> w;
		tree[p].push_back(make_pair(c, w));
		tree[c].push_back(make_pair(p, w));
	}

	// dfs로 가장 먼 노드 구하기
	dfs(1, 0);

	// 이 노드에서 가장 먼 노드의 거리 구하기
	// visited, maxDist 초기화
	fill(visited.begin(), visited.end(), false);
	maxDist = 0;
	dfs(farNode, 0);

	cout << maxDist << endl;

	return 0;
}