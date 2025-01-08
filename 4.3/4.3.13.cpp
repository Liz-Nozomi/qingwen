#include <bits/stdc++.h>

using namespace std;

char graph[2200][2200];


void draw(int centerx,int centery,int layer ){
    if(layer==1){graph[centerx][centery]='X';}
    else{
        int totallen=pow(3,layer-1);
        int unitlen=totallen/3;

        draw(centerx-unitlen,centery-unitlen,layer-1);
        draw(centerx+unitlen,centery-unitlen,layer-1);
        draw(centerx-unitlen,centery+unitlen,layer-1);
        draw(centerx+unitlen,centery+unitlen,layer-1);
        draw(centerx,centery,layer-1);
        
        }
}
int main(){
    int n;
    cin>>n;

    int maxlen=pow(3,n-1);

    memset(graph,' ',sizeof(graph));
    draw(maxlen/2+1,maxlen/2+1,n);
    for(int i=1;i<=maxlen;i++){
        for(int j=1;j<=maxlen;j++){
            cout<<graph[i][j];

        }
        cout<<endl;
    }

}