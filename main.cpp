#include <iostream>
using namespace std;

int main() {
   
    
    int n, i, j, p, d, x, t;

    cout << "Quanti numeri?" << endl;
    cin >> n;
    int v[n];

    i = 0;
    p = 0;
    d = 0;
    while (i < n) {
        x = rand() % (n * 10) + 1;
        v[i] = x;
        if (x % 2 == 0) {
            p = p + 1;
        } else {
            d = d + 1;
        }
        i = i + 1;
    }
    int pa[p];
    int di[d];

    i = 0;
    d = 0;
    p = 0;
    while (i < n) {
        if (v[i] % 2 == 0) {
            pa[p] = v[i];
            p = p + 1;
        } else {
            di[d] = v[i];
            d = d + 1;
        }
        i = i + 1;
    }
    bool scambio;

    scambio = true;
    i = 0;
    while (i <= p && scambio) {
        j = 0;
        scambio = false;
        while (j <= p - 2 - i) {
            if (pa[j] > pa[j + 1]) {
                t = pa[j];
                pa[j] = pa[j + 1];
                pa[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    scambio = true;
    i = 0;
    while (i <= d && scambio) {
        j = 0;
        scambio = false;
        while (j <= d - 2 - i) {
            if (di[j] > di[j + 1]) {
                t = di[j];
                di[j] = di[j + 1];
                di[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    cout << "pari" << endl;
    i = 0;
    while (i < p) {
        cout << pa[i] << endl;
        i = i + 1;
    }
    cout << "dispari" << endl;
    i = 0;
    while (i < d) {
        cout << di[i] << endl;
        i = i + 1;
    }
    int k, b, i1, i2;

    k = d + p;
    int l[k];

    b = 0;
    i1 = 0;
    i2 = 0;
    while (i1 < d && i2 < p) {
        if (di[i1] <= pa[i2]) {
            l[b] = di[i1];
            i1 = i1 + 1;
        } else {
            l[b] = pa[i2];
            i2 = i2 + 1;
        }
        b = b + 1;
    }
    while (i1 < d) {
        l[b] = di[i1];
        b = b + 1;
        i1 = i1 + 1;
    }
    while (i2 < p) {
        l[b] = pa[i2];
        b = b + 1;
        i2 = i2 + 1;
    }
    cout << "Vettore l" << endl;
    b = 0;
    while (b < k) {
        cout << l[b] << endl;
        b = b + 1;
    }
    int valore;

    cout << "Quale valore" << endl;
    cin >> valore;
    int inizio, fine, medio, indice;

    indice = (int) (-1);
    inizio = 0;
    fine = k - 1;
    while (inizio < fine && indice == -1) {
        medio = (int) ((double) (inizio + (fine - inizio)) / 2);
        if (valore == l[medio]) {
            indice = medio;
        } else {
            if (valore > l[medio]) {
                inizio = medio + 1;
            } else {
                fine = medio - 1;
            }
        }
    }
    if (indice != -1) {
        cout << "Il valore è stato trovato nella cella " << indice << endl;
    } else {
        cout << "Il valore non è presente" << endl;
    }
    
}



