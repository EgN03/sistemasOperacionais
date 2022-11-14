Integrantes: <br>
Enrique Granado Novaes 32107803 <br>
Enzo Rocha Damato 32125992<br>
Gustavo Saad Andrade Maluhy 32173091<br>

Para Executar o código, execute os comandos a seguir:<br>
"gcc -pthread -o proj projeto2.c"<br>
"./proj {numero de threads desejadas}"<br>
o numero de threads pode ir de 0 a 100, e se deixado em branco, 100 threads serão executadas.

Para comprovar que o objetivo foi alcançado deve-se notar que a ordem que as threads são executadas muda cada vez que o programa é executado,
e as threads podem ou não ser finalizadas enquanto ainda há outras threads em execução.<br>
o valor final das contas será inconsiste ao fim de cada execução, pois os valores são aleatórios, porém o calculo pode ser feito com as informações
impressas no terminal, sendo indicado a conta que manda os valores e o valor a ser transferido.
