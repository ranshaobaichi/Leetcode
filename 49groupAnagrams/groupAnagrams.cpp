#include<vector>
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void quickSort(string& arr) {
        if (arr.empty()) return;
        quickSort(arr, 0, arr.size() - 1);
    }

    void quickSort(string& arr, int left, int right) {
        if (left >= right) return; // 递归退出条件应为 left >= right
        if (left + 1 == right)
        {
            if (arr[left] > arr[right])
                std::swap(arr[left], arr[right]);
            return;
        }

        // 左、中、右选取中值作为枢纽元
        int mid = (left + right) / 2;
        if (arr[left] > arr[mid]) std::swap(arr[left], arr[mid]);
        if (arr[left] > arr[right]) std::swap(arr[left], arr[right]);
        if (arr[mid] > arr[right]) std::swap(arr[mid], arr[right]);

        // 中值放到倒数第二个位置，最大值留在末尾
        std::swap(arr[mid], arr[right - 1]);
        char pivot = arr[right - 1];

        // 分区操作
        int i = left, j = right - 1;
        while (true) {
            while (arr[++i] < pivot);
            while (pivot < arr[--j]);

            if (i < j) {
                std::swap(arr[i], arr[j]);
            } else {
                break;
            }
        }

        // 将枢纽元放到正确位置
        std::swap(arr[i], arr[right - 1]);

        // 递归对左右区间排序
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for (string s : strs)
        {
            string ori = s;
            quickSort(s);
            ans[s].push_back(ori);
        }
        vector<vector<string>> re;
        for (pair<string, vector<string>> t : ans)
            re.push_back(t.second);
        return re;
    }
};

int main(){
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution pp;
    vector<vector<string>> ans = pp.groupAnagrams(str);
    for (vector<string> a : ans)
    {
        for (string b : a)
            cout << b << ' ';
        cout << endl;
    }
    return 0;
}