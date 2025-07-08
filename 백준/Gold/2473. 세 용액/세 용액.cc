#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int N;
	cin >> N; // 3 <= N <= 5000

	vector<long long> L(N);

	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
	}
	
	// 오름차순 정렬
	sort(L.begin(), L.end());

	long long closestSum = LLONG_MAX;	// 가장 0에 가까운 합
	long long ans1 = 0, ans2 = 0, ans3 = 0;

	for (int i = 0; i < N - 2; i++)
	{
		int left = i + 1;
		int right = N - 1;

		while (left < right)
		{
			long long sum = L[i] + L[left] + L[right];

			if (abs(sum) < abs(closestSum))
			{
				closestSum = sum;
				ans1 = L[i];
				ans2 = L[left];
				ans3 = L[right];
			}

			// 합이 작으므로 더 큰 값 필요
			if (sum < 0)
				left++;
			// 합이 크므로 더 작은 값 필요
			else if (sum > 0)
				right--;
			// 합이 0이면 바로 정답 출력
			else
			{
				cout << L[i] << " " << L[left] << " " << L[right] << endl;
				return 0;
			}
		}
	}

	// 0이 안나오면 가장 0에 가까운 세 용액 출력
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
	return 0;
}