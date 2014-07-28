#include <iostream>
using namespace std;

class Temp{
public:
    static int sum;
    static int n;
    Temp(){ n++; sum += n; }

    static void reset(){
        n = 0;
        sum = 0;
    }
};

int Temp::n = 0;
int Temp::sum = 0;

// int main()
// {
//     int n;
//     while(cin>>n){
//         Temp::reset();
//         Temp *array = new Temp[n];
//         delete[] array;
//         cout<<Temp::sum<<endl;
//     }
//     return 0;
// }


//method two, virtual function
//************************************************************
class Base;
Base* Array[2];

class Base{
public:
    virtual int sum(int n){
        return 0;
    }
};

class Derived : public Base{
public:
    virtual int sum(int n){
        return Array[!!n]->sum(n - 1) + n;
    }
};

int main()
{
    int n;
    while(cin>>n){
        Base *b = new Base();
        Derived *d = new Derived();
        Array[0] = b;
        Array[1] = d;
        int result = Array[1]->sum(n);
        cout<<result<<endl;
    }
    return 0;
}
