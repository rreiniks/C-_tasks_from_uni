#include "Laiks.h"
#include <iostream>

using namespace std;

Laiks::Laiks(int h1,int m1,int s1){    //konstruktors
    sekundes = s1;
    minutes = m1;
    stundas = s1;
}

Laiks::~Laiks(){    //destruktors

}


void Laiks::drukat(){

    cout << stundas << ":" << minutes << ":" << sekundes << endl;

}

void Laiks::mainit(int sekundes_, int minutes_, int stundas_){

    sekundes = sekundes_;
    minutes = minutes_;
    stundas = stundas_;

cout << "Vertibas nomainitas:" << endl;
cout << stundas << ":" << minutes << ":" << sekundes << endl;

}

void Laiks::distance(int sekundes_, int minutes_,int stundas_){ //nosaka distanci starp dotajam un objekta vertibam

int sek1 = sekundes;
int min1 = minutes;
int stu1 = stundas;

min1 = min1 + (stu1 * 60);  //parveido stundas par minutem (objekta dati)
sek1 = sek1 + (min1 * 60);  //parveido minutes par sekundem (objekta dati)

minutes_ = minutes_ + (stundas_ * 60);  //parveido stundas par minutem (ievaditie dati)
sekundes_ = sekundes_ + (minutes_ * 60);    //parveido minutes par sekundem (ievaditie dati)

if(sekundes_ > sek1){   //nosaka kura vertiba lielaka nakamajam darbibam
    int temp = sek1;
    sek1 = sekundes_;
    sekundes_ = temp;
}
sek1 = sek1 - sekundes_;    //salidzina laiku tikai sekundes
min1 = sek1 / 60;   //parveido sekundes minutes
stu1 = min1 / 60;   //parveido minutes stundas

cout << "Atskiriba sekundes: " << sek1 << "s" << endl;

sek1 = sek1 % 60;   //nosaka atlikumu sekundem pec parveidosanas minutes

cout << "Atskiriba minutes: " << min1 << "m " << sek1 << "s " << endl;

min1 = min1 % 60;   //nosaka atlikumu minutem pec parveidosanas stundas

cout << "Atskiriba stundas: " << stu1 << "h " << min1 << "m " << sek1 << "s" << endl;

}
