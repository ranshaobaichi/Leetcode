#include <vector>
#include <iostream>
using namespace std;

/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/
class Solution {
    public:
        int candy(vector<int>& ratings) {
            if (ratings.size() == 1)
                return 1;
            vector<int> left(ratings.size(), 1), right(ratings.size(), 1);
            for (int i = 1; i < ratings.size(); i++)
                if (ratings[i] > ratings[i - 1])
                    left[i] = left[i - 1] + 1;
            for (int i = ratings.size() - 2; i >= 0; i--)
                if (ratings[i] > ratings[i + 1])
                    right[i] = right[i + 1] + 1;
            int ans = 0;
            for (int i = 0; i < ratings.size(); i++)
                ans += max(left[i], right[i]);
            return ans;
        }
    };

int main()
{
    Solution p;
    vector<int> vec = {1, 0, 2};
    cout << p.candy(vec);
    return 0;
}

    