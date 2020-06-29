#include <graphics.h>
#include<conio.h>

int main()
{
    initgraph(640, 480);

    bool isDown = false;
    int lastX, lastY;

    mouse_msg msg;

    setcolor(GREEN);

    for(; is_run(); )
    {
        msg = getmouse();

        switch (msg.msg)
        {
            case mouse_msg_down:
                lastX = msg.x;
                lastY = msg.y;
                isDown = true;
                break;
            case mouse_msg_up:
                isDown = false;
                break;
            case mouse_msg_move:
                if(isDown)
                {
                    do
                    {
                        line(lastX, lastY, msg.x, msg.y); //绘制当前点和上一个点
                        lastX = msg.x;
                        lastY = msg.y;
                        msg = getmouse();
                    }
                    while(mousemsg()&&msg.is_move());
                    if(msg.is_up())
                    isDown = false;
                }
                break;
        }
    }
    closegraph();
    return 0;
}
