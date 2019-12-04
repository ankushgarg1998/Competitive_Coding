#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;


string mc(string text, string alphabet, string cipherAlphabet) {
    string cipher = "";
    loop(i, 0, text.size()) {
        cipher += cipherAlphabet[alphabet.find(text[i])];
    }
    return cipher;
}

int main() {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", cipherAlphabet = "KEYWORDABCFGHIJLMNPQSTUVXZ";
    string text = "ALKINDI";

    string cipher = mc(text, alphabet, cipherAlphabet);
    cout<<cipher<<"\n";

    string ret = mc(cipher, cipherAlphabet, alphabet);
    cout<<ret<<"\n";
}