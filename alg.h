#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> paises;
vector<int> caminho;
float distancias[15][15];
float tempo[15][15];
float custo[15][15];

vector<string> loadFile(ifstream &file, float tab[][15]){
	vector<string> paises;
	paises.resize(15);
	string aux;
	string ficheiro[15][15];
	getline(file, aux, ';');

	for (int i = 0; i < 15; i++){
		if (i == 14)
			getline(file, paises[i]);
		else
			getline(file, paises[i], ';');
	}

	//cout << "\n**\n";

	for (int i = 0; i < 15; i++){
		getline(file, aux, ';');
		for (int j = 0; j < 15; j++){
			if (j == 14)
				getline(file, ficheiro[i][j]);
			else
				getline(file, ficheiro[i][j], ';');
		}
	}

	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (ficheiro[i][j] == "")
				tab[i][j] = stof(ficheiro[j][i]);
			else
				tab[i][j] = stof(ficheiro[i][j]);
			//cout << tab[i][j] << " ";
		}
		//cout << endl;
	}
	file.close();

	return paises;
}

static System::String ^getSystemString(std::string std){

	return gcnew System::String(std.c_str());
}

float algoritmo(int pos, int fim, vector<int> &caminho, float tab[][15]){
	if (caminho.empty()){
		caminho.push_back(pos);
	}
	if (pos == fim){
		return tab[fim][caminho.back()];
	}
	else{
		float m = 9999999;
		int p = -1;
		for (int i = 0; i < 15; i++){
			if (tab[caminho.back()][i] < m && tab[caminho.back()][i] > 0 && find(caminho.begin(), caminho.end(), i) == caminho.end()){
				if (caminho.size() < 14 && i == fim) 
					continue;
				m = tab[caminho.back()][i];
				p = i;
			}
		}
		caminho.push_back(p);
		return m + algoritmo(p, fim, caminho, tab);
	}
}
