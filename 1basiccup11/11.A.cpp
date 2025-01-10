//全排列
#include <bits/stdc++.h>
using namespace std;

void printtime(int t){
    int D=t/86400;
    int H=t%86400/3600;
    int M=t%86400%3600/60;
    int S=t%60;
    cout<<D<<":"<<H<<":"<<M<<":"<<S<<endl;

}

int main(){
    string sr;
    cin>>sr;
    vector<int> queu;
    for(int i=0;i<sr.length();i++){
        int ascii;
        ascii=static_cast<int>(sr[i]);

        if(ascii>=48 and ascii<=57){
            queu.push_back(ascii+4);

        }//0-9
        else if(ascii>=65 and ascii<=90){
            queu.push_back(ascii-65);
        }//AZ
        else if(ascii>=97 and ascii<=122){
            queu.push_back(ascii-71);
        }//az
    }
    int totaltime=queu[0]+queu[1]*62+queu[2]*62*62+queu[3]*62*62*62;
    //cout<<totaltime+1;

    printtime(totaltime+1);
    
}