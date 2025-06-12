#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val) : data(val),next(nullptr){}
};

class st{
    Node* head;

    public:
        st(): head(nullptr){}
        ~st(){
            while(head){
                Node* temp= head;
                head = head->next;
                delete temp;
            }
        }
        void push(int val){
            Node* newnode = new Node(val);

            if(!newnode) return;
            newnode->next = head;
            head = newnode;
        }
        int pop(){
            if(isEmpty()) return -1;
            Node* temp =head;
            int value;
           
            value = temp->data;
            head = head->next;
            delete temp;
            
            return value;
        }
        int peek(){
            if(isEmpty()) return -1;
            return head->data;
        }        
        bool isEmpty(){
            return head==nullptr;
        }
        void print(){
            Node* temp = head;
            while(true){
                cout << temp->data << " -> ";
                temp = temp->next;

                if(temp == nullptr) break;
            }
            cout << "null" <<endl;
        }

};
int main(){
    st s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.print();

    s.pop();

    s.push(100);
    s.push(200);
    s.print();

    return 0;
}