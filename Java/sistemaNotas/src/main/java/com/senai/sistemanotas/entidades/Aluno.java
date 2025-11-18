package com.senai.sistemanotas.entidades;



import java.util.List;

/**
 *
 * @author Alexandre
 */
public class Aluno {
    
    private String nome;
    private String matricula;
    private String turma;
    private List <Double> notas;

    public Aluno(String nome, String matricula, String turma, List<Double> notas) {
        this.nome = nome;
        this.matricula = matricula;
        this.turma = turma;
        this.notas = notas;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getMatricula() {
        return matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getTurma() {
        return turma;
    }

    public void setTurma(String turma) {
        this.turma = turma;
    }

    public List<Double> getNotas() {
        return notas;
    }

    public void setNotas(List<Double> notas) {
        this.notas = notas;
    }
}
