#include<vector>
#include<queue>
using namespace std;

struct Point
{
    int y, x;
    
    Point operator+(const Point& other) const 
    {
        return Point(y + other.y, x + other.x);
    }

    bool operator==(const Point& other) const
    {
        if (y == other.y && x == other.x)
            return true;
        return false;
    }

    Point(int _y, int _x) 
        : y(_y)
        , x(_x) 
    {}
};

queue<Point> q;
vector<Point> direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    int height = maps.size();
    int width = maps[0].size();

    Point start = { 0, 0 };
    Point end = { height - 1, width - 1 };
    
    q.push(start);

    while (!q.empty())
    {
        // 큐에서 빼냄
        Point point = q.front();

        if (point == end)
        {
            answer = maps[point.y][point.x];
            return answer;
        }
        
        q.pop();

        // 인접한 타일 중, 갈 수 있는 타일 체크
        for (int i = 0; i < direction.size(); i++)
        {
            Point nextPoint = point + direction[i];
            if (nextPoint.y >= 0 && nextPoint.y < height && nextPoint.x >= 0 && nextPoint.x < width)
            {
                // 큐에 삽입, 방문 체크
                if (maps[nextPoint.y][nextPoint.x] == 1)
                {
                    q.push(nextPoint);
                    maps[nextPoint.y][nextPoint.x] += maps[point.y][point.x];
                }
            }
        }
        
    }

    return answer = -1;
}