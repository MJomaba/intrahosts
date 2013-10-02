#include "leaf.h"

struct leaf* leaf_create(int NLeaves)
{
	leaf *l ;
	l=Calloc(1,leaf) ;
	l->lo=Calloc(NLeaves,int) ;
	l->h=Calloc(NLeaves,int) ;
	l->s=Calloc(NLeaves-1,int) ;
	l->NLeaves=NLeaves ;
}

struct leaf* R_to_leaf(SEXP R_lo, SEXP R_s)
{
	SEXP R_lodim ;
	int NLeaves, i, j ;
	leaf *l;
	R_lo=coerceVector(R_lo,INTSXP) ;
	R_s=coerceVector(R_s,INTSXP) ;
	R_lodim=getAttrib(R_lo, R_DimSymbol) ;
	NLeaves = INTEGER(R_lodim)[0];
	l=leaf_create(NLeaves) ;
	for (i=0 ; i< NLeaves ; i++)
	{
		j=i*2 ;
		l->lo[i]=INTEGER(R_lo)[j] ;
		l->h[i]=INTEGER(R_lo)[j+1] ;
	}
	
	for (i=0 ; i< (NLeaves-1) ; i++)
	{
		l->s[i]=INTEGER(R_s)[i] ;
	}
	return l ;
}
<<<<<<< HEAD

=======
/*
>>>>>>> 9efa3e2269dea9d8828b5ae1f850e3feb146b714
int getmostrecentpair(int Ha, int Hb, leaf * l)
{
	// look for the most recent coalescing neighbouring pair in Ha and Hb
	int i, m=l->NLeaves, m_i=-1 ;
	for (i=0 ; i< (l->NLeaves - 2) ; i++)
	{
		if (l[i][3]!=l[i+1][3]) // separate nodes
		{
			if ((l[i][2]==Ha && l[i+1][2]==Hb) || (l[i][2]==Hb && l[i+1][2]==Ha))
			{
				if (l[i][4]>0 && l[i][4]<m)
				{
					m=l[i][4] ;
					m_i=i ;
				}
			}
		}	 
	}
	return m_i ;
<<<<<<< HEAD
}
=======
}*/
>>>>>>> 9efa3e2269dea9d8828b5ae1f850e3feb146b714

struct leaf* leaf_update(double **T, leaf *l)
{
	// update leaves based on new branching times and host-host transmission
	int NNodes=l->NLeaves - 1, **INode, i, t, **L, ha, hb ;
	INode=Calloc(2,int*) ;
	for (i=0 ; i<2 ; i++)
	{
		INode[i]=Calloc(NNodes,int) ;
	}
	
	
	// building table to keep track of leaves
	L = Calloc(l->NLeaves,int*) ;
	for (i=0 ; i<l->NLeaves ; i++)
	{
		L[i] = Calloc(5,int) ;
		L[i][0]=l->lo[i] ; // leaf id
		L[i][1]=i ; // current leaf position
		L[i][2]=l->h[i] ; // leaf host
		L[i][3]=l->lo[i] ; // current node
		L[i][4]=-1 ;
	}
	
	for (i=0 ; i<NNodes ; i++)
	{
		L[l->s[i]][4]=i ;	//order of coalescence.
	}
	
	for (t=0 ; t<NNodes ; t++)
	{
		ha=T[i][2] ;
		hb=T[i][3] ;
		
		
	}
	
	
	
	
	
	for (i=0 ; i<2; i++)
	{
		Free(INode[i]) ;
	}
	Free(INode) ;
}