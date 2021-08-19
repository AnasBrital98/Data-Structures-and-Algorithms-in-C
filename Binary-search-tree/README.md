# Binary Search Tree 

* Node :
```c
typedef struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
```

* Functions Prototype :
```c
Node* createNode(int data);
Node* insert(Node *root,Node *node);
Node* search(Node *root,int value);
Node* minValue(Node *node);
Node* maxValue(Node* node);
Node* deleteNode(Node *root,int value);
void getSuminEachLevel(Node * root);
int getSize(Node *root);
int getHeight(Node* root);
void calculateLevelSum(Node* root, int level, int *sum);
void removeNode(Node *node);
void removeTree(Node **root);
void displayInorderTraversals(Node *root);  //parcours infixe
void displayPreorderTraversals(Node *root); //parcours préfixe
void displayPostorderTraversals(Node *root);//parcours suffixe   
```

* Functions Implementation :
```c
Node* createNode(int data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node * insert(Node *root,Node *node)
{
    if(root == NULL)
    {
        return node;
    }
    if(node->data < root->data)
    {
        root->left = insert(root->left,node);;
    }else{
        if(node->data > root->data)
        {
            root->right = insert(root->right,node);
        }else
        {
            printf("the value already exists\n");
        }        
    }
    return root;
}

Node* search(Node *root,int value)
{
    if(root == NULL || root->data == value)
    {
        return root;
    }else if (root->data > value)
    {
        return search(root->left,value);
    }else{
        return search(root->right,value);
    }
}

Node* maxValue(Node* node)
{
    Node* current = node;
    while(current && current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node* minValue(Node *node)
{
    Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node *root,int value)
{
    if(root == NULL)
        return root;
    if(root->data > value)
        root->left = deleteNode(root->left,value);
    else if (root->data < value)
    {
        root->right = deleteNode(root->right,value);
    }else
    {   
        //node with one or no Childeren
        if(root->left == NULL)
        {
            Node* tmp = root->right;
            free(root);
            return tmp;
        }
        if(root->right == NULL)
        {
            Node* tmp = root->left;
            free(root);
            return tmp; 
        }
        // node with two children: Get the inorder successor (smallest in the right subtree)
        Node* tmp =minValue(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right,tmp->data); 
    }
    return root;        
}

int max(int a,int b)
{
    return a-b<0 ? b : a ;
}

int getHeight(Node *root)
{
    if(root == NULL)
        return 0;
    
    return 1 + max(getHeight(root->left),getHeight(root->right));    
}

void calculateLevelSum(Node* root, int level, int *sum)
{
    if(root == NULL)
        return;
    *(sum + level) += root->data;
    calculateLevelSum(root->left,level + 1,sum);
    calculateLevelSum(root->right,level + 1,sum);    
}

int getSize(Node *root)
{
    if(root == NULL)
        return 0;
    else
        return getSize(root->left) + getSize(root->right) + 1 ;    
}

void getSuminEachLevel(Node * root)
{
    int nbrlevels,*sum,*p;
    nbrlevels = getHeight(root);
    sum = (int*)calloc(nbrlevels,sizeof(int));
    calculateLevelSum(root,0,sum);
    for(p=sum;p<sum+nbrlevels;p++)
    {
        printf("level %ld : %d \n",p-sum,*p);
    }
}

void removeNode(Node *node)
{
    if(node == NULL)
        return;
    removeNode(node->left);
    removeNode(node->right);
    printf("Deleting Node %d \n",node->data);
    free(node);        
}

void removeTree(Node **node)
{
    removeNode(*node);
    printf("Deleting Node %d \n",(*node)->data);
    *node = NULL;
    printf("Tree Deleted \n");
}

void displayInorderTraversals(Node *root)  //parcours infixe (Left, Root, Right)
{
    if(root != NULL)
    {
        displayInorderTraversals(root->left);
        printf("%d\n",root->data);
        displayInorderTraversals(root->right);    
    }
    
}

void displayPreorderTraversals(Node *root) //parcours préfixe  (Root, Left, Right)
{
    if(root != NULL)
    {
        printf("%d\n",root->data);
        displayInorderTraversals(root->left);        
        displayInorderTraversals(root->right);
    }
}

void displayPostorderTraversals(Node *root) //parcours suffixe (Left, Right, Root)
{
    if(root != NULL)
    {
        displayInorderTraversals(root->left);
        displayInorderTraversals(root->right);
        printf("%d\n",root->data);       
    }   
}
```

* Testing Binary Search Tree  :
```c
#include<stdlib.h>
#include<stdio.h>
#include "BST.h"

Node *root = NULL;

int main(int argc,char** argv)
{
    root = insert(root,createNode(10));
    root = insert(root,createNode(30));
    root = insert(root,createNode(15));
    root = insert(root,createNode(7));
    root = insert(root,createNode(8));
    root = insert(root,createNode(40));
    root = insert(root,createNode(5));
    // -------------  Minimum and maximum operations test -------------
    
    printf("Mininmum Value : %d \n",minValue(root)->data);
    printf("Maximum Value : %d \n",maxValue(root)->data); 
    
    // -------------- Test delete ----------------------
    
    printf("Before deleting \n");
    printf("Display Inorder Traversals \n");
    displayInorderTraversals(root);
    
    deleteNode(root,10);

    printf("After deleting \n");
    printf("InOrder Traversals : \n");
    displayInorderTraversals(root);
    

    //-------------- Number of levels + sum in each level + size of the tree ----------
    
    printf("Height : %d\n",getHeight(root));
    printf("Size : %d \n",getSize(root));
    getSuminEachLevel(root);   
    
    //--------------- Inorder-Traversals + Preorder-Traversals + Postorder-Traversals ------------
    
    printf("Affichage infixe (left,root,right) => InorderTraversals \n");
    displayInorderTraversals(root);
    printf("Affichage préfixe (root,left,right) => PreorderTraversals \n");
    displayPreorderTraversals(root);
    printf("Affichage suffixe (left,right,root) => PostorderTraverslas\n");
    displayPostorderTraversals(root);
    
   
    
    return 0;
}

```

To Compile The Files Run This Command:

```bash
make makefile out=output_File_Name
```