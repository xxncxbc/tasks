#ifndef CLASSES_H
#define CLASSES_H
#include <math.h>
#include <vector>
using namespace std;

class prime{
public:
    prime(){}
    bool isprime(int x){
        if(x == 1) return false;
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }

        return true;
    }
    vector<int> factorize(int x){
        vector<int> factor;
        for (int i = 2; i <= sqrt(x); i++) {
            while (x % i == 0) {
                if(isprime(i)){
                    factor.push_back(i);
                    x /= i;
                }
            }
        }
        if (x != 1) {
            factor.push_back(x);
        }
        return factor;
    }
    int check(int x){
        vector<int> a = factorize(x); int res = 1;
        for(int i: a){
            res *= i;
        }
        return res;
    }
};


class taylor{
public:
    taylor(){}
    double series(double x, double eps){
        double sum=x, h; int i=4;
        h=(-1)*(pow(x,3)/6);
        do{
            sum+=h;  //Формула очередного слагаемого
            h*=(-1)*((pow(x,2)/((i)*(i+1))));
            i+=2;}
        while( fabs(h)>eps );
        return sum;
    }
};

class sq_eq{
public:
    sq_eq(){}
    vector<double> solve(double a, double b, double c){
        double x1, x2, d; vector<double> sol;
        d = b * b - 4 * a * c; // Рассчитываем дискриминант
        if (d > 0) // Условие при дискриминанте больше нуля
        {
            x1 = ((-b) + sqrt(d)) / (2 * a);
            x2 = ((-b) - sqrt(d)) / (2 * a);
            sol.push_back(x1);
            sol.push_back(x2);
        }
        if (d == 0) // Условие для дискриминанта равного нулю
        {
            x1 = -(b / (2 * a));
            sol.push_back(x1); sol.push_back(x1);
        }
        return sol;
    }
};
#endif // CLASSES_H
