#include <iostream>

using namespace std;

int main(){

srand(time(NULL));

int x[50];
int y[50];
int z[50];
int l = 0;
int xx = 49;
int yy = 49;
cout << "Pirma skaitlu virkne" << endl;
for(int i = 0; i < 50; i++) x[i] = cin >> x[i];

cout << "Otra skaitlu virkne" << endl;
for(int i = 0; i < 50; i++) y[i] = cin >> y[i];

for(int i = 0; i <= xx; i++){
    for(int k = i + 1; k <= xx; k++){
        if(x[k] == x[i]){
            int temp = x[xx];
            x[xx] = x[k];
            x[k] = temp;
            xx--;
        }
    }
}




for(int i = 0; i <= yy; i++){
    for(int k = i + 1; k <= yy; k++){
        if(y[k] == y[i]){
            int temp = y[yy];
            y[yy] = y[k];
            y[k] = temp;
            yy--;
        }
    }
}


for(int i = 0; i <= xx; i++){
    for(int k = 0; k <= yy; k++){
        if(x[i] == y[k]){
            z[l] = x[i];
            l++;
        }

    }
}

cout << "Skelums: " << endl;
for(int i = 0; i < l; i++) cout << z[i] << endl;


delete x;
delete y;
delete z;
return 0;
}
