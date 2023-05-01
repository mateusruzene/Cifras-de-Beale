## Aluno:

Nome: Mateus Siqueira Ruzene
GRR: 20221223

## Módulos usados:

- liblista:  
   Biblioteca de listas ligadas para fazer a manipulação dos números de posição de cada letra da cifra

- libchaves:  
   Bilbioteca de listas ligadas que faz a manipulação e criação das chaves do livro de cifras, e utiliza a liblista para listar todas as posições de cada chave da cifra

- libcifras:  
   Este módulo foi criado para fazer a manipulação e criação do arquivo + struct de chaves que é utilizado para codificar e decodificar

- libdecodifica:  
   Usa o módulo libcifras para decodificar um arquivo, utilizando como base tanto o livro cifra quanto o arquivo de chaves

- libcodifica:  
   Usa o módulo libcifras para codificar um arquivo, usando o livro cifra como base para criar o arquivo de chaves

- beale:  
   Este é o main, faz as verificações de qual ação está querendo fazer, como codificar ou decodificar
