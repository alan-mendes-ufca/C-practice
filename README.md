# C-practice

Solving basic questions about the C programming language - review for the exam.

---

# Aprendizados

## vetores

- **Declaração de arrays:**

  - **Array unidimensional (vetor):**

    ```c
      int vetor[5];                           // Tamanho fixo, valores não inicializados
      int vetor[5] = {1, 2, 3, 4, 5};        // Inicialização completa
      int vetor[] = {1, 2, 3, 4, 5};         // Tamanho inferido automaticamente (5)
      int vetor[5] = {1, 2};                 // Inicialização parcial, resto é 0
      int vetor[5] = {0};                    // Todos elementos inicializados com 0

      // VLA (Variable Length Array)
      int n = 10;
      int vetor[n];                          // Tamanho determinado em tempo de execução

      // Vetor dinâmico
      int _vetor = malloc(n _ sizeof(int));
      free(vetor); // Não esquecer de liberar!
    ```

  - Um array é decaído para um ponteiro que retorna o endereço do início da lista(`&arr[0]`).
  - Equivalência fundamental: `arr[i]  ≡  *(arr + i)` (O **operador de indexação**, por baixo dos panos aplica uma **aritmética de ponteiros** para retornar o índice indexado.)
  - Um array criado dentro de uma função é destruído, ele não pode ser retornado pois o local da mmemória que ele ocupa é apagado. Para solucionar esse problema temos algumas opções:
  - Alocar memória dinâmicamente com malloc (memory allocation) e retorna-lo.
  - utilizar uma função do tipo `void` para preencher um arr que está fora do escopo da função.

---

## Seleção da centena, dezena e unidade de um número:

```c
char centena = ((sum/100) % mod 10) + '0';
char dezena = ((sum/10) % mod 10) + '0';
char unidadae = (sum%10) + '0';
```

---

## matrizes

- **Array bidimensional (matriz):**

  ```c
  int matriz[3][4]; // 3 linhas, 4 colunas, valores não inicializados

  // Inicialização completa
  int matriz[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
  };

  // Inicialização simplificada (sequencial)
  int matriz[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

  // Primeira dimensão omitida (inferida automaticamente)
  int matriz[][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8}
  };  // Compilador infere 2 linhas

  // Inicialização parcial
  int matriz[3][4] = {{1}, {5}, {9}};    // Primeiro elemento de cada linha, resto é 0
  int matriz[3][4] = {0};                // Todos elementos inicializados com 0

  // VLA (Variable Length Array)
  int rows = 3, cols = 4;
  int matriz[rows][cols];                // Tamanho determinado em tempo de execução

  ```

- **Alocação dinâmica (HEAP):**

  ```c
  // Matriz dinâmica (ponteiro para ponteiro)
  int **matriz = malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
      matriz[i] = malloc(cols * sizeof(int));
  }

  // Liberar memória - um pouco mais complicado pois é preciso percorrer os endereços dos arrays
  for (int i = 0; i < rows; i++) {
      free(matriz[i]);
  }
  free(matriz);

  // Matriz dinâmica contígua (alternativa)
  int (*matriz)[cols] = malloc(rows * sizeof(*matriz));
  free(matriz);  // Libera tudo de uma vez
  ```

- Existem algumas formas de indicar que uma função receberá uma matriz como parâmetro, ainda podendo ser separadas em tipos:

  - **Alocação dinâmica na HEAP:**

    - `int **m` (ponteiro para ponteiro)
    - Exemplo: `void func(int **m, int rows, int cols)`

  - **VLAs (Variable Length Array), tamanho determinado em tempo de execução:**

    - `int (*m)[cols]` (ponteiro para array)
    - `int m[][cols]` (array bidimensional com primeira dimensão omitida)
    - Exemplo: `void func(int rows, int cols, int (*m)[cols])`

  - **Array de tamanho fixo (conhecido em tempo de compilação):**
    - `int m[ROWS][COLS]` (ambas dimensões definidas por constantes `#define ROWS 5`)
    - Exemplo: `void func(int m[10][20])`

- **Aritmética de ponteiros em matrizes:**

  - Expressão equivalente a `m[i][j]`: **`*(*(m + i) + j)`**

    - `(m + i)` → ponteiro para a linha (array) `i`
    - `*(m + i)` → desreferencia e retorna um ponteiro para o início da linha `i`
    - `(*(m + i) + j)` → avança `j` posições na linha `i`
    - `*(*(m + i) + j)` → desreferencia e retorna o valor do elemento `[i][j]`

  - **Armazenamento na memória:**
    - **Arrays estáticos e VLAs**: armazenados de forma **contígua** (sequencial) na memória, linha por linha (row-major order)

  ```c
  int matriz[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  // Na memória:
  // [1][2][3][4][5][6][7][8][9][10][11][12]
  //  ↑ linha 0  ↑ linha 1  ↑ linha 2
  ```

  - **Alocação dinâmica (`int **m`)**: cada linha pode estar em locais **diferentes\*\* da memória (não contígua)

  ```c
  int **m = malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
      m[i] = malloc(cols * sizeof(int)); // Cada linha em local diferente!
  }

  // A aritmética *(*(m + i) + j) ainda funciona, mas a memória NÃO é contígua
  ```

  - **Importante**: A forma contígua (arrays estáticos/VLAs) é mais eficiente para cache e performance!

---

## DÚVIDA: Qual a diferença entre `int **m` e `int (*m)[cols]` na passagem de matrizes para funções?

- `int **m` ponteiro para array de ponteiros, onde cada ponteiro aponta para uma linha da matriz. Usado para matrizes alocadas **dinamicamente** onde cada linha pode estar em locais diferentes na memória.

- `int (*m)[cols]` é um ponteiro para um array de colunas, usado para matrizes estáticas ou VLAs onde os dados são armazenados de forma **contínua** na memória.
  - `*((*m) + col)` (ponteiro para array): acessa o elemento `col` na linha contínua apontada por `m`.
  - `m[][col]` (array bidimensional com a primeira dimensão omitida) = `*((*m) + col)`, formas diferentes de criar matrizes, mas com a mesma aritmética, ou seja, iguais.

---

## Dúvida: Qual a diferênça entre VLA (Variable Length Array) e alocação dinâmica com malloc?

- VLA são arrays cujo tamanho é determinado em tempo de execução, mas são alocados na stack (pilha) e têm escopo limitado à função onde são declarados. Eles são automaticamente desalocados quando a função retorna.
- Alocação dinâmica com malloc aloca memória na heap (montão), que permanece alocada até que seja explicitamente liberada com free(), permitindo maior controle sobre o tempo de vida da memória.
  - O tamanho também é determinado em tempo de execução.

---

## Dúvida: Qual a diferença entre alocar um vetor ou matriz com `int* v = (int*)malloc(n * sizeof(int))` e `int *v = malloc(n*sizeof(int))`?

- Em C, o cast `(int*)` antes do `malloc` não é necessário, pois o `malloc` retorna um ponteiro do tipo `void*`, que é automaticamente convertido para qualquer outro tipo de ponteiro. Portanto, ambas as formas são corretas, mas a segunda forma (`int *v = malloc(n * sizeof(int))`) é preferida por ser mais limpa e evitar possíveis erros de conversão em C++.

---

## Dúvida: Como liberar a memória alocada dinamicamente para vetores e matrizes?

- Para vetores alocados com `malloc`, use `free(vetor);`.
- Para matrizes alocadas como ponteiro para ponteiro (`int **m`), libere cada linha primeiro e depois o ponteiro para as linhas:
  ```c
  for (int i = 0; i < rows; i++) {
      free(m[i]);
  }
  // Finalmente, libere o ponteiro para os ponteiros
  free(m);
  ```

---

## Novos comandos git aprendidos

- `git ls-files` : retorna os arquivos que o git está rastreando.
