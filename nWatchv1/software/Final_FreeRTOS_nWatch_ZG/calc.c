/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "calc.h"
//#include "menuv2.h"
#include "heading.h"
#include <stdlib.h>


extern volatile int sec;
extern volatile int sec2;

char num[10];
double wynik;
char znak=0;
char s[20];

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Calc", ID_WINDOW_0, 0, 0, 320, 240, 0, 0x0, 0 },
  { MULTIEDIT_CreateIndirect, "Text", ID_TEXT_0, 0, 32, 320, 40, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 3, 72, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_3, 4, 115, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_6, 5, 157, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 66, 72, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_4, 66, 115, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_8, 130, 157, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_2, 128, 72, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_5, 128, 115, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_7, 68, 157, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_9, 191, 115, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_10, 190, 72, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_11, 192, 157, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_12, 193, 200, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_13, 11, 200, 172, 38, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_14, 256, 72, 60, 40, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'Calc'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, 0x00FFFFFF);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    MULTIEDIT_SetText(hItem, "");
    MULTIEDIT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
    MULTIEDIT_SetFont(hItem, GUI_FONT_D24X32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "1");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetText(hItem, "2");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
    BUTTON_SetText(hItem, "3");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
    BUTTON_SetText(hItem, "4");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
    BUTTON_SetText(hItem, "5");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
    BUTTON_SetText(hItem, "6");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_6);
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    BUTTON_SetText(hItem, "7");
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_8);
    BUTTON_SetText(hItem, "9");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_7);
    BUTTON_SetText(hItem, "8");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_9);
    BUTTON_SetText(hItem, "-");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_10);
    BUTTON_SetText(hItem, "+");
    BUTTON_SetFont(hItem, GUI_FONT_D32);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_11);
    BUTTON_SetText(hItem, "*");
    BUTTON_SetFont(hItem, GUI_FONT_32B_ASCII);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_12);
    BUTTON_SetText(hItem, "/");
    BUTTON_SetFont(hItem, GUI_FONT_32B_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_14);
    BUTTON_SetText(hItem, "del");
    BUTTON_SetFont(hItem, GUI_FONT_32B_ASCII);
    //
    // Initialization of 'Button'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_13);
    BUTTON_SetText(hItem, "=");
    BUTTON_SetFont(hItem, GUI_FONT_32B_ASCII);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"1");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
  	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
  	    MULTIEDIT_AddText(hItem,"2");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_2: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
  	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
  	    MULTIEDIT_AddText(hItem,"3");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_3: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"4");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_4: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"5");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_5: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"6");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_6: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"7");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_7: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"8");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_8: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
    	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    	    MULTIEDIT_AddText(hItem,"9");
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_9: // Notifications sent by 'Button'
      switch(NCode)
      {
		  case WM_NOTIFICATION_CLICKED:
		  {
				znak='-';
				hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
				MULTIEDIT_GetText(hItem,num,10);
				wynik=atof(num);
				MULTIEDIT_SetText(hItem,"");
			break;
		  }
      }
      break;
    case ID_BUTTON_10: // Notifications sent by 'Button'
      switch(NCode)
      {
		  case WM_NOTIFICATION_CLICKED:
		  {
			  	znak='+';
				hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
				MULTIEDIT_GetText(hItem,num,10);
				wynik+=atof(num);
				MULTIEDIT_SetText(hItem,"");
				break;
		  }
      }
      break;
    case ID_BUTTON_11: // Notifications sent by 'Button'
        switch(NCode)
        {
		  case WM_NOTIFICATION_CLICKED:
		  {
				znak='*';
				hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
				MULTIEDIT_GetText(hItem,num,10);
				if(wynik)wynik=wynik*atof(num);
				else wynik=atof(num);
				MULTIEDIT_SetText(hItem,"");
			break;
		  }
        }
        break;
    case ID_BUTTON_12: // Notifications sent by 'Button'
        switch(NCode)
        {
		  case WM_NOTIFICATION_CLICKED:
		  {
				znak='/';
				hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
				MULTIEDIT_GetText(hItem,num,10);
				if(wynik)wynik=wynik/atof(num);
				else wynik=atof(num);
				MULTIEDIT_SetText(hItem,"");
			break;
		  }
        }
        break;
    case ID_BUTTON_13: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
  	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
  	    switch(znak)
  	    {
			case '+':
			{
				MULTIEDIT_GetText(hItem,num,10);
				wynik+=atof(num);
				break;
			}
			case '-':
			{
				MULTIEDIT_GetText(hItem,num,10);
				wynik-=atof(num);
				break;
			}
			case '*':
			{
				MULTIEDIT_GetText(hItem,num,10);
				wynik*=atof(num);
				break;
			}
			case '/':
			{
				MULTIEDIT_GetText(hItem,num,10);
				wynik/=atof(num);
				break;
			}
  	    }
  	    sprintf(s,"%0.7f",wynik);
  	    MULTIEDIT_SetText(hItem,s);
  	    wynik=0;
        break;
      }
      break;

      case ID_BUTTON_14: // Notifications sent by 'Button'
        switch(NCode) {
        case WM_NOTIFICATION_CLICKED:
      	    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
      	    MULTIEDIT_SetText(hItem,"");
      	    wynik=0;
      	    znak=0;
          break;
        case WM_NOTIFICATION_RELEASED:
          // USER START (Optionally insert code for reacting on notification message)
          // USER END
          break;
        // USER START (Optionally insert additional code for further notification handling)
        // USER END
        }
        break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
    case WM_PAINT:
    {
  	  taskENTER_CRITICAL();
  	  LCD_BMP("0:dzien.bmp");
  	  taskEXIT_CRITICAL();
    	break;
    }
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateCalc
*/

WM_HWIN CreateCalc(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}


void Calc( void * pvParameters)
{
	WM_HWIN hWincalc;
	hWincalc  = CreateCalc();
	if(Menu_Handle!=NULL)vTaskDelete(Menu_Handle);
	Menu_Handle=NULL;

	while(1)
	{
		if(GUI_PID_IsPressed())
		{
			if(sec2>1000)
			{
				xTaskCreate(Menu,(char const*)"Menu",512,NULL,6,&Menu_Handle);
				xTaskCreate(Heading_Task,(char const*)"Heading",512,NULL, 6, &Heading_Handle);
			}
		}else
		{
			sec2=0;
		}

		vTaskDelay(100);

	}
}