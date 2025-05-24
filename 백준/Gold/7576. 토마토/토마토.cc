#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> box;
int days[1000][1000];
queue<pair<int, int>> q;

vector<pair<int, int>> dir = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

bool IsValid(int x, int y)
{
	if (x >= 0 && x < box[0].size() && y >= 0 && y < box.size())
	{
		return true;
	}

	return false;
}

void bfs()
{
	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = now.first + dir[i].first;
			int y = now.second + dir[i].second;

			// 범위 안에 있고 익지 않았으면 익은 토마토로
			if (IsValid(x, y) && box[y][x] == 0)
			{
				box[y][x] = 1;
				q.push(make_pair(x, y));
				days[y][x] = days[now.second][now.first] + 1;
			}
		}
	}


}

int main()
{
	int m, n;
	cin >> m >> n;

	box.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t;
			cin >> t;
			box[i].push_back(t);

			// 처음부터 익어있는 토마토 큐에 삽입
			if (t == 1) q.push(make_pair(j, i));
		}
	}

	bfs();

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			result = max(result, days[i][j]);
		}
	}
	
	cout << result;

	return 0;
}
