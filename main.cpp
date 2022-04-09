#include <iostream>
#include "tree.h"
#include "constants.cpp"
#include "node.cpp"

using namespace std; 


int main(){
    //BUILD MAP:
        //BASED ON THE CONSTANTS
    Node Precinct[ROWS][COLS];
    int dNum=1;
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            Precinct[i][j]=Node(dNum);
            dNum++;
        }
    }

    //Fill the touching precincts:
    Node nullNode=Node(-1);
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            //VERTICALLY:
            if(i-1>=0)
                Precinct[i][j].top=&(Precinct[i-1][j]);
            else
                 Precinct[i][j].top=&nullNode;
            if(i+1<=ROWS)
                Precinct[i][j].bottom=&(Precinct[i+1][j]);
            else
                 Precinct[i][j].bottom=&nullNode;
            //HORIZONTALLY:
            if(j-1>=0)
                Precinct[i][j].left=&(Precinct[i][j-1]);
            else
                 Precinct[i][j].left=&nullNode;
            if(j<=COLS)
                Precinct[i][j].right=&(Precinct[i][j+1]);
            else
                 Precinct[i][j].right=&nullNode;
        }
    }

    //BinarySearchTree tree=BinarySearchTree();
    Tree tree =Tree();
    //tree.print(&Precinct[0][0]);
    tree.printPaths(&Precinct[0][0]);



    cout<<"TESTS:"<<endl;
    //TEST NEW MAP:
    cout<<Precinct[0][1].districtNum<<" ";
    cout<<Precinct[1][0].districtNum<<" ";
    cout<<Precinct[1][2].districtNum<<" ";
    cout<<Precinct[3][3].districtNum<<" ";
    cout<<endl<<"2 5 7 16 SHOULD READ "<<endl;

    //TEST:
    cout<<Precinct[0][2].districtNum<<" ";
    cout<<Precinct[0][2].top->districtNum<<" ";
    cout<<Precinct[0][2].bottom->districtNum<<" ";
    cout<<Precinct[0][2].left->districtNum<<" ";
    cout<<Precinct[0][2].right->districtNum<<" ";
    cout<<endl<<"3 -1 7 2 4 SHOULD READ  "<<endl;

   // BinarySearchTree tree=BinarySearchTree(); 
    //tree.print(tree.root);
    cout<<"DONE"<<endl;
    return 0;
}