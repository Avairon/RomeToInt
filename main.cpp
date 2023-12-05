#include <iostream>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

map <char, int> rti;
map <int, char> itr;

void start(){
    itr[1] = 'I';   rti['I'] = 1;
    itr[5] = 'V';   rti['V'] = 5;
    itr[10] = 'X';  rti['X'] = 10;
    itr[50] = 'L';  rti['L'] = 50;
    itr[100] = 'C'; rti['C'] = 100;
    itr[500] = 'D'; rti['D'] = 500;
    itr[1000] = 'M';rti['M'] = 1000;
}


int rimToInt(char* str){
    int out = 0;
    int len = strlen(str);
    //cout << len;

    for(int i = 0; i < len; i++){

        if(rti[str[i - 1]] < rti[str[i]] and i != 0) out += rti[str[i]] - rti[str[i - 1]];
        else if(rti[str[i]] >= rti[str[i + 1]]) out += rti[str[i]];
        
    }

    return out;
}

char* intToRim(int number){
    vector<char> outPreq;
    char* out = new char[256];

    int a = number;
    int razrCounter = 0;
    int des = 1000;

    do{
        if(a / 1000 >= 1){
            razrCounter = a / 1000;
            for(int i = 0; i < razrCounter; i++){
                outPreq.push_back(itr[des]);
            }
            a = a % des;
        }
        if(a / des >= 1){
            razrCounter = a / des;
            if(a < 1000){
                if(razrCounter == 9){
                    outPreq.push_back(itr[des]);
                    outPreq.push_back(itr[des * 10]);
                    razrCounter -= 9;
                }
                if(razrCounter == 4){
                    outPreq.push_back(itr[des]);
                    outPreq.push_back(itr[des * 5]);
                    razrCounter -= 4;                    
                }
                if(razrCounter > 4) {
                    outPreq.push_back(itr[des * 5]);
                    razrCounter -= 5;
                }
            }
            
            for(int i = 0; i < razrCounter; i++){
                outPreq.push_back(itr[des]);
            }
            a = a % des;
        }
        des = des / 10;
    }
    while(a > 0);

    for(int i = 0; i < outPreq.size(); i++){
        out[i] = outPreq[i];
    }

    return out;
}

int main(){
    start();
    char* inputChar = new char[256];
    int input;

    cout << "Insert rome number\n";
    cin >> inputChar;
    cout << rimToInt(inputChar) << '\n';

    cout << "Insert arabic number\n";
    cin >> input;
    cout << intToRim(input) << '\n';
}