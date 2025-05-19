// 274. H-Index
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            vector<int> h(1001, 0);
            for(auto i : citations)
                h[i]++;
            for (int i = 1000; i > 0; i--)
            {
                if (h[i] >= i)
                    return i;
                h[i - 1] += h[i];
            }
            return 0;
        }
    };

int main()
{
    vector<int> a = {1,3,1};
    Solution p;
    cout << p.hIndex(a);
    return 0;
}