#include"Stack.h"
#include"Queue.h"

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackDestort(&s);
}

void TestQueue()
{
	Queue p;
	QueueInit(&p);

	QueuePush(&p, 1);
	QueuePush(&p, 2);
	QueuePush(&p, 3);
	QueuePush(&p, 4);

	while (!QueueEmpty(&p))
	{
		printf("%d ", QueueFront(&p));
		QueuePop(&p);
	}

	QueueDestory(&p);

}

int main()
{
	//TestStack();
	TestQueue();
	return 0;
}