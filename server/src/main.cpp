//
// Created by lcomte on 20/11/2019.
//

#include "Server_TCP.hpp"
#include "Game/Game.hpp"
#include <thread>         // std::this_thread::sleep_for

int main(int argc, char *argv[]) {
    /*std::vector<std::string> playerlist;
    playerlist.emplace_back("Joueur1");
    playerlist.emplace_back("Joueur2");
    playerlist.emplace_back("Joueur3");
    playerlist.emplace_back("Joueur4");
    Game G = Game(playerlist);
    //G.launch();
    //G.update();

}*/

    try
    {
        boost::asio::io_service io_service;
        Server_TCP server(io_service, argv[1]);
        io_service.run();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
