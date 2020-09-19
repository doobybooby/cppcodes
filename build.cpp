#include "PlatSolid.h"

using namespace std;

PlatonicSolid* createFigure(int type)
{
	double e;
	cout << "Please enter a valid edge length\n";
	cout << "Enter: ";
	cin >> e;

	if (type == 1)
	{
		PlatonicSolid* tet = new Tetrahedron(e);
		return tet;
	}
	if (type == 2)
	{
		PlatonicSolid* oct = new Octahedron(e);
		return oct;
	}
	if (type == 3)
	{
		PlatonicSolid* ico = new Icosahedron(e);
		return ico;
	}
	if (type == 4)
	{
		PlatonicSolid* cub = new Cube(e);
		return cub;
	}
	if (type == 5)
	{
		PlatonicSolid* dod = new Dodecahedron(e);
		return dod;
	}
	if (type == 6)
	{
		double e2, e3;
		cout << "Please enter a valid 2nd edge length\n";
		cout << "Enter: ";
		cin >> e2;

		cout << "Please enter a valid 3rd edge length\n";
		cout << "Enter: ";
		cin >> e3;

		PlatonicSolid* par = new Parallelpiped(e,e2,e3);
		return par;
	}
	if (type == 7)
	{
		double height;
		cout << "Please enter a valid HEIGHT\n";
		cout << "Enter: ";
		cin >> height;

		PlatonicSolid* rsp = new RightSquarePyramid(e, height);
		return rsp;

	}
}


void printProperties(PlatonicSolid* type)
{
	type->getArea();
	type->getVolume();
}
void displayboard() {

	cout << "-1: Quit\n";
	cout << "1: Tetrahedron\n";
	cout << "2 : Octahedron\n";
	cout << "3 : Icosahedron\n";
	cout << "4 : Cube\n";
	cout << "5 : Dodecahedron\n";
	cout << "6 : Parallelpiped\n";
	cout << "7 : Right square pyramid\n";
}

int main() {
	
	cout << "Welcom to PlatonicSolids!\n";

	int figtype = -1;
	do {
		cout << "Please enter a number 1-7, or -1 to quit\n";
		displayboard();
		cout << "Enter: ";
		cin >> figtype;
		if(figtype ==-1)
		{
			cout << "Good bye!\n";
			return 0;
		}
		PlatonicSolid* temp = createFigure(figtype);
		printProperties(temp);
		cout << "\n";

	} while (figtype != -1);

	cout << "Good bye!\n";

	return 0;

}