#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
    // l, r: 左右指针 不必多说
    // mFreq : 有个map来存储当前窗口内的各个字母对应的出现次数
    // max: 存储当前窗口内出现字母的最大次数
    // 从左往右遍历，当当前窗口的宽度 > k+max时，窗口平移 ,因为换k个字母也不能满足无重复了
    // 当上述条件不成立时， 继续r++ 扩张窗口
    int characterReplacement(string s, int k) {
        map<char, int> mFreq;
        int l=0, r=0;
        int m = 0;
        for(r=0; r< s.size(); r++){
            mFreq[s[r]]++;//记录每个字符重复次数
            m=max(m, mFreq[s[r]]);//找到最大重复次数
            int windowLen = r-l+1;
            //cout << "max: " << m << "  ";
            //cout << "windowLen" << windowLen << "  "<<endl;
            
            if(windowLen>k+m){//无法满足不重复了 平移
                mFreq[s[l++]]--;
            }
            ////cout << "l: " << l << "r: "  << r <<endl;
            for(auto it : mFreq) {
                //cout << it.first << " : " << it.second<<endl;
            } 
            //cout << endl;
        }
        return s.size()-l;//最后窗口的宽度就是目标值
    }
};

int main(){
    string s="AABABBA";
    int k = 1;
    Solution solution;
    int result = solution.characterReplacement(s, k);
    cout << "result: " << result <<endl;

}