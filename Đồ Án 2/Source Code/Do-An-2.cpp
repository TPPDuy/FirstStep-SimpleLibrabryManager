#include "Ham.h"
struct docgia
{
	char hoten[80] = "";
	char madocgia[50] = "";
	char cmnd[20] = "";
	char gioitinh[30]="";
	char email[100]="";
	char diachi[100]="";
	int ngaysinh;
	int thangsinh;
	int namsinh;
	int ngaylap;
	int thanglap;
	int namlap;
	int ngayhan;
	int thanghan;
	int namhan;
};
struct sach
{
	char tensach[80] = "";
	char masach[80] = "";
	char tacgia[80] = "";
	char theloai[50] = "";
	char nhaxuatban[80] = "";
	int namxuatban;
	int giasach;
	int soluong;
};
struct sachmuon
{
	char masachmuon[50];
};
struct phieumuonsach
{
	char madocgia[80];
	sachmuon masach[50];
	int sosachmuon;
	int ngaymuon;
	int thangmuon;
	int nammuon;
	int ngaytradukien;
	int thangtradukien;
	int namtradukien;
};
struct phieutrasach
{
	phieumuonsach muon;
	int ngaytrathucte;
	int thangtrathucte;
	int namtrathucte;
};
void ghisolieu(FILE *f, int so)
{
	fprintf(f, "%d\n", so);
}
void docsolieu(FILE *f, int &so)
{
	fscanf(f, "%d", &so);
}
void docbodem(FILE *f)
{
	char start[5];
	fprintf(f, "\n");
}
void main()
{
	docgia thedocgia[100];
	sach thongtinsach[100];
	phieumuonsach phieumuon[100];
	phieutrasach phieutra[100];
	int n, sodocgia = 0, x, thutu;
	int sosach = 0; 
	int dongy = 1;
	int sophieumuonsach=0;
	int mangchuathutudocgiatrehen[100] = { -1 };
	int trehen = 0;
	char start[10];
	int themdocgia = 0;
	int themsach = 0;
	int z = 0;
	FILE *f = fopen("docgia.txt", "r");
	FILE *c = fopen("sach.txt", "r");
	FILE *a = fopen("solieu.txt", "r");
	FILE *b = fopen("phieumuonsach.txt", "r");
	docsolieu(a, sodocgia);
	docsolieu(a, sosach);
	docsolieu(a, sophieumuonsach);
	docbodem(a);
	fclose(a);
	fread(thedocgia, sizeof(thedocgia), 1, f);
	fclose(f);
	fread(thongtinsach, sizeof(thongtinsach), 1, c);
	fclose(c);
	fread(phieumuon, sizeof(phieumuon), 1, b);
	fclose(b);
	while (dongy == 1)
	{
		menucongviec();
		printf("Chon cong viec can thuc hien: ");
		scanf("%d", &x);
		if (x == 1)
		{
			themdocgia = 1;
			printf("--------------THEM DOC GIA-----------\n");
			printf("Nhap so luong doc gia can them vao: ");
			scanf("%d", &n);
			for (int i = sodocgia; i < n + sodocgia; i++)
			{
				printf("........Nhap thong tin doc gia thu %d.......\n", i + 1);
				printf("Nhap ho ten: ");
				gets_s(start);
				gets_s(thedocgia[i].hoten);
				printf("Nhap ma doc gia: ");
				gets_s(thedocgia[i].madocgia);
				printf("Nhap so chung minh nhan dan: ");
				gets_s(thedocgia[i].cmnd);
				printf("Nhap gioi tinh: ");
				gets_s(thedocgia[i].gioitinh);
				printf("Nhap ngay thang nam sinh: ");
				scanf("%d %d %d", &thedocgia[i].ngaysinh, &thedocgia[i].thangsinh, &thedocgia[i].namsinh);
				while (kiemtratinhhoplecuangaynhap(thedocgia[i].ngaysinh, thedocgia[i].thangsinh, thedocgia[i].namsinh) == 0)
				{
					printf("Ngay nhap vao khong hop le.\n");
					printf("Moi nhap lai: ");
					scanf("%d %d %d", &thedocgia[i].ngaysinh, &thedocgia[i].thangsinh, &thedocgia[i].namsinh);
				}
				printf("Nhap dia chi sinh song hien tai: ");
				gets_s(start);
				gets_s(thedocgia[i].diachi);
				printf("Nhap email: ");
				gets_s(thedocgia[i].email);
				printf("Nhap ngay lap the thu vien: ");
				scanf("%d %d %d", &thedocgia[i].ngaylap, &thedocgia[i].thanglap, &thedocgia[i].namlap);
				while (kiemtratinhhoplecuangaynhap(thedocgia[i].ngaylap, thedocgia[i].thanglap, thedocgia[i].namlap) == 0)
				{
					printf("Ngay nhap vao khong hop le.\n");
					printf("Moi nhap lai: ");
					scanf("%d %d %d", &thedocgia[i].ngaylap, &thedocgia[i].thanglap, &thedocgia[i].namlap);
				}
				thedocgia[i].ngayhan = thedocgia[i].ngaylap;
				thedocgia[i].thanghan = thedocgia[i].thanglap;
				thedocgia[i].namhan = thedocgia[i].namlap;
				timngaysaungaynhap48thang(thedocgia[i].ngayhan, thedocgia[i].thanghan, thedocgia[i].namhan);
				printf("Ngay het han cua the thu vien se la: %d %d %d\n", thedocgia[i].ngayhan, thedocgia[i].thanghan, thedocgia[i].namhan);
			}
			printf("\n");
			sodocgia += n;
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 2)
		{
			printf("----------DANH SACH CAC DOC GIA TRONG THU VIEN-------------\n");
			if (sodocgia == 0)
			{
				printf("\n       Hien chua co doc gia nao trong thu vien.\n");
				printf("\n");
			}
			else
			{
				for (int i = 0; i < sodocgia; i++)
				{
					printf("........Doc gia thu %d.......\n", i + 1);
					printf("Ho ten: ");
					puts(thedocgia[i].hoten);
					printf("Ma doc gia: ");
					puts(thedocgia[i].madocgia);
					printf("So chung minh nhan dan: ");
					puts(thedocgia[i].cmnd);
					printf("Gioi tinh: ");
					puts(thedocgia[i].gioitinh);
					printf("Ngay thang nam sinh: ");
					printf("%d/%d/%d\n", thedocgia[i].ngaysinh, thedocgia[i].thangsinh, thedocgia[i].namsinh);
					printf("Noi o hien tai: ");
					puts(thedocgia[i].diachi);
					printf("Dia chi email: ");
					puts(thedocgia[i].email);
					printf("Ngay lap the thu vien: ");
					printf("%d/%d/%d\n", thedocgia[i].ngaylap, thedocgia[i].thanglap, thedocgia[i].namlap);
					printf("Ngay het han the thu vien: %d/%d/%d\n", thedocgia[i].ngayhan, thedocgia[i].thanghan, thedocgia[i].namhan);
					printf("\n");
				}
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 3)
		{
			themdocgia = 1;
			int c;
			printf("-----------CHINH SUA THONG TIN DOC GIA-----------\n");
			if (sodocgia == 0)
			{
				printf("Hien khong co doc gia nao trong thu vien de chinh sua.\n");
				printf("\n");
			}
			else
			{
				printf("\nDay la danh sach cac doc gia trong thu vien\n");
				for (int i = 0; i < sodocgia; i++)
				{
					printf("........Doc gia thu %d.......\n", i + 1);
					printf("Ho ten: ");
					puts(thedocgia[i].hoten);
					printf("Ma doc gia: ");
					puts(thedocgia[i].madocgia);
					printf("So chung minh nhan dan: ");
					puts(thedocgia[i].cmnd);
					printf("Gioi tinh: ");
					puts(thedocgia[i].gioitinh);
					printf("Ngay thang nam sinh: ");
					printf("%d/%d/%d\n", thedocgia[i].ngaysinh, thedocgia[i].thangsinh, thedocgia[i].namsinh);
					printf("Noi o hien tai: ");
					puts(thedocgia[i].diachi);
					printf("Dia chi email: ");
					puts(thedocgia[i].email);
					printf("Ngay lap the thu vien: ");
					printf("%d/%d/%d\n", thedocgia[i].ngaylap, thedocgia[i].thanglap, thedocgia[i].namlap);
					printf("Ngay het han the thu vien: %d/%d/%d\n", thedocgia[i].ngayhan, thedocgia[i].thanghan, thedocgia[i].namhan);
					printf("\n");
				}
				printf("=> Nhap so thu tu cua doc gia ma ban muon chinh sua: ");
				scanf("%d", &thutu);
				while (thutu <= 0 || thutu > sodocgia)
				{
					printf("Khong co doc gia nay trong thu vien.\n");
					printf("Moi nhap lai: ");
					scanf("%d", &thutu);
				}
				while (dongy == 1)
				{
					printf("Ban muon chinh sua thong tin gi cua doc gia?\n");
					printf("  1. Chinh sua ho ten.\n");
					printf("  2. Chinh sua ma doc gia.\n");
					printf("  3. Chinh sua so chung minh nhan dan.\n");
					printf("  4. Chinh sua gioi tinh.\n");
					printf("  5. Chinh sua ngay thang nam sinh.\n");
					printf("  6. Chinh sua noi o hien tai.\n");
					printf("  7. Chinh sua dia chi email.\n");
					printf("  8. Chinh sua ngay lap the thu vien.\n");
					printf("\n");
					printf("=> Nhap thong tin ban muon chinh sua: ");
					scanf("%d", &c);
					if (c == 1)
					{
						printf("Nhap lai ho ten cua doc gia: ");
						gets_s(start);
						gets_s(thedocgia[thutu - 1].hoten);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 2)
					{
						printf("Nhap lai ma doc gia: ");
						gets_s(start);
						gets_s(thedocgia[thutu - 1].madocgia);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 3)
					{
						printf("Nhap lai so chung minh nhan dan: ");
						gets_s(start);
						gets_s(thedocgia[thutu - 1].cmnd);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 4)
					{
						printf("Nhap lai gioi tinh cua doc gia: ");
						gets_s(start);
						gets_s(thedocgia[thutu - 1].gioitinh);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 5)
					{
						printf("Nhap lai ngay thang nam sinh: ");
						scanf("%d %d %d", &thedocgia[thutu - 1].ngaysinh, &thedocgia[thutu - 1].thangsinh, &thedocgia[thutu - 1].namsinh);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 6)
					{
						printf("Nhap lai noi o hien tai: ");
						gets_s(start);
						gets_s(thedocgia[thutu - 1].diachi);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 7)
					{
						printf("Nhap lai dia chi email: ");
						gets_s(start);
						gets_s(thedocgia[thutu - 1].email);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 8)
					{
						printf("Nhap lai ngay lap the thu vien: ");
						scanf("%d %d %d", &thedocgia[thutu - 1].ngaylap, &thedocgia[thutu - 1].thanglap, &thedocgia[thutu - 1].namlap);
						thedocgia[thutu - 1].ngayhan = thedocgia[thutu - 1].ngaylap;
						thedocgia[thutu - 1].thanghan = thedocgia[thutu - 1].thanglap;
						thedocgia[thutu - 1].namhan = thedocgia[thutu - 1].namlap;
						timngaysaungaynhap48thang(thedocgia[thutu - 1].ngayhan, thedocgia[thutu - 1].thanghan, thedocgia[thutu - 1].namhan);
						printf("Ngay het han cua the thu vien se la: %d/%d/%d\n", thedocgia[thutu - 1].ngayhan, thedocgia[thutu - 1].thanghan, thedocgia[thutu - 1].namhan);
						printf("Chinh sua thong tin thanh cong!\n");
						printf("Ban co tiep tuc chinh sua thong tin cua doc gia nay khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
				}
				printf("\n-----Thong tin doc gia sau khi chinh sua-----\n");
				printf("Ho ten: ");
				puts(thedocgia[thutu - 1].hoten);
				printf("Ma doc gia: ");
				puts(thedocgia[thutu - 1].madocgia);
				printf("So chung minh nhan dan: ");
				puts(thedocgia[thutu - 1].cmnd);
				printf("Gioi tinh: ");
				puts(thedocgia[thutu - 1].gioitinh);
				printf("Ngay thang nam sinh: ");
				printf("%d/%d/%d\n", thedocgia[thutu - 1].ngaysinh, thedocgia[thutu - 1].thangsinh, thedocgia[thutu - 1].namsinh);
				printf("Noi o hien tai: ");
				puts(thedocgia[thutu - 1].diachi);
				printf("Dia chi email: ");
				puts(thedocgia[thutu - 1].email);
				printf("Ngay lap the thu vien: ");
				printf("%d/%d/%d\n", thedocgia[thutu - 1].ngaylap, thedocgia[thutu - 1].thanglap, thedocgia[thutu - 1].namlap);
				printf("Ngay het han the thu vien: %d/%d/%d\n", thedocgia[thutu - 1].ngayhan, thedocgia[thutu - 1].thanghan, thedocgia[thutu - 1].namhan);
				printf("\n");
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 4)
		{
			themdocgia = 1;
			printf("----------------XOA THONG TIN DOC GIA---------------------\n");
			if (sodocgia == 0)
			{
				printf("Hien chua co doc gia nao trong danh sach.\n");
				printf("\n");
			}
			else
			{
				while (dongy == 1)
				{
					printf("   .....Day la danh sach cac doc gia trong thu vien.....\n");
					for (int i = 0; i < sodocgia; i++)
					{
						printf("Ho ten: ");
						puts(thedocgia[i].hoten);
						printf("Ma doc gia: ");
						puts(thedocgia[i].madocgia);
						printf("So chung minh nhan dan: ");
						puts(thedocgia[i].cmnd);
						printf("Gioi tinh: ");
						puts(thedocgia[i].gioitinh);
						printf("Ngay thang nam sinh: ");
						printf("%d/%d/%d\n", thedocgia[i].ngaysinh, thedocgia[i].thangsinh, thedocgia[i].namsinh);
						printf("Noi o hien tai: ");
						puts(thedocgia[i].diachi);
						printf("Dia chi email: ");
						puts(thedocgia[i].email);
						printf("Ngay lap the thu vien: ");
						printf("%d/%d/%d\n", thedocgia[i].ngaylap, thedocgia[i].thanglap, thedocgia[i].namlap);
						printf("Ngay het han the thu vien: %d/%d/%d\n", thedocgia[i].ngayhan, thedocgia[i].thanghan, thedocgia[i].namhan);
						printf("\n");
					}
					printf("=> Nhap so thu tu cua doc gia ma ban muon xoa khoi danh sach: ");
					scanf("%d", &thutu);
					while (thutu<0 || thutu>sodocgia)
					{
						printf("Khong co doc gia nay trong thu vien.\n");
						printf("Moi nhap lai: ");
						scanf("%d", &thutu);
					}
					for (int j = thutu - 1; j < sodocgia - 1; j++)
					{
						thedocgia[j] = thedocgia[j + 1];
					}
					sodocgia--;
					printf("Doc gia da duoc xoa khoi danh sach!\n");
					printf("Ban co muon xoa doc gia nao nua khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 5)
		{
			printf("-----------TIM KIEM THONG TIN DOC GIA THEO CHUNG MINH NHAN DAN---------\n");
			if (sodocgia == 0)
			{
				printf("Hien chua co doc gia nao trong danh sach.\n");
				printf("\n");
			}
			else
			{
				char cmnd[30] = "";
				int k = -1;
				printf("Nhap so chung minh nhan dan cua doc gia ban can tim: ");
				gets_s(start);
				gets_s(cmnd);
				for (int i = 0; i < sodocgia; i++)
				{
					if (stricmp(thedocgia[i].cmnd, cmnd) == 0)
					{
						k = i;
						break;
					}
				}
				while (k == -1)
				{
					printf("Doc gia nay khong co trong thu vien, hay nhap lai so chung minh nhan dan: ");
					gets_s(cmnd);
					for (int i = 0; i < sodocgia; i++)
					{
						if (stricmp(thedocgia[i].cmnd, cmnd) == 0)
						{
							k = i;
							break;
						}
					}
				}
				printf(".......Thong tin doc gia ban can tim......\n");
				printf("              Doc gia thu %d\n", k + 1);
				printf("Ho ten: ");
				puts(thedocgia[k].hoten);
				printf("Ma doc gia: ");
				puts(thedocgia[k].madocgia);
				printf("So chung minh nhan dan: ");
				puts(thedocgia[k].cmnd);
				printf("Gioi tinh: ");
				puts(thedocgia[k].gioitinh);
				printf("Ngay thang nam sinh: ");
				printf("%d/%d/%d\n", thedocgia[k].ngaysinh, thedocgia[k].thangsinh, thedocgia[k].namsinh);
				printf("Noi o hien tai: ");
				puts(thedocgia[k].diachi);
				printf("Dia chi email: ");
				puts(thedocgia[k].email);
				printf("Ngay lap the thu vien: ");
				printf("%d/%d/%d\n", thedocgia[k].ngaylap, thedocgia[k].thanglap, thedocgia[k].namlap);
				printf("Ngay het han the thu vien: %d/%d/%d\n", thedocgia[k].ngayhan, thedocgia[k].thanghan, thedocgia[k].namhan);
				printf("\n");
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 6)
		{
			printf("----------------TIM KIEM DOC GIA THEO HO TEN--------------\n");
			if (sodocgia == 0)
			{
				printf("           Hien chua co doc gia nao trong danh sach.\n");
				printf("\n");
			}
			else
			{
				char hoten[100] = "";
				int mangchuathutu[100] = { -1 };
				int m = 0;
				printf("Nhap ho ten cua doc gia ban can tim: ");
				gets_s(start);
				gets_s(hoten);
				for (int i = 0; i < sodocgia; i++)
				{
					if (stricmp(thedocgia[i].hoten, hoten) == 0)
					{
						mangchuathutu[m] = i;
						m++;
					}
				}
				if (mangchuathutu[0] == -1)
				{
					printf("Doc gia nay khong nam trong danh sach.\n");
				}
				else
				{
					printf(".......Day la doc gia can tim.......\n");
					for (int j = 0; j<m; j++)
					{
						printf("     Doc gia thu %d\n", mangchuathutu[j] + 1);
						printf("Ho ten: ");
						puts(thedocgia[mangchuathutu[j]].hoten);
						printf("Ma doc gia: ");
						puts(thedocgia[mangchuathutu[j]].madocgia);
						printf("So chung minh nhan dan: ");
						puts(thedocgia[mangchuathutu[j]].cmnd);
						printf("Gioi tinh: ");
						puts(thedocgia[mangchuathutu[j]].gioitinh);
						printf("Ngay thang nam sinh: ");
						printf("%d/%d/%d\n",thedocgia[mangchuathutu[j]].ngaysinh, thedocgia[mangchuathutu[j]].thangsinh, thedocgia[mangchuathutu[j]].namsinh);
						printf("Noi o hien tai: ");
						puts(thedocgia[mangchuathutu[j]].diachi);
						printf("Dia chi email: ");
						puts(thedocgia[mangchuathutu[j]].email);
						printf("Ngay lap the thu vien: ");
						printf("%d/%d/%d\n", thedocgia[mangchuathutu[j]].ngaylap, thedocgia[mangchuathutu[j]].thanglap, thedocgia[mangchuathutu[j]].namlap);
						printf("Ngay het han the thu vien: ");
						printf("%d/%d/%d\n", thedocgia[mangchuathutu[j]].ngayhan, thedocgia[mangchuathutu[j]].thanghan, thedocgia[mangchuathutu[j]].namhan);
						printf(" ------------------------\n");
					}
					printf("\n");
				}
				printf("Ban co muon tiep tuc chuong trinh?\n");
				printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
				scanf("%d", &dongy);
				while (dongy != 0 && dongy != 1)
				{
					printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
					scanf("%d", &dongy);
				}
			}
		}
		if (x == 7)
		{
			themsach = 1;
			printf("----------------THEM SACH VAO THU VIEN----------------\n");
			printf("Nhap so sach can them: ");
			scanf("%d", &n);
			for (int i = sosach; i < n+sosach; i++)
			{
				printf("..........Nhap thong tin quyen sach thu %d...........\n", i + 1);
				printf("Nhap ten sach: ");
				gets_s(start);
				gets_s(thongtinsach[i].tensach);
				printf("Nhap ISBN (ma sach): ");
				gets_s(thongtinsach[i].masach);
				printf("Nhap ten tac gia: ");
				gets_s(thongtinsach[i].tacgia);
				printf("Nhap the loai sach: ");
				gets_s(thongtinsach[i].theloai);
				printf("Nhap nha xuat ban: ");
				gets_s(thongtinsach[i].nhaxuatban);
				printf("Nhap nam xuat ban: ");
				scanf("%d", &thongtinsach[i].namxuatban);
				printf("Nhap gia sach: ");
				scanf("%d", &thongtinsach[i].giasach);
				printf("Nhap so luong: ");
				scanf("%d", &thongtinsach[i].soluong);
				printf("\n");
			}
			sosach += n;
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 8)
		{
			printf("--------------DANH SACH CAC QUYEN SACH TRONG THU VIEN----------\n");
			if (sosach == 0)
			{
				printf("        Hien thu vien chua co quyen sach nao.\n");
				printf("\n");
			}
			else
			{
				for (int i = 0; i < sosach; i++)
				{
					printf("........Quyen sach thu %d.........\n", i+1);
					printf("Ten sach: ");
					puts(thongtinsach[i].tensach);
					printf("Ma ISBN (ma sach): ");
					puts(thongtinsach[i].masach);
					printf("Ten tac gia: ");
					puts(thongtinsach[i].tacgia);
					printf("The loai: ");
					puts(thongtinsach[i].theloai);
					printf("Nha xuat ban: ");
					puts(thongtinsach[i].nhaxuatban);
					printf("Nam xuat ban: ");
					printf("%d\n",thongtinsach[i].namxuatban);
					printf("Gia sach: ");
					printf("%d\n", thongtinsach[i].giasach);
					printf("So luong: ");
					printf("%d\n", thongtinsach[i].soluong);
					printf("\n");
				}
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 9)
		{
			int c;
			themsach = 1;
			printf("--------------CHINH SUA THONG TIN MOT QUYEN SACH----------\n");
			if (sosach == 0)
			{
				printf("         Hien trong thu vien chua co quyen sach nao de chinh sua.\n");
				printf("\n");
			}
			else
			{
				printf("            Day la danh sach cac quyen sach trong thu vien.\n");
				for (int i = 0; i < sosach; i++)
				{
					printf("........Quyen sach thu %d.........\n", i + 1);
					printf("Ten sach: ");
					puts(thongtinsach[i].tensach);
					printf("Ma ISBN (ma sach): ");
					puts(thongtinsach[i].masach);
					printf("Ten tac gia: ");
					puts(thongtinsach[i].tacgia);
					printf("The loai: ");
					puts(thongtinsach[i].theloai);
					printf("Nha xuat ban: ");
					puts(thongtinsach[i].nhaxuatban);
					printf("Nam xuat ban: ");
					printf("%d\n", thongtinsach[i].namxuatban);
					printf("Gia sach: ");
					printf("%d\n", thongtinsach[i].giasach);
					printf("So luong: ");
					printf("%d\n", thongtinsach[i].soluong);
					printf("\n");
				}
				printf("Hay nhap so thu tu cua quyen sach ma ban can chinh sua: ");
				scanf("%d", &thutu);
				while (thutu <= 0 || thutu > sosach)
				{
					printf("Quyen sach nay khong co trong thu vien. Moi nhap lai: ");
					scanf("%d", &thutu);
				}
				while (dongy == 1)
				{
					printf("Ban muon chinh sua thong tin gi?\n");
					printf("    1. Chinh sua ten sach.\n");
					printf("    2. Chinh sua ISBN (ma sach).\n");
					printf("    3. Chinh sua ten tac gia.\n");
					printf("    4. Chinh sua the loai sach.\n");
					printf("    5. Chinh sua nha xuat ban.\n");
					printf("    6. Chinh sua nam xuat ban.\n");
					printf("    7. Chinh sua gia sach.\n");
					printf("    8. Chinh sua so luong.\n");
					printf("\n");
					printf("Nhap thong tin can chinh sua: ");
					scanf("%d", &c);
					if (c == 1)
					{
						printf("-------CHINH SUA TEN SACH------\n");
						printf("Nhap lai ten quyen sach: ");
						gets_s(start);
						gets_s(thongtinsach[thutu - 1].tensach);
						printf("Ten sach da duoc chinh sua thanh cong!.\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 2)
					{
						printf("--------CHINH SUA MA SACH--------\n");
						printf("Nhap lai ma sach: ");
						gets_s(start);
						gets_s(thongtinsach[thutu - 1].masach);
						printf("Ma sach da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 3)
					{
						printf("---------CHINH SUA TEN TAC GIA---------\n");
						printf("Nhap lai ten tac gia: ");
						gets_s(start);
						gets_s(thongtinsach[thutu - 1].tacgia);
						printf("Ten tac gia da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 4)
					{
						printf("-------CHINH SUA THE LOAI SACH-------\n");
						printf("Nhap lai the loai sach: ");
						gets_s(start);
						gets_s(thongtinsach[thutu - 1].theloai);
						printf("The loai sach da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 5)
					{
						printf("--------CHINH SUA NHA XUAT BAN--------\n");
						printf("Nhap lai ten nha xuat ban: ");
						gets_s(start);
						gets_s(thongtinsach[thutu - 1].nhaxuatban);
						printf("Nha xuat ban da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 6)
					{
						printf("----------CHINH SUA NAM XUAT BAN--------\n");
						printf("Nhap lai nam xuat ban sach: ");
						scanf("%d",&thongtinsach[thutu - 1].namxuatban);
						printf("Nam xuat ban da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 7)
					{
						printf("-------CHINH SUA GIA SACH-------\n");
						printf("Nhap lai gia sach: ");
						scanf("%d", &thongtinsach[thutu - 1].giasach);
						printf("Gia sach da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
					if (c == 8)
					{
						printf("---------CHINH SUA SO LUONG--------\n");
						printf("Nhap lai so luong sach: ");
						scanf("%d", &thongtinsach[thutu - 1].soluong);
						printf("So luong sach da duoc chinh sua thanh cong!\n");
						printf("Ban co muon chinh sua quyen sach nay nua khong?\n");
						printf("Neu co hay nhap 1, khong thi nhap 0: ");
						scanf("%d", &dongy);
						while (dongy != 0 && dongy != 1)
						{
							printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
							scanf("%d", &dongy);
						}
					}
				}
			}
			printf("Thong tin quyen sach sau khi chinh sua:\n");
			printf("Ten sach: ");
			puts(thongtinsach[thutu-1].tensach);
			printf("Ma ISBN (ma sach): ");
			puts(thongtinsach[thutu-1].masach);
			printf("Ten tac gia: ");
			puts(thongtinsach[thutu-1].tacgia);
			printf("The loai: ");
			puts(thongtinsach[thutu-1].theloai);
			printf("Nha xuat ban: ");
			puts(thongtinsach[thutu-1].nhaxuatban);
			printf("Nam xuat ban: ");
			printf("%d\n", thongtinsach[thutu-1].namxuatban);
			printf("Gia sach: ");
			printf("%d\n", thongtinsach[thutu-1].giasach);
			printf("So luong: ");
			printf("%d\n", thongtinsach[thutu-1].soluong);
			printf("\n");
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 10)
		{
			themsach = 1;
			printf("--------------XOA THONG TIN MOT QUYEN SACH----------------\n");
			if (sosach == 0)
			{
				printf("        Hien khong co quyen sach nao trong thu vien.\n");
				printf("\n");
			}
			else {
				while (dongy == 1)
				{
					printf("         Day la danh sach cac quyen sach trong thu vien:\n");
					for (int i = 0; i < sosach; i++)
					{
						printf("........Quyen sach thu %d.........\n", i + 1);
						printf("Ten sach: ");
						puts(thongtinsach[i].tensach);
						printf("Ma ISBN (ma sach): ");
						puts(thongtinsach[i].masach);
						printf("Ten tac gia: ");
						puts(thongtinsach[i].tacgia);
						printf("The loai: ");
						puts(thongtinsach[i].theloai);
						printf("Nha xuat ban: ");
						puts(thongtinsach[i].nhaxuatban);
						printf("Nam xuat ban: ");
						printf("%d\n", thongtinsach[i].namxuatban);
						printf("Gia sach: ");
						printf("%d\n", thongtinsach[i].giasach);
						printf("So luong: ");
						printf("%d\n", thongtinsach[i].soluong);
						printf("\n");
					}
					printf("Nhap so thu tu cua quyen sach can xoa: ");
					scanf("%d", &thutu);
					while (thutu <= 0 || thutu > sosach)
					{
						printf("Quyen sach nay khong co trong thu vien. Moi nhap lai: ");
						scanf("%d", &thutu);
					}
					for (int i = thutu - 1; i < sosach - 1; i++)
					{
						thongtinsach[i] = thongtinsach[i + 1];
					}
					printf("Da xoa thanh cong quyen sach vua chon.\n");
					printf("Ban co muon tiep tuc xoa quyen sach nao khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 1 && dongy != 0)
					{
						printf("Du lieu nhap vao khong hop le. Nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 11)
		{
			char masach[100] = "";
			int key;
			printf("---------------TIM SACH THEO MA ISBN-----------------\n");
			if (sosach == 0)
			{
				printf("        Hien khong co quyen sach nao trong thu vien.\n");
				printf("\n");
			}
			else {
				while (dongy == 1)
				{
					printf("Nhap ma sach ma ban can tim: ");
					gets_s(start);
					gets_s(masach);
					for (int i = 0; i < sosach; i++)
					{
						if (stricmp(masach, thongtinsach[i].masach) == 0)
						{
							key = i;
							break;
						}
					}
					printf("      Day la quyen sach can tim: \n");
					printf("........Quyen sach thu %d.........\n", key + 1);
					printf("Ten sach: ");
					puts(thongtinsach[key].tensach);
					printf("Ma ISBN (ma sach): ");
					puts(thongtinsach[key].masach);
					printf("Ten tac gia: ");
					puts(thongtinsach[key].tacgia);
					printf("The loai: ");
					puts(thongtinsach[key].theloai);
					printf("Nha xuat ban: ");
					puts(thongtinsach[key].nhaxuatban);
					printf("Nam xuat ban: ");
					printf("%d\n", thongtinsach[key].namxuatban);
					printf("Gia sach: ");
					printf("%d\n", thongtinsach[key].giasach);
					printf("So luong: ");
					printf("%d\n", thongtinsach[key].soluong);
					printf("\n");
					printf("Ban co muon tim quyen sach nao nua khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Du lieu nhap vao khong hop le. Nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 12)
		{
			char tensach[100];
			char mangchuavitri[100];
			int m = 0;
			printf("----------------TIM SACH THE TEN SACH--------------\n");
			if (sosach == 0)
			{
				printf("       Hien chua co quyen sach nao trong thu vien.\n");
				printf("\n");
			}
			else
			{
				printf("Nhap ten sach ban can tim: ");
				gets_s(start);
				gets_s(tensach);
				for (int i = 0; i < sosach; i++)
				{
					if (stricmp(thongtinsach[i].tensach, tensach) == 0)
					{
						mangchuavitri[m] = i;
						m++;
					}
				}
				if (mangchuavitri[0] == 0)
				{
					printf("Quyen sach nay khong co trong thu vien.\n");
					printf("\n");
				}
				else
				{
					printf("......Day la quyen sach can tim.......\n");
					for (int j = 0; j < m; j++)
					{
						printf("   Quyen sach thu %d\n", j + 1);
						printf("Ten sach: ");
						puts(thongtinsach[mangchuavitri[j]].tensach);
						printf("Ma ISBN (ma sach): ");
						puts(thongtinsach[mangchuavitri[j]].masach);
						printf("Ten tac gia: ");
						puts(thongtinsach[mangchuavitri[j]].tacgia);
						printf("The loai: ");
						puts(thongtinsach[mangchuavitri[j]].theloai);
						printf("Nha xuat ban: ");
						puts(thongtinsach[mangchuavitri[j]].nhaxuatban);
						printf("Nam xuat ban: ");
						printf("%d\n", thongtinsach[mangchuavitri[j]].namxuatban);
						printf("Gia sach: ");
						printf("%d\n", thongtinsach[mangchuavitri[j]].giasach);
						printf("So luong: ");
						printf("%d\n", thongtinsach[mangchuavitri[j]].soluong);
						printf("\n");
					}
				}
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 13)
		{
			printf("---------------LAP PHIEU MUON SACH------------\n");
			if (sodocgia == 0)
			{
				printf("       Hien khong co doc gia nao trong danh sach.\n");
				printf("\n");
			}
			else if (sosach == 0)
			{
				printf("       Hien trong thu vien chua co quyen sach nao de cho muon.\n");
				printf("\n");
			}
			else
			{
				printf("Nhap so phieu muon sach: ");
				scanf("%d", &n);
				sophieumuonsach += n;
				for (int i = 0; i < n; i++)
				{
					printf(".......Lap phieu muon sach thu %d.......\n", i + 1);
					printf("Nhap ma doc gia muon sach: ");
					gets_s(start);
					gets_s(phieumuon[i].madocgia);
					printf("Nhap so quyen sach doc gia muon: ");
					scanf("%d", &x);
					phieumuon[i].sosachmuon = x;
					gets_s(start);
					for (int j = 0; j < x; j++)
					{
						printf(".Nhap ma ISBN cua quyen sach thu %d: ", j + 1);
						gets_s(phieumuon[i].masach[j].masachmuon, 50);
					}
					printf("Nhap ngay muon: ");
					scanf("%d %d %d", &phieumuon[i].ngaymuon, &phieumuon[i].thangmuon, &phieumuon[i].nammuon);
					printf("Nhap ngay tra du kien: ");
					scanf("%d %d %d", &phieumuon[i].ngaytradukien, &phieumuon[i].thangtradukien, &phieumuon[i].namtradukien);
					int hl = 0;
					while (hl == 0)
					{
						for (int j = 1; j <= 7; j++)
						{
							int ng = phieumuon[i].ngaymuon, th = phieumuon[i].thangmuon, nam = phieumuon[i].nammuon;
							timngaysaungayvuanhap(ng, th, nam, j);
							if (ng == phieumuon[i].ngaytradukien && th == phieumuon[i].thangtradukien && nam == phieumuon[i].namtradukien)
							{
								hl = 1;
								break;
							}
						}
						if (hl == 0)
						{
							printf("Ngay tra khong duoc qua 7 ngay ke tu ngay muon.\n");
							printf("Nhap lai ngay tra du kien: ");
							scanf("%d %d %d", &phieumuon[i].ngaytradukien, &phieumuon[i].thangtradukien, &phieumuon[i].namtradukien);
						
						}
					}
				}
				printf("Da lap xong phieu muon sach.\n");
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 14)
		{
			char mangphu[100] = "";
			int thutu = -1;
			printf("----------------LAP PHIEU TRA SACH---------------\n");
			printf("Nhap ma doc gia tra sach: ");
			gets_s(start);
			gets_s(mangphu);
			for (int i = 0; i < sophieumuonsach; i++)
			{
				if (stricmp(phieumuon[i].madocgia, mangphu) == 0)
				{
					thutu = i;
					break;
				}
			}
			if (thutu == -1) printf("Doc gia nay khong muon sach cua thu vien.\n");
			else
			{
				printf("Day la thong tin doc gia muon sach:\n");
				printf(" .Ma doc gia: %s\n", phieumuon[thutu].madocgia);
				printf(" .Ma sach dang muon: \n");
				for (int j = 0; j < phieumuon[thutu].sosachmuon; j++)
				{
					printf("   .%s\n", phieumuon[thutu].masach[j].masachmuon);
				}
				printf(" .Ngay muon: %d/%d/%d\n", phieumuon[thutu].ngaymuon, phieumuon[thutu].thangmuon, phieumuon[thutu].nammuon);
				printf(" .Ngay tra du kien: %d/%d/%d\n", phieumuon[thutu].ngaytradukien, phieumuon[thutu].thangtradukien, phieumuon[thutu].namtradukien);
				printf("Nhap ngay tra thu te: ");
				scanf("%d %d %d", &phieutra[thutu].ngaytrathucte, &phieutra[thutu].thangtrathucte, &phieutra[thutu].namtrathucte);
				int hl = 0;
				for (int j = 1; j <= 7; j++)
				{
					int ng = phieumuon[thutu].ngaymuon, th = phieumuon[thutu].thangmuon, nam = phieumuon[thutu].nammuon;
					timngaysaungayvuanhap(ng, th, nam, j);
					if (ng == phieutra[thutu].ngaytrathucte && th == phieutra[thutu].thangtrathucte && nam == phieutra[thutu].namtrathucte)
					{
						hl = 1;
						break;
					}
				}
				if (hl == 0)
				{
					printf("Doc gia nay da tra sach qua han quy dinh.\n");
					for (int i = 0; i < sodocgia; i++)
					{
						if (stricmp(phieumuon[thutu].madocgia, thedocgia[i].madocgia) == 0)
						{
							mangchuathutudocgiatrehen[trehen] = i;
							trehen++;
						}
					}
				}
				printf("Da hoan thanh phieu tra sach, doc gia da duoc xoa ten ra khoi danh sach muon sach.\n");
				for (int i = thutu; i < sophieumuonsach; i++)
				{
					phieumuon[i] = phieumuon[i + 1];
				}
				sophieumuonsach--;
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 15)
		{
			printf("----------------THONG KE SO LUONG SACH TRONG THU VIEN------------\n");
			int S=0;
			for (int i = 0; i < sosach; i++)
			{
				S = S + thongtinsach[i].soluong;
			}
			printf("Trong thu vien hien co %d quyen sach. Trong do: ", S);
			for (int i = 0; i < sodocgia; i++)
			{
				printf(" .%s: %d quyen\n", thongtinsach[i].tensach, thongtinsach[i].soluong);
			}
			printf("Ban co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 16)
		{
			printf("----------------THONG KE SACH THEO THE LOAI------------\n");
			if (sosach == 0) printf("\nHien trong thu vien chua co quyen sach nao.\n");
			else
			{
				int S = 0;
				for (int i = 0; i < sosach; i++)
				{
					S = S + thongtinsach[i].soluong;
				}
				printf("Trong thu vien hien co %d quyen sach. Trong do:\n", S);
				for (int i = 0; i < sosach; i++)
				{
					int trung = 0;
					for (int j = i - 1; j >=0; j--)
					{
						if (stricmp(thongtinsach[i].theloai, thongtinsach[j].theloai) == 0)
						{
							trung = 1;
							break;
						}
					}
					if (trung == 0)
					{
						int s = 0;
						for (int k = i; k < sosach; k++)
						{
							if (stricmp(thongtinsach[i].theloai, thongtinsach[k].theloai) == 0)
							{
								s = s + thongtinsach[k].soluong;
							}
						}
						printf(" .%s: %d quyen\n", thongtinsach[i].theloai, s);
					}
				}
			}
			printf("\nBan co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 17)
		{
			printf("------------------THONG KE SO LUONG DOC GIA--------------\n");
			printf("\n");
			printf("So doc gia hien co trong thu vien la: %d nguoi\n", sodocgia);
			printf("\nBan co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 18)
		{
			int demnam = 0, demnu = 0;
			printf("------------------THONG KE DOC GIA THEO GIOI TINH-------------\n");
			printf("\nSo doc gia hien co trong thu vien la %d nguoi. Trong do:\n", sodocgia);
			for (int i = 0; i < sodocgia; i++)
			{
				if (stricmp(thedocgia[i].gioitinh, "nam") == 0) demnam++;
				else if (stricmp(thedocgia[i].gioitinh, "nu") == 0) demnu++;
			}
			printf(" .So doc gia nam la: %d nguoi.\n", demnam);
			printf(" .So doc gia nu la: %d nguoi.\n", demnu);
			printf("\nBan co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 19)
		{
			printf("------------------THONG KE SO SACH DANG MUON-----------------\n");
			if (sophieumuonsach == 0) printf("Thu vien chua cho muon quyen sach nao.\n");
			else
			{
				int dem = 0;
				for (int i = 0; i < sophieumuonsach; i++)
				{
					dem = dem + phieumuon[i].sosachmuon;
				}
				printf("Hien thu vien dang cho muon %d quyen sach.\n", dem);
			}
			printf("\nBan co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 20)
		{
			printf("-------------------THONG KE CAC DOC GIA BI TRE HEN----------------\n");
			if (mangchuathutudocgiatrehen[0] == -1) printf("\nKhong co doc gia nao bi tre hen.\n");
			else
			{
				printf("\nCac doc gia bi tre hen: \n");
				printf("\n");
				for (int i = 0; i < trehen; i++)
				{
					printf(" .Ho ten: %s\n", thedocgia[mangchuathutudocgiatrehen[i]].hoten);
					printf(" .Ma doc gia: %s\n", thedocgia[mangchuathutudocgiatrehen[i]].madocgia);
					printf(" .Gioi tinh: %s\n", thedocgia[mangchuathutudocgiatrehen[i]].gioitinh);
					printf("           -----------------------------------\n");
				}
			}
			printf("\nBan co muon tiep tuc chuong trinh?\n");
			printf("Nhap 1 neu muon tiep tuc, 0 neu muon thoat khoi chuong trinh: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Du lieu nhap vao khong hop le. Moi nhap lai: ");
				scanf("%d", &dongy);
			}
		}
	}
	if (dongy == 0)
	{
		FILE *f = fopen("docgia.txt", "wt");
		FILE *c = fopen("sach.txt", "wt");
		FILE *a = fopen("solieu.txt", "wt");
		FILE *b = fopen("phieumuonsach.txt", "wt");
		fwrite(thedocgia, sizeof(thedocgia), 1, f);
		fwrite(thongtinsach, sizeof(thongtinsach), 1, c);
		fwrite(phieumuon, sizeof(phieumuon), 1, b);
		ghisolieu(a, sodocgia);
		ghisolieu(a, sosach);
		ghisolieu(a, sophieumuonsach);
		fclose(f);
		fclose(c);
		fclose(a);
		fclose(b);
	}
}