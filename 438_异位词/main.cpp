#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    void printVec(vector<int> vec){
        cout<< "打印结果数组：";
        for(auto item:vec) {
            cout << item << " " ;
        }
        cout <<endl;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int l=0, r=0;
        int maxLen = p.length();
        int curLen =0 ;
        map<char, int> mFreq;
        map<char, int> curFreq;
        for(auto ch : p){
            mFreq[ch]++;
        }
        int count =0;
        for(;r<s.length(); ){
            char ch = s[r];
            r++;
            if(mFreq.find(ch) != mFreq.end()){
                curFreq[ch]++;
                if( curFreq[ch] == mFreq[ch] ){//只出现一次
                    curLen++;
                }
            }
            if(r-l >= p.length()){
                if(curLen == mFreq.size()){
                    result.push_back(l);
                }
                char leftChar = s[l];
                l++;
                if(mFreq.find(leftChar) != mFreq.end()){
                    if(curFreq[leftChar] == mFreq[leftChar]){
                        curLen--;
                    }
                    curFreq[leftChar]--;
                }
                
            }
        }
        return result;
    }
};
int main(){
    Solution solution;
    string s="baa";
    string p = "aa";
    vector<int> result = solution.findAnagrams(s, p);
    for(auto item: result){
        cout << item << " ";
    }
    cout<<endl;
    return 0;
}