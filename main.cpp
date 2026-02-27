#include <iostream>
#include <string>

#define TOTAL_NOTAS_SIZE 3
int totalAlunos = 1;
float notasSoma = 0;
float mediaTotal;

class Aluno {
    public:
        std::string nome;
        int idade;
        std::string sexo;
        float notas[TOTAL_NOTAS_SIZE];
        float totalNotas;
        bool aprovado;
};

int main() {
    std::cout << "Quantos alunos no total? " << std::endl;
    std::cin >> totalAlunos;

    std::cout << "Qual a media da escola? " << std::endl;
    std::cin >> mediaTotal;

    system("clear");

    Aluno alunos[totalAlunos];

    for (int i = 0; i < totalAlunos; i++) {
        notasSoma = 0;
        std::cout << "Qual o nome do " << i + 1 << " aluno? " << std::endl;
        std::cin >> alunos[i].nome;

        std::cout << "Qual a idade do " << alunos[i].nome << " ? " << std::endl;
        std::cin >> alunos[i].idade;
        
        std::cout << "Qual o sexo do " << alunos[i].nome << " ? " << std::endl;
        std::cin >> alunos[i].sexo;

        for (int j = 0; j < TOTAL_NOTAS_SIZE; j++) {
            std::cout << "Qual a " << j + 1 << " nota do " << alunos[i].nome << " ? " << std::endl;
            std::cin >> alunos[i].notas[j];

            notasSoma += alunos[i].notas[j];
            alunos[i].totalNotas = notasSoma;
        }

        if (notasSoma > mediaTotal) {
            alunos[i].aprovado = true;
        } else {
            alunos[i].aprovado = false;
        }
        system("clear");
    }

    //print tudo
    for (int i = 0; i < totalAlunos; i++) {
        std::cout << "----------------------------" << std::endl;
        std::cout << "Nome: " << alunos[i].nome << std::endl;
        std::cout << "idade: " << alunos[i].idade << std::endl;
        std::cout << "sexo: " << alunos[i].sexo << std::endl;
        std::cout << "Total notas: " << alunos[i].totalNotas << std::endl; 
        
        //print notas
        //for (int j = 0; j < TOTAL_NOTAS_SIZE; j++) {
        //    std::cout << "\tNota " << j + 1 << ": " << alunos[i].notas[j] << std::endl;
        //}

        if (alunos[i].aprovado == 0) {
            std::cout << "status: Reprovado" << std::endl;
        } else {
            std::cout << "status: Aprovado" << std::endl;
        }
    }
    std::cout << "----------------------------" << std::endl;
}