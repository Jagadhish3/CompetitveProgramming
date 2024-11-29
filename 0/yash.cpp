#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        vec.push_back(ele);
    }
    
    int val;
    cin>>val;

    auto it=find(vec.begin(),vec.end(),val);
    if(it!= vec.end()){
        cout<<distance(vec.begin(),it);
    }
  else{
    cout<<"Element not found: ";
  }
    
}
















































/*#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int> vec;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;

        vec.push_back(ele);
    }

   
    //sorting
    sort(vec.begin(),vec.end());

    //reverse
    reverse(vec.begin(),vec.end());

    //merge
    //merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),vec3.begin())

    int val;
    cin>>val;

    int index;
    cin>>index;
    // //insert at begin
    vec.insert(vec.begin(),val);

    // //insert at position
    vec.insert(vec.begin()+index-1,val);

    // //insert at index
    vec.insert(vec.begin()+index-1,val);

    // //insert at ending
    vec.insert(vec.end(),val);


    //deletion at begin
    vec.erase(vec.begin());

    //deletion at index
    vec.erase(vec.begin()+index);

    //deletion at index
    vec.erase(vec.begin()+index-1);

    //deletion at ending
    vec.erase(vec.end()-1);

    for(int i=0;i<vec.size();i++){
        cout<<vec.at(i)<<" ";
    }
    return 0;
}
*/