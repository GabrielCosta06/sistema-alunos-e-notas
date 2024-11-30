#include "usuarios.h"

Usuario usuarios[MAX_USUARIOS];
int num_usuarios = 0;
int num_alunos;


int main() {
    carregarDados();
    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1. Cadastrar Usuario\n");
        printf("2. Autenticar Usuario\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2: {
                Usuario* usuario = autenticarUsuario();
                if (usuario != NULL) {
                    
                    //Criando menus para diferentes usuários
                    //Menu Adm
                    if (usuario->tipo == ADMINISTRADOR) {
                        while (1) {
                            printf("Menu de Usuario:\n");
                            printf("1. Cadastrar Usuario\n");
                            printf("2. Listar Alunos\n");
                            printf("3. Cadastrar Notas\n");
                            printf("4. Modificar Usuario\n");
                            printf("5. Ativar/Inativar Aluno\n");
                            printf("6. Sair\n");
                            printf("Opcao: ");
                            int opcao_usuario;
                            scanf("%d", &opcao_usuario);

                            switch (opcao_usuario) {
                                case 1:
                                    cadastrarUsuario();
                                    break;
                                case 2:
                                    listarAlunos(usuario);
                                    break;
                                case 3:
                                    cadastrarNotas(usuario);
                                    break;
                                case 4:
                                    editarUsuario(usuario);
                                    break;

                                case 5: // Opção para gerenciar a ativação/inativação de alunos
                                printf("1. Inativar Aluno\n");
                                printf("2. Ativar Aluno\n");
                                printf("Opcao: ");
                                int opcao_ativacao;
                                scanf("%d", &opcao_ativacao);
                                int ra_aluno;
                                printf("Digite o RA do aluno: ");
                                scanf("%d", &ra_aluno);
                                
                                if (opcao_ativacao == 1) {
                                    inativarAluno(ra_aluno);
                                } else if (opcao_ativacao == 2) {
                                    ativarAluno(ra_aluno);
                                } else {
                                    printf("Opcao invalida.\n");
                                }
                                   
                                    break;
                                
                                case 6: 
                                     printf("Voltando para o menu inicial...\n");
                                     salvarDados();
                                     break;
                                default:
                                    printf("Opcao invalida.\n");
                            }
                            if (opcao_usuario == 6) {
                                break;
                            }
                        }
                    } else if (usuario->tipo == PROFESSOR) {
                       //Menu Professor
                        while (1) {
                            printf("Menu de Usuario:\n");
                            printf("1. Listar Alunos\n");
                            printf("2. Cadastrar Notas\n");
                            printf("5. Sair\n");
                            printf("Opcao: ");
                            int opcao_usuario;
                            scanf("%d", &opcao_usuario);

                            switch (opcao_usuario) {
                                case 1:
                                    listarAlunos(usuario);
                                break;
                                case 2:
                                    cadastrarNotas(usuario);
                                break;
                                case 3:
                                    exibirNotas(usuario);
                                break;
                                case 5:
                                    salvarDados();
                                    break;
                                default:
                                    printf("Opcao invalida.\n");
                            }
                            if (opcao_usuario == 5) {
                                break;
                            }
                        }
                    }else if (usuario->tipo == ALUNO) {
                        //Menu Aluno
                        printf("Bem-vindo, %s!\n", usuario->nome);
                        while (1) {
                            printf("Menu de Usuario:\n");
                            printf("1. Exibir Notas\n");
                            printf("5. Sair\n");
                            printf("Opcao: ");
                            int opcao_usuario;
                            scanf("%d", &opcao_usuario);

                            switch (opcao_usuario) {
                                case 1:
                                    exibirNotas(usuario);
                                    break;
                                case 5:
                                    printf("Voltando para o menu inicial...\n");
                                    salvarDados();
                                    break;
                                default:
                                    printf("Opcao invalida.\n");
                            }
                            if (opcao_usuario == 5) {
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case 0:
                salvarDados();
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }
}


int gerarRA() {
    return num_alunos++;
}

/**
 * @brief Salva os dados dos usuários em um arquivo.
 *
 * Esta função grava os dados dos usuários em um arquivo chamado "usuarios.txt".
 * Inclui informações como nome, email, senha, RA, tipo de usuário, notas e
 * estado de atividade. Útil para persistir os dados após o encerramento do programa.
 *
 * @note O arquivo é salvo no diretório "C:\".
 * @warning Certifique-se de ter permissões de escrita no diretório especificado.
 */

void salvarDados() {
    FILE *file = fopen("C:\\usuarios.txt", "w");
    if (!file) {
        perror("Erro ao abrir o arquivo para escrita!");
        return;
    }

    // Salvar o número de alunos
    fprintf(file, "NumAlunos: %d\n", num_alunos);

    // Salvar os dados dos usuários
    for (int i = 0; i < num_usuarios; i++) {
        Usuario u = usuarios[i];
        fprintf(file, "Nome: %s\nEmail: %s\nSenha: %s\nRA: %d\nTipo: %d\nNumNotas: %d\nAtivo: %d\nNotas:",
                u.nome, u.email, u.senha, u.ra, u.tipo, u.num_notas, u.ativo); // Incluindo o campo ativo
        for (int j = 0; j < u.num_notas; j++) {
            fprintf(file, " %.2f", u.notas[j]);
        }
        fprintf(file, "\nMédia: %.2f\n\n", u.media);
    }
    fclose(file);
    printf("Dados salvos com sucesso!\n");
}

/**
 * @brief Carrega os dados dos usuários de um arquivo.
 *
 * Lê os dados previamente salvos no arquivo "usuarios.txt" e carrega os
 * usuários na memória do programa. Inclui informações como nome, email, senha,
 * RA, tipo de usuário, notas e estado de atividade.
 *
 * @note O arquivo deve estar localizado em "C:\".
 * @warning Certifique-se de que o arquivo "usuarios.txt" existe e está no formato esperado.
 */

void carregarDados() {
    FILE *file = fopen("C:\\usuarios.txt", "r");
    if (!file) {
        perror("Erro ao abrir o arquivo para leitura!");
        return;
    }

    // Ler o número de alunos
    fscanf(file, "NumAlunos: %d\n", &num_alunos);

    while (fscanf(file, "Nome: %[^\n]\nEmail: %[^\n]\nSenha: %[^\n]\nRA: %d\nTipo: %d\nNumNotas: %d\nAtivo: %d\nNotas:",
                  usuarios[num_usuarios].nome, usuarios[num_usuarios].email, usuarios[num_usuarios].senha,
                  &usuarios[num_usuarios].ra, (int*)&usuarios[num_usuarios].tipo, &usuarios[num_usuarios].num_notas,
                  &usuarios[num_usuarios].ativo) == 7) { // Agora lê também o campo ativo

        for (int j = 0; j < usuarios[num_usuarios].num_notas; j++) {
            fscanf(file, " %f", &usuarios[num_usuarios].notas[j]);
        }
        fscanf(file, "\nMédia: %f\n\n", &usuarios[num_usuarios].media);

        num_usuarios++;
    }
    fclose(file);
    printf("Dados carregados com sucesso!\n");
}

/**
 * @brief Cadastra um novo usuário no sistema.
 *
 * Solicita os dados do novo usuário, como nome, email, senha e tipo de usuário.
 * Caso o tipo seja "Aluno", atribui automaticamente um RA e inicializa o estado
 * como ativo. O email é verificado para evitar duplicatas.
 *
 * @note O novo usuário é salvo imediatamente no arquivo "usuarios.txt".
 * @warning O cadastro falha se o limite de usuários ou alunos for atingido.
 *
 * @details Tipos de usuários:
 * - 0: Administrador
 * - 1: Professor
 * - 2: Aluno
 */

void cadastrarUsuario() {
    if (num_usuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido\n");
        return;
    }
    Usuario novo_usuario = {0};
    printf("Digite o nome do usuario: ");
    scanf(" %[^\n]", novo_usuario.nome);
    printf("Digite o e-mail do usuario: ");
    scanf(" %[^\n]", novo_usuario.email);

    int emailExistente = 0; // Variável para verificar se o email já existe

    for (int i = 0; i < num_usuarios; i++) {
    if (strcmp(usuarios[i].email, novo_usuario.email) == 0) {
        emailExistente = 1; // Email já existe
        break; // Sai do loop
        }
    }   
    if (emailExistente) {
   printf("O email ja esta cadastrado. Por favor, use outro email\n");
        return; // Retorna para não continuar com o cadastro
    }

    printf("Digite a senha do usuario: ");
    scanf(" %[^\n]", novo_usuario.senha);

    printf("Digite o tipo de usuário (0 - Administrador, 1 - Professor, 2 - Aluno): ");
    int tipo;
    scanf("%d", &tipo);

    //Verificando se está no intervalo do tipo
    if (tipo < 0 || tipo > 2) {
        printf("Tipo invalido\n");
        return cadastrarUsuario();
    }
    novo_usuario.tipo = (TipoUsuario)tipo;


    if (novo_usuario.tipo == ALUNO) {
        if (num_alunos > MAX_ALUNOS) {
            printf("Maximo de alunos atingido\n");
            return;
        }
        // Se for um aluno, atribua o RA e inicialize as notas
        novo_usuario.ra = gerarRA(); // Gera um RA automático
        novo_usuario.num_notas = 0; // Inicializa o contador de notas
        novo_usuario.media = 0.0; //Inicializa a media
        novo_usuario.ativo = 1; // Define o aluno como ativo ao cadastrar
    }

    usuarios[num_usuarios++] = novo_usuario;
    salvarDados();
    printf("Usuario cadastrado com sucesso!\n");
}

/**
 * @brief Inativa um aluno com base no RA.
 *
 * Esta função localiza um aluno pelo RA, verifica seu estado e, se ativo, o define como inativo.
 * O estado do aluno é persistido no arquivo de dados.
 *
 * @param ra O RA do aluno a ser inativado.
 *
 * @note Somente alunos podem ser inativados.
 * @warning Se o aluno já estiver inativo, nenhuma ação será tomada.
 */

void inativarAluno(int ra) {
    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].ra == ra && usuarios[i].tipo == ALUNO) {
            if (usuarios[i].ativo == 0) {
                printf("O aluno já está inativo.\n");
                return;
            }
            usuarios[i].ativo = 0; // Inativa o aluno
            printf("Aluno %s inativado com sucesso!\n", usuarios[i].nome);
            salvarDados();
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

/**
 * @brief Ativa um aluno com base no RA.
 *
 * Esta função localiza um aluno pelo RA, verifica seu estado e, se inativo, o define como ativo.
 * O estado do aluno é persistido no arquivo de dados.
 *
 * @param ra O RA do aluno a ser ativado.
 *
 * @note Somente alunos podem ser ativados.
 * @warning Se o aluno já estiver ativo, nenhuma ação será tomada.
 */

void ativarAluno(int ra) {
    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].ra == ra && usuarios[i].tipo == ALUNO) {
            if (usuarios[i].ativo == 1) {
                printf("O aluno já está ativo.\n");
                return;
            }
            usuarios[i].ativo = 1; // Ativa o aluno
            printf("Aluno %s ativado com sucesso!\n", usuarios[i].nome);
            salvarDados();
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

/**
 * @brief Autentica um usuário com base em email e senha.
 *
 * Solicita o email e senha do usuário e verifica se as credenciais correspondem a algum
 * usuário cadastrado. Retorna um ponteiro para o usuário autenticado em caso de sucesso.
 *
 * @return Ponteiro para o usuário autenticado ou NULL se a autenticação falhar.
 *
 * @warning A autenticação falha se o email ou senha estiverem incorretos.
 */

Usuario* autenticarUsuario() {
    char email[MAX_EMAIL];
    char senha[MAX_SENHA];

    printf("Digite o e-mail: ");
    scanf(" %[^\n]", email);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha);

    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            return &usuarios[i]; // Retorna o usuário autenticado
        }
    }
    printf("E-mail ou senha invalidos\n");
    return NULL;
}


/**
 * @brief Lista todos os alunos ativos no sistema.
 *
 * Apenas administradores e professores têm permissão para acessar esta função.
 * Exibe informações como RA, nome e email dos alunos.
 *
 * @param usuario O ponteiro para o usuário que está executando a função.
 *
 * @note Alunos inativos não serão exibidos.
 * @warning O acesso é negado para usuários que não sejam administradores ou professores.
 */
void listarAlunos(Usuario* usuario) {
    if (usuario->tipo != ADMINISTRADOR && usuario->tipo != PROFESSOR) {
        printf("Acesso negado. Apenas administradores e professores podem listar alunos.\n");
        return;
    }

    printf("Lista de Alunos:\n");
    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].tipo == ALUNO && usuarios[i].ativo == 1) { // Verifica se o aluno está ativo
            printf("RA: %d, Nome: %s, E-mail: %s\n", usuarios[i].ra, usuarios[i].nome, usuarios[i].email);
        }
    }
}

/**
 * @brief Cadastra uma nova nota para um aluno.
 *
 * Localiza um aluno pelo RA e adiciona uma nova nota, desde que o limite de notas não tenha
 * sido atingido e a nota esteja no intervalo de 0 a 10. Atualiza a média do aluno automaticamente.
 *
 * @param usuario O ponteiro para o professor que está executando a função.
 *
 * @note Apenas professores podem cadastrar notas.
 * @warning A função falha se o RA não for encontrado ou se o número máximo de notas for atingido.
 */

void cadastrarNotas(Usuario* usuario) {
    if (usuario->tipo != PROFESSOR) {
        printf("Acesso negado. Apenas professores podem cadastrar notas\n");
        return;
    }

    int ra;
    printf("Digite o RA do aluno: ");
    scanf("%d", &ra);

    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].ra == ra && usuarios[i].tipo == ALUNO) {
            if (usuarios[i].num_notas >= MAX_NOTAS) {
                printf("Maximo de notas atingido para este aluno\n");
                return;
            }

            float nota;
            printf("Digite a nota (0 a 10): ");
            scanf("%f", &nota);

            if (nota < 0 || nota > 10) {
                printf("Nota invalida. Deve estar entre 0 e 10\n");
                return;
            }

            usuarios[i].notas[usuarios[i].num_notas++] = nota;
            printf("Nota cadastrada com sucesso!\n");

            float soma = 0.0;
            for (int j = 0; j < usuarios[i].num_notas; j++) {
                soma += usuarios[i].notas[j];
            }

            if (usuarios[i].num_notas > 0) {
                usuarios[i].media = soma / MAX_NOTAS;
            }

            salvarDados();
            return;
        }
    }
    printf("Aluno nao encontrado\n");
}

/**
 * @brief Exibe as notas e a média de um aluno.
 *
 * Permite que alunos visualizem suas notas cadastradas e sua média geral.
 *
 * @param usuario O ponteiro para o aluno que está executando a função.
 *
 * @note Apenas alunos podem acessar esta função.
 * @warning A função falha se não houver notas cadastradas.
 */

void exibirNotas(Usuario* usuario) {
        if (usuario->tipo != ALUNO) {
            printf("Acesso negado. Apenas alunos podem exibir suas notas\n");
            return;
        }

        printf("Notas do Aluno:\n");
        for (int j = 0; j < usuario->num_notas; j++) {
            printf("Nota %d: %.2f\n", j + 1, usuario->notas[j]);
        }
        if (usuario->num_notas > 0) {
            printf("Media: %.2f\n", usuario->media);
        } else {
            printf("Nenhuma nota cadastrada\n");
        }
}

/**
 * @brief Edita as informações de um usuário (aluno ou professor).
 *
 * Permite que administradores editem informações de usuários no sistema com base no RA (para alunos)
 * ou e-mail (para professores). É possível atualizar nome, e-mail e senha, mantendo os valores antigos 
 * caso o usuário não forneça novos valores. Também verifica se um e-mail já está em uso antes de atualizá-lo.
 *
 * @param usuario Ponteiro para o administrador que está executando a edição.
 *
 * @note Apenas administradores têm permissão para executar esta função.
 * @warning A edição não será realizada se o RA ou e-mail fornecido não existir no sistema.
 * @warning Se o e-mail fornecido já estiver cadastrado para outro usuário, ele não será alterado.
 *
 * @details 
 * - Para editar um aluno, forneça seu RA.
 * - Para editar um professor, forneça seu e-mail.
 * - Para manter o valor antigo de qualquer campo, pressione "Enter" sem digitar um novo valor.
 *
 * @return Nada.
 */

void editarUsuario(Usuario* usuario) {
    if (usuario->tipo != ADMINISTRADOR) {
        printf("Acesso negado. Apenas administradores podem editar usuarios.\n");
        return;
    }

    char busca[MAX_EMAIL];
    printf("Digite o RA do aluno ou o e-mail do professor que deseja editar: ");
    fflush(stdin);
    scanf(" %[^\n]", busca); 

    int encontrado = 0; //Indicação Se foi encontrado o usuário

     // Tenta buscar pelo RA (para alunos)
    int ra = busca; // Tenta converter a entrada para inteiro
    for (int i = 0; i < num_usuarios; i++) {
        if (usuarios[i].ra == ra && usuarios[i].tipo == ALUNO) {
            encontrado = 1; // Aluno encontrado
            printf("Editando aluno: %s\n", usuarios[i].nome);

            // Edita o nome
            printf("\nDigite o novo nome do aluno (ou pressione Enter para manter o mesmo): ");
            char novo_nome[MAX_NOME];
            fflush(stdin);
            fgets(novo_nome, sizeof(novo_nome), stdin); //Só com fgets que funciona para manter o mesmo
            novo_nome[strcspn(novo_nome, "\n")] = 0; // Remover /n

            if (strlen(novo_nome) > 1) { //Verifica se foi digitado algo para realizar a mudança
                strcpy(usuarios[i].nome, novo_nome);
            }

            // Edita o e-mail
            printf("\nDigite o novo e-mail do aluno (ou pressione Enter para manter o mesmo): ");
            char novo_email[MAX_EMAIL];
            fflush(stdin);
            fgets(novo_email, sizeof(novo_email), stdin);
            novo_nome[strcspn(novo_email, "\n")] = 0; // Remover /n
            if (strlen(novo_email) > 1) { //Verifica se foi digitado algo para realizar a mudança
               // Verificar se o novo e-mail já está cadastrado
                int emailExistente = 0;
                for (int j = 0; j < num_usuarios; j++) {
                    if (j != i && strcmp(usuarios[j].email, novo_email) == 0) {
                        emailExistente = 1; // E-mail já existe
                        break;
                    }
            }   //Caso o email não exista
                if (!emailExistente) {
                    strcpy(usuarios[i].email, novo_email);
                } else {
                    printf("\nO e-mail já está cadastrado. Mantendo o e-mail atual.\n");
                }
            }

            // Edita a senha
            printf("\nDigite a nova senha do aluno (ou pressione Enter para manter a mesma): ");
            char nova_senha[MAX_SENHA];
            fflush(stdin);
            fgets(nova_senha, sizeof(nova_senha), stdin);
            novo_nome[strcspn(nova_senha, "\n")] = 0; // Remover /n
            if (strlen(nova_senha) > 1) {
                strcpy(usuarios[i].senha, nova_senha);
            }
            printf("\nAluno editado com sucesso!\n");
            salvarDados();
            return;
        }
    }
    // Se não encontrou pelo RA, tenta buscar pelo e-mail (para professores)
    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].email, busca) == 0 && usuarios[i].tipo == PROFESSOR) {
            encontrado = 1; // Professor encontrado
            printf("Editando professor: %s\n", usuarios[i].nome);
            printf("\nDigite o novo nome do professor (ou pressione Enter para manter o mesmo): ");
            char novo_nome[MAX_NOME];
            fflush(stdin);
            fgets(novo_nome, sizeof(novo_nome), stdin);
             novo_nome[strcspn(novo_nome, "\n")] = 0; // Remover /n
            if (strlen(novo_nome) > 1) {
                strcpy(usuarios[i].nome, novo_nome);
            }

            //Editar o email
            printf("\nDigite o novo e-mail do professor (ou pressione Enter para manter o mesmo): ");
            char novo_email[MAX_EMAIL];
            fflush(stdin);
            fgets(novo_email, sizeof(novo_email), stdin);
            novo_nome[strcspn(novo_email, "\n")] = 0; // Remover /n
            if (strlen(novo_email) > 1) {
                // Verifica se o novo email já está cadastrado
                int emailExistente = 0;
                for (int j = 0; j < num_usuarios; j++) {
                    if (j != i && strcmp(usuarios[j].email, novo_email) == 0) {
                        emailExistente = 1; // Email já existe
                        break;
                    }
                }
                if (!emailExistente) {
                    strcpy(usuarios[i].email, novo_email);
                } else {
                    printf("\nO email ja esta cadastrado. Mantendo o email atual...\n");
                }
            }

            printf("\nDigite a nova senha do professor (ou pressione Enter para manter a mesma): ");
            char nova_senha[MAX_SENHA];
            fflush(stdin);
            fgets(nova_senha, sizeof(nova_senha), stdin);
            novo_nome[strcspn(nova_senha, "\n")] = 0; // Remover /n
            if (strlen(nova_senha) > 1) {
                strcpy(usuarios[i].senha, nova_senha);
            }

            printf("\nProfessor editado com sucesso!\n");
            salvarDados();
            return;
        }
    }

    if (!encontrado) {
        printf("\nUsuario com RA ou e-mail informado nao encontrado.\n");
    }
}           
