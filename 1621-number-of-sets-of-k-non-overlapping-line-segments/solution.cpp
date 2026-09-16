#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;

        // Compute C(total, r) % MOD using multiplication and modular inverse
        long long num = 1;
        long long den = 1;

        for (int i = 1; i <= r; ++i) {
            num = (num * (total - i + 1)) % MOD;
            den = (den * i) % MOD;
        }

        // Compute den^(MOD - 2) % MOD using Fermat's Little Theorem
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        return (num * power(den, MOD - 2)) % MOD;
    }
};
