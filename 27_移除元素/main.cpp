#include<iostream>
#include<vector>
#include "utils.h"
using namespace std;
using namespace Utils;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != val){
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
};

int main() {
    // vector<int> nums = {1, 1, 2};
    vector<int> nums = {0,1,2,2,3,0,4,2};
    // vector<int> nums = {};
    int k = Solution().removeElement(nums, 2);
    for(int i=0; i<k; i++) {
        cout << nums[i] << " " ;
    }
    cout << endl;
    return 0;
}