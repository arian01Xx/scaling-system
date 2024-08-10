#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution{
public:
	int getDecimalValue(ListNode* head){
		int num=0;
		while(head!=NULL){
			num=num*2+head->val;
			head=head->next;
		}
		return num;
	}
};

class SolutionOne{
public:
	ListNode* middleOne(ListNode* head){
		ListNode* slow=head;
		ListNode* fast=head;
		while(fast!=NULL && fast->next!=NULL){
			slow=slow->next;
			fast=fast->next->next;
		}
		return slow;
	}
};

class SolutionSecond{
public:
	ListNode* reverseList(ListNode* head){
		ListNode* prev=NULL;
		ListNode* curr=head;
		while(curr!=NULL){
			//1->2->3->4->5->NULL
			ListNode* forward=curr->next; //2
			curr->next=prev; //1->NULL
			prev=curr; //prev NULL ahora es 1, el nuevo final
			curr=forward; //el actual ahora es 2
		}
		return prev;
	}
};

ListNode* createdLinkedList(vector<int> nodes){
	ListNode* head=new ListNode(0);
	ListNode* temp=head; //apunta a la cabeza
	for(int node: nodes){
		temp->next=new ListNode(node); //el siguiente puntero
		//con un valor del vector
		temp=temp->next;
	}
	return head->next; //empieza desde el segundo elemento que es next
}

void printLinkedList(ListNode* root){
	while(root!=nullptr){
		cout<<root->val<<"->";
		root=root->next; //root se actualiza con el siguiente puntero
	}
	cout<<endl;
}

int main(){

	Solution solution;
	vector<int> inputOne={1,0,1};
	ListNode* input=createdLinkedList(inputOne);
	int outputOne=solution.getDecimalValue(input);
	cout<<"----Binary Problem----"<<endl;
	cout<<"Linked List Original: "<<endl;
	printLinkedList(input);
	cout<<"Converted from Binary to Decimal: "<<endl;
	cout<<outputOne<<endl;
	cout<<endl;

	SolutionOne solution1;
	vector<int> nodes={1,2,3,4,5,6};
	ListNode* inputFirst=createdLinkedList(nodes);
	ListNode* outputFirst=solution1.middleOne(inputFirst);
	cout<<"----MiddleNode Problem----"<<endl;
	cout<<"Original Linked List: "<<endl;
	printLinkedList(inputFirst);
	cout<<"MiddleOne: "<<endl;
	printLinkedList(outputFirst);
	cout<<endl;

	SolutionSecond solution2;
	vector<int> nodes2={1,2,3,4,5,6,7,8,9};
	ListNode* input2=createdLinkedList(nodes2);
	ListNode* output2=solution2.reverseList(input2);
	cout<<"---Reverse Problem---"<<endl;
	cout<<"Original Linked List: "<<endl;
	printLinkedList(input2);
	cout<<"Reverse Linked List: "<<endl;
	printLinkedList(output2);
	cout<<endl;

	return 0;
}