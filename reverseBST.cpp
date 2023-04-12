//code to reverse a binary tree 

#include<iostream>
using namespace std;


class node {
public:
	node* next;
	int data;


	//default contructor 
	node() {

	}

	//parametrized constructor
	node(int y) {

		data = y;
		next = NULL;
	}
};

//queue class 
class queue {

public:
	node* head;
	node* rear;

	//default contructor assigning both rear and front NULL
	queue() {
		head = NULL;
		rear = NULL;
	}

	//entering in the queque
	void inqueue(int value) {
		node* in = new node(value);
		//if queue is already empty 
		if (rear == NULL && head == NULL) {

			rear = head = in;


		}
		//queue is empty
		//hence the rear will move one step ahead as entering is fron rear in queue

			//cout << rear->next;
		rear->next = in;
		rear = in;


	}
	void dequeue() {
		//stack already empty
		if (head == NULL) {
			cout << "stack already empty! " << endl;
		}
		//stack have elements 
		else {
			node* del = new  node;

			head = del;
			head = head->next;
			delete del;
		}

	}

	//printing queue
	void print() {
		//making node to traverse thro all the data of queue
		node* traverse = new node;
		traverse = head;

		while (traverse != NULL) {
			cout << traverse->data << endl;
			traverse = traverse->next;
		}

	}


};
class nodet {
public:
	int data;
	nodet* left;
	nodet* right;
	nodet(int a) {
		left = NULL;
		right = NULL;

	}
	nodet() {

	}

};

class tree {
public:

	nodet* root;


	tree() {
		
		root = NULL;


	}
	void insert(int a) {
		nodet* traverse;
		traverse = new nodet();
		nodet* val = new nodet(a);


		if (root == NULL) {
			root = new nodet(a);
		}
		else {
			traverse = root;
			while (traverse != NULL) {
				if (a < traverse->data) {
					traverse = traverse->left;

				}
				else {
					traverse = traverse->right;

				}
			}
			traverse = val;

		}

	}

};

void reverse_tree(tree t) {

   queue Q;
    Q.inqueue(t.root->data);

    // Traverse the tree using BFS and insert nodes into the queue
    nodet* curr = t.root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            Q.inqueue(curr->left->data);
        }
        if (curr->right != NULL) {
            Q.inqueue(curr->right->data);
        }
        curr = Q.head->next;
        Q.dequeue();
    }

    // Traverse the tree again using BFS and assign new values to the nodes
    curr = t.root;
    while (curr != NULL) {
        curr->data = Q.head->data;
        Q.dequeue();
        if (curr->left != NULL) {
            Q.inqueue(curr->left->data);
        }
        if (curr->right != NULL) {
            Q.inqueue(curr->right->data);
        }
        curr = Q.head->next;
        Q.dequeue();
    }




}