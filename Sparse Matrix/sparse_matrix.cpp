#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define PI 3.1415926535
#define testcase long long int t; cin>>t; while(t--)

class Element {
    public:
        int i;
        int j;
        int num;
};

class Sparse {
    private:
        int m;
        int n;
        int size;
        Element *ele;

    public:
        Sparse(int m , int n , int size) {
            this->m = m;
            this->n = n;
            this->size = size;
            ele = new Element[this->size];
        }

        ~Sparse() {
            delete [] ele;
        }

        void read() {
            cout<<"Enter non-zero elements\n";

            for(int i = 0 ; i<size ; i++) {
                cin>>ele[i].i>>ele[i].j>>ele[i].num;
            }
        }

        void display() {
            cout<<"\nSparse Matrix :-\n";
            int k = 0;
            for(int i = 0 ; i<m ; i++) {
                for(int j = 0 ; j<n ; j++) {
                    if(ele[k].i == i && ele[k].j == j) {
                        cout<<ele[k].num<<" ";
                        k++;
                    }
                    else {
                        cout<<0<<" ";
                    }
                }
                cout<<"\n";
            }
        }
};


int main() {
    Sparse s1(5,5,5);
    s1.read();
    s1.display();
    return 0;
}