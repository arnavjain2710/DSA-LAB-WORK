#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int hashTable[TABLE_SIZE];

void initializeHashTable()
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        hashTable[i] = -1;
    }
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int value)
{
    int index = hashFunction(value);
    if (hashTable[index] == -1)
    {
        hashTable[index] = value;
    }
    else
    {
        int i = 1;
        int newIndex;
        int counter = 0;
        while (true)
        {
            newIndex = hashFunction(index + i);
            if (hashTable[newIndex] == -1)
            {
                hashTable[newIndex] = value;
                break;
            }
            counter++;
            if(counter >= 10)
            {
                cout<<"No more space available"<<endl;
                return;
            }
            i++;
        }
    }
}

void displayHashTable()
{
    cout << "Hash Table:" << endl;
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        cout << "[" << i << "]: ";
        if (hashTable[i] != -1)
        {
            cout << hashTable[i];
        }
        cout << endl;
    }
}

int main()
{
    initializeHashTable();

    int values[] = {2, 4, 12, 26, 34, 26, 6, 14, 8, 10 ,11};
    for (int i = 0; i < TABLE_SIZE+1; ++i)
    {
        insert(values[i]);
    }

    displayHashTable();

    return 0;
}
