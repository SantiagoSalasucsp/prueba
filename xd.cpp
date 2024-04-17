#include <iostream>
using namespace std;

struct nodo
{
    int tam = 5;
    nodo* next;
    nodo* prev;
    int* M;
    nodo(nodo* n, nodo* p)
    {

        next = n;
        prev = p;
        M = new int[tam];
    }
};


struct Elementor {

    int* I;
    int* F;

    nodo* ini;
    nodo* fin;

    Elementor(nodo* n, nodo* p);

    int faid(int val, int*& a, nodo*& tmp);
    void add(int val);
    void del(int val);
    void print();
};


Elementor::Elementor(nodo* n, nodo* p) {
    ini = new nodo(NULL, NULL);
    I = ini->M;
    fin = ini;
    F = NULL;
}

int Elementor::faid(int val, int*& a, nodo*& tmp) {
    if (F == NULL) {
        a = I;
        F = I;
        return 0;
    }
    else {

        if (val<*I || val>*F) {
            if (val < *I) {
                a = I;
                tmp = ini;
                return 1;
            }
            else {
                a = F;
                return 2;
            }
        }

        else {
            int* t = I;
            tmp = ini;
            int tam = 5;
            while (*t < val) {
                if (t + 1 == tmp->M + tam) {
                    tmp = tmp->next;
                    t = tmp->M;
                }
                else {
                    t++;
                }

            }
            a = t;
            return 3;
        }




    }

}

void Elementor::add(int val) {
    int* a;
    nodo* tmp;
    int y = faid(val, a, tmp);
    int tam = 5;
    if (y == 0) {
        *a = val;
    }
    if (y == 2) {
        if (F + 1 == fin->M + tam) {
            fin->next = new nodo(NULL, fin);
            fin = fin->next;
            F = fin->M;
            *F = val;
        }
        else {
            F++;
            *F = val;
        }
    }
    if (y == 1) {
        int xd=0;
        while (*a <= *F) {
            
            int v = *a;
            *a = val;
            val = v;
            if (a + 1 == tmp->M + tam) {
                if (F + 1 == fin->M + tam) {
                    int tmp4 = *F;
                    fin->next = new nodo(NULL, fin);
                    fin = fin->next;
                    F = fin->M;
                    *F = tmp4;
                    tmp = tmp->next;
                    a = tmp->M;
                    //*a = val;
                    xd=1;
                    continue;
                }
                tmp = tmp->next;
                a = tmp->M;
                continue;
            }
            if (a == F) {
                 break;
            }
            a++;
        }
        if(xd==0){
            F++;
            *F=val;
            //F++;
            //*a=val
        }
        else{
            
        }


    }

    if (y == 3) {
        int xd = 0;
        while (*a <= *F) {
            int v = *a;
            *a = val;
            val = v;
            if (a + 1 == tmp->M + tam) {
                if (F + 1 == fin->M + tam) {
                    int tmp4 = *F;
                    fin->next = new nodo(NULL, fin);
                    fin = fin->next;
                    F = fin->M;
                    *F = tmp4;
                    tmp = tmp->next;
                    a = tmp->M;
                    //*a = val;
                    xd = 1;
                    continue;
                }
                tmp = tmp->next;
                a = tmp->M;
                continue;
            }
            if (a == F) {
                break;
            }
            a++;
        }
        if (xd == 0) {
            F++;
            *F = val;
            //F++;
        }
        else {

        }


    }



}


void Elementor::del(int val) {
    int* a;
    nodo* tmp;
    int y = faid(val, a, tmp);
    int tam = 5;
    if (y == 0 || y == 1 || y == 2) {
        cout << "el elemento no esta aqui" << endl;
    }
    if (y == 3) {
        while (*a <= *F) {
            int* b = a;
            if (a == F) {
                if (F == fin->M) {
                    fin = fin->prev;
                    F = fin->M + tam - 1;
                }
                else {
                    F--;
                }
                break;
            }
            if (a + 1 == tmp->M + tam) {
                tmp = tmp->next;
                a = tmp->M;
                *b = *a;
                continue;
            }
            a++;
            *b = *a;
            b = a;
        }
        /*if (F == fin->M) {
            fin = fin->prev;
            F = fin->M + tam - 1;
        }*/

    }
    
}

void Elementor::print() {
    int* a = I;
    nodo* tmp = ini;
    int tam = 5;
    cout << "[";
    int y = 1;
    
    while (true) {
        if (tmp == fin) {
            break;
        }
        else {
            tmp = tmp->next;
            y++;
        }
    }


    nodo* tmp2 = ini;
    for (; y > 0; y--) {
        //cout<<"y es: "<<y<<endl;
        int* c = tmp2->M;
        for (int* a = c; a <= tmp2->M + 4; a++) {
            if ( a > F && a<fin->M+5) {
                cout << "-,";
            }
            else {
                cout << *a << ",";
            }
        }
        tmp2 = tmp2->next;
        cout << "]->[";
        //cout<<"saltamos "<<y<<endl;
    }
    cout << "]";
    cout << endl;

}



int main() {
    Elementor x(NULL, NULL);
    /*x.add(3);
    x.add(4);
    x.add(7);
    x.add(9);
    x.add(11);
    x.add(12);
    x.add(13);
    x.add(2);
    x.del(3);
    x.add(15);
    x.print();
    */

    /*
   x.add(1);
   x.add(2);
   x.add(3);
   x.add(4);
   x.add(5);
   x.add(6);
   x.add(7);
   x.add(8);
   x.add(9);
   x.add(10);
   x.print();
   x.add(0);
   x.print();
   */
    
/*
    x.add(0);
    x.add(1);
    x.add(3);
    x.add(4);
    x.add(5);
    x.print();
    x.add(2);
    x.print();
    x.del(6);
    x.print();
*/
    x.add(10);
    x.print();
    x.add(7);
    x.print();
    x.add(9);
    x.print();
    x.add(3);
    x.print();
    x.add(4);
    x.print();
    x.add(0);
    x.print();
    x.add(56);
    x.print();
    x.add(1);
    x.print();
    x.add(23);
    x.print();
    x.add(11);
    x.print();
    x.add(8);
    x.print();
    x.del(10);
    x.print();
}