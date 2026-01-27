#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

typedef struct linkedlist{
    int count;
    NODE *head;
    NODE *tail;
}LINKED_LIST;

NODE* createNode(int data){
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
} 

//INSERT at LAST
void PUSH(LINKED_LIST *list, int data){
    NODE* temp = createNode(data);
    if(list->count == 0){
        list->head = temp;
        list->tail = temp;
        list->count++;
    }else{
        list->tail->next = temp;
        list->count++;
        list->tail = temp;
    }
}

// Delete at LAST
int POP(LINKED_LIST *list){
    int data;
    NODE* temp, *del;
    temp = list->head;
    if(list->count == 1){
        del = list->head;
        data = del->data;
        list->head = list->head->next;
        free(del);
        list->count--;
        return data;
    }
    for(int i=0;temp->next->next != NULL;i++){
        temp = temp->next;
    }
    del = temp->next;
    temp->next = NULL;
    data = del->data;
    free(del);
    list->count--;
    return data;
}

void PRINT(LINKED_LIST list){
    NODE *temp;
    temp = list.head;
    printf("STACK\n");
    if(list.count == 0){
        printf("EMPTY...\n");
        return;
    }
    for(int i=0;temp != NULL; i++){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchEle(LINKED_LIST list, int data){
    int idx = -1;
    NODE *temp = list.head;

    for(int i=0;temp != NULL; i++){
        if(temp->data == data){
            idx = i;
            break;
        }
        temp = temp->next;
    }
    return idx;
}

int main(){
    int ch;
    int data,pos;

    LINKED_LIST stack;
    stack.count = 0;
    stack.head = NULL;
    stack.tail = NULL;

    while(1){
        printf("1) Insert Node (PUSH) \n2) Delete Node (POP) \n3) Print Stack\n4) Search\n5)exit\n");
        printf("Enter your Choice: ");
        scanf("%d",&ch);

        if(ch==1){
            printf("Enter the data: ");
            scanf("%d",&data);
            PUSH(&stack, data);
        }else if(ch==2){
            data = POP(&stack);
            printf("The deleted Data: \t%d\n",data);
        }else if(ch == 3){
            PRINT(stack);
        }else if(ch== 4){
            printf("Enter the data: ");
            scanf("%d",&data);
            pos = searchEle(stack,data);
            printf("The data %d is at %d\n",data, pos);
        }else if(ch ==5){
            printf("Exiting...\n");
            break;
        }else{
            printf("Enter valid choice...\n");
        }
    }
    

}