#include<iostream>
#include<iomanip>


//rai muhammad tabish
//i21-2541

using namespace std;

class node{
	

public:
	
	node* next;
	int data;

	/*seeter getter constructer parametric */
	node(int n) {
		data = n;
		//next = NULL;

	}
	node() {
		data = 0;
		next =NULL;

	}
	void set(int n, node* l) {
		data = n;


		next = l;
	}
	int get_data() {
		return data;

	}
	node* get_next() {
		return next;

	}




};

class link{
public:
	node* head;
	link() {
		head = NULL;
	}


	void insert_end(int v) {
		node *new_node= new node(v);



		if (head == NULL) {
			head = new_node;
			return;
		}

		node* ptr=head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		//and when it reaches that point 
		ptr->next = new_node;

	}


	void insert_start(int v) {
		node* new_node = new node(v);

		new_node->next = head;
		head = new_node;

		

	}
	bool is_empty() {
		if (head == NULL) {
			return 1;

		}
		else return 0;


	}
	//function to search the element 

	void search(int y) {


		node* ptr = head;




		if (head == NULL) {


			cout << "list have no element" << endl;

			return;


		}


		while (ptr != NULL) {
			if(ptr->data==y)
			cout << ptr->data << "is in the linked list ";
			//ptr = ptr->next;
		}

	}
	void update(int h,int y) {

		//when there will be h value in linked ist it will be updated

		node* ptr = head;

		while (ptr != NULL) {

			if (ptr->data = h) {
				ptr->data = y;
			}
			//cout << ptr->data << " ";
			ptr = ptr->next;
		}




	}
	//void 
	//print the linked list 
	void del() {

		node* ptr1 = head;
		node* ptr2 = NULL;

	

	

	

		ptr1 = head;

	
			head = head->next;
			delete ptr1;


			return;
		

	

	}
	void insert_after(int v) {
		node* new_node = new node(v);

		new_node->next = head;
		head = new_node;


	}

	void PRINT() {

		
		node* ptr = head;

		
		
	
		if (head == NULL) {
		
			
			cout << "list have no element" << endl;
			
			return;


		}

		
		while (ptr!= NULL) {

			cout << ptr-> data << " ";
			ptr= ptr->next;
		}
	}
};

int main() {

	link linked_list;

	//linked_list.insert_end(1);
	//linked_list.insert_end(2);
	linked_list.insert_end(3);
	linked_list.insert_start(0);

	//printing linked listtt

	cout << " Elements are ";

	// Print the list
	linked_list.PRINT();
	cout << "\n linked list after deletion " << endl;

	linked_list.del();

	linked_list.PRINT();

	return 0;
}