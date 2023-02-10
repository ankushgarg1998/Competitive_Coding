#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

string caesar_cipher(string text, int shift) {
    string cipher = "";
    loop(i, 0, text.size()) {
        int ch = text[i] - 'A';
        ch = (ch + shift) % 26;
        if(ch < 0)
            ch += 26;
        cipher += char(ch + 'A');
    }
    return cipher;
}

int main() {
    string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int shift = 23, textlen = text.size();

    string cipher = caesar_cipher(text, shift);
    cout<<cipher<<"\n";

    string ret = caesar_cipher(cipher, shift*-1);
    cout<<ret<<"\n";
}