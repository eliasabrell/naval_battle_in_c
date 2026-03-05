# 🚢 Batalha Naval - Nível Avançado

Este é um simulador de **Batalha Naval** desenvolvido em linguagem **C**. O projeto foi estruturado para demonstrar conceitos de manipulação de matrizes, posicionamento de navios, habilidades especiais e áreas de efeito. O jogo permite posicionar navios de diferentes orientações (horizontal, vertical e diagonal) e aplicar habilidades com áreas de efeito em cone, cruz e octaedro.

## 🚀 Funcionalidades

- **Posicionamento de Navios**: O programa permite a criação de navios em diferentes orientações no tabuleiro (horizontal, vertical e diagonal).
- **Habilidades Especiais**:

  - **Cone**: Área de efeito que se expande em forma de cone.
  - **Cruz**: Área de efeito em formato de cruz.
  - **Octaedro**: Área de efeito em formato de losango (octaedro).
- **Exibição do Tabuleiro**: O tabuleiro é exibido com:

  - `0` para água.
  - `3` para navios.
  - `5` para as áreas de efeito das habilidades.
- **Validação de Posicionamento**: O código verifica se os navios não se sobrepõem e se estão dentro dos limites do tabuleiro.

---

## 📊 Habilidades Especiais

### 1. **Cone**

- A habilidade afeta uma área em forma de cone, com o ponto de origem no topo e expandindo-se para a base.

### 2. **Cruz**

- A habilidade afeta uma área em forma de cruz, com o ponto de origem no centro.

### 3. **Octaedro**

- A habilidade afeta uma área com formato de octaedro, representando um losango quando visto de frente.

---

## 🛠️ Como Compilar e Executar

Certifique-se de ter um compilador C (como o `gcc`) instalado em sua máquina.

1. **Clone o repositório:**
[https://github.com/eliabrell/naval_battle_in_c.git](https://github.com/eliasabrell/naval_battle_in_c.git)

  ```bash
  git clone https://github.com/eliasabrell/naval_battle_in_c.git
  cd naval_battle_in_c
  ```

2. **Compile o programa:**

  ```bash
  gcc -o batalha_naval batalha_naval.c
  ```

3. **Execute o jogo:**

  ```bash
  ./batalha_naval
  ```

## 🎮 Exemplo de Uso

Ao iniciar o programa, o jogo exibirá o tabuleiro, com os navios posicionados e as habilidades aplicadas. A área afetada pelas habilidades será marcada com o valor `5`.

### Exemplo de Exibição do Tabuleiro

1. **Tabuleiro Inicial:**

  ```plaintext
  Tabuleiro Final:
   0  0  0  0  X  0  0  0  0  0 
   0  0  0  0  X  0  0  0  0  0 
   *  X  X  X  *  5  *  X  *  0 
   *  *  *  *  0  5  *  *  0  0 
   0  *  *  *  *  *  *  *  0  0 
   0  X  3  3  3  0  0  0  0  0 
   3  3  0  0  0  0  X  *  0  0 
   3  3  0  0  0  0  *  0  0  0 
   0  3  3  0  0  0  0  0  0  0 
   0  0  0  0  0  0  0  0  0  0
  ```

2. **Resultado de Aplicação das Habilidades**:

  O programa irá aplicar as habilidades **Cone**, **Cruz** e **Octaedro** no tabuleiro e sobrepor as áreas de efeito com o valor `5`.

---

## 📋 Estrutura do Código

1. **Inicialização do Tabuleiro**: O tabuleiro é uma matriz 10x10 onde cada célula é inicializada com `0` (representando água).
2. **Posicionamento dos Navios**: Os navios são posicionados nas coordenadas definidas no código, sem sobreposição.
3. **Geração das Habilidades Especiais**:

- **Cone**: Representa uma área que cresce à medida que desce.
- **Cruz**: Afeta todas as células ao redor do ponto central.
- **Octaedro**: Afeta uma área em formato de losango.

4. **Exibição do Tabuleiro**: O tabuleiro é exibido no console, com diferentes símbolos para indicar a água, navios e áreas afetadas pelas habilidades.

---

## 🎮 Exemplo de Saída do Jogo

Quando o jogo é executado, o programa posiciona os navios e aplica as habilidades. A saída pode ser visualizada como:

  ```plaintext
  Tabuleiro Final:
   0  0  0  0  X  0  0  0  0  0 
   0  0  0  0  X  0  0  0  0  0 
   *  X  X  X  *  5  *  X  *  0 
   *  *  *  *  0  5  *  *  0  0 
   0  *  *  *  *  *  *  *  0  0 
   0  X  3  3  3  0  0  0  0  0 
   3  3  0  0  0  0  X  *  0  0 
   3  3  0  0  0  0  *  0  0  0 
   0  3  3  0  0  0  0  0  0  0 
   0  0  0  0  0  0  0  0  0  0
  ```

---

### ✒️ Autor

[Elias Abreu](https://github.com/eliasabrell)

---
