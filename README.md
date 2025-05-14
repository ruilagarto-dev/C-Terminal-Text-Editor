# C-Terminal-Text-Editor

<p align = "center">
	<img src = "assets/logo.png" alt = "logotipo" width = "200"/>
</p>


## Description
This project is a **simple text editor written in C** developed as part of the **Algorithms and Abstract Data Types** course, in the **Computer Engineering** program at the Polytechnic Institute of Setúbal.

The editor operates in the terminal and allows users to **load**, **edit**, **format**, **analyze**, and **save text files**. Interaction is done through a command-line interface, where the user inputs specific commands to manipulate the document.

The system utilizes abstract data structures (ADTs) such as lists, stacks, and maps to manage and process the text content.

This project focuses on the practical application of ADTs, code modularity, and efficient memory management.


## 📷 Demo



## 👥 Authors
- Rui Manuel Do Carmo Lagarto

## ⚙️ Requirements
- Compiler  `gcc`
- `make`
- `valgrind`
- `ncurses`
- Linux environment

### 📥 Dependencies Installation
- Ubuntu
	```bash
	sudo apt update
	sudo apt install libncurses5-dev libncursesw5-dev
	```

## How to Use / Run
### 📦 Compilation
Normal Mode:
```bash 
make
```

Debug Mode:
```bash 
make debug
```


### 🧹 Clean
Remove the executable:
```bash 
make clean
```

### ▶️ Run
Run the editor:
```bash 
make run
```

Or directly:
```bash 
./textEditor/prog
```


### 🧠 Check for Memory Leaks
To check for memory leaks with valgrind:
```bash 
make leak
```

## Features
The editor implements 14 commands, organized into 5 categories:

### 🟦 Base Commands
 - `LOAD`  Loads a text file into memory.
 - `SAVE`  Saves the changes made to the file.
 - `CLOSE` Closes the document being edited.
 - `QUIT`  Terminates the program and frees all memory.
 - `SHOW`  Displays the content of the document, paragraph by paragraph.

 ### 📝 Editing Commands

 - `REPLACEALL` Replaces all occurrences of a word.
 - `UNDO` Reverts the last change made.

 ### 🖨️ Printing Commands
 - `PRINTL` Prints the content left-aligned with configurable width.
 - `PRINTC` Prints the content centered.

 ### 📊 Analysis Commands
  - `STATS`  Displays detailed text statistics.
  - `MARKS`  Generates a histogram with punctuation frequency.
  - `MATRIX` Creates a word co-occurrence matrix across paragraphs.
  - `TOPN` Displays the N most frequent words in the text.

 ### ℹ️ Help Command
 - `HELP` Lists and briefly describes all available commands.

## 📚 References
 - Linguagem C, Bruno Silva (e-book)

 - Tipos Abstratos de Dados - Linguagem C, Bruno Silva (e-book)

 - [ncurses](https://terminalroot.com.br/ncurses/)




