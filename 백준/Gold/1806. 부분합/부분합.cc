#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;

	vector<int> sequence(N);

	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}

	int answer = N + 1;
	int sum = 0, start = 0;

	for (int end = 0; end < N; end++)
	{
		sum += sequence[end];

		// 합이 S 이상이 되면 길이를 answer에 저장하고
		// Sum이 S보다 작아질 때까지 시작 지점을 땡겨온다
		while (sum >= S)
		{
			answer = min(answer, end - start + 1);
			sum -= sequence[start];
			start++;
		}
	}

	if (answer == N + 1)
		cout << 0 << endl;
	else
		cout << answer << endl;

	return 0;
}