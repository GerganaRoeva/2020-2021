#include "server.h"
#include <iostream>

int main()
{
    Server server = Server();
	try{
		Game game_torrent_1 = Game("Tvoite igri", 320, "Alfa", 12900, "za vseki :3", 'M');
		Game game_torrent_2 = Game("CS:GO", 80, "Steam", 1200000, "Windows", 'M');
		Game game_torrent_3 = Game("Tuk nqkawa iga", 90, "Steam", 42500, "jkl", 'P');

		Movie film_torrent = Movie("Film", 40, "mrusnokote123", 20000, "ghjhj", 180, "English");
		Movie film_torrent_0 = Movie("The godfather", 10, "mrusnokote123", 1000, "Francis Ford Coppola", 60, "English");
		Movie film_torrent_3 = Movie("inglish man hihi", 30, "mrusnokote123", 20000, "Martin Scorsese", 120, "English");
		Movie film_torrent_2 = Movie("Interstellar", 10, "mrusnoku4e123", 9000, "Christopher Nolan", 150, "Italian");

		Software software_torrent_2 = Software("VMware Workstation2", 30, "VMware", 100, "VMware", "Linux", "2.0.9");
		Software software_torrent = Software("VMware Workstation", 20, "VMware", 1000, "VMware", "Linux", "3.6.2");
		Software software_torrent_3 = Software("VMware Workstation3", 40, "VMware", 11000, "VMware", "Linux", "7.11.9");

		// std::cout << film_torrent.to_string() << std::endl;

		std::list<Game*> game_torrents;
		std::list<Movie*> film_torrents;
		std::list<Software*> software_torrents;

		game_torrents.push_back(&game_torrent_1);
		game_torrents.push_back(&game_torrent_2);
		game_torrents.push_back(&game_torrent_3);

		film_torrents.push_back(&film_torrent);
		film_torrents.push_back(&film_torrent_0);
		film_torrents.push_back(&film_torrent_2);
		film_torrents.push_back(&film_torrent_3);

		software_torrents.push_back(&software_torrent);
		software_torrents.push_back(&software_torrent_2);
		software_torrents.push_back(&software_torrent_3);

		std::list<std::string> usernames;
		usernames.push_back("Geri");
		usernames.push_back("Misho pitona");
		usernames.push_back("Khrum deto ne iska da pravi flask domashno");



		//std::cout << game_torrents.to_string() << std::endl;

		server = Server(game_torrents, film_torrents, software_torrents);

		std::list<Game*> games_found = server.search_game_rating(game_torrents);

		for(auto it = games_found.begin(); it != games_found.end(); it++)
		{
			std::cout <<(**it).to_string() << std::endl;          
		}
		
	}catch(const char * error){
		std::cout << error << std::endl;
	}
    return 0;
}
