#include <iostream>
using namespace std;
#include <string>
#include <conio.h>
int i;
struct node
{
	string info;
	struct node *left;
	struct node *right;
};
typedef struct node NODEPTR;

NODEPTR *pbstree;		//proot binary search tree

NODEPTR* getnode()		//init for node of tree
{
	NODEPTR *p;
	p = new struct node;
	return p;
}

void freenode(NODEPTR *p)
{
	free(p);
}

void initialize(NODEPTR *&ptree)
{
	ptree = NULL;
}

bool empty(NODEPTR *ptree)
{
	return (ptree == NULL ? true : false);
}

NODEPTR* makenode(string x)
{
	NODEPTR *p;
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void setleft(NODEPTR *p, string x)
{
	if (p == NULL)
		cout << "P khong ton tai";
	else
		if (p->left != NULL)
			cout << "Nut P da co nut con trai";
		else
			p->left = makenode(x);
}

void setright(NODEPTR *p, string x)
{
	if (p == NULL)
		cout << "P khong ton tai";
	else
		if (p->right != NULL)
			cout << "Nut P da co nut con phai";
		else
			p->right = makenode(x);
}

string delleft(NODEPTR *p)
{
	NODEPTR *q;
	string x;
	if (p == NULL) cout << " P KHONG TON TAI";
	else
	{
		q = p->left;
		if (q == NULL)
			cout << " KHONG CO CON TRAI";
		else if (q->left == NULL && q->right == NULL)
		{
			x = q->info;
			p->left = NULL;
			freenode(q);
			return x;
		}
		else
			cout << "== KHONG XOA DUOC VI CO NUT CON! ==";

	}
	return x;
}

string delright(NODEPTR *p)
{
	NODEPTR *q;
	string x;
	if (p == NULL) cout << "P KHONG TON TAI! ";
	else
	{
		q = p->right;
		if (q == NULL)
			cout << " KHONG CO CON PHAI! ";
		else if (q->right == NULL && q->left == NULL)
		{
			x = q->info;
			p->right = NULL;
			freenode(q);
			return x;
		}
		else
			cout << "== KHONG XOA DUOC VI CO NUT CON! ==";

	}
	return x;
}

void pretrav(NODEPTR *proot)
{
	if (proot != NULL)
	{
		cout << proot->info << " ";
		pretrav(proot->left);
		pretrav(proot->right);
	}
}

void intrav(NODEPTR *proot)
{
	if (proot != NULL)
	{
		intrav(proot->left);
		cout << proot->info << " ";
		intrav(proot->right);
	}
}

void postrav(NODEPTR *proot)
{
	if (proot != NULL)
	{
		pretrav(proot->left);
		pretrav(proot->right);
		cout << proot->info << " ";
	}
}

NODEPTR* search_node(NODEPTR *proot, string x)
{
	NODEPTR *p;
	if (proot == NULL)
		return NULL;
	if (proot->info == x)
		return proot;
	p = search_node(proot->left, x);
	if (p == NULL)
		p = search_node(proot->right, x);
	return p;
}

void insert(NODEPTR *&proot, string x)
{
	NODEPTR *p, *q;
	if (proot == NULL)
	{
		proot = makenode(x);
	}
	else
	{
		q = proot;
		p = proot;
		while (x != p->info && q != NULL)
		{
			p = q;
			if (x < q->info)
				q = p->left;
			else
				q = p->right;
		}
		if (x == p->info)
		{
			cout << "BI TRUNG! , KHONG THEM DUOC, VUI LONG NHAP LAI GIA TRI\n"; i--;
		}
		else if (p->info > x)
			setleft(p, x);
		else setright(p, x);
	}
}
bool remove_node(NODEPTR *&proot, string x)
{
	if (proot == NULL) return false;
	else if (proot->info > x) return remove_node(proot->left, x);
	else if (proot->info < x) return remove_node(proot->right, x);
	else
	{
		NODEPTR *p;
		p = proot;
		if (proot->left == NULL) proot = proot->right;
		else if (proot->right == NULL) proot = proot->left;
		else
		{
			NODEPTR *s, *q;
			s = proot;
			q = s->left;
			while (q->right != NULL)
			{
				s = q;
				q = q->right;
			}
			p->info = q->info;
			s->right = q->left;
			delete q;
		}

	}
	return true;
}

/*
NODEPTR* remove_node(NODEPTR *&p)
{

NODEPTR *rp, *f;
if (p == NULL)
cout << "P khong ton tai. Khong the xoa duoc";
else
{
if (p->right == NULL)
rp = p->left;
else
if (p->left == NULL)
rp = p->right;
else
{
f = p;
rp = p->right;
while (rp->left != NULL)
{
f = rp;
rp = rp->left;
}
if (f != p)
{
f->left = rp->right;
rp->right = p->right;
rp->left = p->left;
}
else rp->left = p->left;
}
freenode(p);
return rp;
}
}
*/
void cleartree(NODEPTR *proot)
{
	if (proot != NULL)
	{
		cleartree(proot->left);
		cleartree(proot->right);
		freenode(proot);
	}
}

void Init()
{
	int n;

	string x;
	cout << "\n-----------------------------------------\n";
	cout << " CHUONG TRINH QUAN LI CHUOI KY TU";
	cout << "\n-----------------------------------------";
	cout << "\nCHUONG TRINH HIEN HANH: \" NHAP VAO CHUOI KI TU\"\n";
	cout << "-----------------------------------------";
	cout << "\n* NHAP SO LUONG: ";
	cin >> n;
	//initialize(pbstree);
	cin.ignore();
	cout << "\n* NHAP TUNG CHUOI KI TU: ";
	for (i = 0; i < n; i++)
	{
		getline(cin, x);
		insert(pbstree, x);
	}
	cout << "\n == DA NHAP XONG! NHAN ENTER DE QUAY VE MENU! ==";
	_getch();
	system("cls");
}
void Result()
{
	cout << "\n-----------------------------------------\n";
	cout << " CHUONG TRINH QUAN LI CHUOI KY TU";
	cout << "\n-----------------------------------------";
	cout << "\nCHUONG TRINH HIEN HANH: \"XUAT CAY\"\n";
	cout << "\n-----------------------------------------";
	cout << "\nXUAT CAY VUA NHAP: ";
	if (empty(pbstree) == true)
	{
		cout << "\nCAY RONG. VUI LONG NHAP VAO CHUOI KI TU CHO CAY.\n=> Nhap \"ENTER\" de quay ve Menu";
		_getch();
		return;
	}
	int chose;

	for (;;)
	{
		cout << "\n\t == CHON HINH THUC BAN MUON XUAT ==";
		cout << "\n-----------------------------------------";
		cout << "\n1) PreTrav (NLR)";
		cout << "\n2) InTrav (LNR)";
		cout << "\n3) PosTrav (NRL)";
		cout << "\n\nVUI LONG CHON HINH THUC XUAT : ";
		cin >> chose;
		cout << "\n";
		if (chose == 1) { pretrav(pbstree); break; }
		if (chose == 2) { intrav(pbstree); break; }
		if (chose == 3) { postrav(pbstree); break; }
		cout << "\nNHAP SAI. VUI LONG NHAP LAI! \n";
	}

	cout << endl;
	cout << "\n=> NHAP \"ENTER\" DE TRO VE MENUI CHINH!";
	_getch();
	system("cls");
}

void Searching()
{
	string temp;
	cout << "\n-----------------------------------------\n";
	cout << "CHUONG TRINH QUAN LI CHUOI KY TU";
	cout << "\n-----------------------------------------";
	cout << "\nCHUONG TRINH HIEN HANH: \"TIM KIEM\"\n";
	cout << "-----------------------------------------";
	if (empty(pbstree) == true)
	{
		cout << "\nCAY RONG! VUI LONG NHAP VAO CHUOI KI TU CHO CAY.\n=> == NHAP \"ENTER\" DE TRO VE MENU CHINH! == ";
		_getch();
		return;
	}
	cout << "\n\n\tNHAP CHUOI KI TU CAN TIM: ";
	cin.ignore();
	getline(cin, temp);
	if (search_node(pbstree, temp) == NULL) cout << "\n == KHONG TIM THAY KET QUA NAO! == \n";
	else cout << "\n == TIM THAY KET QUA == \n";
	cout << "== NHAN ENTER DE QUAY VE MENU CHINH! ==";
	_getch();
}

void Remove_BST()
{
	string temp;
	NODEPTR *q;

	cout << "\n\t-----------------------------------------\n";
	cout << "\tCHUONG TRINH QUAN LI CHUOI KY TU";
	cout << "\n\t-----------------------------------------";
	cout << "\nCHUONG TRINH HIEN HANH: \"TIEM KIEM\"";
	cout << "\n-----------------------------------------";
	if (empty(pbstree) == true)
	{
		cout << "\nCAY RONG . VUI LONG NHAP CHUOI KI TU CHO CAY.\n=> Nhap \"ENTER\" de quay ve Menu";
		_getch();
		return;
	}
	cout << "\nNHAP CHUOI KI TU CAN XOA : ";
	cin.ignore();
	getline(cin, temp);
	if (remove_node(pbstree, temp) == true) cout << "DA XOA THANH CONG";
	else cout << "LOI! KHONG XOA DUOC !";
	/*if (search_node(pbstree, temp) != NULL)
	{
	q = search_node(pbstree, temp);
	q=remove_node(q);
	cout << "\nDa xoa xong. ";
	}
	else
	{
	cout << "\nKhong xoa duoc (khong ton tai). ";
	}*/

	cout << ". Nhan Enter de quay ve Menu";
	_getch();
}

int main()
{
	int chose;
	initialize(pbstree);
	for (;;)
	{
		cout << "\t----------------------------------\n";
		cout << "\tCHUONG TRINH QUAN LI CHUOI KY TU.";
		cout << "\n\t----------------------------------";
		cout << "\n\t1) NHAP CAY NHI PHAN/ CHUOI KI TU.";
		cout << "\n\t2) XUAT CAY NHI PHAN/ CHUOI KI TU.";
		cout << "\n\t3) TIM KIEM MOT CHUOI KI TU TRONG CAY.";
		cout << "\n\t4) XOA MOT CHUOI KI TU TRONG CAY.";
		cout << "\n\t5) XOA BO TOAN BO CAY NHI PHAN.";
		cout << "\n\t0) THOAT KHOI CHUONG TRINH.";
		cout << "\n\n\tVUI LONG CHON CHUC NANG CAN THAO TAC : ";
		cin >> chose;
		if (chose == 0) break;
		if (chose >= 1 && chose <= 5)
		{
			switch (chose)
			{
			case 1: {system("cls"); Init(); system("cls"); break; }
			case 2: {system("cls"); Result(); system("cls"); break; }
			case 3: {system("cls"); Searching(); system("cls"); break; }
			case 4: {system("cls"); Remove_BST(); system("cls"); break; }
			case 5:
			{
				system("cls");
				cout << "\t----------------------------------\n";
				cout << "\tCHUONG TRINH QUAN LI CHUOI KY TU";
				cout << "\n\t-----------------------------------------";
				cout << "\nCHUONG TRINH HIEN HANH: \"XOA TOAN BO CAY NHI PHAN\"\n";
				cout << "\n-----------------------------------------";
				cout << "\nDA XOA THANH CONG TOAN BO CAY NHI PHAN. Nhan Enter de quay tro ve Menu";
				cleartree(pbstree);
				initialize(pbstree);
				_getch();
				system("cls");
				break;
			}
			default: {cout << "\nNHAP SAI CHUC NANG. VUI LONG NHAP LAI!"; break; }
			}
		}
	}
	cout << "\nCAM ON BAN DA SU DUNG CHUONG TRINH QUAN LI CHUUOI KI TU\n";
	return 0;
}