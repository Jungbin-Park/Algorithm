#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> Stats;
int minValue = 100;
bool selected[20];

int Diff()
{
	int diff;
	int S = 0, L = 0;

	// selected 에서 true 면 스타트 팀, false 면 링크 팀
	for (int i = 0; i < Stats.size(); i++)
	{
		for (int j = 0; j < Stats.size(); j++)
		{
			if (i == j) continue;

			if (selected[i])
			{
				if (selected[j]) S += Stats[i][j];
			}
			else
			{
				if (!selected[j]) L += Stats[i][j];
			}
		}
		
	}

	diff = S - L;

	if (diff > 0) return diff;
	else return -diff;
}

void Backtrack(int idx, int count)
{
	// 절반 인원으로 팀이 구성되면 두 팀의 차이값 계산
	if (count == Stats.size() / 2)
	{
		// 차이값 계산
		int diff = Diff();
		minValue = min(minValue, diff);
		return;
	}

	for (int i = idx; i < Stats.size(); i++)
	{
		selected[i] = true;
		Backtrack(i + 1, count + 1);
		selected[i] = false;
	}
}

int main()
{
	int N, S;

	cin >> N;
	Stats.resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S;
			Stats[i].push_back(S);
		}
	}
	
	Backtrack(0, 0);

	cout << minValue;

	return 0;
}