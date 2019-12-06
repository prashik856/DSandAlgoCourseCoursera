#include<iostream>
#include<vector>
#include<cstdlib>

using std::cin;
using std::cout;
using std::vector;

long long MaximumProduct(const vector<int>& numbers){
    long long result = 0;
    int n = numbers.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(((long long)numbers[i])*numbers[j] > result){
                result = ((long long)numbers[i])*numbers[j];
            }
        }
    }
    return result;
}

long long MaximumProductFast(const vector<int>& numbers){
    long long result=0;
    int n = numbers.size();
    int max_index1 = -1;
    for(int i=0; i<n; i++){
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1])){
            max_index1 = i;
        }
    }
    //cout << max_index1 << " " << numbers[max_index1] << "\n";

    int max_index2 = -1;
    for(int i=0; i<n; i++){
        if( (i != max_index1) && ((max_index2==-1)||(numbers[i]>numbers[max_index2]))){
            max_index2 = i;
        }
    }
    //cout << max_index2 << " " << numbers[max_index2] << "\n";

    result = ((long long)numbers[max_index1])* numbers[max_index2];
    return result;
}

void StressTest(){
    //Stress Test
    //Generating Random tests
    while(true){

        //Generating random number of array
        // Since we need atleast 2, we are adding 2
        //Getting random number between 0 to 10
        int n = rand() % 10000 + 2;
        cout << n << "\n";

        //Generating the random array (between 0 to 99999)
        vector<int> a;
        for(int i=0; i<n; i++){
            a.push_back(rand() % 100000);
        }
        //Printing array
        for(int i=0; i<n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";

        //Getting correct and fast answer
        long long res1 = MaximumProductFast(a);
        long long res2 = MaximumProduct(a);

        //Outputting wrong answer and breaking our while loop
        if(res1 != res2){
            cout << "Wrong Answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        //Answers are okay
        else{
            cout << "Ok\n";
        }
    }
}

int main(){
    //StressTest();

    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    long long result = MaximumProductFast(numbers);
    cout << result << "\n";
    return 0;
}