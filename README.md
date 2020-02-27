# SpaceExploration-CLI_Game
Just a simple C++ CLI game to challenge my abilities in OOP and basic C++ knowledge.

Description: Send astronauts to space! Add them to a spaceship, add planets to explore and items to each planet. Explore planets and collect items. Some astronauts can die, some can survive. Space is a dangerous place. When you decide you can retire an astronaut who risked his life for your joy.

Commands: The game consists of several commands that control the order of actions. Works on the principle of a command interpreter. The commands are:

LEGEND: [value] - describes an optional argument, \<value\> - describes a mandatory argument:

    ДобавиАстронавт <име на астронавт> //adds astronaut to astronautRepository 

    ДобавиПланета <име на планета> [предмет_1,предмет_2, … предмет_X] //adds planet to PlanetRepository 
    //input of items is delimited by “,” WITHOUT space

    ПенсионирайАстронавт <име на астронавт> //removes astronaut from repo

    ИзследвайПланета <име на планета> //begins exploration of given planet

    Отчет //shows current state of astronauts (Name, Oxygen, Items) 

    Край //ends the program


Commands can also be entered in English.

    AddAstronaut <name>  //adds astronaut to astronautRepository 

    AddPlanet <name> [item1,item2, … itemN] //adds planet to PlanetRepository 
    //input of items is delimited by “,” WITHOUT space

    RetireAstronaut <name> //removes astronaut from repo

    ExplorePlanet <name> //begins exploration of given planet

    Report //shows current state of astronauts (Name, Oxygen, Items) 

    End //ends the program
****