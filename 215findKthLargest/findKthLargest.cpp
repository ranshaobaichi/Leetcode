#include<iostream>
#include<vector>

using namespace std;

class MaxHeap
{
friend class Solution;
public:
    MaxHeap(vector<int> &nums);
    void Insert(int x);
    int Remove();
private:
    int size = 0;
    int *heap = nullptr;
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        MaxHeap Heap(nums);
        for (int i = 1; i < k; i++)
            Heap.Remove();
        return Heap.Remove();
    }
};

MaxHeap::MaxHeap(vector<int> &nums)
{
    heap = new int[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        Insert(nums[i]);
}

void MaxHeap::Insert(int x){
    int i = size, j = (size - 1) / 2;
    heap[size++] = x;
    while (i > 0)
    {
        if (x > heap[j])
        {
            heap[i] = heap[j];
            i = j;
            j = (j - 1) / 2;
        }
        else
            break;
    }
    heap[i] = x;
}

int MaxHeap::Remove()
{
    int temp = heap[0];
    int com = heap[size - 1];
    heap[0] = heap[size - 1];
    heap[size - 1] = -1;
    int i = 0, j = i * 2 + 1;
    while (j <= size)
    {
        if (j + 1 < size && heap[j + 1] > heap[j])
            j++;
        if (com < heap[j])
        {
            heap[i] = heap[j];
            i = j;
            j = j * 2 + 1;
        }
        else
            break;
    }
    heap[i] = heap[--size];
    return temp;
}

int main(){
    vector<int> a = {1};
    Solution p;
    cout << p.findKthLargest(a, 1);
    return 0;
}