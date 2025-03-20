#include <bits/stdc++.h>
using namespace std;
struct vec{
    int start;
    int end;
    int x;
    int y;
    int z;
    vec(){}
    vec(int _start,int _end,int _x,int _y,int _z){
        start = _start;
        end = _end;
        x = _x;
        y = _y;
        z = _z;
    }
};

struct point{
    int px;
    int py;
    int pz;
    point(int _x,int _y,int _z){
        px=_x;
        py = _y;
        pz = _z;
    }
    point(){}
};


int main(){
    int n,m;
    cin>>n>>m;
    vector<point> friends(n+1);
    vector<bool> havelocation(n+1,false);//是否已经确定位置


    vector< vector<vec> > graph(n+1);//类似邻接表
    


    for(int i=0;i<m;i++){
        int op;
        cin>>op;
        if(op == 2){
            int pi,xi,yi,zi;
            cin>>pi>>xi>>yi>>zi;
            friends[pi] = point(xi,yi,zi);
            havelocation[pi] = true;

            //需要清理所有和它相关的向量，如果有更长的依赖，需要用bfs来更新

            queue<int> q;
            q.push(pi);
            while(!q.empty()){
                auto topp = q.front();
                q.pop();
                for(auto vecs:graph[topp]){
                
                    if(!havelocation[vecs.end]){
                        point p;
                        auto current = friends[topp];
                        p.px = current.px + vecs.x;
                        p.py = current.py + vecs.y;
                        p.pz = current.pz + vecs.z;
    
                        friends[vecs.end] = p;
                        havelocation[vecs.end] = true;
                        q.push(vecs.end);
                    }
                }
            }

            
        }

        if(op == 1){
            int ai,bi,xi,yi,zi;
            cin>>ai>>bi>>xi>>yi>>zi;
            if(havelocation[ai]){
                friends[bi] = point(friends[ai].px + xi,friends[ai].py + yi,friends[ai].pz + zi);
                havelocation[bi] = true;
            }else if(havelocation[bi]){
                friends[ai] = point(friends[bi].px-xi,friends[bi].py-yi,friends[bi].pz-zi);
                havelocation[ai] = true;
            }//已经有点的两种情况

            else{
                graph[ai].push_back(vec(ai,bi,xi,yi,zi));
                graph[bi].push_back(vec(bi,ai,-xi,-yi,-zi));
            }//不存在点则直接推进去

        }
    }

    for(int pi=1;pi<=n;pi++){
        if(!havelocation[pi]){
        queue<int> q;
            q.push(pi);
            while(!q.empty()){
                auto topp = q.front();
                q.pop();
                for(auto vecs:graph[topp]){
                
                    if(!havelocation[vecs.end]){
                        point p;
                        auto current = friends[topp];
                        p.px = current.px + vecs.x;
                        p.py = current.py + vecs.y;
                        p.pz = current.pz + vecs.z;
    
                        friends[vecs.end] = p;
                        havelocation[vecs.end] = true;
                        q.push(vecs.end);
                    }
                }
            }
        }
    }


    for(int i=1;i<=n;i++){
        if(!havelocation[i]){
            cout<<-1<<endl;
        }
        else{
            cout<<friends[i].px<<" "<<friends[i].py<<" "<<friends[i].pz<<endl;
        }
    }



}