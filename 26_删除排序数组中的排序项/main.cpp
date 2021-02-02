#include<iostream>
#include<vector>
#include "utils.h"
using namespace std;
using namespace Utils;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i!=0 && nums[i] != nums[i-1]) {
                nums[ans++] = nums[i-1];
            }
        }
        nums[ans++] = nums[nums.size()-1];//最后一个元素入队
        return ans;
    }
};
int main() {
    // vector<int> nums = {1, 1, 2};
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    // vector<int> nums = {};
    int k = Solution().removeDuplicates(nums);
    for(int i=0; i<k; i++) {
        cout << nums[i] << " " ;
    }
    cout << endl;
    return 0;
}