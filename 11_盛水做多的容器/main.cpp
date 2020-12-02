#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;
int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() -1 ;
    int result = INT_MIN;
    while(l<r){
        int curArea = (r-l) * min(height[r], height[l]);
        result = max(result, curArea);  
        // cout << "result: " << result << " curArea:" << curArea << " l:" << l << " r:"<< r<<endl;
        if(height[r] > height[l]) {
            l++;
        } else {
            r--;
        }
    }

    return result;
}
int main() {
    vector< vector<int> > inputs;
    inputs.push_back( vector<int>(5, 1));
    int case1[] = {1,8,6,2,5,4,8,3,7};
    inputs.push_back( vector<int>(case1, case1+sizeof(case1)/sizeof(int)));

    int case2[] = {1,1};
    inputs.push_back( vector<int>(case2, case2+sizeof(case2)/sizeof(int)));

    int case3[] = {4,3,2,1,4};
    inputs.push_back( vector<int>(case3, case3+sizeof(case3)/sizeof(int)));

    int case4[] = {1,2,1};
    inputs.push_back( vector<int>(case4, case4+sizeof(case4)/sizeof(int)));

    for(auto item: inputs){
        int area = maxArea(item);
        cout<< "area: " << area <<endl;
    }
    return 0;
}