# Sistema de Alunos e Notas

**FATEC Arthur de Azevedo - Análise e Desenvolvimento de Sistemas - NOTURNO - 2° Semestre**

### Nomes:
- **José Gabriel Barbeta**
- **Rogério de Lima**
- **Kaique Carvalho**
- **Eduardo Toledo**

Este projeto é um **sistema de gerenciamento de alunos e notas** desenvolvido em C, que possibilita o cadastro, autenticação, listagem, e edição de usuários, além da gestão de notas. O sistema divide os usuários em três categorias: **Administrador**, **Professor** e **Aluno**, cada um com permissões específicas.

## Funcionalidades

1. **Cadastro de Usuário**
   - Permite cadastrar diferentes tipos de usuários: Administrador, Professor e Aluno.
   - Alunos recebem um **RA** (Registro Acadêmico) gerado automaticamente.
   - Dados solicitados incluem nome, e-mail e senha.

2. **Autenticação de Usuário**
   - Login de usuários através de e-mail e senha.
   - Exibição de menus personalizados dependendo do tipo de usuário.

3. **Menu de Usuário**
   - **Administrador**:
     - Cadastro de novos usuários.
     - Listagem de todos os alunos.
     - Cadastro e modificação de notas.
     - Edição de dados dos usuários.
   - **Professor**:
     - Listagem de todos os alunos.
     - Cadastro de notas.
   - **Aluno**:
     - Visualização de suas notas e média.

4. **Gerenciamento de Dados**
   - Dados dos usuários armazenados no arquivo `usuarios.txt`.
   - Carregamento automático dos dados ao iniciar o sistema, com salvamento ao sair.

## Como Utilizar

### Compilar o Programa

Certifique-se de possuir um compilador C (como GCC). Utilize o comando abaixo para compilar o programa:

```bash
gcc -o sistema sistema.c usuarios.c -lm
```

### Executar o Programa

Após a compilação, execute o programa com o comando:

```bash
./sistema
```

### Navegação no Menu

- Ao iniciar, o sistema apresenta um menu para cadastro ou autenticação.
- Usuários autenticados têm acesso a menus específicos conforme o tipo.
- Use os números correspondentes para selecionar opções e pressione **Enter**.

## Estrutura do Projeto

- **usuarios.h**: Definições de estruturas e constantes.
- **sistema.c**: Código principal com fluxo do sistema e menus.
- **usuarios.c**: Implementação das funções de gerenciamento de usuários.
- **usuarios.txt**: Banco de dados simples em texto para armazenamento de usuários.

## Requisitos

- **Compilador C** (GCC ou equivalente).
- Sistema operacional compatível com compilação e execução de programas em C.

## Exemplo de Uso

### Cadastro de um Novo Usuário
```plaintext
Menu:
1. Cadastrar Usuario
2. Autenticar Usuario
0. Sair
Opcao: 1

Digite o nome do usuario: João Silva
Digite o e-mail do usuario: joao.silva@example.com
Digite a senha do usuario: senha123
Digite o tipo de usuário (0 - Administrador, 1 - Professor, 2 - Aluno): 2
Usuario cadastrado com sucesso!
```

### Autenticação e Acesso
```plaintext
Menu:
1. Cadastrar Usuario
2. Autenticar Usuario
0. Sair
Opcao: 2

Digite o e-mail: joao.silva@example.com
Digite a senha: senha123
Bem-vindo, João Silva!

Menu de Usuario:
1. Exibir Notas
5. Sair
Opcao: 1

Notas do Aluno:
Nenhuma nota cadastrada.
```

## Observações

- Este projeto exemplifica manipulação de dados em C com leitura e escrita de arquivos de texto.
- Certifique-se de que o arquivo `usuarios.txt` esteja no diretório correto, ou altere o caminho no código-fonte.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir **issues** ou enviar **pull requests** para sugestões e melhorias.

## Licença

Este projeto é open-source e está licenciado sob a **Licença MIT**.
