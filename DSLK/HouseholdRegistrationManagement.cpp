#include <iostream>
#include <string.h>
using namespace std;

struct xe {
    char soXe[9];
    char hieuXe[30];
    xe* tiep;
};

struct con {
    char MSCN[7];
    char hoTenC[30];
    con* noi;
};

struct HK {
    char soHK[9];
    char hoTenChuHo[30];
    con* conl;
    xe* xel;
    HK* sau;
};

HK* dauhk;

void khoiTao(HK*& dauhk) {
    dauhk = NULL;
}

void nhapXe(xe*& dau) {
    xe* p, * q;
    char soXeTmp[9];
    do {
        cout << "Nhap so xe, go enter de dung: ";
        fflush(stdin);
        gets(soXeTmp);
        if (strcmp(soXeTmp, "\0") != 0) {
            p = new xe;
            strcpy(p->soXe, soXeTmp);
            cout << "Nhap hieu xe: ";
            fflush(stdin);
            gets(p->hieuXe);
            p->tiep = NULL;
            if (dau == NULL)
                dau = p;
            else {
                q->tiep = p;
                q = p;
            }
        }
    } while (strcmp(soXeTmp, "\0") != 0);
}

void nhapCon(con*& dau) {
    // Implement the function body for nhapCon
}

void qlkh(HK*& dauhk) {
    HK* p, * q;
    char soHKtmp[9];
    do {
        cout << "Nhap so ho khau: ";
        fflush(stdin);
        gets(soHKtmp);
        if (strcmp(soHKtmp, "\0") != 0) {
            p = new HK;
            strcpy(p->soHK, soHKtmp);
            cout << "Nhap ho ten chu ho: ";
            fflush(stdin);
            gets(p->hoTenChuHo);
            p->xel = NULL;
            p->conl = NULL;
            p->sau = NULL;
            nhapCon(p->conl);
            nhapXe(p->xel);
            if (dauhk == NULL)
                dauhk = p;
            else {
                q->sau = p;
                q = p;
            }
        }
    } while (strcmp(soHKtmp, "\0") != 0);
}

int demcon(con* x) {
    if (x == NULL)
        return 0;
    else
        return 1 + demcon(x->noi);
}

void hienthi(HK* dauhk) {
    if (dauhk != NULL) {
        cout << dauhk->soHK << " " << dauhk->hoTenChuHo;
        cout << "So con: " << demcon(dauhk->conl);
        hienthi(dauhk->sau);
    }
}

int main() {
    khoiTao(dauhk);
    qlkh(dauhk);
    hienthi(dauhk);

    return 0;
}
