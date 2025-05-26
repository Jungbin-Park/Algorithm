#include <string>
#include <vector>
#include <queue>

using namespace std;

bool IsNeighbor(const string& a, const string& b)
{
    // 두 단어를 비교하여 하나만 단어가 다른 경우를 찾음
    int diff = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }

    return true;
}

int solution(string begin, string target, vector<string> words) 
{
    int n = words.size();

    vector<bool> visited(n, false);
    queue<pair<string, int>> q;

    // 현재 단어와 카운트를 큐에 삽입
    q.push({ begin, 0 });
    
    // bfs 순회
    while (!q.empty())
    {
        pair<string, int> now = q.front();

        string currentStr = now.first;
        int count = now.second;

        q.pop();

        if (currentStr == target) return count;

        // 방문하지 않고 단어가 하나만 다른 단어를 큐에 삽입
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i] && IsNeighbor(currentStr, words[i]))
            {
                visited[i] = true;
                q.push({ words[i], count + 1 });
            }
        }
    }

    return 0;
}