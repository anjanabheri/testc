/* C program for ranson note.*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

struct entry_s {
    char *key;
    int numberofElement;
    struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
    int size;
    struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;

/* Create a new hashtable. */
hashtable_t *ht_create( int size ) {

    hashtable_t *hashtable = NULL;
    int i;

    if( size < 1 ) return NULL;

    /* Allocate the table itself. */
    if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
        return NULL;
    }

    /* Allocate pointers to the head nodes. */
    if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
        free(hashtable);
        return NULL;
    }

    for( i = 0; i < size; i++ ) {
        hashtable->table[i] = NULL;
    }

    hashtable->size = size;

    return hashtable;    
}

/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key ) {
    unsigned long int hashval = 0;
    int i = 0;

    /* Convert our string to an integer */
    while( hashval < ULONG_MAX && i < strlen( key ) ) {
        hashval += key[ i ];
        i++;
    }

    return hashval % hashtable->size;
}

/* Create a key-value pair. */
entry_t *ht_newpair( char *key) {
    entry_t *newpair;

    if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
        return NULL;
    }

    newpair->key = key;
    newpair->numberofElement = 1;
    newpair->next = NULL;

    return newpair;
}

/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key) {
    int bin = 0;
    entry_t *newpair = NULL;
    entry_t *next = NULL;
    entry_t *last = NULL;

    bin = ht_hash( hashtable, key );

    next = hashtable->table[ bin ];
    
    if(next == NULL)
    {
        newpair = ht_newpair( key);
        if(newpair == NULL)
            return;
        hashtable->table[ bin ] = newpair;
        return;
    } else {
        while( next != NULL) {
            if (strcmp(next->key, key)==0)
            {
                next->numberofElement++;
                return;
            }
            last = next;
            next = next->next;
        }
        newpair = ht_newpair( key);
        if(newpair == NULL)
            return;
        last->next = newpair;  
        return;
    }
}

/* Retrieve a key-value pair from a hash table. */
char *ht_get( hashtable_t *hashtable, char *key ) {
    int bin = 0;
    entry_t *pair;

    bin = ht_hash( hashtable, key );

    /* Step through the bin, looking for our value. */
    pair = hashtable->table[ bin ];
    while( pair != NULL) {
        if(strcmp(pair->key, key) == 0)
        {
            if(pair->numberofElement > 0) {
                pair->numberofElement--;
                return pair->key;
            }
            else
                return NULL;
        }
        pair = pair->next;
    }

    return NULL;
}

int main(){
    int m, n, num = 0, magazine_i, ransom_i; 
    char **ransom, **magazine;
    hashtable_t *hashtable;

    scanf("%d %d",&m,&n);

    if(m == 0 || n == 0)
        return 1;

    hashtable = ht_create( 30000 );

    magazine = malloc(sizeof(char*) * m);
    if(magazine == NULL){
        return 1;
    }
    for(magazine_i = 0; magazine_i < m; magazine_i++){
       magazine[magazine_i] = (char *)malloc(10240 * sizeof(char));
       if(magazine[magazine_i]){
            scanf("%s", magazine[magazine_i]);
            ht_set(hashtable, magazine[magazine_i]);
       }
    }
    
    ransom = malloc(sizeof(char*) * n);
    if(ransom == NULL){
        return 1;
    }
    for(ransom_i = 0; ransom_i < n; ransom_i++){
       ransom[ransom_i] = (char *)malloc(10240 * sizeof(char));
       if(ransom[ransom_i])
       {
           scanf( "%s",ransom[ransom_i]);
           if(ht_get( hashtable, ransom[ransom_i]))
               num++;
       }
    }

    if(num == n)
        printf("Yes");
    else
        printf("No");

    return 0;
}
