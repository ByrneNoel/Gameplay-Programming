#include <iostream>

using namespace std;

typedef struct Position
{
	int x;
	int y;
	void
	print()
	{
		cout << "[ x: " << x << " ]" << "[ y: " << y << " ]" << endl;
	}
} Coordinates;

enum WarHead
{
	EXPLOSIVE,
	NUCLEAR
};

typedef struct Enemy
{
	Coordinates coordinates;
} Target;

struct Missile
{
	WarHead payload;
	Coordinates coordinates;
	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update()
	{
		coordinates.x += 1;
		coordinates.y += 2;
	}
};

void initializeGame(Missile& missle, Enemy& enemy)
{
	missle.coordinates.x = 0;
	missle.coordinates.y = 0;

	missle.armed = false;

	enemy.coordinates.x = 2;
	enemy.coordinates.y = 2;
}

void displayMenu()
{
	cout << "1. Warhead" << endl;
	cout << "2. Fire Missile" << endl;
	cout << "3. Exit" << endl;
}

void warHead(Missile &missle)
{
	int option;
	cout << "Select Warhead (0 for EXPLOSIVE, 1 for NUCLEAR): ";
	cin >> option;
	missle.payload = static_cast<WarHead>(option);

}

void updateMisslePosition(Missile& missle)
{
	missle.update();
}

bool checkHit();

int main()
{
	Enemy enemy;
	Missile missle;
	initializeGame(missle, enemy);

	while (true)
	{
		displayMenu();
		int option;
		cin >> option;

		switch (option)
		{
		case 1:
			warHead(missle);	// choose missle type
			break;
		case 2:
			missle.arm();	// Ready the missle
			updateMisslePosition(missle);
			break;
		case 3:
			return 0; // Exit
		default:
			cout << "Invalid option" << endl;
		}

		
	}
	
}