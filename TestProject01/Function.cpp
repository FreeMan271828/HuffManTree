#include"Function.h"
Node::Node(char data,double freq){
    this->data = data;
    this->freq = freq;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}
char Node::getData(){
    return this->data;
}
double Node::getFreq(){
    return this->freq;
}
Node* Node::getLeftTree(){
    return this->leftChild;
}
Node* Node::getRightTree(){
    return this->rightChild;
}
void Node::setElm(char c,double d){
    this->data = c;
    this->freq = d;
}
void Node::setLeftChild(Node* node){
    this->leftChild = node;
}
void Node::setRightChild(Node* node){
    this->rightChild = node;
}

void HuffManTree::printTree(Node* root,std::string str){
    if (!root)
        return;

    if (root->getData() != '$')
        std::cout << root->getData() << ": " << str << "\n";

    printTree(root->getLeftTree(), str + "1");
    printTree(root->getRightTree(), str + "0");
}
Node* HuffManTree::getMinNode(std::vector<Node*>&vec){
    int minIndex = 0;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i]->getFreq() < vec[minIndex]->getFreq()){
            minIndex = i;
        }
    }
    Node* minNode = vec[minIndex];
    vec.erase(vec.begin() + minIndex);
    return minNode;
}
void HuffManTree:: buildHuffManTree(char ch[],double freq[],int size){
    //构建Node*数组
    std::vector<Node*>vec;
    for(int i=0;i<size;i++)
        vec.push_back(new Node(ch[i],freq[i]));
    while(vec.size()!=1){
        //寻找freq最小的两个Node
        Node* node1 = HuffManTree::getMinNode(vec);
        Node* node2 = HuffManTree::getMinNode(vec);
        //构建父节点
        Node* top = new Node('$',node1->getFreq()+node2->getFreq());
        top->setLeftChild(node1);
        top->setRightChild(node2);
        //将父节点推到数组里
        vec.push_back(top);
    }
    printTree(vec[0],{});
}