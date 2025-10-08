# Introdução a Técnicas de Programação
* **Aluno**: Ana Louise Câmara da Costa
* **Matrícula**: 20250065261
* **Período**: 2025.2

## 📁 Estrutura do Projeto
- **projeto/:** Projeto principal da unidade
- **listas/:** Soluções das listas de exercícios
- **README.md:** Este arquivo

## 📚 Projeto: Sistema de Biblioteca
**Descrição**: Um sistema em C que permite ao operador gerenciar um acervo de biblioteca através de um menu interativo. O programa possibilita o cadastro de livros e usuários, consulta de informações pelo código de barras e a realização de empréstimos, verificando pendências e validade da senha do usuário. O desenvolvimento aplica os principais conceitos da Unidade 1, como condicionais, repetições, vetores e funções.

**Repositório**: https://github.com/louisecosta/Costa-AnaLouise-itp-u1-2025-2

**Vídeo de Demonstração**: https://www.youtube.com/watch?v=v4s7H6xJb2c

### Funcionalidades Implementadas:
- **Menu Interativo:** Permite ao operador navegar entre as diferentes opções do sistema.
- **Cadastro de Livros:** Registra dados como título, autor, ano de publicação, número de páginas, ISBN, localização e código de barras.
- **Cadastro de Usuários:** Registra nome, ano de nascimento, e-mail e senha numérica de 6 dígitos.
- **Consulta de Livros:** Busca por código de barras e exibe informações detalhadas, incluindo status (disponível ou emprestado).
- **Empréstimo de Livros:** Permite que um usuário solicite um empréstimo, validando senha, verificando pendências e a disponibilidade do livro.

### Conceitos da U1 Aplicados:
* **Estruturas condicionais:** Utilizadas para validar entradas e controlar o fluxo do sistema (ex.: ano válido, senha correta, disponibilidade de livro).
* **Estruturas de repetição:** Usadas em laços de busca em vetores (procurar livros/usuários) e no loop principal do menu.
* **Vetores:** Armazenam as informações de livros e usuários (títulos, autores, e-mails, senhas, pendências).
* **Funções:** O código foi modularizado em funções para cadastro, consulta e empréstimo, tornando o programa mais organizado. 

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

## 🎯 Principais Aprendizados
CEste projeto foi fundamental para solidificar a aplicação dos conceitos básicos de programação em C. Aprendi, em primeiro lugar, a importância da modularidade através do uso de funções. Dividir o sistema em blocos (cadastro de livro, consulta, empréstimo) tornou o código mais limpo, fácil de ler e, crucialmente, mais simples de corrigir erros.
O uso de condicionais (if/else) e laços de repetição (for/while) permitiu a criação de uma lógica de validação — por exemplo, garantindo a entrada correta de dados ou verificando se o livro está disponível para empréstimo. Por fim, a manipulação eficiente de um conjunto de dados (livros e usuários) foi garantida pelo uso estratégico de vetores.

## 💻 Ambiente de Desenvolvimento
* **SO**: Windows
* **Compilador**: GCC (via MinGW/MSYS2)
* **Editor**: Visual Studio Code