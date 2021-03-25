#include<bits/stdc++.h>
using namespace std;

int main(){
    // Setting the lowest and max value
    int lowestValue = numeric_limits<int>::min();

    // Setting the maximum value
    int maximumValue = numeric_limits<int>::max();

    // Set precision point in cpp
    double pi = 3.14159, npi = -3.14159; 
    cout << fixed << setprecision(0) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(1) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(2) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(3) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(4) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(6) << pi <<" "<<npi<<endl; 
    return 0;
}