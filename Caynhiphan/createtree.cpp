#include <iostream>

struct nut {
    int info;
    nut *left, *right;
};
typedef nut Node;

void khoiTao(Node *&root) {
    root = NULL;
}

void mocNut(Node *&root, int x) {
    if (root == NULL) {
        root = new Node;
        root->info = x;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (root->info >= x)
            mocNut(root->left, x);
        else
            mocNut(root->right, x);
    }
}

void taoCay(Node *&root) {
    int tmp;
    do {
        std::cout << "Nhap so nguyen, 0 de dung: ";
        std::cin >> tmp;
        if (tmp != 0)
            mocNut(root, tmp);
    } while (tmp != 0);
}
// Duyệt cây LRN
void duyetLNR(Node *root) {
    if(root != NULL) {
    duyetLNR(root->left);
    std::cout<<root ->info<<" ";
    duyetLNR(root->right);
    }
}

// Duyệt cây RLN
void duyetRLN(Node *root) {
    if(root != NULL) {
    duyetRLN(root->right);
    duyetRLN(root->left);
    std::cout<<root->info<<" ";
    }
}

// Duyệt cây NRL
void duyetNRL(Node *root) {
    if(root != NULL) {
    std::cout<<root->info<<" ";
    duyetNRL(root->right);
    duyetNRL(root->left);
    }
}

// Đếm số nút, tính tổng các nút
int demSoNut(Node *root) {
    if(root ==NULL)
    return 0;
    return 1 + demSoNut(root->left) + demSoNut(root->right);
}
int tongNut(Node *root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->info;
    return root->info + tongNut(root->left) + tongNut(root->right);
}

// Đếm số lá, in các giá trị lá, tính tổng lá
int demLa(Node *root)
{
    if(root == NULL)
        return 0;
    if((root->left == NULL) && (root->right == NULL))
        return 1;
    return demLa(root->left) + demLa(root->right);
}
void inLa(Node *root)
{
    if(root != NULL)
        if((root->left == NULL) && (root->right == NULL))
            std::cout<<root->info<<" ";
        else
        {
            inLa(root->left);
            inLa(root->right);
        }
}   
int tongLa(Node *root)
{
    if(root == NULL)
        return 0;
    if((root->left == NULL) && (root->right == NULL))
        return root->info;
    return tongLa(root->left) + tongLa(root->right);
}

// Đếm các nút chẵn
int demChan(Node *root)
{
    if(root == NULL)
        return 0;
    if((root->info % 2) == 0)
        return 1 + demChan(root->left) + demChan(root->right);
    return demChan(root->left) + demChan(root->right);
}

// Chiều cao của cây
int max(int a, int b)
{
    if(a>=b)
        return a;
    return b;
}

int chieuCao(Node *root)
{
    if(root == NULL)
        return 0;
    return 1 + max(chieuCao(root->left), chieuCao(root->right));
}

// Mức thứ i, tính tổng giá trị ở mức thứ i
void inMuci(Node *root, int i, int muc = 1)
{
    if(root != NULL)
        if(muc == i)
            std::cout<<root->info<<" ";
        else
    {
            inMuci(root->left, i, muc+1);
            inMuci(root->right, i, muc+1);
    }
}
int tongMuci(Node *root, int i, int muc = 1)
{
    if(root == NULL)
        return 0;
    if(muc == i)
        return root->info;
    return tongMuci(root->left, i, muc+1) + tongMuci(root->right, i,muc+1);
}

//Tìm vị trí của phần tử mang giá trị x
Node *tim(Node *root, int x)
{
    if(root == NULL)
        return NULL;
    if(root->info = x);
        return root;
    if(root->info > x)
        return tim(root->left, x);
    return tim(root->right, x);
}

// Đếm số nút có tổng cây con trái lớn hơn  tổng cây con phải
int demNutTongTraiPhai(Node *root)
{
    if(root == NULL)
        return 0;
    if ((tongNut(root->left)) > (tongNut(root->right)))
        return 1 + demNutTongTraiPhai(root->left) + demNutTongTraiPhai(root->right);
    return demNutTongTraiPhai(root->left) + demNutTongTraiPhai(root->right);
}

// Sao chép cây
void saoChep(Node *root, Node *&root1)
{
    if(root == NULL)
        root1 = NULL;
    else
    {
        root1 = new Node;
        root1->info = root->info;
        saoChep(root->left, root1->left);
        saoChep(root->right, root1->right);
    }
}

// Đếm gốc cây con trái mang giá trị chẵn, gốc  cây con phải mang giá trị lẻ
int demLcRl(Node *root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL || root->right == NULL)
        return demLcRl(root->left) + demLcRl(root->right);
    if(root->left->info %2 == 0 && root->right->info %2 !=0)
        return 1 + demLcRl(root->left) + demLcRl(root->right);
    return demLcRl(root->left) + demLcRl(root->right);
}

// Kiểm tra cây có phải cây nhị phân  tìm kiếm không
int KTcayNPTK(Node *root)
{
    if (root == NULL)
        return 1;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        if(root->left == NULL) KTcayNPTK(root->right);
        else
            if(root->right == NULL) KTcayNPTK(root->left);
            else
                if(root->left->info > root->info || root->right->info < root->info)
    return 0;
}

int main() {
    Node *root, *root1;
    khoiTao(root);
    taoCay(root);
    //
    duyetLNR(root);
    //
    duyetRLN(root);
    //
    duyetNRL(root);
    //
    demSoNut(root);
    tongNut(root);
    //
    demLa(root);
    inLa(root);
    tongLa(root);
    //
    demChan(root);
    //
    int a,b;
    printf("Nhap a va b:"); scanf("%d %d", &a, &b);
    max(a,b);
    chieuCao(root);
    //
    std::cout << "In muc i 1: ";
    inMuci(root, 1);
    std::cout << std::endl;
    std::cout << "Tong muc i 2: " << tongMuci(root, 2) << std::endl;
    
    int x= 5;
    Node *result_node = tim(root, x);
    if (result_node != nullptr) {
        std::cout << "Found node with value " << x << ". Node info: " << result_node->info << std::endl;
    } else {
        std::cout << "Node with value " << x << " not found." << std::endl;
    }
    // 
    demNutTongTraiPhai(root);
    //
    khoiTao(root1);
    saoChep(root, root1);
    // 
    demLcRl(root);
    //
    KTcayNPTK(root);

}

   
