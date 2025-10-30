#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <tuple>

using namespace std;

pair<int, int> toDir(const char& c)
{
    switch (c)
    {
    case 'U': return { 1, 0 };
    case 'D': return { -1, 0 };
    case 'R': return { 0, 1 };
    case 'L': return { 0, -1 };
    }

    return { 0, 0 };
}

int solution(string dirs) 
{
    int answer = 0;
    int y = 5, x = 5;

    // 방문한 "간선"을 저장 (무방향: (a->b)와 (b->a) 동일)
    set<array<int, 4>> edges;

    for (char c : dirs) 
    {
        auto [dy, dx] = toDir(c);
        int ny = y + dy;
        int nx = x + dx;

        // 경계 체크
        if (ny < 0 || ny > 10 || nx < 0 || nx > 10)
            continue;

        // 간선 정규화(무방향)
        int ay = y, ax = x, by = ny, bx = nx;

        if (tie(ay, ax) > tie(by, bx)) 
            swap(ay, by), swap(ax, bx);

        array<int, 4> e = { ay, ax, by, bx };
        if (edges.insert(e).second)
            answer++;

        // 실제 이동
        y = ny; x = nx;
    }

    return answer;
}