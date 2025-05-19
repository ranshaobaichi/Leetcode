/*380
实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。
*/


/*381
RandomizedCollection 是一种包含数字集合(可能是重复的)的数据结构。它应该支持插入和删除特定元素，以及删除随机元素。

实现 RandomizedCollection 类:

RandomizedCollection()初始化空的 RandomizedCollection 对象。
bool insert(int val) 将一个 val 项插入到集合中，即使该项已经存在。如果该项不存在，则返回 true ，否则返回 false 。
bool remove(int val) 如果存在，从集合中移除一个 val 项。如果该项存在，则返回 true ，否则返回 false 。注意，如果 val 在集合中出现多次，我们只删除其中一个。
int getRandom() 从当前的多个元素集合中返回一个随机元素。每个元素被返回的概率与集合中包含的相同值的数量 线性相关 。
您必须实现类的函数，使每个函数的 平均 时间复杂度为 O(1) 。

注意：生成测试用例时，只有在 RandomizedCollection 中 至少有一项 时，才会调用 getRandom 。
*/
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class RandomizedSet {
private:
    struct num
    {
        int count;
        int val;
        num(int v) : val(v), count(1) { }
    };
    vector<num> nums;
    unordered_map<int, int> map;
    vector<int> unused_index;

public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (map.count(val))
        {
            nums[map[val]].count++;
            return false;
        }
        if (unused_index.empty())
        {
            nums.emplace_back(num(val));
            map.emplace(val, nums.size() - 1);
        }
        else
        {
            int index = unused_index.back();
            unused_index.pop_back();
            nums[index] = num(val);
            map.emplace(val, index);
        }
        return true;
    }
    
    bool remove(int val) {
        if (!map.count(val) || nums[map[val]].val != val)
            return false;
        nums[map[val]].count--;
        if (nums[map[val]].count <= 0)
        {
            unused_index.push_back(map[val]);
            map.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int rand_index = rand() % nums.size();
        while (find(unused_index.begin(), unused_index.end(), rand_index) != unused_index.end())
            rand_index = rand() % nums.size();
        return nums[rand_index].val;
    }
};
    
/*
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
*/

int main()
{
    cout << "hello world";
    return 0;
}