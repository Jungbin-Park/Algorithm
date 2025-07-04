#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;	// 보석 수, 가방 수
	cin >> N >> K;

	vector<pair<int, int>> jewels(N);	// 보석 {무게, 가격}
	vector<int> carryWeight(K);	// 각 가방에 담을 수 있는 무게

	for (int i = 0; i < N; i++)
	{
		cin >> jewels[i].first >> jewels[i].second;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> carryWeight[i];
	}

	// 무게 순 정렬
	sort(jewels.begin(), jewels.end());
	sort(carryWeight.begin(), carryWeight.end());

	// 우선 순위 큐
	priority_queue<int> pq;

	long long answer = 0;
	int j = 0;

	// 가방 순회
	for (int i = 0; i < K; ++i)
	{
		// 담을 수 있는 모든 보석 우선순위 큐에 삽입
		while (j < N && jewels[j].first <= carryWeight[i])
		{
			pq.push(jewels[j].second);
			++j;
		}

		// 가장 비싼 가격 누적
		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;

	return 0;;
}