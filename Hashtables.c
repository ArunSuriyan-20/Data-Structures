#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* createNode(int data){
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
} 

void initializeHash(NODE **htable){
    for(int i=0; i<29; i++){
        htable[i] = NULL;
    }
}

int Hashfunc(int data){
    int key;
    key = (((data * 19)/17)*11) % 29;
    return key;
}

void insertNode(NODE **htable, int data){
    int key = Hashfunc(data);
    NODE *temp = createNode(data);
    NODE *cur;

    printf("\nThe key for %d is %d\n",data, key);
    if(htable[key] == NULL){
        htable[key] = temp;
    }else{
        cur = htable[key];
        for(int i=0; cur->next != NULL; i++){
            cur = cur->next;
        }
        cur->next = temp;
    }
}

void deleteNode(NODE **htable, int data){
    int key = Hashfunc(data);
    NODE *temp;
    NODE *cur;

    if(htable[key]->data == data){
        temp = htable[key];
        htable[key] = htable[key]->next;
        free(temp);    
    }else{
        temp = htable[key];
        for(int i=0; temp->next != NULL; i++){
            if(temp->next->data == data){
                cur = temp->next;
                temp->next = temp->next->next;
                free(cur);
            }
        }
    }
}

void PRINT(NODE **htable){
    NODE *temp;
    printf("\n\tHash Table\n");
    for(int i=0;i<29;i++){
        temp = htable[i];
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int searchELe(NODE **htable, int data){
    int found = 0;
    NODE *temp;
    int key = Hashfunc(data);

    temp = htable[key];
    while(temp != NULL){
        if(temp->data == data){
            found  = 1;
            return found;
        }
        temp = temp->next;
    }
    return found;
}

int main(){
    NODE *hashtable[29]; // hashtable -> 29 elements(NODE address) 
    int ch, data, pos;
    
    initializeHash(hashtable);

    while(1){
        printf("1) Insert \n2) Delete \n3) Print\n4) Search\n5)exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);

        if(ch==1){
            printf("Enter the data: ");
            scanf("%d",&data);
            insertNode(hashtable, data);
        }else if(ch==2){
            printf("Enter the data: ");
            scanf("%d",&data);
            deleteNode(hashtable, data);
            printf("The deleted Data: \t%d\n",data);
        }else if(ch == 3){
            PRINT(hashtable);
        }else if(ch== 4){
            printf("Enter the data: ");
            scanf("%d",&data);
            pos = searchELe(hashtable,data);
            pos ? printf("The data %d is FOUND\n",data) : printf("The data %d is NOT FOUND\n",data);
        }else if(ch ==5){
            printf("Exiting...\n");
            break;
        }else{
            printf("Enter valid choice...\n");
        }
    }

}