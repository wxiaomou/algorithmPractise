#include<iostream>
#include<string>

using namespace std;

struct Node {
	int val;
	Node *next;
	Node (int _val) : val(_val) {};
};

class Solution {
	public:
		Node *insert(Node *head, int val) {
			if (!head) {
				head = new Node(val);
				head->next = head;
				return head;
			}
			Node *tmp = new Node(val);
			// place behand head
			Node *cur = head;
			if (val < head->val) {
				while (cur->next != head) cur = cur->next;
				cur->next = tmp;
				tmp->next = head;
				return tmp;
			} else {
				while (cur->next != head && cur->next->val < val) cur = cur->next;
				tmp->next = cur->next;
				cur->next = tmp;
			}
			return head;
		}
};

void printList(Node *start)
{
	  Node *temp;
		 
		if(start != NULL)
	 {
	    temp = start;
			cout << endl;
	    do {
		      cout << temp->val << " ";
		      temp = temp->next;
	    } while(temp != start);
	  }
}

int main()
{
	  int arr[] = {12, 56, 2, 11, 1, 90};
	  int list_size, i;
			 
	  /* start with empty linked list */
	  Node *start = NULL;
		Solution sol;
					 
	  /* Create linked list from the array arr[].
		 *     Created linked list will be 1->2->11->56->12 */
	  for(i = 0; i< 6; i++)
	  {
			start = sol.insert(start, arr[i]);
	  }
				 
	  printList(start);
	  return 0;
}

