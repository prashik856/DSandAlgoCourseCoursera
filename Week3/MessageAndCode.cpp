//You are given a message and code. You need to find if the characters in the message can be found in the same order in the code.
#include<iostream>
#include<vector>

using namespace std;

bool MessageAndCode(string message, string code){
    bool result = true;
    int messageSize = message.length();
    int codeSize = code.length();
    int i=0, j=0;
    while(i<messageSize){
        char m = message[i];
        while(j<codeSize){
            if(m == code[j]){
                //character found
                //break this while loop and increase i
                i++;
                j++;
                if(i == messageSize){
                    return true;
                }
                break;
            }
            j++;
        }
        if(j>=codeSize){
            return false;
        }
    }
    return result;
}

int main(){
    string message;
    string code;
    cin >> message;
    cin >> code;
    bool result = MessageAndCode(message, code);
    if(result){
        cout << "OK" << endl;
    }
    else{
        cout << "Not Present" << endl;
    }
    return 0;
}