#include<iostream>
#include<vector>
using namespace std;
namespace Utils {
template <typename T>
void DisplayVec(vector<T> &vec)
{
    cout << "[";
    typename vector<T>::iterator iter = vec.begin();
    while (iter != vec.end()) {
        cout << *iter++ << ", ";
    }
    cout << "]"<<endl;
}

};