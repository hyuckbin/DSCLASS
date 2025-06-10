#include <iostream>
using namespace std;

int main(){
    string alpha;
    int alphacount[26] = {0};
    int blankcount =0;
    getline(cin,alpha);
    string append = "";

    for(char ch : alpha){
        ch = toupper(ch);
        append+=ch;
        if(isalpha(ch))
            alphacount[ch-'A'] ++;
        else if(ch ==' ') 
            blankcount++;
    }
    
    alpha = append;
    for(int i=0; i<26; i++){
        if(alphacount[i]>0){
            cout << char('A'+i)<<" : " << alphacount[i] <<endl;
        }
    }
    

    cout <<"Blankcount : " << blankcount;

    return 0;
}