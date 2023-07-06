#ifndef LAIKS_H
#define LAIKS_H

class Laiks
{
    private:
        int sekundes;
        int minutes;
        int stundas;
    public:
        Laiks(int h1,int m1,int s1);
        ~Laiks();
        void mainit(int sekundes_, int minutes_, int stundas_);
        void drukat();
        void distance(int sekundes_, int minutes_, int stundas_);
};

#endif
