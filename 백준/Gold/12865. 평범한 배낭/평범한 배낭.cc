#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 4, 7
	int N, K;
	cin >> N >> K;

	// dp[w] = 무게가 w일 때의 최대 가치
	vector<int> dp(K + 1, 0);

	for (int i = 0; i < N; i++)
	{
		int weight, value;
		cin >> weight >> value;

		for (int w = K; w >= weight; --w)
		{
			dp[w] = max(dp[w], dp[w - weight] + value);
		}
	}

	cout << dp[K] << endl;

	return 0;

}