#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int y, x, cnt;
};

vector<pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int n, m;

bool CanMove(int y, int x, vector<string>& maps, vector<vector<bool>>& visited)
{
	if (y >= 0 && y < n && x >= 0 && x < m &&
		maps[y][x] != 'X' && !visited[y][x])
		return true;

	return false;
}

int bfs(char start, char end, vector<string>& maps)
{
	queue<Point> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// start 큐에 추가
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == start)
			{
				q.push({ i, j, 0 });
				visited[i][j] = true;
				break;
			}
		}
	}

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		if (maps[now.y][now.x] == end)
		{
			return now.cnt;
		}

		// 상하좌우 체크
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + direction[i].first;
			int nx = now.x + direction[i].second;

			if (CanMove(ny, nx, maps, visited))
			{
				q.push({ ny, nx, now.cnt + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	return -1;
}

int solution(vector<string> maps)
{
	int result = 0;

	n = maps.size();
	m = maps[0].size();

	int distSToL = bfs('S', 'L', maps);
	int distLToE = bfs('L', 'E', maps);

	if (distSToL == -1 || distLToE == -1) return -1;

	result = distSToL + distLToE;

	return result;
}