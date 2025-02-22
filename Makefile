# Estrutura pronta do Professor Wagner Barros de OSA
##############################################################################
# Exemplo de makefile para um projeto em linguagem C++...
# Para simplificar, todos os arquivos estão em um mesmo diretório
##############################################################################
# Arquivo principal: main.cpp
##############################################################################
#                       Arquivos auxiliares do projeto
##############################################################################
# SimpleMemoryManager.cpp: depende de SimpleMemoryManager.h 
##############################################################################

# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN 	:= main
# objetos a serem gerados na compilação
OBJECTS := $(MAIN).o SimpleMemoryManager.o 
# (para C, pode-se usar o padrão ISO 2011 (c11) ou 2018 (c18), dependendo do seu compilador...
# usar -std=c98 no lugar do c++11, c++17, c++20, etc.. 

FLAGS 	:= -Wall -Wextra -std=c++17 -pedantic-errors


# habilitar a depuração
DEBUG :=  -g

# necessário apenas quando se incluir  a biblioteca <math.h> em algum arquivo fonte no projeto
MATH 	:= -lm

# definição do compilador: para C usar o gcc, por exemplo
CC		:= g++

# ajustando alguns parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
else
OUTPUTMAIN := $(MAIN).out
endif

# ponto de compilação principal
all: main.exe
	@echo Compiling 'all' complete!

# gerando o arquivo executavel
main.exe: $(OBJECTS)  
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)
	
# gerando o arquivo objeto da função principal... 
main.o: $(MAIN).cpp  SimpleMemoryManager.h 
	$(CC) $(FLAGS) -c $(MAIN).cpp
	
# gerando o arquivo objeto SimpleMemoryManager.o
SimpleMemoryManager.o: SimpleMemoryManager.cpp SimpleMemoryManager.h
	$(CC) $(FLAGS) -c SimpleMemoryManager.cpp

clean:
ifeq ($(OS), Windows_NT)
	del /Q *.o
	del /Q $(OUTPUTMAIN)
else
	rm -rf *.o
	rm -rf $(OUTPUTMAIN)
endif
	@echo Cleanup complete!!!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'all' complete!!!