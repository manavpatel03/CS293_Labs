#include "dictionary.h"
#include "cmath"

bool comp(char *a, char *b)
{
    for (int i = 0; i < 32; i++)
        if (a[i] != b[i])
            return false;
    return true;
}

Dictionary::Dictionary()
{
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
    while (key[i] != NULL)
    {
        poly += (int(key[i]) * pow(31, i));
        i++;
    }
    double pol = poly * (sqrt(5) - 1) / 2;
    pol = pol - int(pol);
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
            if (A[i].key == NULL || A[i].key[0] == 0)
                return i;
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
        if (hashValue(A[i].key) == hash && A[i].key[0] != 0)
            return &A[i];
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
        if (hashValue(A[i].key) == hash_value && A[i].key[0] != 0)
        {
            A[hash_value].key[0] = '\0';
            return true;
        }
        i++;
    }
    return false;
}
