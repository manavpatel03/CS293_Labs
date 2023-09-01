#include <iostream>
#include <algorithm>
#include "hash.h"
using namespace std;

string crackOne(size_t hash) {
    string ans = ">e you up";
    if( insecureHashOne(ans) != hash ) cout << "Hash mismatch!\n";
    return ans;
}

string crackTwo(size_t hash) {
    string ans = "";
    if( insecureHashTwo(ans) != hash ) cout << "Hash mismatch!\n";
    return ans;
}


string crackThree(size_t hash) {
  string ans = "";
  if( insecureHashThree(ans) != hash ) cout << "Hash mismatch!\n";
  return ans;
}

string crackFour(size_t hash) {
  string ans = "";
  if( insecureHashFour(ans) != hash ) cout << "Hash mismatch!\n";
  return ans;
}

string crackFive(size_t hash) {
  string ans = "";
  if( insecureHashFive(ans) != hash ) cout << "Hash mismatch!\n";
  return ans;
}

string crackSix(size_t hash) {
  string ans = "";
  if( insecureHashSix(ans) != hash ) cout << "Hash mismatch!\n";
  return ans;
}


int main (int argc, char* argv[]) {
    size_t hash;
    string ans, hint;
    int choice;
    cout<< "Choose hash function:";
    cin >> choice;
    if (choice == 1) {
        hash = PASSWORD_HASH_ONE;
        ans = "Password: \"" + crackOne(hash) + "\"";
    }
    else if (choice == 2) {
        hash = PASSWORD_HASH_TWO;
        ans = "Password: \"" + crackTwo(hash) + "\"";
    }
    else if (choice == 3) {
        hash = PASSWORD_HASH_THREE;
        ans = "Password: \"" + crackThree(hash) + "\"";
    }
    else if (choice == 4) {
        hash = PASSWORD_HASH_FOUR;
        ans = "Password: \"" + crackFour(hash) + "\"";
    }
    else if (choice == 5) {
        hash = PASSWORD_HASH_FIVE;
        ans = "Password: \"" + crackFive(hash) + "\"";
    }
    else if (choice == 6) {
        hash = PASSWORD_HASH_SIX;
        ans = "Password: \"" + crackSix(hash) + "\"";
    }
    cout << ans << endl;
}
