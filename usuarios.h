#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX_USUARIOS 50
#define MAX_NOME 51
#define MAX_EMAIL 51
#define MAX_SENHA 21
#define MAX_ALUNOS 40
#define MAX_NOTAS 3 // Máximo de 3 notas

typedef enum {
    ADMINISTRADOR,
    PROFESSOR,
    ALUNO
} TipoUsuario;

typedef struct {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];
    int ra;
    float notas[MAX_NOTAS]; // Notas do aluno
    int num_notas; // Contador de notas
    float media;
    TipoUsuario tipo;
} Usuario;

extern Usuario usuarios[MAX_USUARIOS];
extern int num_usuarios;
extern int num_alunos;

int gerarRA();
void cadastrarUsuario();
Usuario* autenticarUsuario();
void listarAlunos(Usuario* usuario);
void cadastrarNotas(Usuario* usuario);
void exibirNotas(Usuario* usuario);
void editarUsuario(Usuario* usuario);
void salvarDados();
void carregarDados();

#endif //USUARIOS_H