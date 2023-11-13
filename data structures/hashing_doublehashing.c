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
    KeyValue* newKeyValue = malloc(sizeof(KeyValue));
    if (newKeyValue != NULL) {
        newKeyValue->key=malloc((strlen(key)+1)*sizeof(char));
        newKeyValue->value=malloc((strlen(value)+1)*sizeof(char));
        strcpy(newKeyValue->key,key);
        strcpy(newKeyValue->value,value);
    }
    newKeyValue->isDeleted=false;
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
        hash+=((int)key[ind]+128);
        ind++;
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
        ht->num_ops++;
        retval=h1;
    }
    else if(ht->array[h1]->isDeleted==true){
        ht->array[h1]->isDeleted=false;
        strcpy(ht->array[h1]->key,key);
        strcpy(ht->array[h1]->value,value);
        free(to_insert);
        ht->num_ops++;
        retval=h1;
    }
    else{
        int h2=secondhash(h1);
        int index=h1;
        while(ht->array[index]!=NULL){
            if(ht->array[index]->isDeleted==true){
                ht->array[index]->isDeleted=false;
                strcpy(ht->array[index]->key,key);
                strcpy(ht->array[index]->value,value);
                free(to_insert);
                retval=index;
                ht->num_ops++;
                goto wasdeleted;
            }
            index+=h2;
            index%=TABLE_SIZE;
            ht->num_ops++;
            if(index==h1){//if index becomes equal to initial value again, it means it has gone into a loop
                return 1;
            }
        }
        ht->array[index]=to_insert;
        retval=index;
        ht->num_ops++;
    }
    wasdeleted:
    ht->num_keys++;
    ht->num_occupied_indices++;

    return retval;
}

// return the value of the key in the table
// return NULL if key not found
char *search_key(HashTable *ht, char* key){
    int h1=key_to_int(key);
    int index=h1;
    if(ht->array[index]==NULL){
        return NULL;
    }
    else if(strcmp(ht->array[index]->key,key)==0 && ht->array[index]->isDeleted==false){
        ht->num_ops++;
        return ht->array[index]->value;
    }
    else{
        int h2=secondhash(index);
        for(int i=0;i<TABLE_SIZE;i++){//if the item is not found after table_size number of iterations, it means it doesn't exist as the function may have gotten stuck in a loop
            index+=h2;
            index%=TABLE_SIZE;
            ht->num_ops++;
            if(ht->array[index]==NULL){
                return NULL;
            }
            else if(strcmp(ht->array[index]->key,key)==0 && ht->array[index]->isDeleted==false){
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
    int n=ht->num_ops;
    char *temp=search_key(ht,key);
    ht->num_ops=n;
    if(temp==NULL){
        return -1;
    }
    int index=key_to_int(key);
    int h2=secondhash(index);
    while(strcmp(ht->array[index]->key,key)!=0){
        ht->num_ops++;
        index+=h2;
        index%=TABLE_SIZE;
    }
    ht->num_ops++;
    ht->array[index]->isDeleted=true;
    ht->num_keys--;
    ht->num_occupied_indices--;
    return index;
}

// this equals the number of keys in table/size of table
float get_load_factor(HashTable *ht){
    float lf=(float)ht->num_keys/TABLE_SIZE;
    ht->load_factor=lf;
    return lf;
}

// this equals the number of operations done so far/num of elems in table
float get_avg_probes(HashTable *ht){
    return ht->num_ops/ht->num_occupied_indices;
}

// display hash table visually
void display(HashTable *ht){
    printf("displaying hash table:\n");
    printf("\nINDEX\t%-35s\t%-35s\n\n","KEY","VALUE");
    for(int i=0;i<TABLE_SIZE;i++){
        if(ht->array[i]==NULL){
            printf("%-5d\t%-35s\t%-35s\n",i,"NULL","NULL");
        }
        else if(ht->array[i]->isDeleted==true){
            printf("%-5d\t%-35s\t%-35s\n",i,"deleted","deleted");
        }
        else{
            printf("%-5d\t%-35s\t%-35s\n",i,ht->array[i]->key,ht->array[i]->value);
        }
    }
    printf("\n");
}

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

int main(){
    HashTable *ht= createHashTable();
	char key[12][40]= {"first name", "last name", "uid", "sport", "food", "holiday", "role_model", "subject", "song", "movie", "colour", "book"};
	char value[12][40]= {"Shubhan", "Singh", "20223001118", "Cricket", "Paneer", "Himalayas", "Nobody specific", "Maths", "Birthquake", "The good, the bad and the ugly", "Light blue", "Nineteen eighty four"};
	// Insertion of all the values:
    int insert;
	for(int i=0; i<12; i++)
	{
		insert= insert_key_value(ht, key[i], value[i]);
        if(insert==-1){
            printf("Insertion failed for key \"%s\"\n",key[i]);
        }
	}
    printf("After inserting all vlaues:\n\n");
	display(ht);
	printf("\nTotal number of Operations: %d\n", ht->num_ops);
	printf("\nThe load factor for the hash table is: %.2f\n",get_load_factor(ht));

	// Displaying a value whose key is present.
	printf("\nValue of the Key \"song\": %s\n", search_key(ht, "song"));
	
	// Displaying a value whose key is NOT present.
	char* st=search_key(ht,"album");
    if(st==NULL){
        printf("\nKey %s not present\n","album");
    }

    delete_key(ht,key[5]);
    printf("\nAfter deleting key \"holiday\":\n");
    display(ht);
    delete_key(ht,key[8]);
    printf("\nAfter deleting key \"song\":\n");
    display(ht);
    insert=insert_key_value(ht,key[8],value[8]);
    if(insert==-1){
        printf("Insertion failed for key \"%s\"\n",key[8]);
    }
    insert=insert_key_value(ht,key[5],value[5]);
    if(insert==-1){
        printf("Insertion failed for key \"%s\"\n",key[5]);
    }
    printf("After inserting deleted keys back:\n");
    display(ht);

return 0;
}