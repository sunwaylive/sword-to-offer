#include <iostream>
#include <stack>
using namespace std;

stack<int> in;
stack<int> out;

void push(int x){
    in.push(x);
}

int pop(){
    if(out.empty()){
	//copy data from in
	while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    //after copy data
    if(out.empty()) return -1;
    else {
	int ret = out.top();
	out.pop();
        return ret;
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--){
	string opcode;
	cin>>opcode;
	if(opcode[1] == 'U'){
            int opvalue;
            cin>>opvalue;
            push(opvalue);
        }else{
            cout<<pop()<<endl;
        }
    }
    return 0;
}
