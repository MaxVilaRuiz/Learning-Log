#include <iostream>
using namespace std;

void change_c1(int& lx_old, int& lx, int& px_old, int px) {
    if (lx_old < lx) {
        lx_old = lx;
        lx = 0;
        px_old = px;
    }
}

void output(int lx_old, int lx, int px_old, int px, char x) {
    if (lx_old == 0) cout << '"' << x << '"' << " = 0";
    else if (lx_old < lx) cout << '"' << x << '"' << " = " << lx << '(' << px << ')';
    else cout << '"' << x << '"' << " = " << lx_old << '(' << px_old << ')';

    if(x != 'T') cout << ", ";
    else cout << endl;
}

int main() {
    int la, lc, lg, lt;
    int la_old, lc_old, lg_old, lt_old;
    int pa, pc, pg, pt;
    int pa_old, pc_old, pg_old, pt_old;
    int posicio;

    char c1, c2;
    while (cin >> c1) {
        la = 0, lc = 0, lg = 0, lt = 0;
        la_old = 0, lc_old = 0, lg_old = 0, lt_old = 0;
        pa = 0, pc = 0, pg = 0, pt = 0;
        pa_old = 0, pc_old = 0, pg_old = 0, pt_old = 0;
        posicio = 1;

        if (c1 != '.') {
            if (c1 == 'A') la++, pa = 1;
            else if (c1 == 'C') lc++, pc = 1;
            else if (c1 == 'G') lg++, pg = 1;
            else lt++, pt = 1;

            while (cin >> c2 and c2 != '.') {
                posicio++;

                if (c1 == c2) {
                    if (c1 == 'A') la++;
                    else if (c1 == 'C') lc++;
                    else if (c1 == 'G') lg++;
                    else lt++;
                }
                else {
                    if (c1 == 'A') change_c1(la_old, la, pa_old, pa);
                    else if (c1 == 'C') change_c1(lc_old, lc, pc_old, pc);
                    else if (c1 == 'G') change_c1(lg_old, lg, pg_old, pg);
                    else change_c1(lt_old, lt, pt_old, pt);

                    if (c2 == 'A') {
                        la++;
                        pa = posicio;
                    }
                    else if (c2 == 'C') {
                        lc++;
                        pc = posicio;
                    }
                    else if (c2 == 'G') {
                        lg++;
                        pg = posicio;
                    }
                    else {
                        lt++;
                        pt = posicio;
                    }
                }

                c1 = c2;
            }

            if (c1 == 'A') change_c1(la_old, la, pa_old, pa);
            else if (c1 == 'C') change_c1(lc_old, lc, pc_old, pc);
            else if (c1 == 'G') change_c1(lg_old, lg, pg_old, pg);
            else change_c1(lt_old, lt, pt_old, pt);
                        
        }
        
        output(la_old, la, pa_old, pa, 'A');
        output(lc_old, lc, pc_old, pc, 'C');
        output(lg_old, lg, pg_old, pg, 'G');
        output(lt_old, lt, pt_old, pt, 'T');
    } 
}