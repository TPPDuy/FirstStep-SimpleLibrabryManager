#include<stdio.h>
#include <string.h>
int kiemtratinhhoplecuangaynhap(int ng, int th, int n)//kiem tra xem ngay nhap vao co hop le hay khong
{
	if (th < 1 || th>12)
	{
		return 0;
	}
	if ((th == 1 || th == 3 || th == 5 || th == 7 || th == 8 || th == 10 || th == 12) && (ng < 0 || ng>31))
	{
		return 0;
	}
	if ((th == 4 || th == 6 || th == 9 || th == 11) && (ng < 0 || ng>30)) printf("Khong hop le\n");
	if (th == 2)
	{
		if ((n % 4 == 0) && (ng < 0 || ng>29))
		{
			return 0;
		}
		if ((n % 4 != 0) && (ng < 0 || ng>28))
		{
			return 0;
		}
	}
	return 1;
}
//viet ham nhap vao tat ca thong tin
void hotendocgia(char hoten[])
{
	char start[10];// chuoi rong, dung de xu ly luc no bi troi ham
	gets_s(start, 10);
	printf("Nhap ho ten: ");
	gets_s(hoten, 100);
}
void nhaptensach(char tensach[])
{
	char start[10];
	gets_s(start, 10);
	printf("Nhap ten sach: ");
	gets_s(tensach, 100);
}
void nhapthongtin(char chuoi[])
{
	gets_s(chuoi, 100);
}
void nhapngaythangnam(int ngay[], int thang[], int nam[], int a)
{
	scanf("%d %d %d", &ngay[a], &thang[a], &nam[a]);
	while (kiemtratinhhoplecuangaynhap(ngay[a], thang[a], nam[a]) == 0)
	{
		printf("Du lieu nhap vao khong hop le. Hay nhap lai: ");
		scanf("%d %d %d", &ngay[a], &thang[a], &nam[a]);
	}
}
void nhapso(int mang[], int a)
{
	scanf("%d", &mang[a]);
}
//xuat thong tin ra ngoai
void xuatthongtin(char chuoi[], int a)
{
	int dem = 1;
	for (int i = 0; chuoi[i] != '\0'; i++)
	{
		if (dem == a)
		{
			for (int j = i; chuoi[j] != '^'; j++)
			{
				printf("%c", chuoi[j]);
			}
			dem++;
		}
		if (chuoi[i] == '^')
		{
			dem++;
		}
	}
	printf("\n");
}
void xuatngaythang(int ngay[], int thang[], int nam[], int a)
{
	printf("%d - %d - %d", ngay[a], thang[a], nam[a]);
	printf("\n");
}
void xuatso(int mang[], int a)
{
	printf("%d\n", mang[a]);
}
//Chinh sua thong tin
int timkiemvitri(char chuoi[], int a)// tim vi tri bat dau cua nguoi thu a trong chuoi
{
	int stt = 1;
	for (int i = 0; chuoi[i] != '\0'; i++)
	{
		if (stt == a) return i;
		if (chuoi[i] == '^') stt++;
	}
	return -1;
}
void chinhsuathongtin(char chuoigoc[],char chuoimoi[], int a, int soluong)
{
	char chuoiphu[80] = "";
	int vitri=0;
	int temp = a;
	vitri = timkiemvitri(chuoigoc, temp);
	if (a == 1 && soluong == a)
	{
		strcpy(chuoiphu, chuoimoi);
		strcat(chuoiphu, "^");
		strcpy(chuoigoc, chuoiphu);
	}
	if (a == 1 && soluong!=a)
	{
		strcpy(chuoiphu,chuoimoi);
		strcat(chuoiphu, "^");
		int j = strlen(chuoiphu);
		int start = 0;
		start = timkiemvitri(chuoigoc, 2);
		for (int i = start; chuoigoc[i] != '\0'; i++)
		{
			chuoiphu[j] = chuoigoc[i];
			j++;
		}
		strcpy(chuoigoc, chuoiphu);
	}
	if(a!=1)
	{
		if (soluong != a)
		{
			for (int i = 0; i < vitri; i++)
			{
				chuoiphu[i] = chuoigoc[i];
			}
			strcat(chuoiphu, chuoimoi);
			int l = strlen(chuoiphu);
			int demdaungancach = 0, key;
			for (int i = 0; chuoigoc[i] != '\0'; i++)
			{
				if (demdaungancach == a)
				{
					key= i;
					break;
				}
				if (chuoigoc[i] == '^') demdaungancach++;
			}
			int j = l;
			for (int i = key-1; chuoigoc[i] != '\0'; i++)
			{
				chuoiphu[j] = chuoigoc[i];
				j++;
			}
			strcpy(chuoigoc, chuoiphu);
		}
		if (soluong == a)
		{
			for (int i = 0; i < vitri; i++)
			{
				chuoiphu[i] = chuoigoc[i];
			}
			strcat(chuoiphu, chuoimoi);
			strcat(chuoiphu, "^");
			strcpy(chuoigoc, chuoiphu);
		}
	}
}
void chinhsuangaythang(int ngay[], int thang[], int nam[], int a)
{
	scanf("%d %d %d", &ngay[a], &thang[a], &nam[a]);
}
//Xoa thong tin
void xoathongtin(char chuoigoc[], int a, int soluong)
{
	char chuoiphu[80] = "";
	int vitri = 0;
	int temp = a;
	vitri = timkiemvitri(chuoigoc, temp);
	if (a == 1 && soluong == a)
	{
		chuoigoc = "";
	}
	if (a == 1 && soluong != a)
	{
		int j = 0;
		int start = 0;
		start = timkiemvitri(chuoigoc, 2);
		for (int i = start; chuoigoc[i] != '\0'; i++)
		{
			chuoiphu[j] = chuoigoc[i];
			j++;
		}
		strcpy(chuoigoc, chuoiphu);
	}
	if (a != 1)
	{
		if (soluong != a)
		{
			for (int i = 0; i < vitri; i++)
			{
				chuoiphu[i] = chuoigoc[i];
			}
			int l = strlen(chuoiphu);
			int demdaungancach = 0, key;
			for (int i = 0; chuoigoc[i] != '\0'; i++)
			{
				if (demdaungancach == a)
				{
					key = i;
					break;
				}
				if (chuoigoc[i] == '^') demdaungancach++;
			}
			int j = l;
			for (int i = key; chuoigoc[i] != '\0'; i++)
			{
				chuoiphu[j] = chuoigoc[i];
				j++;
			}
			strcpy(chuoigoc, chuoiphu);
		}
		if (soluong == a)
		{
			for (int i = 0; i < vitri; i++)
			{
				chuoiphu[i] = chuoigoc[i];
			}
			strcpy(chuoigoc, chuoiphu);
		}
	}
}
void xoangaythang(int mang[], int a, int soluong)
{
	for (int i = a; i <= soluong - 1; i++)
	{
		mang[a] = mang[a + 1];
	}
}
//tim thong tin theo cmnd
int timvitringuoidung(char chuoigoc[], char chuoitim[], int soluong)// tim xem day la nguoi dung thu may trong danh sach
{
	int a , vitri;
	for (int i = 1; i <= soluong; i++)
	{
		vitri = timkiemvitri(chuoigoc, i);
		int k = vitri;
		if (k == -1) return -1;
		char chuoiphu[100]= "";
		a = 0;
			for (int j = k; chuoigoc[j] != '^'; j++)
			{
				chuoiphu[a] = chuoigoc[j];
			a++;
			}
			if (stricmp(chuoiphu, chuoitim) == 0) return i;
	}
	return -1;
}
//tim thong tin theo ho ten
void timvitritheoten(char chuoigoc[], char chuoitim[], int soluong, int mangchuavitri[])
{
	int a, vitri;
	int m = 0;
	for (int i = 1; i <= soluong; i++)
	{
		vitri = timkiemvitri(chuoigoc, i);
		int k = vitri;
		char chuoiphu[100] = "";
		a = 0;
		for (int j = k; chuoigoc[j] != '^'; j++)
		{
			chuoiphu[a] = chuoigoc[j];
			a++;
		}
		if (stricmp(chuoiphu, chuoitim) == 0)
		{
			mangchuavitri[m] = i;
			m++;
		}
	}
}
// tim ngay sau ngay vua nhap n ngay
int songay(int thang, int nam)
{
	int sn;
	switch (thang) 
	{
	case 1: case 3: case 5:case 7:case 8:case 10:case 12:
	{
		sn = 31;
		break;
	}
	case 4: case 6:case 9: case 11:
	{
		sn = 30;
		break;
	}
	case 2:
	{
		if (nam % 4 == 0) sn = 29;
		else sn = 28;
		break;
	}
	}
	return sn;
}
void timngaysaungayvuanhap(int &ngay, int &thang, int &nam, int n)
{
	ngay = ngay + n;
	while (ngay > songay(thang, nam))
	{
		ngay = ngay - songay(thang, nam);
		thang++;
		if (thang > 12)
		{
			thang = 1;
			nam++;
		}
	}
}
// thong ke so luong doc gia theo gioi tinh
void thongkesoluongtheogioitinh(char gioitinh[], int &nam, int &nu, int soluongdocgia)
{
	for (int i = 1; i <= soluongdocgia; i++)
	{
		char mangphu[4] = "";
		int a = 0;
		int vitri=timkiemvitri(gioitinh, i);
		for (int j = vitri; gioitinh[j] != '^'; j++)
		{
			mangphu[a] = gioitinh[j];
			a++;
		}
		if (stricmp(mangphu, "nam") == 0) nam++;
		if (stricmp(mangphu, "nu") == 0) nu++;
	}
}
// thong ke so luong sach theo the loai
void thongkesoluongsachtheotheloai(char theloai[],int soluong[], int soluongsach)
{
	for (int i = 1; i <= soluongsach; i++)
	{
		int b[100] = { 0 };
		int trung = 0;
		char mangphu[100] = "";
		int a = 0, S=0;
		int vitri = timkiemvitri(theloai, i);
		for (int j = vitri; theloai[j] != '^'; j++)
		{
			mangphu[a] = theloai[j];
			a++;
		}
		int k = 1;
		for (int j = 1; j < i; j++)
		{
			char mangphu1[100] = "";
			int m = 0;
			int l = timkiemvitri(theloai, j);
			for (int n = l; theloai[n] != '^'; n++)
			{
				mangphu1[m] = theloai[n];
				m++;
			}
			if (stricmp(mangphu, mangphu1) == 0)
			{
				trung = 1;
				break;
			}
		}
		if (trung == 0)
		{
			timvitritheoten(theloai, mangphu, soluongsach, b);
			for (int j = 0; b[j] != 0; j++)
			{
				S = S + soluong[b[j]];
			}
			printf("  .");
			for (int j = 0; mangphu[j] != '\0'; j++)
			{
				printf("%c", mangphu[j]);
			}
			printf(": %d quyen\n", S);
		}
	}
}
// thong ke so sach dang muon
int checkmasachtrung(char chuoidesosanh[], char chuoicansosanh[],  int sosach, int sothutu)
{
	if (sothutu == -1) return 0;
	else
	{
		for (int j = 1; j < sothutu; j++)
		{
			char mangphu[100] = "";
			int m = 0;
			int l = timkiemvitri(chuoidesosanh, j);
			for (int n = l; chuoidesosanh[n] != '^'; n++)
			{
				mangphu[m] = chuoidesosanh[n];
				m++;
			}
			if (stricmp(mangphu, chuoicansosanh) == 0) return 1;
		}
	}
	return 0;	
}
void thongkesachdangmuon(char masachmuon[],char masach[], char tensach[], int soluongsachmuon, int soluongsach)
{
	for (int i = 1; i <= soluongsachmuon; i++)
	{
		int b[100] = { 0 };
		char mangphu[100] = "";
		int m = 0;
		int dem = 0;
		int vitri = timkiemvitri(masachmuon, i);
		for (int j = vitri; masachmuon[j] != '^'; j++)
		{
			mangphu[m] = masachmuon[j];
			m++;
		}
		if (checkmasachtrung(masachmuon, mangphu, soluongsachmuon,i) == 0)
		{
			timvitritheoten(masachmuon, mangphu, soluongsachmuon, b);
			for (int j = 0; b[j] != 0; j++)
			{
				dem++;
			}
			int thutu = timvitringuoidung(masach, mangphu, soluongsach);
			printf("Ten sach: ");
			xuatthongtin(tensach, thutu);
			printf("Ma sach: ");
			xuatthongtin(masach, thutu);
			printf("So luong: %d quyen\n", dem);
			printf("---------------------\n");
		}
		else continue;
	}
}
void xuatsachdangmuon(char sosachmuon[], int soluongsachmuon)
{
	for (int i = 1; i <= soluongsachmuon; i++)
	{
		int vitri = timkiemvitri(sosachmuon, i);
		for (int j = vitri; sosachmuon[j] != '-'; j++)
		{
			if (sosachmuon[j + 1] == '-') printf("\n");
			printf("%c", sosachmuon[j]);
		}
	}
}
