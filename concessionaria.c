/*
3. Crie um programa para manipular os dados dos veículos de uma pequena locadora.
Para cada veículo, é preciso saber: placa (string), marca (string), valor da diária (float) e
disponibilidade (um inteiro ou char indicando se está disponível ou alugado). Crie uma
struct para representar o veículo e armazene-os em um array.
Em seguida, implemente funções para:

a) Ler os dados dos veículos e inseri-los no array, mantendo-o sempre ordenado
alfabeticamente placa (ou seja, cada novo veículo deve ser inserido na posição correta,
deslocando os demais se necessário, de forma que o array permaneça em ordem
alfabética de placa a cada inserção);

b) Exibir os dados de todos os veículos, indicando quais estão disponíveis para locação;

c) Buscar um veículo pela placa e exibir seus dados. A placa buscada deve ser passada
como parâmetro para a função;

d) Registrar a locação de um veículo (dada a placa), marcando-o como indisponível. A
função deve avisar caso o veículo já esteja alugado;

e) Registrar a devolução de um veículo (dada a placa), marcando-o como disponível
novamente;

f) Remover um veículo do array, dada a placa fornecida pelo usuário. A remoção só deve
ser realizada se o veículo estiver disponível (um veículo alugado não pode ser removido).
Ao remover, os elementos seguintes do array devem ser deslocados para manter a
ordenação por placa e não deixar "buracos";

Além disso, o programa deve apresentar um menu interativo (usando um while e um
switch, por exemplo), permitindo ao usuário escolher repetidamente entre as opções:
cadastrar veículo, exibir veículos, buscar por placar, alugar, devolver, remover veículo e
sair do programa. O menu deve continuar sendo exibido até que o usuário escolha a
opção de sair
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Veiculo{
    char placa[20], marca[20];
    float diaria;
    int disponibilidade;
}Veiculo;

void ordenar_alfabeticamente(Veiculo array_veiculos[100]){
    char placa_auxiliar[20], marca_auxiliar[20];
    float diaria_auxiliar;
    int disp_auxiliar;

    for(int i=0; array_veiculos[i].diaria != 0; i++){
        strcpy(placa_auxiliar, array_veiculos[i].placa);
        strcpy(marca_auxiliar, array_veiculos[i].marca);
        diaria_auxiliar = array_veiculos[i].diaria;
        disp_auxiliar = array_veiculos[i].disponibilidade;
        for(int j=i+1; array_veiculos[j].diaria != 0; j++){
            if(strcmp(placa_auxiliar, array_veiculos[j].placa) > 0){
                strcpy(array_veiculos[i].placa, array_veiculos[j].placa);
                strcpy(array_veiculos[j].placa, placa_auxiliar);

                strcpy(array_veiculos[i].marca, array_veiculos[j].marca);
                strcpy(array_veiculos[j].marca, marca_auxiliar);

                array_veiculos[i].diaria = array_veiculos[j].diaria;
                array_veiculos[j].diaria = diaria_auxiliar;

                array_veiculos[i].disponibilidade = array_veiculos[j].disponibilidade;
                array_veiculos[j].disponibilidade = disp_auxiliar;
            }
        }
    }
}

int buscar_placa(Veiculo array_veiculos[100], char placa[20]){
    int indice_veiculo;
    for(int i=0; array_veiculos[i].diaria != 0; i++){
        if(strcmp(array_veiculos[i].placa, placa) == 0){
            indice_veiculo = i;
            return indice_veiculo;
        }
    }
    return -1;
}

void imprimir_um_veiculo(Veiculo array_veiculos[100], char placa[20]){
    if(buscar_placa(array_veiculos, placa) != -1){
        if(array_veiculos[buscar_placa(array_veiculos, placa)].disponibilidade == 1){
            printf("\nVeículo encontrado.\nPlaca: %sMarca: %sDiária: R$%.2f\nDisponível para alugar\n\n", array_veiculos[buscar_placa(array_veiculos, placa)].placa, array_veiculos[buscar_placa(array_veiculos, placa)]. marca, array_veiculos[buscar_placa(array_veiculos, placa)].diaria);
        }else{
            printf("\nVeículo encontrado.\nPlaca: %sMarca: %sDiária: R$%.2f\nAlugado\n\n", array_veiculos[buscar_placa(array_veiculos, placa)].placa, array_veiculos[buscar_placa(array_veiculos, placa)]. marca, array_veiculos[buscar_placa(array_veiculos, placa)].diaria);
        }
    }else{
        printf("Não há um veículo com esta placa no sistema.\n");
    }
}

void ler_dados_veiculo(Veiculo array_veiculos[100]){
    Veiculo veiculo;
    printf("\n========ADICIONAR VEÍCULO========");
    printf("\nPlaca do carro: ");
    fgets(veiculo.placa, sizeof(veiculo.placa), stdin);
    if(buscar_placa(array_veiculos, veiculo.placa) == -1){
        printf("Marca do carro: ");
        fgets(veiculo.marca, sizeof(veiculo.marca), stdin);
        printf("Diária do carro: ");
        scanf("%f", &veiculo.diaria);
        printf("Disponibilidade(0-Alugado, 1-Disponível): ");
        scanf("%d", &veiculo.disponibilidade);

        for(int i=0; i<100; i++){
            if(array_veiculos[i].diaria == 0){
                strcpy(array_veiculos[i].placa, veiculo.placa);
                strcpy(array_veiculos[i].marca, veiculo.marca);
                array_veiculos[i].diaria = veiculo.diaria;
                array_veiculos[i].disponibilidade = veiculo.disponibilidade;
                break;
            }
        }

        ordenar_alfabeticamente(array_veiculos);
        printf("\nVeículo adicionado com sucesso.\n");
    }else{
        printf("Já existe um veículo com esta placa.");
    }    
}

void imprimir_veiculos(Veiculo array_veiculos[100]){
    printf("\n=====DADOS DOS VEÍCULOS=====\n");
    if(array_veiculos[0].diaria == 0){
        printf("A lista de veículos está vazia.\n");
        return;
    }else{
        for(int i=0; i<100; i++){
            if(array_veiculos[i].diaria == 0){
                return;
            }else{
                printf("VEÍCULO %d\n", i+1);
                if(array_veiculos[i].disponibilidade == 1){
                    printf("Placa: %sMarca: %sDiária: R$%.2f\nDisponível para alugar\n\n", array_veiculos[i].placa, array_veiculos[i]. marca, array_veiculos[i].diaria);
                }else{
                    printf("Placa: %sMarca: %sDiária: R$%.2f\nAlugado\n\n", array_veiculos[i].placa, array_veiculos[i]. marca, array_veiculos[i].diaria);
                }
            }   
        }
    }
}

void ler_placa(char placa[20], int tamanho){
    printf("Digite a placa: ");
    fgets(placa, tamanho, stdin);
    return;
}

void alugar_um_veiculo(Veiculo array_veiculos[100], char placa[20]){
    if(buscar_placa(array_veiculos, placa) == -1){
        printf("Não há um veículo com esta placa.\n");
        return;
    }else{
        if(array_veiculos[buscar_placa(array_veiculos, placa)].disponibilidade == 0){
            printf("Este veículo já está alugado.\n");
        }else{
            imprimir_um_veiculo(array_veiculos, placa);
            char confirmar;
            printf("Deseja alugar o carro?(S/N): ");
            scanf("%c", &confirmar);
            if(confirmar == 'S'){
                array_veiculos[buscar_placa(array_veiculos, placa)].disponibilidade = 0;
                printf("Veículo alugado com sucesso.\n");
            }else{
                return;
            }
        }
    }
}

void devolver_veiculo(Veiculo array_veiculos[100], char placa[20]){
    if(buscar_placa(array_veiculos, placa) == -1){
        printf("Não há um veículo com esta placa.\n");
        return;
    }else{
        if(array_veiculos[buscar_placa(array_veiculos, placa)].disponibilidade == 1){
            printf("Este veículo não está alugado.\n");
        }else{
            imprimir_um_veiculo(array_veiculos, placa);
            char confirmar;
            printf("Deseja devolver o carro?(S/N): ");
            scanf("%c", &confirmar);
            if(confirmar == 'S'){
                array_veiculos[buscar_placa(array_veiculos, placa)].disponibilidade = 1;
                printf("Veículo devolvido com sucesso.\n");
            }else{
                return;
            }
        }
    }
}

void remover_veiculo(Veiculo array_veiculos[100], char placa[20]){
    int indice_placa = buscar_placa(array_veiculos, placa);

    if(indice_placa == -1){
        printf("Não há um veículo com esta placa.\n");
        return;
    }else{
        if(array_veiculos[indice_placa].disponibilidade == 0){
            printf("Não é possível remover este veículo pois está alugado.\n");
        }else{
            imprimir_um_veiculo(array_veiculos, placa);
            char confirmar;
            printf("Deseja remover o carro?(S/N): ");
            scanf("%c", &confirmar);
            if(confirmar == 'S'){
                int indice;
                for(int i = indice_placa; array_veiculos[i+1].diaria != 0; i++){
                    strcpy(array_veiculos[i].placa, array_veiculos[i+1].placa);
                    strcpy(array_veiculos[i].marca, array_veiculos[i+1].marca);
                    array_veiculos[i].diaria = array_veiculos[i+1].diaria;
                    array_veiculos[i].disponibilidade = array_veiculos[i+1].disponibilidade;
                    indice = i+1;
                }
                strcpy(array_veiculos[indice].placa, "0");
                strcpy(array_veiculos[indice].marca, "0");
                array_veiculos[indice].diaria = 0;
                array_veiculos[indice].disponibilidade = 0;
                printf("Veículo removido com sucesso.\n");
            }else{
                return;
            }
        }
    }
}

void menu(Veiculo array_veiculos[100]){
    int opcao = 0;
    printf("============================\n       IFSP veículos");
    while(opcao != 7){
        printf("\n=======MENU PRINCIPAL=======\n1 - Cadastrar veículo\n2 - Exibir veículos\n3 - Busca por placa\n4 - Alugar veículo\n5 - Devolver veículo\n6 - Remover veículo\n7 - Sair do programa\nEscolha uma opção: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');
        char placa[20];
        switch(opcao){
            case 1:
            ler_dados_veiculo(array_veiculos);
            break;
        case 2:
            imprimir_veiculos(array_veiculos);
            break;
        case 3:
            ler_placa(placa, sizeof(placa));
            imprimir_um_veiculo(array_veiculos, placa);
            break;
        case 4:
            ler_placa(placa, sizeof(placa));
            alugar_um_veiculo(array_veiculos, placa);
            break;
        case 5:
            ler_placa(placa, sizeof(placa));
            devolver_veiculo(array_veiculos, placa);
            break;
        case 6:
            ler_placa(placa, sizeof(placa));
            remover_veiculo(array_veiculos, placa);
            break;
        case 7:
            printf("\nSaindo do programa...");
            break;
        default:
            printf("Insira uma opção válida.");
            break;
       }
    }
}

int main(){
    Veiculo veiculos[100] = {0};
    menu(veiculos);
}