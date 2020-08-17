/*Pay Supreme Tribute to Comrade VLADIMIR ILLICH LENIN!*/
/*§°§ä§Õ§Ñ§Û§ä§Ö §Õ§à§Ý§Ø§ß§à§Ö §ä§à§Ó§Ñ§â§Ú§ë§å §£§Ý§Ñ§Õ§Ú§Þ§Ú§â§å §ª§Ý§î§Ú§é§å §­§Ö§ß§Ú§ß§å!*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> clean(vector<int>a, int object)
{
	a.erase(find(a.begin(), a.end(), object));
	return a;
}
int fd(vector<int>a,int pos)
{
	if (find(a.begin(), a.end(), pos) == a.end())return 0;
	else return 1;
}
int fddirection(vector<int>me, vector<int>emp, int pos)
{
	int flag=0;
	for (int m = 0; m < 4; m++)
	{
		int x;
		if (m == 0) x = 1;
		else if (m == 1)x = 100;
		else if (m == 2)x = 101;
		else x = 99;
		int a = -4 * x, b = -3 * x, c = -2 * x, d = -1 * x, f = 1 * x, g = 2 * x, h = 3 * x, i = 4 * x;
		int one = (fd(emp, pos + a) == 1) + (fd(me, pos + b) == 1) + (fd(me, pos + c) == 1) + (fd(emp, pos + d) == 1) + (fd(emp, pos + f) == 1);
		int	two = (fd(emp, pos + b) == 1) + (fd(me, pos + c) == 1) + (fd(me, pos + d) == 1) + (fd(emp, pos + f) == 1);
		int three = (fd(emp, pos + a) == 1) + (fd(me, pos + b) == 1) + (fd(emp, pos + c) == 1) + (fd(me, pos + d) == 1)+(fd(emp, pos + f) == 1);
		int	four = (fd(emp, pos + c) == 1) + (fd(me, pos + d) == 1) + (fd(me, pos + f) == 1) + (fd(emp, pos + g) == 1);
		int	five = (fd(emp, pos + d) == 1) + (fd(me, pos + f) == 1) + (fd(me, pos + g) == 1) + (fd(emp, pos + h) == 1);
		int	six = (fd(emp, pos + d) == 1) + (fd(emp, pos + f) == 1) + (fd(me, pos + g) == 1) + (fd(me, pos + h) == 1) + (fd(emp, pos + i) == 1);
		int	seven = (fd(emp, pos + d) == 1) + (fd(me, pos + f) == 1) + (fd(emp, pos + g) == 1) + (fd(me, pos + h) == 1) + (fd(emp, pos + i) == 1);
		int eight= (fd(emp, pos + c) == 1) + (fd(me, pos + d) == 1) + (fd(emp, pos + f) == 1) + (fd(me, pos + g) == 1) + (fd(emp, pos + h) == 1);
		int nine = (fd(emp, pos + b) == 1) + (fd(me, pos + c) == 1) + (fd(emp, pos + d) == 1) + (fd(me, pos + f) == 1) + (fd(emp, pos + g) == 1);
		
		if ((one == 5) || (two == 4) || (three == 5) || (four == 4) || (five == 4) || (six == 5) || (seven == 5)||(eight==5)||(nine==5))
		{
			flag++;
		}
	}
	if (flag >= 2) { return 0; }
	else return 1;
}
int eval(const vector<int>me, const vector<int>he, const vector<int>emp)
{
	int a[21] = { 0,
		10000000,400000,-1000000,-1000000,90,
		-500,90,-40,30,-60,
		50,-350000,55,-40,20,
		-60,15,90,-1000000,-1000000 };
	int score = 0;
	const int my = me.size();
	const int his = he.size();

	for (int i = 0; i < my; ++i)
	{
		//1
		int flag1_horizonal =
			fd(me, me[i] + 1) + fd(me, me[i] + 2) + fd(me, me[i] - 1) + fd(me, me[i] - 2);
		int flag1_vertical =
			fd(me, me[i] + 100) + fd(me, me[i] + 200) + fd(me, me[i] - 100) + fd(me, me[i] - 200);
		int flag1_uldr =
			fd(me, me[i] + 101) + fd(me, me[i] + 202) + fd(me, me[i] - 101) + fd(me, me[i] - 202);
		int flag1_urdl =
			fd(me, me[i] + 99) + fd(me, me[i] + 198) + fd(me, me[i] - 99) + fd(me, me[i] - 198);
		if (flag1_horizonal == 4 || flag1_uldr == 4 || flag1_urdl == 4 || flag1_vertical == 4) { score = score + a[1]; }
		//2
		int flag2_horizonal =
			fd(me, me[i] + 1) + fd(me, me[i] + 2) + fd(me, me[i] - 1) + fd(emp, me[i] - 2) + fd(emp, me[i] + 3);
		int flag2_vertical =
			fd(me, me[i] + 100) + fd(me, me[i] + 200) + fd(me, me[i] - 100) + fd(emp, me[i] - 200) + fd(emp, me[i] + 300);
		int flag2_uldr =
			fd(me, me[i] + 101) + fd(me, me[i] + 202) + fd(me, me[i] - 101) + fd(emp, me[i] - 202) + fd(emp, me[i] + 303);
		int flag2_urdl =
			fd(me, me[i] + 99) + fd(me, me[i] + 198) + fd(me, me[i] - 99) + fd(emp, me[i] - 198) + fd(emp, me[i] + 297);
		int score2 = ((flag2_horizonal == 5) + (flag2_uldr == 5) + (flag2_urdl == 5) + (flag2_vertical == 5))*a[2];
		score = score + score2;
		//5
		int flag5_horizonala =
			fd(me, me[i] + 1) + fd(me, me[i] + 2) + fd(me, me[i] - 1) + fd(he, me[i] - 2) + fd(emp, me[i] + 3);
		int flag5_horizonalb =
			fd(me, me[i] + 1) + fd(me, me[i] + 2) + fd(me, me[i] - 1) + fd(emp, me[i] - 2) + fd(he, me[i] + 3);
		int flag5_verticala =
			fd(me, me[i] + 100) + fd(me, me[i] + 200) + fd(me, me[i] - 100) + fd(he, me[i] - 200) + fd(emp, me[i] + 300);
		int flag5_verticalb =
			fd(me, me[i] + 100) + fd(me, me[i] + 200) + fd(me, me[i] - 100) + fd(emp, me[i] - 200) + fd(he, me[i] + 300);
		int flag5_uldra =
			fd(me, me[i] + 101) + fd(me, me[i] + 202) + fd(me, me[i] - 101) + fd(he, me[i] - 202) + fd(emp, me[i] + 303);
		int flag5_uldrb =
			fd(me, me[i] + 101) + fd(me, me[i] + 202) + fd(me, me[i] - 101) + fd(emp, me[i] - 202) + fd(he, me[i] + 303);
		int flag5_urdla =
			fd(me, me[i] + 99) + fd(me, me[i] + 198) + fd(me, me[i] - 99) + fd(he, me[i] - 198) + fd(emp, me[i] + 297);
		int flag5_urdlb =
			fd(me, me[i] + 99) + fd(me, me[i] + 198) + fd(me, me[i] - 99) + fd(emp, me[i] - 198) + fd(he, me[i] + 297);

		int score5 = ((flag5_horizonalb == 5) + (flag5_uldrb == 5) + (flag5_urdlb == 5) + (flag5_verticalb == 5) + (flag5_horizonala == 5) + (flag5_uldra == 5) + (flag5_urdla == 5) + (flag5_verticala == 5)) * a[5];
		score = score + score5;
		//7
		int flag7_horizonal =
			fd(me, me[i] + 1) + fd(me, me[i] - 1) + fd(emp, me[i] - 2) + fd(emp, me[i] + 2);
		int flag7_vertical =
			fd(me, me[i] + 100) + fd(me, me[i] - 100) + fd(emp, me[i] - 200) + fd(emp, me[i] + 200);
		int flag7_uldr =
			fd(me, me[i] + 101) + fd(me, me[i] - 101) + fd(emp, me[i] - 202) + fd(emp, me[i] + 202);
		int flag7_urdl =
			fd(me, me[i] + 99) + fd(me, me[i] - 99) + fd(emp, me[i] - 198) + fd(emp, me[i] + 198);
		int score7 = ((flag7_horizonal == 4) + (flag7_uldr == 4) + (flag7_urdl == 4) + (flag7_vertical == 4)) * a[7];
		score = score + score7;
		//9
		int flag9_horizonala =
			fd(me, me[i] + 1) + fd(me, me[i] - 1) + fd(me, me[i] - 2) + fd(emp, me[i] + 2) + fd(emp, me[i] + 3);
		int flag9_horizonalb =
			fd(me, me[i] + 1) + fd(me, me[i] - 1) + fd(emp, me[i] - 2) + fd(me, me[i] + 2) + fd(emp, me[i] - 3);
		int flag9_verticala =
			fd(me, me[i] + 100) + fd(me, me[i] - 100) + fd(me, me[i] - 200) + fd(emp, me[i] + 200) + fd(emp, me[i] + 300);
		int flag9_verticalb =
			fd(me, me[i] + 100) + fd(me, me[i] - 100) + fd(emp, me[i] - 200) + fd(me, me[i] + 200) + fd(emp, me[i] - 300);
		int flag9_uldra =
			fd(me, me[i] + 101) + fd(me, me[i] - 101) + fd(me, me[i] - 202) + fd(emp, me[i] + 202) + fd(emp, me[i] + 303);
		int flag9_uldrb =
			fd(me, me[i] + 101) + fd(me, me[i] - 101) + fd(emp, me[i] - 202) + fd(me, me[i] + 202) + fd(emp, me[i] - 303);
		int flag9_urdla =
			fd(me, me[i] + 99) + fd(me, me[i] - 99) + fd(me, me[i] - 198) + fd(emp, me[i] + 198) + fd(emp, me[i] + 297);
		int flag9_urdlb =
			fd(me, me[i] + 99) + fd(me, me[i] - 99) + fd(emp, me[i] - 198) + fd(me, me[i] + 198) + fd(emp, me[i] - 297);

		int score9 = ((flag9_horizonalb == 5) + (flag9_uldrb == 5) + (flag9_urdlb == 5) + (flag9_verticalb == 5) + (flag9_horizonala == 5) + (flag9_uldra == 5) + (flag9_urdla == 5) + (flag9_verticala == 5)) * a[9];
		score = score + score9;
		//11
		int flag11_horizonal =
			fd(me, me[i] + 1) + fd(emp, me[i] - 1) + fd(emp, me[i] + 2);
		int flag11_vertical =
			fd(me, me[i] + 100) + fd(emp, me[i] - 100) + fd(emp, me[i] + 200);
		int flag11_uldr =
			fd(me, me[i] + 101) + fd(emp, me[i] - 101) + fd(emp, me[i] + 202);
		int flag11_urdl =
			fd(me, me[i] + 99) + fd(emp, me[i] - 99) + fd(emp, me[i] + 198);
		int score11 = ((flag11_horizonal == 3) + (flag11_uldr == 3) + (flag11_urdl == 3) + (flag11_vertical == 3)) * a[11];
		score = score + score11;
		//13
		int flag13_horizonala =
			fd(me, me[i] + 1) + fd(emp, me[i] + 2) + fd(me, me[i] + 3) + fd(emp, me[i] + 4) + fd(emp, me[i] - 1);
		int flag13_horizonalb =
			fd(emp, me[i] + 1) + fd(me, me[i] + 2) + fd(me, me[i] + 3) + fd(emp, me[i] + 4) + fd(emp, me[i] - 1);
		int flag13_verticala =
			fd(me, me[i] + 100) + fd(emp, me[i] + 200) + fd(me, me[i] + 300) + fd(emp, me[i] + 400) + fd(emp, me[i] - 100);
		int flag13_verticalb =
			fd(emp, me[i] + 100) + fd(me, me[i] + 200) + fd(me, me[i] + 300) + fd(emp, me[i] + 400) + fd(emp, me[i] - 100);
		int flag13_uldra =
			fd(me, me[i] + 101) + fd(emp, me[i] + 202) + fd(me, me[i] + 303) + fd(emp, me[i] + 404) + fd(emp, me[i] - 101);
		int flag13_uldrb =
			fd(emp, me[i] + 101) + fd(me, me[i] + 202) + fd(me, me[i] + 303) + fd(emp, me[i] + 404) + fd(emp, me[i] - 101);
		int flag13_urdla =
			fd(me, me[i] + 99) + fd(emp, me[i] + 198) + fd(me, me[i] + 297) + fd(emp, me[i] + 396) + fd(emp, me[i] - 99);
		int flag13_urdlb =
			fd(emp, me[i] + 99) + fd(me, me[i] + 198) + fd(me, me[i] + 297) + fd(emp, me[i] + 396) + fd(emp, me[i] - 99);

		int score13 = ((flag13_horizonalb == 5) + (flag13_uldrb == 5) + (flag13_urdlb == 5) + (flag13_verticalb == 5) + (flag13_horizonala == 5) + (flag13_uldra == 5) + (flag13_urdla == 5) + (flag13_verticala == 5)) * a[13];
		score = score + score13;
		//14
		int flag14_horizonala =
			fd(me, me[i] + 1) + fd(emp, me[i] + 2) + fd(me, me[i] - 1) + fd(emp, me[i] - 2) + fd(he, me[i] + 3);
		int flag14_horizonalb =
			fd(me, me[i] + 1) + fd(emp, me[i] + 2) + fd(me, me[i] - 1) + fd(emp, me[i] - 2) + fd(he, me[i] - 3);
		int flag14_verticala =
			fd(me, me[i] + 100) + fd(emp, me[i] + 200) + fd(me, me[i] - 100) + fd(emp, me[i] - 200) + fd(he, me[i] + 300);
		int flag14_verticalb =
			fd(me, me[i] + 100) + fd(emp, me[i] + 200) + fd(me, me[i] - 100) + fd(emp, me[i] - 200) + fd(he, me[i] - 300);
		int flag14_uldra =
			fd(me, me[i] + 101) + fd(emp, me[i] + 202) + fd(me, me[i] - 101) + fd(emp, me[i] - 202) + fd(he, me[i] + 303);
		int flag14_uldrb =
			fd(me, me[i] + 101) + fd(emp, me[i] + 202) + fd(me, me[i] - 101) + fd(emp, me[i] - 202) + fd(he, me[i] - 303);
		int flag14_urdla =
			fd(me, me[i] + 99) + fd(emp, me[i] + 198) + fd(me, me[i] - 99) + fd(emp, me[i] - 198) + fd(he, me[i] + 297);
		int flag14_urdlb =
			fd(me, me[i] + 99) + fd(emp, me[i] + 198) + fd(me, me[i] - 99) + fd(emp, me[i] - 198) + fd(he, me[i] - 297);

		int score14 = ((flag14_horizonalb == 5) + (flag14_uldrb == 5) + (flag14_urdlb == 5) + (flag14_verticalb == 5) + (flag14_horizonala == 5) + (flag14_uldra == 5) + (flag14_urdla == 5) + (flag14_verticala == 5)) * a[14];
		score = score + score14;
		//17
		int flag17_horizonal =
			fd(emp, me[i] + 1) + fd(emp, me[i] - 1) + fd(me, me[i] + 2) + fd(emp, me[i] + 3);
		int flag17_vertical =
			fd(emp, me[i] + 100) + fd(emp, me[i] - 100) + fd(me, me[i] + 200) + fd(emp, me[i] + 300);
		int flag17_uldr =
			fd(emp, me[i] + 101) + fd(emp, me[i] - 101) + fd(me, me[i] + 202) + fd(emp, me[i] + 303);
		int flag17_urdl =
			fd(emp, me[i] + 99) + fd(emp, me[i] - 99) + fd(me, me[i] + 198) + fd(emp, me[i] + 297);
		int score17 = ((flag17_horizonal == 4) + (flag17_uldr == 4) + (flag17_urdl == 4) + (flag17_vertical == 4)) * a[17];
		score = score + score17;
		//18
		int flag18_horizonal =
			fd(emp, me[i] + 1) + fd(me, me[i] - 1) + fd(me, me[i] + 2) + fd(me, me[i] + 3);
		int flag18_vertical =
			fd(emp, me[i] + 100) + fd(me, me[i] - 100) + fd(me, me[i] + 200) + fd(me, me[i] + 300);
		int flag18_uldr =
			fd(emp, me[i] + 101) + fd(me, me[i] - 101) + fd(me, me[i] + 202) + fd(me, me[i] + 303);
		int flag18_urdl =
			fd(emp, me[i] + 99) + fd(me, me[i] - 99) + fd(me, me[i] + 198) + fd(me, me[i] + 297);
		int score18 = ((flag18_horizonal == 4) + (flag18_uldr == 4) + (flag18_urdl == 4) + (flag18_vertical == 4)) * a[18];
		score = score + score18;
		
	}

	for (int i = 0; i < his; ++i)
	{
		//3
		int flag3_horizonala =
			fd(he, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] - 1) + fd(emp, he[i] - 2) ;
		int flag3_horizonalb =
			fd(he, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] - 1) +  fd(emp, he[i] + 3);
		int flag3_verticala =
			fd(he, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] - 100) + fd(emp, he[i] - 200) ;
		int flag3_verticalb =
			fd(he, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] - 100) +  fd(emp, he[i] + 300);
		int flag3_uldra =
			fd(he, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] - 101) + fd(emp, he[i] - 202);
		int flag3_uldrb =
			fd(he, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] - 101) +  fd(emp, he[i] + 303);
		int flag3_urdla =
			fd(he, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] - 99) + fd(emp, he[i] - 198) ;
		int flag3_urdlb =
			fd(he, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] - 99) +  fd(emp, he[i] + 297);
		int score3 = ((flag3_horizonala == 4) + (flag3_uldra == 4) + (flag3_urdla == 4) + (flag3_verticala == 4)+ (flag3_horizonalb == 4) + (flag3_uldrb == 4) + (flag3_urdlb == 4) + (flag3_verticalb == 4)) * a[3];
		score = score + score3;
		//4
		int flag4_horizonala =
			fd(he, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] - 1) + fd(me, he[i] - 2) + fd(emp, he[i] + 3);
		int flag4_horizonalb =
			fd(he, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] - 1) + fd(emp, he[i] - 2) + fd(me, he[i] + 3);
		int flag4_verticala =
			fd(he, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] - 100) + fd(me, he[i] - 200) + fd(emp, he[i] + 300);
		int flag4_verticalb =
			fd(he, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] - 100) + fd(emp, he[i] - 200) + fd(me, he[i] + 300);
		int flag4_uldra =
			fd(he, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] - 101) + fd(me, he[i] - 202) + fd(emp, he[i] + 303);
		int flag4_uldrb =
			fd(he, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] - 101) + fd(emp, he[i] - 202) + fd(me, he[i] + 303);
		int flag4_urdla =
			fd(he, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] - 99) + fd(me, he[i] - 198) + fd(emp, he[i] + 297);
		int flag4_urdlb =
			fd(he, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] - 99) + fd(emp, he[i] - 198) + fd(me, he[i] + 297);

		int score4 = ((flag4_horizonalb == 5) + (flag4_uldrb == 5) + (flag4_urdlb == 5) + (flag4_verticalb == 5) + (flag4_horizonala == 5) + (flag4_uldra == 5) + (flag4_urdla == 5) + (flag4_verticala == 5)) * a[4];
		score = score + score4;
		//6
		int flag6_horizonal =
			fd(he, he[i] + 1) + fd(he, he[i] - 1) + fd(emp, he[i] - 2) + fd(emp, he[i] + 2);
		int flag6_vertical =
			fd(he, he[i] + 100) + fd(he, he[i] - 100) + fd(emp, he[i] - 200) + fd(emp, he[i] + 200);
		int flag6_uldr =
			fd(he, he[i] + 101) + fd(he, he[i] - 101) + fd(emp, he[i] - 202) + fd(emp, he[i] + 202);
		int flag6_urdl =
			fd(he, he[i] + 99) + fd(he, he[i] - 99) + fd(emp, he[i] - 198) + fd(emp, he[i] + 198);
		int score6 = ((flag6_horizonal == 4) + (flag6_uldr == 4) + (flag6_urdl == 4) + (flag6_vertical == 4)) * a[6];
		score = score + score6;
		//8
		int flag8_horizonala =
			fd(he, he[i] + 1) + fd(he, he[i] - 1) + fd(me, he[i] - 2) + fd(emp, he[i] + 2) + fd(emp, he[i] + 3);
		int flag8_horizonalb =
			fd(he, he[i] + 1) + fd(he, he[i] - 1) + fd(emp, he[i] - 2) + fd(me, he[i] + 2) + fd(emp, he[i] -3);
		int flag8_verticala =
			fd(he, he[i] + 100) + fd(he, he[i] - 100) + fd(me, he[i] - 200) + fd(emp, he[i] + 200) + fd(emp, he[i] + 300);
		int flag8_verticalb =
			fd(he, he[i] + 100) + fd(he, he[i] - 100) + fd(emp, he[i] - 200) + fd(me, he[i] + 200) + fd(emp, he[i] -300);
		int flag8_uldra =
			fd(he, he[i] + 101) + fd(he, he[i] - 101) + fd(me, he[i] - 202) + fd(emp, he[i] + 202) + fd(emp, he[i] + 303);
		int flag8_uldrb =
			fd(he, he[i] + 101) + fd(he, he[i] - 101) + fd(emp, he[i] - 202) + fd(me, he[i] + 202) + fd(emp, he[i] -303);
		int flag8_urdla =
			fd(he, he[i] + 99) + fd(he, he[i] - 99) + fd(me, he[i] - 198) + fd(emp, he[i] + 198)+fd(emp,he[i] + 297);
		int flag8_urdlb =
			fd(he, he[i] + 99) + fd(he, he[i] - 99) + fd(emp, he[i] - 198) + fd(me, he[i] + 198)+ fd(emp, he[i] - 297);

		int score8 = ((flag8_horizonalb == 5) + (flag8_uldrb == 5) + (flag8_urdlb == 5) + (flag8_verticalb == 5) + (flag8_horizonala == 5) + (flag8_uldra == 5) + (flag8_urdla == 5) + (flag8_verticala == 5)) * a[8];
		score = score + score8;
		//10
		int flag10_horizonal =
			fd(he, he[i] + 1) + fd(emp, he[i] - 1) + fd(emp, he[i] + 2);
		int flag10_vertical =
			fd(he, he[i] + 100) + fd(emp, he[i] - 100) + fd(emp, he[i] + 200);
		int flag10_uldr =
			fd(he, he[i] + 101) + fd(emp, he[i] - 101) + fd(emp, he[i] + 202);
		int flag10_urdl =
			fd(he, he[i] + 99) + fd(emp, he[i] - 99) + fd(emp, he[i] + 198);
		int score10 = ((flag10_horizonal == 3) + (flag10_uldr == 3) + (flag10_urdl == 3) + (flag10_vertical == 3)) * a[10];
		score = score + score10;
		//12
		int flag12_horizonala =
			fd(he, he[i] + 1) + fd(emp, he[i] + 2) + fd(he, he[i] + 3) + fd(emp, he[i] + 4) + fd(emp, he[i] - 1);
		int flag12_horizonalb =
			fd(emp, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] + 3) + fd(emp, he[i] + 4) + fd(emp, he[i] - 1);
		int flag12_verticala =
			fd(he, he[i] + 100) + fd(emp, he[i] + 200) + fd(he, he[i] + 300) + fd(emp, he[i] + 400) + fd(emp, he[i] - 100);
		int flag12_verticalb =
			fd(emp, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] + 300) + fd(emp, he[i] + 400) + fd(emp, he[i] - 100);
		int flag12_uldra =
			fd(he, he[i] + 101) + fd(emp, he[i] + 202) + fd(he, he[i] + 303) + fd(emp, he[i] + 404) + fd(emp, he[i] - 101);
		int flag12_uldrb =
			fd(emp, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] + 303) + fd(emp, he[i] + 404) + fd(emp, he[i] - 101);
		int flag12_urdla =
			fd(he, he[i] + 99) + fd(emp, he[i] + 198) + fd(he, he[i] + 297) + fd(emp, he[i] + 396) + fd(emp, he[i] - 99);
		int flag12_urdlb =
			fd(emp, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] + 297) + fd(emp, he[i] + 396) + fd(emp, he[i] - 99);

		int score12 = ((flag12_horizonalb == 5) + (flag12_uldrb == 5) + (flag12_urdlb == 5) + (flag12_verticalb == 5) + (flag12_horizonala == 5) + (flag12_uldra == 5) + (flag12_urdla == 5) + (flag12_verticala == 5)) * a[12];
		score = score + score12;
		//15
		int flag15_horizonala =
			fd(he, he[i] + 1) + fd(emp, he[i] + 2) + fd(he, he[i] - 1) + fd(emp, he[i] - 2) + fd(me, he[i] + 3);
		int flag15_horizonalb =
			fd(he, he[i] + 1) + fd(emp, he[i] + 2) + fd(he, he[i] - 1) + fd(emp, he[i] - 2) + fd(me, he[i] - 3);
		int flag15_verticala =
			fd(he, he[i] + 100) + fd(emp, he[i] + 200) + fd(he, he[i] - 100) + fd(emp, he[i] - 200) + fd(me, he[i] + 300);
		int flag15_verticalb =
			fd(he, he[i] + 100) + fd(emp, he[i] + 200) + fd(he, he[i] - 100) + fd(emp, he[i] - 200) + fd(me, he[i] - 300);
		int flag15_uldra =
			fd(he, he[i] + 101) + fd(emp, he[i] + 202) + fd(he, he[i] - 101) + fd(emp, he[i] - 202) + fd(me, he[i] + 303);
		int flag15_uldrb =
			fd(he, he[i] + 101) + fd(emp, he[i] + 202) + fd(he, he[i] - 101) + fd(emp, he[i] - 202) + fd(me, he[i] - 303);
		int flag15_urdla =
			fd(he, he[i] + 99) + fd(emp, he[i] + 198) + fd(he, he[i] - 99) + fd(emp, he[i] - 198) + fd(me, he[i] + 297);
		int flag15_urdlb =
			fd(he, he[i] + 99) + fd(emp, he[i] + 198) + fd(he, he[i] - 99) + fd(emp, he[i] - 198) + fd(me, he[i] - 297);
		int score15 = ((flag15_horizonalb == 5) + (flag15_uldrb == 5) + (flag15_urdlb == 5) + (flag15_verticalb == 5) + (flag15_horizonala == 5) + (flag15_uldra == 5) + (flag15_urdla == 5) + (flag15_verticala == 5)) * a[15];
		score = score + score15;
		//16
		int flag16_horizonal =
			fd(emp, he[i] + 1) + fd(emp, he[i] - 1) + fd(he, he[i] + 2) + fd(emp, he[i] + 3);
		int flag16_vertical =
			fd(emp, he[i] + 100) + fd(emp, he[i] - 100) + fd(he, he[i] + 200) + fd(emp, he[i] + 300);
		int flag16_uldr =
			fd(emp, he[i] + 101) + fd(emp, he[i] - 101) + fd(he, he[i] + 202) + fd(emp, he[i] + 303);
		int flag16_urdl =
			fd(emp, he[i] + 99) + fd(emp, he[i] - 99) + fd(he, he[i] + 198) + fd(emp, he[i] + 297);
		int score16 = ((flag16_horizonal == 4) + (flag16_uldr == 4) + (flag16_urdl == 4) + (flag16_vertical == 4)) * a[16];
		score = score + score16;
		//19
		int flag19_horizonal =
			fd(emp, he[i] + 1) + fd(he, he[i] - 1) + fd(he, he[i] + 2) + fd(he, he[i] + 3);
		int flag19_vertical =
			fd(emp, he[i] + 100) + fd(he, he[i] - 100) + fd(he, he[i] + 200) + fd(he, he[i] + 300);
		int flag19_uldr =
			fd(emp, he[i] + 101) + fd(he, he[i] - 101) + fd(he, he[i] + 202) + fd(he, he[i] + 303);
		int flag19_urdl =
			fd(emp, he[i] + 99) + fd(he, he[i] - 99) + fd(he, he[i] + 198) + fd(he, he[i] + 297);
		int score19 = ((flag19_horizonal == 4) + (flag19_uldr == 4) + (flag19_urdl == 4) + (flag19_vertical == 4)) * a[19];
		score = score + score19;
		//20
		int flag20_horizonala =
			fd(emp, he[i] - 1) + fd(he, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] - 2);
		int flag20_horizonalb =
			fd(he, he[i] - 1) + fd(emp, he[i] + 1) + fd(he, he[i] + 2) + fd(he, he[i] - 2);
		int flag20_verticala =
			fd(emp, he[i] - 100) + fd(he, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] - 200);
		int flag20_verticalb =
			fd(he, he[i] - 100) + fd(emp, he[i] + 100) + fd(he, he[i] + 200) + fd(he, he[i] - 200);
		int flag20_uldra =
			fd(emp, he[i] - 101) + fd(he, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] - 202);
		int flag20_uldrb =
			fd(he, he[i] - 101) + fd(emp, he[i] + 101) + fd(he, he[i] + 202) + fd(he, he[i] - 202);
		int flag20_urdla =
			fd(emp, he[i] - 99) + fd(he, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] - 198);
		int flag20_urdlb =
			fd(he, he[i] - 99) + fd(emp, he[i] + 99) + fd(he, he[i] + 198) + fd(he, he[i] - 198);
		int score20 = ((flag20_horizonala == 4) + (flag20_uldra == 4) + (flag20_urdla == 4) + (flag20_verticala == 4)+ (flag20_horizonalb == 4) + (flag20_uldrb == 4) + (flag20_urdlb == 4) + (flag20_verticalb == 4)) * a[20];
		score = score + score20;

	}

	return score;
}
int main()
{
	char command[10];
	vector<int>me;
	vector<int>he;
	vector<int>emp;
	for (int ccc = 0; ccc < 15; ++ccc) 
	{
		for (int ddd = 0; ddd < 15; ++ddd)
		{
			emp.push_back(ccc * 100 + ddd);
		}
	}
	int x, y, player,pos;
	int status = 0;//0=white,1=black
	cin >> command;//START
	for (int i = 0; i < 3; ++i)
	{
		cin >> command >> x >> y >> player;
		pos = x * 100 + y;
		if (player == 1)me.push_back(pos);
		else he.push_back(pos);
		emp=clean(emp, pos);
	}//PLACE
	cin>>command;//DONE
	cout << "OK" << endl;//OK
	if (me.size() == 1)cin>>command;//BEGIN
	else {
		status = 1;
		cin >> command >> x >> y;//TURN
		pos = x * 100 + y;
		he.push_back(pos);
		emp=clean(emp, pos);
	}
	int num=1;//Xth drop
	while (command[0]!='E')/*drop(find->evaluate)->receive->*/
	{
		/*find place to drop*/
		
		int decision = -1000000;
		int maxscore = -100000000;
		if (status == 1) // banned drop
		{
			vector<int>candidategrade;
			for (int n = 0; n < (int)emp.size(); ++n)
			{
				if (emp[n] == 505) {
					emp[n] = 505;
				}
				if (fddirection(me, emp, emp[n]))candidategrade.push_back(emp[n]);
			}
			for (int i = 0; i < (int)candidategrade.size(); ++i)
			{
				int temp = candidategrade[i];
				vector<int> emp2 = clean(candidategrade, temp);
				vector<int>me2 = me;

				me2.push_back(temp);
				int sc = eval(me2, he, emp2);
				if (sc > maxscore)
				{
					decision = temp;
					maxscore = sc;
				}
			}
		}
		else
		{
			for (int i = 0; i < (int)emp.size(); ++i)
			{
				int temp = emp[i];
				vector<int> emp2 = clean(emp, temp);
				vector<int>me2 = me;
				//TEST
				
				me2.push_back(temp);
				int sc = eval(me2, he, emp2);
				if (sc > maxscore)
				{
					decision = temp;
					maxscore = sc;
				}
			}

		}

		cout << decision / 100 <<' '<< decision % 100<<endl;

		emp = clean(emp, decision);
		me.push_back(decision);
		
		cin >> command;
		if (command[0] == 'E') 
		{
			break;
		}
		else
		{
			cin>> x >> y;
			pos = x * 100 + y;
			he.push_back(pos);
			emp = clean(emp, pos);
		}
	}
	return 0;
}