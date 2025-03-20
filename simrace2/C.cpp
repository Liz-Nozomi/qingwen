#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int maxH = 0;
    string s;
    cin>>s;
    if( s.length() == 0){
        cout<<"##########################"<<endl;
        cout<<"abcdefghijklmnopqrstuvwxyz"<<endl;
        cout<<"00000000000000000000000000"<<endl;
        return 0;
    }
    vector<int> frequency(26,0);
    for(int i=0;i<s.length();i++){
        frequency[s[i]-'a'] ++;
    }
    for(int temp:frequency){
        maxH = max(maxH, temp);
    }
    vector<string> result;
    for(int i=1;i<=maxH;i++){
        string temp = "";
        for(int j=0;j<26;j++){
            if(frequency[j] >= i){
                temp += '@';
            }else{
                temp += '#';
            }
        }
        result.push_back(temp);
    }
    cout<<"##########################"<<endl;
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<endl;
    }
    cout<<"abcdefghijklmnopqrstuvwxyz"<<endl;
    int bitLine = 0;
    while(maxH > 0){
        bitLine ++;
        maxH /= 10;
    }
    vector<vector<char>> bits(26);
    for(int i=0;i<26;i++){
        int fre = frequency[i];
        vector<char> temp;
        while(fre != 0){
        	int t = fre % 10;
        	char tt = '0' + t;
            temp.push_back(tt);
            fre /= 10;
        }
        reverse(temp.begin(),temp.end());
        if(temp.size() == 0){
        	temp.push_back('0');
		}
        int ttt = temp.size();
        for(int j=0;j<bitLine - ttt;j++){
            temp.push_back('$');
        }
        bits[i] = temp;
    }
    for(int i=0;i<bitLine;i++){
        for(int j = 0;j<26;j++){
            cout<<bits[j][i];
        }
        cout<<endl;
    }
    return 0;
}