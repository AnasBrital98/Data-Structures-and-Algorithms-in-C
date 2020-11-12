#include<stdio.h>
#include<stdlib.h>
#include "BST.h"

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
/*int NumberOflevels(Node *root)
{
    if(root->left == NULL && root->right == NULL)
        return 0;
    int left = 0;
    if(root->left != NULL)
        left = getNumberOflevels(root->left);
    int right = 0;
    if(root->right != NULL)
        right = getNumberOflevels(root->right);
    return max(left,right) + 1;    
}

int getNumberOflevels(Node *root)
{
    return NumberOflevels(root)+1;
}*/

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