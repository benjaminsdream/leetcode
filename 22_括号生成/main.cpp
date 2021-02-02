#include<iostream>
#include<vector>
#include "utils.h"
using namespace std;
class Solution {
public:
    //1 暴力法
    // vector<string> generateParenthesis(int n) {
    //     if(n==1) {
    //         return vector<string>{"()"};
    //     }
    //     vector<string> ans;
    //     string s;
    //     g(s, 2*n, ans);
    //     return ans;
    // }
    // void g(string& s, int n, vector<string>& ans){
    //     cout << "s:" << s<<endl;
    //     if(s.size() == n) {
    //         if(isMatch(s)){
    //             ans.push_back(s);
    //         }
    //         return;
    //     }
    //     s =  s + "(";
    //     g(s, n, ans);
    //     s.pop_back();
    //     s =  s + ")";
    //     g(s, n, ans);
    //     s.pop_back();
    //     return;
    // }
    // bool isMatch(string s) {
    //     int balance = 0;
    //     for(auto ch : s){
    //         if(ch == '(') balance++;
    //         if(ch == ')') balance--;
    //         if(balance < 0 ) return false;
    //     }
        
    //     return balance == 0;
    // }
    // // 2 暴力+剪枝（卡特兰数）
    // vector<string> generateParenthesis(int n) {
    //     if(n==1) {
    //         return vector<string>{"()"};
    //     }
    //     vector<string> ans;
    //     string s;
    //     int open = 0;
    //     int close = 0;
    //     g(s, open, close, ans, n);
    //     return ans;
    // }
    // void g(string& s, int open, int close, vector<string>& ans, int n) {
    //     if(s.size() == n*2){
    //         if(isMatch(s)) ans.push_back(s);
    //     }
    //     if(open<n) { // 还能继续放 （
    //         s += "(";
    //         g(s, open+1, close, ans, n);
    //         s.pop_back();
    //     }
    //     if(close < open) { // 还能继续放 ); 相等不能继续放 ） 但是可以放 (
    //         s += ")";
    //         g(s, open, close+1, ans, n);
    //         s.pop_back(); 
    //     }
    // }
    // 3 按括号序列的长度递归
    
    vector<string> generateParenthesis(int n) {
        return *g(n);
    }
    shared_ptr<vector<string>> c[100] = {nullptr};
    shared_ptr<vector<string>> g(int n){
        if(c[n] != nullptr) {
            return c[n];
        }
        if( n == 0 ){
            return shared_ptr<vector<string>>( new vector<string>{""});
        } else {
            auto ans = shared_ptr<vector<string>>(new vector<string>);
            for(int i=0; i<n; i++){
                auto l=g(i);
                auto r=g(n-i-1);
                for(auto k : *l) {
                    for( auto j : *r) {
                        ans->push_back("(" + k + ")" + j);
                    }
                }
            }
            c[n] = ans;
        }
        
        return c[n];
    }
};
int main() {
    auto result = Solution().generateParenthesis(3);
    Utils::DisplayVec(result);
    return 0;
}
