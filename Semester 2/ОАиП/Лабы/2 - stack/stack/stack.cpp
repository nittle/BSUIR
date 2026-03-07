#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Stack {
	int info;
	Stack* next;
} *stack_begin, * t;

// Add element to stack
Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

// View the whole stack
void View(Stack* p) {
	Stack* t = p;
	while (t != NULL) {
		cout << " " << t->info << endl;
		t = t->next;
	}
}

// Free memory used by stack
void Del_All(Stack** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

// Pop element out of stack
Stack* OutStack(Stack* p, int* out) {
	Stack* t = p;
	*out = p->info;
	p = p->next;
	delete t;
	return p; 
}

bool Ind(Stack* p) {
	if (p == NULL)
		return false;

	Stack* t = p;
	while (t != NULL && t->next != NULL) 
		t = t->next;

	if (p == t) return false;

	int buff = p->info;
	p->info = t->info;
	t->info = buff;

	return true;
}

void Sort_p(Stack** p) {
	Stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void Sort_info(Stack* p) {
	Stack* t = NULL, * t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}

void main()
{
	srand(time(NULL));
	int newp = 0;

	int i, in, n, kod;
	while (true) {
		cout << "1 - Create.\n2 - Add.\n3 - View.\n4 - Del.\n5 - Pop element\n6 - ind.\n7 - sort\nEXIT - 0.\n: ";
		cin >> kod;
		switch (kod) {
		case 1: case 2:
			if (kod == 1 && stack_begin != NULL) {
				// Clean memory before creating a new stack
				cout << "Clear Memory!" << endl;
				break;
			}
			cout << "Input kol = "; cin >> n;
			for (i = 1; i <= n; i++) {
				in = rand() % 201 - 100;
				stack_begin = InStack(stack_begin, in);
			}
			if (kod == 1) cout << "Create " << n << endl;
			else cout << "Add " << n << endl;
			break;
		case 3: if (!stack_begin) {
			cout << "Stack is clear!" << endl;
			break;
		}
			  cout << "--- Stack ---" << endl;
			  View(stack_begin);
			  break;
		case 4:
			Del_All(&stack_begin);
			cout << "Memory Free!" << endl;
			break;
		case 5:
			int out;
			stack_begin = OutStack(stack_begin, &out);
			cout << "Popped element " << out << endl;
			break;
		case 6:
			if (Ind(stack_begin))
				cout << "Success" << endl;
			else
				cout << "Nothing happened" << endl;
			break;
		case 7:
			int kod2;
			cout << "1 - info sort\n2 - pointer sort\n: ";
			cin >> kod2;
			switch (kod2)
			{
			case 1:
				Sort_info(stack_begin);
				cout << "Sorting by info..." << endl;
				break;
			case 2:
				
				stack_begin = InStack(stack_begin, 10);
				Sort_p(&stack_begin);
				stack_begin = OutStack(stack_begin, &newp);
				cout << "Sorting by pointers..." << endl;
				break;
			default:
				cout << "Wrong choice!" << endl;
				break;
			}
			break;
		case 0:
			if (stack_begin != NULL)
				Del_All(&stack_begin);
			return;
		}
	}
}