#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
// 
// std::merge(nums1.rbegin() + n, nums1.rend(), nums2.rbegin(), nums2.rend(), nums1.rbegin(), 
//       [](int a, int b){ return a > b; });

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto out = nums1.rbegin();
        auto in1 = out + n;
        auto in2 = nums2.rbegin();
        while(in1 != nums1.rend() && in2 != nums2.rend())
        {
            if(*in1 < *in2)
            {
                *out = *in2;
                ++in2;
            }
            else{
                *out = *in1;
                ++in1;
            }
            ++out;
        }
        for(; in2 != nums2.rend(); ++in2)
        {
            *out = *in2;
            ++out;
        }
    }
};

int main()
{
    {
        // Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        // Output: [1,2,2,3,5,6]
        Solution s;
        vector<int> v1 = {1, 2, 3, 0, 0, 0};
        vector<int> v2 = {2, 5, 6};
        const vector<int> res = {1, 2, 2, 3, 5, 6};
        const int m = 3;
        const int n = 3;
        s.merge(v1, m, v2, n);
        std::cout << ((v1 == res) ? "OK" : "FAIL") << endl;
    }
    {
        // Input: nums1 = [1], m = 1, nums2 = [], n = 0
        // Output: [1]
        Solution s;
        vector<int> v1 = {1};
        const int m = 1;
        vector<int> v2 = {};
        const int n = 0;
        const vector<int> res = {1};
        s.merge(v1, m, v2, n);
        std::cout << ((v1 == res) ? "OK" : "FAIL") << endl;
    }
    {
        // Input: nums1 = [0], m = 0, nums2 = [1], n = 1
        // Output: [1]
        Solution s;
        vector<int> v1 = {0};
        const int m = 0;
        vector<int> v2 = {1};
        const int n = 1;
        const vector<int> res = {1};
        s.merge(v1, m, v2, n);
        std::cout << ((v1 == res) ? "OK" : "FAIL") << endl;
    }
}