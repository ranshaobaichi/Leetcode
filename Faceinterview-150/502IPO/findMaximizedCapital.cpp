/*
502. IPO
困难
相关标签
相关企业
假设 力扣（LeetCode）即将开始 IPO 。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。 
由于资源有限，它只能在 IPO 之前完成最多 k 个不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。

给你 n 个项目。对于每个项目 i ，它都有一个纯利润 profits[i] ，和启动该项目需要的最小资本 capital[i] 。
最初，你的资本为 w 。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。
总而言之，从给定项目中选择 最多 k 个不同项目的列表，以 最大化最终资本 ，并输出最终可获得的最多资本。
答案保证在 32 位有符号整数范围内。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
            int n = profits.size();
            int curr = 0;
            priority_queue<int, vector<int>, less<int>> pq;
            vector<pair<int, int>> arr;
    
            for (int i = 0; i < n; ++i) {
                arr.push_back({capital[i], profits[i]});
            }
            sort(arr.begin(), arr.end());
            for (int i = 0; i < k; ++i) {
                while (curr < n && arr[curr].first <= w) {
                    pq.push(arr[curr].second);
                    curr++;
                }
                if (!pq.empty()) {
                    w += pq.top();
                    pq.pop();
                } else {
                    break;
                }
            }
    
            return w;
        }
    };

int main()
{
    Solution p;
    vector<int> prefits = {1,2,3};
    vector<int> capital = {1,1,2};
    cout << p.findMaximizedCapital(1, 0, prefits, capital);
    return 0;
}