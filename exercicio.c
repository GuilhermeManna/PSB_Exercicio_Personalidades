#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_P 10

typedef struct {
  int dia, mes, ano;
} Data;

struct Pessoa {
  char nome[50];
  char nacionalidade[50];
  Data data;
  char foto[50];
} personalidades[MAX_P];

struct Pessoa personalidades[MAX_P] = {
  {"Ada Lovelace","Britânica",{10,12,1815},"foto0.png"},
  {"Linus Torvalds","Finlandês",{28,12,1969},"foto9.png"},
  {"Grace Hopper","Americana",{9,12,1906},"foto1.png"},
  {"Edgar F. Codd","Britânico",{19,8,1923},"foto3.png"},
  {"Alan Turing","Britânico",{23,6,1912},"foto2.png"},
  {"Edsger Dijkstra","Holandês",{11,5,1930},"foto5.png"},
  {"Ward Cunningham","Americano",{26,5,1949},"foto7.png"},
  {"Donald Knuth","Americano",{10,1,1938},"foto6.png"},
  {"Bill Gates","Americano",{28,10,1955},"foto8.png"},
  {"Marvin Minsky","Americano",{9,8,1927},"foto4.png"}
};

void ordenar(void);
int previsaoAno(void);

void ordenar (void)
{
  int i, j;
  for(i = 0; i < MAX_P; ++i)
  {
    for(j = i; j < MAX_P; ++j)
    {
      if(personalidades[i].data.ano > personalidades[j].data.ano) {
        struct Pessoa troca = personalidades[i];
        personalidades[i] = personalidades[j];
        personalidades[j] = troca;
      }
    }
  }
}

int previsaoAno(void) {
  int media, difDatas = 0;

  for (int i = 0; i < MAX_P; ++i) {
    difDatas += labs(personalidades[i].data.ano - personalidades[i+1].data.ano);
  }

  media = difDatas / MAX_P;
  return personalidades[0].data.ano + media;
}

int main() {
  ordenar();

  printf("A previsão do ano de nascimento da décima-primeira personalidade é: %d\n", previsaoAno());

  return 0;
}
