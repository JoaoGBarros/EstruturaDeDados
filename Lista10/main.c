#include <stdio.h>
#include "Arvore.h"

/* 
* Como "tema" do exercicio, em vez de utilizar o TAD alunos, eu preferi por criar um TAD Albuns
* Em que eu crio Arvores Binarias de Busca utilizando os albuns dos meus artistas preferidos, levando em
* Consideracao a quantidade de streams(plays) da musica mais popular do album. 
* A raiz da arvore eh o album mais novo
*/


int main(){
    Arvore* SanCisco = CriaArvoreVazia();
    Album* The_Water;
    Album* Gracetown;
    Album* San_Cisco;
    Album* Between_You_And_Me;

    int id = 1;
    int contador = 0;

    FILE* graph = fopen("graphviz.txt", "w");

    The_Water = CriaAlbum("San Cisco", "The Water", 9808752);
    Gracetown = CriaAlbum("San Cisco", "Gracetown", 28667419);
    San_Cisco = CriaAlbum("San Cisco", "San Cisco", 35741389);
    Between_You_And_Me = CriaAlbum("San Cisco", "Between You and Me", 10360515);

    SanCisco = InsereArvore(SanCisco, Between_You_And_Me, &id);
    SanCisco = InsereArvore(SanCisco, The_Water, &id);
    SanCisco = InsereArvore(SanCisco, Gracetown, &id);
    SanCisco = InsereArvore(SanCisco, San_Cisco, &id);
    
    ImprimeArvore(SanCisco);
    ImprimeGrafico(SanCisco, &contador, graph, &id);
    
    SanCisco = RetiraArvore(SanCisco, 28667419, &id, &contador); //Retira o album de acordo com o numero de streams - nesse caso o Gracetown
    
    ImprimeArvore(SanCisco);
    ImprimeGrafico(SanCisco, &contador, graph, &id);
    DestroiArvore(SanCisco);

    //Reseta so valores do id e contador, ja que vai ser criada outra arvore
    id = 1; 
    contador = 0;
    Arvore* MyChemicalRomance = CriaArvoreVazia();
    Album* TCSR = CriaAlbum("MCR", "Three Cheers for Sweet Revenge", 220435086);
    Album* TBP = CriaAlbum("MCR", "The Black Parade", 421379692);
    Album* DD = CriaAlbum("MCR", "Danger Days: The True Lives of The Fabulous Killjoys", 145562027);

    MyChemicalRomance = InsereArvore(MyChemicalRomance, DD, &id);
    MyChemicalRomance = InsereArvore(MyChemicalRomance, TBP, &id);
    MyChemicalRomance = InsereArvore(MyChemicalRomance, TCSR, &id);

    ImprimeArvore(MyChemicalRomance);
    ImprimeGrafico(MyChemicalRomance, &contador, graph, &id);
    
    MyChemicalRomance = RetiraArvore(MyChemicalRomance, 145562027, &id, &contador); //Retira o album de acordo com o numero de streams - nesse caso o Danger Days
    
    ImprimeArvore(MyChemicalRomance);
    ImprimeGrafico(MyChemicalRomance, &contador, graph, &id);
    DestroiArvore(MyChemicalRomance);

    fclose(graph);

    return 0;
}