#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> rgbCost(n, vector<int>(3));
    vector<vector<int>> curCost(n, vector<int>(3));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> rgbCost[i][j];
        }
    }

    curCost[0][0] = rgbCost[0][0];
    curCost[0][1] = rgbCost[0][1];
    curCost[0][2] = rgbCost[0][2];

    for (int i = 1; i < n; i++)
    {
        curCost[i][0] = rgbCost[i][0] + min(curCost[i - 1][1], curCost[i - 1][2]);
        curCost[i][1] = rgbCost[i][1] + min(curCost[i - 1][0], curCost[i - 1][2]);
        curCost[i][2] = rgbCost[i][2] + min(curCost[i - 1][0], curCost[i - 1][1]);
    }

    cout << min({ curCost[n - 1][0], curCost[n - 1][1], curCost[n - 1][2] });
    

    return 0;
}