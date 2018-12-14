#include<stdio.h>
void menucongviec()//danh sach cong viec muon thuc hien
{
	printf("\n");
	printf(" ___________________CHON CONG VIEC THUC HIEN TUONG UNG VOI SO DUNG TRUOC_________________\n");
	printf("|                                                                                        |\n");
	printf("|          _QUAN LI DOC GIA                                                              |\n");
	printf("|           1. Them thong tin doc gia                                                    |\n");
	printf("|           2. Xem danh sach doc gia trong thu vien                                      |\n");
	printf("|           3. Chinh sua thong tin mot doc gia                                           |\n");
	printf("|           4. Xoa thong tin mot doc gia                                                 |\n");
	printf("|           5. Tim kiem doc gia theo CMND                                                |\n");
	printf("|           6. Tim kiem doc gia theo ho ten                                              |\n");
	printf("|         _QUAN LI SACH                                                                  |\n");
	printf("|           7. Them sach                                                                 |\n");
	printf("|           8. Xem danh sach cac sach trong thu vien                                     |\n");
	printf("|           9. Chinh sua thong tin mot quyen sach                                        |\n");
	printf("|          10. Xoa thong tin mot quyen sach                                              |\n");
	printf("|          11. Tim sach theo ISBN                                                        |\n");
	printf("|          12. Tim sach theo ten sach                                                    |\n");
	printf("|        _PHIEU MUON SACH                                                                |\n");
	printf("|          13. Lap phieu muon sach                                                       |\n");
	printf("|          14. Lap phieu tra sach                                                        |\n");
	printf("|        _CAC THONG KE CO BAN                                                            |\n");
	printf("|          15. Thong ke so luong sach trong thu vien                                     |\n");
	printf("|          16. Thong ke so luong sach theo the loai                                      |\n");
	printf("|          17. Thong ke so luong doc gia                                                 |\n");
	printf("|          18. Thong ke so luong doc gia theo gioi tinh                                  |\n");
	printf("|          19. Thong ke so sach dang muon                                                |\n");
	printf("|          20. Thong ke danh sach doc gia bi tre han                                     |\n");
	printf("|________________________________________________________________________________________|\n");
	printf("\n");
}
int kiemtratinhhoplecuangaynhap(int ng, int th, int n)
{
	if (th < 1 || th>12)
	{
		return 0;
	}
	if ((th == 1 || th == 3 || th == 5 || th == 7 || th == 8 || th == 10 || th == 12) && (ng < 0 || ng>31))
	{
		return 0;
	}
	if ((th == 4 || th == 6 || th == 9 || th == 11) && (ng < 0 || ng>30))
	{
		return 0;
	}
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
void timngaysaungaynhap48thang(int &ng, int &th, int &n)
{
	n = n + 4;
}
int ngaytrongthang(int ng, int th, int n)
{
	int sn;
	switch (th)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	{
		sn = 31;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		sn = 30;
		break;
	}
	case 2:
	{
		if (n % 4 == 0)
		{
			sn = 29;
			break;
		}
		else
		{
			sn = 28;
			break;
		}
	}
	}
	return sn;
}
void timngaysaungayvuanhap(int &ng, int &th, int &n, int k)
{
	int sn = ngaytrongthang(ng, th, n);
	ng = ng + k;
	if (ng > sn)
	{
		ng = ng - sn;
		th++;
		if (th > 12)
		{
			th = 1;
			n++;
		}
	}
}

