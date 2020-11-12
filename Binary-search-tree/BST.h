#ifndef __Binary__tree
typedef struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

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
#endif