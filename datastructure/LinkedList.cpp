#include <cstdio>
using namespace std;
class Node{
	public:
	int data;
	Node *next = NULL;
};
class LinkedList{
	private:
		Node *head = new Node();
		int count = 0;
	public:
		void push(int data);
		void pop(int id);
		void printID(int id);
		void size();
		void printAll();
};
void LinkedList::push(int data){
	if(count==0){
		head->data = data;
		head->next = NULL;
	}else{
		Node* newNode = new Node();
		newNode->data = data;
		Node* iter = head;
		while(iter->next!=NULL)iter = iter->next;
		iter->next = newNode;
	}
	count++;
}
void LinkedList::pop(int id){
	Node* iter = head;
	if(count>id){
		while(id-->1)iter = iter->next;
		Node* tmp = iter->next->next;
		delete iter->next;
		iter->next = tmp;
		count--;
	}
}
void LinkedList::printID(int id){
	Node* iter = head;	
	if(count>id){
		while(id-->0)iter = iter->next;
		printf("%d\n", iter->next->data);
	}
}
void LinkedList::size(){
	printf("%d\n", count);
}
void LinkedList::printAll(){
	Node* iter = head;
	printf("%d ",iter->data);
	while(iter->next!=NULL){
		iter = iter->next;
		printf("%d ",iter->data);
	}
	printf("\n");
}
int main(){
	LinkedList* LL = new LinkedList();
	for(int i = 0; i < 5; i++)LL->push(i);
	LL->size();
	LL->pop(3);
	LL->size();
	LL->printAll();
}
