/*
Rihards Reiniks rr20038

03.03.2021

F4. Dots teksta fails f.
Uzrakstīt programmu, kura atrod failā f visus vārdus,
kas satur apakšvirkni m. Izvadīt šos vārdus failā f1.
Par vārdu uzskatīt patvaļīgu simbolu virkni,
kas atdalīta ar tukšumiem vai pieturas zīmēm
(punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).
Drīkst uzskatīt, ka vārda garums nepārsniedz 40.

*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main (){
int ok = 1;
do{

string m;   //apaksvirkne
string rinda;   //visai rindai
string word = "";    //vardam
int i = 0;
int check = 0;

fstream fin ("f.txt", ios::in);
fstream fout ("f1.txt", ios::out);

cout << "Ievadiet apaksvirkni: ";
cin >> m;



while (getline(fin, rinda)){    //apstrada teksta failu pa rindinai
    if(word != ""){
        if(word.find(m) != string::npos)fout << word << ' ';   //kad sakas jauna rinda japarbauda vai nav iesakts vards no ieprieksejas rindas
        word = "";
    }
    for(auto x : rinda){
        if (x == ',' || x == '.' || x == '!' || x == '?' || x == ' ' || x == '(' || x == ')'){ //nosaka vardu beigas
            if(word.find(m) != string::npos)fout << word << ' ';   //izvada vārdu ja taja ir apaksvirkne m
            word = "";  //sak vārdu no jauna
        }else{
            word = word + x;   //veido vardu pa burtam
        }
    }

}
fin.close();
fout.close();
cout << "Repeat?(1)";
cin >> ok;
}while(ok == 1);
return 0;
}
