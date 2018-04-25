#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <io.h>
#include <wchar.h>
#include <fcntl.h>
#define max_mssv 11
#define max_name 31
#define max_school 31
#define max_day 11
#define max_email 31
#define max_image 31
#define max_introduce 101
#define max_hoppy 101
struct student
{
	wchar_t MSSV[max_mssv];
	wchar_t Name[max_name];
	wchar_t School[max_school];
	int School_year;
	wchar_t BirthDay[max_day];
	wchar_t Email[max_email];
	wchar_t Image[max_image];
	wchar_t Introduce_Myself[max_introduce];
	wchar_t Hoppy[11][max_hoppy];
};
void main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	FILE*f = NULL;
	f = _wfopen(L"1712839_Data.csv", L"r,ccs=UTF-8");
	student ST[20];
	int i = 0;
	int j = 0;
	wchar_t GIN[256];
	wchar_t *KIN;
	int a[20], l = 0;
	int k = 0;
	wprintf(L"Chuong trình đọc File CSV và tạo file HTML-------------------------------->\n\n\n\n\n\n\n\n\n\n\n\n");
	//Đọc File CSV
	//---------------------------------------------------------------------------->
	fseek(f, 3L, SEEK_SET);
	while (fgetws(GIN, 255, f) != NULL)
	{
		KIN = wcstok(GIN, L","); wcscpy(ST[i].MSSV, KIN);
		KIN = wcstok(NULL, L","); wcscpy(ST[i].Name, KIN);
		KIN = wcstok(NULL, L","); wcscpy(ST[i].School, KIN);
		KIN = wcstok(NULL, L","); ST[i].School_year = _wtoi(KIN);
		KIN = wcstok(NULL, L","); wcscpy(ST[i].BirthDay, KIN);
		KIN = wcstok(NULL, L","); wcscpy(ST[i].Email, KIN);
		KIN = wcstok(NULL, L","); wcscpy(ST[i].Image, KIN);
		KIN = wcstok(NULL, L","); wcscpy(ST[i].Introduce_Myself, KIN);
		j = 0;
		while (1)
		{
			KIN = wcstok(NULL, L",");
			if (KIN == NULL) break;
			wcscpy(ST[i].Hoppy[j], KIN);
			j++;
		}
		a[l] = j; l++;
		wprintf(L"\n");
		i++;
	}
	wprintf(L"\n");
}