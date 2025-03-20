#include <bits/stdc++.h>
using namespace std;
struct order{
    char type;
    int price;
    int quantity;    
    order(){}
    order(char _type,int _price,int _quantity){
        type = _type;
        price = _price;
        quantity = _quantity;

    }
    int idx;
};

bool cmpbuy(order o1,order o2){
    if(o1.price != o2.price){
        return o1.price < o2.price;
    }else if(o1.price == o2.price){
        return o1.idx > o2.idx;
    }
}
bool cmpsell(order o1,order o2){
    if(o1.price != o2.price){
        return o1.price > o2.price;
    }else if(o1.price == o2.price){
        return o1.idx > o2.idx;
    }
}

priority_queue<order,vector<order>,decltype(&cmpbuy)> buy(cmpbuy);
priority_queue<order,vector<order>,decltype(&cmpsell)> sell(cmpsell);

void trade(order o){
    if(o.type == 'B'){//买单到达
        while(!sell.empty() and sell.top().price <= o.price and o.quantity >0){
            if(o.quantity >= sell.top().quantity){
                o.quantity -= sell.top().quantity;
                sell.pop();
            
            }else{
                auto temp = sell.top();
                sell.pop();
                temp.quantity -= o.quantity;
                sell.push(temp);
                o.quantity = 0;
            }
        }
        if(o.quantity != 0){
            buy.push(o);
        }
    }

    if(o.type == 'S'){//卖单到达
        while(!buy.empty() and buy.top().price >= o.price and o.quantity >0){
            if(o.quantity >= buy.top().quantity){
                o.quantity -= buy.top().quantity;
                buy.pop();
            
            }else{
                auto temp = buy.top();
                buy.pop();

                temp.quantity -= o.quantity;
                buy.push(temp);
                o.quantity = 0;
            }
        }
        if(o.quantity != 0){
            sell.push(o);
        }
    }

}

int main(){
    int n;
    cin>>n;


    //我tmd用不了lambda 草

    for(int i=0;i<n;i++){
        order o;
        cin>>o.type>>o.price>>o.quantity;
        o.idx = i;
        trade(o);
        
    }
    cout<<buy.size()<<endl;
    while(!buy.empty()){
        cout<<buy.top().type<<" "<<buy.top().price<<" "<<buy.top().quantity<<endl;
        buy.pop();
    }

    cout<<sell.size()<<endl;
    while(!sell.empty()){
        cout<<sell.top().type<<" "<<sell.top().price<<" "<<sell.top().quantity<<endl;
        sell.pop();
    }

}