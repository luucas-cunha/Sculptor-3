# Escultor 3D

<p align="justify">
Trata-se de uma ferramenta desenvolvida em C++ que tem como objetivo permitir que o usuário tenha acesso a formas geométricas simples e possa utilizá-las para criar suas próprias esculturas tridimensionais, que poderão ser salvas em arquivos no formato .OFF e acessadas posteriormente. Para utilizar a ferramenta em seu computador, é necessário abrir o arquivo <b>plotter.cpp</b>, ir até o slot chamado <b>saveFile</b> e alterar o caminho onde o arquivo será salvo.
</p>

## Interface 

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269629-afad0f80-3efb-11eb-94c7-ff18a848e338.png">
</p>

<p align="justify">
A interface consiste em:
</p>
<p align="justify">
1. <b>Menu Arquivo</b>: localizado no canto superior esquerdo da interface, contém as funcionalidades de <b>criar um novo escultor</b>, <b>salvar arquivo</b> e <b>sair do programa</b>.
</p>
<p align="justify">
2. <b>Barra de ferramentas</b>: localizada logo abaixo do menu Arquivo, contém as funcionalidades de <b>inserir voxel</b>, <b>remover voxel</b>, <b>inserir caixa</b>, <b>remover caixa</b>, <b>inserir esfera</b>, <b>remover esfera</b>, <b>inserir elipsoide</b> e <b>remover elipsoide</b>, utilizadas para manipular figuras geométricas.
</p>
<p align="justify">
3. <b>Escultor</b>: localizado logo abaixo da barra de ferramentas, é a <b>área semelhante a um tabuleiro</b>, que é destinada ao desenho da <b>escultura tridimensional</b>.
</p>
<p align="justify">
4. <b>Seletor de profundidade</b>: localizado logo abaixo do escultor, tem a função de permitir que você altere o plano visível da sua escultura tridimensional (como se estivesse cortando-a em várias "fatias"), conforme modifica o valor do controle deslizante <b>Z</b>.
</p>
<p align="justify">
5. <b>Seletores de propriedades das figuras</b>: localizados no canto direito da interface, eles alteram os atributos das figuras geométricas que estão identificadas por seus nomes no topo de cada grupo de controles deslizantes. 
</p>
<p align="justify">
6. <b>Seletores de cor</b>: localizados logo abaixo dos seletores de propriedades das figuras, eles permitem que você defina uma cor que será utilizada para pintar as figuras geométricas utilizadas na sua escultura tridimensional, conforme modifica o valor dos controles deslizantes <b>R</b> (tonalidade de cor vermelha), <b>G</b> (tonalidade de cor verde), <b>B</b> (tonalidade de cor azul) e <b>A</b> (transparência). A cor escolhida pode ser visualizada ao lado dos controles deslizantes.
</p>

## Funcionalidades

### Inserir Voxel

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269636-b3409680-3efb-11eb-8a42-023261c042c4.png">
</p>

<p align="justify">
  Para desenhar um voxel (cubo de dimensões 1x1x1) na escultura, você deve clicar no <b>primeiro ícone</b> da barra de ferramentas. Em seguida, pode alterar a cor caso considere necessário e, finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que o voxel seja colocado. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá desenhar vários voxels conforme o caminho feito pelo mouse.
</p>

### Remover Voxel

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269682-c05d8580-3efb-11eb-903f-4cce4486b4a5.png">
</p>

<p align="justify">
Para remover um voxel (cubo de dimensões 1x1x1) da escultura, você deve clicar no <b>segundo ícone</b> da barra de ferramentas. Em seguida, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que o voxel seja apagado. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá remover vários voxels conforme o caminho feito pelo mouse.
</p>

### Inserir Caixa

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269717-c94e5700-3efb-11eb-849f-7454559f1b96.png">
</p>

<p align="justify">
Para desenhar uma caixa na escultura, você deve clicar no <b>terceiro ícone</b> da barra de ferramentas. Em seguida, selecione as dimensões da caixa, modificando os controles deslizantes localizados na área <b>Caixa</b>. Altere a cor caso considere necessário e, finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que a caixa seja colocada. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá desenhar várias caixas conforme o caminho feito pelo mouse.
</p> 

### Remover Caixa

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269730-cfdcce80-3efb-11eb-8f51-1a3c79b6a752.png">
</p>

<p align="justify">
Para remover uma caixa da escultura, você deve clicar no <b>quarto ícone</b> da barra de ferramentas. Em seguida, selecione as dimensões da caixa, modificando os controles deslizantes localizados na área <b>Caixa</b>. Finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que a caixa seja apagada. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá remover várias caixas conforme o caminho feito pelo mouse.
</p>

### Inserir Esfera

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269779-e125db00-3efb-11eb-871f-9a876fcb0a8f.png">
</p>

<p align="justify">
Para desenhar uma esfera na escultura, você deve clicar no <b>quinto ícone</b> da barra de ferramentas. Em seguida, selecione o raio da esfera, modificando o controle deslizante localizado na área <b>Esfera</b>. Altere a cor caso considere necessário e, finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que a esfera seja colocada. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá desenhar várias esferas conforme o caminho feito pelo mouse.
</p>

### Remover Esfera

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269788-e3883500-3efb-11eb-8f54-235c92ee8eda.png">
</p>

<p align="justify">
Para remover uma esfera da escultura, você deve clicar no <b>sexto ícone</b> da barra de ferramentas. Em seguida, selecione o raio da esfera, modificando o controle deslizante localizado na área <b>Esfera</b>. Finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que a esfera seja apagada. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá remover várias esferas conforme o caminho feito pelo mouse.
</p>

### Inserir Elipsoide

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269798-e4b96200-3efb-11eb-8b3a-56671be4526a.png">
</p>

<p align="justify">
Para desenhar um elipsoide na escultura, você deve clicar no <b>sétimo ícone</b> da barra de ferramentas. Em seguida, selecione os raios do elipsoide, modificando os controles deslizantes localizados na área <b>Elipsoide</b>. Altere a cor caso considere necessário e, finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que o elipsoide seja colocado. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá desenhar vários elipsoides conforme o caminho feito pelo mouse.
</p>

### Remover Elipsoide

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269827-f26ee780-3efb-11eb-900a-3e7dab011e61.png">
</p>

<p align="justify">
Para remover um elipsoide da escultura, você deve clicar no <b>oitavo ícone</b> da barra de ferramentas. Em seguida, selecione os raios do elipsoide, modificando os controles deslizantes localizados na área <b>Elipsoide</b>. Finalmente, clique com o botão esquerdo do mouse dentro do escultor, no local onde deseja que o elipsoide seja apagado. Se mantiver o botão esquerdo do mouse pressionado e arrastá-lo, poderá remover vários elipsoides conforme o caminho feito pelo mouse.
</p>

### Novo Escultor

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102269874-031f5d80-3efc-11eb-9446-b24253a35045.png">
</p>

<p align="justify">
Para criar um novo escultor, você deve abrir o menu Arquivo e clicar no <b>primeiro item</b> entre os exibidos. 
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270020-3a8e0a00-3efc-11eb-88b5-56e0e3c229ab.png">
</p>

<p align="justify">
Em seguida, confirme se você deseja ou não prosseguir para a criação do novo escultor. 
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270049-437edb80-3efc-11eb-8e22-69e08a2623b3.png">
</p>

<p align="justify">
Será exibida uma janela com 3 controles deslizantes, para que você selecione as dimensões do novo escultor. Para confirmar a escolha, clique no botão <b>OK</b>.
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270054-45e13580-3efc-11eb-9f12-d86ac717326f.png">
</p>

<p align="justify">
O antigo escultor será substituído por um novo, com as dimensões que você escolheu.
</p>

### Salvar Arquivo

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270068-4c6fad00-3efc-11eb-8cb2-908b9f70ad50.png">
</p>

<p align="justify">
Para salvar a sua escultura em um arquivo, você deve abrir o menu Arquivo e clicar no <b>segundo item</b> entre os exibidos.
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270092-5691ab80-3efc-11eb-98f7-c7f200781ff3.png">
</p>

<p align="justify">
Será exibida uma janela confirmando que o arquivo foi salvo no caminho que você especificou no <b>plotter.cpp</b>.
</p>

### Sair

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270097-58f40580-3efc-11eb-891a-e63895040d52.png">
</p>

<p align="justify">
Para fechar o programa, você deve abrir o menu Arquivo e clicar no <b>terceiro item</b> entre os exibidos.
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/71016225/102270108-5e515000-3efc-11eb-9932-9fbd7c653423.png">
</p>

<p align="justify">
Em seguida, confirme se você deseja ou não fechar o programa.
</p>

<br>
<br>
<br>
<br>
<br>
Desenvolvido por Lucas Cunha Alves, para a disciplina de Programação Avançada (DCA1202) da UFRN.
