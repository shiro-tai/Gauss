#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int N=0;
float S = 0;
float A[30][30], B[30], X[30];
void PopularMatriz(){
    printf("\nOrdem do sistema: ");
    scanf("%d",&N);
    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("\nElemento[%d][%d] = ",i+1, j+1);
            scanf("%f", &A[i][j]);
        }
        cout<<"\nDigite o termo independente ["<<i+1<<"] ";
        cin>>B[i];
        cout<<flush;
    }
}

void MostrarMatriz(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf ("\n[%d][%d] = %.2f\n", i, j,A[i][j]);
        }
    }
}

void triangularizar(){
    for(int k=0;k<(N-1);k++){
        for(int i=k+1;i<N;i++){
            for(int j= k+1;j<N;j++){
                A[i][j] = (A[k][k]*A[i][j])-(A[i][k]*A[k][j]);
            }
            B[i]= (A[k][k]*B[i])-(A[i][k]*B[k]);
            A[i][k]=0;
        }
    }
}

void solucao(){
    X[N-1]= B[N-1]/A[N-1][N-1];
    for(int k = N-2; k>=0; k--){
        S = 0;
        for(int j=k+1; j<N; j++){
            S += A[k][j]*X[j];
            X[k] = (B[k]-S)/A[k][k];
        }
    }
}

void MostrarSolucao(){
    cout<<"\nSolucao do problema:"<<endl;
    for(int i=0;i<N;i++){
        printf("[%d]=%.2f",i,X[i]);
    }
}
int main(){
    PopularMatriz();
    MostrarMatriz();
    triangularizar();
    MostrarMatriz();
    solucao();
    MostrarSolucao();
    
}
