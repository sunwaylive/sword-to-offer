#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

class MyStack{
private:
    stack<int> value;
    stack<int> minimum;

public:
    MyStack() {}

    void pop(){
        if(this->value.empty()) return;

        int t = this->value.top();
        this->value.pop();
        if(!this->minimum.empty() && t <= this->minimum.top())
            this->minimum.pop();
    }

    void push(int val){
        this->value.push(val);
        if(this->minimum.empty() || val < this->minimum.top())
            this->minimum.push(val);
    }

    void getMin(){
        if(!this->minimum.empty())
            printf("%d\n", this->minimum.top());
        else
            printf("NULL\n");
    }
};

int main()
{
    int n;
    while(cin>>n){
        MyStack *stk = new MyStack;
        char op;
        int value;
        while(n--){
            cin>>op;
            if(op == 's'){
                cin>>value;
                stk->push(value);
                stk->getMin();
            }else if(op == 'o'){
                stk->pop();
                stk->getMin();
            }
        }
    }

    return 0;
}
