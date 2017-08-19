#include "bits/stdc++.h"
using namespace std;

class node{
public:
	int data;
	node *next;
};

int main(int argc, char const *argv[])
{
	node *head = new node();
	node *first;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;

		node *newnode = new node();
		newnode->data = temp;
		newnode->next = NULL;
		if(i == 0)
			first = newnode;
		head->next = newnode;
		head = head->next;
	}

	first->next->next->next = first->next;
	int visited[10000] = {0};

	memset(visited, 0, sizeof visited);

	while(first != NULL){
		if(visited[first->data]){
			cout << "loop";
			return 0;
		}
		visited[first->data] = 1;
		first = first->next;
	}

	cout << "no loop";
	return 0;
}