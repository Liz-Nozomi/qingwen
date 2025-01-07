#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> arr;
    string wd;

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        cin>>wd;
        arr.push_back(wd);
    }

    int shortest=arr[0].length();
    for(int i=0;i<n;i++){
        if((arr[i].length())<shortest){
            shortest=arr[i].length();
        }
    }

    int head,token=0;
    for (int i=0;i<shortest;i++){
        if(token==1)break;
        for(int j=0;j<n-1;j++){
            if(arr[j][i]==arr[j+1][i]){
                //cout<<arr[j][i]<<endl;
            }else{
                //cout<<"wa "<<arr[j][i]<<endl;
                token=1;
                head=i;
                break;
            }
        }
    }

    for(int i=0;i<head;i++){
        cout<<arr[0][i];
    }
}