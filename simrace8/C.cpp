//ybb
#include <bits/stdc++.h>
using namespace std;

struct file{
    string prefix;
    string name;
    string after;
};

file getFileName(const string& s) {
    file f;
    size_t lastSlash = s.find_last_of('/');

    if (lastSlash == s.npos) {
        f.prefix = "";
        f.name = s;
        f.after = "";
    } else {
        f.prefix = s.substr(0, lastSlash + 1);
        std::string fileName = s.substr(lastSlash + 1);
        size_t lastPoint = fileName.find_last_of('.');

        if (lastPoint == std::string::npos) {
            f.name = fileName;
            f.after = "";
        } else {
            f.name = fileName.substr(0, lastPoint);
            f.after = fileName.substr(lastPoint + 1);
        }
    }

    return f;
}

int main(){


    int n;
    cin>>n;
    vector<file> fs(n);
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        fs[i] = getFileName(s);
    }

    unordered_map<string,unordered_map<string,unordered_map<string,int> > > filesys;
    for (const auto &File : fs) {

        string name = File.name;
        string after = File.after;
        string prefix = File.prefix;

        auto &count = filesys[prefix][after][name];

        if (count == 0) {
            count = 2;
        } else {
            // 如果文件名已经存在，生成新名称
            int version = count;
            string newName = name + "(" + to_string(version) + ")";
            filesys[prefix][after][newName] = 1;
            count++;
        }
    }
    //cout<<filesys["/a/"]["txt"]["file"];
}