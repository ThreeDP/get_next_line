<div align="center" >
  <img src="https://raw.githubusercontent.com/ThreeDP/ThreeDP/main/imgs/GNL.svg" alt="Get Next Line" width="175" height="175">
  <h1>Pega a próxima linha</h1>
</div>

[![norminette](https://github.com/ThreeDP/get_next_line/actions/workflows/norminette.yml/badge.svg)](https://github.com/ThreeDP/get_next_line/actions/workflows/norminette.yml)
[![madatory](https://github.com/ThreeDP/get_next_line/actions/workflows/mandatory.yml/badge.svg)](https://github.com/ThreeDP/get_next_line/actions/workflows/mandatory.yml)
[![bonus](https://github.com/ThreeDP/get_next_line/actions/workflows/bonus.yml/badge.svg)](https://github.com/ThreeDP/get_next_line/actions/workflows/bonus.yml)
[![tripouille](https://github.com/ThreeDP/get_next_line/actions/workflows/tripouille.yml/badge.svg)](https://github.com/ThreeDP/get_next_line/actions/workflows/tripouille.yml)

# Score
[![dapaulin's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl9hhx9hp00400gmjtv4jf33f/project/2829489)](https://github.com/JaeSeoKim/badge42)

# Sobre
> Ahhh a GNL! Esse projeto tem o objetivo de realizar a leitura de um arquivo e retornar uma linha por vez. Parece ser bem simples de inicio, porém manipular strings em C pode se um grande desafio, em python da pra fazer facilmente com 5 linhas! Porém não vamos nós prender nesse fatos, esse projeto cria uma visão muito diferente do processo de leitura de uma arquvivo, sinceramente após terminar consegui entender até o motivo de não conseguir ler todas as linhas de alguns arquivos utilizando python, claramente eu não estavam ultilizando a linguagem da maneira correta. Enfim esse foi uns dos projetos mais interessantes que fiz até o momneto durante a minha trajetória na 42 e espero que esse repósitorio te ajude de algum forma.

# Como utilizar
> Se tiver interesse em testar ou usar de alguma forma o que foi desenvolvido nesse repósitorio a seguir temos os passos para compilar seu código C com a GNL.

```bash
git clone git@github.com:ThreeDP/get_next_line.git
```

> Clone o repósitorio do github

```bash
cc <sua main> get_next_line.c get_next_line_utils.c
```

> Compile a main do seu projeto com os arquivos .c, não se esqueça de indicar o diretório onde está os arquivos da GNL, se você clonou direto desse repositório provavelmente o diretório será get_next_line e será necessário incluir isso na frente dos arquivos .c na compilação, será necessário incluir o header no seu arquivo main, você pode incluir adicionando #include "get_next_line/get_next_line.h, claro se você clonou o arquivo e não alterou o diretório.

# Desenvolvimento
> Durante esse projeto tive o interesse em utilizar listas encadeadas para fixar os conceitos e ir mais a fundo nesse conhecimento. A ideia central do código é criar nós com um char * do tamanhando BUFFER_SIZE enquanto não encontra um \n ou \0 e após isso juntar todas essa partes em uma unica string. Isso permitir diminuir o numero de vezes em que utilizamos o malloc para alocar e desalocar strings economizando processamento.

# TDD
> Mas uma vez tentei melhorar minha habilidades com TDD, esse foi um projeto que quase consegui cobrir tudo com teste, porém tive que alterar o escopo de algumas funções e isso me fez perder alguns testes, eu quase consegui ;(, porém ganhei muito conhecimento sobre TDD.
