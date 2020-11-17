#include<iostream>
#include<vector>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1){
        return s;
    }
    vector< string > results;
    results.resize(numRows);
    bool change = false;
    int lineNo = 0;
    for(int i=0;i<s.size(); i++){
        char ch= s[i];
        results[lineNo].push_back(ch);
        if(lineNo == numRows-1 || lineNo == 0){
            change = !change;
        }
        lineNo += change ? 1 :-1;
    }
    string output;
    for(auto item : results){
        output += item;
    }
    return output;
}
class Input  {
    public:
        Input(string _s, int _numRows): s(_s), numRows(_numRows){}
        string s;
        int numRows;
};
int main() {
    vector<Input> inputs;
    Input input(string("LEETCODEISHIRING"), 3);
    Input input2(string("AB"), 1);

    inputs.push_back(input);
    inputs.push_back(input2);

    for(auto it : inputs){
        string output = convert(it.s, it.numRows);
        cout << it.s << " " << it.numRows<<endl;
        cout << output<<endl<<endl;
    }
    return 0;
}