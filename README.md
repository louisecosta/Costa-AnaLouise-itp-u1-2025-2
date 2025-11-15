# Introdução a Técnicas de Programação
* **Aluno**: Ana Louise Câmara da Costa
* **Matrícula**: 20250065261
* **Período**: 2025.2

## 📁 Estrutura do Projeto
- **projeto/:** Projeto principal da unidade
- **listas/:** Soluções das listas de exercícios
- **README.md:** Este arquivo

## 📚 Projeto: Sistema de Biblioteca
**Descrição**: Um sistema em C que permite ao operador gerenciar um acervo de biblioteca através de um menu interativo. O programa possibilita o cadastro de livros e usuários, consulta de informações e a realização de empréstimos, relatório de informações e status e validade da senha do usuário. O desenvolvimento so projeto foi feito de forma gradual e seguindo os conteúdos apresentados em aula.

**Repositório**: https://github.com/louisecosta/Costa-AnaLouise-itp-u1-2025-2

**Vídeo de Demonstração U1**: https://www.youtube.com/watch?v=v4s7H6xJb2c
**Vídeo de Demonstração U2**: https://www.youtube.com/watch?v=OPMTNso83Lg

### Funcionalidades Implementadas:
- **Menu Interativo:** Permite ao operador navegar entre as diferentes opções do sistema.
- **Cadastro de Livros:** Registra dados como título, autor, ano de publicação, número de páginas, ISBN, localização e código de barras.
- **Consulta de Livros:** Busca por código de barras e exibe informações detalhadas, incluindo status (disponível ou emprestado).
- **Buscar livro por titulo/Autor:** Buscar informações sobre um livro sabendo o nome do autor ou o titulo do livro.
- **Relatorio tabular de livros:** Relatorio de livros cadastrados, com suas informações e status de emprestimo.
- **Cadastro de Usuários:** Registra nome, ano de nascimento, e-mail e senha numérica de 6 dígitos.
- **Empréstimo de Livros:** Permite que um usuário solicite um empréstimo, validando senha, verificando pendências e a disponibilidade do livro.
- **Devolução de livros:** Permite a devolução de um livro que foi emprestado.

### Conceitos da U1 Aplicados:
* **Estruturas condicionais:** Utilizadas para validar entradas e controlar o fluxo do sistema (ex.: ano válido, senha correta, disponibilidade de livro).
* **Estruturas de repetição:** Usadas em laços de busca em vetores (procurar livros/usuários) e no loop principal do menu.
* **Vetores:** Armazenam as informações de livros e usuários (títulos, autores, e-mails, senhas, pendências).
* **Funções:** O código foi modularizado em funções para cadastro, consulta e empréstimo, tornando o programa mais organizado. 

### Conceitos da U2 Aplicados:
* **Strings e manipulação de texto:** Utilizadas para armazenar nomes, títulos, autores e e-mails.

* **Estruturas de repetição aninhadas:** Aplicadas principalmente na criação do relatório tabular de livros. Um loop externo percorre cada livro e um loop interno percorre as colunas da matriz, permitindo imprimir a tabela organizada com todos os campos de cada registro.

* **Matrizes (arrays bidimensionais):** Utilizadas na função de relatório de livros, onde é criada uma matriz relatório para armazenar título, autor, ano, páginas, local e status. Essa estrutura permite tabular e imprimir os dados de forma alinhada e organizada.

* **Ponteiros básicos:** Empregados na manipulação dos vetores dinâmicos de livros e usuários. Os ponteiros permitem acessar e modificar diretamente cada registro, além de serem usados em funções que recebem strings como argumento.

* **Alocação dinâmica de memória (malloc, realloc e free):** Implementada para permitir que a quantidade de livros e usuários cresça conforme necessário. O programa aloca memória inicial com malloc, dobra o tamanho dos vetores quando atingido o limite usando realloc, e libera toda a memória com free ao encerrar o sistema.

## 📝 Listas de Exercícios
As soluções para as listas de exercícios da Unidade 1 estão na pasta `listas/`.

### Semana 2 - Variáveis, Tipos e Operadores
* Problema 1: Calculadora de IMC
* Problema 2: Conversão de temperatura
* Problema 3: Cálculo de juros compostos
* Problema 4: Operações aritméticas básicas

### Semana 3 - Estruturas Condicionais
* Problema 1: Classificação de IMC
* Problema 2: Calculadora de energia elétrica
* Problema 3: Sistema de notas
* Problema 4: Pedra, papel, tesoura
* Problema 5: Calculadora de desconto progressivo
* Problema 6: Diagnóstico médico simples
* Problema 7: Sistema de equações do 2º grau
* Problema 8: Validador de triângulos

### Semana 4A - Repetições Simples
* Problema 1: Dobrando até não poder mais
* Problema 2: Salve o homem aranha
* Problema 3: Números colegas
* Problema 4: Jogo de dardos

### Semana 4B - Análise e Padrões
* Questões 1-4: Análise de código
* Questões 5-11: Implementações de padrões e problemas

### Semana 5 - Funções (Parte 1)
* Problema 1: Horários das rondas
* Problema 2: Primos triplos
* Problema 3: Pousando a sonda espacial

### Semana 6 - Vetores
* Problema 1: MEC Correção ENEM
* Problema 2: Álbum de figurinhas
* Problema 3: A construção da ponte
* Problema 4: Em busca do tesouro perdido

### Semana 7 - Strings
* Problema 1: Campo minado 1D
* Problema 2: Detecção de placas
* Problema 3: OpenMeet

### Semana 8 - Repetições aninhadas
* Problema 1: Estou com sorte (ou não)
* Problema 2: Os dias mais chuvosos
* Problema 3: Esse sim é piloto

### Semana 9 - Matrizes
* Problema 1: Campo Agrícola
* Problema 2: Sugestão de amigos
* Problema 3: Campeonato de empates
* Problema 4: Uma pechincha!

### Semana 10 - Ponteiros e Alocação dinâmica
* Problema 1: Soma de Vetores
* Problema 2: Ocorrências no vetor
* Problema 3: Sopa de letrinhas

## 🎯 Principais Aprendizados
* Unidade 1: Este projeto foi fundamental para solidificar a aplicação dos conceitos básicos de programação em C. Aprendi, em primeiro lugar, a importância da modularidade através do uso de funções. Dividir o sistema em blocos (cadastro de livro, consulta, empréstimo) tornou o código mais limpo, fácil de ler e, crucialmente, mais simples de corrigir erros.
O uso de condicionais (if/else) e laços de repetição (for/while) permitiu a criação de uma lógica de validação — por exemplo, garantindo a entrada correta de dados ou verificando se o livro está disponível para empréstimo. Por fim, a manipulação eficiente de um conjunto de dados (livros e usuários) foi garantida pelo uso estratégico de vetores.
* Unidade 2: A Unidade 2 representou um salto significativo na maturidade técnica do projeto. Os conceitos de ponteiros, alocação dinâmica e estruturas compostas trouxeram robustez e flexibilidade ao sistema, aproximando-o de aplicações reais.
Comparado à Unidade 1, o código passou de um modelo linear e fixo para uma arquitetura modular, expansível e orientada a dados.
O principal aprendizado foi entender como o gerenciamento manual de memória impacta diretamente a estabilidade do programa.


## 💻 Ambiente de Desenvolvimento
* **SO**: Windows
* **Compilador**: GCC (via MinGW/MSYS2)
* **Editor**: Visual Studio Code