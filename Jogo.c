#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
char mapa[8][11];
char bola[8][11];
int l,c;
int x,y;

void MapaSeco(){
    for(l=0;l<8;l++){
        for(c=0;c<11;c++){
            mapa[l][c] = ' ';
        }
    }
}
void Obstaculos(){
    for(l=1;l<4;l++){
        for(c=2;c<=7;c++){
            mapa[l][c] = '#';
        }
    }
}
int Barrinha(){
    for(l=7;l<8;l++){
        for(c=3;c<=6;c++){
            mapa[l][c] = '*';
        }
    }


}
char Bolinha(){
    srand(time(NULL));
    for(l=6;l<8;l++){
        for( c=0;c<10;c++){
            if(l==6 && c==4){
                mapa[l][c] = 'o';
            }

        }
    }



}
void Print(){
	printf(" __________\n");
		for (int l=0; l<8; l++){
			printf("|");
			for(int c=0; c<10; c++){
				printf("%c", mapa[l][c]); //mostrar o mapa

            }
			printf("|\n");
		}
	printf(" ----------\n");
    printf("\nDigite (a) para mover pra esquerda\nDigite (d) para mover para direita\nE q pra sair\n");
}
int main(){
    MapaSeco();
    Obstaculos();
    Barrinha();
    Bolinha();
    Print();
    int fim = 1;
    while(fim!=0){
        Sleep(500);
        if(kbhit()){

            switch(getch()){
            case 'd':
                for(int j=0;j<c;j++){
                    if(mapa[7][j] == '*'&& j<6){
                        mapa[7][j+4]='*';
                        mapa[7][j]= ' ';
                        break;
                    }

                }


                    for(x=0;x<8;x++){
                        for(y=0;y<11;y++){
                            if(mapa[x][y] == 'o'){
                                mapa[x-1][y+1] = 'o';
                                mapa[x][y] = ' ';

                            }
                        }

                    }


            case 'a':
                for(int j=0;j<c;j++){
                    if(mapa[7][j] == '*' && j!=0){
                        mapa[7][j-1]='*';
                        mapa[7][j+3]=' ';
                        break;
                    }
                }


                break;
             case 'q':
                fim = 0;
                printf("\nVOCE FINALIZOU O JOGO\n");
                system("pause");
                break;

            }


        }
        system("cls");
        Print();

    }



return 0;
}
