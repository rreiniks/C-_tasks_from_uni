#include <iostream>

using namespace std;

int main(){

int x,y;

int desas[3][3];

for (int i = 0; i < 3; i++){
    for(int k = 0; k < 3; k++){
        desas[i][k] = 0;
    }
}

int uzvaretajs = 0;
int i = 0;

while(i < 9){
    if(i <= 4){
        for(int l = 0; l < 3; l++){
            if(desas[l][0] == desas[l][1] && desas[l][0] == desas[l][2]){
                uzvaretajs = desas[l][0];
            }

            else if(desas[0][l] == desas[1][l] && desas[0][l] == desas[2][l]){
                uzvaretajs = desas[0][l];
            }
            else if(desas[0][0] == desas[1][1] && desas[0][0] == desas[2][2]){
                uzvaretajs = desas[0][0];
            }
            else if(desas[0][2] == desas[1][1] && desas[1][1] == desas[2][0]){
                uzvaretajs = desas[1][1];
            }
        }
    }

    if(i % 2 == 0){
        cout << "Pirma speletaja gajiens ";
        cin >> x >> y;
        while(desas[x][y] != 0){
            cout << "Tas laukums jau ir aiznemts, ludzu atkartot gajienu!" << endl;
            cout << "Pirma speletaja gajiens ";
            cin >> x >> y;
        }
        desas[x][y] = 1;
    }

    else{
        cout << "Otra speletaja gajiens ";
        cin >> x >> y;
        while(desas[x][y] != 0){
            cout << "Tas laukums jau ir aiznemts, ludzu atkartot gajienu!" << endl;
            cout << "Otra speletaja gajiens ";
            cin >> x >> y;
        }
        desas[x][y] = 2;
    }

    if(uzvaretajs == 1){
        cout << "Pirmais speletajs ir uzvarejis!!!";
        break;
    }else if(uzvaretajs == 2){
        cout << "Otrais speletajs ir uzvarejis";
        break;
    }

    if(i == 8) cout << "Neizskirts!";


i++;
}


return 0;
}
