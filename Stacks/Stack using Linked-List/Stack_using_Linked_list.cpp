#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
    public:
        T val;
        Node<T>* next;

        Node(T val) {
            this->val = val;
            this->next = NULL;
        }
};

template <typename T>
class Stack {
    private:
        Node<T>* head;
        int length;

    public:
        Stack() {
            head = NULL;
            length = 0;
        }  

        int size() {
            return length;
        }

        bool isEmpty() {
            return length == 0;
        }

        void push(T val) {
            Node<T>* n = new Node<T>(val);
            n->next = head;
            head = n;
            length++;    
        }

        void pop() {
            if(isEmpty()) {
                cout<<"Stack is Empty"<<"\n";
                return;
            }

            Node<T>* temp = head;
            head = head->next;
            temp->next = NULL;
            delete(temp);
            length--;
        }

        T top() {
            if(isEmpty()) {
                cout<<"Stack is Empty"<<"\n";
                return 0;
            }
            return head->val;
        }
};

int main() {
    Stack<int> s;

    for(int i = 1 ; i<=10 ; i++) {
        s.push(i*i);
    }

    while(!s.isEmpty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}