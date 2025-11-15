#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constantes
#define MAX_TEXTO 100  // Tamanho maximo para nomes, titulos, etc.
#define SENHA_DIGITOS 6
#define PRAZO_DIAS 14
#define TAM_INICIAL 10  // Tamanho inicial para alocacao dinamica

// Estrutura para Livro
typedef struct {
    char titulo[MAX_TEXTO];
    int ano;
    char autor[MAX_TEXTO];
    int codBarras;
    int numSistema;
    int numPaginas;
    char localizacao[MAX_TEXTO];
    char isbn[MAX_TEXTO];
    bool emprestado;
    int diasEmprestado;  // Dias desde o emprestimo (simulado)
} Livro;

// Estrutura para Usuario
typedef struct {
    char nome[MAX_TEXTO];
    int anoNascimento;
    char email[MAX_TEXTO];
    int senha;
    bool pendencia;
} Usuario;

// Ponteiros para arrays dinamicos
Livro *livros = NULL;
Usuario *usuarios = NULL;
int contadorLivros = 0;
int capacidadeLivros = TAM_INICIAL;
int contadorUsuarios = 0;
int capacidadeUsuarios = TAM_INICIAL;

// Nome do operador
char nomeOperador[MAX_TEXTO];

// Funcao para limpar buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//2.2
// Funcao para ler string com fgets (robusta)
void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove o \n
}

// Funcao para validar numero
bool validarNumero(int valor, int min, int max) {
    return (valor >= min && valor <= max);
}

// Funcao para validar senha
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

// Funcao para realocar memoria se necessario
void realocarLivros() {
    capacidadeLivros *= 2;
    livros = (Livro *)realloc(livros, capacidadeLivros * sizeof(Livro));
    if (livros == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        exit(1);
    }
}

void realocarUsuarios() {
    capacidadeUsuarios *= 2;
    usuarios = (Usuario *)realloc(usuarios, capacidadeUsuarios * sizeof(Usuario));
    if (usuarios == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        exit(1);
    }
}
//5.3
// Cadastro de livro
void cadastrarLivro() {
    if (contadorLivros >= capacidadeLivros) {
        realocarLivros();
    }

    int id = contadorLivros;
    bool valido = true;

    printf("--- Cadastro de Livro ---\n");
    printf("Titulo: ");
    //5.4
    lerString(livros[id].titulo, MAX_TEXTO);

    printf("Ano de publicacao (1900-2023): ");
    scanf("%d", &livros[id].ano);
    limparBuffer();
    if (!validarNumero(livros[id].ano, 1900, 2023)) {
        valido = false;
        printf("Erro: Ano invalido!\n");
    }

    printf("Autor: ");
    lerString(livros[id].autor, MAX_TEXTO);

    printf("Codigo de barras: ");
    scanf("%d", &livros[id].codBarras);
    limparBuffer();
    if (livros[id].codBarras <= 0) {
        valido = false;
        printf("Erro: Codigo invalido!\n");
    }

    printf("Numero de sistema: ");
    scanf("%d", &livros[id].numSistema);
    limparBuffer();
    if (livros[id].numSistema <= 0) {
        valido = false;
        printf("Erro: Numero invalido!\n");
    }

    printf("Numero de paginas: ");
    scanf("%d", &livros[id].numPaginas);
    limparBuffer();
    if (livros[id].numPaginas <= 0) {
        valido = false;
        printf("Erro: Paginas invalidas!\n");
    }

    printf("Localizacao: ");
    lerString(livros[id].localizacao, MAX_TEXTO);

    printf("ISBN: ");
    lerString(livros[id].isbn, MAX_TEXTO);

    // Verifica se faltam infos basicas
    if (!valido || strlen(livros[id].titulo) == 0 || strlen(livros[id].autor) == 0 || strlen(livros[id].isbn) == 0) {
        printf("Erro: Faltam informacoes do material a ser cadastrado.\n");
        // Opcao de reiniciar
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
        printf("Titulo: %s | Ano: %d | Autor: %s | Cod. Barras: %d | ISBN: %s\n",
               livros[id].titulo, livros[id].ano, livros[id].autor, livros[id].codBarras, livros[id].isbn);
        livros[id].emprestado = false;
        livros[id].diasEmprestado = 0;
        contadorLivros++;
    }
}

// Cadastro de usuario
void cadastrarUsuario() {
    if (contadorUsuarios >= capacidadeUsuarios) {
        realocarUsuarios();
    }

    int id = contadorUsuarios;
    bool valido = true;

    printf("--- Cadastro de Usuario ---\n");
    printf("Nome: ");
    lerString(usuarios[id].nome, MAX_TEXTO);

    printf("Ano de nascimento (1900-2023): ");
    scanf("%d", &usuarios[id].anoNascimento);
    limparBuffer();
    if (!validarNumero(usuarios[id].anoNascimento, 1900, 2023)) {
        valido = false;
    }

    printf("Email: ");
    lerString(usuarios[id].email, MAX_TEXTO);

    // Validacao de senha
    int senha;
    do {
        printf("Senha (6 digitos numericos): ");
        scanf("%d", &senha);
        limparBuffer();
        if (!validarSenha(senha)) {
            printf("Erro: Senha deve ter exatamente 6 digitos numericos.\n");
        }
    } while (!validarSenha(senha));
    usuarios[id].senha = senha;
    usuarios[id].pendencia = false;

    if (!valido || strlen(usuarios[id].nome) == 0 || strlen(usuarios[id].email) == 0) {
        printf("Erro: Faltam informacoes do usuario.\n");
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
        printf("Usuario cadastrado com sucesso!\n");
        contadorUsuarios++;
    }
}

// Consulta de livro por codigo
void consultarLivro() {
    if (contadorLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int codBusca;
    printf("--- Consulta de Livro ---\n");
    printf("Codigo de barras: ");
    scanf("%d", &codBusca);
    limparBuffer();

    bool encontrado = false;
    for (int i = 0; i < contadorLivros; i++) {
        if (livros[i].codBarras == codBusca) {
            printf("Livro encontrado!\n");
            printf("Titulo: %s | Autor: %s | Ano: %d | Paginas: %d | Local: %s | ISBN: %s | Status: %s\n",
                   livros[i].titulo, livros[i].autor, livros[i].ano, livros[i].numPaginas, livros[i].localizacao, livros[i].isbn,
                   (livros[i].emprestado ? "Emprestado" : "Disponivel"));
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        printf("Livro nao encontrado.\n");
    }

    // Opcao de continuar
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

// Busca de livros por string (titulo ou autor)
void buscarLivroPorString() {
    if (contadorLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    char busca[MAX_TEXTO];
    printf("--- Busca de Livro por Titulo ou Autor ---\n");
    printf("Digite o termo de busca: ");
    lerString(busca, MAX_TEXTO);
//2.3
    bool encontrado = false;
    for (int i = 0; i < contadorLivros; i++) {
        if (strstr(livros[i].titulo, busca) != NULL || strstr(livros[i].autor, busca) != NULL) {
            printf("Livro encontrado!\n");
            printf("Titulo: %s | Autor: %s | Ano: %d | Paginas: %d | Local: %s | ISBN: %s | Status: %s\n",
                   livros[i].titulo, livros[i].autor, livros[i].ano, livros[i].numPaginas, livros[i].localizacao, livros[i].isbn,
                   (livros[i].emprestado ? "Emprestado" : "Disponivel"));
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("Nenhum livro encontrado com o termo '%s'.\n", busca);
    }
}

// Relatorio tabular de livros (usando matriz para tabular)
void relatorioLivros() {
    if (contadorLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
//4.1
    // Matriz para relatorio (linhas: livros, colunas: campos)
    char relatorio[contadorLivros][6][MAX_TEXTO];  // 6 colunas: Titulo, Autor, Ano, Paginas, Local, Status

    for (int i = 0; i < contadorLivros; i++) {
        strcpy(relatorio[i][0], livros[i].titulo);
        strcpy(relatorio[i][1], livros[i].autor);
        sprintf(relatorio[i][2], "%d", livros[i].ano);
        sprintf(relatorio[i][3], "%d", livros[i].numPaginas);
        strcpy(relatorio[i][4], livros[i].localizacao);
        strcpy(relatorio[i][5], livros[i].emprestado ? "Emprestado" : "Disponivel");
    }
//3.1
    // Imprimir tabela com loops aninhados
    printf("--- Relatorio de Livros ---\n");
    printf("%-30s %-20s %-4s %-7s %-15s %-10s\n", "Titulo", "Autor", "Ano", "Pags", "Local", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < contadorLivros; i++) {
        for (int j = 0; j < 6; j++) {
            if (j == 0) printf("%-30s ", relatorio[i][j]);
            else if (j == 1) printf("%-20s ", relatorio[i][j]);
            else if (j == 2) printf("%-4s ", relatorio[i][j]);
            else if (j == 3) printf("%-7s ", relatorio[i][j]);
            else if (j == 4) printf("%-15s ", relatorio[i][j]);
            else printf("%-10s ", relatorio[i][j]);
        }
        printf("\n");
    }
}

// Emprestimo
void emprestimo() {
    if (contadorUsuarios == 0 || contadorLivros == 0) {
        printf("Cadastre usuarios e livros primeiro.\n");
        return;
    }

    char emailBusca[MAX_TEXTO];
    printf("--- Emprestimo de Livro ---\n");
    printf("Email do usuario: ");
    lerString(emailBusca, MAX_TEXTO);
//2.1
    // Busca usuario
    int idUsuario = -1;
    for (int i = 0; i < contadorUsuarios; i++) {
        if (strcmp(emailBusca, usuarios[i].email) == 0) {
            idUsuario = i;
            break;
        }
    }

    if (idUsuario == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    if (usuarios[idUsuario].pendencia) {
        printf("%s esta com multa/pendencia.\n", usuarios[idUsuario].nome);
        return;
    }

    int codLivro;
    printf("Codigo de barras do livro: ");
    scanf("%d", &codLivro);
    limparBuffer();

    // Busca livro disponivel
    int idLivro = -1;
    for (int j = 0; j < contadorLivros; j++) {
        if (livros[j].codBarras == codLivro && !livros[j].emprestado) {
            idLivro = j;
            break;
        }
    }

    if (idLivro == -1) {
        printf("Livro nao encontrado ou ja emprestado.\n");
        return;
    }

    // Verifica senha
    int senha;
    printf("Senha do usuario: ");
    scanf("%d", &senha);
    limparBuffer();
    if (senha != usuarios[idUsuario].senha) {
        printf("Senha invalida.\n");
        return;
    }

    // Sucesso
    livros[idLivro].emprestado = true;
    livros[idLivro].diasEmprestado = 0;  // Reset dias
    printf("Emprestimo para %s finalizado com sucesso!\n", usuarios[idUsuario].nome);
    printf("Prazo: %d dias para devolucao.\n", PRAZO_DIAS);
}

// Devolucao com controle de penalidade
void devolucao() {
    if (contadorLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    int codLivro;
    printf("--- Devolucao de Livro ---\n");
    printf("Codigo de barras do livro: ");
    scanf("%d", &codLivro);
    limparBuffer();

    // Busca livro emprestado
    int idLivro = -1;
    for (int j = 0; j < contadorLivros; j++) {
        if (livros[j].codBarras == codLivro && livros[j].emprestado) {
            idLivro = j;
            break;
        }
    }

    if (idLivro == -1) {
        printf("Livro nao encontrado ou nao emprestado.\n");
        return;
    }

    // Simulacao: perguntar quantos dias passaram
    int diasPassados;
    printf("Quantos dias passaram desde o emprestimo? ");
    scanf("%d", &diasPassados);
    limparBuffer();

    livros[idLivro].emprestado = false;
    printf("Devolucao realizada com sucesso!\n");

    if (diasPassados > PRAZO_DIAS) {
        // Encontrar usuario (simplificado: assumir que sabemos o email, mas para simplicidade, marcar pendencia generica ou pedir email)
        // Para este exemplo, vamos assumir que precisamos do email do usuario para setar pendencia
        char emailBusca[MAX_TEXTO];
        printf("Email do usuario que devolveu: ");
        lerString(emailBusca, MAX_TEXTO);

        int idUsuario = -1;
        for (int i = 0; i < contadorUsuarios; i++) {
            if (strcmp(emailBusca, usuarios[i].email) == 0) {
                idUsuario = i;
                break;
            }
        }

        if (idUsuario != -1) {
            usuarios[idUsuario].pendencia = true;
            printf("Penalidade aplicada: Usuario %s tem pendencia devido ao atraso.\n", usuarios[idUsuario].nome);
        }
    }
}

// Funcao menu
int menu() {
    int opcao;
    printf("\n--- Sistema de Biblioteca ---\n");
    printf("Operador: %s\n", nomeOperador);
    printf("1 - Cadastro de livros\n");
    printf("2 - Consultar informacoes do livro\n");
    printf("3 - Buscar livro por titulo/autor\n");
    printf("4 - Relatorio tabular de livros\n");
    printf("5 - Cadastro de usuario\n");
    printf("6 - Emprestimo de livro\n");
    printf("7 - Devolucao de livro\n");
    printf("8 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    // If/else para opcoes
    if (opcao == 1) {
        cadastrarLivro();
    } else if (opcao == 2) {
        consultarLivro();
    } else if (opcao == 3) {
        buscarLivroPorString();
    } else if (opcao == 4) {
        relatorioLivros();
    } else if (opcao == 5) {
        cadastrarUsuario();
    } else if (opcao == 6) {
        emprestimo();
    } else if (opcao == 7) {
        devolucao();
    } else if (opcao == 8) {
        printf("Saindo... Obrigado, %s!\n", nomeOperador);
        return 8;  // Retorna 8 para sinalizar saida
    } else {
        printf("Opcao invalida! Tente novamente.\n");
        return menu();  // Recursao simples para repetir menu se invalido
    }

    return opcao;  // Retorna a opcao (nao 8, entao continua no loop)
}

// Main
int main() {
    // Alocacao inicial
    livros = (Livro *)malloc(TAM_INICIAL * sizeof(Livro));
    if (livros == NULL) {
        printf("Erro: Falha na alocacao inicial de livros!\n");
        return 1;
    }
    usuarios = (Usuario *)malloc(TAM_INICIAL * sizeof(Usuario));
    if (usuarios == NULL) {
        printf("Erro: Falha na alocacao inicial de usuarios!\n");
        free(livros);
        return 1;
    }
    // Entrada do operador
    printf("Bem-vindo ao Sistema de Biblioteca!\n");
    printf("Nome do operador: ");
    lerString(nomeOperador, MAX_TEXTO);
// Loop principal
    int opcao;
    do {
        opcao = menu();
    } while (opcao != 8);
    // Liberação de memória
    free(livros);
    free(usuarios);
    return 0;
}