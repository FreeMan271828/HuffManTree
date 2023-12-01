#pragma once
#ifndef _FUNCTION_H
#define _FUNCTION_H

#include<bits/stdc++.h>

class Node{
private:
    char data;
    double freq;
    Node* leftChild;
    Node* rightChild;
public:
    Node(char data,double freq);
    char getData();
    double getFreq();
    Node* getLeftTree();
    Node* getRightTree();
    void setElm(char data,double freq);
    void setLeftChild(Node* node);
    void setRightChild(Node* node);
};

class HuffManTree{
public:
    static Node* getMinNode(std::vector<Node*>&vec);
    static void buildHuffManTree(char ch[],double freq[],int size);
    static void printTree(Node* node,std::string str);
};

#endif