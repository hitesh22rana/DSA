// Stack Implementation using array


#include<bits/stdc++.h>
using namespace std;

class Stack {
    private:
        int *arr;
        int nextIndex;
        int capacity;

    public:
        Stack() {
            capacity = 100;
            arr = new int[100];
            nextIndex = 0;
        }

        Stack(int size) {
            capacity = size;
            arr = new int[size];
            nextIndex = 0;
        }

        // Basics Funcions

        int size() {
            return nextIndex;
        }

        bool isEmpty() {
            return nextIndex == 0;
        }

        void push(int val) {
            if(nextIndex == capacity) {
                cout<<"Stack is full"<<"\n";
                return;
            }
            arr[nextIndex++] = val;
        }

        void pop() {
            if(this->isEmpty()) {
                cout<<"Stack is already Empty"<<"\n";
                return;
            }
            nextIndex--;
        }

        int top() {
            if(nextIndex > 0) {
                return arr[nextIndex-1]; 
            }

            return -1;
        }
};

int main() {
    Stack s(5);
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    
    // if(s.isEmpty() == true) {
    //     cout<<"Empty"<<"\n";
    // }

    // else {
    //     cout<<"Not Empty"<<"\n";
    // }

    // s.pop();
    // cout<<s.size()<<"\n";
    // cout<<s.top()<<"\n";
    // s.push(50);
    // s.push(60);
    // s.push(70);
    // cout<<s.top()<<"\n";
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.top()<<"\n";
    // s.pop();

    Stack s1(10);

    for(int i = 1 ; i<=10 ; i++) {
        s1.push(i);
    }

    while(!s1.isEmpty()) {
        cout<<s1.top()<<" ";
        s1.pop();
    }

    return 0;
}