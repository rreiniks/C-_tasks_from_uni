/*
Rihards Reiniks rr20038

G14. Uzrakstīt funkciju, kas no dotā saraksta izveido 2 jaunus tā,
lai jaunajos būtu visas vērtības no dotā saraksta,
bet vienā būtu visas pāra vērtības, otrā – nepāra
(dotajam sarakstam pēc funkcijas izpildes ir jāsaglabājas).

Darbs veikts 21.04.2021
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

//Ievieto vērtību sarakstā
void insert(Node** root, int item){
    Node *ptr, *temp;   //Ievieto vērtību un norāda to, ka nākamā ir tukša
    temp = new Node;
    temp->data = item;
    temp->next = NULL;

    if (*root == NULL) *root = temp;    //Pārbauda vai šis elements nebūs pirmais sarakstā
    else{   //Ievieto vērtību vietā, kur jau nav cita vērtība (ir NULL)
        ptr = *root;
        while(ptr->next != NULL)ptr = ptr->next;    //Meklē kur beidzas vērtības
        ptr->next = temp;
    }
}

//Izvada sarakstu
void printList(Node* root){
    while(root != NULL){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

//Izdzēš sarakstu
void deleteList (Node* &root)
{
    Node *p = root;
    while (p!=NULL)
    {
        root = root->next;
        delete p;
        p = root;
    };
};

//Uzdevumā prasītā funkcija
Node* newLists(Node* root, Node* &root1, Node* &root2){
    Node *ptr = root;
    Node* ptr1 = NULL;
    Node* ptr2 = NULL;
    while(ptr != NULL){
        if((ptr->data)%2 == 0){
            if(root2 == NULL){
                Node* temp = new Node;
                temp->data = ptr->data;
                temp->next = NULL;
                root2 = temp;
            }else{
                insert(&root2, ptr->data);
            }
        }else{
            if(root1 == NULL){
                Node* temp = new Node;
                temp->data = ptr->data;
                temp->next = NULL;
                root1 = temp;
            }else{
                insert(&root1, ptr->data);
            }
        }
        ptr = ptr->next;
    }
}

int main(){
int d = 1;
do{

    Node *root = NULL, *root1 = NULL, *root2 = NULL;

    int n;
    cout << "Input list lenght: ";
    cin >> n;
    cout << endl;
    int in;

    for(int i = 0; i < n; i++){
        cout << "Input integer: ";
        cin >> in;
        insert(&root, in);
        cout << endl;
    }

    cout << "Input list: " << endl;
    printList(root);

    newLists(root, root1, root2);

    cout << "Input list after function: " << endl;
    printList(root);

    cout << "Odd: " << endl;
    printList(root1);
    cout << "Even: " << endl;
    printList(root2);

    deleteList(root);
    deleteList(root1);
    deleteList(root2);

cout << "Repeat (1) or finish (0)?" << endl;
cin >> d;
}while(d == 1);
}
