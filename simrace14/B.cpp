#include <bits/stdc++.h>
using namespace std;

int n,m;

void movel(vector< vector<char> > &graph){

    for(int i=0;i<n;i++){//一行
        queue<char> q;
        int jingcnt = 0;

        //如果遇到@直接入队；遇到#存储如果遇到%就把所有存储的#全部入队
        for(int j=0;j<m;j++){
            if(graph[i][j] == '@'){
                q.push('@');
            }else if(graph[i][j] == '#'){
                jingcnt++;
            }else{
                for(int jing=0;jing<jingcnt;jing++){
                    q.push('#');
                }
                jingcnt=0;
                q.push('%');
            }
        }
        for(int jing=0;jing<jingcnt;jing++){
            q.push('#');
        }
        jingcnt=0;


        for(int j=0;j<m;j++){
            graph[i][j] = q.front();
            q.pop();
        }
    }
}

void mover(vector< vector<char> > &graph){

    for(int i=0;i<n;i++){//一行
        queue<char> q;
        int jingcnt = 0;

        //如果遇到@直接入队；遇到#存储如果遇到%就把所有存储的#全部入队
        for(int j=m-1;j>=0;j--){
            if(graph[i][j] == '@'){
                q.push('@');
            }else if(graph[i][j] == '#'){
                jingcnt++;
            }else{
                for(int jing=0;jing<jingcnt;jing++){
                    q.push('#');
                }
                jingcnt=0;
                q.push('%');
            }
        }
        for(int jing=0;jing<jingcnt;jing++){
            q.push('#');
        }
        jingcnt=0;


        for(int j=m-1;j>=0;j--){
            graph[i][j] = q.front();
            q.pop();
        }
    }
}

void moved(vector< vector<char> > &graph){

    for(int j=0;j<m;j++){//一列
        queue<char> q;
        int jingcnt = 0;

        //如果遇到@直接入队；遇到#存储;如果遇到%就把所有存储的#全部入队
        for(int i=n-1;i>=0;i--){
            if(graph[i][j] == '@'){
                q.push('@');
            }else if(graph[i][j] == '#'){
                jingcnt++;
            }else{
                for(int jing=0;jing<jingcnt;jing++){
                    q.push('#');
                }
                jingcnt=0;
                q.push('%');
            }
        }
        for(int jing=0;jing<jingcnt;jing++){
            q.push('#');
        }
        jingcnt=0;


        for(int i=n-1;i>=0;i--){
            graph[i][j] = q.front();
            q.pop();
        }
    }
}

void moveu(vector< vector<char> > &graph){

    for(int j=0;j<m;j++){//一列
        queue<char> q;
        int jingcnt = 0;

        //如果遇到@直接入队；遇到#存储如果遇到%就把所有存储的#全部入队
        for(int i=0;i<n;i++){
            if(graph[i][j] == '@'){
                q.push('@');
            }else if(graph[i][j] == '#'){
                jingcnt++;
            }else{
                for(int jing=0;jing<jingcnt;jing++){
                    q.push('#');
                }
                jingcnt=0;
                q.push('%');
            }
        }
        for(int jing=0;jing<jingcnt;jing++){
            q.push('#');
        }
        jingcnt=0;


        for(int i=0;i<n;i++){
            graph[i][j] = q.front();
            q.pop();
        }
    }
}

int main(){
    cin>>n>>m;
    vector< vector<char> > graph(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    
    string cmds;
    cin>>cmds;//指令序列


    for(auto cmd:cmds){
        if(cmd == 'L'){
            movel(graph);
        }
        if(cmd == 'R'){
            mover(graph);
        }
        if(cmd == 'U'){
            moveu(graph);
        }
        if(cmd == 'D'){
            moved(graph);
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }

}