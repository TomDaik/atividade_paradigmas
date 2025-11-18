package com.senai.sistemanotas.entidades;

import java.util.Collections;
import java.util.List;

/**
 *
 * @author Alexandre
 */
public class CalculadoraNotas {

    public static double calcularMedia(List<Double> notas) {
        double soma = 0;
        for (double n : notas) {
            soma += n;
        }
        return soma / notas.size();
    }

    public static double calcularMediana(List<Double> notas) {
        Collections.sort(notas);
        int meio = notas.size() / 2;

        if (notas.size() % 2 == 0) {
            return (notas.get(meio - 1) + notas.get(meio)) / 2.0;
        } else {
            return notas.get(meio);
        }
    }

    public static double desvioPadrao(List<Double> notas) {
        double media = calcularMedia(notas);
        double soma = 0;

        for (double n : notas) {
            soma += Math.pow(n - media, 2); // Subtrai cada nota da média e eleva ao quadrado.
        }

        return Math.sqrt(soma / notas.size()); // Soma todos os valores, divide pela quantidade de elementos, retorna a raiz quadrada
    }

    public static String getResultado(double media) {
        if (media >= 6.0) {
            return "Aprovado";
        } else if (media >= 5.0) {
            return "Recuperação";
        } else {
            return "Reprovado";
        }
    }
}
