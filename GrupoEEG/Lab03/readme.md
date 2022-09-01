<h1>Lab02b</h1>
Ex1 - Criação de Processos:

![image](https://user-images.githubusercontent.com/83346303/188031265-8f9cd717-fe54-4e79-b3a1-64902eb0c2a5.png)

<p>1)Rode o programa anterior para valores grandes de n. As
mensagens sempre estarão ordenadas pelo valor de i?</p>
<p>Sim! As mensagens sempre estarão ordernadas pelo valor de i. Por conta que ele vai criando os filhos na ordem da execução. </p>

![ex1SO](https://user-images.githubusercontent.com/83346303/187840569-a974f131-7262-4e48-924b-92f2fbde55f1.PNG)

<hr>
<p>2) O que acontece se o programa anterior escreve-se as mensagens para sys.stdout, usando print, ao invés de para sys.stderr?</p>
<p> O processo com o stdout mostra a saída padrão na inteface com o usuário. Enquanto o stderr mostra uma saída de erro.

![ex2SO](https://user-images.githubusercontent.com/83346303/187840630-cf04b02b-919f-421e-8e22-fc81f7ea3ffd.PNG)

<p>Para rodar os códigos em C no Linux basta colocar primeiro o comando gcc -o (NOME DO ARQUIVO PARA SAÍDA) (NOME DO ARQUIVO ORIGINAL .C) e depois colocar ./(SAÍDA) (NÚMERO DE PROCESSOS).</p> 
<b>Exemplo:</b>
<p>1 - gcc -o ex2 sys2.c</p>
<p>2 - ./ex2 5</p>
