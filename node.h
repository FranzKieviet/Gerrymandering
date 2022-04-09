#include <iostream>
using namespace std;
#define _MY_HEADERH


class Node{// ######################### RENAME TO PRECINCT ###########
    public:
        int score; //+1 if desired party, -1 is other party
        int districtNum=0;
        int data;

        Node *left = NULL;
        Node *right = NULL;
        Node *top = NULL;
        Node *bottom=NULL;



        Node *next=NULL;

    Node(){
    }

    Node(int val){
        districtNum=val;
    }
    };

class BinarySearchTree{
    public:
        Node *root = new Node();

    //Add values to tree
    void add(int newData){

        //Node for our new Node:
        Node *newNode = new Node();
        newNode->data=newData;

        //Assign score:
        if (newData%2)
            newNode->score=-1;
        else
            newNode->score=1;

        //To help with searching:
        Node *temp=new Node();
        temp=root;

        //If we don't have a root, make this the root:
        if (root->data == 0){
            root->data = newData;
            return;
        }
//Loop to keep searching till we find where to place the value
        while(true){
            //Check the left:
            if (newData < temp->data)
                //If we reacehd a leaf, attach newNode to it
                if (temp->left == NULL){
                    temp->left = newNode;
                    break;
                }
                //If it is not a leaf, there is still more to look at
                //so set temp to that new subtree:
                else
                    temp = temp->left;
            //If not the left, then it must go on the Right
            else{
                //If we reacehd a leaf, attach newNode to it
                if (temp->right == NULL){
                    temp->right = newNode;
                    break;
                }
                else
                //If it is not a leaf, there is still more to look at
                //so set temp to that new subtree:
                    temp = temp->right;
            }
        }

        return;
        }
 
    void print(Node *temp){
        if (temp != 0){
            //Keep going to the left when possible using recursion
            print(temp->left);
            cout << temp->data << " ";
            print(temp->right);
        }
    }
};