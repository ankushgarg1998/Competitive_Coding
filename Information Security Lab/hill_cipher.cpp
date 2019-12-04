#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a; i<b; i++)
using namespace std;

string hill_cipher(string text, const vector<vector<int> > &key) {
    string cipher = "";
    loop(i, 0, 3) {
        int ch = 0;
        loop(j, 0, 3)
            ch += key[i][j]*(text[j] - 'A');
        cipher += (char)((ch%26) + 'A');
    }
    return cipher;
}

vector<vector<int> > matrix_inverse(const vector<vector<int> > &v) {
    vector<vector<int> > ans = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    // Matrix inverse modulo 26
    // = MI(det(MAT)) * adj(MAT)
    // MI = Multiplicative inverse mod 26.
    // after every MAT formation every element mod 26.
    return ans;
}

int main() {
    string text = "ACT";
    vector<vector<int> > key {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}}; //GYB NQK URP

    string cipher = hill_cipher(text, key);
    cout<<cipher<<"\n\n";

    vector<vector<int> > key_inverse = matrix_inverse(key);
    string ret = hill_cipher(cipher, key_inverse);
    cout<<ret<<"\n\n";

    return 0;
}