#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<bool> visited;
int answer = 0;

void dfs(int _node, int _end, int _dist, const vector<vector<int>>& tree)
{
	if (_node == _end)
	{
		answer += _dist;
		return;
	}

	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[_node][i] && !visited[i])
		{
			visited[i] = true;
			dfs(i, _end, tree[_node][i] + _dist, tree);
			visited[i] = false;
		}
	}

	return;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> tree(N, vector<int>(N));
	visited.resize(N);

	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2, dist;
		cin >> node1 >> node2 >> dist;
		tree[node1 - 1][node2 - 1] = dist;
		tree[node2 - 1][node1 - 1] = dist;
	}

	for (int i = 0; i < M; i++)
	{
		answer = 0;

		// 거리를 구하고 싶은 노드 입력
		int num1, num2;
		cin >> num1 >> num2;

		visited[num1 - 1] = true;
		dfs(num1 - 1, num2 - 1, 0, tree);
		visited[num1 - 1] = false;

		cout << answer << endl;
	}

	return 0;
}