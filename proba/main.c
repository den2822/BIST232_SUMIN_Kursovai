#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include < Windows.h >
//Структура
struct BD
{
    char name[50];// массив для хранения имени веб - сервиса
    char type[50];// массив для хранения типа веб-сервиса
    float rating; // переменная для хранения рейтинга веб-сервиса
    char site[50];// массив для хранения адреса сайта веб-сервиса
    char tel[20];      // массив для хранения номера технической поддержки сервиса
    char mail[50];// массив для хранения адреса электронной почты сервиса
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
    int k = 0;//счетчик кол-ва записанных БД
    int choice = 1;
    char pyti[50];
    bd temp;
    FILE* file;
    puts("Вас приветствует программа БД Веб-сервисы");
    puts("Программу разработал: Сумин Д. А.");
    puts("                    : Группа БИСТ-232");
    while (choice != 0) {
        Hello();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (k < 100) {
                one(&newsave);
                save[k] = newsave;
                k = k + 1;
                puts("Веб-сервис добавлен.");

            }
            else {
                puts("база переполнена...");
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
                puts("напишите путь к файлу.");
                scanf("%49s", &pyti);
                file = fopen(pyti, "r");
                if (file == NULL) {
                    puts("Файл не найден...");
                }

                else {
                    while (!feof(file) && (k < 100)) {
                        newsave = six(file, save);
                        save[k] = newsave;
                        vivod(save[k]);
                        k = k + 1;
                        if (k == 100) {
                            puts("база переполнена...");
                        }
                    }
                }
            }
             else {
                 puts("база переполнена...");


                break;
        case 7:
            if (k != 0) {
                for (int i = 0; i < k; i++) {
                    vivod(save[i]);
                }
                break;
            }
            else {
                puts("БД пуста, добавьте сервисы...");
            }

            }
        }
    }
}

void Hello() {
    puts("Выбирети интересующее вас действие:");
    puts("1. Добавить в БД Веб-сервис.");
    puts("2. Поиск Веб-сервиса в БД по адресу эл почты.");
    puts("3. Поиск Веб-сервиса в БД по категории.");
    puts("4. Сортировка по имени сайта.");
    puts("5. Вывод из программы в файл.");
    puts("6. Ввод из файла в программу.");
    puts("7. Вывод базы данных в консоль.");
    puts("0. Завершение программы.");
    puts("-------------------------------------------");
}
void one(bd* info) {
    puts("Выбрана функция 1. Добавить в БД Веб-сервис");
    puts("Напишите название сервиса.");
    scanf("%49s", &info->name);
    puts("Напишите имя сайта.");
    scanf("%49s", &info->site);
    puts("Напишите категорию сервиса.");
    scanf("%49s", &info->type);
    puts("Напишите рейтинг сервиса.");
    scanf("%f", &info->rating);
    puts("Напишите телефон службы поддержки.");
    scanf("%19s", &info->tel);
    puts("Напишите адрес электронной почты.");
    scanf("%49s", &info->mail);
    puts("-------------------------------------------");

}
void vivod(bd vivod) {
    printf("название      : %s\n", vivod.name);
    printf("категория     : %s\n", vivod.type);
    printf("рейтинг       : %.1f\n", vivod.rating);
    printf("сайт          : %s\n", vivod.site);
    printf("телефон тп    : %s\n", vivod.tel);
    printf("адрес эл почты: %s\n", vivod.mail);
    puts("-------------------------------------------");
}
void two(bd* search, int schet) {
    puts("Выбрана функция 2.  Поиск Веб-сервиса в БД по адресу эл почты.");
    if (schet == 0) {
        puts("БД пуста, добавьте сервисы...");
    }
    else {
        char vvod[50];
        puts("Введите адрес который вы ищите.");
        scanf("%49s", &vvod);
        for (int i = 0; i < schet; i = i + 1) {
            if (strcmp(search[i].mail, vvod) == 0) {
                vivod(search[i]);

            }
            else {
                puts("сервис не найден...");

            }
        }
    }

}
void three(bd* search, int schet) {
    puts("Выбрана функция 3.  Поиск Веб-сервиса в БД по категории.");
    if (schet == 0) {
        puts("БД пуста, добавьте сервисы...");
    }
    else {
        char vvod[50];
        puts("Введите категорию которую вы ищите.");
        scanf("%49s", &vvod);
        for (int i = 0; i < schet; i = i + 1) {
            if (strcmp(search[i].type, vvod) == 0) {
                vivod(search[i]);

            }
            else {
                puts("сервис не найден...");

            }
        }
    }
}
bd four(bd* syte, int schet) {
    bd temp;

    puts("Выбрана фунция 4.Сортировка списка БД по имени сайта.");
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
        fprintf(S1, "название      : %s\n", vivod[i].name);
        fprintf(S1, "категория     : %s\n", vivod[i].type);
        fprintf(S1, "рейтинг       : %.1f\n", vivod[i].rating);
        fprintf(S1, "сайт          : %s\n", vivod[i].site);
        fprintf(S1, "телефон тп    : %s\n", vivod[i].tel);
        fprintf(S1, "адрес эл почты: %s\n", vivod[i].mail);
        fprintf(S1, "-------------------------------------------\n");
        printf("записано %i из %zu...\n", i + 1, schet);
    }
    fclose(S1);
}
bd six(FILE* S3) {
    bd nnewsave;
    char z[50];
    char w[50]; 
        fgets(nnewsave.name, 50, S3);//сканирует строчку, и ставит на конец символ \n
        char* ptr = strchr(nnewsave.name, '\n');//ищем \n
        if (ptr != NULL) {
            *ptr = '\0';//заменяем его на конец массива
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
        nnewsave.rating = atof(w);// fgets сканирует char а нам нужен float

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
   


