#include <iostream>
using namespace std;
int queue[50];
int n = 50;
int front = - 1;
int rear = - 1;

void Q_insertion() {
   int val;
   if (rear == n - 1)
      cout<<"Queue Overflow"<<endl;
   else {
    
      front = 0;
      cout<<"Insert value in the queue : ";
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}

void Delete() {
   if (front == - 1) {
      cout<<"Queue Underflow ";
   return ;
   } else {
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      front++;;
   }
}

void Display_Q () {
   if (front == - 1 )
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
         cout<<queue[i]<<" ";
      cout<<endl;
   }
}
int main() {
   int ch;
   cout<<"1. Insert an element to the queue"<<endl;
   cout<<"2. Delete an element from the queue"<<endl;
   cout<<"3. Display all elements of the queue"<<endl;
   cout<<"4. Exit"<<endl;
do {
   cout<<"\nEnter your choice : ";
   cin>>ch;
   switch (ch) {
      case 1: Q_insertion();
         break;
      case 2: Delete();
         break;
      case 3: Display_Q ();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);
   return 0;
}
