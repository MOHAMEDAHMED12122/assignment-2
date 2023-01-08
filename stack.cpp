#include <iostream>
using namespace std;

class QueueWithArray
{
 	int arraySize;
	int* myArray;
	int front, rear;
	int counterSize;

public :

	QueueWithArray(int size)
	{
		myArray = new int[size];
		arraySize = size;
	
		front = rear = 0;
	}

	void Enqueue(int data)
	{

		if (counterSize == arraySize)
		{
			cout << "Queue is Full !";
		}

		else
		{
			myArray[rear] = data;

			rear = (rear + 1) % arraySize;

			counterSize++;
		}
	}

	int Dequeue()
	{
		if (counterSize == 0)
		{
			cout << "Queue is Empty !";
		}

		else
		{
			int numHodler = myArray[front];

			front = (front + 1) % arraySize;

			counterSize--;

			return numHodler;
		}
	}

	int Peek()
	{
		if (counterSize == 0)
		{
			cout << "Queue is Empty !";

			return -1;
		}

		return myArray[front];
	}

	string IsEmpty()
	{
		if (counterSize == 0)
			return "True";

		return "False";
	}

	string IsFull()
	{
		if (counterSize == arraySize)
			return "True";

		return "False";
	}
};

int main()
{
	QueueWithArray queue(3);

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	cout << "IsFull() : " << queue.IsFull() << "\n";

	cout << "Peek() : " << queue.Peek() << "\n";
	queue.Dequeue(); 

	queue.Enqueue(50);	//Circular Test

	cout << "Peek() : " << queue.Peek() << "\n";
	queue.Dequeue();

	cout << "Peek() : " << queue.Peek() << "\n";
	queue.Dequeue();

	cout << "Peek() : " << queue.Peek() << "\n";
	queue.Dequeue();

	cout << "IsEmpty() : " << queue.IsEmpty();
}