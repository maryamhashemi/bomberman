#include "managerClient.h"


ManagerClient::ManagerClient()
{
  gui = new GUI();
  menu = new Menu(1383,855);

  wall = new Wall[109] {{132,132},{264,132},{396,132},{528,132},{660,132},{792,132},{924,132},{1056,132},{1188,132},
                        {132,264},{264,264},{396,264},{528,264},{660,264},{792,264},{924,264},{1056,264},{1188,264},
                        {132,396},{264,396},{396,396},{528,396},{660,396},{792,396},{924,396},{1056,396},{1188,396},
                        {132,528},{264,528},{396,528},{528,528},{660,528},{792,528},{924,528},{1056,528},{1188,528},
                        {132,660},{264,660},{396,660},{528,660},{660,660},{792,660},{924,660},{1056,660},{1188,660},

                        {0,0},{66,0},{132,0},{198,0},{264,0},{330,0},{396,0},{462,0},{528,0},{594,0},{660,0},{726,0},{792,0},{858,0},{924,0},{990,0},{1056,0},{1122,0},{1188,0},{1254,0},{1320,0},
                        {0,66},{0,132},{0,198},{0,264},{0,330},{0,396},{0,462},{0,528},{0,594},{0,660},{0,726},{0,792},
                        {1320,66},{1320,132},{1320,198},{1320,264},{1320,330},{1320,396},{1320,462},{1320,528},{1320,594},{1320,660},{1320,726},{1320,792},
                        {66,792},{132,792},{198,792},{264,792},{330,792},{396,792},{462,792},{528,792},{594,792},{660,792},{726,792},{792,792},{858,792},{924,792},{990,792} ,{1056,792},{1122,792},{1188,792},{1254,792}
                        };

    obs = new Obstacles[56]{
                           {66,264},{66,330},{132,330},{198,462},{264,462},{330,462},{198,528},{330,528},{330,594},{330,660},{330,726},{264,594},
                           {396,594},{462,594},{528,594},{198,660},{198,726},{264,726},{330,726},{396,726},{528,726},{594,726},{660,726},{594,660},
                           {792,594},{858,528},{858,396},{1254,660},{1254,594},{1254,396},{726,330},{726,66},{726,132},{792,66},{924,66},{198,330},
                           {198,264},{198,198},{264,198},{330,198},{330,132},{330,66},{264,66},{396,66},{858,462},{858,594},{858,330},{792,330},{858,66},
                           {1254,66},{1254,132},{1254,198},{1254,264},{1254,330},{1188,198},{1122,198}
                           };
    gift = new Gift[6]{
		               {792,66},{1254,198},{792,330},{594,726},{330,132},{330,660}
				   };

     bomber1 = new Bomberman( 65 , 65 , 57 , 57 );
     bomber2 = new Bomberman( 1254 , 726 , 59 , 59 );
     
     bomb1 = new Bomb(500,500);
     bomb2 = new Bomb(500,500);
     
     timer = new Timer(0,0,0);
     bomb1timer = new Timer(0 , 4 , 0);
     bomb2timer = new Timer(0 , 4 , 0);
 }


int ManagerClient::getWorldWidth()
{
    return WorldWidth;
}

Menu* ManagerClient::getMenu()
{
	return menu;
}

Wall* ManagerClient::getWall()
{
    return wall;
}

Obstacles* ManagerClient::getObs()
{
    return obs;
}

Bomberman* ManagerClient::getBomber1()
{
    return bomber1;
}

Bomberman* ManagerClient::getBomber2()
{
    return bomber2;
}

Bomb* ManagerClient::getBomb()
{
    return bomb1;
}
Gift* ManagerClient::getGift()
{
	return gift;
}


 void ManagerClient::run()
 {
     bool running = true;
     bool *move = new bool[4] {{0}};
     bool shoot = 0;
     
     bool gift1 = 0;
     bool gift2 = 0;
     
     sf::Event event;
        
     gui->getWindow()->clear();
        
if(gui->drawMenu(menu))
{	
	
	
	
     while (running)
    {	
		std::string dataServer;
		std::string dataClient = " ";
		
		
		try
		{
			ClientSocket client_socket ( "172.17.8.111" , 30000 );
				try
				{
				  
				  while(gui->getWindow()->pollEvent(event))
                        {
                                switch(event.type)
                                {
                                        case sf::Event::Closed:
                                        {
                                                gui->getWindow()->close();
                                                return;
                                        }

                                        case sf::Event::KeyPressed:
                                        {
                                                switch(event.key.code)
                                                {
                                                        case sf::Keyboard::Right:
                                                        {
                                                                move[0]=1;
                                                                break;
                                                        }
                                                        case sf::Keyboard::Up:
                                                        {
                                                                move[1]=1;
                                                                break;
                                                        }
                                                        case sf::Keyboard::Left:
                                                        {
                                                                move[2]=1;
                                                                break;
                                                        }
                                                        case sf::Keyboard::Down:
                                                        {
                                                                move[3]=1;
                                                                break;
                                                        }

                                                        case sf::Keyboard::Space:
                                                        {
                                                                shoot=1;
                                                                break;
                                                        }
                                                }
                                                break;
                                        }

                                        case sf::Event::KeyReleased:
                                        {
                                                switch(event.key.code)
                                                {
                                                        case sf::Keyboard::Right:
                                                        {
                                                                move[0]=0;
                                                                break;
                                                        }
                                                        case sf::Keyboard::Up:
                                                        {
                                                                move[1]=0;
                                                                break;
                                                        }
                                                        case sf::Keyboard::Left:
                                                        {
                                                                move[2]=0;
                                                                break;
                                                        }
                                                        case sf::Keyboard::Down:
                                                        {
                                                                move[3]=0;
                                                                break;
                                                        }
                                                        /*case sf::Keyboard::Space:
                                                        {
                                                                shoot=0;
                                                                break;
                                                        }*/

                                                }
                                                break;
                                        }
                                }
        
                        }

						dataClient = bomber1->move2(move ,obs , wall ,bomber2);
                                
                        if(shoot)
                        {
							dataClient = bomb1->shoot2(bomber1 , bomb1timer);
							shoot=0;
						}
								
						client_socket << dataClient;
						client_socket >> dataServer;
								
						bomber2->move1(dataServer , obs  , wall ,bomber1);
						bomb2->shoot1(dataServer , bomber2 , bomb2timer);
						
						for(int i=0; i<6 ; i++)
						{
								if ( gift[i].getGift(bomber1) == 1)
									gift1 = 1;
									
								if ( gift[i].getGift(bomber2) == 1)
									gift2 = 1;
						}
						
						gui->drawBack();
						gui->drawBomber(bomber1,true);
						gui->drawBomber(bomber2,false);
						gui->drawWall(wall);
						gui->drawTimer(timer);
						gui->drawGift(gift);
						gui->drawObs(obs);
					
						if(bomb1timer->getSeconds()<4)
							bomb1timer->handletime();
							
						if(bomb2timer->getSeconds()<4)	
						    bomb2timer->handletime();
					
						if(bomb1timer->getSeconds()>=1 && bomb1timer->getSeconds()<=3)
						{	
							gui->drawBomb(bomb1);
						}
							
						
						if(bomb1timer->getSeconds()==3)
						{
								sf::Music b;
								if (!b.openFromFile("howto.wav")) {}
								b.play();
								bomb1timer->handletime();
								b.pause();
								
								if(gift1 == 1)
								{
									bomb1->explodeGift(obs , bomber1 ,bomber2);
								}	

								
							bomb1->explode(obs , bomber1 ,bomber2);
						}
						
						if(bomb2timer->getSeconds()>=1 && bomb2timer->getSeconds()<=3)
						{	
							gui->drawBomb(bomb2);
						}
							
						
						if(bomb2timer->getSeconds()==3)
						{
							
								sf::Music b;
								if (!b.openFromFile("howto.wav")) {}
								b.play();
							
								if( gift2 == 1)
								{
									bomb2->explodeGift(obs , bomber1 ,bomber2);
								}	
							
								
							bomb2->explode(obs , bomber1 ,bomber2);
						}	
						
						if(bomber1->getIsExist()==0 && bomber2->getIsExist()==1){gui->drawGameover();}
							
							
						if(bomber1->getIsExist()==1 && bomber2->getIsExist()==0){gui->drawWin();}
							
							
					
						gui->getWindow()->display();
						
						client_socket << dataClient;
						client_socket >> dataServer;
				
				}
				  catch ( SocketException& ) { std::cout << "error";}

				  std::cout << "We received this response from the server:\n\"" << dataServer << "\"\n";

		}
		
		catch ( SocketException& e )
		{
			//gui->drawLoading();
			//gui->getWindow()->display();
			std::cout << "Exception was caught:" << e.description() << "\n";
		}
                        
	}		
}

}
