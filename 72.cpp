#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

/* function prototype */
int HASH(string);

int main() {
    string message = "10011001100011001000110111011101";
    int secret = HASH(message);
    cout << secret << endl;
    return 0;
}

int HASH(string input_msg) {
    while(input_msg.length() % 32 != 0) /*padding zeros until length multiple of 32*/
        input_msg = input_msg + "0";

    vector<string> word;
    for(int i = 0; i < input_msg.length(); i++) {
        string block = "";
        for(int j = 0; j < 32; j++)
            block = block + input_msg[i+j];
        i = i + 32;
        word.push_back(block);
    }

    int secret = 0; /*output hash int value*/
    for(int i = 0; i < word.size(); i++){ /*Main hashing algorithm*/
        int hash_out = 0;
        for(int j = 0; j < 32; j++){
            hash_out = hash_out + ((word[i][32-j-1] == '0') ? 0 : 1)*pow(2,j);
        }
        secret = ((int)pow(secret + 2 + hash_out, 1234567)) % 9993201131;
    }

    return secret;
}
