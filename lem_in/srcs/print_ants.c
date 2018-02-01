nclude "../includes/lem_in.h"

void    ants_walk(t_env *e)
{
	    printf("ants = %d\n", e->nb_ants);
		    printf("paths = %d\n", e->nb_path);
			    printf("chemin 1 = %d\n", e->tab_way->path_master[0].path[0].node);

				/*********************************************************/
				/******************DO THE MATH***************************/
				/*  fourmi = X;
				 *      nb_path = Y;
				 *          size_path = sx;
				 *              path = x;
				 *                  the number of path we want = 666;
				 *                      Total_sx = Tsx = s(0+.+.....+.+x);
				 *
				 *                          AP = ANTS / PATH = (X + Tsx) / Y
				 *
				 *                              x = 0;
				 *                                  AP = 0;
				 *                                      Tsx = 0;
				 *                                          while (x < Y && X > sx) (si sx > forcement le dernier chemin a prendre)
				 *                                                Tsx += sx;
				 *                                                      do the AP;
				 *                                                            if (NAP > AP)
				 *                                                                    666 = x;
				 *                                                                          x++;
				 *
				 *                                                                              for each path
				 *                                                                                  while (ya des fourmi)
				 *                                                                                          balancer fourmi inda pampa (afficher fourmi num (max fourmi - fourmi actuel) + sa\
				 *                                                                                          lle)
				 *
				 *                                                                                          */
				/*********************************************************/
				/******************DO THE MATH***************************/
}
