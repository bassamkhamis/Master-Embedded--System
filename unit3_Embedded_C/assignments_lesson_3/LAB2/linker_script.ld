/* Auther :Bassam
   Date   : feb 4 2022
   
*/

MEMORY
{
flash (rx) : ORIGIN = 0x08000000, LENGTH = 32k
sram (rwx) : ORIGIN = 0x20000000, LENGTH = 10k
}

SECTIONS
{
 .text : {
     *(.vectors*)
     *(.text*)
     *(.rodata)
	 . = ALIGN(4);
      _E_text = . ;
         }>flash

 .data : {
      _S_DATA = . ;
      *(.data)
      . = ALIGN(4);
      _E_DATA = . ;
      
         }>sram AT> flash

 .bss : {
      _S_bss = . ;
     *(.bss)
     _E_bss = . ;
     
     . = . + 0X1000;
     _stack_top = . ;
        }>sram
}