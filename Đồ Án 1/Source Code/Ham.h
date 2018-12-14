#include<stdio.h>
#include<string.h>
void choncongviecthuchien();
void hotendocgia(char hoten[]);
void nhapthongtin(char chuoi[]);
void nhapngaythangnam(int ngay[], int thang[], int nam[], int a);
int kiemtratinhhoplecuangaynhap(int ng, int th, int n);
int timkiemvitri(char chuoi[], int a);
void xuatthongtin(char chuoi[], int a);
void xuatngaythang(int ngay[], int thang[], int nam[], int a);
void chinhsuathongtin(char chuoigoc[], char chuoimoi[], int a, int soluong);
void chinhsuangaythang(int ngay[], int thang[], int nam[], int a);
void xoathongtin(char chuoigoc[], int a, int soluong);
void xoangaythang(int mang[], int a, int soluong);
int timvitringuoidung(char chuoigoc[], char chuoitim[], int soluong);// tim xem day la nguoi dung thu may trong danh sach
void timvitritheoten(char chuoigoc[], char chuoitim[], int soluong, int mangchuavitri[]);
void nhaptensach(char tensach[]);
void nhapso(int mang[], int a);
void xuatso(int mang[], int a);
int songay(int thang, int nam);
void timngaysaungayvuanhap(int &ngay, int &thang, int &nam, int n);
void thongkesoluongtheogioitinh(char gioitinh[], int &nam, int &nu, int soluongdocgia);
void thongkesoluongsachtheotheloai(char theloai[],int soluong[], int soluongsach);
int checkmasachtrung(char chuoidesosanh[], char chuoicansanh[], int sosach, int sothutu);
void thongkesachdangmuon(char masachmuon[],char masach[], char tensach[], int soluongsachmuon, int soluongsach);
void xuatsachdangmuon(char sosachmuon[], int soluongsachmuon);