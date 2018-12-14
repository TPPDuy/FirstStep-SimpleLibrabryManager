#include"Ham.h"
void main()
{
	int x, a, b = 0, sodocgia;
	int d, e = 0, tongsosach;
	char hoten[1000] = "", diachiemail[1000] = "", diachinha[1000] = "", madocgia[1000] = "", cmnd[1000] = "", gt[100] = "";
	char tensach[1000] = "", tacgia[1000] = "", masach[1000] = "", nhaxuatban[1000] = "", theloai[1000] = "";
	int ngaysinh[100], thangsinh[100], namsinh[100];
	int ngaylap[100], thanglap[100], namlap[100];
	int ngayhethan[100], thanghethan[100], namhethan[100];
	int dongy = 1;
	int soquyensach[100], giasach[100], namxuatban[100];
	char mangphu[100];
	char madocgiamuonsach[1000] = "";
	char madocgiatrasach[1000] = "";
	int sophieu, sosachmuon = 0, l;
	char masachmuon[100] = "";
	int tongsosachmuon = 0;
	int ngaymuon[100], thangmuon[100], nammuon[100], ngaytradukien[100], thangtradukien[100], namtradukien[100], ngaytrathucte[100], thangtrathucte[100], namtrathucte[100];
	int sosachnguoidungmuon[100] = { 0 };
	int mangchuasothutucacdocgiatrehan[100] = { 0 };
	int s = 1, q=0;
	int sothutusachmuon[100];
	int z = 0;
	printf("                                           DO AN 1\n");
	printf("==============================CHUONG TRINH QUAN LI THU VIEN DON GIAN=========================\n");
	printf("      -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_MSSV: 1612143_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	printf("\n");
	int lanthemdocgia = 0, lanthemsach = 0;
	while (dongy == 1)
	{
		choncongviecthuchien();
		printf("_Chon cong viec muon thuc hien: ");
		scanf("%d", &x);
		while (x < 1 || x>20)
		{
			printf("Du lieu nhap vao khong hop le, moi ban nhap lai: ");
			scanf("%d", &x);
		}
		//Quan li doc gia
		if (x == 1)//Them doc gia
		{
			lanthemdocgia++;
			printf("----------THEM DOC GIA---------\n");
			if (lanthemdocgia == 1)
			{
				printf("=> Nhap so luong doc gia ma ban muon them vao: ");
				scanf("%d", &a);
				for (int i = 1; i <= a; i++)
				{
					printf("======Nhap thong tin doc gia thu %d=====\n", i);
					hotendocgia(mangphu);//nhap ho ten vao mang phu
					strcat(mangphu, "^");//ngan cach moi ho ten bang dau "-"
					strcat(hoten, mangphu);//noi mang phu vao mang ho ten
					printf("Nhap ma doc gia: ");
					nhapthongtin(mangphu);//tuong tu voi mang ho ten
					strcat(mangphu, "^");
					strcat(madocgia, mangphu);
					printf("Nhap so chung minh nhan dan: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(cmnd, mangphu);
					printf("Nhap gioi tinh: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(gt, mangphu);
					printf("Nhap email: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(diachiemail, mangphu);
					printf("Nhap dia chi sinh song hien tai: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(diachinha, mangphu);
					printf("Nhap ngay thang nam sinh: ");
					nhapngaythangnam(ngaysinh, thangsinh, namsinh, i);
					printf("Nhap ngay lap the thu vien: ");
					nhapngaythangnam(ngaylap, thanglap, namlap, i);
					printf("Nhap ngay het han cua the thu vien (toi da 48 thang ke tu ngay lap): ");
					nhapngaythangnam(ngayhethan, thanghethan, namhethan, i);
					sodocgia = a + 1;
				}
			}
			else
			{
				printf("Nhap so doc gia can them vao: ");
				scanf("%d", &b);
				for (int i = sodocgia; i < b + sodocgia; i++)
				{
					printf("========Nhap thong tin doc gia thu %d=========\n", i);
					hotendocgia(mangphu);//nhap ho ten vao mang phu
					strcat(mangphu, "^");//ngan cach moi ho ten bang dau "-"
					strcat(hoten, mangphu);//noi mang phu vao mang ho ten
					printf("Nhap ma doc gia: ");
					nhapthongtin(mangphu);//tuong tu voi mang ho ten
					strcat(mangphu, "^");
					strcat(madocgia, mangphu);
					printf("Nhap so chung minh nhan dan: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(cmnd, mangphu);
					printf("Nhap gioi tinh: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(gt, mangphu);
					printf("Nhap email: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(diachiemail, mangphu);
					printf("Nhap dia chi sinh song hien tai: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(diachinha, mangphu);
					printf("Nhap ngay thang nam sinh: ");
					nhapngaythangnam(ngaysinh, thangsinh, namsinh, i);
					printf("Nhap ngay lap the thu vien: ");
					nhapngaythangnam(ngaylap, thanglap, namlap, i);
					printf("Nhap ngay het han cua the thu vien (toi da 48 thang ke tu ngay lap): ");
					nhapngaythangnam(ngayhethan, thanghethan, namhethan, i);
				}
				sodocgia = sodocgia + b;
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 2)//xuat danh sach cac doc gia
		{
			printf("\n");
			printf("---------------DANH SACH CAC DOC GIA TRONG THU VIEN----------\n ");
			for (int m = 1; m < sodocgia; m++)
			{
				printf("\n**** DOC GIA THU %d ****\n", m);
				printf("Ho ten: ");
				xuatthongtin(hoten, m);
				printf("Ma doc gia: ");
				xuatthongtin(madocgia, m);
				printf("So chung minh nhan dan: ");
				xuatthongtin(cmnd, m);
				printf("Gioi tinh: ");
				xuatthongtin(gt, m);
				printf("Dia chi email: ");
				xuatthongtin(diachiemail, m);
				printf("Noi sinh song hien tai: ");
				xuatthongtin(diachinha, m);
				printf("Ngay thang nam sinh: ");
				xuatngaythang(ngaysinh, thangsinh, namsinh, m);
				printf("Ngay lap the thu vien: ");
				xuatngaythang(ngaylap, thanglap, namlap, m);
				printf("Ngay het han the thu vien: ");
				xuatngaythang(ngayhethan, thanghethan, namhethan, m);
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 3)//Chinh sua thong tin cua mot doc gia
		{
			printf("---------CHINH SUA THONG TIN DOC GIA--------\n");
			char hotenchinhsua[100];
			int c, thutu;
			printf("****DAY LA DANH SACH CAC DOC GIA TRONG THU VIEN*****\n");
			for (int i = 1; i < sodocgia; i++)
			{
				printf("  ****DOC GIA THU %d: \n", i);
				printf("Ho ten: ");
				xuatthongtin(hoten, i);
				printf("Ma doc gia: ");
				xuatthongtin(madocgia, i);
				printf("So chung minh nhan dan: ");
				xuatthongtin(cmnd, i);
				printf("Gioi tinh: ");
				xuatthongtin(gt, i);
				printf("Dia chi email: ");
				xuatthongtin(diachiemail, i);
				printf("Noi sinh song hien tai: ");
				xuatthongtin(diachinha, i);
				printf("Ngay thang nam sinh: ");
				xuatngaythang(ngaysinh, thangsinh, namsinh, i);
				printf("Ngay lap the thu vien: ");
				xuatngaythang(ngaylap, thanglap, namlap, i);
				printf("Ngay het han the thu vien: ");
				xuatngaythang(ngayhethan, thanghethan, namhethan, i);
			}
			printf("--> Nhap so thu tu cua doc gia ma ban can chinh sua thong tin: ");
			scanf("%d", &thutu);
			while (thutu<0 || thutu>sodocgia - 1)
			{
				printf("Nguoi nay khong nam trong danh sach cac doc gia da co\n");
				printf("Ban hay nhap lai so thu tu cua doc gia can chinh sua: ");
				scanf("%d", &thutu);
			}
			while (dongy != 0)
			{
				printf("----BAN MUON CHINH SUA THONG TIN GI?----\n");
				printf("    1. Chinh sua ho ten\n");
				printf("    2. Chinh sua ma doc gia\n");
				printf("    3. Chinh sua so chung minh nhan dan\n");
				printf("    4. Chinh sua gioi tinh\n");
				printf("    5. Chinh sua dia chi email\n");
				printf("    6. Chinh sua dia chi sinh song\n");
				printf("    7. Chinh sua ngay thang nam sinh\n");
				printf("    8. Chinh sua ngay lap the thu vien\n");
				printf("    9. Chinh sua ngay het han cua the thu vien\n");
				printf("==> Hay nhap thong tin ma ban muon chinh sua: ");
				scanf("%d", &c);
				while (c <= 0 || c > 9)
				{
					printf("Khong hop le. Ban hay nhap lai cong viec can thuc hien: ");
					scanf("%d", &c);
				}
				if (c == 1)
				{
					char hotenmoi[100] = "";
					char troi[10];
					printf("Nhap lai ho ten moi: ");
					gets_s(troi);//tranh bi troi ham gets_s(hotenmoi);
					gets_s(hotenmoi);
					chinhsuathongtin(hoten, hotenmoi, thutu, sodocgia - 1);
					printf("Ho ten da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 2)
				{
					char madocgiamoi[100] = "";
					char troi[10];
					printf("Nhap lai ma doc gia: ");
					gets_s(troi);
					gets_s(madocgiamoi);
					chinhsuathongtin(madocgia, madocgiamoi, thutu, sodocgia - 1);
					printf("Ma doc gia da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tu CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 3)
				{
					char cmndmoi[100] = "";
					char troi[10];
					printf("Nhap lai so chung minh nhan dan: ");
					gets_s(troi);
					gets_s(cmndmoi);
					chinhsuathongtin(cmnd, cmndmoi, thutu, sodocgia - 1);
					printf("So chung minh nhan dan da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 4)
				{
					char gtmoi[100] = "";
					char troi[10];
					printf("Nhap lai gioi tinh: ");
					gets_s(troi);
					gets_s(gtmoi);
					chinhsuathongtin(gt, gtmoi, thutu, sodocgia - 1);
					printf("Gioi tinh da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 5)
				{
					char emailmoi[100] = "";
					char troi[10];
					printf("Nhap lai dia chi email: ");
					gets_s(troi);
					gets_s(emailmoi);
					chinhsuathongtin(diachiemail, emailmoi, thutu, sodocgia - 1);
					printf("Email da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 6)
				{
					char diachimoi[100] = "";
					char troi[10];
					printf("Nhap lai dia chi sinh song hien tai: ");
					gets_s(troi);
					gets_s(diachimoi);
					chinhsuathongtin(diachinha, diachimoi, thutu, sodocgia - 1);
					printf("Dia chi da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 7)
				{
					printf("Ban hay nhap lai ngay thang nam sinh: ");
					chinhsuangaythang(ngaysinh, thangsinh, namsinh, thutu);
					printf("Ngay thang nam sinh da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 8)
				{
					printf("Ban hay nhap lai ngay lap the thu vien: ");
					chinhsuangaythang(ngaylap, thanglap, namlap, thutu);
					printf("Ngay lap the thu vien da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (c == 9)
				{
					printf("Ban hay nhap lai ngay het han cua the thu vien (han su dung toi da 48 thang ke tu ngay lap the): ");
					chinhsuangaythang(ngayhethan, thanghethan, namhethan, thutu);
					printf("Ngay het han cua the thu vien da duoc chinh sua thanh cong!\n");
					printf(">>>> Ban co muon tiep tuc CHINH SUA doc gia nay khong?\n Neu co nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 4)
		{
			printf("---------XOA THONG TIN MOT DOC GIA------------\n");
			printf("\n");
			while (dongy == 1)
			{
				printf("****DAY LA DANH SACH CAC DOC GIA TRONG THU VIEN*****\n");
				for (int i = 1; i < sodocgia; i++)
				{
					printf("  ****DOC GIA THU %d: \n", i);
					printf("Ho ten: ");
					xuatthongtin(hoten, i);
					printf("Ma doc gia: ");
					xuatthongtin(madocgia, i);
					printf("So chung minh nhan dan: ");
					xuatthongtin(cmnd, i);
					printf("Gioi tinh: ");
					xuatthongtin(gt, i);
					printf("Dia chi email: ");
					xuatthongtin(diachiemail, i);
					printf("Noi sinh song hien tai: ");
					xuatthongtin(diachinha, i);
					printf("Ngay thang nam sinh: ");
					xuatngaythang(ngaysinh, thangsinh, namsinh, i);
					printf("Ngay lap the thu vien: ");
					xuatngaythang(ngaylap, thanglap, namlap, i);
					printf("Ngay het han the thu vien: ");
					xuatngaythang(ngayhethan, thanghethan, namhethan, i);
				}
				int thutu;
				printf("==> Hay nhap so thu tu cua doc gia ma ban can xoa: ");
				scanf("%d", &thutu);
				while (thutu<0 || thutu>sodocgia - 1)
				{
					printf("Doc gia nay khong co trong danh sach. Moi ban nhap lai: ");
					scanf("%d", &thutu);
				}
				xoathongtin(hoten, thutu, sodocgia - 1);
				xoathongtin(madocgia, thutu, sodocgia - 1);
				xoathongtin(cmnd, thutu, sodocgia - 1);
				xoathongtin(gt, thutu, sodocgia - 1);
				xoathongtin(diachiemail, thutu, sodocgia - 1);
				xoathongtin(diachinha, thutu, sodocgia - 1);
				xoangaythang(ngaysinh, thutu, sodocgia - 1);
				xoangaythang(thangsinh, thutu, sodocgia - 1);
				xoangaythang(namsinh, thutu, sodocgia - 1);
				xoangaythang(ngaylap, thutu, sodocgia - 1);
				xoangaythang(thanglap, thutu, sodocgia - 1);
				xoangaythang(namlap, thutu, sodocgia - 1);
				xoangaythang(ngayhethan, thutu, sodocgia - 1);
				xoangaythang(thanghethan, thutu, sodocgia - 1);
				xoangaythang(namhethan, thutu, sodocgia - 1);
				sodocgia--;
				printf("Ban da xoa thanh cong doc gia thu %d!\n", thutu);
				printf(">>>>> Ban co muon tiep tuc xoa nua khong?<<<<<<\n");
				printf(" Neu co hay nhap 1, khong thi nhap 0: ");
				scanf("%d", &dongy);
				while (dongy != 0 && dongy != 1)
				{
					printf("Khong hop le. Hay nhap lai: ");
					scanf("%d", &dongy);
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 5)
		{
			char timcmnd[100] = "";
			char troi[10];//em bi troi ham nen lam cai chuoi trong de no troi cai chuoi trong ma khong troi chuoi chinh
			printf("--------TIM KIEM DOC GIA THEO SO CHUNG MINH NHAN DAN---------\n");
			while (dongy == 1)
			{
				printf("...Hay nhap so chung minh nhan dan cua doc gia ma ban can tim: ");
				gets_s(troi);
				gets_s(timcmnd);
				int b = timvitringuoidung(cmnd, timcmnd, sodocgia - 1);
				if (b != -1)
				{
					printf("...DAY LA DOC GIA BAN DANG TIM:\n ");
					printf(" \n ****DOC GIA THU %d: \n", b);
					printf("Ho ten: ");
					xuatthongtin(hoten, b);
					printf("Ma doc gia: ");
					xuatthongtin(madocgia, b);
					printf("So chung minh nhan dan: ");
					xuatthongtin(cmnd, b);
					printf("Gioi tinh: ");
					xuatthongtin(gt, b);
					printf("Dia chi email: ");
					xuatthongtin(diachiemail, b);
					printf("Noi sinh song hien tai: ");
					xuatthongtin(diachinha, b);
					printf("Ngay thang nam sinh: ");
					xuatngaythang(ngaysinh, thangsinh, namsinh, b);
					printf("Ngay lap the thu vien: ");
					xuatngaythang(ngaylap, thanglap, namlap, b);
					printf("Ngay het han the thu vien: ");
					xuatngaythang(ngayhethan, thanghethan, namhethan, b);
					printf(">>>>>> Ban co muon TIM KIEM DOC GIA nao nua khong?\n");
					printf(" Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (b == -1)
				{
					printf("Doc gia nay khong co trong danh sach.\n");
					printf(">>>> Ban co muon tiep tuc TIM KIEM DOC GIA khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 6)
		{
			char troi[10];
			char timten[100];
			int mangchuasonguoidungcungten[100] = { 0 };
			printf("-------------TIM KIEM DOC GIA THEO HO TEN-------------\n");
			while (dongy == 1)
			{
				printf("Hay nhap ho ten cua doc gia ma ban can tim: ");
				gets_s(troi);
				gets_s(timten);
				timvitritheoten(hoten, timten, sodocgia - 1, mangchuasonguoidungcungten);
				if (mangchuasonguoidungcungten[0] != 0)
				{
					for (int i = 0; mangchuasonguoidungcungten[i] != 0; i++)
					{
						printf("...DAY LA DOC GIA BAN DANG TIM:\n ");
						printf("  ****DOC GIA THU %d: \n", mangchuasonguoidungcungten[i]);
						printf("Ho ten: ");
						xuatthongtin(hoten, mangchuasonguoidungcungten[i]);
						printf("Ma doc gia: ");
						xuatthongtin(madocgia, mangchuasonguoidungcungten[i]);
						printf("So chung minh nhan dan: ");
						xuatthongtin(cmnd, mangchuasonguoidungcungten[i]);
						printf("Gioi tinh: ");
						xuatthongtin(gt, mangchuasonguoidungcungten[i]);
						printf("Dia chi email: ");
						xuatthongtin(diachiemail, mangchuasonguoidungcungten[i]);
						printf("Noi sinh song hien tai: ");
						xuatthongtin(diachinha, mangchuasonguoidungcungten[i]);
						printf("Ngay thang nam sinh: ");
						xuatngaythang(ngaysinh, thangsinh, namsinh, mangchuasonguoidungcungten[i]);
						printf("Ngay lap the thu vien: ");
						xuatngaythang(ngaylap, thanglap, namlap, mangchuasonguoidungcungten[i]);
						printf("Ngay het han the thu vien: ");
						xuatngaythang(ngayhethan, thanghethan, namhethan, mangchuasonguoidungcungten[i]);
					}
					printf(">>>>>> Ban co muon TIM KIEM DOC GIA nao nua khong?\n");
					printf(" Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				else
				{
					printf("Doc gia nay khong co trong danh sach.\n");
					printf(">>>> Ban co muon tiep tuc TIM KIEM DOC GIA khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 7)
		{
			lanthemsach++;
			printf("--------THEM SACH VAO THU VIEN---------\n");
			if (lanthemsach == 1)
			{
				printf("=> Nhap so luong sach ma ban muon them vao: ");
				scanf("%d", &d);
				for (int i = 1; i <= d; i++)
				{
					printf("======Nhap thong quyen sach thu %d=====\n", i);
					nhaptensach(mangphu);
					strcat(mangphu, "^");
					strcat(tensach, mangphu);
					printf("Nhap ma sach: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(masach, mangphu);
					printf("Nhap ten tac gia: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(tacgia, mangphu);
					printf("Nhap nha xuat ban: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(nhaxuatban, mangphu);
					printf("Nhap the loai sach: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(theloai, mangphu);
					printf("Nhap nam xuat ban: ");
					nhapso(namxuatban, i);
					printf("Nhap gia tien (VND): ");
					nhapso(giasach, i);
					printf("Nhap so luong: ");
					nhapso(soquyensach, i);
					tongsosach = d + 1;
				}
			}
			else
			{
				printf("Nhap so quyen sach can them vao: ");
				scanf("%d", &e);
				for (int i = tongsosach; i < e + tongsosach; i++)
				{
					printf("======Nhap thong quyen sach thu %d=====\n", i);
					nhaptensach(mangphu);
					strcat(mangphu, "^");
					strcat(tensach, mangphu);
					printf("Nhap ma sach: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(masach, mangphu);
					printf("Nhap ten tac gia: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(tacgia, mangphu);
					printf("Nhap nha xuat ban: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(nhaxuatban, mangphu);
					printf("Nhap the loai sach: ");
					nhapthongtin(mangphu);
					strcat(mangphu, "^");
					strcat(theloai, mangphu);
					printf("Nhap nam xuat ban: ");
					nhapso(namxuatban, i);
					printf("Nhap gia tien (VND): ");
					nhapso(giasach, i);
					printf("Nhap so luong: ");
					nhapso(soquyensach, i);
				}
				tongsosach = e + tongsosach;
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 8)
		{
			printf("\n");
			printf("---------DANH SACH CAC SACH TRONG THU VIEN-----------\n");
			for (int m = 1; m < tongsosach; m++)
			{
				printf("\n******* SACH THU %d ********\n", m);
				printf("Ten sach: ");
				xuatthongtin(tensach, m);
				printf("Ma ISBN: ");
				xuatthongtin(masach, m);
				printf("Tac gia: ");
				xuatthongtin(tacgia, m);
				printf("Nha xuat ban: ");
				xuatthongtin(nhaxuatban, m);
				printf("The loai: ");
				xuatthongtin(theloai, m);
				printf("Nam xuat ban: ");
				xuatso(namxuatban, m);
				printf("Gia tien (VND): ");
				xuatso(giasach, m);
				printf("So luong: ");
				xuatso(soquyensach, m);
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 9)
		{
			char thongtinmoi[100];
			int thutusach;
			int congviec;
			printf("-----------------CHINH SUA THONG TIN SACH-----------------\n");
			printf("\n=========DAY LA DANH SACH CAC SACH TRONG THU VIEN========\n");
			for (int m = 1; m < tongsosach; m++)
			{
				printf("\n******* SACH THU %d ********\n", m);
				printf("Ten sach: ");
				xuatthongtin(tensach, m);
				printf("Ma ISBN: ");
				xuatthongtin(masach, m);
				printf("Tac gia: ");
				xuatthongtin(tacgia, m);
				printf("Nha xuat ban: ");
				xuatthongtin(nhaxuatban, m);
				printf("The loai: ");
				xuatthongtin(theloai, m);
				printf("Nam xuat ban: ");
				xuatso(namxuatban, m);
				printf("Gia tien (VND): ");
				xuatso(giasach, m);
				printf("So luong: ");
				xuatso(soquyensach, m);
			}
			printf("=> Nhap so thu tu cua quyen sach ma ban muon chinh sua: ");
			scanf("%d", &thutusach);
			while (thutusach<0 || thutusach>tongsosach - 1)
			{
				printf("Nguoi nay khong nam trong danh sach cac doc gia da co\n");
				printf("Ban hay nhap lai so thu tu cua doc gia can chinh sua: ");
				scanf("%d", &thutusach);
			}
			while (dongy != 0)
			{
				printf("----BAN MUON CHINH SUA THONG TIN GI?----\n");
				printf("    1. Chinh sua ten sach\n");
				printf("    2. Chinh sua ma sach (ISBN)\n");
				printf("    3. Chinh sua ten tac gia\n");
				printf("    4. Chinh sua nha xuat ban\n");
				printf("    5. Chinh sua the loai sach\n");
				printf("    6. Chinh sua nam xuat ban\n");
				printf("    7. Chinh sua gia sach\n");
				printf("    8. Chinh sua so luong\n");
				printf("==> Hay nhap thong tin ma ban muon chinh sua: ");
				scanf("%d", &congviec);
				while (congviec <= 0 || congviec > 8)
				{
					printf("Khong hop le. Ban hay nhap lai cong viec can thuc hien: ");
					scanf("%d", &congviec);
				}
				if (congviec == 1)
				{
					char troi[10];
					printf("Ban hay nhap lai ten quyen sach: ");
					gets_s(troi);
					gets_s(thongtinmoi);
					chinhsuathongtin(tensach, thongtinmoi, thutusach, tongsosach);
					printf("Ten sach da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0:  ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 2)
				{
					char troi[10];
					printf("Ban hay nhap lai ma sach (ISBN): ");
					gets_s(troi);
					gets_s(thongtinmoi);
					chinhsuathongtin(masach, thongtinmoi, thutusach, tongsosach);
					printf("Ma sach da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 3)
				{
					char troi[10];
					printf("Ban hay nhap lai ten tac gia: ");
					gets_s(troi);
					gets_s(thongtinmoi);
					chinhsuathongtin(tacgia, thongtinmoi, thutusach, tongsosach);
					printf("Ten tac gia da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 4)
				{
					char troi[10];
					printf("Nhap lai nha xuat ban: ");
					gets_s(troi);
					gets_s(thongtinmoi);
					chinhsuathongtin(nhaxuatban, thongtinmoi, thutusach, tongsosach);
					printf("Ten nha xuat ban da duoc chinh sua thanh cong!");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 5)
				{
					char troi[10];
					printf("Ban hay nhap lai the loai sach: ");
					gets_s(troi);
					gets_s(thongtinmoi);
					chinhsuathongtin(theloai, thongtinmoi, thutusach, tongsosach);
					printf("The loai sach da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 6)
				{
					printf("Ban hay nhap lai nam xuat ban: ");
					scanf("%d", &namxuatban[thutusach]);
					printf("Nam xuat ban da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 7)
				{
					printf("Ban hay nhap lai gia sach: ");
					scanf("%d", &giasach[thutusach]);
					printf("Gia sach da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				if (congviec == 8)
				{
					printf("Ban hay nhap lai so sach: ");
					scanf("%d", &soquyensach[thutusach]);
					printf("So sach da duoc chinh sua thanh cong!\n");
					printf("=== Ban co muon tiep tuc CHINH SUA quyen sach nay khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 10)
		{
			int thutusach;
			printf("-----------XOA THONG TIN MOT QUYEN SACH-------------\n");
			while (dongy == 1)
			{
				printf("\n=========DAY LA DANH SACH CAC SAC TRONG THU VIEN========\n");
				for (int m = 1; m < tongsosach; m++)
				{
					printf("\n******* SACH THU %d ********\n", m);
					printf("Ten sach: ");
					xuatthongtin(tensach, m);
					printf("Ma ISBN: ");
					xuatthongtin(masach, m);
					printf("Tac gia: ");
					xuatthongtin(tacgia, m);
					printf("Nha xuat ban: ");
					xuatthongtin(nhaxuatban, m);
					printf("The loai: ");
					xuatthongtin(theloai, m);
					printf("Nam xuat ban: ");
					xuatso(namxuatban, m);
					printf("Gia tien (VND): ");
					xuatso(giasach, m);
					printf("So luong: ");
					xuatso(soquyensach, m);
				}
				printf("Nhap so thu tu cua quyen sach ban can xoa: ");
				scanf("%d", &thutusach);
				while (thutusach<0 || thutusach>tongsosach - 1)
				{
					printf("Quyen sach nay khong co trong thu vien. Ban hay nhap lai: ");
					scanf("%d", &thutusach);
				}
				xoathongtin(tensach, thutusach, tongsosach - 1);
				xoathongtin(masach, thutusach, tongsosach - 1);
				xoathongtin(tacgia, thutusach, tongsosach - 1);
				xoathongtin(nhaxuatban, thutusach, tongsosach - 1);
				xoathongtin(theloai, thutusach, tongsosach - 1);
				xoangaythang(namxuatban, thutusach, tongsosach - 1);
				xoangaythang(giasach, thutusach, tongsosach - 1);
				xoangaythang(soquyensach, thutusach, tongsosach - 1);
				tongsosach--;
				printf("Ban da xoa thanh cong toan bo thong tin cua quyen sach thu %d\n", thutusach);
				printf("Ban co muon XOA thong tin cua quyen sach khac khong?\n Neu co hay nhap 1, khong thi nhap 0: ");
				scanf("%d", &dongy);
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 11)
		{
			char troi[10];
			char timma[100];
			printf("-------------------TIM SACH THEO MA ISBN-----------------------\n");
			while (dongy == 1)
			{
				printf("Hay nhap ma IBSN cua quyen sach ma ban can tim: ");
				gets_s(troi);
				gets_s(timma);
				int b = timvitringuoidung(masach, timma, tongsosach - 1);
				if (b != -1)
				{
					printf("         --------DAY LA QUYEN SACH BAN MUON TIM-----\n");
					printf("                   **** Quyen sach thu %d *****\n", b);
					printf("Ten sach: ");
					xuatthongtin(tensach, b);
					printf("Ma ISBN: ");
					xuatthongtin(masach, b);
					printf("Tac gia: ");
					xuatthongtin(tacgia, b);
					printf("Nha xuat ban: ");
					xuatthongtin(nhaxuatban, b);
					printf("The loai: ");
					xuatthongtin(theloai, b);
					printf("Nam xuat ban: ");
					xuatso(namxuatban, b);
					printf("Gia tien (VND): ");
					xuatso(giasach, b);
					printf("So luong: ");
					xuatso(soquyensach, b);
					printf(">>>> Ban co muon tiep tuc TIM KIEM SACH khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
				else
				{
					printf("Quyen sach nay khong co trong thu vien.\n");
					printf(">>>> Ban co muon tiep tuc TIM KIEM SACH khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 12)
		{
			int mangchuathutucacsachcungten[100] = { 0 };
			char tensachcantim[100];
			char troi[10];
			printf("------------------TIM SACH THEO TEN SACH----------------\n");
			while (dongy == 1)
			{
				printf("Nhap ten sach ma ban can tim: ");
				gets_s(troi);
				gets_s(tensachcantim);
				timvitritheoten(tensach, tensachcantim, tongsosach - 1, mangchuathutucacsachcungten);
				if (mangchuathutucacsachcungten[0] != 0)
				{
					printf("============ DAY LA QUYEN SACH BAN CAN TIM ============\n");
					for (int i = 0; mangchuathutucacsachcungten[i] != 0; i++)
					{
						printf("       ******* QUYEN SACH THU %d *********\n", mangchuathutucacsachcungten[i]);
						printf("Ten sach: ");
						xuatthongtin(tensach, mangchuathutucacsachcungten[i]);
						printf("Ma ISBN: ");
						xuatthongtin(masach, mangchuathutucacsachcungten[i]);
						printf("Tac gia: ");
						xuatthongtin(tacgia, mangchuathutucacsachcungten[i]);
						printf("Nha xuat ban: ");
						xuatthongtin(nhaxuatban, mangchuathutucacsachcungten[i]);
						printf("The loai: ");
						xuatthongtin(theloai, mangchuathutucacsachcungten[i]);
						printf("Nam xuat ban: ");
						xuatso(namxuatban, mangchuathutucacsachcungten[i]);
						printf("Gia tien (VND): ");
						xuatso(giasach, mangchuathutucacsachcungten[i]);
						printf("So luong: ");
						xuatso(soquyensach, mangchuathutucacsachcungten[i]);
					}
					printf(">>>> Ban co muon tiep tuc TIM KIEM SACH khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
				}
				else
				{
					printf("Quyen sach ban can tim khong co trong thu vien.\n");
					printf(">>>> Ban co muon tiep tuc TIM KIEM SACH khong?\n");
					printf("Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 13)
		{
			char troi[10];
			printf("---------------------LAP PHIEU MUON SACH--------------\n");
			printf("\n");
			printf("Nhap so phieu muon sach: ");
			scanf("%d", &sophieu);
			while (sophieu > sodocgia)
			{
				printf("So phieu da vuot qua so luong doc gia. Ban hay nhap lai so phieu: ");
				scanf("%d", &sophieu);
			}
			gets_s(troi);
			for (int i = 1; i <= sophieu; i++)
			{
				char phu[100] = "";
				printf("----Phieu muon sach thu %d-----", i);
				printf("\n");
				printf("Nhap ma doc gia: ");
				gets_s(phu);
				while (timvitringuoidung(madocgia, phu, sodocgia - 1) == -1)
				{
					printf("Nguoi nay khong co trong danh sach cac doc gia.\n ");
					printf("Ban co muon nhap lai ma doc gia khong? Neu co hay nhap 1, khong thi nhap 0: ");
					scanf("%d", &dongy);
					while (dongy != 0 && dongy != 1)
					{
						printf("Khong hop le. Hay nhap lai: ");
						scanf("%d", &dongy);
					}
					while (dongy == 1)
					{
						printf("Nhap lai ma doc gia: ");
						gets_s(troi);
						gets_s(phu);
						dongy = 0;
					}
				}
				strcat(phu, "^");
				strcat(madocgiamuonsach, phu);
				dongy = 1;
				while(dongy==1)
				{
					printf("Nhap ngay muon sach: ");
					scanf("%d %d %d", &ngaymuon[i], &thangmuon[i], &nammuon[i]);
					while (kiemtratinhhoplecuangaynhap(ngaymuon[i], thangmuon[i], nammuon[i]) == 0)
					{
						printf("Ngay nhap vao khong hop le. Ban hay nhap lai: ");
						scanf("%d %d %d", &ngaymuon[i], &thangmuon[i], &nammuon[i]);
					}
					printf("Nhap ngay tra du kien: ");
					scanf("%d %d %d", &ngaytradukien[i], &thangtradukien[i], &namtradukien[i]);
					while (kiemtratinhhoplecuangaynhap(ngaytradukien[i], thangtradukien[i], namtradukien[i]) == 0)
					{
						printf("Ngay nhap vao khong hop le. Ban hay nhap lai: ");
						scanf("%d %d %d", &ngaymuon[i], &thangmuon[i], &nammuon[i]);
					}
					int ng, th, n;
					int khongthoa = 1;
					while (khongthoa == 1)
					{
						for (int j = 1; j <= 7; j++)
						{
							ng = ngaymuon[i];
							th = thangmuon[i];
							n = nammuon[i];
							timngaysaungayvuanhap(ng, th, n, j);
							if (ng == ngaytradukien[i] && th == thangtradukien[i] && n == namtradukien[i])
							{
								khongthoa = 0;
								break;
							}
						}
						if (khongthoa == 1)
						{
							printf("Ngay tra du kien khong duoc qua 7 ngay ke tu ngay muon sach.\n");
							printf("Ban hay nhap lai ngay tra du kien: ");
							scanf("%d %d %d", &ngaytradukien[i], &thangtradukien[i], &namtradukien[i]);
							while (kiemtratinhhoplecuangaynhap(ngaytradukien[i], thangtradukien[i], namtradukien[i]) == 0)
							{
								printf("Ngay nhap vao khong hop le. Ban hay nhap lai: ");
								scanf("%d %d %d", &ngaymuon[i], &thangmuon[i], &nammuon[i]);
							}
						}
					}
					printf("Nhap so sach ma doc gia muon: ");
					scanf("%d", &sosachmuon);
					sosachnguoidungmuon[s] = sosachmuon;
					s++;
					gets_s(troi);
					for (int j = 1; j <= sosachmuon; j++)
					{
						printf("Nhap ma ISBN cua quyen sach thu %d: ", j);
						gets_s(mangphu);
						while (timvitringuoidung(masach, mangphu, tongsosach - 1) == -1)
						{
							printf("Quyen sach nay khong co trong thu vien.\n");
							printf("Ban hay nhap lai: ");
							gets_s(mangphu);
						}
						sothutusachmuon[z] = timvitringuoidung(masach, mangphu, tongsosach - 1);
						z++;
						strcat(mangphu, "^");
						strcat(masachmuon, mangphu);
					} 
					tongsosachmuon = tongsosachmuon + sosachmuon;
					dongy = 0;
				}
			}
			printf("Lap phieu muon sach da xong.\n");
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 14)
		{
			char troi[10];
			char madocgiatrasach[100] = "";
			printf("-----------------LAP PHIEU TRA SACH-----------\n");
				printf("Nhap ma doc gia: ");
				gets_s(troi);
				gets_s(madocgiatrasach);
				int sothutu = timvitringuoidung(madocgiamuonsach, madocgiatrasach, sophieu);
				if (sothutu == -1) printf("Doc gia nay khong co trong danh sach muon sach.\n");
				else
				{
					printf("---------Thong tin doc gia--------\n");
					int thutu = timvitringuoidung(madocgia, madocgiatrasach, sodocgia - 1);
					printf("Ho ten: ");
					xuatthongtin(hoten, thutu);
					printf("Ma doc gia: ");
					xuatthongtin(madocgia, thutu);
					printf("Ngay muon sach: %d/%d/%d\n", ngaymuon[sothutu], thangmuon[sothutu], nammuon[sothutu]);
					printf("Ngay tra du kien: %d/%d/%d\n", ngaytradukien[sothutu], thangtradukien[sothutu], namtradukien[sothutu]);
					printf("Nhung quyen sach da muon: \n");
					int i = sosachnguoidungmuon[sothutu];
					for (int j = sosachnguoidungmuon[sothutu - 1] ; j < i + sosachnguoidungmuon[sothutu - 1]; j++)
					{
						printf("Ten sach: ");
						xuatthongtin(tensach, sothutusachmuon[j]);
						printf("Ma sach: ");
						xuatthongtin(masach, sothutusachmuon[j]);
						printf("-------------------------\n");
					}
					printf("Nhap ngay tra thuc te: ");
					scanf("%d %d %d", &ngaytrathucte[sothutu], &thangtrathucte[sothutu], &namtrathucte[sothutu]);
					while (kiemtratinhhoplecuangaynhap(ngaytrathucte[sothutu], thangtrathucte[sothutu], namtrathucte[sothutu]) == 0)
					{
						printf("Ngay nhap vao khong hop le. Ban hay nhap lai: ");
						scanf("%d %d %d", &ngaytrathucte[sothutu], &thangtrathucte[sothutu], &namtrathucte[sothutu]);
					}
					int ng, th, n;
					int khongthoa = 1;
					for (int j = 1; j <= 7; j++)
					{
						ng = ngaymuon[sothutu];
						th = thangmuon[sothutu];
						n = nammuon[sothutu];
						timngaysaungayvuanhap(ng, th, n, j);
						if (ng == ngaytrathucte[sothutu] && th == thangtrathucte[sothutu] && n == namtrathucte[sothutu])
						{
							khongthoa = 0;
							break;
						}
					}
					if (khongthoa == 1)
					{
						printf("Doc gia nay da tra sach qua han cho phep.\n");
						mangchuasothutucacdocgiatrehan[q] = thutu;
						q++;
					}
				}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 15)
		{
			printf("-------------THONG KE SO LUONG SACH TRONG THU VIEN----------\n");
			int S = 0;
			if (lanthemsach==0) printf("Trong thu vien hien chua co quyen sach nao.\n");
			else
			{
				for (int i = 1; i<tongsosach; i++)
				{
					S = S + soquyensach[i];
				}
				printf("Tong so luong sach thu vien hien co la %d quyen\n", S);
				printf("Trong do: \n");
				for (int m = 1; m < tongsosach; m++)
				{
					printf("_");
					xuatthongtin(tensach, m);
					printf(" .So luong: %d quyen", soquyensach[m]);
					printf("\n");
				}
			}
				printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
				scanf("%d", &dongy);
				while (dongy != 0 && dongy != 1)
				{
					printf("Khong hop le. Hay nhap lai: ");
					scanf("%d", &dongy);
				}
		}
		if (x == 16)
		{
			printf("-------------THONG KE SACH THEO THE LOAI---------\n");
			if (lanthemsach == 0) printf("Trong thu vien hien chua co quyen sach nao.\n");
			else
			{
				printf("Trong thu vien hien co nhung the loai sach nhu sau: \n");
				thongkesoluongsachtheotheloai(theloai,soquyensach, tongsosach - 1);
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 17)
		{
			printf("-------------THONG KE SO LUONG DOC GIA TRONG THU VIEN------------\n");
			printf("=_=_ So luong doc gia hien co trong thu vien la: %d nguoi\n", sodocgia - 1);
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 18)
		{
			printf("-------------THONG KE SO LUONG DOC GIA THEO GIOI TINH--------------\n");
			int sonam=0, sonu=0;
			if (lanthemdocgia==0) printf("Trong thu vien hien chua co doc gia nao.\n");
			else
			{
				thongkesoluongtheogioitinh(gt, sonam, sonu, sodocgia - 1);
				printf("So doc gia hien co trong thu vien la: %d nguoi\n", sodocgia - 1);
				printf("Trong do: \n");
				printf("  .So luong doc gia nam la: %d nguoi\n", sonam);
				printf("  .So luong doc gia nu la: %d nguoi\n", sonu);
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 19)
		{
			printf("------------THONG KE SO QUYEN SACH DANG MUON----------\n");
			if (lanthemsach == 0) printf("Trong thu vien hien khong co quyen sach nao.\n");
			else
			{
				printf("Nhung quyen sach hien dang cho muon: \n");
				thongkesachdangmuon(masachmuon,masach, tensach, tongsosachmuon, tongsosach-1);
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
		if (x == 20)
		{
			printf("------------THONG KE CAC DOC GIA BI TRE HAN---------------\n");
			if (mangchuasothutucacdocgiatrehan[0] == 0) printf("Hien khong co doc gia nao bi tre hen.\n");
			else
			{
				for (int i = 0; mangchuasothutucacdocgiatrehan[i] != 0; i++)
				{
					printf("Ho ten: ");
					xuatthongtin(hoten, mangchuasothutucacdocgiatrehan[i]);
					printf("Ma doc gia: ");
					xuatthongtin(madocgia, mangchuasothutucacdocgiatrehan[i]);
					printf("--------------------------\n");
				}
			}
			printf("-----Ban co muon TIEP TUC CHUONG TRINH khong?-----\n Neu co hay nhap 1, muon thoat khoi chuong trinh thi nhap 0: ");
			scanf("%d", &dongy);
			while (dongy != 0 && dongy != 1)
			{
				printf("Khong hop le. Hay nhap lai: ");
				scanf("%d", &dongy);
			}
		}
	}
}


