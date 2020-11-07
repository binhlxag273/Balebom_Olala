# Balebom_Olala
// B-Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <vector>
class B_Tree {
	class Node {
	public:
		std::vector<int> data_;
		std::vector<Node*> nextNode_;
		Node* parent;
		Node() {
			parent = NULL;
		}
	};

public:
	B_Tree() {
		read_data();
	}

	void get_tree() {

	}

private:
	void split_node(Node* &root, Node* &parent, bool isleaf) {
		Node * neighbour = new Node();
		// set data
		neighbour->data_.push_back(root->data_[2]);
		parent->data_.push_back(root->data_[1]);
		root->data_.pop_back();
		root->data_.pop_back();
		//
		if (isleaf == false) {
			neighbour->nextNode_.push_back(root->nextNode_[2]);
			neighbour->nextNode_.push_back(root->nextNode_[3]);
			root->nextNode_.pop_back();
			root->nextNode_.pop_back();
		}
		// set parent
		parent->nextNode_.push_back(neighbour);
		neighbour->parent = parent;
		
	}

	void update_tree(Node* &root, int value) {
		// split root node
		if (root->data_.size() == 3 && root->parent == NULL) {
			Node * newParent = new Node();
			root->parent = newParent;
			newParent->nextNode_.push_back(root);
			bool isleaf = true;
			if (root->nextNode_.size() > 0)
				isleaf = false;
			split_node(root, newParent, isleaf);
			root = newParent;
			update_tree(root, value);
			return;
		}
		// split none root node
		else if (root->data_.size() == 3 && root->parent != NULL) {
			Node * parent = root->parent;
			int location;
			for (int i = 0; i < parent->nextNode_.size(); i++) {
				if (parent->nextNode_[i]->data_.size() == 3) {
					location = i;
					break;
				}
			}
			split_node(root, parent, 1);
			root = parent->nextNode_[location];
			update_tree(parent, value);
			
			return;
		}
		// DFS
		else if (root->nextNode_.size() != 0) {
			for (int i = 0; i < root->data_.size(); i++) {
				if (root->data_[i] > value) {
					update_tree(root->nextNode_[i], value);
					return;
				}
				else if (i == root->data_.size() - 1) {
					update_tree(root->nextNode_[i + 1], value);
					return;
				}
			}
		}
		// add value to the leaf
		else {
			for (int i = 0; i < root->data_.size(); i++) {
				if (root->data_[i] > value) {
					root->data_.insert(root->data_.begin() + i, value);
					return;
				}
			}
			root->data_.push_back(value);
			return;
		}
	}

	void read_data() {
		int n, value;
		std::cin >> n;
		Node * root = new Node;
		for (int i = 0; i < n; i++) {
			std::cin >> value;
			update_tree(root, value);
		}
	}
};
struct Node {
	int data;
	Node * next;
};

void push(Node** head_ref, int value) {
	Node * newNode = new Node();
	newNode->data = value;
	newNode->next = *head_ref;
}
int main()
{
	B_Tree tree;
}



