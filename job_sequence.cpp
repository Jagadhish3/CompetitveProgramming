#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct job{
    char ch;
    int deadline;
    int profit;
}job[5];
//error sqigly
class A{
    char c;
    int deadli;
    int pro;

    public:
    vector<job> vec;
    int push(char ch,int deadline,int profit){
        vec.push_back({ch,deadline,profit});
    }

    bool comp(job a,job b){
        return job.profit-ab.profit;
    }

   

};

int main(){
    sort(job,job+n,comp)
}