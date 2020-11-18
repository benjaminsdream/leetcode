#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

// int reverse(int x) {
//     if(x / 10 == 0 ) {
//         return x;
//     }
//     bool negtive = false;
//     long long   y = x;
//     if(x<0){
//         y =  ~(long long)x + 1;
//         // cout << y << " | x=" << x << " | INT_MAX:" << INT_MAX<<endl;
//         negtive = true;
//     }
//     vector<int> chList;

//     while(y != 0){
//         int  mod = y % 10;

//         chList.push_back(mod);
//         y = y/10;
//     }
//     // for(auto i : chList){
//     //     cout << "i:"<< i << endl;
//     // }
//     long result = 0;
//     int count = 0;
//     int len = chList.size();
//     for(int i=0; i<chList.size(); i++) {
//         int  ch = chList[i];
//         if(ch == 0){
//             count ++;
//             continue;
//         } else {
//             break;
//         }
//     }
//     int begin = len-count-1;
//     for(int i=count; i< len; i++){
//         int ch = chList[i];
//         int n = begin--;
//         long tmp = (ch *  (long long)(pow(10, n)));
//         if(tmp > INT_MAX){
//             return 0;
//         }
//         result += tmp;
//         // cout << ch << " | " << pow(10, n) << " " << tmp << "  | " << result << "  " <<endl;

//     }
//     if(result > INT_MAX){
//         result = 0;
//     }
//     if(negtive){
//         result = ~result+1;
//     }
//     return result;
// }
int reverse(int x) {
    int result = 0;
    while(x != 0 ){
        int mod = x%10;
        x = x/10;
        if((result > INT_MAX/10) || ( (result == INT_MAX/10)  && mod > 7)) return 0;
        if((result < INT_MIN/10) || ( (result == INT_MIN/10)  && mod < -8)) return 0;
        result = result * 10 + mod;
        // cout << mod << " | " << x << " | " << result <<endl;
    }
    return  result + x;
}
int main(){
    vector<int> inputs;
    inputs.push_back(0);
    inputs.push_back(123);
        inputs.push_back(120);

    inputs.push_back(123456789);
        inputs.push_back(123456780);

    inputs.push_back(1234567899);
    inputs.push_back(-2147483648);
    inputs.push_back(2147483647);
    inputs.push_back(2147483641);




    for(auto i : inputs){
        int output = reverse(i);
        cout << i << "   |  " << output << endl;
    }
    return 0;
}