#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int>::iterator n1 = nums1.begin(), n2 = nums2.begin(), mid;
        for (int i = 0; i < (len1 + len2) / 2;i++){
            if(n1!=nums1.end()&&n2!=nums2.end())
                mid = *n1 < *n2 ? n1++ : n2++;
            else if(n1==nums1.end())
                mid = n2++;
            else
                mid = n1++;
        }
        
        int minior;
        if(n1!=nums1.end()&&n2!=nums2.end())
            minior = *n1 < *n2 ? *n1 : *n2;
        else if(n1==nums1.end()) minior = *n2;
        else minior = *n1;

        if((len1+len2)%2==1)
            return minior;
        else
            return (double)(*mid + minior) / 2;
    }
};

int main(){
    vector<int> a1 = {1,2}, a2 = {3,4};
    Solution pp;
    cout<<pp.findMedianSortedArrays(a1, a2);
    return 0;
}