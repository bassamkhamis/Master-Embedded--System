/****************************************************
*   Auther:Bassam                                   *
*   Date  :23-10-2022                               *
*   file  : Rte_SWC1.c                               *
*****************************************************/

/******************************************/
#include<Rte_SWC1.h>
/******************************************/

void SUM(){
	
	 unsigned short x=0,y=0;
	 unsigned z=0;
	 std_ReturnType status =E_NOT_OK;
	 
	 status = Rte_Read_SUM_RPSUM_val1( &x );
	 status = Rte_Read_SUM_RPSUM_val2( &y );
	 z = x + y ;
	 
	 status = Rte_write_SUM_PPSUM_SumResult(z);
	
	
	
	
}