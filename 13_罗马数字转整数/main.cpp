#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>
#include<map>

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
map<string, int> GetMap() {
    map<string, int> romans2Int;
    romans2Int["M"] =  1000;
    romans2Int["CM"] =  900;
    romans2Int["D"] =  500;
    romans2Int["CD"] =  400;

    romans2Int["C"] =  100;
    romans2Int["XC"] =  90;
    romans2Int["L"] =  50;
    romans2Int["XL"] =  40;

    romans2Int["X"] =  10;
    romans2Int["IX"] =  9;
    romans2Int["V"] =  5;
    romans2Int["IV"] =  4;

    romans2Int["I"] =  1;

    return romans2Int;
}
int romanToInt(string roman) {
    int romanInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    map<string, int> romans2Int = GetMap();

    int result=0;
    int len = roman.size();
    for(int i =0 ;i <len; i++){
        if(i== len-1){
            result += romans2Int[string(1, roman[i])];
            break;
        }
        char ch = roman[i];
        char chPost = roman[i+1];
        string key = string(1, ch) + string(1, chPost);
        // printf("key:%s, result:%d, ch:%c, chPost:%c\n", 
            // key.c_str(), result, ch, chPost);
        if( ch=='I' && (chPost =='V' || chPost =='X') ) {
            result += romans2Int[key];
            i++;
            continue;
        }
        if( ch=='X' && (chPost =='L' || chPost =='C') )  {
            result += romans2Int[key];
            i++;
            continue;
        }
        if( ch=='C' && (chPost =='D' || chPost =='M') ) {
            result += romans2Int[key];
            i++;
            continue;
        }
        result += romans2Int[string(1, ch)];
    }
    return result;
}
int main() {
    string case1[] = {"LVIII", "MCMXCIV", "III", "IV", "IX"};
    vector< string > inputs( case1, case1+5 );

    for(auto item: inputs){
        int result = romanToInt(item);
        cout<< "input: "<< item << " result: " << result <<endl;
    }
    return 0;
}