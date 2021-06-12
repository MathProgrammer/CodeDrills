// Custom list node. DO NOT MODIFY.
#include <deque>
#include <iostream>
using namespace std;

template <typename T>
class ListNode {
public:
	T value;
	ListNode<T>* next;
	ListNode(T value) {
		this->value = value;
		this->next = nullptr;
	}
};

class ReorderingList {
public:
	ListNode<int>* reorderList(ListNode<int>* list) {
		deque <ListNode <int>* > Q;
		
		while(list != NULL)
		{	//cout << "Pushing " << list->value << " ";
			Q.push_back(list);
			list = list->next;
		}
		
		ListNode <int> *head = nullptr, *current;
		
		if(Q.size() > 0)
		{
			head = Q.front();
			current = Q.front(); //cout << "Q " << current->value;
			Q.pop_front();
		}
	
		if(Q.size() > 0)
		{
			current->next = Q.back();
			current = current->next;
			Q.pop_back();
		}
		
		while(Q.size() > 0)
		{
			current->next = Q.front();
			Q.pop_front();
			current = current->next;
			
			if(Q.size() > 0)
			{
				current->next = Q.back();
				Q.pop_back();
				current = current->next;
			}
		}
		
		if(head != NULL)
		{
			current->next = NULL;
		}
		
		return head;
	}
};
