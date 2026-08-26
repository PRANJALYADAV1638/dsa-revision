#include <iostream>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);
        long long ans = (half * half) % MOD;

        if (n % 2)
            ans = (ans * x) % MOD;

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % MOD;
    }
};

int main() {
    Solution obj;

    long long n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Count of Good Numbers = " << obj.countGoodNumbers(n) << endl;

    return 0;
}