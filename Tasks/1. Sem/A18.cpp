/*
Rihards Reiniks 20038

A18. Doti divi naturāli skaitļi. Noteikt, vai šie skaitļi ir savstarpēji pirmskaitļi.

Programma izveidota: 2020/10/7
*/


#include <iostream>
using namespace std;

class ListElem{
    public:
        int num;
        ListElem * next;
};

void add_elem(ListElem * &first, int num){
    ListElem * t = new ListElem();
    t->num = num;
    t->next = 0;

    if(first == 0){
        first = t;
    }else{
        t->next = first;
        first = t;
    }
}

void print_list(ListElem * first){
    for(ListElem * curr = first; curr != 0; curr = curr->next){
        cout << curr->num << endl;
    }
    cout << "</>" << endl;
}

int main (){
    ListElem * first = 0;
    add_elem(first,2);
    add_elem(first,5);
    add_elem(first,7);
    print_list(first);


   /* cout << first << endl;
    first = new ListElem();
    cout << first << endl;
    cout << first->num << endl;
    cout << first->next << endl;

    first->num = 2;
    first->next = 0;

    cout << first->num  << endl;
    cout << first->next << endl;

    ListElem * sec = 0;
    sec = new ListElem();
    cout << sec << endl;

    sec->num = 5;
    sec->next = 0;

    cout << sec->num  << endl;
    cout << sec->next << endl;

    ListElem * third = 0;
    third = new ListElem();
    cout << third << endl;

    third->num = 7;
    third->next = 0;

    cout << third->num  << endl;
    cout << third->next << endl;

    first->next = sec;
    sec->next = third;

    cout << first->next << endl;
    cout << sec->next << endl;
    */
}
