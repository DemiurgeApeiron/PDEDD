#include <iostream>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

int main(){
    cout << "enter the list values: " <<endl;
    string line, val;
    getline(cin, line);
    stringstream ss(line);
    queue<int> a;
    stack<int> b;
    while (getline(ss, val, ' ')){
        a.push(atoi(val.c_str()));
        b.push(atoi(val.c_str()));
    }
    vector<int> output;
    while ((!a.empty()) && !b.empty())
    {
        if(a.front() > b.top()){
            output.push_back(1);
            b.pop();
        }
        else if(a.front() < b.top()){
            output.push_back(2);
            a.pop();
        }
        else if(a.front() == b.top()){
            output.push_back(0);
            a.pop();
            b.pop();
        }
    }
    cout << endl;
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << ", ";
    }
    cout << endl;
    

    
}