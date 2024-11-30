# Sistema de Alunos e Notas

**FATEC Arthur de Azevedo - Análise e Desenvolvimento de Sistemas - NOTURNO - 2° Semestre**

---

### Equipe:
- **José Gabriel Barbeta**
- **Rogério de Lima**
- **Kaique Carvalho**
- **Eduardo Toledo**

Este projeto consiste em um **sistema de gerenciamento de alunos e notas** desenvolvido na linguagem C, com foco em manipulação de arquivos e estruturas de dados. Ele possibilita o cadastro, autenticação, listagem e edição de usuários, bem como o gerenciamento de notas. O sistema organiza os usuários em três categorias principais: **Administrador**, **Professor** e **Aluno**, cada qual com permissões específicas.

---

## Funcionalidades do Sistema

### 1. Cadastro de Usuário
- Inclusão de novos usuários com os seguintes tipos:
  - **Administrador**: gerencia usuários e notas.
  - **Professor**: gerencia notas de alunos.
  - **Aluno**: consulta suas próprias notas.
- Geração automática de um **RA (Registro Acadêmico)** para alunos.
- Informações requeridas:
  - Nome
  - E-mail
  - Senha
  - Tipo de usuário

### 2. Autenticação de Usuário
- Login seguro com e-mail e senha.
- Controle de acesso baseado no tipo de usuário.
- Apresentação de menus personalizados conforme permissões.

### 3. Menu Personalizado
#### **Administrador**
- Cadastrar novos usuários.
- Listar e consultar informações de alunos.
- Editar dados de usuários.
- Gerenciar notas (inclusão, edição e exclusão).

#### **Professor**
- Listar alunos vinculados.
- Cadastrar e editar notas dos alunos.

#### **Aluno**
- Consultar notas e médias de suas disciplinas.

### 4. Gerenciamento de Dados
- **Persistência**: os dados dos usuários são armazenados em um arquivo de texto (`usuarios.txt`), permitindo a reutilização após o fechamento do programa.
- Operações de leitura e escrita para:
  - Carregar os dados no início do programa.
  - Salvar automaticamente ao sair.

---

## Estrutura do Projeto

- **`main.c`**: arquivo principal contendo o fluxo do programa e a lógica de menus.
- **`usuarios.h`**: cabeçalho com definições de estruturas e protótipos.
- **`usuarios.txt`**: arquivo de texto para armazenamento dos dados.

---

## Requisitos do Sistema

- **Ambiente de desenvolvimento**:
  - Compilador C (como GCC).
  - Sistema operacional compatível com execução de programas em C (Windows, Linux ou macOS).
- **Recursos mínimos**:
  - Acesso a terminal ou prompt de comando.
  - Editor de texto para possíveis edições no código-fonte.

---

## Instruções de Uso

### 1. Compilação do Programa
Certifique-se de ter um compilador C instalado. Para compilar o programa, execute o seguinte comando no terminal:

```bash
gcc -o sistema main.c usuarios.c -lm
```

### 2. Execução do Programa
Após a compilação, inicie o sistema com o comando:

```bash
./sistema
```

### 3. Navegação
- O programa inicia com opções de cadastro e login.
- Após o login, menus específicos são exibidos de acordo com o tipo de usuário.
- Selecione opções digitando o número correspondente e pressionando **Enter**.

---

## Exemplo de Execução

### Cadastro de Usuário
```plaintext
Menu Principal:
1. Cadastrar Usuário
2. Autenticar Usuário
0. Sair
Opção: 1

Digite o nome do usuário: Ana Pereira
Digite o e-mail do usuário: ana.pereira@example.com
Digite a senha do usuário: senha123
Digite o tipo de usuário (0 - Administrador, 1 - Professor, 2 - Aluno): 2
Usuário cadastrado com sucesso! RA: 20240001
```

### Autenticação e Acesso ao Menu de Aluno
```plaintext
Menu Principal:
1. Cadastrar Usuário
2. Autenticar Usuário
0. Sair
Opção: 2

Digite o e-mail: ana.pereira@example.com
Digite a senha: senha123
Bem-vindo(a), Ana Pereira!

Menu do Aluno:
1. Consultar Notas
0. Sair
Opção: 1

Notas do Aluno:
- Matemática: 8.5
- Português: 7.0
Média Final: 7.75
```

---

## Observações Importantes

1. **Segurança dos Dados**:
   - As senhas dos usuários são armazenadas de forma simples no arquivo de texto.
   - Para maior segurança, recomenda-se implementar uma função de hash para criptografia de senhas.

2. **Gerenciamento de Arquivos**:
   - O arquivo `usuarios.txt` deve estar no diretório C:
   - Caso contrário, o caminho precisa ser ajustado no código-fonte.

---

## Contribuições
Contribuições são bem-vindas! Sugestões e melhorias podem ser feitas via **issues** ou **pull requests** no repositório do projeto.

---

## Licença
Este projeto é open-source e está licenciado sob a **Licença MIT**. Consulte o arquivo `LICENSE` para mais informações. 
