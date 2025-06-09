#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
	int y, x;
	int dist;
	bool broken;
};

int N, M;
vector<vector<int>> map;
vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool CanMove(int y, int x) {
	return (y >= 0 && y < N && x >= 0 && x < M);
}

int Bfs() {
	vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
	queue<Node> q;

	q.push({0, 0, 1, false});
	visited[0][0][0] = true;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.y == N - 1 && now.x == M - 1)
			return now.dist;

		for (const auto& dir : directions) {
			int y = now.y + dir[0];
			int x = now.x + dir[1];

			if (!CanMove(y, x)) continue;

			// 벽이 아닌 경우
			if (map[y][x] == 0 && !visited[y][x][now.broken]) {
				visited[y][x][now.broken] = true;
				q.push({ y, x, now.dist + 1, now.broken });
			}
			// 벽인데 아직 부수지 않았을 경우
			else if (map[y][x] == 1 && !now.broken && !visited[y][x][1]) {
				visited[y][x][1] = true;
				q.push({ y, x, now.dist + 1, true });
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;
	map.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
		}
	}

	cout << Bfs();

	return 0;
}