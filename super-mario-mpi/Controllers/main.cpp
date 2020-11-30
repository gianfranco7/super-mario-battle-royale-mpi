#include "../Models/mario.cpp"

int main()
{
	Mario mario;
	cout << "Coin " << mario.getCoinEncounterOutcome() << endl;
	cout << "Hole " << mario.getHoleEncounterOutcome() << endl;
	cout << "Goomba " << mario.getLittleGoombaEncounterOutcome() << endl;
	cout << "KoopaTroopa " << mario.getKoopaTroopaEncounterOutcome() << endl;
	return 0;
}
