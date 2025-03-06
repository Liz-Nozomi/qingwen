#include <bits/stdc++.h>
using namespace std;

int main(){
    string word;
    cin>>word;
    queue<char> q1;
    queue<char> q2;
    for(auto it:word){
        if(it == 'a' or it == 'e' or it == 'i' or it =='o' or it == 'u' or it == 'A' or it == 'E' or it == 'I' or it == 'O' or it == 'U'){
            q1.push (it);
        }else{
            q2.push(it);
        }
    }
    while(!q2.empty()){
        cout<<q2.front();
        q2.pop();
    }
    while(!q1.empty()){
        cout<<q1.front();
        q1.pop();
    }
}