#include <bits/stdc++.h>
using namespace std;
int currentschool;

struct student{
    int idx;
    int A;
    int B;
    set<int> schools_applied;
    set<int> friends;

    int school_final_score[1010];
    int finalschool = -1;
};
struct school{
    int idx;
    int q;//人数上限
    int f;//加分
    int y;//门槛
    int lowest_score;
    vector<int> finalstudent;
};
vector<student> students(1010);
vector<school> schools(1010);

bool cmp_school(int stu1,int stu2){
    auto stua = students[stu1];
    auto stub = students[stu2];
    //cout<<"here"<<endl;
    return stua.school_final_score[currentschool] > stub.school_final_score[currentschool] and stua.A > stub.A and stua.B > stub.B and stua.idx > stub.idx;

}
int main(){
    int n,m,k;//学校， 学生，申请
    cin>>n>>m>>k;



    vector< vector<int> >schools_select_students(1010);

    vector< vector<int> >students_select_schools(1010);

    for(int i=0;i<m;i++){
        student s;
        cin>>s.A>>s.B;
        s.idx = i;
        students[i] = s;
        
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            int as;
            cin>>as;
            students[i].schools_applied.insert(as-1);
        }
    }

    int relc;
    cin>>relc;
    for(int i=0;i<relc;i++){
        int si,ti;
        cin>>si>>ti;
        students[si-1].friends.insert(ti-1);
        students[ti-1].friends.insert(si-1);

    }

    //cout<<"donehere";
    for(int i=0;i<n;i++){
        cin>>schools[i].q>>schools[i].f>>schools[i].y;
        schools[i].idx = i;
    }


    //以下为学校选学生--------------------


    for(int sc=0;sc<n;sc++){//每所学校


        int tq = schools[sc].q;
        int tf = schools[sc].f;
        int ty = schools[sc].y;


        for(int stu = 0;stu<m;stu++){
            if(students[stu].schools_applied.find(sc) != students[stu].schools_applied.end()){
                //cout<<stu<<endl;
                //申请了这所学校
                int score = students[stu].A+students[stu].B;

                if(score > ty){
                    score += tf;
                }
                else{
                    for(auto it:students[stu].friends){
                        if(students[it].schools_applied.find(sc) != students[it].schools_applied.end()){
                            score += tf;
                            break;
                        }
                    }
                }
                students[stu].school_final_score[sc] = score;
                //cout<<score<<endl;
                //到此为止正确

                schools_select_students[sc].push_back(stu);
            }
        }


        currentschool = sc;
        sort(schools_select_students[sc].begin(),schools_select_students[sc].end(),cmp_school);


        //这里还有一个超额录取 我不写了

        schools[sc].lowest_score = students[schools_select_students[sc][tq-1]].school_final_score[sc];//找当前学校录取最低分


        for(int i=0;i<tq;i++){//录取工作
            students_select_schools[schools_select_students[sc][i]].push_back(sc);
        }
    }//至此，学生录取完成



    for(int stu=0;stu<m;stu++){
        int lowest_score=0;
        int selectschool = -1;

        for(auto sch:students_select_schools[stu]){
            if(schools[sch].lowest_score > lowest_score){
                selectschool = schools[sch].idx;
                lowest_score = schools[sch].lowest_score;
            }
        }
        students[stu].finalschool = selectschool;
        schools[selectschool].finalstudent.push_back(stu);
    }

    for(int i=0;i<n;i++){
        cout<<"School "<<i+1<<": ";

        int temp = 0;
        for(auto it:schools[i].finalstudent){
            cout<<it+1;
            if(temp < schools[i].finalstudent.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }





}