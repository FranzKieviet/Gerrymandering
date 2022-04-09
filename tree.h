#include <iostream>
#include "constants.cpp"
#include "node.cpp"
using namespace std; 

    /* UTILITY FUNCTIONS /
    / Utility that prints out an array on a line. */
    void printArray(int ints[], int len){
        int i;
        cout<<"LEN: "<<len<<" ---- ";
        for (i = 0; i < len; i++)
        {
            cout << ints[i] << " ";
        }
        cout<<endl;
    }


class Tree{
    public:
        Node root = new Node();
    //Builds a tree to evalute which options are the best:


    void printPaths(Node node)
    {
        int path[NUMP];
        printPathsRecur(node, path, 0);
    }

    /* Recursive helper function -- given a node,
    and an array containing the path from the root
    node up to but not including this node,
    print out all the root-leaf paths./
    void printPathsRecur(Node node, int path[], int pathLen)
    {
        if (node == NULL)
            return;

        /* append this node to the path array /
        if(node->districtNum != -1){ 
            path[pathLen] = (node->districtNum);
            pathLen++;
        }

        //If there is 4 in a district:
        if (pathLen==NUMP){
            //Check that there are no duplicates:
            int dup=0;
            for(int i=0; i<pathLen; i++){
                for(int j=i+1;j<pathLen;j++){
                    if(path[i]==path[j]){
                        dup=1;
                        break;
                    }
                }
            }
            if(!dup)
                printArray(path, pathLen);
        }

        else
        {
            / otherwise try both subtrees */
            printPathsRecur(node->left, path, pathLen);
            printPathsRecur(node->right, path, pathLen);
            printPathsRecur(node->top, path, pathLen);
            printPathsRecur(node->bottom, path, pathLen);
        }
    }
};