#include <iostream>
using namespace std;
struct node
{
	double data;
	node * next;
};
class list
{
	private:
		node * first;
		node * last;
	public:
		list ()
		{
			first = NULL;
			last = NULL;
		}
		~list()
		{
		}
		void insert_in_last (double value);
		void insert_at_position(double value,int pos);
		void insert_in_start (double value);
		void remove_first();
		void remove_at_position(int pos);
		void remove_last();
		void print ();
		void print_pos (int pos);
};
int main()
{
	list l;
	l.insert_at_position(5.4,1);
	l.insert_in_last(25);
	l.insert_in_last(50);
	l.insert_in_last(90);
	l.insert_in_last(40);
	l.insert_in_last(55);
	l.print();
	l.insert_in_last(15);
	l.print();
	l.insert_in_start(10);
	l.print();
	l.remove_first();
	l.print();
	l.remove_last();
	l.print();
	l.remove_at_position(4);
	l.print();
	l.insert_at_position(60,3);
	l.print();
	return 0;
}
void list::insert_in_last(double value)
{
	node * temp = new node;
	temp->data=value;
	temp->next=NULL;
	if(first==NULL)
	{
		first = temp;
		last = temp;
	}
	else
	{
		last->next=temp;
		last=temp;
	}
}
void list::insert_at_position(double value, int pos)
{
	node*temp_1=new node;
	temp_1->data=value;
	temp_1->next=NULL;
	if (pos==1)
	{
		if ((first == NULL)&&(last==NULL))
		{
			first=temp_1;
			last=temp_1;
			return;
		}
		temp_1->next=first;
		first=temp_1;
		return;
	}
	node*temp_2;
	temp_2=first;
	for(int i=0; i<pos-2; i++)
		temp_2=temp_2->next;
	if (temp_2==last)
	{
		temp_2->next=temp_1;
		last=temp_1;
		return;
	}
	temp_1->next=temp_2->next;
	temp_2->next=temp_1;
}
	void list::insert_in_start(double value)
{
	node * temp = new node;
	temp->data=value;
	if(last==NULL)
	{
		first=temp;
		last=temp;
		return;
	}
	temp->next=first;
	first=temp;
}
void list::print()
{
	node*temp;
	temp=first;
	cout<<"Data in the list : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}
void list::print_pos(int pos)
{
	node*temp;
	temp=first;
	for (int i=0; i<pos-1; i++)
	{
		temp=temp->next;
	}
	cout<<"Data at position "<<pos<<" : "<<temp->data<<endl;
}
void list::remove_first()
{
	node*temp;
	temp=first;
	first=first->next;
	delete temp;
}
void list::remove_at_position(int pos)
{
	node*temp_1;
	temp_1=first;
	if (pos==1)
	{
		first=first->next;
		delete temp_1;
		return;
	}
	node*temp_2;
	temp_2=first;
	for(int i=0; i<pos-2;i++)
	{
		temp_2=temp_2->next;
	}
	if(temp_2->next==last)
	{
		temp_1=last;
		delete temp_1;
		last=temp_2;
		temp_2->next=NULL;
		return;
	}
	temp_1=temp_2->next;
	temp_2->next=temp_1->next;
	delete temp_1;
}
void list::remove_last()
{
	node*temp;
	temp=first;
	while(temp->next!=last)
	{
		temp=temp->next;
	}
	delete temp->next;
	last=temp;
	last->next=NULL;
}

