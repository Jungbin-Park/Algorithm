#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> meetings[i].first >> meetings[i].second;
    }

    // 끝나는 시간 기준 오름차순 정렬
    sort(meetings.begin(), meetings.end()
        , [](pair<int, int>& a, pair<int, int>& b){ 
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });

    int count = 0, last_end_time = 0;

    for (const auto& meeting : meetings) 
    {
        if (meeting.first >= last_end_time) 
        {
            last_end_time = meeting.second;
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}