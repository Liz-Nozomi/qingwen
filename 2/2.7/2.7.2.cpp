#include <iostream>
#include <cstring>
using namespace std;
void increase(int &x) {
    x++;
    
}
int main(){
    int n;
    scanf("%d",&n);
    increase(n);
    cout<<n<<endl;
}