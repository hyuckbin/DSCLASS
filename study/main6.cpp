#include <iostream>
#include <sstream>
using namespace std;

class MS{
    int size , top;
    int* list;

    public:
        MS(int cap) : size(cap) , top(-1){
            list = new int[size];
        }
        ~MS(){
            delete[] list;
        }
        void push(int val){
            if(isFull()) return;

            list[++top] = val;
        }
        int pop(){
            if(isEmpty()) return -1;
            int temp = list[top];
            top --;

            return temp;
        }
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top+1 == size;
        }
        int peek(){
            return list[top];
        }

        void printAll(){
            int i=top;
            while(true){
                cout << list[i--];    
                if(i == -1) break;
                cout << " -> "; 
            }
            cout << endl;
        }
};
int main(){
    int count ;
    cin >> count;
    cin.ignore();
    MS s(count); 

    string way;
    
    while(true){
    cin >> way; 
    if(way == "push"){
    int num;    
        cin >> num;
        s.push(num);
    }
    if(way == "pop"){
        s.pop();
    }

    if(way == "print"){
        s.printAll();
        break;
    }
}

cout << "종료" ;



    return 0;
}