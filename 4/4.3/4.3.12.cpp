#include<bits/stdc++.h>
using namespace std;
int graph[26][26]={0};
int total;
int current=1;


void draw(int x,int y,int direction){
    //direction,length
    if(current>total*total){
        return;
    }
    if(direction % 4==1 ){
        while(x<=total and x>=1 and graph[x][y]==0){
            graph[x][y]=current;
            x++;
            current++;
            
        }
        x--;y++;
    }
    if(direction % 4==2 ){
        while(y<=total and y>=1 and graph[x][y]==0){
            graph[x][y]=current;
            y++;
            current++;
            

        }
        y--;x--;
    }
    if(direction % 4==3 ){
        while(x<=total and x>=1 and graph[x][y]==0){
            graph[x][y]=current;
            x--;
            current++;
          

        }
        x++;y--;
    }
    if(direction % 4==0 ){
        while(y<=total and y>=1 and graph[x][y]==0){
            graph[x][y]=current;
            y--;
            current++;
         

        }
        x++;y++;
    }
    draw(x,y,direction+1);



}


int main(){
    int n;
    cin>>n;
    total=n;
    
    draw(1,1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[j][i];
            if(j<=n-1)cout<<" "; 
        }
        cout<<endl;

    }
}