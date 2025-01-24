#include <bits/stdc++.h>
using namespace std;

struct Fruit{
    string name;
    int price;
    Fruit(string _name,int _price){
        name = _name;
        price = _price;
    }
    bool operator<(const Fruit &other)const{
        return price > other.price;
    }

};

int main(){
    int n;
    cin>>n;
    priority_queue<Fruit> q;
    for(int i=0;i<n;i++){
        string name;
        int price;
        cin>>name>>price;
        q.push(Fruit(name,price));


    }
    auto topp=q.top();
    cout<<topp.name<<" "<<topp.price;
}

