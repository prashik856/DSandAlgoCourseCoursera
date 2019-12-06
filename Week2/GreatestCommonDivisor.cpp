#include<iostream>
#include<cstdlib>

using namespace std;

int NaiveGCD(int a, int b){
    int result = 0;
    
    for(int i=1; i<=b; i++){
        if(a%i==0 && b%i==0){
            result = i;
        }
    }
    return result;
}

int FastGCD(int a, int b){
    int result = 0;
    int remainder = 0;
    if(b==0){
        return b;
    }

    else{
        remainder = a % b;
        cout << a << " " << b << " " << remainder << "\n";
        if(remainder == 0){
            return b;
        }

        else{
            FastGCD(b, remainder);
        }
    }
}

void StressTest(){
    while(true){
        int a,b;
        a = rand() % 100000;
        b = rand() % 100000;
        if(b > a){
            int temp = a;
            a = b;
            b = temp;
        }
        int result1=0, result2=0;
        result1 = NaiveGCD(a,b);
        result2 = FastGCD(a,b);
        if(result1 == result2){
            cout << a << " " << b << "\n";
            cout << "OK\n";
        }
        else{
            cout << a << " " << b << "\n";
            cout << "Wrong Answer" << "\n";
            cout << result1 << " " << result2 << "\n";
            break;
        }
    }
}

int main(){
    //StressTest();
    int a,b;
    cin >> a >> b;
    int result = 0;
    
    if(b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    
    result = FastGCD(a,b);
    cout << "GCD of " << a << " and " << b << " is: " << result << "\n";
    return 0;
}