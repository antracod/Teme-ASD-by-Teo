#include <iostream>
using namespace std;

struct nod {

    int info;
nod *next;

};

 nod *prim = NULL, *ultim = NULL;

void af() {

    if (prim == NULL) cout << "lista vida\n";
nod *p = prim;

    while (p != NULL)

    { 
cout << p->info << " ";
p = p->next;
    }
    cout << "\n";
}
void adi(int x) {
    if (prim == NULL)
    {
        prim = new nod;
        prim->info = x;
        prim->next = NULL;
        ultim = prim;
        return;

    }

    nod *p = new nod;
    p->info = x;
    p->next = prim;
    prim = p;

}
void adf(int x) {

    if (prim == NULL) {
        prim = new nod;
        prim->info = x;
        prim->next = NULL;
        ultim = prim;
        return;

    }

    nod *p = new nod;
    p->info = x;
    ultim->next = p;
    ultim = p;
    ultim->next = NULL;

}
int cv(int x) {

    int k = 0;
    nod *p = prim;
    while (p != NULL) {

        k++;
        if (p->info == x) return k;
        p = p->next;

    }

    return -1;

}
int cp(int k) {

    int s = 1;
    nod *p = prim;
    while (s < k && p->next != NULL) {

        p = p->next;
        s++;

    }

    if (s < k) return -1;
    return p->info;

}
void iv(int val, int x) {

    nod *p = prim;
    while (p->next != NULL && p->next->info != val) {

        p = p->next;
    }
    if (p == ultim) {

        if (p->info != val) return;
        nod *q = new nod;
        q->info = x;
        q->next = NULL;
        ultim->next = q;
        ultim = q;
    }
    nod *q = new nod;
    q->info = x;
    q->next = p->next;
    p->next = q;

}
void ip(int k, int x) {

    if (k == 1) {
        nod *p = new nod;
        p->info = x;
        p->next = prim;
        prim = p;
        return;
    }
    int s = 1;
    nod *p = prim;
    while (s < k - 1 && p->next != NULL) {
        p = p->next;

    }
    nod *q = new nod;
    q->info = x;
    q->next = p->next;
    p->next = q;
    if (p == ultim) {
        ultim = q;

    }
}
void sv(int x) {

    if (prim == ultim && prim->info == x) {
        delete prim;
        prim = NULL;
        return;

    }
    if (prim->info == x) {

        nod *b = prim;
        prim = prim->next;
        delete b;
        return;

    }
    nod *p = prim;
    while (p->next != NULL && p->next->info != x) {
        p = p->next;

    }

    if (p == ultim) { 
        return;

    }

    if (p->next == ultim) ultim = p;
    nod *b = p->next;
    p->next= p->next->next;
    delete b;

}
void sp(int k) {

    if (k == 1 && prim == ultim) {
        delete prim;
        prim = NULL;
        return;

    }

    if (k == 1) {

        nod *b = prim;
        prim = prim->next;
        delete b;
        return;
    }

    nod *p = prim;
    int s = 1;
    while (s < k - 1 && p->next != NULL) {
        p = p->next;
        s++;
    }

    if (p == ultim) return;//lista are mai putin de k elemente
    if (p->next == ultim) ultim = p;
    nod *b = p->next;
    p->next = b->next;
    delete b;

}

int main() {

    int q;
    int x, k, val;
    do {
        cin >> q;

        if (q == 1) {
            cin >> x;
            adi(x);
        }
        if (q == 2) {
            cin >> x;
            adf(x);
        }
        if (q == 3) {
        af();
        }
        if (q == 4) {
            cin >> x;
            cout << cv(x) << "\n";
        }
        if (q == 5) {
            cin >> k;
            cout << cp(k) << "\n";
        }
        if (q == 6) {
            cin >> val >> x;
            iv(val, x);
        }
        if (q == 7) {
            cin >> k >> x;
            ip(k, x);
        }
        if (q == 8) {
            cin >> x;
            sv(x);
        }
        if (q == 9) {
            cin >> k;
            sp(k);
        }
    } while (q != 0);
}