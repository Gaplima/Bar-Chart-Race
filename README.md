# Bar Chart Race
 Project for the 'Programming Language I' subject, made in April 2021

Linguagem de Programação I - T01
Projeto de Programação #2

Aluno: Gabriel Alves Pinheiro Lima
Professor: Selan Rodrigues dos Santos

Comando de compilação: gpp -Wall main.cpp -o main
Comando de execução: ./main
Link do git: 

Bar Chart Race

   Este trabalho consiste de desenvolver em c++ um Bar Chart Race que o usuário seleciona qual a tabela deseja conferir e o programa exibe na tela uma animação a partir de dados pré-estabelecidos.
   O código foi feito inteiramente por mim, Gabriel Alves, utilizando de alguns conceitos aprendidos nos encontros do Zoom e/ou em disciplinas anteriores. Este código desenvolvido é composto de um arquivo main.cpp e um arquivo text_color.h (fornecido pelo professor) para auxiliar na identificação dos textos com diferentes cores. Além disso, há uma pasta com 2 arquivos .txt que são as duas opções de tabelas conectadas ao código. O arquivo principal consiste de  3 funções do tipo int que facilitaram a dinamizar o desenvolvimento do projeto.

   Algumas partes solicitadas no arquivo .pdf eu não consegui fazer por motivos como erro de compilação ou simplesmente por eu não saber como aplicá-las da maneira requisitada, são elas:
   -Ler e processar argumentos da linha de comando. Não consegui aplicar
   -Não consegui separar as categorias e portanto as barras estão numa cor só, pelo mesmo motivo o Bar Chart está sem legenda.

   Já outros detalhes do código foram feitos de maneira diferente da solicitada no .pdf do projeto, alguns para adaptar melhor ao resto do código, outros por serem dependentes das partes que eu não consegui fazer. Estes detalhes são:
   -Programa rodar com valores padrões, caso o usuário não insira estas informações na linha de comando. Como eu não consegui aplicar argumentos na linha de comando, o usuário é "forçado" a inserir valores para fps e quantidade desejada de linhas;
   -Ler o arquivo e salvar informação na memória. Único detalhe aqui é que eu fiz um menu numérico de opções para o usuário escolher qual arquivo (dos 2 pré-definidos) o programa irá ler;
   -Por enquanto o código apresenta apenas uma classe que contém o título do BCR, a medida de grandeza dos valores do BCR e a fonte de seus dados.
