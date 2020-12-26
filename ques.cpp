

#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int count=0,m=0;
    for(int i=0;i<n;++i){
        count+=arr[i];
        if(count<0){
            count=0;
        }
        m=max(m,count);
    }
    cout<<m<<endl;
}