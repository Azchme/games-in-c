#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include <pthread.h>
#include <dos.h>

HANDLE fechadura;
int pulo;
int score=0;
int flag=1;
int yPerso=16;
int xPerso=8;

void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=(short)x;
    coord.Y=(short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void imprimePersonagem(int x,int y)
{
    int i,j;

    WaitForSingleObject(fechadura,INFINITE);

    gotoxy(x,y);
    printf("%c",217);
    gotoxy(x+1,y);
    printf(" ");
    gotoxy(x+2,y);
    printf("%c",192);

    gotoxy(x,y-1);
    printf("%c",218);
    gotoxy(x+1,y-1);
    printf("%c",193); ///197 ou 193
    gotoxy(x+2,y-1);
    printf("%c",191);

    gotoxy(x,y-2);
    printf("%c",196);
    gotoxy(x+1,y-2);
    printf("%c",197);
    gotoxy(x+2,y-2);
    printf("%c",196);

    gotoxy(x,y-3);
    printf("%c",192);
    gotoxy(x+1,y-3);
    printf("%c",194);
    gotoxy(x+2,y-3);
    printf("%c",217);

    yPerso=y-3;

    gotoxy(x,y-4);
    printf("%c",218);
    gotoxy(x+1,y-4);
    printf("%c",196);
    gotoxy(x+2,y-4);
    printf("%c",191);

    ReleaseMutex(fechadura);

}

void apagaPersonagem(int x,int y)
{
    int i,j;

    WaitForSingleObject(fechadura,INFINITE);
    gotoxy(x,y-4);
    printf("   ");
    gotoxy(x,y-3);
    printf("   ");
    gotoxy(x,y-2);
    printf("   ");
    gotoxy(x,y-1);
    printf("   ");
    gotoxy(x,y);
    printf("   ");

    ReleaseMutex(fechadura);

}

void imprimeColuna(int x, int y, int tipoColuna)
{
    char c1 = 186, c2 = 178, c3 = 219 ;

    WaitForSingleObject(fechadura,INFINITE);

    if(tipoColuna==1)
    {
        gotoxy(x,y-2);
        printf("%c",c1);
        gotoxy(x,y-1);
        printf("%c",c1);
        gotoxy(x,y);
        printf("%c",c1);

        if(yPerso==y&&x==xPerso)
            exit(1);
        if(yPerso==y-1&&x==xPerso)
            exit(1);
        if(yPerso==y-2&&x==xPerso)
            exit(1);

        if(yPerso==y&&x-1==xPerso)
            exit(1);
        if(yPerso==y-1&&x-1==xPerso)
            exit(1);
        if(yPerso==y-2&&x-1==xPerso)
            exit(1);

        if(yPerso==y&&x-2==xPerso)
            exit(1);
        if(yPerso==y-1&&x-2==xPerso)
            exit(1);
        if(yPerso==y-2&&x-2==xPerso)
            exit(1);
    }
    if(tipoColuna==2)
    {
        gotoxy(x,y-3);
        printf("%c",c2);
        gotoxy(x,y-2);
        printf("%c",c2);
        gotoxy(x,y-1);
        printf("%c",c2);
        gotoxy(x,y);
        printf("%c",c2);

        if(yPerso==y&&x==xPerso)
            exit(1);
        if(yPerso==y-1&&x==xPerso)
            exit(1);
        if(yPerso==y-2&&x==xPerso)
            exit(1);
        if(yPerso==y-3&&x==xPerso)
            exit(1);

        if(yPerso==y&&x-1==xPerso)
            exit(1);
        if(yPerso==y-1&&x-1==xPerso)
            exit(1);
        if(yPerso==y-2&&x-1==xPerso)
            exit(1);
        if(yPerso==y-3&&x-1==xPerso)
            exit(1);

        if(yPerso==y&&x-2==xPerso)
            exit(1);
        if(yPerso==y-1&&x-2==xPerso)
            exit(1);
        if(yPerso==y-2&&x-2==xPerso)
            exit(1);
        if(yPerso==y-3&&x-2==xPerso)
            exit(1);

    }
    if(tipoColuna==3)
    {

        gotoxy(x,y-5);
        printf("%c",c3);
        gotoxy(x,y-4);
        printf("%c",c3);
        gotoxy(x,y-3);
        printf("%c",c3);
        gotoxy(x,y-2);
        printf("%c",c3);
        gotoxy(x,y-1);
        printf("%c",c3);
        gotoxy(x,y);
        printf("%c",c3);

        if(yPerso==y&&x==xPerso)
            exit(1);
        if(yPerso==y-1&&x==xPerso)
            exit(1);
        if(yPerso==y-2&&x==xPerso)
            exit(1);
        if(yPerso==y-3&&x==xPerso)
            exit(1);
        if(yPerso==y-4&&x==xPerso)
            exit(1);
        if(yPerso==y-5&&x==xPerso)
            exit(1);

        if(yPerso==y&&x-1==xPerso)
            exit(1);
        if(yPerso==y-1&&x-1==xPerso)
            exit(1);
        if(yPerso==y-2&&x-1==xPerso)
            exit(1);
        if(yPerso==y-3&&x-1==xPerso)
            exit(1);
        if(yPerso==y-4&&x-1==xPerso)
            exit(1);
        if(yPerso==y-5&&x-1==xPerso)
            exit(1);

        if(yPerso==y&&x-2==xPerso)
            exit(1);
        if(yPerso==y-1&&x-2==xPerso)
            exit(1);
        if(yPerso==y-2&&x-2==xPerso)
            exit(1);
        if(yPerso==y-3&&x-2==xPerso)
            exit(1);
        if(yPerso==y-4&&x-2==xPerso)
            exit(1);
        if(yPerso==y-5&&x-2==xPerso)
            exit(1);
    }

    ReleaseMutex(fechadura);
}

void apagaColuna(int x, int y, int tipoColuna)
{
    int i,j;


    if(tipoColuna==1)
    {
        gotoxy(x,y-2);
        printf(" ");
        gotoxy(x,y-1);
        printf(" ");
        gotoxy(x,y);
        printf(" ");
    }
    if(tipoColuna==2)
    {
        gotoxy(x,y-3);
        printf(" ");
        gotoxy(x,y-2);
        printf(" ");
        gotoxy(x,y-1);
        printf(" ");
        gotoxy(x,y);
        printf(" ");
    }
    if(tipoColuna==3)
    {
        gotoxy(x,y-5);
        printf(" ");
        gotoxy(x,y-4);
        printf(" ");
        gotoxy(x,y-3);
        printf(" ");
        gotoxy(x,y-2);
        printf(" ");
        gotoxy(x,y-1);
        printf(" ");
        gotoxy(x,y);
        printf(" ");
    }
}

void capturaTecla()
{
    char tecla;
    while(1)
    {
        pulo=0;
        tecla = getch();
        if (tecla == -32)
            tecla = getch();
        pulo=tecla;
        Sleep(100);
    }
}

void space()
{
    int i;
    WaitForSingleObject(fechadura,INFINITE);
    imprimePersonagem(6,16);
    ReleaseMutex(fechadura);
    for(i=16; i>7; i--) ///Sobe
    {
        WaitForSingleObject(fechadura,INFINITE);
        apagaPersonagem(6,i);
        imprimePersonagem(6,i-1);
        ReleaseMutex(fechadura);

    }
    for(i=7; i<16; i++) ///Desce
    {
        WaitForSingleObject(fechadura,INFINITE);
        apagaPersonagem(6,i);
        imprimePersonagem(6,i+1);
        ReleaseMutex(fechadura);
    }
}

void arrowUp()
{
    int i;
    WaitForSingleObject(fechadura,INFINITE);
    imprimePersonagem(6,16);
    ReleaseMutex(fechadura);
    for(i=16; i>10; i--) ///Sobe
    {
        WaitForSingleObject(fechadura,INFINITE);
        apagaPersonagem(6,i);
        imprimePersonagem(6,i-1);
        ReleaseMutex(fechadura);
    }
    for(i=10; i<16; i++) ///Desce
    {
        WaitForSingleObject(fechadura,INFINITE);
        apagaPersonagem(6,i);
        imprimePersonagem(6,i+1);
        ReleaseMutex(fechadura);
    }
}

void tela()
{
    int i;
    char cB = 223, dE = 219;

    for(i=1; i<70; i++) ///cima
    {
        WaitForSingleObject(fechadura,INFINITE);
        gotoxy(i,0);
        printf("%c",cB);
        ReleaseMutex(fechadura);
    }
    for(i=0; i<20; i++) ///esquerda
    {
        WaitForSingleObject(fechadura,INFINITE);
        gotoxy(0,i);
        printf("%c",dE);
        ReleaseMutex(fechadura);
    }
    for(i=0; i<71; i++) ///baixo
    {
        WaitForSingleObject(fechadura,INFINITE);
        gotoxy(i,20);
        printf("%c",cB);
        ReleaseMutex(fechadura);
    }
    for(i=0; i<20; i++) ///direita
    {
        WaitForSingleObject(fechadura,INFINITE);
        gotoxy(70,i);
        printf("%c",dE);
        ReleaseMutex(fechadura);
    }

    for(i=1; i<70; i++) ///Chao
    {
        WaitForSingleObject(fechadura,INFINITE);
        gotoxy(i,17);
        printf("%c",176);
        gotoxy(i,18);
        printf("%c",176);
        gotoxy(i,19);
        printf("%c",176);
        ReleaseMutex(fechadura);
    }

}

void runner(int x, int y)
{
    ///R
    gotoxy(x,y);
    printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,187);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,201,188);
    gotoxy(x,y+3);
    printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187);
    gotoxy(x,y+4);
    printf("%c%c%c  %c%c%c",219,219,186,219,219,186);
    gotoxy(x,y+5);
    printf("%c%c%c  %c%c%c",200,205,188,200,205,188);

    ///U
    gotoxy(x+8,y);
    printf("%c%c%c   %c%c%c",219,219,187,219,219,187);
    gotoxy(x+8,y+1);
    printf("%c%c%c   %c%c%c",219,219,186,219,219,186);
    gotoxy(x+8,y+2);
    printf("%c%c%c   %c%c%c",219,219,186,219,219,186);
    gotoxy(x+8,y+3);
    printf("%c%c%c   %c%c%c",219,219,186,219,219,186);
    gotoxy(x+8,y+4);
    printf("%c%c%c%c%c%c%c%c%c",200,219,219,219,219,219,219,201,188);
    gotoxy(x+8,y+5);
    printf(" %c%c%c%c%c%c%c ",200,205,205,205,205,205,188);

    ///N
    gotoxy(x+17,y);
    printf("%c%c%c%c   %c%c%c",219,219,219,187,219,219,187);
    gotoxy(x+17,y+1);
    printf("%c%c%c%c%c  %c%c%c",219,219,219,219,187,219,219,186);
    gotoxy(x+17,y+2);
    printf("%c%c%c%c%c%c %c%c%c",219,219,201,219,219,187,219,219,186);
    gotoxy(x+17,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c",219,219,186,200,219,219,187,219,219,186);
    gotoxy(x+17,y+4);
    printf("%c%c%c %c%c%c%c%c%c",219,219,186,200,219,219,219,219,186);
    gotoxy(x+17,y+5);
    printf("%c%c%c  %c%c%c%c%c",200,205,188,200,205,205,205,188);

    ///N
    gotoxy(x+28,y);
    printf("%c%c%c%c   %c%c%c",219,219,219,187,219,219,187);
    gotoxy(x+28,y+1);
    printf("%c%c%c%c%c  %c%c%c",219,219,219,219,187,219,219,186);
    gotoxy(x+28,y+2);
    printf("%c%c%c%c%c%c %c%c%c",219,219,201,219,219,187,219,219,186);
    gotoxy(x+28,y+3);
    printf("%c%c%c%c%c%c%c%c%c%c",219,219,186,200,219,219,187,219,219,186);
    gotoxy(x+28,y+4);
    printf("%c%c%c %c%c%c%c%c%c",219,219,186,200,219,219,219,219,186);
    gotoxy(x+28,y+5);
    printf("%c%c%c  %c%c%c%c%c",200,205,188,200,205,205,205,188);

    ///E
    gotoxy(x+38,y);
    printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,187);
    gotoxy(x+38,y+1);
    printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,205,205,188);
    gotoxy(x+38,y+2);
    printf("%c%c%c%c%c%c  ",219,219,219,219,219,187);
    gotoxy(x+38,y+3);
    printf("%c%c%c%c%c%c  ",219,219,201,205,205,188);
    gotoxy(x+38,y+4);
    printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,187);
    gotoxy(x+38,y+5);
    printf("%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,188);

    ///R
    gotoxy(x+46,y);
    printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,187);
    gotoxy(x+46,y+1);
    printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187);
    gotoxy(x+46,y+2);
    printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,201,188);
    gotoxy(x+46,y+3);
    printf("%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187);
    gotoxy(x+46,y+4);
    printf("%c%c%c  %c%c%c",219,219,186,219,219,186);
    gotoxy(x+46,y+5);
    printf("%c%c%c  %c%c%c",200,205,188,200,205,188);
}

void menuRunner()
{
    WaitForSingleObject(fechadura,INFINITE);
    tela();
    runner(9,4);
    gotoxy(30,12);
    printf("           ");
    while(flag==1)
    {
        gotoxy(30,12);
        printf("PRESS ENTER");
        _sleep(500);
        gotoxy(30,12);
        printf("           ");
        _sleep(500);
        fflush(stdin);
    }
    ReleaseMutex(fechadura);
}

void placar()
{
    while(1)
    {
        WaitForSingleObject(fechadura,INFINITE);

        _sleep(100);
        score++;

        if(score%100==0)
            Beep(750, 300);

        gotoxy(60,4);
        printf("HI %.6d",score);
        ReleaseMutex(fechadura);
    }
}

void escondecursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void movColuna(int tipoColuna)
{
    int i,j;
    WaitForSingleObject(fechadura,INFINITE);
    imprimeColuna(69,16,tipoColuna);
    ReleaseMutex(fechadura);

    for(i=69; i>1; i--) ///Esquerda->Direita
    {
        WaitForSingleObject(fechadura,INFINITE);
        apagaColuna(i,16,tipoColuna);
        imprimeColuna(i-1,16,tipoColuna);
        ReleaseMutex(fechadura);
    }
    WaitForSingleObject(fechadura,INFINITE);
    apagaColuna(i,16,tipoColuna);
    ReleaseMutex(fechadura);
}

void criaColuna()
{
    int tipoColuna=0,tempColuna;
    srand((unsigned)time(NULL));

    while(1)
    {
        tipoColuna =  1 + ( rand() % 3 );
        tempColuna = 1000 + ( rand() % 5000 );
        _sleep(tempColuna);
        _beginthread(movColuna,NULL,tipoColuna);
    }
}

void controles()
{
    while(1)
    {
        switch(pulo)
        {
        case 32: ///Space -> Pulo Maior
            space();
            break;
        case 72: ///arrowUp -> Pulo menor
            arrowUp();
            break;
        case 13:
            flag=0;
            system("CLS");
            tela();
            imprimePersonagem(6,16);
            _beginthread(capturaTecla,NULL,NULL);
            _beginthread(controles,NULL,NULL);
            _beginthread(placar,NULL,NULL);
            _beginthread(criaColuna,NULL,NULL);

            while(1);
            break;
        }
    }
}

void main()
{
    system("color 70");
    system("mode 71,21");
    fechadura=CreateMutex(NULL,FALSE,NULL);
    escondecursor();
    _beginthread(capturaTecla,NULL,NULL);
    _beginthread(controles,NULL,NULL);
    menuRunner();
    while(1);
}
