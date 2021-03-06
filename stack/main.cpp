//
//  main.cpp
//  array
//
//  Created by Lee Yi Wei on 2021/6/7.
//

#include <iostream>
//#include <stack>

using namespace std;

/*
class stackarray{
    
private:
    int top; //index of the top
    int size; // stack array size
    int *stack;
    void doublesize(); // double the size if the array full
    
public:
    stackarray():top(0),size(1){
        stack = new int[size];
    }
    
    void push(int x); // push the number to the top
    void pop(); // pop the top number out of the stack
    int Top(); // print out the top number
    bool isEmpty(); // check is the stack empty will return true and false
    int getsize(); // get the array size
    
};

void stackarray::doublesize(){
    size = size *2; //double the size
    int *newstack = new int[size]; // make the new stack size
    
    
    for(int i=0; i <size/2;i++)
    {
        newstack[i] = stack[i]; // move the old data to the new stack
        
    }
    
    delete [] stack;
    stack = newstack;
}

void stackarray::push(int x){
    if(top == size-1)
    {
        doublesize();
    }
    
    stack[++top] = x; //top+1 and input the number
    
    init         push(6)
    |   |        |   |
    |   |        |   |
    |   |        |6  |
    |___|        |___|
    top : 0      top + 1 =top 1 = 6
            
     
}

void stackarray::pop()
{
    if(isEmpty()){
        cout<<"The stack is Empty."<<endl;
        return ;
    }
    top--;
}

int stackarray::Top()
{
    if(isEmpty())
    {
        cout<<"The stack is empty."<<endl;
        
    }
    
    return stack[top];
}

bool stackarray::isEmpty(){
    return top==0; //return true when top is 0
}

int stackarray::getsize()
{
    return top;
    
    init         push(6)
    |   |        |   |
    |   |        |   |
    |   |        |6  |
    |___|        |___|
    size: 0      size: 1
     
}

int main(){
    
    
    //using the stack function
    stack<int> stacknumber;
    
    stacknumber.push(5); //5
    stacknumber.push(6); //6 5
    stacknumber.push(1); //1 6 5
    while(!stacknumber.empty())
    {
        cout<<"The number in stack: "<<stacknumber.top()<<endl;
        stacknumber.pop();
    }
    
    stackarray arr;
    arr.push(6);
    arr.push(12);
    //arr.pop();
    cout<<arr.Top()<<endl;
    cout<<"get size: "<<arr.getsize()<<endl;
    
}
*/


class stacklist; // friend class

class stacknode{
private:
    int data; // data for the list
    stacknode *next; // next
public:
    stacknode():data(0),next(0){}; //set the data = 0 and next = 0
    stacknode(int x):data(x),next(0){}; // if input x than data = x
    stacknode(int x,stacknode *nextnode):data(x),next(nextnode){}; // ???????????????push front???????????????????????????nextnode
    
    friend class stacklist;
    
};

class stacklist{
private:
    stacknode *top; //??????????????????address
    int size; //size
public:
    stacklist():top(0),size(0){}; //??????top = 0 ??? size =0
    void push(int x);
    void pop();
    bool isEmpty();
    int getsize();
    int Top();
};


void stacklist::push(int x)
{
    if(isEmpty()){
        top = new stacknode(x);
        size++;
        return;
    }
    
    stacknode *newnode = new stacknode(x); // make the new node became the number (x)
    newnode->next = top; // ???top push????????????
    top = newnode; // top = new node
    size++; //size +1
    /*
     
        init            push(6)
     ___________        _____________
     |                 |6
     -----------        --------------
     
        size:0             *newnode???address = 6
        top:0               newnode->next ?????????newnode?????????NULL????????????????????????node?????????top
                            ???newnode???????????????top
                            size +1 ???????????????????????????
     */
}

/*??????stack??????first in last out?????????
 ????????????????????????????????????????????????node
 ??????pop????????????????????????node???top->next????????????*/
void stacklist::pop(){
    if(isEmpty()){
        cout<<"The stack list is empty."<<endl;
        return;
    }
    
    stacknode *deletenode = top; //???????????????pointer??????top?????????stack?????????????????????
    top = top->next; //????????????top???????????????
    delete deletenode; //???????????????
    deletenode = 0;
    size --; //???????????????size
}

bool stacklist::isEmpty(){
    return (size==0);
}

int stacklist::Top(){
    if(isEmpty()){
        cout<<"The stack list is empty."<<endl;
        return 0;
    }
    
    return top->data;
}

int stacklist::getsize(){
    return size;
}

int main(){
    stacklist list;
    //list.pop();
    cout<<"The size is: "<<list.getsize()<<endl;
    cout<<"The top is: "<<list.Top()<<endl;
}
