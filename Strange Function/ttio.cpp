#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long inv2 = (MOD + 1) / 2;

long long bin_mod(const string& s) {
    long long r = 0;
    for (char c : s) r = (r * 2 + (c - '0')) % MOD;
    return r;
}

long long g(const string& s) {
    if (s == "0") return 0;
    long long B = bin_mod(s);
    int b = s.back() - '0';
    return (3LL * B % MOD - b + MOD) % MOD * inv2 % MOD;
}

string conv(const string& s) {
    string r = s;
    for (char& c : r) c = ((c - '0') % 2 == 1) ? '1' : '0';
    size_t i = r.find_first_not_of('0');
    if (i == string::npos) return "0";
    return r.substr(i);
}

bool is01(const string& s) {
    for (char c : s) if (c != '0' && c != '1') return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string x;
        cin >> x;
        if (x == "0") { cout << 0 << '\n'; continue; }
        long long ans;
        if (is01(x)) {
            ans = g(x);
        } else {
            string c = conv(x);
            ans = (1 + g(c)) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}