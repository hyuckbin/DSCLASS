#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 3;
struct gpa{
    string name[SIZE]; // 과목
    int score[SIZE]; // 학점
    int jumsu[SIZE]; // 취득점수
    string grade[SIZE];
    double getScore[SIZE]; //취득학점
};

void getGrade(gpa& g){
    for(int i=0; i<SIZE; i++){
    if(g.jumsu[i] >=95){
        g.getScore[i] = 4.5;
        g.grade[i] = "A+";
     }
     else if(g.jumsu[i] >=90){
        g.getScore[i] = 4.0;
        g.grade[i] = "'A0'";
     }
     else if(g.jumsu[i] >=85){
        g.getScore[i] = 3.5;
        g.grade[i] = "'B+'";
     }
     else if(g.jumsu[i] >=80){
        g.getScore[i] = 3.0;
        g.grade[i] = "'B0'";
     }
     else{
        g.getScore[i] = 0;
        g.grade[i] = "'F'";
     }
    }
}
void print(const gpa& p,int all,double gpa){
    for(int i=0; i<SIZE; i++){
    cout << p.name[i] <<"(" <<p.score[i] << ") " << p.grade[i]<<" "<< fixed << setprecision(1) <<p.getScore[i]<<endl; 
    }
    cout <<"Total Credit : " << all<< " GPA : " << fixed << setprecision(2) << gpa;
}

void cal(gpa& g){
    int allScore =0 ; //총 학점
    double gpa = 0;

    getGrade(g);
    for(int i=0; i<SIZE; i++){
        allScore += g.score[i];
        gpa += (g.score[i] * g.getScore[i]);
    }
    gpa = gpa/allScore;

    print(g,allScore,gpa);
}


int main(){
    gpa a;
    for(int i=0; i<SIZE; i++){
        cin >> a.name[i] >> a.score[i] >> a.jumsu[i];
    }
    cal(a);
    return 0;
}