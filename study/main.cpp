#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 3;

struct Jumsu{
    int jum[SIZE];
    int sum =0;
    double avg;
    string grade[SIZE];
};
// 전역변수 j 이렇게 사용하면 어느곳에서나 접근이 가능해서 코드 파악이 힘들다
void calcul(Jumsu& j){
    for(int i=0; i<SIZE; i++){
        j.sum += j.jum[i];
         // 평균 계산 위치
       
        if(j.jum[i]>= 70){
            j.grade[i] ="pass"; 
        }
        else j.grade[i] = "fail";
    }
    j.avg = (double)j.sum/SIZE;

}

void print(const Jumsu& j ,string n[3]){
    cout << j.sum <<" " << fixed<<setprecision(1) <<j.avg<<endl;
    for(int i = 0 ; i<SIZE; i++){
        cout << n[i] <<" - " <<j.grade[i] <<endl;
    }

}
int main(){
    Jumsu j;
    string name[3] = {"Kor" , "Eng" , "Math"};
    for(int i=0; i<SIZE; i++){
        cin>>j.jum[i];
   }
   
   calcul(j);

   print(j,name);

    return 0;
}