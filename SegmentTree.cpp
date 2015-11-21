//
//  SegmentTree.cpp
//  TestAlgorithm
//
//  Created by FengYinghao on 11/21/15.
//  Copyright © 2015 FengYinghao. All rights reserved.
//

#include "SegmentTree.hpp"

SegmentTreeNode::SegmentTreeNode(int a, int b):start(a),
                                               end(b),
                                               sum(0),
                                               left(nullptr),
                                               right(nullptr) {
                                                   
                                                   
    
};

int SegmentTreeNode::GetStart() {
    return start;
}
int SegmentTreeNode::GetEnd() {
    return end;
}
void SegmentTreeNode::SetSum(int sum) {
    this->sum = sum;
}
int SegmentTreeNode::GetSum() {
    return sum;
}

void SegmentTreeNode::SetLeft(SegmentTreeNode* left) {
    this->left = left;
}
SegmentTreeNode* SegmentTreeNode::GetLeft() {
    return left;
}
void SegmentTreeNode::SetRight(SegmentTreeNode* right) {
    this->right = right;
}

SegmentTreeNode* SegmentTreeNode::GetRight() {
    return right;
}

void SegmentTree::BuildTree(vector<int> &nums, int start, int end) {
    root = GenerateTree(nums, start, end);
}

SegmentTreeNode* SegmentTree::GenerateTree(vector<int> &nums, int start, int end) {
    if(start > end) return nullptr;
    SegmentTreeNode *node = new SegmentTreeNode(start,end);
    if(start == end) {
        node->SetSum(nums[start]);
        return node;
    }
    int mid = start + (end - start) / 2;
    SegmentTreeNode *left = GenerateTree(nums,start,mid);
    SegmentTreeNode *right = GenerateTree(nums,mid+1,end);
    node->SetLeft(left);
    node->SetRight(right);
    node->SetSum(left->GetSum() + right->GetSum());
    return node;
}

int SegmentTree::ModifyTree(int i, int val) {
    return _ModifyTree(i, val, root);
}

int SegmentTree::QueryTree(int i, int j) {
    return _QueryTree(i, j, root);
}

int SegmentTree::_ModifyTree(int i, int val,SegmentTreeNode *node) {
    if(node == nullptr) return 0;
    int diff;
    if(node->GetStart() == i && node->GetEnd() == i) {
        diff = val - node->GetSum();
        node->SetSum(val);
        return diff;
    }
    int mid = (node->GetStart() + node->GetEnd()) / 2;
    if(i > mid) {
        diff = _ModifyTree(i,val,node->GetRight());
    } else {
        diff = _ModifyTree(i,val,node->GetLeft());
    }
    node->SetSum(node->GetSum() + diff);
    return diff;
}

int SegmentTree::_QueryTree(int i, int j,SegmentTreeNode *node) {
    if(node == nullptr) return 0;
    if(node->GetStart() == i && node->GetEnd() == j) return node->GetSum();
    int mid = (node->GetStart() + node->GetEnd()) / 2;
    if(i > mid) return _QueryTree(i,j,node->GetRight());
    if(j <= mid) return _QueryTree(i,j,node->GetLeft());
    return _QueryTree(i,mid,node->GetLeft()) + _QueryTree(mid+1,j,node->GetRight());
}
