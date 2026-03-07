#include <iostream>
using namespace std;

struct Spis2 {
	int info;
	Spis2* next, * prev;
} *queue_begin, *queue_end, *t;

void Create_Spis2(Spis2** b, Spis2** e, int in) {
	t = new Spis2;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}
void Add_Spis2(int kod, Spis2** b, Spis2** e, int in) {
	t = new Spis2;
	t->info = in;
	if (kod == 0) {
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;
	}
	else {
		t->next = NULL;
		t->prev = *e;
		(*e)->next = t;
		*e = t;
	}
}
void View_Spis2(int kod, Spis2* t) {
	while (t != NULL) {
		cout << t->info << endl;
		if (kod == 0) t = t->next;
		else t = t->prev;
	}
}
void Del_All(Spis2** b) {
	while (*b != NULL) {
		t = *b;
		*b = (*b)->next;
		delete t;
	}
}

void Ind(Spis2* entry_point) {
	Spis2* t = entry_point;
	while (t->next != NULL) {
		t = t->next;
	}
	int buff = entry_point->info;
	entry_point->info = t->info;
	t->info = buff;
}
void main()
{
	int i, in, n, kod, kod1;
	char Str[2][10] = { "Begin ", "End " };
	while (true) {
		cout << "Create - 1\nAdd - 2\nView - 3\nDel - 4\n\Ind. - 5\nEXIT - 0\n: ";
		cin >> kod;
		switch (kod) {
		case 1: 
			if (queue_begin != NULL) {
				cout << "Clear memory before creating!" << endl;
				break;
			}
			cout << "Start info = "; cin >> in;
			Create_Spis2(&queue_begin, &queue_end, in);
			cout << "Created with starting info = " << queue_begin->info << endl;
			break;
		case 2:
			cout << "Info = "; cin >> in;
			cout << "Add to start - 0, Add to end - 1 : "; cin >> kod1;
			Add_Spis2(kod1, &queue_begin, &queue_end, in);
			if (kod1 == 0) t = queue_begin;
			else t = queue_end;
			cout << "Added to " << Str[kod1] << " " << t->info << endl;
			break;
		case 3: 
			if (!queue_begin) {
			cout << "Stack is empty!" << endl;
			break;
			}
			cout << "View from start - 0,View from end - 1: ";
			cin >> kod1;
			if (kod1 == 0) {
				t = queue_begin;
				cout << "-- Begin --" << endl;
			}
			else {
				t = queue_end;
				cout << "--- End --" << endl;
			}
			View_Spis2(kod1, t);
			break;
		case 4:
			Del_All(&queue_begin);
			cout << "Memory has been freed!" << endl;
			break;
		case 5:
			Ind(queue_begin);
			break;
		case 0: 
			if (queue_begin != NULL)
				Del_All(&queue_begin);
			return;
		}
	}
}