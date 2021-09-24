#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_P 10

struct Data {
  int dia, mes, ano;
};

struct Pessoa {
  char nome[50];
  char nacionalidade[50];
  struct Data data;
  char foto[50];
} personalidades[MAX_P];

struct Pessoa personalidades[MAX_P] = {
  {"Ada Lovelace","Britânica",{10,12,1815},"foto0.png"},
  {"Grace Hopper","Americana",{9,12,1906},"foto1.png"},
  {"Alan Turing","Britânico",{23,6,1912},"foto2.png"},
  {"Edgar F. Codd","Britânico",{19,8,1923},"foto3.png"},
  {"Marvin Minsky","Americano",{9,8,1927},"foto4.png"},
  {"Edsger Dijkstra","Holandês",{11,5,1930},"foto5.png"},
  {"Donald Knuth","Americano",{10,1,1938},"foto6.png"},
  {"Ward Cunningham","Americano",{26,5,1949},"foto7.png"},
  {"Bill Gates","Americano",{28,10,1955},"foto8.png"},
  {"Linus Torvalds","Finlandês",{28,12,1969},"foto9.png"}
};

int previsaoAno(int *x);

int previsaoAno(int *x) {
  int media, difDatas = 0;

  for (int i = 0; i < MAX_P; ++i) {
    difDatas += labs(personalidades[i].data.ano - personalidades[i+1].data.ano);
  }

  media = difDatas/10;
  return personalidades[9].data.ano + media;
}

int main() {
  int proximoAno;

  printf("A previsão do ano de nascimento da décima-primeira personalidade é: %d\n", previsaoAno(&proximoAno));

  return 0;
}
