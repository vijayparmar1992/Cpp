#include<iostream>

using namespace std;

class Linklist
{
private:
	struct node
	{
		int data;
		node* link;
	}*p;
public:
	Linklist()
	{
		p = NULL;
	}
	~Linklist()
	{
		node* temp;

		while (p != NULL)
		{
			temp = p->link;
			delete p; //delete current node
			p = temp;//assign next node to p
		}
		cout << "Destructor called " << endl;
	}

	void append(int num)
	{
		node *temp,*r;
		//if this is the first element
		if (p == NULL)
		{
			temp = new node;
			temp->data = num;
			temp->link = NULL;
			p = temp;
		}
		else
		{
			temp = p; //assign first element of linklist
			while (temp->link != NULL)//traverse upto end
				temp = temp->link;
			r = new node; //new node
			r->data = num;
			r->link = NULL; //last node is NULL
			temp->link = r; //assign add. of last node to p. node

		}
	}
	void display()
	{
		cout << "Displaying node elements" << endl;
		node* temp;
		temp = p;
		if (temp == NULL)
		{
			cout << "no element" << endl;
			return;
		}
		while (temp->link != NULL)
		{
			cout << temp->data << endl;
			temp = temp->link;
		}
		cout << temp->data << endl;// to print last character
	}
	void deleteNode(int num)
	{
		node* temp, *old=new node;
		temp = p; //assign to traverse

		while (temp->data != num)//traverse untill u get number
		{
			old = temp; //store old node data
			temp = temp->link;//point towards next node for next iteration
		}
		if (temp == p)//Means this is the first node
		{
			p = temp->link; //now p will point to next node
			delete temp;
		}
		else //node is between nodes
		{
			old->link = temp->link; //preious node point to next(require to delete) to next node
			delete temp;
		}
	}


};


int main()
{
	Linklist l;
	l.append(12);
	l.append(34);
	l.append(1);
	l.append(67);
	l.append(7);
	l.append(-100);
	l.append(555);
	l.deleteNode(7); //mid delete
	l.deleteNode(12);
	l.deleteNode(555);
	l.deleteNode(-100);
	l.deleteNode(34);
	l.deleteNode(1);
	//l.deleteNode(67);
	l.display();
	l.append(12);
	l.append(34);
	l.append(1);
	l.append(67);
	l.append(7);
	l.display();
	l.~Linklist();
	l.display();
	return 0;
}
