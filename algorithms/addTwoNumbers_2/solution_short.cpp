/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	
	ListNode* L3 = new ListNode(0);
	ListNode* l3=L3;
	bool jinwei=0;
	while(jinwei || l1 || l2)
	{
		int sum = jinwei + (l1?l1->val:0) + (l2?l2->val:0);
//		cout<<"sum:"<<sum<<"jinwei:"<<jinwei<<" "<<endl;
		ListNode* temp= new ListNode(sum%10);
		jinwei=sum/10;
		l3->next=temp;
		l3=temp;
		l1=l1?l1->next:NULL;
		l2=l2?l2->next:NULL;
	}

	return L3->next;
}



//
//	if(l1 ==NULL)
//		return l2;
//	if(l2 == NULL)
//		return l1;
//
//	ListNode* L3 = new ListNode(0);
//	ListNode* currNode= L3;
//	ListNode* prev=currNode;
//	bool jinwei = 0;
//	while((l1 || l2))
//	{
//		int num1(0),num2(0),sum(0);
//		if(l1)
//			num1=l1->val;
//		if(l2)
//			num2=l2->val;
//		sum = (num1+num2+jinwei)%10;
//		currNode->val=sum;
//		if((num1+num2+jinwei)/10)
//			jinwei = true;
//		else
//			jinwei=false;
////		cout<<"num1:"<<num1<<", num2:"<<num2<<"jinwei:"<<jinwei<<"sum:"<<sum<<endl;
//		ListNode* temp = new ListNode(0);
//		prev=currNode;
//		currNode->next=temp;
//		currNode=temp;
//		if(l1)
//			l1=l1->next;
//		if(l2)
//			l2=l2->next;
//	}
//	
//	if(jinwei)
//	{
//		currNode->val=1;
//	}
//	else
//	{
//		prev->next=NULL;
//		free(currNode);
//	}
//	return L3;
//}
//
int main(int argc,char**argv)
{
	freopen(argv[1],"r",stdin);
	
	string line;
	ListNode *L1=new ListNode(0);
	ListNode *L2=new ListNode(0);
	ListNode *prev,*L3;

	
	int cnt=1;
	char buf[100];
	while(cin.getline(buf,100))	
	{
		if(cnt==1)
			L3=L1;
		else
			L3=L2;
		string sBuf=buf;
		vector<string> v;
		SplitString(sBuf,v," ");
		for(size_t i=0;i<v.size();i++)
		{
			ListNode *temp = new ListNode(0);
			int num=atoi(v[i].c_str());
			L3->val=num;
			prev=L3;
			L3->next=temp;
			L3=temp;
		}
		prev->next=NULL;
		free(L3);
		cnt++;


	}

	ListNode* curr = L1;
	while(curr)
	{
		cout<<curr->val<<" ";
		curr=curr->next;
	}
	cout<<endl;
	curr=L2;
	while(curr)
	{
		cout<<curr->val<<" ";
		curr=curr->next;
	}
	cout<<endl;

	L3=addTwoNumbers(L1,L2);
	while(L3)
	{
		cout<<L3->val<<" ";
		L3=L3->next;
	}
	cout<<endl;
	return 0;
}
