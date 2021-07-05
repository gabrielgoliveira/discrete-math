#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b, resto, quociente, i = 0;
    
    vector <vector<int>> matriz;
    vector<int> linha;
    
    cout<<"Digite A e B : ";
    cin>>a>>b;
    
    quociente = int(a/b);
    resto = a%b;
    
    linha.push_back(a);
    linha.push_back(b);
    linha.push_back(quociente);
    linha.push_back(resto);
    
    matriz.push_back(linha);
    
    linha.clear();

    cout<<endl;
    while(resto != 0) {
            //recuperando dados
            a = matriz[i][0];
            b = matriz[i][1];
            quociente = matriz[i][2];
            resto = matriz[i][3];
            
            //calculando a nova linha
            a = b;
            b = resto;
            
            quociente = int(a/b);
            resto = a%b;
    
            //inserindo no vetor linha
            linha.push_back(a);
            linha.push_back(b);
            linha.push_back(quociente);
            linha.push_back(resto);
            
            //inserindo na matriz e limpando o vetor linha
            matriz.push_back(linha);
            linha.clear();
            i++;
    }
 /*
    for(int i = 0; i<matriz.size(); i++){
        
        for(int j = 0; j<matriz[i].size(); j++){
            cout<<matriz[i][j]<<" | ";
        }
        cout<<endl;
    }
*/  

    int size = matriz.size() - 1;
    matriz[size].push_back(0);
    matriz[size].push_back(1);
    
    for(int i = (size-1); i >= 0; i--) {
        int s_anterior = matriz[i+1][4];
        int t_anterior = matriz[i+1][5];
        int q_atual = matriz[i][2];
        
        matriz[i].push_back(matriz[i+1][5]);
        matriz[i].push_back(s_anterior - (t_anterior*q_atual));
    }
    cout<<"a, b, q, r, s, t"<<endl;
    for(int i = 0; i<matriz.size(); i++){
        
        for(int j = 0; j<matriz[i].size(); j++){
            cout<<matriz[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<"O inverso eh : "<<matriz[0][5];
    return 0;
}
