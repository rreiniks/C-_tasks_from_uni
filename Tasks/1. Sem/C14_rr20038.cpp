/* C14
Doti n naturâli skaitïi a(1), ... a(n).
Atrast doto salikto skaitïu (t.i., kas nav pirmskaitïi)
lielâko kopîgo dalîtâju,
izmantojot divas funkcijas: kas  atrod divu skaitïu lielâko
kopîgo dalîtâju un kas atpazîst pirmskaitli.
*/
#include <iostream>
#include <stdio.h>  //NULL
#include <stdlib.h> //srand, rand//
#include <time.h>   //time//
using namespace std;

bool pirmskaitlis(int n){   //funkcija lai noteiktu vai ir pirmskaitlis

bool irps = true;
/*if(n == 1){       viens nav pirmskaitlis bet nav ari salikts skaitlis.
    irps = false;
}else if (n > 1){*/
    for(int i = 2; i <= (n/2); i++){ //cikls līdz n/2 jo ja nebus dalitajs lidz skaitla pusei tad nebus ari talak.
        if (n % i == 0){
            irps = false;
            break;
        }
    }
//}
return irps;
}

int lkd(int a, int b){  //funkcija kas nosaka lielako kopigo dalitaju

if(b > a){  //sakarto ta lai a > b
int temp = a;
a = b;
b = temp;
}

int c, d, lkd;

for(int i = a; i > 0; i--){ //cikls nosaka LKD
    c = b % i;
    d = a % i;
    if(c == 0 && d == 0){
        lkd = i;
        break;
    }
}
return lkd;
}


int main(){
int ok;
do{ //cikls programmas atkartoanai

srand(time(NULL));  //seed prieks rand funkcijas

int n, m;
cout << "Ievadi virknes garumu: ";
cin >> n;

cout << "Ievadi merogu virknei: ";
cin >> m;

int *virkne = new int[n];   //dinamisks masivs prieks sakuma virknes

for(int i = 0; i < n; i++){ //aizpilda masivu ar random n vertibam

    virkne[i] = rand()%m + 1;

}

cout << "Generetie skaitli: " << endl;

for(int i = 0; i < n; i++){ //uzgenereta masiva izvade
    cout << virkne[i] << endl;
}

int k = 0;

for(int i = 0; i < n; i++){ //Nosaka cik pirmskaitli ir masiva
    if(pirmskaitlis(virkne[i])) k++;
}

int s = (n-k);  //nosaka garumu salikto skaitlu masivam

int *ssk = new int[s];  //izveido salikto skaitlu masivu

int l = 0;

for(int i = 0; i < n; i++){ //ievieto saliktos skaitlus masiva
    if(pirmskaitlis(virkne[i])) continue;
    else{
    ssk[l] = virkne[i];
    l++;
    }
}
cout << endl << "Saliktie skaitli: " << endl;

for(int i = 0; i < s; i++){ //izvada jauno masivu
    cout << ssk[i] << endl;
}
int dal = 10000000;
for(int i = 0; i < (s/2)+1; i++){   //atrod LKD katram skaitlim ar vienu citu skaitli.
    int temp = lkd(ssk[i],ssk[s-i]);
    if (temp < dal) dal = temp; //saglaba tikai mazako LKD
}

for(int i = 0; i < s; i++){ //parbauda vai visiem skaitliemm der ieprieks atrastais LKD
    while((ssk[i]%dal) != 0){   //ja neder tad velk kvadratsakn no skaitla lidz skaitlis dalas
        int temp = dal;
        dal = temp/dal;
    }

}

cout << "LKD ir: " << dal << endl;

delete virkne;
delete ssk;

cout << "Turpinat(1) vai beigt(0)?" << endl;

cin >> ok;

}while(ok == 1);
return 0;
}
