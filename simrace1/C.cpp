#include <bits/stdc++.h>
using namespace std;
struct Student{
    int score[4];
    int id;
    int sum;
    Student(int _sa,int _sb,int _sc,int _sd){
        score[0] = _sa;
        score[1] = _sb;
        score[2] = _sc;
        score[3] = _sd;
        sum = _sa + _sb + _sc + _sd;
    }
    Student(){}
    bool isselected = false;
};


struct School{
    int k;//录取人数
    int c;//选择科目
    vector<int> selectedstudent;
    School(int _k,int _c){
        k = _k;
        c = _c;
    }
    School(){}
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<Student> students(n);
    vector<School> schools(m);

    for(int i=0;i<n;i++){
        int s1,s2,s3,s4;
        cin>>s1>>s2>>s3>>s4;
        students[i] = Student(s1,s2,s3,s4);
        students[i].id = i;

    }

    for(int i=0;i<m;i++){
        int k,c;
        cin>>k>>c;
        schools[i] = School(k,c);
    }

    //现在开始排序。
    for(int i=0;i<m;i++){//遍历学校
        int ck = schools[i].k;
        int cc = schools[i].c;

        sort(students.begin(),students.end(),[cc](const Student &a,const Student &b){
            if(a.sum != b.sum){
                return a.sum > b.sum;
            }else if(a.sum == b.sum and cc == 0){
                return a.id < b.id;
            }else if(a.sum == b.sum and cc != 0 and a.score[cc-1] != b.score[cc-1]){
                return a.score[cc-1] > b.score[cc-1];
            }else if(a.sum == b.sum and cc != 0 and a.score[cc-1] == b.score[cc-1]){
                return a.id < b.id;
            }
        
        });


        int tk_score = students[ck].sum;
        int tk_c_score = students[ck].score[cc-1];
        
        int cnt = 0;
        int j = 0;
        
        while(cnt < ck){
            if(!students[j].isselected){
                schools[i].selectedstudent.push_back(students[j].id);
                students[j].isselected = true;
                cnt++;
            }
            j++;
        }//录取ck人

        if(cc == 0){
            while(j<n and students[j-1].sum == students[j].sum){
                if(!students[j].isselected){
                    schools[i].selectedstudent.push_back(students[j].id);
                    students[j].isselected = true;
                }
                j++;
            }
        }//cc=0时候的超额录取
        if(cc != 0){
            while(j<n and students[j-1].sum == students[j].sum and students[j].score[cc-1] == students[j-1].score[cc-1]){
                if(!students[j].isselected){
                    schools[i].selectedstudent.push_back(students[j].id);
                    students[j].isselected = true;

                }
                j++;
            }
        }//cc!=0时候的超额录取

    }

    int temp = 0;
    for(auto it:schools){
        cout<<it.selectedstudent.size();
        if(it.selectedstudent.size() != 0){
            cout<<" ";
        }

        int temp2 = 0;
        for(auto it2:it.selectedstudent){
            cout<<it2+1;
            temp2++;
            if(temp2 < it.selectedstudent.size()){
                cout<<" ";
            }
            
        }
        temp++;
        if(temp < schools.size()){
            cout<<endl;
        }

    }


}