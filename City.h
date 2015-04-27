#pragma once
#include <string>
using namespace std;

class City
{
public:
	string nome;
	int id;
	bool visited;


	City(){
		this->id = -1;
		this->nome = "";
		this->visited = false;
	}

	City(string s, int i){
		this->id = i;
		this->nome = s;
		this->visited = false;
	}

	void change(string s, int i){
		this->id = i;
		this->nome = s;
	}

	void visit(){
		this->visited = true;
	}

	bool wasVisited(){
		return this->visited;
	}
};

