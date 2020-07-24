class Solution {
public:
    // 滑动窗口思路
    // 右指针不断向右 直到找到满足条件的位置  并判断是否最小子数组
    // 左指针不断右移 直到不满条件为止
    // minLen  最小长度
    // curLen 当前长度
    // l r 左右指针
    // curSum 当前和
    int minSubArrayLen(int s, vector<int>& nums) {
        int curSum = 0;
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int curLen = 0;
        while(r<nums.size()) {
            curSum += nums[r++];
            if(curSum<s){//不满足条件 继续右移
                curLen ++;
                continue; 
            }
            curLen ++;
            while(curSum>=s && l<r ) {//直到找到不满足条件的
                minLen = curLen < minLen ? curLen : minLen;
                curSum -= nums[l++]; // 当前和-1
                curLen--; //当前长度-1
                if(curSum>=s){//右移之后剩余和还是满足条件
                    continue;
                }
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
