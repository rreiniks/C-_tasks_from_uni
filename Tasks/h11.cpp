/*H11. Uzrakstīt programmu, kas ļauj izveidot un labot bināru failu, kura ieraksta struktūra ir sekojoša:
vārds – atslēga (30 simboli), vārds – vērtība (30 simboli), ieraksta statuss (0 vai 1).
Programmai katrs jauns ieraksts jāieliek faila beigās. Jāparedz iespēja (1) izmest faila komponenti (loģiski atzīmējot kā izmestu),
(2) izdrukāt faila esošās komponentes uz ekrāna, (3) izmest loģiski izmestas komponentes fiziski.

Rihards Reiniks rr20038

Uzdevums veikts 21-06-2021
*/
#include <fstream>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class vards{
private:
    char atslega[30];
    char vertiba[30];
    bool b;

public:
    vards(const char* a, const char* v, bool bo);
    void print();
    void write(vards v);
    void logdel(char* a);
    bool read(ifstream &fin);
    void fizdel();
};

vards::vards(const char* a, const char* v, bool bo){
    strncpy(atslega, a, 30);
    strncpy(vertiba, v, 30);
    b = bo;

}

bool vards::read (ifstream &fin){   //nolasa komponenti no faila
    fin.read((char*)this, sizeof(vards)); // Nolasa komponenti
    return (bool)fin;
}

void vards::print(){    //parada komponenti uz ekrana
    cout << atslega << ' '<< vertiba << ' ' << b <<endl;
};

void vards::write(vards v){ //ieraksta bin faila
    ofstream fout("vards.bin", ios::binary | ios::app);
    fout.seekp(0, ios::end);    //lai rakstitu faila beigas
    fout.write((char *)&v, sizeof(vards));
    fout.close();
}

void vards::logdel(char *a){    //pieskir bool vertibu 0 failiem kur ir atbilstosa atslega

    int pos, flag = 0;
    fstream fs;
    fs.open("vards.bin", ios::in | ios::binary | ios::out);

    while(!fs.eof()){  //cikls mekle atslegu pec kuras nosaka kuru komponenti izmest

        pos = fs.tellg();       //Nosaka poziciju kura tagad lasa
        fs.read((char*)this, sizeof(vards));
        if(fs){
            int i = 0;
            if(strcmp(atslega,a)==0){   //salidzina vai atslega sakrit
                flag = 1;
                fs.seekp(pos);  //Nosaka kur rakstis pec ieprieks noteiktas pozicijas
                b = 0;
                fs.write((char*)this, sizeof(vards));
            }
        }
    }
fs.close();

if(flag == 1)cout << "Record successfully modified" << endl;


}

void vards::fizdel(){   //izdzes fiziski

    ifstream fin("vards.bin", ios::in | ios::binary);
    ofstream fout("temp.bin", ios::out | ios::binary);  //izveido jaunu failu kurs aizvietos originalo

    fin.read((char*)this, sizeof(vards));
    while(!fin.eof()){  //cikls parbauda vai bool vertiba ir 0, ja taa ir tiek izmesta komponente
        if(b == 0){
            cout << "Izdesa: " << atslega << ' ' << vertiba << endl;    //izvada izmesto komponenti

        }else{
            fout.write((char*)this, sizeof(vards));
        }
        fin.read((char*)this, sizeof(vards));
    }
fout.close();
fin.close();
remove("vards.bin");
rename("temp.bin","vards.bin");

}

int main(){
int ok = 1;
ifstream fin;
ofstream fout;
do{
    char x[30],y[30];
    vards printeris(x,y,1);


    cout << endl << "Tagadejie ieraksti:" << endl << endl;
    fin.open("vards.bin", ios::in | ios::binary);
    if(fin){
    printeris.read(fin);
    while(!fin.eof()){  //izdrukaa visas komponentes uz ekrana
        printeris.print();
        printeris.read(fin);
    }
    cout << endl;
    fin.close();
}

    cout << "Pievienot ierakstu (1), Logiski izdzest(2), Fiziski izdzest ierakstus(3), Beigt darbu(0): ";
    cin >> ok;
    switch(ok){
    case 0:
        break;
    case 1:{
        char x1[30],y1[30];                   //Ieraksta pievienosana
        cin >> x1 >> y1;
        vards v1(x1,y1,1);
        v1.write(v1);
        break;}
    case 2:{                      //Logiska dzesana
        char ch[30];
        char m[30];
        cin >> m;
        vards v(ch,m,1);
        strncpy(ch, m, 30);     //Nokope ka string lai var salidzinat ar to ko kope no binara faila
        v.logdel(ch);
        break;}
    case 3:{
        char l[30],k[30];
        vards d(l,k,1);                    //Fiziska dzesana
        d.fizdel();
        break;}
    }
}while(ok != 0);
}
