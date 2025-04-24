#include<iostream>
#include<vector>
using namespace std;

void maxheap(vector<int> &vec){
    int i=vec.size()-1;

    while(i>0){
        int p = (i-1)/2;
        if(vec[i]>vec[p]){
            swap(vec[i],vec[p]);
            i=p;
        }else{
            break;
        }
    }
}
void deletion(vector<int> &vec){
    if(vec.empty()){
        cout<<"Heap is empty.";
        return;
    }

    vec[0]=vec.back();
    vec.pop_back();

    int i=0;
    int size=vec.size();

    while(true){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest = i;

        if(left<size && vec[left]>vec[largest]){
            largest=left;
        }

        if(right<size && vec[right]>vec[largest]){
            largest=right;
        }

        if(largest==i) break;
        swap(vec[i],vec[largest]);
        i=largest;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> res;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;

        res.push_back(ele);
        maxheap(res);
    }
    // deletion(res);
    int k;
    cout<<"Enter kth largets element";
    cin>>k;
    for(int i=1;i<k;i++) deletion(res);

cout<<res[0];
    // for(int i:res){
    //     cout<<i<<" ";
    // }
}