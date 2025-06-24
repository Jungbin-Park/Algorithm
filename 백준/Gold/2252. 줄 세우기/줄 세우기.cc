#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1);
	vector<int> degree(N + 1, 0);
	queue<int> q;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		degree[B]++;
	}

	// 차수가 0인 학생먼저 큐에 삽입
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int now = q.front();
		cout << now << " ";
		q.pop();

		// 현재 학생보다 뒤에 있는 학생들의 차수를 감소시킴
		int cnt = graph[now].size();

		for (int i = 0; i < cnt; i++)
		{
			int neighbor = graph[now][i];
			degree[neighbor]--;

			// 차수가 0이 되면 큐에 삽입
			if (degree[neighbor] == 0)
				q.push(neighbor);
		}
	}
}