#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void loadFile(ifstream &file,string *paises, float tab[][15]){
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
}

float calculoTotal(float tab[][15], int *caminho){
	float tot = 0;
	int prev = 0;
	for (int i = 0; i < 15; i++){
		if (i != 0)
			tot += tab[prev][caminho[i]];
		prev = caminho[i];
	}
	return tot;
}

int main(){
	ifstream dist;// cost, time;
	dist.open("distance.csv");
	//cost.open("cost.csv");
	//time.open("time.csv");
	string paises[15];
	float distancias[15][15];
	//float tempo[15][15];
	//float custo[15][15];
	int caminho[15], bestWay[15];

	float total;
	float best = INFINITY;

	loadFile(dist, paises, distancias);// load da tabela das distancias

	int inicio = 7;
	int fim = 0;

	
	cout << "melhor caminho:" << endl;
	for (int i = 0; i < 15; i++){
		cout << paises[bestWay[i]] << ", ";
	}
	cout << "\ncom um total de " << best << "Km";
	cout << endl;
	system("Pause");
	return 0;
}




