class Solution
{
public:
    int countStrings(int n)
    {
        // Based on the derivation: Total(n) = Total(n-1) + Total(n-2)
        // This is essentially the (n+2)th Fibonacci number.

        if (n == 1)
            return 2;
        if (n == 2)
            return 3;

        long long a = 2; // Total strings for n=1
        long long b = 3; // Total strings for n=2
        long long total = 0;

        for (int i = 3; i <= n; i++)
        {
            total = a + b;
            a = b;
            b = total;
        }

        return (int)total;
    }
};