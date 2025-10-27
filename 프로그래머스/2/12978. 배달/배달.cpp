#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = numeric_limits<int>::max();

int solution(int N, vector<vector<int>> road, int K)
{
	vector<vector<pair<int, int>>> graph(N + 1);
	vector<int> distances(N + 1, INF);
	vector<bool> visited(N + 1, false);
	distances[1] = 0;

	// 양방향
	for (const auto& r : road)
	{
		int a = r[0], b = r[1], cost = r[2];
		graph[a].push_back({ b, cost });
		graph[b].push_back({ a, cost });
	}

	// 우선순위 큐 (최소 비용, 직전 노드)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
	heap.push({ 0, 1 });

	while (!heap.empty())
	{
		int dist = heap.top().first;
		int node = heap.top().second;
		heap.pop();

		if (visited[node])
			continue;
		visited[node] = true;

		for (const auto& next : graph[node])
		{
			int next_node = next.first;
			int next_dist = next.second;
			int cost = dist + next_dist;

			// 거쳐가는 노드로 가는 경로의 비용이 더 짧으면 최소 비용 갱신
			if (cost < distances[next_node])
			{
				distances[next_node] = cost;
				heap.push({ cost, next_node });
			}
		}
	}

	int count = 0;

	// 거리가 K 이하인 장소 카운트
	for (int i = 0; i <= N; i++)
	{
		if (distances[i] <= K)
			count++;
	}
	
	return count;
}