#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <io.h>
#include <wchar.h>
#include <fcntl.h>
#define max_mssv 10
#define max_name 40
#define max_school 31
#define max_day 11
#define max_email 31
#define max_image 31
#define max_introduce 201
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
	f = _wfopen(L"1712839_data.csv", L"r,ccs=UTF-8");
	student ST[20];
	int i = 0;
	int j = 0;
	wchar_t GIN[256];
	wchar_t *KIN;
	int a[20], l = 0;
	int k = 0;
	wprintf(L"Đồ Án 1 -KTLT- 1712839 \n\n\n\n");
	// doc file CSV
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
	//Ghi file HTML
	for (int j = 0; j < i; j++)
	{
		wchar_t FILE_NAME[30];
		wcscpy(FILE_NAME, ST[j].MSSV);
		wcscat(FILE_NAME, L".html");
		wchar_t FILE_PATH[50];
		wcscpy(FILE_PATH, L"WEBSITE/");
		wcscat(FILE_PATH, FILE_NAME);
		FILE*f1 = _wfopen(FILE_PATH, L"wt,ccs=UTF-8");
		fwprintf(f1, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f1, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f1, L"	   <head>\n");
		fwprintf(f1, L"        <meta http-equiv=\"Content-Type\" content=\"text/html; charset = utf-8\" />\n");
		fwprintf(f1, L"        <link rel=\"stylesheet\" type=\"text/css\" href=\"personal.css\" />\n");
		fwprintf(f1, L"        <title>HCMUS - %s</title>\n", ST[j].Name);
		fwprintf(f1, L"    </head>\n");
		fwprintf(f1, L"    <body>\n");
		fwprintf(f1, L"        <div class=\"Layout_container\">\n");
		fwprintf(f1, L"            <!-- Begin Layout Banner Region -->\n");
		fwprintf(f1, L"            <div class=\"Layout_Banner\" >\n");
		fwprintf(f1, L"                <div><img id=\"logo\" src=\"Images/logo.jpg\" height=\"105\" /></div>\n");
		fwprintf(f1, L"                <div class=\"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(f1, L"            </div>\n");
		fwprintf(f1, L"            <!-- End Layout Banner Region -->\n");
		fwprintf(f1, L"            <!-- Begin Layout MainContents Region -->\n");
		fwprintf(f1, L"            <div class=\"Layout_MainContents\">\n");
		fwprintf(f1, L"                <!-- Begin Below Banner Region -->\n");
		fwprintf(f1, L"                <div class=\"Personal_Main_Information\">\n");
		fwprintf(f1, L"                    <!-- Begin Thông tin cá nhân  ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(f1, L"                    <div class=\"Personal_Location\">\n");
		fwprintf(f1, L"                        <img src=\"Images/LogoFooter.jpg\" width=\"27\" height=\"33\" />\n");
		fwprintf(f1, L"                        <span class=\"Personal_FullName\">%s - %s</span>\n", ST[j].Name, ST[j].MSSV);
		fwprintf(f1, L"                        <div class=\"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
		fwprintf(f1, L"                        <br />\n");
		fwprintf(f1, L"                        <div class=\"Personal_Phone\">\n");
		fwprintf(f1, L"                        Email: %s\n", ST[j].Email);
		fwprintf(f1, L"                        </div>\n");
		fwprintf(f1, L"                        <br />\n");
		fwprintf(f1, L"                        <br />\n");
		fwprintf(f1, L"                    </div>\n");
		fwprintf(f1, L"                    <!-- End Thông tin cá nhân ----------------------------------------------------------------------------------------- -->\n");
		fwprintf(f1, L"                    <div class=\"Personal_HinhcanhanKhung\">\n");
		fwprintf(f1, L"                        <img src=\"Images/%s\" class=\"Personal_Hinhcanhan\" />\n", ST[j].Image);
		fwprintf(f1, L"                    </div>\n");
		fwprintf(f1, L"                </div>\n");
		fwprintf(f1, L"                <!-- End Below Banner Region -->\n");
		fwprintf(f1, L"                <!-- Begin MainContents Region -->\n");
		fwprintf(f1, L"                <div class=\"MainContain\">\n");
		fwprintf(f1, L"                <!-- Begin Top Region -->\n");
		fwprintf(f1, L"                    <div class=\"MainContain_Top\">\n");
		fwprintf(f1, L"                        <div class=\"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f1, L"                        <div>\n");
		fwprintf(f1, L"                            <ul class=\"TextInList\">\n");
		fwprintf(f1, L"                                <li>Họ và tên: %s</li>\n", ST[j].Name);
		fwprintf(f1, L"                                <li>MSSV: %s</li>\n", ST[j].MSSV);
		fwprintf(f1, L"                                <li>Sinh viên khoa %s</li>\n", ST[j].School);
		fwprintf(f1, L"                                <li>Ngày sinh: %s</li>\n", ST[j].BirthDay);
		fwprintf(f1, L"                                <li>Email: %s</li>\n", ST[j].Email);
		fwprintf(f1, L"                            </ul>\n");
		fwprintf(f1, L"                        </div>\n");
		fwprintf(f1, L"                        <div class=\"InfoGroup\">Sở thích</div>\n");
		fwprintf(f1, L"                        <div>\n");
		fwprintf(f1, L"                            <ul class=\"TextInList\">\n");
		for (int k1 = 0; k1 < a[k]; k1++)
			fwprintf(f1, L"                                <li>%s</li>\n", ST[j].Hoppy[k1]);
		fwprintf(f1, L"                            </ul>\n");
		fwprintf(f1, L"                        </div>\n");
		fwprintf(f1, L"                        <div class=\"InfoGroup\">Mô tả</div>\n");
		fwprintf(f1, L"                        <div class=\"Description\">\n");
		fwprintf(f1, L"                            %s.\n", ST[j].Introduce_Myself);
		fwprintf(f1, L"                        </div>\n");
		fwprintf(f1, L"                    </div>\n");
		fwprintf(f1, L"                </div>\n");
		fwprintf(f1, L"            </div>\n");
		fwprintf(f1, L"            <!-- Begin Layout Footer -->\n");
		fwprintf(f1, L"            <div class=\"Layout_Footer\">\n");
		fwprintf(f1, L"                <div class=\"divCopyright\">\n");
		fwprintf(f1, L"                    <br />\n");
		fwprintf(f1, L"                    <img src=\"Images/LogoFooter_gray.jpg\" width=\"34\" height=\"41\" /><br />\n");
		fwprintf(f1, L"                    <br />\n");
		fwprintf(f1, L"                    @2013</br>\n");
		fwprintf(f1, L"                    Đồ án giữ kỳ</br>\n");
		fwprintf(f1, L"                Kỹ thuật lập trình</br>\n");
		fwprintf(f1, L"                TH2012/03</br>\n");
		fwprintf(f1, L"                1712839 - Châu Nguyễn Khánh Trình</br>\n");
		fwprintf(f1, L"                </div>\n");
		fwprintf(f1, L"            </div>\n");
		fwprintf(f1, L"            <!-- End Layout Footer -->\n");
		fwprintf(f1, L"        </div>\n");
		fwprintf(f1, L"    </body>\n");
		fwprintf(f1, L"</html>\n");
		k++;
	}
	wprintf(L"Ok Thành công rồi ^.^ \n");
	getch();
}