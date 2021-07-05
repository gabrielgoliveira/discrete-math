#include <iostream>
#include <stdlib.h>

using namespace std;

string toLower(string s) {
    int size = s.size();
    for(int i = 0; i < size; i++){
        char temp = s[i];
        if(temp <= 90 && temp != 32){
            //maiscula
            temp = char(temp+32);
            s[i] = temp;
        }
    }
    return s;
}


string encrypt(string message, int key) {
    message = toLower(message);
    
    int size = message.size();
    string out = "";
    
    for(int i = 0; i < size; i++) {
        char temp = message[i];
        if(temp != 32){
            int pos = temp - 97;
            
            pos = (pos + key)%26;
            
            message[i] = char(97 + pos);
        }
    }
    
    return message;
}

string decrypt(string message, int key) {
    message = toLower(message);
    
    int size = message.size();
    string out = "";
    
    for(int i = 0; i < size; i++) {
        char temp = message[i];

        if(temp != 32) {
            int pos = temp - 97;
            
            pos = (pos - key)%26;

            if(pos < 0){
                pos = 25 + pos;
            }
            message[i] = char(97 + pos);
        }

    }
    
    return message;

}

int main()
{
    string message;
    int key, option;
    
    cout<<" ----------------- Cifra de Troca ------------------ "<<endl;
    cout<<"1 - Criptografar a Mensagem"<<endl;
    cout<<"2 - Descriptografar"<<endl;
    cout<<"Escolha um Numero : ";
    cin>>option;

    system("cls");
    fflush(stdin); //clear buffer

    if(option == 1){
        cout<<"Digite a mensagem para encriptar : ";
        getline(cin, message);
        cout<<"Agora digite a chave secreta : ";
        cin>>key;
        cout<<"Encriptando ... "<<endl;
        cout<<"-> Mensagem Encriptada : "<<encrypt(message, key)<<endl;
    } else if (option == 2){
        cout<<"Digite a mensagem para desencriptar : ";
        getline(cin, message);
        cout<<"Agora digite a chave secreta : ";
        cin>>key;
        cout<<"Desencriptando ... "<<endl;
        cout<<"-> Mensagem Desencriptada : "<<decrypt(message, key)<<endl;
    } else {
        cout<<"A opcao escolhida nao eh valida"<<endl;
    }

    return 0;
}