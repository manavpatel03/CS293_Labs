#include "dictionary.h"
#include "cmath"

bool comp(char *a, char *b)
{
    if(a[0] == 0 || b[0] == 0 || a == NULL || b == NULL)  return false;
    for (int i = 0; i < 32 && a[i] != 0 && b[i] != 0; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

Dictionary::Dictionary()
{
    N = DICT_SIZE;
    A = new Entry[N];
    for (int i = 0; i < N; i++)
    {
        A[i].key = NULL;
    }
};

int Dictionary::hashValue(char key[])
{
    int hashValue = 0;
    long long int poly = 0;
    int i = 0;
    while (key[i] != 0)
    {
        poly += (int(key[i]) * pow(33, i));
        i++;
    }
    double pol = poly * (sqrt(5) - 1) / 2;
    pol = pol - floor(pol);
    hashValue = int(floor(N * pol));
    return hashValue;
}

int Dictionary::findFreeIndex(char key[])
{
    int hash_val = hashValue(key);
    if (A[hash_val].key == NULL || A[hash_val].key[0] == 0)
        return hash_val;
    else
    {
        int i = hash_val + 1;
        while (i % N != hash_val)
        {
            if (A[i % N].key == NULL || A[i % N].key[0] == 0)
                return i % N;
            else if(comp(A[i].key,key)) return i%N;
       }
    }

    return -1;
}

struct Entry *Dictionary::get(char key[])
{
    int i = hashValue(key);
    int hash = i;
    if (comp(A[i].key, key))
        return &A[i];
    i++;
    while (i % N != hash)
    {
        if(A[i%N].key == NULL || key == NULL ||A[i % N].key[0] == 0) return NULL;
        if (hashValue(A[i % N].key) == hash && A[i % N].key[0] != 0)
            return &A[i % N];
        i++;
    }
    return NULL;
}

bool Dictionary::put(Entry e)
{
    int index = findFreeIndex(e.key);
    if (index == -1)
        return false;
    A[index].key = e.key;
    A[index].value = e.value;
    return true;
}

bool Dictionary::remove(char key[])
{
    int hash_value = hashValue(key);
    int i = hash_value;
    if (hashValue(A[hash_value].key) == hash_value)
    {
        A[hash_value].key[0] = '\0';
        return true;
    }
    i++;
    while (i % N != hash_value)
    {
        if(A[i%N].key == NULL || A[i % N].key[0] == 0) return false;
        if (hashValue(A[i%N].key) == hash_value && A[i%N].key[0] != 0)
        {
            A[i%N].key[0] = '\0';
            return true;
        }
        i++;
    }
    return false;
}
