#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, answer = 0;
vector<vector<int>> tree;

vector<int> visited;

void dfs(vector<int> cur, const vector<int>& info)
{
	int sheepCount = 0;
	int wolfCount = 0;

	// 현재 경로를 기준으로 양/늑대 카운트
	for (int c : cur)
	{
		if (info[c] == 1) wolfCount++;
		else sheepCount++;
	}

	if (sheepCount <= wolfCount) return;

	// 최대 양의 수 갱신
	answer = max(answer, sheepCount);

	for (int i = 0; i < cur.size(); i++)
	{
		int node = cur[i];
		// 현재 노드와 인접한 노드 순회
		for (const auto& neighbor : tree[node])
		{
			// 방문한 노드는 건너뜀
			if (visited[neighbor]) continue;

			// 방문 체크, 경로에 노드 추가 후 dfs 호출
			visited[neighbor] = true;
			cur.push_back(neighbor);
			dfs(cur, info);
			cur.pop_back();
			visited[neighbor] = false;
		}
	}
}

int solution(vector<int> info, vector<vector<int>> edges)
{
	n = info.size();
	tree.resize(n);
	visited.resize(n, false);

	for (const auto& e : edges)
	{
		tree[e[0]].push_back(e[1]);
	}

	visited[0] = true;
	dfs({ 0 }, info);

	return answer;
}