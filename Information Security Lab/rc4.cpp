#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

void printv(const vector<int> &v) {
    for(auto x: v)
        cout<<x<<" ";
    cout<<"\n\n";
}

string rc4(string text, vector<int> &key) {
    string ans = "";
    loop(i, 0, text.size()) {
        ans += (char)((int)text[i] ^ key[i]);
    }
    return ans;
}

int main() {
    string key = "JaiMataDi", text = "HELLO WORLD!";
    int keylen = key.size(), textlen = text.size();
    
    // vector initialization
    vector<int> S(256), T(256);
    loop(i, 0, 256) {
        S[i] = i;
        T[i] = key[i%keylen];
    }

    // key-generation algorithm (KGA)
    int j=0;
    loop(i, 0, 256) {
        j = (j + S[i] + T[i]) % 256;
        swap(S[i], S[j]);
    }

    // pseudo-random generation algorithm (PRGA)
    int i=0; j=0;
    vector<int> prk(textlen);
    loop(x, 0, textlen) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        prk[x] = S[(S[i] + S[j]) % 256];
    }

    // RC4 encryption
    string cipherText = rc4(text, prk);
    cout<<cipherText<<"\n\n";

    // RC4 decryption
    string retreivedText = rc4(cipherText, prk);
    cout<<retreivedText<<"\n\n";

    return 0;
}