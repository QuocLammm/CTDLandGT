#include <string.h>
#include<stdio.h>

struct nut
{
    char Data[80];
    nut *sau,*truoc;
};
typedef nut Node;

Node *dau;
Node *dau1;
int i;
void khoitao(Node *&dau)
{
    dau=NULL;
}
void nhapvb(Node *&dau)
{
    char tam[80];
    Node *q,*p;
    do
    {
        printf("Nhap vao dong van ban, Enter dung: ");
        fflush(stdin);
        gets(tam);
    if(strcmp(tam,"\0")!=0)
    {
        p=new Node;
        strcpy(p->Data,tam);
        p->sau=NULL;
        p->truoc=NULL;
        if(dau==NULL)
            dau=p;
        else
        {
            q->sau=p;
            p->truoc=q;
        }
    q=p;
    }
}
    while(strcmp(tam,"\0")!=0);
}

void duyetvb(Node *dau)
{
    if(dau!=NULL)
    {
    printf("\n%s",dau->Data);
    duyetvb(dau->sau);
    }
}

void indongi(Node *dau, int i,int dem=1)
{
    if(dau!=NULL)
    {
        if(dem==i)
            printf("\n%s",dau->Data);
        else
            indongi(dau->sau,i,dem+1);
    }
}

void indongi2(Node *dau,int i)
{
    int dem;
    Node *p;
    p=dau;
    dem=1;
    while((p!=NULL)&&(dem!=i))
    {
        p=p->sau;
        dem=dem+1;
    }
    if(p!=NULL)
        printf("\ndong %d la:\n%s",i,p->Data);
}

void inij(Node *dau, int i, int j)
{
    int dem;
    Node *p,*q;
    if(j>=i)
    {
        // tim i
        dem=1;
        p=dau;
        while(p!=NULL&&dem!=i)
            {
            p=p->sau;
            dem=dem+1;
            }
        if(p!=NULL)
        {
        // tim j
        q=p;
        while(q!=NULL&&dem!=j)
    {
    q=q->sau;
    dem=dem+1;
}
// in ra dong i den dong j.
    if(q!=NULL)
        while(p!=q->sau)
            {
            printf("\n%s",p->Data);
            p=p->sau;
            }
        }
    }
}

void xoadongi(Node *&dau,int i)
{
    Node *p,*q,*t;
    int dem;
    p=dau; dem=1;
    while(p!=NULL&&dem!=i)
    {
        p=p->sau;
        dem=dem+1;
    }
    if(p!=NULL)
    {
        if(p==dau)
        {
            dau=dau->sau;
            dau->truoc=NULL;
            delete p;
        }
        else
            if(p->sau==NULL)
            {
                q=p->truoc;
                q->sau=NULL;
                delete p;
            }
            else
            {
            q=p->truoc;
            t=p->sau;
            q->sau=t;
            t->truoc=q;
            delete p;
        }
    }
}

void xoadongidq(Node *&dau,int i,int dem=1)
{
    Node *p;
    if(dau!=NULL)
    {
        if(dem==i)
        {
            p=dau;
            dau=dau->sau;
            dau->truoc=NULL;
            delete p;
        }
        else
            xoadongidq(dau->sau,i,dem+1);
    }
}

void chepij(Node *dau, int i, int j, Node *&dau1)
{
    int dem;
    Node *p,*q,*t,*l;
    if(j>=i)
    {
        // tim i
        dem=1;
        p=dau;
        while(p!=NULL&&dem!=i)
        {
            p=p->sau;
            dem=dem+1;
        }
        if(p!=NULL)
        {
        // tim j
            q=p;
            while(q!=NULL&&dem!=j)
            {
                q=q->sau;
                dem=dem+1;
            }
        // in ra dong i den dong j.
            if(q!=NULL)
            while(p!=q->sau)
            {
                //printf("\n%s",p->Data);
            t=new Node;
            strcpy(t->Data,p->Data);
            t->sau=NULL;t->truoc=NULL;
            if (dau1==NULL)
                dau1=t;
            else
            {
                l->sau=t;
                t->truoc=l;
            }
            l=t;
            p=p->sau;
            }
        }
    }
}

void chendong(Node *&dau,int i, int j, int k)
{
    int m;
    Node *v,*u,*w;
    v=dau;
    m=1;
    chepij(dau,i,j,dau1);
    while(v!=NULL&&m!=k)
    {
        v=v->sau;
        m=m+1;
    }
    if(v!=NULL)
    { // v tro den dong k
        u=dau1;
        while(u->sau!=NULL)
        u=u->sau;
    // u la dong cuoi cua ds dau1
        w=v->sau; // dong sau dong k
        v->sau=dau1;
        dau1->truoc=v;
        u->sau=w;
        w->truoc=u;
    }
}

void xoaij(Node *&dau,int i, int j)
{
    Node *p,*q,*u,*v;
    int dem;
    if(i<j)
    {
        dem=1;
        p=dau;
        while(p!=NULL&&dem!=i)
        {
            p=p->sau;
            dem=dem+1;
        }
        q=p;
        if(p!=NULL)
        {
            while(q!=NULL&&dem!=j)
            {
                q=q->sau;
                dem=dem+1;
            }
            if(q!=NULL)
            {
                u=p->truoc;
                u->sau=q->sau;
                q->sau=v; v->truoc=u;
                while(p!=q)
                {
                    delete p;
                    p=p->sau;
                }
            }
        }
    }
}