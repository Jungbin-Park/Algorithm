#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations)
{
    // 이중우선순위큐 multiset 이용 
    std::multiset<int> dq;

    for (const auto& op : operations)
    {
        // 삽입
        if (op[0] == 'I')
        {
            int num = stoi(op.substr(2));
            dq.insert(num);
        }
        // 삭제
        else
        {
            if (!dq.empty())
            {
                // multiset의 최솟값 : begin(), 최댓값 : rbegin()
                int num = stoi(op.substr(2));

                // 최댓값 삭제
                if (num > 0)
                    dq.erase(*dq.rbegin());
                // 최솟값 삭제
                else
                    dq.erase(*dq.begin());
            }
        }
    }

    // 큐가 비어있으면 [0, 0] 반환
    if (dq.empty())
        return { 0, 0 };
    // [최댓값, 최솟값] 반환
    else
    {
        int maxNum = *dq.rbegin();
        int minNum = *dq.begin();
        return { maxNum, minNum };
    }
}