#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int y, x;
    int count;
};

vector<vector<bool>> visited;

vector<Point> direction = { {1, 0}, {0, 1}, {-1 ,0}, {0, -1} };

bool CanMove(Point now, vector<string>& _maps)
{
    int y = now.y;
    int x = now.x;

    if (y < 0 || y >= _maps.size() || x < 0 || x >= _maps[0].size()
        || _maps[y][x] == 'X' || visited[y][x])
        return false;

    return true;
}

int bfs(const char& _start, const char& _end, vector<string> _maps)
{
    int n = _maps.size();
    int m = _maps[0].size();
    visited.assign(n, vector<bool>(m, false));
    Point startPoint = { -1, -1, -1 };

    // 좌표 찾기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (_maps[i][j] == _start)
            {
                startPoint = { i, j, 0 };
                visited[i][j] = true;
                break;
            }
        }
    }

    // bfs
    queue<Point> q;
    q.push(startPoint);

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        
        if (_maps[now.y][now.x] == _end)
            return now.count;

        for (int i = 0; i < 4; i++)
        {
            Point next = { now.y + direction[i].y, now.x + direction[i].x, now.count};
            if (CanMove(next, _maps))
            {
                q.push({ next.y, next.x, next.count + 1 });
                visited[next.y][next.x] = true;
            }
                
        }
    }

    return -1;
}

int solution(vector<string> maps)
{
    int sToL = bfs('S', 'L', maps);
    if (sToL == -1) return -1;

    int lToE = bfs('L', 'E', maps);

    return lToE == -1 ? -1 : sToL + lToE;
}