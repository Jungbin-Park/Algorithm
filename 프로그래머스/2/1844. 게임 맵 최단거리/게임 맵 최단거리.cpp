#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int y, x;
	int count;
};

int n, m;

// 상하좌우
vector<vector<int>> direction = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

queue<Point> q;

bool CanMove(int y, int x, const vector<vector<int>>& maps, const vector<vector<bool>>& visited)
{
	// 맵의 범위를 초과하지 않고 벽이 아니고 방문하지 않은 타일이면 통과
	if (y >= 0 && y < n && x >= 0 && x < m &&
		maps[y][x] != 0 && !visited[y][x])
		return true;

	return false;
}


int bfs(int y, int x, const vector<vector<int>>& maps)
{
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	visited[y][x] = true;
	
	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		if (now.y == n-1 && now.x == m-1)
		{
			return now.count;
		}

		// 상하좌우 체크
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + direction[i][0];
			int nx = now.x + direction[i][1];

			// 갈 수 있는 타일이면 큐에 추가, 방문 체크
			if (CanMove(ny, nx, maps, visited))
			{
				q.push({ ny, nx, now.count + 1 });
				visited[ny][nx] = true;
			}
		}
	}

	return -1;
}

int solution(vector<vector<int>> maps)
{
	int result = 0;

	n = maps.size();
	m = maps[0].size();

	// 플레이어 (0, 0), 상대 (n, m)
	q.push({ 0, 0, 1 });
	result = bfs(0, 0, maps);


	return result;
}