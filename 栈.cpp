#include <iostream>
using namespace std;

class stack {
public:
    int* sp, top, max;
    void inflate(int lengh) {
        max++;
    }
    stack(stack& s)
    {
        top = s.top;
        max = s.max;
        sp = new int[max];
        for (int i = top - 1; i >= 0; i--)
        {
            sp[i] = s.pop();
        }
    }
    ~stack()
    {
        cout << "hh" << endl;
    }
public:
    stack(int size = 10) :max(size) {
        sp = new int[max];
        top = -1;
    }
    int pop() {
        if (top == -1)
            return -1;
        else
            return sp[top--];
    }
    void push(int value) {
        sp[++top] = value;
        //        cout<<sp[top]<<" ";
        //        if(top==max-1)
        //            inflate(1);
    }
    stack& operator=(stack& rightValue) {
        max = rightValue.max;
        top= rightValue.top;
        sp = new int[rightValue.max];
        for (int i = 0; i < rightValue.max; i++) {
            sp[i] = rightValue.sp[top--];
        }
        for (int i = 0; i < this->max; i++)
            this->push(sp[i]);
        return *this;//·µ»Ø×ÔÉí 
    }
    void show() {
        while (top != -1)
            cout << pop();
        cout << endl;
    }
};
int main(int argc, const char* argv[]) {
    int max1, max2, n;
    cin >> max1 >> max2;
    stack a(max1), b(max2);
    for (int i = 0; i < max1; i++) {
        cin >> n;
        a.push(n);
    }
    for (int i = 0; i < max2; i++) {
        cin >> n;
        b.push(n);
    }
    if (max1 > max2) {
        a.max = b.max;
        int cnt = max1 - max2;
        while (cnt--)
            a.pop();
    }
    else {
        b.max = a.max;
        int cnt = max2 - max1;
        while (cnt--)
            b.pop();
    }
    stack q, p;
    q = a;
    q.show();
    a = b;
    //a.show();
    p = q;
    // p.show();
    b = p;
    //b.show();
    //a.show();
    //b.show();
    return 0;
}