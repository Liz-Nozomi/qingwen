#include <bits/stdc++.h>

using namespace std;

char graph[2200][2200];

void X(int centerx,int centery,int layer){
    
    int totallen=pow(3,layer-1);
    int unitlen=totallen/3;
    int lw=unitlen/2;
    for(int i=centerx-lw;i<=centerx+lw;i++){
        for(int j=centery-lw;j<=centery+lw;j++){
            graph[i][j]='X';
        }
    }

}

void draw(int centerx,int centery,int layer ){
    if(layer==1){graph[centerx][centery]=' ';}

    else{
        int totallen=pow(3,layer-1);
        int unitlen=totallen/3;

        draw(centerx-unitlen,centery-unitlen,layer-1);
        draw(centerx,centery-unitlen,layer-1);
        draw(centerx+unitlen,centery-unitlen,layer-1);

        draw(centerx-unitlen,centery,layer-1);
        draw(centerx+unitlen,centery,layer-1);

        draw(centerx-unitlen,centery+unitlen,layer-1);
        draw(centerx,centery+unitlen,layer-1);
        draw(centerx+unitlen,centery+unitlen,layer-1);

        X(centerx,centery,layer);
        
        }
}
int main(){
    int n;
    cin>>n;

    int maxlen=pow(3,n-1);

    memset(graph,' ',sizeof(graph));

    draw(maxlen/2+1,maxlen/2+1,n);
    for(int i=0;i<=maxlen+1;i++){
        graph[0][i]='+';
        graph[maxlen+1][i]='+';
        graph[i][0]='+';
        graph[i][maxlen+1]='+';
    }
    for(int i=0;i<=maxlen+1;i++){
        for(int j=0;j<=maxlen+1;j++){
            cout<<graph[i][j];

        }
        cout<<endl;
    }

}