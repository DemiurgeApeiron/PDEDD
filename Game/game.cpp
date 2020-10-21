#include <iostream>
#include <queue>
#include <sstream>
#include <stack>

using namespace std;

int main(){
    string line;
    srand(time(NULL));
    for(size_t i = 0; i < 100000; i++){
        int numRand = (int)rand();
        line += to_string(numRand % (10)) + " ";
    }
    line = line.substr(0, line.size()-1);
    string val;
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
    /*for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << ", ";
    }
    cout << endl;*/
    

    
}