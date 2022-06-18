# LineGame
Este jogo foi elaborado para da disciplina Estrutura de Dados de 2018, do curso de ciência da computação UNIOESTE Cascavel-PR. 

O jogo proposto consiste em formar uma matriz bidimensional m x n. As posições da matriz podem assumir dois estados. O primeiro, representado pelos pontos brancos na Figura 1, correspondem às posições a serem preenchidas. Já o segundo estado representa as posições de início ou término de uma linha (células coloridas e numeradas).
Na imagem exibida a seguir, pode-se verificar a presença de valores numerados de um a sete. Cada valor é duplicado. A ideia é que os dois valores sejam ligados por uma única linha que não seja sobreposta por nenhuma outra linha. Ou seja, uma posição x,y só pode ser ocupada por uma linha ou elemento numerado.

![alt text](https://github.com/VictorPozzan/LineGame/blob/master/images/image-1.jpg?raw=true)

Figura 1. Exemplo de matriz inicial para o jogo Linhas.

Na Figura 2, abaixo, são apresentadas as ligações entre as duas posições com valor 2 e as duas posições com valor 6. Cada ponto marcado com um valor pode ser tanto inicial como final, ou seja, uma linda pode, por exemplo, sair da posição [1,4] até a posição [2,9] ou pode ser traçada no sentido contrário.
A decisão de onde a linha tem início e onde termina, bem como o caminho que ela fará fica a encargo do jogador e não do programador.

![alt text](https://github.com/VictorPozzan/LineGame/blob/master/images/image-2.jpg?raw=true)

Figura 2. Exemplo de conexão entre os pares de pontos.

O processo de ligação entre as posições numeradas é realizado para cada um dos pares presentes na matriz, conforme apresentado nas Figuras 3 e 4. No caso da figura 4, pode-se ver que todos os pares numerados são conectados.
O objetivo do jogo é conectar todos os pares de posições numerados e, ao mesmo tempo, passar por todas as posições marcadas com pontos brancos, conforme mostrado na Figura 4. O resultado alcançado com sucesso é visto na Figura 5, em que todos os elementos da matriz foram “visitados” e nenhuma linha cruzou com outra.

![alt text](https://github.com/VictorPozzan/LineGame/blob/master/images/image-3.jpg?raw=true)

Figura 3. Linhas conectando um conjunto maior de pontos.

![alt text](https://github.com/VictorPozzan/LineGame/blob/master/images/image-4.jpg?raw=true)

Figura 4. Ligações entre praticamente todos os pares.

Caso o jogador escolha caminhos que conectem todos os pares de nós sem que todas as posições da matriz sejam preenchidas, o jogo continua. Algum dos caminhos poderá ser desfeito e refeito na tentativa de preencher todas as coordenadas.

O que deve ser implementado na solução do exercício:
a) A solução deve, obrigatoriamente, usar orientação a objetos. Para tanto, pode-se, por exemplo, se criar uma classe do tipo lista e outra do tipo nó.
b) Uma vez que cada conjunto de elementos ligados pode ser percorrido nos dois sentidos, a abordagem construída deve utilizar listas duplamente encadeadas.    
c) A implementação deve consultar o usuário sobre o tamanho da matriz a ser utilizada e permitir que o usuário determine cada um dos pontos de início e fim. Para tanto, deve-se construir um procedimento chamado ConstroiMatriz que receberá por parâmetro as
dimensões especificadas, fará a alocação dinâmica do espaço e fará a determinação das posições iniciais (informadas pelo usuário).

![alt text](https://github.com/VictorPozzan/LineGame/blob/master/images/image-5.jpg?raw=true)

Figura 5. Resultado concluído com sucesso.


Este procedimento deve questionar também quanto ao número de pares que se farão presentes na matriz (deve, obrigatoriamente haver pelo menos 1 par e na máximo (n x m)/2 pares. Tal verificação deve ser realizada.
d) Depois de preparada a matriz, o programa deve permitir ao usuário (através da função ConstroiCaminho) que ele selecione uma determinada célula para começar a traçar os percursos. Estas células necessariamente são elementos numerados e, portanto, deve-se fazer a verificação.
e) Assim que a posição iniciar for escolhida, o usuário vai informando a direção que o caminho deve seguir: cima, baixo, direita, esquerda. O programa deve então ir marcando o caminho e adicionando as posições à lista correspondente.
f) O processo de marcação deve fazer algumas verificações no momento em que o usuário informa uma posição:
    f.1) É uma posição válida? O usuário não está tentando ir para uma direção impossível? Por exemplo, ir para a coluna -1;
    f.2) O usuário não pode passar por uma posição preenchida com um valor que seja diferente do inicial. Por exemplo, ele começou pelo índice “3” na matriz. Durante o caminho, ele não poderá passar pela posição que contém o valor “2”, apenas pelo valor inicial. Para tanto, deve-se implementar a função ChecaPosicao;
    f.3) O usuário pode escolher um caminho que já foi usado por outra lista. Quando isso ocorrer, a lista anterior deve ser apagada pois espera-se que a solução informada agora seja a correta. Para tanto, deve-se implementar a função ChecaCaminho, que verifica se a posição escolhida se sobrepõe a um caminho anterior.
g) Deve ser implementada uma função ChecaFinal que verifica se todas as listas realmente conectam cada um dos pares de valores da matriz e deve checar também se todas as posições da matriz fazem parte de algum caminho. Caso as duas verificações sejam válidas, o programa deve exibir mensagem informando que o jogo foi concluído com sucesso.
