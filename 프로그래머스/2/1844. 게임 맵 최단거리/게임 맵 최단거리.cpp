#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct Point
{
	int y, x;
	int count;
};

vector<Point> direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<vector<bool>> visited;

bool CanMove(Point _point, const vector<vector<int>>& _maps)
{
	int y = _point.y;
	int x = _point.x;

	if(y < 0 || y >= n || x < 0 || x >= m || _maps[y][x] == 0 || visited[y][x])
		return false;

	return true;
}

int bfs(Point _start, const vector<vector<int>>& _maps)
{
	queue<Point> q;
	q.push(_start);

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		if (now.y == (n - 1) && now.x == (m - 1))
			return now.count;

		for (int i = 0; i < 4; i++)
		{
			Point next = { now.y + direction[i].y, now.x + direction[i].x, now.count };

			if (CanMove(next, _maps))
			{
				q.push({next.y, next.x, next.count + 1});
				visited[next.y][next.x] = true;
			}
		}

	}

	return -1;
}

int solution(vector<vector<int>> maps)
{
	n = maps.size();
	m = maps[0].size();

	visited.assign(n, vector<bool>(m, false));
	Point start = { 0, 0, 1 };

	
	visited[0][0] = true;
	int result = bfs(start, maps);

	return result;
}