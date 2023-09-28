#include <iostream>
#include <thread>
#include <fstream>
#include <string>

#include "text_color.h"
using namespace std;

int exibirChart(string time[], string label[], string info[], string category[], string lin[], int qttlin, int value[], int opc);
int sort(string time[], string label[], string info[], string category[], string lin[], int qttlin, int value[], int opc);

int fps = 24;
int bars = 5;

class ChartInfo {
  public:
    string title;
    string typeofvalue;
    string source;
}Chartum;

int main(){
  int ini;
  int opc;
  cout << "============================================\n  Bem vindo ao programa Bar Chart Race 1.0\n  Copyright (C) 2021, Gabriel Alves P Lima\n============================================\n\nDigite 1 para iniciar, ou insira outro valor para sair do programa: ";
  cin >> ini;
  if (ini == 1){
    opc = 0;
  }
  else{
    opc = 92;
  }

  if (opc != 92){//Esse 92 é um valor genérico alto para que o programa só encerre em situações bem específicas
    int bcropc = 0;
    while (bcropc > 2 || bcropc < 1){
      cout << "1)World's most valuable brands from 2000 to 2018\n2)The most populous cities in the world from 1500 to 2018\nSelecione uma opção: ";
      cin >> bcropc;
    }

    int qttlin = 0;

    if (bcropc == 1){
      ifstream in("data/brands.txt");
      string quantidade;
      while (getline(in, quantidade)){
      qttlin++;
      }
    }
    else if (bcropc == 2){
      ifstream in("data/cities.txt");
      string quantidade;
      while (getline(in, quantidade)){
      qttlin++;
      }
    }

    string linhas[qttlin];

    if (bcropc == 1){
      ifstream barchart;
      cout << Color::tcolor( ">>>Preparando-se para ler data/brands.txt'...", Color::GREEN);
      barchart.open("data/brands.txt");
      if (barchart.is_open()){
        cout << Color::tcolor( ">>>Arquivo lido com sucesso!\n\n", Color::GREEN);
        getline(barchart, Chartum.title);
        getline(barchart, Chartum.typeofvalue);
        getline(barchart, Chartum.source);
        int teste = 0;
        while (getline(barchart, linhas[teste]) && teste < qttlin){
          teste++;
        }
        barchart.close();
      }
      else{
        cout << "Não foi possível abrir\n\n\n";
      }
    }
    else if (bcropc == 2){
      ifstream barchart;
      cout << Color::tcolor( ">>>Preparando-se para ler data/cities.txt'...", Color::GREEN);
      barchart.open("data/cities.txt");
      if (barchart.is_open()){
        cout << Color::tcolor( ">>>Arquivo lido com sucesso!\n\n", Color::GREEN);
        getline(barchart, Chartum.title);
        getline(barchart, Chartum.typeofvalue);
        getline(barchart, Chartum.source);
        int teste = 0;
        while (getline(barchart, linhas[teste]) && teste < qttlin){
          teste++;
        }
        barchart.close();
      }
      else{
        cout << "Não foi possível abrir\n\n\n";
      }
    }

    string time[qttlin];
    string label[qttlin];
    string info[qttlin];
    int value[qttlin];
    string category[qttlin];

    
    for (int i = 0; i < qttlin; i++){
      if (linhas[i].length() > 5){
        int tipo = 0;
        int aux = 0;
        string linaux[1];
        for (int j = 0; j < linhas[i].length(); j++){
          if (linhas[i][j] ==  ','){
            tipo++;
            aux = 0;
          }
          else{
            if (tipo == 0){
              time[i] += linhas[i][j];
              aux++;
            }
            else if(tipo == 1){
              label[i] += linhas[i][j];
              aux++;
            }
            else if(tipo == 2){
              info[i] += linhas[i][j];
              aux++;
            }
            else if(tipo == 3){
              linaux[0] +=linhas[i][j];
            }
            else if(tipo == 4){
              category[i]+= linhas[i][j];
              aux++;
            }
          } 
        }
        value[i] = stoi(linaux[0]);
        linaux[0] = "";
        aux = 0;
        tipo = 0;
      }
    }

    int erro = 1;
    while (erro == 1){
      cout << "Informe a quantidade de fps desejada [1, 24]: ";
      cin >> fps;
      if (fps > 24){
        cout << "Você digitou um valor maior que 24. Por favor, tente novamente\n";
      }
      else if (fps < 1){
        cout << "Você digitou um valor menor que 1. Por favor, tente novamente\n";
      }
      else{
        erro = 0;
      }
    }
    erro = 1;
    while (erro == 1){
      cout << "Informe a quantidade de barras desejada [1, 15]: ";
      cin >> bars;
      if (bars > 15){
        cout << "Você digitou um valor maior que 15. Por favor, tente novamente\n";
      }
      else if (bars < 1){
        cout << "Você digitou um valor menor que 1. Por favor, tente novamente\n";
      }
      else{
        erro = 0;
      }
    }
    opc = sort(time, label, info, category, linhas, qttlin, value, opc);
    opc+=4;
  }
  cout << "Fim da Execução!";
  return 0;
}

int exibirChart(string time[], string label[], string info[], string category[], string lin[], int qttlin, int value[], int opc){
  string text;
  text = to_string(fps);
  cout << Color::tcolor( ">>> A velocidade da animação é de ", Color::GREEN) << Color::tcolor( text, Color::GREEN) << Color::tcolor( "fps\n", Color::GREEN);
  cout << Color::tcolor( ">>> Título: ", Color::GREEN) << Color::tcolor( Chartum.title, Color::GREEN) << Color::tcolor( "\n", Color::GREEN);
  cout << Color::tcolor( ">>> Valor em: ", Color::GREEN) << Color::tcolor( Chartum.typeofvalue, Color::GREEN) << Color::tcolor( "\n", Color::GREEN);
  cout << Color::tcolor( ">>> Fonte: ", Color::GREEN) << Color::tcolor( Chartum.source, Color::GREEN) << Color::tcolor( "\n", Color::GREEN);
  cout << Color::tcolor( ">>> Digite qualquer valor e pressione Enter para iniciar a execução: ", Color::GREEN); 
  cin >> text;
  int charts = 0;
  for (int i = 0; i < qttlin; i++){
    if (value[i] > 0 && value[i+1] == 0){
      charts++;
    }
  }
  int teste = 2;
  int proport = 0;
  for (int a = 0; a < charts-1; a++){
    int primeiro = teste;
    cout << Color::tcolor( Chartum.title, Color::BRIGHT_BLUE ) << "\n\n";
    cout << Color::tcolor( "Tempo: ", Color::BRIGHT_BLUE ) << time[teste] << "\n\n";
    for (int i = primeiro; i < bars+primeiro; i++){
      if (value[teste] <= 0){
        break;
      }
      if (i == primeiro){
        cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
      }
      else{
        float x = value[teste];
        float y = value[primeiro];
        if (x < y){
          for (int j = 0; j <= x/y * 50; j++){
            cout << "■";
          }
        }
      }
      cout << " " << label[teste] << " [" <<  value[teste] << "]\n\n";
      teste++;
    }
    cout << "+---------+---------+---------+---------+---------+\n";
    cout << Color::tcolor( "0         ", Color::BRIGHT_YELLOW );
    proport = value[primeiro]/5;
    text = to_string(proport);
    cout << Color::tcolor( text, Color::BRIGHT_YELLOW );
    for (int k = text.size(); k <= 9; k++){
      cout << " ";
    }
    proport = value[primeiro]/5 *2;
    text = to_string(proport);
    cout << Color::tcolor( text, Color::BRIGHT_YELLOW );
    for (int k = text.size(); k <= 9; k++){
      cout << " ";
    }
    proport = value[primeiro]/5 *3;
    text = to_string(proport);
    cout << Color::tcolor( text, Color::BRIGHT_YELLOW );
    for (int k = text.size(); k <= 9; k++){
      cout << " ";
    }
    proport = value[primeiro]/5 *4;
    text = to_string(proport);
    cout << Color::tcolor( text, Color::BRIGHT_YELLOW );
    for (int k = text.size(); k <= 9; k++){
      cout << " ";
    }
    proport = value[primeiro];
    text = to_string(proport);
    cout << Color::tcolor( text, Color::BRIGHT_YELLOW ) << "\n";
    /*cout << Color::tcolor( "0         20%       40%       60%       80%       100%\n", Color::BRIGHT_YELLOW );*/
    cout << Color::tcolor( Chartum.typeofvalue, Color::BRIGHT_YELLOW ) << "\n\n";
    cout << Chartum.source << "\n";
    cout << "Legendas\n\n\n";
    chrono::milliseconds  duration{ 1000/fps };
    this_thread::sleep_for( duration );
    while (value[teste] > 0){
      teste++;
    }
    teste+=2;
  }

  return opc;
}

int sort(string time[], string label[], string info[], string category[], string lin[], int qttlin, int value[], int opc){

  int troca;
  string strtroca[1];
  for (int i = 0; i < qttlin; i++){
    for (int j = i+1; j < qttlin; j++){
      if (value[i] <= 0 || value[j] <= 0 || value[i] > 1000000 || value[j] > 1000000){
        if (value[i] > 1000000){
          value[i] = 0;
        }
        if (value[j] > 1000000){
          value[j] = 0;
        }        
        break;
      }
      else if (value[i] <  value[j] && lin[i].length() > 5 && lin[j].length() > 5 && value[i] != 0 && value[j] != 0){
        troca = value[i];
        value[i] = value[j];
        value[j] = troca;

        strtroca[0] = time[i];
        time[i] = time[j];
        time[j] = strtroca[0];

        strtroca[0] = label[i];
        label[i] = label[j];
        label[j] = strtroca[0];

        strtroca[0] = info[i];
        info[i] = info[j];
        info[j] = strtroca[0];

        strtroca[0] = category[i];
        category[i] = category[j];
        category[j] = strtroca[0];
      }
    }
  }
  /*for (int i = 0; i < qttlin; i++){
    cout << time[i] << label[i] << info[i] << value[i] << category[i] << endl;
  }*/
  opc = exibirChart(time, label, info, category, lin, qttlin, value, opc);
  return opc = 88;
}