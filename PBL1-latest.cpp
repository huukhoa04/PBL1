#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"
#define name_limit 20
#define glimit 5
#define adrlimit 30
#define email_limit 30
#define max 100
struct date{
	int day;
	int month;
	int year;
};
struct sinhvien{

	int ID;
	char firstname[name_limit];
	char secondname[name_limit];
	char lastname[name_limit];
	char sex[glimit];
	char address[adrlimit];
	date birth;
	char email[email_limit];
};
typedef sinhvien SV;
void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
	
}
void capnhatsinhvien(SV sv[], int &n, int *position);
void themsinhvien(SV &sv, int i);
void structswap(SV *sv1, SV *sv2);
void xoasinhvien(SV sv[], int &n);
void timkiemsinhvien(SV sv[], int &n,char c);
void capmasv(SV &sv, int i);
void capemailsv(SV &sv);
void indanhsach(SV sv[], int &n);
void alphabetsortAZ(SV sv[], int &n);
void alphabetsortZA(SV sv[], int &n);
void menu(SV sv[], int &n);
int main(int argc, char *argv[]){							//main
	SV sv[max];
	int n;
	menu(sv,n);
	return(0);
}
void capnhatsinhvien(SV sv[], int &n, int *position){
	fflush(stdin);
	printf("\nNHAP SO LUONG SINH VIEN CAN THEM: "); scanf("%d", &n);
	for (int i=*position+1; i<=*position+n; i++){
	themsinhvien(sv[i], i);
	capmasv(sv[i],i);	
	capemailsv(sv[i]);
	}
	*position+=n;	
}

void themsinhvien(SV &sv, int i){
	fflush(stdin);
	printf("nhap thong tin cho sv thu %d", i);	fflush(stdin);
	printf("\nnhap ho: "); fgets(sv.firstname, sizeof(sv.firstname), stdin); xoaXuongDong(sv.firstname);
	printf("\nnhap ten lot: "); fflush(stdin); fgets(sv.secondname, sizeof(sv.secondname), stdin); xoaXuongDong(sv.secondname);
	printf("\nnhap ten: "); fflush(stdin); fgets(sv.lastname, sizeof(sv.lastname), stdin); xoaXuongDong(sv.lastname);
	printf("\nnhap ngay sinh:"); fflush(stdin); scanf("%d%d%d", &sv.birth.day, &sv.birth.month, &sv.birth.year);
	printf("\ngioi tinh: "); fflush(stdin); fgets(sv.sex, sizeof(sv.sex), stdin); xoaXuongDong(sv.sex);
	printf("\ndia chi: "); fflush(stdin); fgets(sv.address, sizeof(sv.address), stdin); xoaXuongDong(sv.address);
	
	
}

void capmasv(SV &sv,int i){
	sv.ID = 10000+i;
}

void capemailsv(SV &sv){
	char alias[20]="@sv.dut.udn.vn";
	sprintf(sv.email,"%d",sv.ID);
	strcat(sv.email,alias);
	
}

void in(SV &sv, int i){
	printf("\n%2d \t%s %s %s  \t\t\t%d/%d/%d \t  %s \t\t%s \t%d \t%4s",i, sv.firstname, sv.secondname, sv.lastname, sv.birth.day, sv.birth.month, sv.birth.year, sv.sex, sv.address, sv.ID, sv.email); 
}

void indanhsach(SV sv[], int &n){
	if (n==0) printf("chua co danh sach sinh vien");
	else{
	printf("\nSTT\t   Ho va ten\t\t\t   \tNgay sinh\tGioi tinh\tDia chi\t\tMaSV\t\tEmailsv");
	for (int i=1; i<=n; i++){
		in(sv[i],i);
		//printf("\n%2d \t%s %s %s  \t\t\t%d/%d/%d \t  %s \t\t%s \t%d \t%4s",sv[i].sothutu, sv[i].firstname, sv[i].secondname, sv[i].lastname, sv[i].birth.day, sv[i].birth.month, sv[i].birth.year, sv[i].sex, sv[i].address, sv[i].ID, sv[i].email);
	}}
}

void structswap(SV *sv1, SV *sv2){
	SV temp= *sv1;
	*sv1 = *sv2;
	*sv2 = temp;
}

void alphabetsortAZ(SV sv[], int &n){
	SV temp;
	for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
         if(strcmp(sv[i].lastname,sv[j].lastname)>0){
            structswap(&sv[i],&sv[j]);}
}

void alphabetsortZA(SV sv[], int &n){
	SV temp;
	for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
         if(strcmp(sv[i].lastname,sv[j].lastname)<0){
            structswap(&sv[i],&sv[j]);}
}

void timkiemsinhvien(SV sv[], int &n, char c){
	fflush(stdin);
	int fID;
	char fName[name_limit];
	switch(c){
	case '2':{
	printf("\nnhap masv can tim"); scanf("%d", &fID);
	printf("danh sach cac sv co ma sv %d", fID);
	for (int i=1; i<=n; i++)
	if (fID==sv[i].ID) 	in(sv[i],i); //printf("\n%2d \t%s %s %s  \t\t\t%d/%d/%d \t  %s \t\t%s \t%d \t%4s",sv[i].sothutu, sv[i].firstname, sv[i].secondname, sv[i].lastname, sv[i].birth.day, sv[i].birth.month, sv[i].birth.year, sv[i].sex, sv[i].address, sv[i].ID, sv[i].email);

	break;}
	case '1':{
	printf("\nnhap ten can tim: "); fgets(fName, sizeof(fName), stdin);  xoaXuongDong(fName);
	printf("danh sach cac sv co ten: %s", fName);
	for (int i=1; i<=n; i++)
	if (strcmp(sv[i].lastname,fName)==0) in(sv[i],i); //printf("\n%2d \t%s %s %s  \t\t\t%d/%d/%d \t  %s \t\t%s \t%d \t%4s",sv[i].sothutu, sv[i].firstname, sv[i].secondname, sv[i].lastname, sv[i].birth.day, sv[i].birth.month, sv[i].birth.year, sv[i].sex, sv[i].address, sv[i].ID, sv[i].email);
	break;
	}}
}
void xoasinhvien(SV sv[], int &n){
	fflush(stdin);
	char select_var;
	int fID;
	int i;
	printf("\nNHAP MA SINH VIEN CUA SINH VIEN CAN XOA"); scanf("%d", &fID);
	while(i<n){
		i++;
	if (fID==sv[i].ID){
		for (int j=i; i<n; i++){
			sv[j] = sv[j+1];
		}
		n--;
	}}
}

void menu(SV sv[], int &n){
	int c=1;
	int p=0;
	char select_var;
	char sort_select_var;
	printf("\n\n\tMADE BY NGUYEN HUU KHOA\n\n");
	while(c>0){
	fflush(stdin);
	printf("------QUAN LY DANH SACH SINH VIEN------\n");
	printf("1.THEM SINH VIEN\n");
	printf("2.IN DANH SACH SINH VIEN\n");
	printf("3.SAP XEP SINH VIEN\n");
	printf("4.TIM KIEM SINH VIEN\n");
	printf("5.XOA SINH VIEN\n");
	printf("0.THOAT KHOI CHUONG TRINH\n");
	printf("\nNHAP LUA CHON CUA BAN: "); scanf("%c", &select_var);
	switch(select_var){
		case '0':{
			c=0;
			break;
		}
		case '1': {
		capnhatsinhvien(sv,n,&p);
		break;
		}
				  
		case '2': {
		indanhsach(sv,p);
		break;
				   }
				  
		case '3': {
		fflush(stdin);
		printf("\t1.SAP XEP THEO TEN TU A-->Z\n");
		printf("\t2.SAP XEP THEO TEN TU Z-->A\n");
		printf("\nNHAP LUA CHON CUA BAN: "); scanf("%c", &sort_select_var); fflush(stdin);
		if (sort_select_var == '1') alphabetsortAZ(sv,p);
		if (sort_select_var == '2') alphabetsortZA(sv,p);
		break;
				   }
		case '4': {
			fflush(stdin);
		printf("\t1.TIM KIEM THEO TEN\n");
		printf("\t2.TIM KIEM THEO MA SINH VIEN\n");
		printf("\nNHAP LUA CHON CUA BAN: "); scanf("%c", &sort_select_var);
		timkiemsinhvien(sv,p,sort_select_var);
		break;
		}
		case '5':{
			xoasinhvien(sv,p);
			break;
		}
	}	if (c>0){
		printf("\nnhap 0 de ket thuc chuong trinh"); scanf("%d", &c);
		}
	}
}
