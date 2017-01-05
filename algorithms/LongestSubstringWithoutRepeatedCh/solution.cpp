/*
dp 
dict来保存上一次出现重复字符的位置，用来确定出现重复字符时，需要计算的起始位置
start保存了计算的初始位置
*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

using namespace std;

int lengthOfLongestSubstring(string s) {
	        
	vector<int> dict(256,-1);
	int max_len=0,start=-1;
	for(size_t i=0;i<s.size();i++)
	{
		start=max(start,dict[s[i]]+1);
		dict[s[i]]=i;
		max_len=max(max_len,int(i-start+1));
		cout<<i<<" "<<s[i]<<" "<<start<< " "<<max_len<<endl;
	}
	return max_len;

}
int main(int argc,char** argv)
{
	freopen(argv[1],"r",stdin);
	string s;
	while(getline(cin,s))
	{
		string result;
		int len = lengthOfLongestSubstring(s);
		cout<<s<<"  --> "<<len<<endl;
	}
	return 0;
}
