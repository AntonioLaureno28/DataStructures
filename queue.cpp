#include <iostream>
const int max_itens = 10;


using namespace std;

struct queue
{
    int items[max_itens];
    int head = -1, tail;

    bool isEmpty(){
        return (head == -1);
    }

    bool isFull(){
        return (head == (tail+1) % max_itens);
    }

    void enqueue(int item){
        if(isFull()){
            cout << "A fila esta cheia\n";
        } else if(isEmpty()) {
            head = tail = 0;
            items[tail] = item;
        }
        else {
            items[tail % max_itens] = item;
            tail++;          
        }
    }

    int dequeue(){
        if(isEmpty()){
            cout << "a fila esta vazia\n";
            return 0;
        } else if(head == tail){
            head = -1;
        }
        else {
            head++;
            return items[(head-1) % max_itens];
        }
    }

    int print(){
        if(isEmpty()){
            cout << "Fila vazia";
        } else {
            cout << "[ ";
            for (int i = head; i < tail; i++){
                cout << items[i % max_itens] << " ";
            }
            cout << "]\n";
        }
    }
};


int main(){
    queue q;


    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);


    q.print();

    q.enqueue(11);

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue(11);
    q.enqueue(12);

    q.print();


}
