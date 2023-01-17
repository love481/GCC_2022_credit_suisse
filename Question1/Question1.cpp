#include<bits/stdc++.h>
using namespace std;
string solution(long n) {
     if (n<0) return "-1";
    if (!(n % 4)) return "BUY";
    if (!(n % 2)) return "PASS";
    else return "SELL";
}
int main() {
	long n;
	cin >> n;	
	cout << solution(n) << "\n";
}