#include <iostream>
using namespace std;

// Creating a class for circular linked list
class C_Queue {
    // initialise a pointer that will be used to dynamically allocate size of
    // the queue each time the program is run
    int *queue;

 public:
    int size, first, last;
    C_Queue(int s) {
        size = s;
        // initialising an array of the size user gave in contructor while
        // creating class object
        queue = new int(size);
        first = last = -1;
    }
    void enqueue(int el);
    int dequeue();
    bool isEmpty();
    bool isFull();
    void display();
};
void C_Queue::enqueue(int el) {
    if (isFull() != true) {
        if (last == size - 1 || last == -1) {
            queue[0] = el;
            last = 0;
            if (first == -1)
                first = 0;
        } else {
            queue[++last] = el;
        }
    } else {
        cout << "\nQueue is Full";
    }
}
int C_Queue::dequeue() {
    if (isEmpty() || first >= size) {
        return -1;
    } else {
        int data = queue[first];
        if (first == last) {
            first = last = -1;
        } else if (first == size - 1) {
            first = 0;
        } else {
            first++;
        }
        return data;
    }
}
bool C_Queue::isEmpty() { return first == -1 && last == -1; }
bool C_Queue::isFull() {
    return (first == 0 && last == size - 1 || first == last + 1);
}
void C_Queue::display() {
    if (isEmpty()) {
        cout << "Queue is Empty!!";
    } else {
        cout << "Queue: \n";
        if (last >= first) {
            for (int i = first; i <= last; i++) {
                cout << queue[i] << " ";
            }
        } else if (first >= last) {
            for (int i = first; i < size; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= last; i++) {
                cout << queue[i] << " ";
            }
        }
    }
    cout << endl;
}

void menu() {
    cout << "\n1. Enqueue";
    cout << "\n2. Dequeue";
    cout << "\n3. Display";
    cout << "\n4. Exit";
}
int main() {
    int size, d, t;
    cout << "Enter the size of the queue: ";
    cin >> size;
    C_Queue *queue = new C_Queue(size);
    while (true) {
        menu();
        int ch;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the element: ";
                int ele;
                cin >> ele;
                queue->enqueue(ele);
                break;
            case 2:
                d = queue->dequeue();
                if (d != -1) {
                    cout << "Deleted element: " << d;
                } else {
                    cout << "Queue Empty!";
                }
                break;
            case 3:
                queue->display();
                break;
            case 4:
                return 0;
        }
    }
}