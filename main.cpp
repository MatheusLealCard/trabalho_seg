#include <iostream>
#include <stdio.h>
#include <string>

float depoisMedia = 0.0f;

class Aluno {
public:
    char nome[100];
    int idade;
    char sexo[100];
    float nota[100];
    bool aprovado;    
};

int main() {
    float mediaAprov;
    int qtdAlunos;
    class Aluno alunos[100];
    std::cout << "Digite a media de aprovacao da faculdade" << std::endl;
    std::cin >> mediaAprov;
    std::cout << "Digite a qtd de alunos" << std::endl;
    std::cin >> qtdAlunos;
    for (int i = 0; i < qtdAlunos; i++) {
        std::cout << "Digite o nome do "<< i + 1 << " Aluno" << std::endl;
        std::cin >> alunos[i].nome;
        std::cout << "Digite a idade do "<< i + 1 << " Aluno" << std::endl;
        std::cin >> alunos[i].idade;
        std::cout << "Digite o sexo do "<< i + 1 << " Aluno" << std::endl;
        std::cin >> alunos[i].sexo;
        
        for (int k = 0; k < 3; k++) {
            alunos[k].nota[k] = 0.0;
            printf("%d nota: ", k + 1);
            std::cin >> alunos[k].nota[k];
            //printf("nota %d: %f\n", k + 1, alunos[k].nota[k]);
        }
        system("clear");
        
        if (i == qtdAlunos - 1) {
            for (int j = 0; j < qtdAlunos; j++) {
                printf("Aluno: %d\n", j + 1);
                printf("\tNome: %s\n", alunos[j].nome);
                printf("\tIdade: %d\n", alunos[j].idade);
                printf("\tSexo: %s\n\n", alunos[j].sexo);
                printf("\tNotas: \n");
                for (int y = 0; y < 100; y++) {
                    printf("\t%d: %f\n", y + 1 ,alunos[y].nota[y]);
                    depoisMedia = depoisMedia + alunos[y].nota[y]; 
                    if (depoisMedia >= mediaAprov) {
                        alunos[y].aprovado = true;
                    } else {
                        alunos[y].aprovado = false;
                    }
                    if (y >= 100 -1) {
                        if (alunos[y].aprovado == 1) {
                            printf("\t\tStatus: passou");
                        } else {
                            printf("\tStatus: reprovou");
                        }
                    }
                }
                
            }
        }
    }
}
