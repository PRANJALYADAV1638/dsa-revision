#include <iostream>
using namespace std;

class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1.0;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        return power(x, N);
    }
};

int main() {
    Solution obj;

    double x;
    int n;

    cout << "Enter base: ";
    cin >> x;

    cout << "Enter exponent: ";
    cin >> n;

    cout << "Answer = " << obj.myPow(x, n) << endl;

    return 0;
}