#include "Window.h"
#include "alg.h"

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
	paises=loadFile(time, tempo);// load da tabela das tempo

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RoadToEurope::Window form;
	Application::Run(%form);
}