#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {

    private:
    
        T *arr;
        int nextIndex;
        int capacity;

    public:
    
        Stack() {
            capacity = 4;   
            arr = new T[4];
            nextIndex = 0;
        }

        // Basics Funcions  

        int size() {
            return nextIndex;
        }

        bool isEmpty() {
            return nextIndex == 0;
        }

        void push(T val) {
            if(nextIndex == capacity) {
                T *temp = new T[2*capacity];

                for(int i = 0 ; i<capacity ; i++) {
                    temp[i] = arr[i];
                }

                delete [] arr;
                arr = temp;
                capacity = 2*capacity;
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

        T top() {
            if(nextIndex > 0) {
                return arr[nextIndex-1]; 
            }

            return 0;
        }

}; 

int main() {

    Stack<int> s;
    for(int i = 1 ; i<=6 ; i++) {
        s.push(i);
    }

    cout<<s.top()<<"\n";
    return 0;
}