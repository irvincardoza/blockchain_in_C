#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <CommonCrypto/CommonDigest.h>


typedef struct Block{
    int index;
    time_t timestamp;
    char data[256];
    char prev_hash[CC_SHA256_DIGEST_LENGTH * 2 + 1];
    char hash[CC_SHA256_DIGEST_LENGTH * 2 + 1];
    struct Block* next;


}Block;


//prebuilt function to calculate hash
void calculate_sha256(char* string, char outputBuffer[65]) {
    CC_SHA256_CTX sha256;
    CC_SHA256_Init(&sha256);
    CC_SHA256_Update(&sha256, string, (CC_LONG)strlen(string));
    unsigned char hash[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256_Final(hash, &sha256);
    for (int i = 0; i < CC_SHA256_DIGEST_LENGTH; i++) {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}
//creating a block using linked lists

Block* create_block(int index,char*data,char*prev_hash){
    Block* new_block=(Block*)malloc(sizeof(Block));
    new_block->index=index;
    new_block->timestamp=time(NULL);
    strcpy(new_block->data,data);
    strcpy(new_block->prev_hash,prev_hash);

    //creating new hash
    char b_hash[1024];
    sprintf(b_hash, "%d%ld%s%s", new_block->index, new_block->timestamp, new_block->data, new_block->prev_hash);
    calculate_sha256(b_hash, new_block->hash);
    new_block->next=NULL;
    return new_block;
}

void addBlock(Block **blockchain){
    Block *new_block;
    char data[256];
    fgets(data,sizeof(data),stdin);
    data[strcspn(data, "\n")] = '\0';

    if(*blockchain==NULL){
        //if blockchain is empty we create the firsdt block
        new_block=create_block(0,data,"0");
        //update blockchain pointer to point to firdt block
        *blockchain=new_block;
    }else{
        //find the last block in list
        Block* lastBlock=*blockchain;
        while(lastBlock->next!=NULL){
            lastBlock=lastBlock->next;//traversing the list till end
        }
    new_block = create_block(lastBlock->index + 1, data, lastBlock->hash);
    lastBlock->next = new_block;
    }



}
void printBlockchain(Block*blockchain){
    Block *current=blockchain;
    //create a pointer to point to current block
    while(current!=NULL){
     printf("Block: %d\n",current->index);
         printf("Timestamp: %ld\n",current->timestamp);
         printf("Data: %s\n",current->data);
         printf("Previous Hash: %s\n",current->prev_hash);
      printf("Hash: %s\n\n",current->hash);
        current=current->next;
    }
}
int main(){
    Block* blockchain=NULL;
    char choice='y';
    do{
        addBlock(&blockchain);
    
   
    printf("Block added to blockchain.\n");
        printf("Do you want to add another block? (y/n): ");
        scanf(" %c", &choice);
        getchar(); 
    }while (choice == 'y' || choice == 'Y');
    //free memory

    printf("Blockchain contents:\n");
    printBlockchain(blockchain); 
    Block* current=blockchain;
    Block* nextBlock;
    while(current!=NULL){
        nextBlock=current->next;
        free(current);
        current=nextBlock;
    }
    return 0;
}