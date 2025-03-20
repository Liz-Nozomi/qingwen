#include <bits/stdc++.h>
using namespace std;
int removebuildings(vector<int> &height){
    int n = height.size();
    if(n == 1){
        return 0;
    }

    vector<bool> abletoremove(n,false);
    int rmvcnt = 0;
    for(int i=1;i<n-1;i++){
        if(height[i] > height[i-1] or height[i] > height[i+1]){
            abletoremove[i] = true;
            rmvcnt++;
        }
    }

    if(n>2 and height[0] > height[1]){
        abletoremove[0] = true;
        rmvcnt++;
    }
    if(n>2 and height[n-1] > height[n-2]){
        abletoremove[n-1] = true;
        rmvcnt++;
    }

    if(n==2){
        if(height[0] > height[1]){
            abletoremove[0] = true;
            rmvcnt++;
        }
        else if(height[0] < height[1]){
            abletoremove[1] = true;
            rmvcnt++;
        }
        else return 0;
    }


    vector<int> res;
    for(int i=0;i<n;i++){
        if(abletoremove[i] == false){
            //cout<<"pushed"<<i;
            res.push_back(height[i]);
        }
    }
    //cout<<endl;
    height = res;
    return rmvcnt;

}
int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }

    if(n == 2){
        if(height[0] != height[1]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }//好像没有这样的数据点？

    if(n == 1){
        cout<<0;
        return 0;
    }//有一个点

    int opcnt = 0;
    
    while(removebuildings(height) != 0){
        opcnt++;
    }
    cout<<opcnt;


}