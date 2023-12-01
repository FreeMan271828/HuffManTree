#include"Function.h"
using namespace std;
int main(){
    char ch[] ={'a','b','c','d','e','f','g','h'};
    double arr[]={0.05,0.29,0.07,0.08,0.14,0.23,0.03,0.11};
    int size = sizeof(ch)/sizeof(char);
    HuffManTree::buildHuffManTree(ch,arr,size);
}