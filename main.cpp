#include <iostream>
#include <string>

#define TOTAL_NOTAS_SIZE 3

#if defined(_WIN32)
    #define PRINT "cls"
#elif defined(__linux__)
    #define PRINT "clear"
#endif 

int total_alunos = 0;
int media_escola = 5;

class Aluno {
    public:
        std::string nome;
        int idade;
        std::string sexo;
        float notas[TOTAL_NOTAS_SIZE];
};

void get_alunos_data(Aluno &a);
float calcula_media(float *, int);
void list_alunos(Aluno &a);

int main() {
    std::cout << "Quantos alunos no total? " << std::endl;
    std::cin >> total_alunos;

    std::cout << "Qual a media da escola? " << std::endl;
    std::cin >> media_escola;

    system(PRINT);

    Aluno alunos[total_alunos];
    
    for (int i = 0; i < total_alunos; i++) {
        get_alunos_data(alunos[i]);
    }
   
    for (int i = 0; i < total_alunos; i++) {
        float nota_aluno = calcula_media(alunos[i].notas, TOTAL_NOTAS_SIZE);
        list_alunos(alunos[i]);
        std::cout << "Media do aluno: " << nota_aluno << std::endl; 
        if (nota_aluno < media_escola) {
            std::cout << "Status: Reprovado" << std::endl;
        } else {
            std::cout << "Status: Aprovado" << std::endl;
        }
    }

    std::cout << "----------------------------" << std::endl;
}

void get_alunos_data(Aluno &a) {
    int i = 0;
    std::cout << "Qual o nome do aluno? " << std::endl;
    std::cin >> a.nome;

    std::cout << "Qual a idade do " << a.nome << " ? " << std::endl;
    std::cin >> a.idade;
    
    std::cout << "Qual o sexo do " << a.nome << " ? " << std::endl;
    std::cin >> a.sexo;

    for (int j = 0; j < TOTAL_NOTAS_SIZE; j++) {
        std::cout << "Qual a " << j + 1 << " nota do " << a.nome << " ? " << std::endl;
        std::cin >> a.notas[j];
    }
    system(PRINT);
}

void list_alunos(Aluno &a) {
    std::cout << "----------------------------" << std::endl;
    std::cout << "Nome: " << a.nome << std::endl;
    std::cout << "Idade: " << a.idade << std::endl;
    std::cout << "Sexo: " << a.sexo << std::endl;
    
    //Printa notas
    //for (int j = 0; j < TOTAL_NOTAS_SIZE; j++) {
    //    //std::cout << nota[j] << std::endl;
    //    std::cout << "Nota " << j + 1 << ": " << a.notas[j] << std::endl;
    //}
}

float calcula_media(float *lista, int arr_size) {
    if (arr_size == 0) return 0.0f;
    float soma = 0.0f;

    for (int i = 0; i < arr_size; i++) {
        soma += lista[i];
    } 
    return soma / arr_size;
}
