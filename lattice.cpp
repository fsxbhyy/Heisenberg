#include "head.h"
#include <iostream>
/*double Spin::LA[Sub][TotalNeighbor][4]={{{0,0,1,1},{0,0,2,1},{1,-1,1,1},{0,-1,2,1}}, 
                                        {{0,0,2,1},{0,0,0,1},{-1,1,0,1},{-1,0,2,1}},
                                        {{0,0,1,1},{0,0,0,1},{0,1,0,1},{1,0,1,1}}}; *///kagome


double Spin::LA[Sub][TotalNeighbor][4]={{{1,0,0,1},{0,1,0,1},{-1,0,0,1},{0,-1,0,1},                   
  					{1,1,0,-0.4},{1,-1,0,-0.4},{-1,1,0,-0.4},{-1,-1,0,-0.4}}};//square

/*double Spin::LA[Sub][TotalNeighbor][4]={{{0,0,1,1},{0,0,2,1},{1,-1,1,1},{0,-1,2,1}},//whatever
                                        {{0,0,2,1},{0,0,0,1},{-1,1,0,1},{-1,0,2,1}},
                                        {{0,0,1,1},{0,0,0,1},{0,1,0,1},{1,0,1,1}}};*/


