#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

unsigned long long int NaiveFibonacci(int n){
    unsigned long long result = 0 ;
    if(n == 0){
        result = 0;
    }

    else if(n==1){
        result = 1;
    }

    else{
        result = NaiveFibonacci(n-1) + NaiveFibonacci(n-2);
    }

    return result;
}

unsigned long long int FastFibonacci(int n){
    vector<unsigned long long int> numbers(n+1);
    numbers[0] = 0;
    if(n == 0){
        return numbers[n];
    }

    else if(n==1){
        numbers[1] = 1;
        return numbers[n];
    }

    else{
        numbers[1] =1;
        for(int i=2; i<=n; i++){
            numbers[i] = numbers[i-1] + numbers[i-2];
        }
        return numbers[n];
    }
}

void StressTest(){
    while (true)
    {
        int n = rand() % 50;
        unsigned long long int result1=0;
        unsigned long long int result2=0;

        result1 = NaiveFibonacci(n);
        result2 = FastFibonacci(n);

        if(result1 == result2){
            cout << n << " ";
            cout << "OK" << "\n";
        }

        else{
            cout << n << " ";
            cout << "Error: Wrong Answer" << "\n";
            cout << result1 << " " << result2 << "\n";
        }
    }
    
}

int main(){
    //Get the fibonacci number
    //StressTest();
    unsigned long long int result1=0;
    unsigned long long int result2=0;
    int n;
    cin >> n;

    //Naive solution
    //result1 = NaiveFibonacci(n);
    result2 = FastFibonacci(n);
    cout << n << "th fibonacci number is: " << result2 << "\n";
    return 0;
}