#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int y, x;
    int score;

    bool operator==(const Point& other) const
    {
        return y == other.y && x == other.x;
    }

    Point operator+(const Point& other) const
    {
        return Point(y + other.y, x + other.x);
    }

    Point(int _y, int _x, int _score = 0)
        : y(_y)
        , x(_x)
        , score(_score) 
    {}
};

bool IsValid(const Point& _point, const int& _height, const int& _width)
{
    return (_point.y >= 0 && _point.y < _height && _point.x >= 0 && _point.x < _width);
}

vector<Point> direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int height, width;

int bfs(char _start, char _end, vector<string>& maps)
{
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<Point> q;

    Point start(0, 0), end(0, 0);

    // 시작 - 끝 지점 좌표로 변환
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (maps[i][j] == _start) start = { i, j };
            if (maps[i][j] == _end) end = { i, j };
        }
    }

    q.push(start);

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();

        if (now == end)
        {
            return now.score;
        }

        // 상하좌우 갈 수 있는 타일 체크
        for (int i = 0; i < 4; i++)
        {
            Point next = now + direction[i];

            // 벽이 아니고 방문한 적 없는 타일이면
            if (IsValid(next, height, width) && maps[next.y][next.x] != 'X' && !visited[next.y][next.x])
            {
                // 큐에 삽입 + 방문 체크
                next.score += now.score + 1;
                q.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }

    return 0;
}


int solution(vector<string> maps)
{
    int answer = 0;

    height = maps.size();
    width = maps[0].length();

    int distanceSToL = bfs('S', 'L', maps);

    int distanceLToE = bfs('L', 'E', maps);

    if (distanceSToL == 0 || distanceLToE == 0) return -1;

    return distanceSToL + distanceLToE;
}