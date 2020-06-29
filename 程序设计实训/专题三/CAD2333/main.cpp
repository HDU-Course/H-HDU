#include<iostream>
#include<stdio.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define MAXELEM 100

int main()
{
	typedef struct coord {
		double x1;
		double y1;
		double x2;
		double y2;
	}coord;

	coord Line[MAXELEM];
	coord Rectangle[MAXELEM];
	coord Ellipse[MAXELEM];
	coord Word[MAXELEM];
	static int temp_l = 0;//分别为 直线/矩形/椭圆/文字 的数目
	static int temp_r = 0;
	static int temp_e = 0;
	static int temp_w = 0;
	initgraph(980, 756);//初始化图形


	setcolor(GREEN);
	for (int i = 54, k = 0; i < 756; i += 30, k++)
	{
		if (k % 5 == 0)
			i += 24;
		rectangle(10, i, 210, i + 30);
	}
	/*虚线部分*/
	setlinestyle(PS_DASH);
	line(220, 0, 220, 756);
	line(0, 60, 980, 60);
	setlinestyle(PS_SOLID);
	/*文字部分*/
	outtextxy(84, 24, "选择界面");
	outtextxy(512, 24, "作图界面");
	outtextxy(102, 83, "直线");
	outtextxy(102, 257, "矩形");
	outtextxy(102, 431, "椭圆");
	outtextxy(102, 605, "文字");
	outtextxy(12, 113, "放置直线");
	outtextxy(12, 143, "删除直线");
	outtextxy(12, 173, "改变大小");
	outtextxy(12, 203, "移动直线");
	outtextxy(12, 292, "放置矩形");
	outtextxy(12, 322, "删除矩形");
	outtextxy(12, 352, "改变大小");
	outtextxy(12, 382, "移动矩形");
	outtextxy(12, 461, "放置椭圆");
	outtextxy(12, 491, "删除椭圆");
	outtextxy(12, 521, "改变大小");
	outtextxy(12, 551, "移动椭圆");
	outtextxy(12, 640, "放置文字");
	outtextxy(12, 670, "删除文字");
	outtextxy(12, 700, "改变大小");
	outtextxy(12, 730, "移动文字");


	/*LINE: 74-709 功能部分*/


	MOUSEMSG m;											// 定义鼠标消息
	while (true)
	{
	Flag_ChoiceAgain:
		double START_X, START_Y, END_X, END_Y;

		m = GetMouseMsg();
		/*作图区单击左键，选择功能*/
		if (m.uMsg == WM_LBUTTONDOWN)
		{

			/*作图区选择直线相关的操作*/
			/*LINE: 88-281 直线操作*/

			if (10 <= m.x && m.x <= 210 && 108 <= m.y && m.y <= 228)
			{
				/*1:放置直线*/
				if (m.y <= 138)
				{
				Flag_LineAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，获取起点
						{
							START_X = m.x;
							START_Y = m.y;
							Line[temp_l].x1 = m.x;
							Line[temp_l].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)//确保起点在作图区内
							{
								m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取终点
								{
									END_X = m.x;
									END_Y = m.y;
									Line[temp_l].x2 = m.x;
									Line[temp_l].y2 = m.y;
									if (END_X >= 220 && END_Y >= 60)//确保终点在作图区内
									{
										setcolor(RED);
										line(START_X, START_Y, END_X, END_Y);
										temp_l++;				//直线的数量加一
										goto Flag_LineAgain;	//重复画线
									}
								}
								else if (m.uMsg == WM_RBUTTONUP)
								{
									goto Flag_ChoiceAgain;
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键回到功能选择区域
							goto Flag_ChoiceAgain;
					}
				}
				/*2:删除直线*/
				else if (m.y <= 168)
				{
				Flag_DeleteAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，删除线段
						{
							int i;
							for (i = 0; i < temp_l; i++)	//遍历直线数组，寻找符合条件的直线
							{
								if (m.x >= 220 && m.y >= 60)//限制区域为作图区域
									if (fabs((Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1) - (Line[i].y2 - m.y) / (Line[i].x2 - m.x)) <= 0.1)//只要是一条直线上，即选中
									{
										setcolor(BLACK);
										line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
										for (int k = i; k < temp_l - 1; k++)//线性存储，所以后续直线需要向前移一位
										{
											Line[k].x1 = Line[k + 1].x1;
											Line[k].y1 = Line[k + 1].y1;
											Line[k].x2 = Line[k + 1].x2;
											Line[k].y2 = Line[k + 1].y2;
										}
										temp_l--;

										goto Flag_DeleteAgain;//重复删除
									}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
				/*3:改变直线大小*/
				else if (m.y <= 198)
				{
				Flag_ChoiceLineAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键,选中线段
						{
							int i;
							for (i = 0; i < temp_l; i++)
							{
								if (m.x >= 220 && m.y >= 60)		//限制区域为作图区域
									if (fabs((Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1) - (Line[i].y2 - m.y) / (Line[i].x2 - m.x)) <= 0.1)//只要是一条直线上，即选中
									{
										double k = (Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1);//计算斜率
									again:
										char ch;
										ch = getch();
										if (ch == 'w')					//键盘w增大
										{
											setcolor(BLACK);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											Line[i].x1 -= 50;
											Line[i].y1 -= 50 * k;
											Line[i].x2 += 50;
											Line[i].y2 += 50 * k;
											setcolor(RED);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											goto again;
										}
										if (ch == 's')			//键盘s减小
										{
											setcolor(BLACK);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											Line[i].x1 += 50;
											Line[i].y1 += 50 * k;
											Line[i].x2 -= 50;
											Line[i].y2 -= 50 * k;
											setcolor(RED);
											line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
											goto again;
										}
										goto Flag_ChoiceLineAgain;
									}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键，重新功能选择
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				/*4:移动直线*/
				else if (m.y <= 228)
				{
				Flag_MoveAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，选择线段
						{
							int i;
							for (i = 0; i < temp_l; i++)		//筛选线段
							{
								if (m.x >= 220 && m.y >= 60)//限制鼠标移动区域为作图区域
									if (fabs((Line[i].y2 - Line[i].y1) / (Line[i].x2 - Line[i].x1) - (Line[i].y2 - m.y) / (Line[i].x2 - m.x)) <= 0.1)//只要是一条直线上，即选中
									{
										double START_X, START_Y, END_X, END_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取终点
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Line[i].x1 += D_x;
													Line[i].x2 += D_x;
													Line[i].y1 += D_y;
													Line[i].y2 += D_y;
													line(Line[i].x1, Line[i].y1, Line[i].x2, Line[i].y2);
													goto Flag_MoveAgain;//重复选择线段移动
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveAgain;//重新选择线段移动
									}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
			}

			/*作图区选择矩形相关的操作*/
			/*LINE: 286-498 矩形操作*/

			if (10 <= m.x && m.x <= 210 && 282 <= m.y && m.y <= 402)
			{
				/*1:放置矩形*/
				if (m.y <= 312)
				{
				Flag_RectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，获取矩形左上顶点
						{
							START_X = m.x;
							START_Y = m.y;
							Rectangle[temp_r].x1 = m.x;
							Rectangle[temp_r].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)//确保起点在作图区内
							{
								m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取矩形右下顶点
								{
									END_X = m.x;
									END_Y = m.y;
									Rectangle[temp_r].x2 = m.x;
									Rectangle[temp_r].y2 = m.y;
									if (END_X >= 220 && END_Y >= 60)//确保终点在作图区内
									{
										setcolor(RED);
										rectangle(START_X, START_Y, END_X, END_Y);
										temp_r++;				//矩形的数量加一
										goto Flag_RectangleAgain;	//重复画矩形
									}
								}
								else if (m.uMsg == WM_RBUTTONUP)
								{

									goto Flag_ChoiceAgain;
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键回到功能选择区域
							goto Flag_ChoiceAgain;
					}
				}
				/*2:删除矩形*/
				else if (m.y <= 342)
				{
				Flag_DeleteRectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，删除矩形
						{
							int i;
							for (i = 0; i < temp_r; i++)	//遍历矩形数组，寻找符合条件的矩形
							{
								if (m.x >= 220 && m.y >= 60)//限制区域为作图区域
								{
									bool a = (fabs(m.x - Rectangle[i].x1) < 5);
									bool b = (fabs(m.x - Rectangle[i].x2) < 5);
									bool c = (fabs(m.y - Rectangle[i].y1) < 5);
									bool d = (fabs(m.y - Rectangle[i].y2) < 5);
									if((a||b)&&(c||d))//点击矩形任一顶点即选中
									{
										setcolor(BLACK);
										rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
										for (int k = i; k < temp_r - 1; k++)//线性存储，所以后续矩形需要向前进一位
										{
											Rectangle[k].x1 = Rectangle[k + 1].x1;
											Rectangle[k].y1 = Rectangle[k + 1].y1;
											Rectangle[k].x2 = Rectangle[k + 1].x2;
											Rectangle[k].y2 = Rectangle[k + 1].y2;
										}
										temp_r--;

										goto Flag_DeleteRectangleAgain;//重复删除
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
				/*3:改变矩形大小*/
				else if (m.y <= 372)
				{
					Flag_ChoiceRectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键,选中矩形
						{
							int i;
							for (i = 0; i < temp_r; i++)
							{
								if (m.x >= 220 && m.y >= 60)		//限制区域为作图区域
								{
									bool a = (fabs(m.x - Rectangle[i].x1) < 5);
									bool b = (fabs(m.x - Rectangle[i].x2) < 5);
									bool c = (fabs(m.y - Rectangle[i].y1) < 5);
									bool d = (fabs(m.y - Rectangle[i].y2) < 5);
									if ((a || b) && (c || d))//点击矩形任一顶点即选中
									{
										double k = (Rectangle[i].y2 - Rectangle[i].y1) / (Rectangle[i].x2 - Rectangle[i].x1);//长宽比
										Again:
										char ch;
										ch = getch();
										if (ch == 'w')					//键盘w增大
										{
											setcolor(BLACK);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											Rectangle[i].x1 -= 50;
											Rectangle[i].y1 -= 50 * k;
											Rectangle[i].x2 += 50;
											Rectangle[i].y2 += 50 * k;
											setcolor(RED);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											goto Again;
										}
										if (ch == 's')			//键盘s减小
										{
											setcolor(BLACK);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											Rectangle[i].x1 += 50;
											Rectangle[i].y1 += 50 * k;
											Rectangle[i].x2 -= 50;
											Rectangle[i].y2 -= 50 * k;
											setcolor(RED);
											rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
											goto Again;
										}
										goto Flag_ChoiceRectangleAgain;
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键，重新功能选择
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				/*4:移动矩形*/
				else if (m.y <= 402)
				{
				Flag_MoveRectangleAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，选择线段
						{
							int i;
							for (i = 0; i < temp_r; i++)		//筛选线段
							{
								if (m.x >= 220 && m.y >= 60)//限制鼠标移动区域为作图区域
								{
									bool a = (fabs(m.x - Rectangle[i].x1) < 5);
									bool b = (fabs(m.x - Rectangle[i].x2) < 5);
									bool c = (fabs(m.y - Rectangle[i].y1) < 5);
									bool d = (fabs(m.y - Rectangle[i].y2) < 5);
									if ((a || b) && (c || d))//点击矩形任一顶点即选中
									{
										double START_X, START_Y, END_X, END_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取终点
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Rectangle[i].x1 += D_x;
													Rectangle[i].x2 += D_x;
													Rectangle[i].y1 += D_y;
													Rectangle[i].y2 += D_y;
													rectangle(Rectangle[i].x1, Rectangle[i].y1, Rectangle[i].x2, Rectangle[i].y2);
													goto Flag_MoveRectangleAgain;//重复选择线段移动
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveAgain;//重新选择线段移动
									}
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
			}

			/*作图区选择椭圆相关的操作*/
			/*LINE: 503-715 椭圆操作*/
			if (10 <= m.x && m.x <= 210 && 456 <= m.y && m.y <= 576)
			{
				/*1:放置椭圆*/
				if (m.y <= 486)
				{
				Flag_EllipseAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，获取起点
						{
							START_X = m.x;
							START_Y = m.y;
							Ellipse[temp_e].x1 = m.x;
							Ellipse[temp_e].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)//确保起点在作图区内
							{
								m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取终点
								{
									END_X = m.x;
									END_Y = m.y;
									Ellipse[temp_e].x2 = m.x;
									Ellipse[temp_e].y2 = m.y;
									if (END_X >= 220 && END_Y >= 60)//确保终点在作图区内
									{
										setcolor(RED);
										ellipse((START_X*0.5+END_X*0.5),START_Y,0, 0, (END_X*0.5-START_X*0.5), (END_Y-START_Y));
										temp_e++;		//直线的数量加一
										goto Flag_EllipseAgain;	//重复画线
									}
								}
								else if (m.uMsg == WM_RBUTTONUP)
								{

									goto Flag_ChoiceAgain;
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键回到功能选择区域
							goto Flag_ChoiceAgain;
					}
				}
				/*2:删除椭圆*/
				else if (m.y <= 516)
				{
				Flag_DeleteEAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，删除椭圆
						{
							int i;
							for (i = 0; i < temp_e; i++)	//遍历椭圆数组，寻找符合条件的直线
							{
								if (m.x >= 220 && m.y >= 60)//限制区域为作图区域
								{
									bool a = (fabs(m.x - Ellipse[i].x1) < 5);
									bool b = (fabs(m.x - Ellipse[i].x2) < 5);
									bool c = (fabs(m.y - Ellipse[i].y1) < 5);
									bool d = (fabs(m.y - Ellipse[i].y2) < 5);
									if((a||b)&&(c||d))//点击椭圆左右任一顶点即选中
									{
										setcolor(BLACK);

										ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
										for (int k = i; k < temp_e - 1; k++)//线性存储，所以后续直线需要向前移一位
										{
											Ellipse[k].x1 = Ellipse[k + 1].x1;
											Ellipse[k].y1 = Ellipse[k + 1].y1;
											Ellipse[k].x2 = Ellipse[k + 1].x2;
											Ellipse[k].y2 = Ellipse[k + 1].y2;
										}
										temp_e--;

										goto Flag_DeleteEAgain;//重复删除
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
				/*3:改变椭圆大小*/
				else if (m.y <= 546)
				{
				Flag_ChoiceEAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键,选中椭圆
						{
							int i;
							for (i = 0; i < temp_e; i++)
							{
								if (m.x >= 220 && m.y >= 60)		//限制区域为作图区域
								{
									bool a = (fabs(m.x - Ellipse[i].x1) < 5);
									bool b = (fabs(m.x - Ellipse[i].x2) < 5);
									bool c = (fabs(m.y - Ellipse[i].y1) < 5);
									bool d = (fabs(m.y - Ellipse[i].y2) < 5);
									if((a||b)&&(c||d))//点击椭圆左右任一顶点即选中
									{
										double k = (Ellipse[i].y2 - Ellipse[i].y1) / (Ellipse[i].x2 - Ellipse[i].x1);//长宽比
									_Eagain:
										char ch;
										ch = getch();
										if (ch == 'w')					//键盘w增大
										{
											setcolor(BLACK);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											Ellipse[i].x1 -= 50;
											Ellipse[i].y1 -= 50 * k;
											Ellipse[i].x2 += 50;
											Ellipse[i].y2 += 50 * k;
											setcolor(RED);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											goto _Eagain;
										}
										if (ch == 's')			//键盘s减小
										{
											setcolor(BLACK);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											Ellipse[i].x1 += 50;
											Ellipse[i].y1 += 50 * k;
											Ellipse[i].x2 -= 50;
											Ellipse[i].y2 -= 50 * k;
											setcolor(RED);
											ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
											goto _Eagain;
										}
										goto Flag_ChoiceEAgain;
									}
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键，重新功能选择
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				/*4:移动椭圆*/
				else if (m.y <= 576)
				{
				Flag_MoveEAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键，选择椭圆
						{
							int i;
							for (i = 0; i < temp_e; i++)		//筛选椭圆
							{
								if (m.x >= 220 && m.y >= 60)//限制鼠标移动区域为作图区域
								{
									bool a = (fabs(m.x - Ellipse[i].x1) < 5);
									bool b = (fabs(m.x - Ellipse[i].x2) < 5);
									bool c = (fabs(m.y - Ellipse[i].y1) < 5);
									bool d = (fabs(m.y - Ellipse[i].y2) < 5);
									if((a||b)&&(c||d))//点击椭圆左右任一顶点即选中
									{
										double START_X, START_Y, END_X, END_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取终点
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Ellipse[i].x1 += D_x;
													Ellipse[i].x2 += D_x;
													Ellipse[i].y1 += D_y;
													Ellipse[i].y2 += D_y;
													ellipse((Ellipse[i].x1*0.5+ Ellipse[i].x2*0.5),Ellipse[i].y1,0,0, (Ellipse[i].x2*0.5-Ellipse[i].x1*0.5), (Ellipse[i].y2-Ellipse[i].y1));
													goto Flag_MoveEAgain;//重复选择椭圆移动
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveEAgain;//重新选择椭圆移动
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}
			}

			//作文字
			if (10 <= m.x && m.x <= 210 && 635 <= m.y && m.y <= 745)
            {
                char ch;
                if(m.y<665)
                {
                    Flag_WordAgain:
                    while(true)
                    {
                        m = GetMouseMsg();
                        if (m.uMsg == WM_LBUTTONDOWN)
                        {
                            START_X = m.x;
							START_Y = m.y;
							Word[temp_w].x1 = m.x;
							Word[temp_w].y1 = m.y;
							while (START_X >= 220 && START_Y >= 60)
                            {
                                m = GetMouseMsg();
								if (m.uMsg == WM_LBUTTONUP)
                                {


                                    if (START_X >= 220 && START_Y >= 60)
                                        {
                                moveto(START_X,START_Y);

                                setcolor(RED);
                                ch = getch();
                                xyprintf(START_X,START_Y,&ch);
                                temp_w++;
                                goto Flag_WordAgain;
                                        }
                                }


                        else if (m.uMsg == WM_RBUTTONUP)
                        {
                            goto Flag_ChoiceAgain;
                        }
                            }
                        }
                    else if (m.uMsg == WM_RBUTTONDOWN)//单击右键回到功能选择区域
							goto Flag_ChoiceAgain;
                }
            }


            else if (m.y <= 695)
				{
				Flag_DeleteWordAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							int i;
							for (i = 0; i < temp_w; i++)
							{
								if (m.x >= 220 && m.y >= 60)//限制区域为作图区域
								{
									bool a = (fabs(m.x - Word[i].x1) < 5);
									bool b = (fabs(m.x - Word[i].x2) < 5);
									if((a||b))
									{
										setcolor(BLACK);
                                        xyprintf(Word[i].x1,Word[i].y1,&ch);
										for (int k = i; k < temp_w - 1; k++)
										{
											Word[k].x1 = Word[k + 1].x1;
											Word[k].y1 = Word[k + 1].y1;
										}
										temp_w--;
										goto Flag_DeleteWordAgain;//重复删除
									}
								}
							}
						}

                    }
                }


//缩放
            else if (m.y <= 725)
				{
				Flag_ChoiceWAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)
						{
							int i;
							for (i = 0; i < temp_w; i++)
							{
								if (m.x >= 220 && m.y >= 60)
								{
									bool a = (fabs(m.x - Word[i].x1) < 5);
									bool b = (fabs(m.y - Word[i].y1) < 5);
									if(a||b)//
									{
									    _Wagain:
										char s;
										s = getch();
										if (s == 'w')					//键盘w增大
										{
											setcolor(BLACK);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											LOGFONTA f;
											getfont(&f);
											f.lfHeight+=4;
											setfont(f.lfHeight, 0,"宋体");
											setcolor(RED);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											goto _Wagain;
										}
										if (s == 's')					//键盘w增大
										{
											setcolor(BLACK);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											LOGFONTA f;
											getfont(&f);
											f.lfHeight-=4;
											setfont(f.lfHeight, 0,"宋体");
											setcolor(RED);
											xyprintf(Word[i].x1,Word[i].y1,&ch);
											goto _Wagain;
										}
										goto Flag_ChoiceWAgain;
									}
								}

							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键，重新功能选择
						{

							goto Flag_ChoiceAgain;
						}

					}
				}
				//移动
            else if (m.y <= 745)
				{
				Flag_MoveWAgain:
					while (true)
					{
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN)		//单击左键
						{
							int i;
							for (i = 0; i < temp_w; i++)		//筛选
							{
								if (m.x >= 220 && m.y >= 60)//限制鼠标移动区域为作图区域
								{
									bool a = (fabs(m.x - Word[i].x1) < 5);
									bool b = (fabs(m.y - Word[i].y1) < 5);
									if((a||b))//点
									{
										double START_X, START_Y;
										START_X = m.x;
										START_Y = m.y;
										setcolor(BLACK);
										xyprintf(Word[i].x1,Word[i].y1,&ch);
										while (START_X >= 220 && START_Y >= 60)
										{
											m = GetMouseMsg();
											if (m.uMsg == WM_LBUTTONUP)//左键弹起，获取终点
											{
												END_X = m.x;
												END_Y = m.y;
												if (END_X >= 220 && END_Y >= 60)
												{
													setcolor(RED);
													double D_x = END_X - START_X;
													double D_y = END_Y - START_Y;
													Word[i].x1 += D_x;
													Word[i].y1 += D_y;

													xyprintf(Word[i].x1,Word[i].y1,&ch);
													goto Flag_MoveWAgain;//重复选择椭圆移动
												}
											}
											else if (m.uMsg == WM_RBUTTONUP)
											{

												goto Flag_ChoiceAgain;
											}
										}
										goto Flag_MoveWAgain;//重新选择椭圆移动
									}
								}
							}
						}
						else if (m.uMsg == WM_RBUTTONDOWN)//单击右键,回到功能选择界面
						{

							goto Flag_ChoiceAgain;
						}
					}
				}



            }//作文字
		}

		}

	getch();
	closegraph();

	return 0;
}
