/* RR20038 Rihards Reiniks
D19
"Izveidot klasi ""Laiks"", kura tiek glabati tris skaitli - stunda, minute, sekunde.
Klasei izveidot sadas metodes: (1) konstruktors, ar kuru tiek padotas sakotnejas vertibas,
(2) destruktors, kurs pazino par objekta likvidesanu,
(3) metode ""Mainit"" ar tris parametriem, kas uzstada jaunas vertibas,
(4) metode ""Drukat"", kas izdruka laiku,
(5) metode ""Distance"" ar tris parametriem - citu laika momentu,
kas aprekina un izdruka attalumu starp abiem laika momentiem gan sekundes, gan minutes,
gan apvienoti (stundas, minutes un sekundes)."
*/

#include <iostream>
#include "Laiks.cpp"
#include "Laiks.h"

using namespace std;


int main(){

Laiks l1(23, 24, 21);

l1.drukat();

l1.mainit(57, 36, 12);

l1.distance(56,35, 11);

return 0;   //automatiski izsauc destructor
}
