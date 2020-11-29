#include <iostream>
#include <sstream>
#include <vector>


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
    vector<int> a;
    vector<int> b;
    while (getline(ss, val, ' ')){
        a.push_back(atoi(val.c_str()));
        b.push_back(atoi(val.c_str()));
    }
    vector<int> output;
    while ((!a.empty()) && !b.empty())
    {
        if(a.front() > b.back()){
            output.push_back(1);
            b.pop_back();
        }
        else if(a.front() < b.back()){
            output.push_back(2);
            a.erase(a.begin());
        }
        else if(a.front() == b.back()){
            output.push_back(0);
            a.erase(a.begin());
            b.pop_back();
        }
    }
    cout << endl;
    /*for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << ", ";
    }
    cout << endl;*/

    
}