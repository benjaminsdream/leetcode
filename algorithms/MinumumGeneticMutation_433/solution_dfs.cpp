#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<string>

using namespace std;


int minMutation(string start, string end, vector<string>& bank) {

	queue<string>q;
	q.push(start);
	set<string>visited;
	visited.insert(start);
	

	
	int level=0;
	while(!q.empty())
	{
		int size=q.size();
		while(size--)
		{
			string sCurr=q.front();
			q.pop();
			if(sCurr == end)
				return level;
			for(size_t i=0;i<sCurr.size();i++)
			{
				char old=sCurr[i];
				string sACGT="ACGT";
				for(size_t j=0;j<sACGT.size();j++)
				{
					sCurr[i]=sACGT[j];
					if((visited.find(sCurr)==visited.end())  && (find(bank.begin(),bank.end(),sCurr) != bank.end()))
					{
						q.push(sCurr);
						visited.insert(sCurr);
					}
				}
				sCurr[i]=old;
			}
		}
		level++;
	}
	
	return -1;
	
}


int main(int argc,char** argv)
{

        freopen(argv[1],"r",stdin);
        string start,end;
        vector<string>bank;

        cin>>start;
        cin>>end;
        string tmp;
        while(cin>>tmp)
        {
                bank.push_back(tmp);
        }
        cout<<start<<end<<endl;
        for(auto it=bank.begin();it!=bank.end();it++)
                cout<<*it<<endl;


        cout<<"Hello,runrun"<<endl;
        int step = minMutation(start,end,bank);
        cout<<step<<endl;
        return 0;
}
