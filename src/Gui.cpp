
#include <agar/agar/core.h>
#include <agar/agar/gui.h>
// AGAR Gui and Events  

void  VM205::Gui(int argc, char **argv) {

	AG_Window *win;
	AG_FixedPlotter *plot;
	
	if (AG_InitCore(NULL, 0) == -1 ||
		AG_InitGraphics(0) == -1) {
			
	fprintf(stderr, "Init failed: %s\n", AG_GetError());
	return (1);
	}
		
		win = AG_WindowNew(0);
		plot = AG_FixedPlotterNew(win, AG_FIXED_PLOTTER_LINES, AG_FIXED_PLOTTER_EXPAND);
		//AG_ObjectAttach(win,plot);
		AG_LabelNew(win, 0, "Hello, plotter!");

		AG_WindowShow(win);
		AG_EventLoop();
		return (0); 
if (AG_InitCore(NULL, 0) == -1 || AG_InitGraphics(0) == -1) {
	fprintf(stderr, "Init failed: %s\n", AG_GetError());
	return (1);
	}		

AG_Window *win;
win = AG_WindowNew(AG_WINDOW_MAIN);

AG_BindStdGlobalKeys();

AG_FixedPlotter *plot;
plot = AG_FixedPlotterNew(win, AG_FIXED_PLOTTER_LINES, AG_FIXED_PLOTTER_SCROLL);
AG_FixedPlotterCurve(plot, "My Curve", 1, 0, 0, 0);



AG_Button *btn;
AG_Event *ev;
btn = AG_ButtonNew(win, 0, "Say Hello");

ev = AG_SetEvent(btn, "button-pushed", SayHello, NULL);
AG_EventPushString(ev, NULL, "World");
AG_EventPushInt(ev, NULL, 0);

AG_WindowUpdate(win);
AG_WindowShow(win);
AG_EventLoop();

printf("Closing down...\n");
AG_DestroyGraphics();
AG_Destroy();

void SayHello(AG_Event *event)
{
	char *s   = AG_STRING(1);  /* From AG_SetEvent() */
	int state = AG_INT(2);     /* From later AG_PostEvent() */

	AG_TextMsg(AG_MSG_INFO, "Hello, %s! (state=%d)", s, state);
}