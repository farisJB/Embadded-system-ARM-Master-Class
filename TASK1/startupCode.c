
extern uint32 __data_load__  ;
extern uint32 __data_start__ ;
extern uint32 __data_end__   ;
extern uint32 __bss_start__  ;
extern uint32 __bss_end__    ;
extern uint32 _stack         ;

void ResetHandler(void)
{
  /*Init Stack pointer: Done By HW */
  
  
  
  uint32 *Ptr2Sbss = (uint32*)&__bss_start__;
  uint32 *Ptr2Ebss = (uint32*)&__bss_end__;
  
  uint32 *Ptr2Src =  (uint32*)&__data_load__;
  uint32 *Ptr2sDes = (uint32*)&__data_start__;
  uint32 *Ptr2eDes = (uint32*)&__data_end__;
  
  /* Init .BSS */
  while(Ptr2Sbss< Ptr2Ebss)
  {
	  *(Ptr2Sbss++) = 0;
  }
  
  
  /*Init .DATA */
	while(Ptr2sDes< Ptr2eDes)
	{
		
		
		*(Ptr2sDes++) = *(Ptr2Src++);
	}
	

	/*jUMB tO MAIN */
	main();
	
	while(1);

}