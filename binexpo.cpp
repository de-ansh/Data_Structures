#include<bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
	long long  base, y,n;
	cin>>base>>y>>n;
	long long expo=binpow(base,y,n);
	cout<<expo;
	return 0;
}
