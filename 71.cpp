#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

bool isPrime(int);
int gcd(int,int);

class Key{
public:
    int N;
    int e;
    int d;

    Key(int N_in, int e_in, int d_in){
        N = N_in;
        e = e_in;
        d = d_in;
    }
};

Key make_random_key(int n){
    int p, q;

    do {
        do{
            p = rand() % 100;
        }while (!isPrime(p));
        do{
            q = rand() % 100;
        }while (!isPrime(p));
    } while (p*q < pow(2, n));

    int N = p*q;
    int m = (p - 1) * (q - 1);
    int e;

    do {
        e = rand() % m + 1;
    } while (gcd(e,m) != 1 || (!(e < m)));

    int d = 1;
    Key key(N, e, d);
    return key;
}

vector<char> rsa(...) {
    /*still need time to figure this out...*/
}

int main() {
    srand(time(NULL));

    vector<char> encryption;
    encryption.push_back('S');
    encryption.push_back('a');
    encryption.push_back('D');
    encryption.push_back('S');

    Key key = make_random_key(4);

    vector<char> test_msg_1 = rsa(key,encryption,true);
    vector<char> test_msg_2 = rsa(key,test_msg_1,true);

    if(test_msg_1 == test_msg_2)
        cout << "Encryption passed..." << endl;
    else
        cout << "Encryption failed..." << endl;

    return 0;
}

bool isPrime(int n)
{
    if (n == 2)                 return true;
    if (n < 2 || n % 2 == 0)    return false;

    for(int i = 3; (i*i) <= n; i += 2)
    {
        if (n % i == 0) return false;
    }

    return true;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

