#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;
int insertion();
int insertionAtBeginning();
int insertionAtPosition();
int insertionAtEnd();
int deletion();
int deletionAtBeginning();
int deletionAtPosition();
int deletionAtEnd();
int display();
int reverse();


int main(){
    int choice;
    while(1){
        printf("1. Insertion 2. Deletion 3. Display 4. Reverse 5.Exit \n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){

            case 1: insertion();
            break;
            case 2: deletion();
            break;
            case 3: display();
            break;
            case 4: reverse();
            break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n\n");

        }
    }

    return 0;
}


int insertion(){
    int choice;
    printf("1. Insertion At The Beginning   2.Insertion At Specific Position   3. Insertion At The End  \n");
    printf("Enter choice: \n");
    scanf("%d",&choice);
    switch(choice){
        case 1: insertionAtBeginning();
        break;
        case 2: insertionAtPosition();
        break;
        case 3: insertionAtEnd();
        break;
        default: printf("Invalid Choice \n\n");
    }

    return 0;
}


int insertionAtBeginning(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data=data;
    if(head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
    }else{
        newNode->prev=NULL;
        newNode->next=head;
        head->prev=newNode;
        head=newNode;

        printf("Node Inserted At Beginning Successfully \n");
    }


    return 0;
}
int insertionAtPosition(){
    int data,pos,lengthOfList=0;
    struct Node* temp = head;
    while(temp!=NULL){
        lengthOfList++;
        temp=temp->next;
    }
    printf("Enter position to insert: ");
    scanf("%d",&pos);

    if(pos>0 && pos<=lengthOfList+1){

        if(pos==1){
            insertionAtBeginning();
        }else if(pos==lengthOfList+1){
            insertionAtEnd();
        }else{
            printf("Enter the data: ");
            scanf("%d",&data);

            struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
            newNode->data=data;

            temp=head;
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }

            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;

             printf("Node Inserted At %d position Successfully \n",pos);
        }
    }else{
            printf("Position is not in range of length \n");
    }

    return 0;
}

int insertionAtEnd(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data=data;
    if(head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
    }else{
        struct Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;

         printf("Node Inserted At End Successfully \n");
    }


    return 0;
}
int deletion(){
    int choice;
    printf("1. Deletion At The Beginning   2.Deletion At Specific Position   3. Deletion At The End  \n");
    printf("Enter choice: \n");
    scanf("%d",&choice);
    switch(choice){
        case 1: deletionAtBeginning();
        break;
        case 2: deletionAtPosition();
        break;
        case 3: deletionAtEnd();
        break;
        default: printf("Invalid Choice \n\n");
    }

    return 0;
}

int deletionAtBeginning(){

    if(head==NULL){
        printf("No Node Available To Delete\n");
    }else{
        struct Node *newNode = head;
        head=head->next;
        head->prev=NULL;
        free(newNode);

        printf("Node Deleted At Beginning Successfully \n");
    }


    return 0;
}
int deletionAtPosition(){
    int data,pos,lengthOfList=0;
    if(head==NULL){
        printf("No Node Available To Delete\n ");
    }else{

        struct Node* temp = head;
        while(temp!=NULL){
            lengthOfList++;
            temp=temp->next;
        }
        printf("Enter position to delete: ");
        scanf("%d",&pos);

        if(pos>0 && pos<=lengthOfList){

            if(pos==1){
                deletionAtBeginning();
            }else if(pos==lengthOfList){
                deletionAtEnd();
            }else{

                temp=head;
                for(int i=1;i<pos-1;i++){
                    temp=temp->next;
                }

                struct Node *newNode = temp->next;
                temp->next= newNode->next;
                newNode->next->prev=temp;

                free(newNode);

                 printf("Node Deleted At %d position Successfully \n",pos);
            }
        }else{
            printf("Position is not in range of length \n");
        }
    }

    return 0;
}

int deletionAtEnd(){

    if(head==NULL){
        printf("No Node Available To Delete\n");
    }else if(head->next==NULL){
        head=NULL;
    }else{
        struct Node* temp = head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        struct Node* newNode = temp->next;
        temp->next=NULL;

        free(newNode);
    }

    printf("Node Deleted At The End Successfully \n");

    return 0;
}

int display(){

    struct Node *temp = head;

    printf("The Nodes Are In Forward: \n ");
    while(temp->next!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
    printf("The Nodes Are In Backward: \n ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->prev;
    }
    printf("\n\n");
    return 0;
}


int reverse(){
    struct Node *temp,*curr,*prev;

    temp=head;
    prev=NULL;
    while(temp!=NULL){
        curr= temp->next;
        temp->next=prev;
        temp->prev=curr;
        prev=temp;
        temp=curr;
    }
    head=prev;

}
