/*
 * File: hashing_doublehashing.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: November 1, 2023
 * Description: This program implements hashing using using double hashing for collision resolution
 */


// IMPORTANT: Use hash2(x) = 11 - (x % 11) as the 2nd hash function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 23

typedef struct KeyValue {
    char *key;
    char *value;
    bool isDeleted;
} KeyValue;

typedef struct {
    KeyValue **array;
    int size;
    float load_factor;
    // num of keys present
    int num_keys;
    // num of array indices of the table that are occupied
    int num_occupied_indices;
    // num of ops done so far
    int num_ops;
} HashTable;


KeyValue *createKeyValue(char *key, char *value) {
    KeyValue* newKeyValue = (KeyValue*)malloc(sizeof(KeyValue));
    if (newKeyValue != NULL) {
        newKeyValue->key = key;
        newKeyValue->value = value;
    }
    return newKeyValue;
}

HashTable* createHashTable() {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->array = (KeyValue **)malloc(TABLE_SIZE * sizeof(KeyValue *));
    for (int i=0; i<TABLE_SIZE; i++){
        newTable->array[i] = NULL;
    }
    newTable->size = TABLE_SIZE;
    newTable->load_factor = 0;
    newTable->num_keys = 0;
    newTable->num_occupied_indices = 0;
    newTable->num_ops = 0;
    return newTable;
}


// use sum of ascii values to convert string to int
int key_to_int(char* key){
    int hash=0,ind=0;
    while(key[ind]!='\0'){
        hash+=(key[ind]+128);
    }
    hash%=TABLE_SIZE;
    return hash;
}

int secondhash(int x){
    return (11-(x%11));
}

// return the index position in the table where the insertion happens
// return -1 if insertion fails
int insert_key_value(HashTable *ht, char* key, char* value){
    if(ht->num_occupied_indices==TABLE_SIZE){
        return -1;
    }
    int h1=key_to_int(key);
    int retval;
    KeyValue* to_insert=createKeyValue(key,value);
    if(ht->array[h1]==NULL){
        ht->array[h1]=to_insert;
        ht->num_keys++;
        retval=h1;
    }
    else{
        int h2=secondhash(h1);
        int index=(h1+h2)%TABLE_SIZE;
        while(ht->array[index]!=NULL){
            index+=h2;
            index%=TABLE_SIZE;
            if(index==h1){//if index becomes equal to initial value again, it means it has gone into a loop
                return 1;
            }
        }
        ht->array[index]=to_insert;
    }

    ht->num_occupied_indices++;
    ht->num_ops++;
    return retval;
}

// return the value of the key in the table
// return NULL if key not found
char *search_key(HashTable *ht, char* key){
    int h1=key_to_int(key);
    int index=h1;
    if(ht->array[index]!=NULL){
        return ht->array[index]->value;
    }
    else{
        int h2=secondhash(index);
        for(int i=0;i<TABLE_SIZE;i++){//if the item is not found after table_size number of iterations, it means it doesn't exist as the function may have gotten stuck in a loop
            index+=h2;
            if(ht->array[index]==NULL){
                return NULL;
            }
            else if(strcmp(ht->array[index]->key,key)==0){
                return ht->array[index]->value;
            }
            else if(index==h1){
                return NULL;
            }
        }
    }
    return NULL;
}

// return the index position in the table where the deletion happens
// return -1 if deletion fails
int delete_key(HashTable *ht, char* key){
    char *temp=search_key(ht,key);
    if(temp==NULL){
        return -1;
    }
    KeyValue* marker=createKeyValue(NULL,NULL);//marker to be put in place of deleted entry
    int index=key_to_int(key);
    int h2=secondhash(index);
    while(strcmp(ht->array[index]->key,key)!=0){
        index+=h2;
    }
    KeyValue* temp=ht->array[index];
    ht->array[index]=marker;
    free(temp);
    return index;
}

// this equals the number of keys in table/size of table
int get_load_factor(HashTable *ht){
    
}

// this equals the number of operations done so far/num of elems in table
int get_avg_probes(HashTable *ht);

// display hash table visually
void display(HashTable *ht);


// -> Insert the following key, values in the table:
// 1. 'first name' -> <your first name>
// 2. 'last name' -> <your last name>
// 3. 'uid' -> <your uid>
// 4. 'sport' -> <your favorite sport>
// 5. 'food' -> <your favorite food>
// 6. 'holiday' -> <your favorite holiday destination>
// 7. 'role_model' -> <your role model>
// 8. 'subject' -> <your favourite subject>
// 9. 'song' -> <your favourite song>
// 10. 'movie' -> <your favorite movie>
// 11. 'colour' -> <your favorite colour>
// 12. 'book' -> <your favorite book>

// -> Test the table with search and delete operations