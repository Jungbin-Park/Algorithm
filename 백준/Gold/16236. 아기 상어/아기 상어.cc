#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> space;
vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool canMove(int y, int x, int sharkSize)
{
	// 박스 범위 내에 있고 물고기의 크기가 상어 크기와 같거나 작은지
	if (y >= 0 && y < space.size() && x >= 0 && x < space.size() &&
		space[y][x] <= sharkSize)
	{
		return true;
	}

	return false;
}

struct Compare
{
	bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
	{
		// 거리 우선
		if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
		// y 우선
		if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
		// x 우선
		return get<2>(a) > get<2>(b);
	}
};

int Bfs(pair<int, int>& sharkPos, int& sharkSize)
{
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Compare> pq;
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	pq.push({ 0, sharkPos.first, sharkPos.second });
	visited[sharkPos.first][sharkPos.second] = true;

	while (!pq.empty())
	{
		auto [dist, y, x] = pq.top();
		pq.pop();

		// 먹을 수 있는 물고기이면 '거리(=시간)' 리턴
		if (space[y][x] > 0 && space[y][x] < sharkSize)
		{
			space[y][x] = 0;
			sharkPos = { y, x };
			return dist;
		}

		// 상하좌우 체크 후 방문
		for (const auto& dir : dirs)
		{
			int ny = y + dir.first;
			int nx = x + dir.second;

			if (canMove(ny, nx, sharkSize) && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				pq.push({ dist + 1, ny, nx });
			}
		}
	}

	return 0;
}

int main()
{
	cin >> n;

	space.resize(n, vector<int>(n));
	
	pair<int, int> sharkPos;
	int eatenFish = 0;
	int sharkSize = 2;
	int totalTime = 0;

	// 공간 생성
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];

			if (space[i][j] == 9)
			{
				// 상어 위치 기록 후 0으로 초기화
				sharkPos = { i, j };
				space[i][j] = 0;
			}
		}
	}

	while (true)
	{
		int time = Bfs(sharkPos, sharkSize);
		if (time == 0) break;

		totalTime += time;
		eatenFish++;

		if (eatenFish == sharkSize)
		{
			sharkSize++;
			eatenFish = 0;
		}
	}
	
	cout << totalTime << endl;

	return 0;
}