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

string intToRoman(int num) {
    int romanInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result;
    int len = sizeof(romanInt) / sizeof(int);
    for(int i=0; i<len; i++){
        while(num >= romanInt[i]){
            result += romans[i];
            num -= romanInt[i];
        }
        
    }
    return result;
}
int main() {
    int case1[] = {3, 4, 9, 58, 1994};
    vector< int > inputs( case1, case1+sizeof(case1)/sizeof(int) );

    for(auto item: inputs){
        string result = intToRoman(item);
        cout<< "input: "<< item << " result: " << result <<endl;
    }
    return 0;
}