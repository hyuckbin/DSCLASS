#include <iostream>
#include <string>
using namespace std;

struct st{
    string name[2];
    int price[2] ;
    string make[2];
};

void input(st& s){
    for(int i=0; i<2; i++){
       cin>>s.name[i] >> s.price[i] >> s.make[i];
    }
}

bool compare(const st& t){
    string n1 ="";
    string n2="";
    for(char ch : t.name[0]){
        ch = toupper(ch);
        n1 +=ch;
    }
    
    for(char ch : t.name[1]){
        ch = toupper(ch);
        n2 +=ch;
    }

    if(n1 == n2){
        if(t.price[0] == t.price[1]){
            return true;
        }
        
        return false;
    }

    return false;
}
int main(){
    st two;
    input(two);
    if(compare(two)){
        cout << two.name[0] << " is equal";
    }
    else{
        cout << two.name[0] <<" and "<< two.name[1] << " is not equal";
    }
   return 0;
}