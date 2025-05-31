#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

// 현재 행에 다른 퀸이 있는지
bool isSameRow(int placedRow, int currentRow)
{
	return placedRow == currentRow;
}

// 대각선에 다른 퀸이 있는지
bool isDiagonal(int placedCol, int placedRow, int currentCol, int currentRow)
{
	// 대각선에 있으면 가로 길이 차이 = 세로 길이 차이
	return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

// 퀸을 안전하게 배치할 수 있는지
bool isSafePosition(const vector<int>& queen, int col, int row)
{
	for (int i = 0; i < col; ++i)
	{
		// 같은 행이나 대각선에 퀸이 이미 있으면 false
		if (isSameRow(queen[i], row) || isDiagonal(i, queen[i], col, row))
		{
			return false;
		}
	}

	return true;
}

long long placeQueens(vector<int>& queen, int col)
{
	if (col == N)
		return 1;

	long long count = 0;

	for (int row = 0; row < N; ++row)
	{
		// 퀸을 놓을 수 있는 위치면 퀸을 배치
		if (isSafePosition(queen, col, row))
		{
			queen[col] = row;
			count += placeQueens(queen, col + 1);
			queen[col] = -1;
		}
	}

	return count;
}

int main()
{
	cin >> N;

	// queen[n] : n행 queen[n]열에 퀸이 있음
	vector<int> queen(N, -1);

	cout << placeQueens(queen, 0);

	return 0;
}