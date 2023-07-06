#include <iostream>

using namespace std;

int main(){

int x[20];

for(int i = 1; i <= 20; i++){
    cout << "Ievadi " << i << ". zena augumu ";
    cin >> x[i-1];
    for(int k = i; k > 0; k--){
        if (x[k-1] > x[k-2] && i > 1){
            int temp = x[k-1];
            x[k-1] = x[k-2];
            x[k-2] = temp;
        }
    }
    cout << "Ierinda: ";
    for(int k = 0; k < i; k++)cout << x[k] << " ";
    cout << endl;
}

return 0;
}
