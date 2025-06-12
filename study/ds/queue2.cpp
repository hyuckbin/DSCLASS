#include <iostream>
using namespace std;
class Q{
    int* list;        // 배열 포인터
    int capacity;    // 큐 크기
    int front;       // 첫 원소 인덱스
    int rear;        // 마지막 원소 인덱스
    int size ;

    public:
        Q(int size){
            capacity = size;
            list = new int[capacity];
            front = rear = 0;
            this->size =0;
        }
        ~Q(){
            delete[] list;
        }
        bool isEmpty(){
            return size == 0;
        }
        bool isFull(){
            return size == capacity;
        }
        void enqueue(int val){
            if(isFull()) return;
            list[rear] = val;
            rear = (rear + 1) % capacity;
            size ++;
        }
        int dequeue(){
            if(isEmpty()) return -1;
            int val = list[front];
            front = (front + 1) %capacity;
            size --;
            return val;
        }

        void display(){
            if(isEmpty()) return;
            int i = front;
            int count =0;
            while(count < size) {
                cout  << list[i] << " -> ";
                count ++;
                i = (i+1) % capacity;
            }
            cout <<endl;
        }
};
int main(){
    Q q(5);

     q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display(); // 출력: Queue elements: 10 20 30 40

    q.dequeue(); // 출력: 10을(를) 큐에서 삭제했습니다.
    q.dequeue(); // 출력: 20을(를) 큐에서 삭제했습니다.

    q.display(); // 출력: Queue elements: 30 40

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // 큐가 가득 찼으므로 삽입 실패

    q.display(); // 출력: Queue elements: 30 40 50 60
    return 0;
}