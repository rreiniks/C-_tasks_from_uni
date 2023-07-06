/*
Rihards Reiniks rr20038

B12. Dots naturals skaitlis n. Uzrakstit funkciju, kas atrod n-to Fibonaci skaitli.
(Fibonaci skaitlus define sekojosi: f(1) = 1, f(2) = 1, f(n) = f(n-1) + f(n-2), t. i. f(3)=2, f(4)=3, f(5)=5 utt.)
Bez tam uzrakstit nerekursîvu funkciju, kas dotajam naturalam skaitlim pasaka, vai tas ir Fibonaci skaitlis.

Programma izveidota: 10/13/2020
*/


#include <iostream>
using namespace std;

int fibonacci(int f){   //izveido funkciju, lai noteiktu vai ievaditais skaitlis ir fibonaci skaitlis

if(f < 0){  //fibonaci skaitlu virkne sakas no nulles
    cout << "Ievaditais skaitlis nav fibonaci skaitlis (nav naturals skaitlis)" << endl;
    return 0;
}
else if (f == 0){   //nultais virknes loceklis ir 0
    cout << "Ievaditais skaitlis ir fibonaci skaitlis (bet nav naturals skaitlis)" << endl;
    return 0;
}
else{
int a = 0;
int b = 1;
int c = 0;
do{ //cikls parbauda vai ievaditais skaitlis ir fibonaci skaitlu virkne sakot ar 1 virknes locekli
c = a + b;
if(f == c){ //ja ievaditais skaitlis sakrit ar ieprieksejo divu fibonaci skaitlu summu, tad tas ir fibonaci skaitlis
    cout << "Ievaditais skaitlis ir fibonaci skaitlis" << endl;
return 0;
}
a = b;
b = c;
}while(f >= c);
}
cout << "Ievaditais skaitlis nav fibonaci skaitlis" << endl;    //cikls beidzies - nav fibonaci skaitlis
return 0;
}

int main (){
    int ok;
    do{ //cikls atkārtotai izpildei
        int n, a, b, c;
        cin >> n;
        if (n < 0){ //fibonaci skaitlu virknes kartas numuram jabut naturalam skaitlim vai 0.
            cout << "Ievaditi nepareizi dati" << endl;
        }else if (n == 0){  //nultais loceklis nav ieklauts cikla
            cout << '0' << endl;
        }
        else{
            a = 0;
            b = 1;
            for(int i = 2; i <= n; i++){    //cikls kas aprekina n-to fibonaci skaitli
                c = a + b;
                a = b;
                b = c;
            }
            cout << b << endl;
        }
        fibonacci (n);  //izsauc izveidoto funkciju
        cout << "Turpinat (1) vai beigt (0)?" << endl;
        cin >> ok;
    }while (ok == 1);
}
