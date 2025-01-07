#include <iostream>
#include <cstring>
using namespace std;
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y){
        x=_x;
        y=_y;
    }
};


int main(){
    Point point;
    int x,y;
    scanf("%d %d",&x,&y);
    point=Point(x,y);
    printf("%d %d",point.x,point.y);


}
