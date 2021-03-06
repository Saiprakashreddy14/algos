// Stress test generator for Last Digit of the Sum of Fibonacci Numbers problem.

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> f = {0, 1};

int fibsum(long long n)
{
    return (
               // (n / f.size()) * accumulate(f.begin(), f.end(), 0) +
               // As sum(f) % 10 == 0, remove above line
               accumulate(f.begin(), f.begin() + (n % f.size() + 1), 0)) %
           10;
}

int main()
{
    int curr;
    long long n;
    for (int i = 2; i <= 100; i++)
    {
        curr = (f[i - 1] + f[i - 2]) % 10;
        if (curr == 0 && f[i - 1] == 1)
        {
            break;
        }
        f.push_back(curr);
    }
    cin >> n;
    cout << fibsum(n) << endl;
    return 0;
}