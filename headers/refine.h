/*
 * Copyright <2012> <Vincent Le Guilloux,Peter Schmidtke, Pierre Tuffery>
 * Copyright <2013-2018> <Peter Schmidtke, Vincent Le Guilloux>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 */

#ifndef DH_REFINE
#define DH_REFINE



/* -------------------------------INCLUDES--------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "voronoi.h"
#include "calc.h"
#include "pocket.h"
#include "fparams.h"
#include "psorting.h"

/* -------------------------- PUBLIC STRUCTURES ------------------------------*/


/* --------------------------PROTOTYPES---------------------------------------*/

void refinePockets(c_lst_pockets *pockets, s_fparams *params);
//void apply_clustering(c_lst_pockets *pockets, s_fparams *params);
//c_lst_pockets *apply_clustering(c_lst_pockets *pockets, s_fparams *params);
void apply_clustering_old(c_lst_pockets *pockets, s_fparams *params);
c_lst_pockets *apply_clustering(c_lst_pockets *pockets, s_fparams *params, s_lst_vvertice *lvert);
c_lst_pockets *assign_apply_clustering( s_fparams *params, s_lst_vvertice *lvert);
void reIndexPockets(c_lst_pockets *pockets);
void dropSmallNpolarPockets(c_lst_pockets *pockets, s_fparams *params);
void drop_tiny(c_lst_pockets *pockets, s_fparams *params) ;
void dropSmallPockets(c_lst_pockets *pockets, s_fparams *params);
int cmp_pockets(const node_pocket *p1, const node_pocket *p2);
#endif
