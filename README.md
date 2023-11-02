LABORATÓRIO DE SISTEMAS OPERACIONAIS - PTHREADS PARTE 2

Bruno Roveri - 322310911
Lucas Farias - 32250193



 - Execução do código pela AWS (COM MUTEX)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/f2417244-362b-4637-9cca-077657e78c54)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/0cb7ebe9-8cde-4e44-84f5-7105f5fd5f70)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/323c452d-71b5-472a-a26e-e70df9999c27)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/ae43f98c-2edb-45ad-91a9-4b8da5bb0c9b)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/0dbd806d-3c8f-4d86-b33c-83363fddee59)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/4b0050de-034c-47ba-8fc9-72781a056685)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/14fce887-3a3b-4957-a8a5-fa476ba9588e)


 - Execução do código pela AWS (SEM MUTEX)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/ebeed97f-bea7-4733-b40a-e05907c8b043)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/c7456f43-24c1-4ed8-8df4-277fabeb6bd8)

![image](https://github.com/brunoroveri/LAB3PT2/assets/142548195/6f329111-63c9-4517-9bbb-539e7e1cca04)

(ERRO DESCONHECIDO, NÃO CONSEGUI IMPLEMENTAR PELO AWS O SEM MUTEX)


Compilação:
Use o gcc para compilar o código. Ele utiliza a biblioteca pthread para threads, então é necessário incluir a flag -lpthread:

gcc nome_do_arquivo.c -o nome_do_programa -lpthread


Execução:

Para executar o programa, basta especificar a rota para o arquivo a ser executado. Por exemplo:

./nome_do_arquivo


DIFERENÇA COM O USO DO MUTEX OU SEM MUTEX


Ao utilizar mutexes, é fundamental em situações que requerem consistência e prevenção de condições de corrida. Apesar de terem um overhead, eles asseguram que os programas operem de maneira estável e segura.

1. Gestão de Concorrência vs. Concorrência Desimpedida:
   - Com Mutex: A gestão de concorrência é estabelecida, e as threads aguardam a sua vez para acessar o recurso compartilhado.
   - Sem Mutex: As threads podem acessar recursos compartilhados a qualquer momento, aumentando a possibilidade de conflitos e condições de corrida.

2. Desempenho:
   - Com Mutex: Pode haver uma leve sobrecarga devido à espera pelo mutex e às operações de bloqueio e desbloqueio. No entanto, isso garante segurança na concorrência.
   - Sem Mutex: Em teoria, é mais rápido devido à ausência de bloqueios. No entanto, condições de corrida podem levar a resultados inconsistentes ou erros.

3. Previsibilidade:
   - Com Mutex: O comportamento é mais previsível, especialmente quando os mutexes são usados para garantir a ordem de execução, conforme visto no código fornecido.
   - Sem Mutex: O comportamento pode ser imprevisível e variar a cada execução devido a condições de corrida.

4. Complexidade:
   - Com Mutex: A implementação pode ser um pouco mais complexa, uma vez que é necessário gerenciar quando bloquear e desbloquear o mutex.
   - Sem Mutex: Menos complexidade na implementação, mas é essencial garantir que as threads não interfiram umas com as outras, o que pode ser desafiador em programas maiores ou mais complexos.
