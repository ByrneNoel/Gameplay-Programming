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
		armed = !armed;
		
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
	cout << "3. Set Target Coordinates" << endl; 
	cout << "4. Exit" << endl;

	

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


bool checkHit(Target* target, Missile* missle)
{
	int targetX = target->coordinates.x;	// get the targets coordinates
	int targetY = target->coordinates.y;

	int missileX = missle->coordinates.x;	// get the missles coordinates
	int missileY = missle->coordinates.y;

	if (missle->payload == EXPLOSIVE)
		{
			return missileX == targetX && missileY == targetY;
		}

	// check if missle is nuclear

	else if (missle->payload == NUCLEAR)
		{
			return(missileX >= targetX - 1 && missileX <= targetX + 1) &&	// returns 3x3 area
			(missileY >= targetY - 1 && missileY <= targetY + 1);
		}

	return false;
			
}

void setTargetCoordinates(Enemy& enemy)
{
	cout << "Enter target coordinates (x y): ";
	cin >> enemy.coordinates.x >> enemy.coordinates.y;
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

			if (checkHit(&enemy, &missle))
			{
				cout << "HIT" << endl;
			}
			else
			{
				cout << "Missed" << endl;
			}
			break;
		case 3:
			setTargetCoordinates(enemy);
			break;
		case 4:
			return 0;
		default:
			cout << "Invalid option" << endl;
		}
	}
}

