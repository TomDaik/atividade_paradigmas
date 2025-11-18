package com.senai.sistemanotas;


import com.senai.sistemanotas.entidades.Aluno;
import com.senai.sistemanotas.entidades.CalculadoraNotas;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Aluno
 */
public class SistemaNotas {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o nome do aluno: ");
        String nome = sc.nextLine();

        System.out.print("Digite a matricula do aluno: ");
        String matricula = sc.nextLine();

        System.out.print("Digite a turma do aluno: ");
        String turma = sc.nextLine();

        System.out.print("Quantas notas deseja informar? ");
        int quantidade = sc.nextInt();

        List<Double> notas = new ArrayList<>();

        for (int i = 1; i <= quantidade; i++) {
            System.out.print("Digite a nota " + i + ": ");
            double nota = sc.nextDouble();
            notas.add(nota);
        }

        // Cria o aluno
        Aluno aluno = new Aluno(nome, matricula, turma, notas);

        System.out.println("\n===== RESULTADOS =====");
        System.out.println("Aluno: " + aluno.getNome());
        System.out.println("Matricula: " + aluno.getMatricula());
        System.out.println("Turma: " + aluno.getTurma());
        System.out.println("Notas: " + aluno.getNotas());

        System.out.printf("Media: %.2f%n", CalculadoraNotas.calcularMedia(notas));
        System.out.printf("Mediana: %.2f%n", CalculadoraNotas.calcularMediana(notas));
        System.out.printf("Desvio Padrao: %.2f%n", CalculadoraNotas.desvioPadrao(notas));

        sc.close();  
    }  
}
