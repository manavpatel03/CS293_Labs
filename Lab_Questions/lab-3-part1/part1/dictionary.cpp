#include "dictionary.h"
#include "cmath"

Dictionary::Dictionary(){
    A = new Entry[N];
    for(int i = 0;i < N;i++)
        {
            A[i].key = NULL;
        }
};


int Dictionary::hashValue(char key[]){
    int hashValue = 0;
    long long int poly = 0;
    int i = 0;
    while(key[i] != NULL)
        {
            poly += (int(key[i]) * pow(31,i)); 
            i++;
        }
    double pol = poly * (sqrt(5) - 1) / 2;
    pol = pol - int(pol);
    hashValue = int(floor(N * pol));
    return hashValue;
}

int Dictionary::findFreeIndex(char key[]){
    int hash_val = hashValue(key);
    if(A[hash_val].key == NULL) return hash_val;

    return -1;
}

struct Entry* Dictionary::get(char key[]){
    return NULL;
}

bool Dictionary::put(Entry e) {
    return false; // Dummy return
}

bool Dictionary::remove(char key[]){
    return false; // Dummy return
}
