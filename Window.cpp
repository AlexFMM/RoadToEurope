#include "Window.h"
#include "alg.h"
#include "City.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;


[STAThread]
void Main(array<String^>^ args){
	ifstream dist, cost, time;
	dist.open("distance.csv");
	cost.open("cost.csv");
	time.open("time.csv");

	loadFile(dist, distancias);// load da tabela das distancias
	loadFile(cost, custo);// load da tabela das distancias
	paises=loadFile(time, custo);// load da tabela das tempo
	City cidades[15];

	for (int i = 0; i < 15; i++){
		cidades[i].change(paises[i], i);
	}

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RoadToEurope::Window form;
	Application::Run(%form);
}