#include "Competition.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

/*
In Competition constructors (both default and non-constructor),
use srand(1);
Sample output in online GDB.

  1 T        H                                                                                                                                                      
  2 T         H                                                                                                                                                     
  3 T                  H                                                                                                                                            
  4    T                H                                                                                                                                           
  5       T           H                                                                                                                                             
  6        T                   H                                                                                                                                    
  7         T                  H                                                                                                                                    
  8   T                                 H                                                                                                                           
  9 T                                   H                                                                                                                           
 10 T                                            H                                                                                                                  
 11  T                                           H                                                                                                                  
 12   T                                           H                                                                                                                 
 13      T                                                 H                                                                                                        
 14         T                                                       H                                                                                               
 15   T                                                              H                                                                                              
 16      T                                                         H                                                                                                
 17       T                                                              H                                                                                          
Yuck, hare wins.                                                                                                                  game 2:
 ...
 98 H                                        T
 99 H                                           T
100          H                                     T
101           H                                     T
102            H                                       T
103          H                                            T
104                   H                                    T
105                 H                                         T
106                  H                                         T
107                  H                                            T
108                  H                                               T
109                   H                                                 T
110                   H                                                  T
Yay!!! tortoise wins!

game 3
  1 H T
  2    T  H
  3      TH
  4        TH
  5         T
Ouch, Tortoise bites Hare.
  6          T
Ouch, Tortoise bites Hare.
It is a tie.
*/

//g++ *.cpp or
//g++ *.cpp -o output
//./output
int main() {
    Competition game;
    game.start(); 

    cout << endl << "game 2" << endl;
    Competition game2;
    game2.start();

    cout << endl << "game 3" << endl;
    int harePattern[] = {6, -3, 2, 0, 0};
    Hare rabbit(harePattern, 
                sizeof(harePattern)/sizeof(harePattern[0]), 0);

    int torPattern[] = {1, 2, 2, -1};
    Tortoise tor(torPattern, 
                 sizeof(torPattern)/sizeof(torPattern[0]), 0);
 
    Competition game3(&rabbit, &tor, 10);
    game3.start();

    return 0;
}