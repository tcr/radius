#ifndef _COROUTINE_H_
#define _COROUTINE_H_

#define scr_begin         static int scrLine = 0; switch(scrLine) { case 0:;
#define scr_finish(z)     } scrLine = 0; return (z)
#define scr_finish_void   } scrLine = 0; return

#define scr_return(z)     \
    do {\
        scrLine=__LINE__;\
        return (z); case __LINE__:;\
    } while (0)
#define scr_return_void       \
    do {\
        scrLine=__LINE__;\
        return; case __LINE__:;\
    } while (0)

#endif
