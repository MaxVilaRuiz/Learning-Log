#include <iostream>
using namespace std;

int main() {
    int n;
    int anterior = 0, pic = 0, posterior = 0;
    bool trobat = false;
    while ((cin >> n) and (n != 0)) {
        if ((anterior == 0) or (pic == 0) or (posterior == 0)) {
            if (anterior == 0) anterior = n;
            else if (pic == 0) pic = n;
            else if (posterior == 0) {
                posterior = n;

                if ((pic > 3143) and (anterior < pic) and (pic > posterior)) {
                    trobat = true;
                }
            }
        }
        else {
            if ((pic > 3143) and (anterior < pic) and (pic > posterior)) {
                trobat = true;
            }
            else {
                anterior = pic;
                pic = posterior;
                posterior = n;

                if ((pic > 3143) and (anterior < pic) and (pic > posterior)) {
                    trobat = true;
                }
            }
        }
    }
    if (trobat) cout << "SI" << endl;
    else cout << "NO" << endl;
}