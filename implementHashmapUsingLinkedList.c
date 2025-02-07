#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
int size = 0;

typedef struct HashMap
{
    int key;
    int value;
    struct HashMap *next;
} HashMap;

HashMap *createHashMap(int key, int value)
{
    HashMap *hashmap = (HashMap *)malloc(sizeof(HashMap));
    hashmap->key = key;
    hashmap->value = value;
    hashmap->next = NULL;
    return hashmap;
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insertAtEnd(HashMap *hashmap, int key, int value)
{
    HashMap *temp = hashmap;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createHashMap(key, value);
}

void deleteKeyFromMap(HashMap **map, int key)
{
    HashMap *temporaryHashMap = *map;
    if (temporaryHashMap == NULL)
    {
        printf("None\n");
        return;
    }
    if (temporaryHashMap->key == key)
    {
        printf("Key %d deleted\n", temporaryHashMap->key);
        *map = (*map)->next;
        temporaryHashMap->next = NULL;
        free(temporaryHashMap);
        return;
    }
    while (temporaryHashMap->next != NULL && temporaryHashMap->next->key != key)
    {
        temporaryHashMap = temporaryHashMap->next;
    }
    if (!temporaryHashMap->next)
    {
        printf("None\n");
        return;
    }
    HashMap *toDelete = temporaryHashMap->next;
    temporaryHashMap->next = toDelete->next;
    toDelete->next = NULL;
    printf("Key %d deleted\n", toDelete->key);
    free(toDelete);
}

void search(HashMap *map, int key)
{
    if (map == NULL)
    {
        printf("None\n");
        return;
    }
    HashMap *tempMap = map;
    while (tempMap != NULL && tempMap->key != key)
    {
        tempMap = tempMap->next;
    }
    if (!tempMap)
    {
        printf("None\n");
        return;
    }
    printf("Value: %d\n", tempMap->value);
}

void display(HashMap **table)
{
    printf("Hash Table:\n");
    for (int index = 0; index < 10; index++)
    {
        if (table[index] == NULL)
        {
            continue;
        }
        HashMap *tempMap = table[index];
        printf("Index %d:(%d,%d)", index, tempMap->key, tempMap->value);
        tempMap = tempMap->next;
        while (tempMap != NULL)
        {
            printf("->(%d,%d)", tempMap->key, tempMap->value);
            tempMap = tempMap->next;
        }
        printf("\n");
    }
}

int main()
{
    HashMap **hashTable = (HashMap **)calloc(TABLE_SIZE, sizeof(HashMap));
    int key, value, choice, index;
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            index = hashFunction(key);
            printf("Enter the value: ");
            scanf("%d", &value);
            if (!hashTable[index])
            {
                hashTable[index] = createHashMap(key, value);
            }
            else
            {
                insertAtEnd(hashTable[index], key, value);
            }
            printf("\n");
            break;

        case 2:
            printf("Enter key:");
            scanf("%d", &key);
            index = hashFunction(key);
            search(hashTable[index], key);
            printf("\n");
            break;

        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            index = hashFunction(key);
            deleteKeyFromMap(&hashTable[index], key);
            printf("\n");
            break;

        case 4:
            display(hashTable);
            printf("\n");
            break;

        case 5:
            printf("Exiting.\n");
            return 0;
        }
    }

    return 0;
}