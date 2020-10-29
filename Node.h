/*
This class is an implementation of the LinkedList's Node
*/

#ifndef NODE_H
#define NODE_H

typedef int Type;

class Node
{
private:
	Type data;
	Node* next;
public:
	Node(Type item, Node* ptr = nullptr);		//c'tor with a default value for this->next
	~Node();
	void InsertAfter(Node* newNode);			//insert a Node so that this->next points at it
	Type GetData();								//get the Node's data
	Node* GetNext();							//get the next Node
};

#endif // !NODE_H
