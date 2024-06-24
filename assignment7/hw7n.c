// name: <your name here>
// email: <your email here>

// Hash table with doubly linked list for chaning/
#include <stdio.h>
#include <stdlib.h> 

struct bucket* hashTable = NULL; 
int BUCKET_SIZE = 10; 

// node struct
struct node {

    // Add your code here
    int key;
    int value;
    struct node* next;
    struct node* prev;

};

// bucket struct
struct bucket{

    // Add your code here
    struct node* head;
    struct node* tail;

    int count; // # of nodes in the bucket

};

// create a new node
struct node* createNode(int key, int value){

    // Add your code here
    struct node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;


    return newNode;
}

//  hash function \\with %
int hashFunction(int key){
    return key % BUCKET_SIZE;
}

//  insert a new key
void add(int key, int value){
    int hashIndex = hashFunction(key);
    
    // Add your code here
    struct node* newNode = createNode(key, value);
    // when node is empty
    if (hashTable[hashIndex].count == 0){
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].tail = newNode;  
    }
    // when node has a key
    else{
        hashTable[hashIndex].head->prev = newNode;

        newNode->next = hashTable[hashIndex].head;

        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;
    }

}

// remove a key
void remove_key(int key){
    int hashIndex = hashFunction(key);

    // Add your code here
    struct node* node = hashTable[hashIndex].head;

    while (node != NULL){

        if (node->key == key){

            if (node->prev != NULL){
                node->prev->next = node->next; 
            } else {
                // node is head
                hashTable[hashIndex].head = node->next;
            }
            if (node->next != NULL) {
                node->next->prev = node->prev;
            } else {
                // node is tail
                hashTable[hashIndex].tail = node->prev;
            }
            free(node);
            hashTable[hashIndex].count--;
            return;
        
        }
        node = node->next;
    }

}

// search a value using a key
void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;

    // Add your code here
    if (node == NULL){
        printf("No node found");
    }
    while (node != NULL) {
        if (node->key == key) {
            printf("\nKey = [ %d ], Value = [ %d ].\n", node->key, node->value);
            return;
        }
         node = node->next;
    }
    printf("No node found");
    return;
}

void display(){
    struct node* iterator;

    printf("\n========= display start ========= \n");
    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key: %d, val: %d)  <-> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}

int main(){
    hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));
    
    add(0, 1);
    add(1, 10);
    add(11, 12);
    add(21, 14);
    add(31, 16);
    add(5, 18);
    add(7, 19);

    display();

    remove_key(31);
    remove_key(11);

    display();

    search(5);
    search(1);
}
