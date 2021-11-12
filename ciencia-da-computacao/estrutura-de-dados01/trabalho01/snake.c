#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define MAX_X 60
#define MAX_Y 20

int score, espacos, key, prev_key;
double speed = 0.1;

char base[MAX_Y][MAX_X];

typedef struct corpo
{
     int y;
     int x;
     struct corpo *ant;
     struct corpo *prox;
} corpo;

corpo *corpo_cabeca = NULL;
corpo *corpo_cauda = NULL;

typedef struct asteriscos
{
     int y;
     int x;
     struct asteriscos *prox;
} asteriscos;

asteriscos *asteriscos_cabeca = NULL;
asteriscos *asteriscos_cauda = NULL;

struct comida
{
     int y;
     int x;
} comida;

void inicio();
void fim();
void fim2();
void esperar();
void gotoxy(unsigned short, unsigned short);
void gerar();
void add_corpo(int, int);
void desenhar();
void tela();
void input();
void direcao();
void mover(int, int);
void comida2();
void obstaculos2();
void checar();
void matar();
void desalocar();

void inicio()
{
     int key;
     system("cls");
     gotoxy(15, 1);
     printf("Algoritmos e Estrutura de Dados I - Trabalho 2");
     gotoxy(25, 3);
     printf("Instrucoes de como jogar");
     gotoxy(32, 5);
     printf("Comida: %c", 254);
     gotoxy(31, 7);
     printf("Obstaculo: x");
     gotoxy(25, 9);
     printf("Mover: Setas do teclado");
     gotoxy(21, 11);
     printf("Aperte Enter para iniciar o jogo.");
     key = getch();
     while (key != 13)
     {
          key = getch();
     }
     system("cls");
}

void fim()
{
     int key;
     desalocar();
     system("cls");
     gotoxy(23, 1);
     printf("Voce perdeu. Pontos: %d - Espacos: %d", score, espacos);
     gotoxy(8, 3);
     printf("Quer jogar de novo? Aperte Enter para jogar ou Esc para encerrar.");
     key = getch();
     while ((key != 13) && (key != 27))
     {
          key = getch();
     }
     if (key == 13)
     {
          main();
     }
     else if (key == 27)
     {
          exit(0);
     }
}

void fim2()
{
     int key;
     desalocar();
     system("cls");
     gotoxy(23, 1);
     printf("Voce ganhou. Pontos: %d - Espacos: %d", score, espacos);
     gotoxy(8, 3);
     printf("Quer jogar de novo? Aperte Enter para jogar ou Esc para encerrar.");
     key = getch();
     while ((key != 13) && (key != 27))
     {
          key = getch();
     }
     if (key == 13)
     {
          main();
     }
     else if (key == 27)
     {
          exit(0);
     }
}

void esperar(double speed)
{
     clock_t esperar;
     esperar = clock() + speed * CLOCKS_PER_SEC;
     while (clock() < esperar)
     {
     }
}

void gotoxy(unsigned short x, unsigned short y)
{
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD position = {x, y};
     SetConsoleCursorPosition(handle, position);
}

void gerar()
{
     int y, x;
     score = 0;
     espacos = 3;
     speed = 0.1;
     for (y = 0; y < MAX_Y; y++)
     {
          for (x = 0; x < MAX_X; x++)
          {
               base[y][x] = ' ';
          }
     }
     for (y = 1; y < MAX_Y - 1; y++)
     {
          base[y][0] = 186;
          base[y][MAX_X - 1] = 186;
     }
     for (x = 1; x < MAX_X - 1; x++)
     {
          base[0][x] = 205;
          base[MAX_Y - 1][x] = 205;
     }
     base[0][0] = 201;
     base[0][MAX_X - 1] = 187;
     base[MAX_Y - 1][0] = 200;
     base[MAX_Y - 1][MAX_X - 1] = 188;
     add_corpo(10, 30);
     add_corpo(10, 29);
     add_corpo(10, 28);
     desenhar();
     comida2();
     obstaculos2();
     key = (rand() % (80 - 72)) + 72;
     while ((key != 72) && (key != 75) && (key != 77) && (key != 80))
     {
          key = (rand() % (80 - 72)) + 72;
     }
     prev_key = key;
}

void add_corpo(int y, int x)
{
     corpo *tmp;
     tmp = (corpo *)malloc(sizeof(corpo));
     if (tmp == NULL)
     {
          getchar();
          exit(1);
     }
     if (corpo_cabeca == NULL)
     {
          corpo_cabeca = tmp;
          tmp->ant = NULL;
     }
     else
     {
          corpo_cauda->prox = tmp;
          tmp->ant = corpo_cauda;
     }
     tmp->y = y;
     tmp->x = x;
     tmp->prox = NULL;
     corpo_cauda = tmp;
}

void desenhar()
{
     corpo *atual;
     atual = corpo_cabeca;
     while (atual != NULL)
     {
          base[atual->y][atual->x] = '*';
          atual = atual->prox;
     }
     matar();
}

void tela()
{
     gotoxy(0, 0);
     int y, x;
     printf("\n\tPontos: %d - Espacos: %d", score, espacos);
     printf("\n");
     for (y = 0; y < MAX_Y; y++)
     {
          printf("\t");
          for (x = 0; x < MAX_X; x++)
          {
               printf("%c", base[y][x]);
          }
          printf("\n");
     }
     esperar(speed);
}

void input()
{
     if (kbhit())
     {
          prev_key = key;
          key = getch();
          key = getch();
     }
     if (prev_key == 77 && key == 75)
     {
          key = prev_key;
     }
     else if (prev_key == 75 && key == 77)
     {
          key = prev_key;
     }
     else if (prev_key == 72 && key == 80)
     {
          key = prev_key;
     }
     else if (prev_key == 80 && key == 72)
     {
          key = prev_key;
     }
}

void direcao()
{
     int y = corpo_cabeca->y, x = corpo_cabeca->x;
     if (key == 72)
     {
          y--;
          mover(y, x);
     }
     else if (key == 80)
     {
          y++;
          mover(y, x);
     }
     else if (key == 77)
     {
          x++;
          mover(y, x);
     }
     else if (key == 75)
     {
          x--;
          mover(y, x);
     }
     else
     {
          key = prev_key;
          direcao();
     }
}

void mover(int y, int x)
{
     corpo *atual;
     atual = corpo_cauda;
     base[corpo_cauda->y][corpo_cauda->x] = ' ';
     while (atual != corpo_cabeca)
     {
          atual->y = atual->ant->y;
          atual->x = atual->ant->x;
          atual = atual->ant;
     }
     corpo_cabeca->y = y;
     corpo_cabeca->x = x;
     desenhar();
     checar();
}

void comida2()
{
     corpo *b_tmp;
     asteriscos *o_tmp;
     int b_con = 0, o_con = 0;
     comida.x = (rand() % (MAX_X - 3)) + 1;
     comida.y = (rand() % (MAX_Y - 3)) + 1;
     b_tmp = corpo_cabeca;
     while (b_tmp != NULL)
     {
          if ((comida.y == b_tmp->y) && (comida.x == b_tmp->x))
          {
               b_con = 1;
               b_tmp = NULL;
          }
          else
          {
               b_tmp = b_tmp->prox;
          }
     }
     o_tmp = asteriscos_cabeca;
     while (o_tmp != NULL)
     {
          if ((comida.y == o_tmp->y) && (comida.x == o_tmp->x))
          {
               o_con = 1;
               o_tmp = NULL;
          }
          else
          {
               o_tmp = o_tmp->prox;
          }
     }
     if ((b_con == 1) || (o_con == 1))
     {
          comida2();
     }
     base[comida.y][comida.x] = 254;
}

void obstaculos2()
{
     asteriscos *o_tmp;
     corpo *b_tmp;
     o_tmp = (asteriscos *)malloc(sizeof(asteriscos));
     if (o_tmp == NULL)
     {
          getchar();
          exit(1);
     }
     if (asteriscos_cabeca == NULL)
     {
          asteriscos_cabeca = o_tmp;
     }
     else
     {
          asteriscos_cauda->prox = o_tmp;
     }
     o_tmp->x = (rand() % (MAX_X - 3)) + 1;
     o_tmp->y = (rand() % (MAX_Y - 3)) + 1;
     if ((o_tmp->x == comida.x) && (o_tmp->y == comida.y))
     {
          b_tmp = corpo_cabeca;
          while (b_tmp != NULL)
          {
               if ((o_tmp->x == b_tmp->x) && (o_tmp->y == b_tmp->y))
               {
                    free(o_tmp);
                    b_tmp = NULL;
                    obstaculos2();
               }
          }
     }
     o_tmp->prox = NULL;
     asteriscos_cauda = o_tmp;
     base[o_tmp->y][o_tmp->x] = 'x';
}

void checar()
{
     asteriscos *o_tmp;
     if ((corpo_cabeca->y == comida.y) && (corpo_cabeca->x == comida.x))
     {
          if (espacos != 15)
          {
               score++;
               comida2();
               if ((score % 3) == 0)
               {
                    add_corpo(corpo_cauda->y, corpo_cauda->x);
                    speed -= 0.01;
                    espacos++;
                    if (espacos == 15)
                    {
                         fim2();
                    }
                    else
                    {
                         desenhar();
                    }
               }
               if ((score % 2) == 0)
               {
                    obstaculos2();
               }
          }
          else
          {
               fim2();
          }
     }
     if ((corpo_cabeca->y == 0) || (corpo_cabeca->x == 0) || (corpo_cabeca->y == (MAX_Y - 1)) || (corpo_cabeca->x == (MAX_X - 1)))
     {
          fim();
     }
     o_tmp = asteriscos_cabeca;
     while (o_tmp != NULL)
     {
          if ((corpo_cabeca->y == o_tmp->y) && (corpo_cabeca->x == o_tmp->x))
          {
               fim();
          }
          o_tmp = o_tmp->prox;
     }
}

void matar()
{
     corpo *tmp;
     tmp = corpo_cabeca->prox;
     while (tmp != NULL)
     {
          if ((corpo_cabeca->y == tmp->y) && (corpo_cabeca->x == tmp->x))
          {
               tmp = NULL;
               fim();
          }
          else
          {
               tmp = tmp->prox;
          }
     }
}

void desalocar()
{
     corpo *b_atual, *b_prox;
     asteriscos *o_atual, *o_prox;
     b_atual = corpo_cabeca;
     while (b_atual != NULL)
     {
          b_prox = b_atual->prox;
          free(b_atual);
          b_atual = b_prox;
     }
     o_atual = asteriscos_cabeca;
     while (o_atual != NULL)
     {
          o_prox = o_atual->prox;
          free(o_atual);
          o_atual = o_prox;
     }
     corpo_cabeca = NULL;
     corpo_cauda = NULL;
     asteriscos_cabeca = NULL;
     asteriscos_cauda = NULL;
}

int main(void)
{
     inicio();
     srand(time(NULL));
     gerar();
     tela();
     while (1)
     {
          direcao();
          input();
          tela();
     }
     return 0;
}
