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
    /*
    printf("Mininmum Value : %d \n",minValue(root)->data);
    printf("Maximum Value : %d \n",maxValue(root)->data); 
    */
    // -------------- Test delete ----------------------
    /*
    printf("Before deleting \n");
    printf("Display Inorder Traversals \n");
    displayInorderTraversals(root);
    
    deleteNode(root,10);

    printf("After deleting \n");
    printf("InOrder Traversals : \n");
    displayInorderTraversals(root);
    */

    //-------------- Number of levels + sum in each level + size of the tree ----------
    
    printf("Height : %d\n",getHeight(root));
    printf("Size : %d \n",getSize(root));
    getSuminEachLevel(root);   
    
    //--------------- Inorder-Traversals + Preorder-Traversals + Postorder-Traversals ------------
    /*
    printf("Affichage infixe (left,root,right) => InorderTraversals \n");
    displayInorderTraversals(root);
    printf("Affichage préfixe (root,left,right) => PreorderTraversals \n");
    displayPreorderTraversals(root);
    printf("Affichage suffixe (left,right,root) => PostorderTraverslas\n");
    displayPostorderTraversals(root);
    */
   
    
    return 0;
}
