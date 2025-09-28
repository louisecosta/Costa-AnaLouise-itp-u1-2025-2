#include <stdio.h>
#include <stdbool.h>

// Constantes
#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_TEXTO 100  // Tamanho máximo para nomes, títulos, etc.
#define SENHA_DIGITOS 6
#define PRAZO_DIAS 14

// Arrays para livros
char titulos[MAX_LIVROS][MAX_TEXTO];
int anos[MAX_LIVROS];
char autores[MAX_LIVROS][MAX_TEXTO];
int codBarras[MAX_LIVROS];
int numSistema[MAX_LIVROS];
int numPaginas[MAX_LIVROS];
char localizacao[MAX_LIVROS][MAX_TEXTO];
char isbn[MAX_LIVROS][MAX_TEXTO];
int contadorLivros = 0;

// Arrays para usuários
char nomesUsuarios[MAX_USUARIOS][MAX_TEXTO];
int anosNascimento[MAX_USUARIOS];
char emails[MAX_USUARIOS][MAX_TEXTO];
int senhas[MAX_USUARIOS];
bool pendencias[MAX_USUARIOS];
int contadorUsuarios = 0;

// Status de empréstimo
bool emprestados[MAX_LIVROS];

// Nome do operador
char nomeOperador[MAX_TEXTO];

// Função para limpar buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para validar número
bool validarNumero(int valor, int min, int max) {
    return (valor >= min && valor <= max);
}

// Função para validar senha
bool validarSenha(int senha) {
    if (senha < 100000 || senha > 999999) return false;
    int temp = senha;
    int digitos = 0;
    while (temp > 0) {
        digitos++;
        temp /= 10;
    }
    return (digitos == SENHA_DIGITOS);
}

// Função auxiliar para comparar strings manualmente
bool compararStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return false;
        i++;
    }
    return (str1[i] == str2[i]);
}

// Cadastro de livro
void cadastrarLivro() {
    if (contadorLivros >= MAX_LIVROS) {
        printf("Erro: Acervo cheio!\n");
        return;
    }

    int id = contadorLivros;
    bool valido = true;

    printf("--- Cadastro de Livro ---\n");
    printf("Título: ");
    scanf("%s", titulos[id]);
    limparBuffer();

    printf("Ano de publicação (1900-2023): ");
    scanf("%d", &anos[id]);
    if (!validarNumero(anos[id], 1900, 2023)) {
        valido = false;
        printf("Erro: Ano inválido!\n");
    }

    printf("Autor: ");
    scanf("%s", autores[id]);
    limparBuffer();

    printf("Código de barras: ");
    scanf("%d", &codBarras[id]);
    if (codBarras[id] <= 0) {
        valido = false;
        printf("Erro: Código inválido!\n");
    }

    printf("Número de sistema: ");
    scanf("%d", &numSistema[id]);
    if (numSistema[id] <= 0) {
        valido = false;
        printf("Erro: Número inválido!\n");
    }

    printf("Número de páginas: ");
    scanf("%d", &numPaginas[id]);
    if (numPaginas[id] <= 0) {
        valido = false;
        printf("Erro: Páginas inválidas!\n");
    }

    printf("Localização: ");
    scanf("%s", localizacao[id]);
    limparBuffer();

    printf("ISBN: ");
    scanf("%s", isbn[id]);
    limparBuffer();

    // Verifica se faltam infos básicas
    if (!valido || titulos[id][0] == '\0' || autores[id][0] == '\0' || isbn[id][0] == '\0') {
        printf("Erro: Faltam informações do material a ser cadastrado.\n");
        // Opção de reiniciar
        int opcao;
        do {
            printf("1 - Reiniciar cadastro | 0 - Voltar ao menu\n");
            scanf("%d", &opcao);
            limparBuffer();
            if (opcao == 1) {
                cadastrarLivro();
                return;
            }
        } while (opcao != 0);
    } else {
        printf("Material cadastrado com sucesso!\n");
        printf("Título: %s | Ano: %d | Autor: %s | Cod. Barras: %d | ISBN: %s\n",
               titulos[id], anos[id], autores[id], codBarras[id], isbn[id]);
        contadorLivros++;
        emprestados[id] = false;
    }
}

// Cadastro de usuário
void cadastrarUsuario() {
    if (contadorUsuarios >= MAX_USUARIOS) {
        printf("Erro: Limite de usuários atingido!\n");
        return;
    }

    int id = contadorUsuarios;
    bool valido = true;

    printf("--- Cadastro de Usuário ---\n");
    printf("Nome: ");
    scanf("%s", nomesUsuarios[id]);
    limparBuffer();

    printf("Ano de nascimento (1900-2023): ");
    scanf("%d", &anosNascimento[id]);
    if (!validarNumero(anosNascimento[id], 1900, 2023)) {
        valido = false;
    }

    printf("Email: ");
    scanf("%s", emails[id]);
    limparBuffer();

    // Validação de senha
    int senha;
    do {
        printf("Senha (6 dígitos numéricos): ");
        scanf("%d", &senha);
        if (!validarSenha(senha)) {
            printf("Erro: Senha deve ter exatamente 6 dígitos numéricos.\n");
        }
    } while (!validarSenha(senha));
    senhas[id] = senha;
    pendencias[id] = false;

    if (!valido || nomesUsuarios[id][0] == '\0' || emails[id][0] == '\0') {
        printf("Erro: Faltam informações do usuário.\n");
        int opcao;
        do {
            printf("1 - Reiniciar | 0 - Voltar ao menu\n");
            scanf("%d", &opcao);
            limparBuffer();
            if (opcao == 1) {
                cadastrarUsuario();
                return;
            }
        } while (opcao != 0);
    } else {
        printf("Usuário cadastrado com sucesso!\n");
        contadorUsuarios++;
    }
}

// Consulta de livro 
void consultarLivro() {
    if (contadorLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int codBusca;
    printf("--- Consulta de Livro ---\n");
    printf("Código de barras: ");
    scanf("%d", &codBusca);
    limparBuffer();

    bool encontrado = false;
    for (int i = 0; i < contadorLivros; i++) {
        if (codBarras[i] == codBusca) {
            printf("Livro encontrado!\n");
            printf("Título: %s | Autor: %s | Ano: %d | Páginas: %d | Local: %s | ISBN: %s | Status: %s\n",
                   titulos[i], autores[i], anos[i], numPaginas[i], localizacao[i], isbn[i],
                   (emprestados[i] ? "Emprestado" : "Disponível"));
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro não encontrado.\n");
    }

    // Opção de continuar
    int opcao;
    do {
        printf("1 - Nova consulta | 0 - Voltar ao menu\n");
        scanf("%d", &opcao);
        limparBuffer();
        if (opcao == 1) {
            consultarLivro();
            return;
        }
    } while (opcao != 0);
}

// Empréstimo 
void emprestimo() {
    if (contadorUsuarios == 0 || contadorLivros == 0) {
        printf("Cadastre usuários e livros primeiro.\n");
        return;
    }

    char emailBusca[MAX_TEXTO];
    printf("--- Empréstimo de Livro ---\n");
    printf("Email do usuário: ");
    scanf("%s", emailBusca);
    limparBuffer();

    // Busca usuário (loop while + compararStrings)
    int idUsuario = -1;
    int i = 0;
    while (i < contadorUsuarios) {
        if (compararStrings(emailBusca, emails[i])) {
            idUsuario = i;
            break;
        }
        i++;
    }

    if (idUsuario == -1) {
        printf("Usuário não encontrado.\n");
        return;
    }

    if (pendencias[idUsuario]) {
        printf("%s está com multa/pendência.\n", nomesUsuarios[idUsuario]);
        return;
    }

    int codLivro;
    printf("Código de barras do livro: ");
    scanf("%d", &codLivro);
    limparBuffer();

    // Busca livro disponível
    int idLivro = -1;
    for (int j = 0; j < contadorLivros; j++) {
        if (codBarras[j] == codLivro && !emprestados[j]) {
            idLivro = j;
            break;
        }
    }

    if (idLivro == -1) {
        printf("Livro não encontrado ou já emprestado.\n");
        return;
    }

    // Verifica senha
    int senha;
    printf("Senha do usuário: ");
    scanf("%d", &senha);
    if (senha != senhas[idUsuario]) {
        printf("Senha inválida.\n");
        return;
    }

    // Sucesso
    emprestados[idLivro] = true;
    printf("Empréstimo para %s finalizado com sucesso!\n", nomesUsuarios[idUsuario]);
    printf("Prazo: %d dias para devolução.\n", PRAZO_DIAS);
}

// Função menu 
int menu() {
    int opcao;
    printf("\n--- Sistema de Biblioteca ---\n");
    printf("Operador: %s\n", nomeOperador);
    printf("1 - Cadastro de livros\n");
    printf("2 - Consultar informações do livro\n");
    printf("3 - Cadastro de usuário\n");
    printf("4 - Empréstimo de livro\n");
    printf("5 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    limparBuffer();

    // If/else para opções 
    if (opcao == 1) {
        cadastrarLivro();
    } else if (opcao == 2) {
        consultarLivro();
    } else if (opcao == 3) {
        cadastrarUsuario();
    } else if (opcao == 4) {
        emprestimo();
    } else if (opcao == 5) {
        printf("Saindo... Obrigado, %s!\n", nomeOperador);
        return 5;  // Retorna 5 para sinalizar saída
    } else {
        printf("Opção inválida! Tente novamente.\n");
        return menu();  // Recursão simples para repetir menu se inválido
    }

    return opcao;  // Retorna a opção (não 5, então continua no loop)
}

// Main 
int main() {
    // Inicializa arrays
    for (int i = 0; i < MAX_LIVROS; i++) {
        titulos[i][0] = '\0';
        emprestados[i] = false;
    }
    for (int i = 0; i < MAX_USUARIOS; i++) {
        nomesUsuarios[i][0] = '\0';
        pendencias[i] = false;
    }

    // Entrada do operador 
    printf("Bem-vindo ao Sistema de Biblioteca!\n");
    printf("Nome do operador: ");
    scanf("%s", nomeOperador);
    limparBuffer();

    // Loop principal
    int opcao;
    do {
        opcao = menu();
    } while (opcao != 5);

    return 0;
}
