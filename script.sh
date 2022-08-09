#!/bin/bash

for i in 2500 5000 7500 10000
    do
        for j in {1..10}
            do
                echo "Rodando com tamanho de $i ($j/10)"
                ./main.o $i p
            done
        for j in {1..10}
            do
                echo "Rodando com tamanho de $i ($j/10)"
                ./main.o $i s
            done
    done