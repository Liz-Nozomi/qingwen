#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<char, int>pii;
bool cmp(pii a, pii b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
int main(){
    string n;
    int k;
    cin>>n>>k;
    vector<pii> value;
    vector<char> temp;
    for(int i=0;i<n.size();i++){
        temp.push_back(n[i]);
        value.push_back(pii(n[i], i));
    }
    sort(temp.begin(), temp.end(), greater<char>());
    string max_result = "";
    for(int i=0;i<n.size();i++){
        max_result += temp[i];
    }
    int count = 0;
    while(k > 0 && value.size() > 0){
        sort(value.begin(), value.end(), cmp);
        int num = 0;
        while(value[num].second - count > k){
            num ++;
        }
        if(num == value.size()){
            count++;
            continue;
        }
        int step = value[num].second;
        for(int i = step-1;i>=count;i--){
            n[i+1] = n[i];
        }
        n[count] = value[num].first;
        value.erase(value.begin()+num);
        k -= (step -count);
        count ++;
        if(n == max_result){
            break;
        }
    }
    if(k > 0 && k % 2 == 1){
        swap(n[n.size()-1], n[n.size()-2]);
    }
    cout<<n;
    return 0;
}