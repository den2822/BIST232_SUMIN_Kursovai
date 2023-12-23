#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include < Windows.h >
//���������
struct BD
{
    char name[50];// ������ ��� �������� ����� ��� - �������
    char type[50];// ������ ��� �������� ���� ���-�������
    float rating; // ���������� ��� �������� �������� ���-�������
    char site[50];// ������ ��� �������� ������ ����� ���-�������
    char tel[20];      // ������ ��� �������� ������ ����������� ��������� �������
    char mail[50];// ������ ��� �������� ������ ����������� ����� �������
};
typedef struct BD bd;


void Hello();
void one(bd* info);
void two(bd* search, int schet);
void three(bd* search, int schet);
bd four(bd* syte, int schet);
void vivod(bd vivod);
void openfive(bd* vivod, int schet);
bd six(FILE* S3);

void main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    bd save[100];
    bd newsave;
    int k = 0;//������� ���-�� ���������� ��
    int choice = 1;
    char pyti[50];
    bd temp;
    FILE* file;
    puts("��� ������������ ��������� �� ���-�������");
    puts("��������� ����������: ����� �. �.");
    puts("                    : ������ ����-232");
    while (choice != 0) {
        Hello();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (k < 100) {
                one(&newsave);
                save[k] = newsave;
                k = k + 1;
                puts("���-������ ��������.");

            }
            else {
                puts("���� �����������...");
            }
            break;
        case 2:
            two(save, k);

            break;
        case 3:
            three(save, k);
            break;

        case 4:
            *save = four(save, k);

            break;
        case 5:
            openfive(save, k);
            break;
        case 6:
            if (k < 100) {
                puts("�������� ���� � �����.");
                scanf("%49s", &pyti);
                file = fopen(pyti, "r");
                if (file == NULL) {
                    puts("���� �� ������...");
                }

                else {
                    while (!feof(file) && (k < 100)) {
                        newsave = six(file, save);
                        save[k] = newsave;
                        vivod(save[k]);
                        k = k + 1;
                        if (k == 100) {
                            puts("���� �����������...");
                        }
                    }
                }
            }
             else {
                 puts("���� �����������...");


                break;
        case 7:
            if (k != 0) {
                for (int i = 0; i < k; i++) {
                    vivod(save[i]);
                }
                break;
            }
            else {
                puts("�� �����, �������� �������...");
            }

            }
        }
    }
}

void Hello() {
    puts("�������� ������������ ��� ��������:");
    puts("1. �������� � �� ���-������.");
    puts("2. ����� ���-������� � �� �� ������ �� �����.");
    puts("3. ����� ���-������� � �� �� ���������.");
    puts("4. ���������� �� ����� �����.");
    puts("5. ����� �� ��������� � ����.");
    puts("6. ���� �� ����� � ���������.");
    puts("7. ����� ���� ������ � �������.");
    puts("0. ���������� ���������.");
    puts("-------------------------------------------");
}
void one(bd* info) {
    puts("������� ������� 1. �������� � �� ���-������");
    puts("�������� �������� �������.");
    scanf("%49s", &info->name);
    puts("�������� ��� �����.");
    scanf("%49s", &info->site);
    puts("�������� ��������� �������.");
    scanf("%49s", &info->type);
    puts("�������� ������� �������.");
    scanf("%f", &info->rating);
    puts("�������� ������� ������ ���������.");
    scanf("%19s", &info->tel);
    puts("�������� ����� ����������� �����.");
    scanf("%49s", &info->mail);
    puts("-------------------------------------------");

}
void vivod(bd vivod) {
    printf("��������      : %s\n", vivod.name);
    printf("���������     : %s\n", vivod.type);
    printf("�������       : %.1f\n", vivod.rating);
    printf("����          : %s\n", vivod.site);
    printf("������� ��    : %s\n", vivod.tel);
    printf("����� �� �����: %s\n", vivod.mail);
    puts("-------------------------------------------");
}
void two(bd* search, int schet) {
    puts("������� ������� 2.  ����� ���-������� � �� �� ������ �� �����.");
    if (schet == 0) {
        puts("�� �����, �������� �������...");
    }
    else {
        char vvod[50];
        puts("������� ����� ������� �� �����.");
        scanf("%49s", &vvod);
        for (int i = 0; i < schet; i = i + 1) {
            if (strcmp(search[i].mail, vvod) == 0) {
                vivod(search[i]);

            }
            else {
                puts("������ �� ������...");

            }
        }
    }

}
void three(bd* search, int schet) {
    puts("������� ������� 3.  ����� ���-������� � �� �� ���������.");
    if (schet == 0) {
        puts("�� �����, �������� �������...");
    }
    else {
        char vvod[50];
        puts("������� ��������� ������� �� �����.");
        scanf("%49s", &vvod);
        for (int i = 0; i < schet; i = i + 1) {
            if (strcmp(search[i].type, vvod) == 0) {
                vivod(search[i]);

            }
            else {
                puts("������ �� ������...");

            }
        }
    }
}
bd four(bd* syte, int schet) {
    bd temp;

    puts("������� ������ 4.���������� ������ �� �� ����� �����.");
    for (int i = 0; i < schet; i = i + 1) {

        for (int j = i + 1; j < schet; j = j + 1) {

            if (syte[i].site[0] > syte[j].site[0]) {
                temp = syte[i];
                syte[i] = syte[j];
                syte[j] = temp;

            }
        }
    }
    for (int i = 0; i < schet; i = i + 1) {
    }
    return(*syte);
}
void openfive(bd* vivod, int schet) {
    FILE* S1;
    S1 = fopen("vivod.txt", "w");
    for (int i = 0; i < schet; i++) {
        fprintf(S1, "��������      : %s\n", vivod[i].name);
        fprintf(S1, "���������     : %s\n", vivod[i].type);
        fprintf(S1, "�������       : %.1f\n", vivod[i].rating);
        fprintf(S1, "����          : %s\n", vivod[i].site);
        fprintf(S1, "������� ��    : %s\n", vivod[i].tel);
        fprintf(S1, "����� �� �����: %s\n", vivod[i].mail);
        fprintf(S1, "-------------------------------------------\n");
        printf("�������� %i �� %zu...\n", i + 1, schet);
    }
    fclose(S1);
}
bd six(FILE* S3) {
    bd nnewsave;
    char z[50];
    char w[50]; 
        fgets(nnewsave.name, 50, S3);//��������� �������, � ������ �� ����� ������ \n
        char* ptr = strchr(nnewsave.name, '\n');//���� \n
        if (ptr != NULL) {
            *ptr = '\0';//�������� ��� �� ����� �������
        }

        fgets(nnewsave.type, 50, S3);
        char* pts = strchr(nnewsave.type, '\n');
        if (pts != NULL) {
            *pts = '\0';
        }

        fgets(w, 50, S3);
        char* ptw = strchr(w, '\n');
        if (ptw != NULL) {
            *ptw = '\0';
        }
        nnewsave.rating = atof(w);// fgets ��������� char � ��� ����� float

        fgets(nnewsave.site, 50, S3);
        char* pta = strchr(nnewsave.site, '\n');
        if (pta != NULL) {
            *pta = '\0';
        }

        fgets(nnewsave.tel, 50, S3);
        char* ptt = strchr(z, '\n');
        if (ptt != NULL) {
            *ptt = '\0';
        }

        fgets(nnewsave.mail, 50, S3);
        char* pty = strchr(nnewsave.mail, '\n');
        if (pty != NULL) {
            *pty = '\0';
            
        }
        return(nnewsave);
        }
   


