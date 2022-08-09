#!/bin/bash

for i in 1 2 4 8
    do
        for j in {1..10}
            do
                echo "Rodando com tamanho de $i e $j threads ($j/10)"
                ./main.o 15000 p
            done
        for j in {1..10}
            do
                echo "Rodando com tamanho de $i ($j/10)"
                ./main.o 15000 s
            done
    done