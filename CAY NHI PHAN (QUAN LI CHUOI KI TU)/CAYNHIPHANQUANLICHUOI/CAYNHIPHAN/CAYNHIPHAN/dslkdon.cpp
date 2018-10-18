#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;
struct date
{
	int ngay, thang, nam;
};
struct sinhvien
{
	string maSV;
	string hoTen;
	date ngaysinh;
	int dtb;
};

struct node
{
	sinhvien info;
	struct node *next;
};

//Khai báo bi?n con tr? ch? d?n m?t nút
typedef node *NODEPTR;
//Qu?n lý dsld don qua con tr? d?u plist
NODEPTR *plist;
//	M?t s? tác v?
//Tác v? getnode:
NODEPTR getnode()
{
	NODEPTR p;
	p = (NODEPTR)malloc(sizeof(node));
	return p;
}
//Tác v? freenode:
void freenode(NODEPTR p)
{
	free(p);
}
//Tác v? initialize: Kh?i t?o danh sách r?ng
void initialize(NODEPTR *plist)
{
	plist = NULL;
}
//Tác v? empty:
int empty(NODEPTR *plist)
{
	return (plist == NULL ? true : false);
}
//Tác v? nodepointer:
NODEPTR nodepointer(NODEPTR *plist, int i) // Dùng d? xác d?nh v? trí con tr?
{
	NODEPTR p;
	int vitri = 0;
	p = *plist;
	while (p != NULL &&vitri < i)
	{
		p = p->next;
		vitri++;
	}
	return p;
}
//Tác v? position
int position(NODEPTR *plist, NODEPTR p)
{
	if (p = NULL) return -1;
	NODEPTR q;
	q = *plist;
	int vitri = 0;
	while (q != p)
	{
		q = q->next;
		vitri++;
	}
	return vitri;
}
//Tác v? prenode
NODEPTR prenode(NODEPTR *plist, NODEPTR p)
{
	NODEPTR q;
	q = *plist;
	if (p == *plist || p == NULL)
		cout << "Khong tim duoc p\n";
	else while (q->next != p)
		q = q->next;
	return q;
}
//Tác v? listsize
int listsize(NODEPTR *plist)
{
	int i = 0;
	NODEPTR p;
	if (empty(plist))
		return 0;
	p = *plist;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}
//Tác v? push: Thêm m?t node vào d?u danh sách
void push(NODEPTR *plist, sinhvien x)
{
	NODEPTR p;
	p = getnode();
	p->info = x;
	p->next = *plist;
	*plist = p;
}
//Tác v? insafter: Thêm 1 node vào sau node p
void insafter(NODEPTR p, sinhvien x)
{
	NODEPTR q;
	if (p == NULL)
		cout << "Khong them duoc!\n";
	else
	{
		q = getnode();
		q->info = x;
		q->next = p->next;
		p->next = q;
	}
}
//Tác v? pop: xóa node d?u kh?i danh sách
sinhvien pop(NODEPTR *plist)
{
	NODEPTR p;
	p = getnode();
	sinhvien x;
	p = *plist;
	*plist = p->next;
	x = p->info;
	free(p);
	return(x);
}
//Tác vu delafter: xóa 1 node sau node p
sinhvien delafter(NODEPTR p)
{
	NODEPTR q;
	sinhvien x;
	if (p == NULL || p->next == NULL)
		cout << "Khong xoa duoc!\n";
	else
	{
		q = p->next;
		x = q->info;
		p->next = q->next;
		freenode(q);
	}
	return(x);
}
//Tác v? place: thêm m?t nút có n?i dung x vào dslk dã có th? t?
void place(NODEPTR *plist, sinhvien x)
{
	NODEPTR p, q;
	q = NULL;
	for (p = *plist; p != NULL&&p->info.dtb < x.dtb; p = p->next)
		q = p;
	if (q != NULL)
		insafter(q, x);
	else push(plist, x);
}
//Tác v? traverse: Duyet ds và in thông tin
void traverse(NODEPTR *plist)
{
	NODEPTR p;
	p = *plist;
	int i = 1;
	while (p != NULL)
	{
		cout << i << "\t";
		cout << p->info.maSV << "\t";
		cout << p->info.hoTen << "\t";
		cout << p->info.dtb << endl;
		p = p->next;
		i++;
	}
}
//Tác v? search: tìm kiem
NODEPTR search(NODEPTR *plist, string x)
{
	NODEPTR p;
	p = *plist;
	while (p != NULL || p->info.maSV != x)
		p = p->next;
	return(p);
}
//Tác vu sort: Sap xep
void selectionsort(NODEPTR *plist)
{
	NODEPTR p, q, pmin;
	sinhvien min;
	for (p = *plist; p->next != NULL; p = p->next)
	{
		pmin = p;
		min = p->info;
		for (q = p->next; q != NULL; q = q->next)
			if (q->info.dtb < min.dtb)
			{
				min = q->info;
				pmin = q;
			}
		pmin->info = p->info;
		p->info = min;
	}
}
//Tác v? clearlist: xóa toàn b? danh sách
void clearlist(NODEPTR *plist)
{
	NODEPTR p, q;
	q = NULL;
	p = *plist;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		freenode(q);
		plist = NULL;
	}
}
NODEPTR Max(NODEPTR *plist)
{
	NODEPTR p, max;
	max = *plist;
	if (*plist == NULL)
	{
		cout << "Danh sach rong!\n";
		return NULL;
	}
	else
		for (p = (*plist)->next; p != NULL; p = p->next)
			if (p->info.dtb > max->info.dtb)
				max = p;
	return max;
}
NODEPTR Min(NODEPTR *plist)
{
	NODEPTR p, min;
	min = *plist;
	if (plist == NULL)
	{
		cout << "Danh sach rong!\n";
		return NULL;
	}
	for (p = (*plist)->next; p != NULL; p = p->next)
		if (p->info.dtb < min->info.dtb)
			min = p;
	return min;
}
int main()
{
	sinhvien sv;
	NODEPTR p;
	int vitri, chucnang;
	string	id;
	char c;

	initialize(plist);

	cout << "\n\tCHUONG TRINH QUAN LY DANH SACH SINH VIEN\n";
	cout << "   1: Xem danh sach sinh vien\n";
	cout << "   2: Them sinh vien vao danh sach\n";
	cout << "   3: Xoa sinh vien trong danh sach\n";
	cout << "   4: Hieu chinh sinh vien\n";
	cout << "   5: Sap xep danh sach theo DiemTB\n";
	cout << "   6: Tim kiem sinh vien theo MSSV\n";
	cout << "   7: Them sinh vien vao danh sach da co thu tu\n";
	cout << "   8: Tim sinh vien co diem trung binh cao nhat\n";
	cout << "   9: Tim sinh vien co diem trung binh thap nhat\n";
	cout << "   10: Xoa toan bo danh sach\n";
	cout << "   0: Ket thuc chuong trinh\n";

	do
	{
		cout << "\nChuc nang ban chon: ";
		cin >> chucnang;
		if (chucnang == 1)
		{
			cout << "\nDanh sach sinh vien: ";
			cout << "\nSTT   MSSV    HO TEN   DIEM TB\n";
			traverse(plist);
		}

		if (chucnang == 2)
		{
			cout << "\nVi tri them (0, 1, 2, ...): ";
			cin >> vitri;
			cout << "\nMa so sinh vien: ";
			cin.ignore();
			getline(cin, sv.maSV);
			fflush(stdin);
			cout << "\nHo ten sinh vien: ";
			fflush(stdin);
			getline(cin, sv.hoTen);
			//cin.ignore();
			cout << "\nNhap ngay sinh: ";
			cin >> sv.ngaysinh.ngay;
			cout << "\nNhap thang sinh: ";
			cin >> sv.ngaysinh.thang;
			cout << "\nNhap nam sinh: ";
			cin >> sv.ngaysinh.nam;
			fflush(stdin);
			cout << "\nNhap diem trung binh:  ";
			cin >> sv.dtb;

			if (vitri == 0)
				push(plist, sv);
			else
			{
				p = nodepointer(plist, vitri - 1);//p chi nut truoc nut can them
				if (p == NULL)
					cout << "Vi tri khong hop le";
				else
					insafter(p, sv);
			}

		}
		if (chucnang == 3)
		{
			cout << "\nVi tri xoa (0, 1, 2, ...): ";
			cin >> vitri;
			if (vitri == 0)
				pop(plist);
			else
			{
				p = nodepointer(plist, vitri - 1);//p chi nut truoc nut can xoa
				delafter(p);
			}

		}
		if (chucnang == 4)
		{
			cout << "\nVi tri hieu chinh (0, 1, 2, ...): ";
			cin >> vitri;
			p = nodepointer(plist, vitri); // p chi nut can hieu chinh
			if (p == NULL)
				cout << "Vi tri khong phu hop";
			else
			{
				cout << "\nSTT: " << vitri << "  MSSV: " << p->info.maSV << "  HO TEN:  " << p->info.hoTen << "  DIEM TB" << p->info.dtb;
				cout << "\nMa so sv moi: ";
				fflush(stdin);
				getline(cin, sv.maSV);
				cout << "Ho ten sv moi: ";
				fflush(stdin);
				getline(cin, sv.hoTen);
				cout << "Diem TB sv moi: ";
				cin >> sv.dtb;

				p->info = sv;
			}
		}

		if (chucnang == 5)
		{
			selectionsort(plist);
		}

		if (chucnang == 6)
		{
			cout << "\nNhap ma sinh vien can tim: ";
			fflush(stdin);
			getline(cin, id);
			p = search(plist, id);
			if (p == NULL)
				cout << "Khong co sinh vien co ma so " << id;
			else
				cout << "Tim thay o vi tri: " << position(plist, p) << ", Ho ten: " << p->info.hoTen << ", DiemTB: " << p->info.dtb;
		}

		if (chucnang == 7)
		{
			cout << "\n   Thong tin sinh vien them vao: ";
			cout << "\nMa so sinh vien: ";
			fflush(stdin);
			getline(cin, sv.maSV);
			cout << "Ten sinh vien: ";
			fflush(stdin);
			getline(cin, sv.hoTen);
			cout << "Diem trung binh: ";
			cin >> sv.dtb;

			place(plist, sv);
		}

		if (chucnang == 8)
		{
			p = Max(plist);
			if (p != NULL)
			{
				cout << "\nSinh vien co diem trung binh cao nhat:\n";
				cout << "\nMa sv: " << p->info.maSV << ", Ho ten: " << p->info.hoTen << ", DiemTB: " << p->info.dtb;
			}
		}

		if (chucnang == 9)
		{
			p = Min(plist);
			if (p != NULL)
			{
				cout << "\nSinh vien co diem trung binh thap nhat:\n";
				cout << "\nMa sv: " << p->info.maSV << ", Ho ten: " << p->info.hoTen << ", DiemTB: " << p->info.hoTen;
			}
		}

		if (chucnang == 10)
		{
			cout << "\n   Ban co chac khong (c/C: co) ";
			cin >> c;
			if (c == 'c' || c == 'C')
				clearlist(plist);
		}

	} while (chucnang != 0);

	// xoa tat ca cac nut tren danh sach lien ket
	clearlist(plist);

	return 0;
}