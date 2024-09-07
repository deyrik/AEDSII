all: 
	clear
	gcc src/main.c src/lista/lista.h src/lista/lista.c src/hash/hash.h src/hash/hash.c  src/leitura/leitura.h src/leitura/leitura.c src/patricia/patricia.c src/patricia/patricia.h -o bin/exe -lm
	./bin/exe

alll:
	clear
	gcc -fno-pch src/main.c src/lista/lista.h src/lista/lista.c src/hash/hash.h src/hash/hash.c src/leitura/leitura.h src/leitura/leitura.c src/patricia/patricia.c src/patricia/patricia.h -o bin/exe -lm
	./bin/exe


compile: 
	gcc src/main.c src/lista/lista.c src/hash/hash.c src/patricia/patricia.c -o bin/exe -lm

run:
	./bin/exe

testeLista:
	gcc -g src/testes/teste_lista.c src/lista/lista.h src/lista/lista.c -o testelista -lm
	./testelista

testeHash:
	gcc -g src/testes/teste_hash.c src/lista/lista.h src/lista/lista.c src/hash/hash.h src/hash/hash.c -o testehash -lm
	./testehash

testeLeitura:
	gcc -g src/testes/teste_leitura.c src/lista/lista.h src/lista/lista.c src/hash/hash.h src/hash/hash.c  src/leitura/leitura.h src/leitura/leitura.c src/patricia/patricia.c src/patricia/patricia.h -o testeleitura -lm
	./testeleitura

testeUtil:
	gcc -g src/testes/teste_util.c  src/utilidades/utilidades.h src/utilidades/utilidades.c -o /utilExe
	./utilExe
