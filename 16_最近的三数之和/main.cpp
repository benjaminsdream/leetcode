#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;
using namespace Utils;

class Solution {
public:
    int  threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int best = 1000000000;
        auto update = [&](int cur) {
            if( abs(cur-target) < abs(best-target) ){
                best = cur;
            }
        };
        for(int i=0; i<len; i++) {
            //找到第一个不同的数
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = len-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    return target;
                } 
                update(sum);
                if(sum > target) {
                    int k0=k-1;
                    while(j<k0 && nums[k] == nums[k0]) --k0;
                    k=k0;
                } else {
                    int j0 = j+1;
                    while(j0<k && nums[j] == nums[j0]) ++j;
                    j = j0;
                }
            }
        }
        return best;
    }
};

int main(){
    int nums[] = {0,0,0};
    vector<int> case1( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 1;

    int output = Solution().threeSumClosest(case1, target);
    cout << "输出是："<< output << endl;
    cout<<"done"<<endl;
    return 0;
}