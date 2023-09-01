#include <iostream>
#include <vector>
using namespace std;

// Function to find all combinations whose product is equal to 'target'
void findCombinations(vector<int>& current, long long int start, long long int remaining, vector<int>& factors) {
    if (remaining == 1) {
        char ans[factors.size() + 1];
        int size = factors.size();
        int index = 0;
        for (int i = 0; i < size; ++i) {
            if (factors[i] <= 255) {
                ans[index++] = static_cast<char>(factors[i]);
            } else {
                size--;
            }
        }
        for (int i = 0; i < size; ++i) {
            cout << ans[i];
        }
        cout << endl;
        return;
    }

    for (long long int i = start; i <= remaining; ++i) {
        if (remaining % i == 0) {
            current.push_back(i);  // Include i in the combination
            factors.push_back(i);  // Add to the factors vector
            findCombinations(current, i, remaining / i, factors);  // Recurse with reduced remaining
            current.pop_back();  // Backtrack to explore other possibilities
            factors.pop_back();  // Remove from the factors vector
        }
    }
}

int main() {
    long long int target = 14300129759786736;
    target = target / 5381;
    vector<int> currentCombination;
    vector<int> factors;
    findCombinations(currentCombination, 2, target, factors);  // Start from 2, as 1 isn't useful

    return 0;
}
