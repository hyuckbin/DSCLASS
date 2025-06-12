#include <iostream>
using namespace std;
//stack
class st{
    int cap,top;
    int *list;

    public:
        st(int size): cap(size),top(-1){
            list = new int[size];
        }
        ~st(){
            delete[] list;
        }
        void push(int val){
            if(isFull()) return;

            list[++top] = val;
        }
        int pop(){
            if(isEmpty()) return -1;

            return list[top--];
        }
        int peek(){
            if(isEmpty()) return -1;
            return list[top];
        }        
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top +1 == cap;
        }
        void print(){
            for(int i=0; i< top+1; i++){
                cout << list[i] << " -> ";
            }
            cout <<endl;
        }

};

int main(){
    st s(5);
    s.push(10);
    s.push(20);
    s.push(30);

    s.print();

    s.pop();

    s.push(100);
    s.push(200);

    s.print();
    
}