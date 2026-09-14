# concessionaria_em_C

# 🚗 Sistema de Gerenciamento de Locadora em C

Aplicação em linha de comando desenvolvida em Linguagem C para gerenciamento de frota de veículos. O projeto foi elaborado como prática dos conceitos de **Algoritmos e Estruturas de Dados**.

---

## 📌 Funcionalidades

O sistema conta com um menu interativo no terminal e permite realizar as seguintes operações:

* **Cadastrar Veículo:** Registra a placa, marca, valor da diária e status de disponibilidade. O sistema realiza a inserção e mantém os veículos em **ordem alfabética pela placa**.
* **Exibir Veículos:** Lista todos os veículos cadastrados no sistema e seus respetivos status.
* **Buscar por Placa:** Pesquisa e exibe os dados detalhados de um veículo a partir de sua placa.
* **Alugar Veículo:** Altera o status do veículo para indisponível (impede a locação caso já esteja alugado).
* **Devolver Veículo:** Registra a devolução, tornando o veículo disponível novamente.
* **Remover Veículo:** Remove o registro do veículo e reorganiza os elementos no array para evitar posições vazias (a remoção é permitida apenas se o veículo estiver disponível).

---

## 🧠 Conceitos Aplicados

* **Estruturas de Dados (`struct`):** Modelagem do tipo `Veiculo` para representação dos dados.
* **Algoritmos de Ordenação e Busca:** Ordenação por strings e busca sequencial.
* **Manipulação de Strings (`string.h`):** Uso de `strcmp` para comparações e `strcpy` para cópia de dados.
* **Gerenciamento de Fluxo e Entradas:** Leitura limpa com `fgets`, controle via `switch/while` e manipulação do buffer de entrada (`getchar()`).

---

## 🚀 Como Executar

### Pré-requisitos
* Compilador C instalado (`gcc`, `clang` ou ambiente de sua preferência).

### Execução via Terminal

1. Clone o repositório:
   ```bash
   git clone [https://github.com/seu-usuario/concessionaria_em_C.git](https://github.com/seu-usuario/concessionaria_em_C.git)
   
Acesse o diretório do projeto:
cd concessionaria_em_C

Compile o código:
gcc concessionaria.c -o concessionaria

Execute o programa:
./concessionaria

📄 Licença
Projeto desenvolvido para fins estritamente acadêmicos e educacionais.
