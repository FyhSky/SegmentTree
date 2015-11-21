//
//  SegmentTree.hpp
//  TestAlgorithm
//
//  Created by FengYinghao on 11/21/15.
//  Copyright © 2015 FengYinghao. All rights reserved.
//

#ifndef SegmentTree_hpp
#define SegmentTree_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;



class SegmentTreeNode {
public:
    SegmentTreeNode(int a, int b);
    int GetStart();
    int GetEnd();
    void SetSum(int sum);
    int GetSum();
    void SetLeft(SegmentTreeNode* left);
    SegmentTreeNode* GetLeft();
    void SetRight(SegmentTreeNode* right);
    SegmentTreeNode* GetRight();
    
private:
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

};


class SegmentTree {
public:
    void BuildTree(vector<int> &nums, int start, int end);
    SegmentTreeNode *GetRoot();
    int ModifyTree(int i, int val);
    int QueryTree(int i, int j);

private:
    SegmentTreeNode *GenerateTree(vector<int> &nums, int start, int end);
    int _ModifyTree(int i, int val,SegmentTreeNode *node);
    int _QueryTree(int i, int j,SegmentTreeNode *node);
    SegmentTreeNode *root;
};




#endif /* SegmentTree_hpp */
