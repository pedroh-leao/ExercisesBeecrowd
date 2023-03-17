#include <stdio.h>

void coordenadasxy(int matriz[][1000], int linhas, int colunas, int coordenadas[]){
    int contador;

    for(int i=1; i<linhas-1; i++){
        for(int j=1; j<colunas-1; j++){
            if(matriz[i][j]==42){
                contador = 0;

                for(int y = i-1; y <= i+1; y++){
                    for(int x = j-1; x <= j+1; x++){
                        if(matriz[y][x] == 7)
                            contador++;
                    }
                }

                if(contador == 8){
                    coordenadas[0] = i+1;
                    coordenadas[1] = j+1;
                }
            }
        }
    }
}

int main(){
    int matriz[1000][1000];
    int n, m;

    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    int coordenadas[2] = {0, 0};
    coordenadasxy(matriz, n, m, coordenadas);

    printf("%d %d\n", coordenadas[0], coordenadas[1]);

    return 0;
}