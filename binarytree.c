/*binary trees*/
#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int value;
    struct tree* Rlink;
    struct tree* Llink;
}tree;/*declaring a structure with the name tree*/

tree* createNode(){
    int value=0;
    
    printf("Type value(-1 to not add): ");
    scanf("%d",&value);
    if(value == -1)
        return NULL;
    
    tree* node = (tree*)malloc(sizeof(tree));
        if(node==NULL){/*For error handling. If for some reason memory couldn't be allocated*/
            printf("Memory allocation failed");
            return NULL;
        }
    node->value = value;/*set root's value*/
    node->Rlink = NULL;
    node->Llink = NULL;
    printf("Node Inserted!\n");
    return node;
}
void insertNode(tree** root){
    *root  = createNode();
    if(*root==NULL)
        return;

    printf("Left-child[%d]:\n",(*root)->value);
    insertNode(&((*root)->Llink));
    printf("Right-child[%d]:\n",(*root)->value);
    insertNode(&((*root)->Rlink));
}
void preOrder(tree* root){/*follows classic recursive algorithm for preorder*/
    if(root == NULL)
        return;
    printf("%d -> ",root->value);
    preOrder(root->Llink);
    preOrder(root->Rlink);
}
void postOrder(tree* root){
    if(root == NULL)
        return;
    postOrder(root->Llink);
    postOrder(root->Rlink);
    printf("%d -> ",root->value);
}
void inOrder(tree* root){
    if(root == NULL)
        return;
    inOrder(root->Llink);
    printf("%d -> ",root->value);
    inOrder(root->Rlink);
}
void main(){
    tree *root = NULL;
    while(1){
        
        printf("\n\t\tTrees-Menu\t\n");
        printf("------------------------------------------");
        printf("\n1.Create-a-Tree\t\t2.pre-order\n3.in-order\t\t4.post-order\n5.Exit\t\n");
        printf("------------------------------------------\n");
        int choice=0;
        scanf("%d",&choice);

        switch(choice){
            case 1: insertNode(&root);
                    break;
            case 2: printf("Pre-order: ");
                    preOrder(root);
                    printf("END\n");
                    break;
            case 3: printf("In-order: ");
                    inOrder(root);
                    printf("END\n");
                    break;
            case 4: printf("Post-order: ");
                    postOrder(root);
                    printf("END\n");
                    break;
            case 5: exit(0);

            default: printf("Invalid Choice!");
                    break; 
        }
    }
}
/*Example to try out: 
    create a tree(input in order): 5 6 9 -1 -1 8 -1 -1 7 -1 3 2 -1 -1 -1.
    preorder: 5 6 9 8 7 3 2 
*/