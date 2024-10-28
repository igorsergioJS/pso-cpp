# Algoritmo de Otimização por Enxame de Partículas (PSO)

Este projeto implementa o algoritmo de **Otimização por Enxame de Partículas (PSO)** em C++ para otimizar uma função objetivo específica. O PSO é um método de otimização baseado em populações, onde partículas representam soluções e ajustam suas posições com base em sua experiência e na experiência global do enxame.

## Descrição do Algoritmo
O algoritmo inicia criando partículas com posições e velocidades aleatórias dentro de um espaço delimitado. Em cada iteração, as partículas atualizam suas velocidades e posições considerando três componentes:

1. **Inércia**: Mantém a partícula em seu movimento atual.
2. **Componente Cognitivo**: Permite que a partícula se mova em direção ao seu melhor resultado pessoal (experiência própria).
3. **Componente Social**: Permite que a partícula se mova em direção ao melhor resultado global encontrado por todo o enxame (influência do grupo).

O objetivo do PSO é minimizar a função objetivo, ajustando as posições das partículas até que o enxame se aproxime da posição ótima.

## Parâmetros Ajustáveis

Abaixo estão os parâmetros principais do PSO e uma breve explicação sobre como cada um afeta o comportamento do algoritmo:

- **`num_particles`** (Número de Partículas): Quantidade de partículas no enxame. Um valor maior aumenta a precisão da busca, mas também o custo computacional. Valores comuns variam entre 10 e 1000, dependendo da complexidade do problema.
  
- **`num_iterations`** (Número de Iterações): Número de ciclos de ajuste de posição das partículas. Mais iterações permitem uma busca mais detalhada, mas aumentam o tempo de execução.

- **`bounds`** (Limites de Busca): Define o espaço de busca para cada dimensão (neste caso, `x` e `y`). Esse parâmetro limita onde as partículas podem se mover.

- **`inertia`** (Inércia): Fator que mantém a partícula em seu movimento atual. Um valor alto (por exemplo, `0.7`) tende a manter as partículas se movendo, enquanto um valor baixo (`0.3`) faz com que as partículas mudem de direção mais rapidamente.

- **`cognitive`** (Componente Cognitivo): Peso que determina a influência da experiência individual da partícula em sua direção. Um valor alto aumenta a exploração baseada no histórico individual.

- **`social`** (Componente Social): Peso que determina a influência da melhor experiência do enxame sobre a partícula. Um valor alto faz com que o enxame se concentre rapidamente na área da melhor solução global conhecida.

## Instruções para Execução

Para compilar e executar o código em um ambiente de desenvolvimento C++, siga os passos abaixo:

1. **Compilação**: Utilize um compilador de C++, como `g++`. Execute:
   ```bash
   g++ -o pso pso.cpp


2. **Execução**: Após compilar, execute o programa:
      ```bash
   ./pso


## Exemplo de Saída
  ```bash
  Best Position: (x, y)
  Best Score (w15): valor_otimizado
