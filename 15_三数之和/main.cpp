#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;
using namespace Utils;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >  results ;
        sort(nums.begin(), nums.end());
        // 排序
        // 依次遍历
        // 转换成twoSum的问题：nums, l, r, target, origin
        int len = nums.size();
        for(int i=0; i<nums.size(); i++) {
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int value = nums[i]; // 一直找到当前数和前面的不一样的那个为止
            int target = -nums[i];
            auto result = twoSum(nums, i+1, len-1, target, value);
            results.insert(results.end(), result.begin(), result.end());
        }
        return results;
    }
    vector< vector<int> > twoSum(vector<int>& nums, int l, int r, 
                                 int target, int value){
        vector<vector<int> >  results;
        //双指针法求解twoSum
        // 不同的是 这个可能有多个解
        while(l<r) {
            int sum = nums[l] + nums[r];
            if( sum  == target){
                vector<int> oneResult ;
                oneResult.push_back(value);
                oneResult.push_back(nums[l]);
                oneResult.push_back(nums[r]);
                results.push_back(oneResult);
                // 还可能有多组解, 继续搜索
                while(l<r && nums[l] == nums[l+1]) l++; l++;
                while(l<r && nums[r] == nums[r-1]) r--; r--;

            } else if ( sum < target ) {
                l++;
            } else {
                r--; 
            }
        }
        return results;
    }
};

void DisplayVecs(vector<vector<int> > inputs){
    for(auto item : inputs) {
        DisplayVec(item);
    }
    cout << endl << endl;
}
int main(){
    vector< vector<int> > cases;
    int case1[] = {-1,0,1,2,-1,-4};
    int case2[] = {};
    int case3[] = {0};
    int case4[] = {0, 0, 0, 0};
    cases.push_back(vector<int>(case1, case1+sizeof(case1)/sizeof(int)));
    cases.push_back(vector<int>(case2, case2+sizeof(case2)/sizeof(int)));
    cases.push_back(vector<int>(case3, case3+sizeof(case3)/sizeof(int)));
    cases.push_back(vector<int>(case4, case4+sizeof(case4)/sizeof(int)));

    for(size_t i=0; i< cases.size(); i++){
        vector<int> nums = cases[i];
        vector<vector<int> > output = Solution().threeSum(nums);
        cout << "输入是：";
        DisplayVec(nums);
        cout << "输出是："<<endl;
        DisplayVecs(output);
        
    }
    cout<<"done"<<endl;
    return 0;
}