/*
Programming Studio DS009
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findRoom(int persons[5]){
    int can[5];
    int canCount = 0;
    for(int i=0; i<5; i++){
        if(persons[i] < 2){
            can[canCount] = i;
            canCount++;
        }
    }
    if(canCount ==0) {
        return -1;}

    int randindex = rand() % canCount;

    int select = can[randindex];


    return select +1 ;
} 
void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc,int p[2][5]){
    cout<<"남학생"<<endl;
    for(int i= 0; i<mc ; i++){
        cout << mn[i] <<" : " << mr[i] <<" 호 "<<endl; 
    }
    cout<<"여학생"<<endl;
    for(int i= 0; i<wc ; i++){
        cout << wn[i] <<" : " << wr[i] <<" 호 "<<endl; 
    }

    cout <<"호실별 명단"<<endl;
    int r[10] = {101,102,103,104,105,201,202,203,204,205};
    string name[10] = {};
    /*
    101 호에 있는 사람들을 알아함
    어떻게
    mn 에는 이름이 담겨있고, mr 에는 남자가 몇호에 있는지 있다. 그럼 mr[mc]로 굴리면 될까?
    
    */
    for(int i=0; i<mc; i++){
        int num = mr[i] -101;
        name[num] += mn[i] + " ";
    }
    //a, b, c -> 103 , 101 ,102 호 베정받음
    //num = mr[i] -101 = 2 , 0 ,1 -> name[2] = mn[0] = a ///mn[1] = b , me[2] =c , mn[3] ==
    for(int i=0; i<wc; i++){
        int num = wr[i] -201+5;
        name[num] += wn[i] + " ";
    }

    for(int i = 0; i < 10; i++){
        if(name[i] == ""){
            cout << r[i] << "호 : " <<endl;
        }
        if(name[i] != ""){
            cout << r[i] << "호 : " << name[i] << endl;
        }

    }
}

int main(){
    int person[2][5]={0};

    string mn[10]; //남자 이름
    int mr[10] ; // 남자 방 위치
    int mc =0 ; // 남자 수
    string wn[10]; 
    int wr[10];
    int wc = 0;

    int menu;
    srand(time(0));

    while(1){
        cout << " menu 입력:  0 = 종료 1 = 남  2= 여  ";
        cin >> menu;

        if(menu ==0 ) break;

        else if(menu==1){
            if(mc>10) continue;

            cout << " 학생이름 : " ;
            cin >>mn[mc];

            int roomno = findRoom(person[0]);
            mr[mc] = 100 + roomno;
            
            cout << mn[mc] << "학생 " <<mr[mc] <<"에 배정됨"<< endl;
            person[0][roomno-1] ++;
            mc ++;
        }

        else if(menu==2){
            if(wc>10) continue;

            cout << " 학생이름 : " ;
            cin >>wn[wc];
            
            int roomno = findRoom(person[1]);
            wr[wc] = 200 + roomno;
            
            cout << wn[wc] << "학생 " <<wr[wc] <<"에 배정됨"<< endl;
            person[1][roomno-1] ++;
            wc ++;
        }

        else if(menu ==3){
            printReport(mn,mr,mc,wn,wr,wc,person);
        }

    }

	return 0;
}

