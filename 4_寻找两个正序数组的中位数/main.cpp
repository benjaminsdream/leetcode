#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //1. 确定长度短的数组 去二分查找
        if(nums1.size() > nums2.size()){
            nums1.swap(nums2);
        }
        // for(auto i : nums1){
        //     cout << i  << " ";
        // }
        // cout << endl;
        // for(auto i : nums2){
        //     cout << i << " ";
        // }
        // cout <<endl;
        int left = 0;
        int right = nums1.size();
        int totalLeft = (nums1.size() + nums2.size() + 1)/2;
        //2. 二分查找中位线
        while(left < right) {
            int i = left + (right-left+1)/2;
            int j = totalLeft - i;
            if(nums1[i-1] > nums2[j]){
                right = i-1;
            } else {
                left = i;
            }
            // cout << i << " " << j << " " << left << " " << right << endl;
        }
        int i = left;
        int j = totalLeft - i;
        // cout << "i:" << i << "  j:"<<j<<endl;
        //3. 确定中位线两边的4个值
        int leftMax1 = i==0 ? INT_MIN : nums1[i-1];
        int rightMin1 = i==nums1.size() ? INT_MAX : nums1[i];
        int leftMax2 = j==0? INT_MIN : nums2[j-1];
        int rightMin2 = j=nums2.size() ? INT_MAX : nums2[j];
        //4. 根据奇、偶数来返回result
        if( ( (nums1.size() + nums2.size()) % 2 )  ==  1 ){
            return max(leftMax1, leftMax2);
        } else {
            int x = max(leftMax1, leftMax2);
            int y = min(rightMin1, rightMin2);
            return (double(x)+double(y))/2;
        }
}
int main(){
    vector<int> nums2 = {1, 2};
    vector<int> nums1 = {3,4};
    auto result = findMedianSortedArrays(nums1, nums2);
    cout<< "result:" << result <<endl;
}