#include<iostream>
#include<vector>
#include "utils.h"
using namespace std;
using namespace Utils;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ans = haystack.find(needle);
        return ans;
    }
};
int main() {
    string haystack = "hello";
    string needle = "ll1";
    int k = Solution().strStr(haystack, needle);
    cout<< "k:" << k<<endl;
    return 0;
}