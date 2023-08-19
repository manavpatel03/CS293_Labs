#include <iostream>
#include <queue>
using namespace std;

int main()
{
    long long int n;
    int count = 0;
    queue<int> Q;
    cin >> n;
    while (n != 1)
    {
        Q.push(n % 256);
        n /= 256;
        count++;
    }
    char *S = new char(count + 1);
    for (int i = 0; i < n; i++)
    {
        S[i] = Q.front();
        Q.pop();
    }
    cout << S;
}