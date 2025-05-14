# C-Terminal-Text-Editor

<p align = "center">
	<img src = "assets/logo.png" alt = "logotipo" width = "200"/>
</p>


## Descrição
Este projeto é um **editor de texto simples em linguagem C** feito no contexto da unidade curricular **Algoritmos Tipos Abstratos Dados**, do curso de **Engenharia Informática** do Instituto Politecnico de Setúbal.

O editor funciona em terminal e permite **carregar**, **editar**, **formatar**, **analisar e guardar ficheiros de texto.**A interação é feita através de uma linha de comandos, onde o utilizador insere instruções especificas para manipular o documento.

O sistema utiliza estrutura de dados abstratos (ADTs) como listas, pilhas,map, para gerir e processar o conteúdo textual.

Este projeto foca-se na aplicação prática de ADTs, modularidade de código e manipulação efeciente de memoria.


## 📷 Demostração



## 👥 Autores
- Rui Manuel Do Carmo Lagarto - 2024114784
- Donizete Francisco Có - 200221162
- Inês Colaço Palet - 201701984

## ⚙️ Requesitos
- Compilador `gcc`
- `make`
- `valgrind`
- `ncurses`
- Ambiente Linux

### 📥 Instalação de Dependências
- Ubuntu
	```bash
	sudo apt update
	sudo apt install libncurses5-dev libncursesw5-dev
	```

## Como usar / Executar
### 📦 Compilação
Modo Normal:
```bash 
make
```

Modo Debug:
```bash 
make debug
```


### 🧹 Limpeza
Remove o executável:
```bash 
make clean
```

### ▶️ Execução
Corre o editor:
```bash 
make run
```

Ou diretamente:
```bash 
./textEditor/prog
```


### 🧠 Verificar memory leaks
Para testar fugas de memória com o valgrind:
```bash 
make leak
```

## Funcionalidades
Ao todo, o editor implementa 14 comandos, organizado em 5 categorias:

### 🟦 Comandos Base
 - `LOAD`  Carrega um ficheiro de texto em memória.
 - `SAVE`  Guarda as alterações feitas ao ficheiro.
 - `CLOSE` Fecha o documento em edição.
 - `QUIT`  Termina o programa e liberta toda a memória.
 - `SHOW`  Exibe o conteudo do documento, parágrafo a parágrafo.

 ### 📝 Comandos de Edição
 - `REPLACEALL` Substitui todas as ocorrências de uma palavra.
 - `UNDO` Reverte a última alteração feita.

 ### 🖨️ Comandos de Impressão
 - `PRINTL` Imprime o conteúdo com alinhamento à esquerda e largura configuravel.
 - `PRINTC` Imprime o conteúdo com alinhamento ao centro.

 ### 📊 Comandos de Análise
  - `STATS`  Mostra estatísticas detalhadas do texto.
  - `MARKS`  Gera um histograma com a frequencia de pontuação.
  - `MATRIX` Cria uma matriz de coocorrência de palavras em parágrafos.
  - `TOPN` Apresenta as N palavras mais frequentes do texto.

 ### ℹ️ Comando de Ajuda
 - `HELP` Lista e descreve brevemente todos os comandos disponiveis.

## 📚 Referências
 - Linguagem C, Bruno Silva (e-book)

 - Tipos Abstratos de Dados - Linguagem C, Bruno Silva (e-book)

 - [ncurses](https://terminalroot.com.br/ncurses/)

