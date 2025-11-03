/*
Write a program to implement a stack using (a) Two queues and (b) One Queue.
*/
#include <iostream>
#include <queue>
using namespace std;

// Stack with two queue

queue<int> q1, q2;

void push1(int x){
    q2.push(x);

    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void pop1(){
    if(q1.empty()){
        cout << "Stack is empty!\n";
        return;
    }
    cout<<"Popped: "<< q1.front()<<endl;
    q1.pop();
}

int top1(){
    if(q1.empty()){
        cout<<"Stack is empty!\n";
        return -1;
    }
    return q1.front();
}

bool empty1(){
    return q1.empty();
}

// Stack with one queue
queue<int> q;

void push2(int x){
    int size=q.size();
    q.push(x);

    for(int i=0;i<size;i++){
        q.push(q.front());
        q.pop();
    }
}

void pop2(){
    if(q.empty()){
        cout<<"Stack is empty!\n";
        return;
    }
    cout<<"Popped: "<< q.front()<<endl;
    q.pop();
}

int top2(){
    if(q.empty()){
        cout<<"Stack is empty!\n";
        return -1;
    }
    return q.front();
}

bool empty2(){
    return q.empty();
}


int main(){
    cout<<"Stack using TWO queues:\n";
    push1(10);
    push1(20);
    push1(30);
    cout<<"Top: "<<top1()<<endl;
    pop1();
    cout<<"Top: "<<top1()<<endl;
    pop1();
    pop1();
    pop1();

    cout<<"\nStack using ONE queue:\n";
    push2(10);
    push2(20);
    push2(30);
    cout<<"Top: "<<top2()<<endl;
    pop2();
    cout<<"Top: "<<top2()<<endl;
    pop2();
    pop2();
    pop2();
}