#include <iostream>
#include <queue>
using namespace std;

int main()
{
    long long int n;
    queue<int> Q;
    cin >> n;
    int x;
    while (n > 1)
    {
        x = n % 256;
        Q.push(x);
        cout << x << endl;
        n = n/256;
    }
    char S[Q.size() + 1];
    int size = Q.size();
    for (int i = 0; i < size; i++)
    {
        S[i] = char(Q.front());
        Q.pop();
    }
    cout << endl;
    for(int i = size;i >= 0;i--) cout << S[i];
}