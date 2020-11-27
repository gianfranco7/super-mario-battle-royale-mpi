#include "../Models/world.cpp"

int main()
{
	World world;
	world.printWorld();


/*Mario m;
	
	[0, 1, 3, 4, 5, 6]

	if (my_id == 0)  {

		while ( condicion ) { // Mientras haya mas de 1 Mario vivo

			 // Haga algo para coordinar con los demas
			 MPI_Bcast(...) //Ej. enviar el id del proceso que debe imprimir en consola

		}

		// Imprime el ganador ... 

	}

	coins[num_processes];
	attacking[num_processes]
	activePlayers[num_processes]
	goobas[num_processes]

	m.setStrategy(...) // aleatoreamente elegimos estrategia

	while (m.isAlive()) {

		 MPI_Bcast(...) // Recibir el id del proceso que imprime en consola

		 MPI_Allgather(... coins)
		 MPI_Allgather(&attacking /*sendbuf*///, ... attackers /*recv buf*/)
		 //...

		 // Calcular a quien atacar
		 // Calcular cuantos bichitos tengo q meter en mi mundo porque los envia mi atacante
		// ...

		/// int attacking = // selecciono a quien ataco 

		// elements = w.next();
		// Para cada elemento en elements
			// m.choseAction(element) 
			// if moneda = m.addCoin()
			// if kill goomba // hacemos algo 
			// if didn't jump // Game over

			/*if (my_id == proceso que imprime) {
				print ...
				cout << ...
			}


	}

	while (...) { // Mientras todos los demas sigan jugando, yo (Mario fantasmita) debo seguir llamando las funciones respectivas para evitar bloquear los procesos activos
		Broadcast(... )
		All Gather (...)
	}*/

    return 0;
}
