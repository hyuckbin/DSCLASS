#include <iostream>
using namespace std;
//연결리스트 queue
// rear 과 front 는 같은 노드를 사용
struct Node{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr){}
};

class Q{
    Node* front;
    Node* rear;

    public :
        Q() : front(nullptr) , rear(nullptr){}
        ~Q(){
            while(front){
                dequeue();
            }
        }
        void enqueue(int val){
            Node* newnode = new Node(val);
            if(isEmpty()){
                front = rear = newnode;
                return;
            }
            rear -> next = newnode;
            rear = newnode;
        }
        int dequeue(){
            if(isEmpty()) return -1;
            Node *temp = front;
            int val = temp->data;
            front = front ->next; 
            delete temp;
            
            return val;
        }
        int getFront(){
            return front->data;
        }
        int getRear(){
            return rear->data;
        }
        bool isEmpty(){
            return front == nullptr;
        }
        void print(){
            Node *temp = front;
            while(true){
                cout << temp->data ;
                temp = temp->next;

                if(temp == nullptr) break;
                cout << " -> ";
            }
            cout <<endl;
        }
};
int main(){
    Q q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(1100);

    q.print();
    return 0;
}