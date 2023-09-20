#include <iostream>
struct nut
{
    int giaTri;
    nut *tiep;
};
typedef nut Node;
Node *dau;

void khoiTao(Node *&dau)
{
    dau=NULL;
}

void nhapDS(Node *&dau)
{
    Node *p, *q;
    int x;
    do{
        std::cout<<"Nhap mot so nguyen, nhap 0 de dung: ";
        std::cin>>x;
        if(x!=0)
        {
            p = new Node;
            p->giaTri=x;
            p->tiep=NULL;
        if(dau==NULL)
            dau=p;
        else
            q->tiep=p;
            q=p;
        }
    }while(x!=0);
}

// Duyệt danh sách
void duyetDS(Node *dau)
{
    Node *p = dau;
    while (p != NULL)
    {
        std::cout << p->giaTri << " ";
        p = p->tiep;
    }
}

void duyetDeQuy(Node *dau)
{
    if (dau != NULL)
    {
        std::cout << dau->giaTri << " ";
        duyetDeQuy(dau->tiep);
    }
}

// Các phép toán trên danh sách
int tinhTong(Node *dau)
{
    if(dau==NULL)
        return 0;
    else
        return dau->giaTri + tinhTong(dau->tiep);
}

int tinhTongSoLe(Node *dau)
{
    if(dau==NULL)
        return 0;
    else
        if((dau->giaTri % 2) == 0)
            return tinhTongSoLe(dau->tiep);
        else
            return dau->giaTri + tinhTongSoLe(dau->tiep);
}

int demSoChan(Node *dau)
{
    if (dau==NULL)
        return 0;
    else
        if((dau->giaTri % 2) == 0)
            return 1 + demSoChan(dau->tiep);
        else
            return demSoChan(dau->tiep);
}

// Xắp sếp danh sách
void sapXep(Node *&dau)
{
    Node *p, *q;
    int tam;
    p=dau;
    while(p->tiep != NULL)
    {
        q=p->tiep;
        while(q!=NULL)
        {
            if(p->giaTri > q->giaTri)
            {
                tam=p->giaTri;
                p->giaTri = q->giaTri;
                q->giaTri = tam;
            }
            q=q->tiep;
        }
    p=p->tiep;
    }
}

// Thêm phần tử vào danh sách
void chenDau(Node *&dau, int x)
{
    Node *p = new Node;
    p->giaTri = x;
    p->tiep = dau;
    dau = p;
}

void chenThuTu(Node *&dau, int x)
{
    if (dau == NULL || dau->giaTri >= x)
        chenDau(dau, x);
    else
        chenThuTu(dau->tiep, x);
}

void chenCuoi(Node *&dau, int x)
{
    Node *p = new Node;
    p->giaTri = x;
    p->tiep = NULL;

    if (dau == NULL)
        chenDau(dau, x);
    else
    {
        Node *q = dau;
        while (q->tiep != NULL)
            q = q->tiep;
        q->tiep = p;
    }
}

void chenSau(Node *&dau, int x, int y)
{
    Node *p = dau;
    while (p != NULL && p->giaTri != y)
        p = p->tiep;

    if (p != NULL)
    {
        Node *q = new Node;
        q->giaTri = x;
        q->tiep = p->tiep;
        p->tiep = q;
    }
}

void chenTruoc(Node *&dau, int x, int y)
{
    Node *p = dau, *prev = NULL;

    while (p != NULL && p->giaTri != y)
    {
        prev = p;
        p = p->tiep;
    }

    if (p != NULL)
    {
        Node *q = new Node;
        q->giaTri = x;
        q->tiep = p;

        if (prev == NULL)
            dau = q; // Insert at the beginning
        else
            prev->tiep = q; // Insert in the middle
    }
}

// Xóa phần tử ra khỏi danh sách
void xoaDau(Node *&dau, int x) 
{
    Node *p;
    if(dau != NULL) 
    {
        p = dau;
        dau = dau->tiep;
        delete p;
    }
}
void xoaCuoi(Node *&dau, int x) {
    Node *p, *q;
    q = NULL;
    p = dau;
    while((p != NULL) && (p->tiep != NULL))
    {
        q = p;
        p = p->tiep;
    }
    if(p != NULL)
        if(p == dau)
        xoaDau(dau, x);
    else {
        q->tiep = NULL;
        delete p;
    }
}

// Đảo ngược danh sách
void daoNguocTaoDSMoi(Node *dau) {
    Node *p;
    while(p != NULL) {
        chenDau(dau, p->giaTri);
        p = p->tiep;
    }
}
void daoNguoc(Node *&dau) //Khong Tao DS Moi 
{
    Node *p, *q;
    q = NULL; p = NULL;
    while(dau != NULL) {
        p = dau;
        dau = dau->tiep;
        p->tiep = q;
        q = p;
    }
    dau = p;
}

// Tính tổng các nút có thứ tự lẻ
int tongTTLe(Node *dau) {
    Node *p;
    int dem = 0, sum =0;
    p = dau; 
    dem =1;
    while(p != NULL) {
    if(dem % 2 != 0)
        sum += p->giaTri;
        p = p->tiep;
        dem++;
    }
    return sum;
}

// Xóa nút trước nút cuối cùng
void xoaNutTruocNutCuoi(Node *&dau) {
    Node *p, *q, *t;
    p = dau;
    q = NULL, t = NULL;
    while(p->tiep != NULL)
    {
        t = q;
        q = p;
        p =
        p->tiep;
    }
    if(q != NULL) {
        if(q == dau) {
            dau = dau->tiep;
            delete q;
        }
        else {
            t->tiep = p;
            delete q;
        }
    }
}

//




int main()
{
    Node *dau = NULL;
    khoiTao(dau);
    nhapDS(dau);
    //
    duyetDS(dau);
    duyetDeQuy(dau);
    //
    tinhTong(dau);
    tinhTongSoLe(dau);
    demSoChan(dau);
    // 
    sapXep(dau);
    //
    chenDau(dau, 10);
    chenCuoi(dau, 20);
    chenSau(dau, 30, 20);
    chenTruoc(dau, 15, 20);
    //
    xoaDau(dau,10);
    xoaCuoi(dau,15);
    // 
    daoNguocTaoDSMoi(dau);
    daoNguoc(dau);
    //
    tongTTLe(dau);
    // 
    xoaNutTruocNutCuoi(dau);
    return 0;
}
