#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        if(n < 0) break;
        if(n < 3){
            cout<<"Pity!"<<endl<<"#"<<endl;
            continue;
        }

        int low = 1, high = 2;
        int sum = 3;
        int half = n / 2;
        bool flag = false;
        //cout<<"n: "<<n<<endl;
        while(low <= half){
            if(sum < n){
                high++;
                sum += high;
            }else if(sum > n){
                sum -= low; //minus first!
                low++;
            }else if(sum == n){
                flag = true;
                for(int i = low; i < high; ++i)
                    cout<<i<<" ";
                cout<<high <<endl;
                //change high or low are both ok
                high++;
                sum += high;
                //sum -= low;//minus first!
                //low++;
            }
        }
        if(!flag) cout<<"Pity!"<<endl;
        cout<<"#"<<endl;
    }
    return 0;
}
