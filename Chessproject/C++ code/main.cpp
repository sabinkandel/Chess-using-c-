
#include <iostream>
#include <string>
#include<graphics.h>
using namespace std;
class window;
 struct goti {

char gotiname;
        char goticolor;



    };


    struct Box
    {

        goti goti;
        char color;



    };

   struct Board {



        Box boxes[8][8];





    };

  struct loc {

        int row;
        char column;
    };



class setup {



    Board board;
    char name[10] = "HGUMRUGHP";



public:





        Board intBoardsetup() {

             for (int i = 0;i <= 7;i++) {
                 for (int j = 0;j <= 7;j++)
                 {
                     if ((i + j) % 2 == 0) {
                         board.boxes[i][j].color = 'B';
                     }
                     else board.boxes[i][j].color = 'W';
                 };
             };

             for (int i = 0;i <= 7;i++) {
                 for (int j = 0;j <= 7;j++) {

                     if (i == 0 || i == 1)
                         board.boxes[i][j].goti.goticolor = 'B';

                     else if(i == 6 || i == 7)
                         board.boxes[i][j].goti.goticolor = 'W';
                     else       board.boxes[i][j].goti.goticolor = 'E';

                     if (i == 0 || i == 7)  board.boxes[i][j].goti.gotiname = name[j]; else board.boxes[i][j].goti.gotiname = '\0';
                     if (i == 1 || i == 6)  board.boxes[i][j].goti.gotiname = 'P';
                 }

             };

            return board;


        };










       Board initialsetup() {

        Board board = intBoardsetup();

        return board;

        };




        };



class input {


private:
string ett;
    Box sourcebox;
    Box Destinationbox;

    loc source;
    loc destination;
    bool valid;
    char nam[9] = "abcdefgh";
 int    turn = 0;



public:

    void takeinput() {


              POINT d,s;



               while(!GetAsyncKeyState(VK_LBUTTON))
               {


               }


               GetCursorPos(&s);
               while(GetAsyncKeyState(VK_LBUTTON))
               {


               }

GetCursorPos(&d);









cout << endl<< "s.x : "<<s.x << endl;


cout << "s.y : " <<s.y<<endl;
cout<< "d.x : "<<d.x << endl;


cout << "d.y : " <<d.y<<endl;


source.column = 'a'-1+((s.x-3)/50);
         source.row= 9-((s.y-25)/50);
cout << endl<< "sc : " <<  source.column << endl;


  destination.column = 'a'-1+((d.x-3)/50);
         destination.row= 9-((d.y-25)/50);
cout << "dc : "<<destination.column << endl;
cout << "sr : " <<  source.row << endl;
cout << "dr : " <<  destination.row << endl;


    };



    void inpptr(Board &B1)
    {
        for (int i = 0;i < 8;i++) {
            if (source.column == nam[i]) sourcebox.goti = B1.boxes[source.row - 1][i].goti;

        }

            for (int i = 0;i < 8;i++)
            {
                if (destination.column == nam[i]) {
                    Destinationbox.goti = B1.boxes[destination.row - 1][i].goti;


                }
            }



        cout << sourcebox.goti.gotiname<<Destinationbox.goti.gotiname;




    };

    void executeinput(Board& B1)
    {
        for (int i = 0;i < 8;i++)
        {
            if (destination.column == nam[i]) {

                B1.boxes[destination.row - 1][i].goti = sourcebox.goti;

            }
            for (int i = 0;i < 8;i++) {
                if (source.column == nam[i]) {
                    B1.boxes[source.row - 1][i].goti.gotiname = '\0';
                    B1.boxes[source.row - 1][i].goti.goticolor = 'E';

                }

            }

        }



        cout << sourcebox.goti.goticolor << Destinationbox.goti.goticolor;


        if(Destinationbox.goti.gotiname=='R')

        {

            cout << "Game OVERR";
            int agy;
            cin >> agy;



        }



    };

 bool validinputt() {


     if(turn==0){
        if(sourcebox.goti.goticolor=='W') {
                turn=1;
            return 1;
        }
        else return 0;

        }
        if(turn==1){
        if(sourcebox.goti.goticolor=='B') {
                turn=0;
            return 1;
        }
        else return 0;

        }

        }




    bool validinput1() {
        if (source.column >= 'a' && source.column <= 'h' && destination.column >= 'a' && destination.column <= 'h' && source.row > 0 && source.row < 9 && destination.row>0 && destination.row < 9) return 1; else return 0;
    }
    bool validinput2(Board B1) {
        goti s= sourcebox.goti;
        goti d= Destinationbox.goti;
        int dr = destination.row-1;
        char  dc = destination.column;
        int  sr = source.row-1;
        char  sc = source.column;
        int sci = sc - 97;
        int dci = dc - 97;

        if (s.goticolor != d.goticolor) {

            if (s.gotiname == 'P') {
               if(s.goticolor=='B'){
                if (dr - sr == 1) {
                    if (abs(dc - sc) == 1 && d.goticolor != s.goticolor && d.goticolor != 'E') return 1;
                    if (abs(dc - sc) == 0 && d.goticolor == 'E') return 1;
                }
                else if (dr - sr == 2 && sr == 1) {
                    if (abs(dc - sc) == 0 && d.goticolor == 'E'&& B1.boxes[sr+1][dc].goti.goticolor != 'E') return 1;
                }
            } else if(s.goticolor=='W'){
             if (dr - sr == -1) {
                    if (abs(dc - sc) == 1 && d.goticolor != s.goticolor && d.goticolor != 'E') return 1;
                    if (abs(dc - sc) == 0 && d.goticolor == 'E') return 1;
                }
                else if (dr - sr == -2 && sr == 6) {
                    if (abs(dc - sc) == 0 && d.goticolor == 'E'&& B1.boxes[sr+1][dc].goti.goticolor != 'E') return 1;
                }


            }
            }


            if (s.gotiname == 'G')
           {

                if (dr != sr && dc != sc && abs(dr - sr) + abs(dc - sc) == 3) return 1;
            }
            if (s.gotiname == 'R')
            {

                if (dr == sr || dc == sc) {
                    if (abs(dr - sr) + abs(dc - sc) == 1) return 1;
                }
                else if (dr != sr && dc != sc) {
                    if (abs(dr - sr) + abs(dc - sc) == 2) return 1;
                }

            }
            if (s.gotiname == 'H')
            {
                if (dr == sr) {
                    int dist = dci - sci - 1;
                    if (dist > 0) {
                        for (int i = sci + 1;i < dci;i++)
                            if (B1.boxes[dr][i].goti.goticolor != 'E') goto end;
                    }
                    if (dist < 0) {
                        for (int i = dci + 1;i < sci;i++)
                            if (B1.boxes[dr][i].goti.goticolor != 'E') goto end;
                    }

                    return 1;
                }




                    if (dci == sci) {
                        int dist = dr - sr - 1;
                        if (dist > 0) {
                            for (int i = sr + 1;i < dr;i++)
                                if (B1.boxes[i][dci].goti.goticolor != 'E') goto end;
                        }
                        if (dist < 0) {
                            for (int i = dr + 1;i < sr;i++)
                                if (B1.boxes[i][dci].goti.goticolor != 'E') goto end;
                        }

                        return 1;
                    }

            }


            if (s.gotiname == 'U')
            {
                int distr = dr - sr;
                int distc = dci - sci;
                if(abs(distr)!=abs(distc)) goto end;
                if (distr > 1 && distc>1) {
                    for (int i=1;sr+i<dr;i++)
                       if (B1.boxes[sr+i][sci+i].goti.goticolor != 'E') goto end;
                }
                if (distr < -1 && distc > 1) {
                    for (int i = 1;sci+i<dci;i++)
                        if (B1.boxes[sr - i][sci + i].goti.goticolor != 'E') goto end;
                }

                if (distr > 1 && distc < -1) {
                    for (int i = 1;sr + i < dr;i++)
                        if (B1.boxes[sr + i][sci - i].goti.goticolor != 'E') goto end;
                }
                if (distr < -1 && distc < -1) {
                    for (int i = 1;sc + i > dci;i++)
                        if (B1.boxes[sr - i][sci - i].goti.goticolor != 'E') goto end;
                }
                return 1;
            }

            if (s.gotiname == 'M')
            {

                int distr = dr - sr;
                int distc = dci - sci;
                if (abs(distr) == abs(distc)) {
                    if (distr > 1 && distc > 1) {
                        for (int i = 1;sr + i < dr;i++)
                            if (B1.boxes[sr + i][sci + i].goti.goticolor != 'E') goto end;
                    }
                    if (distr < -1 && distc > 1) {
                        for (int i = 1;sci + i < dci;i++)
                            if (B1.boxes[sr - i][sci + i].goti.goticolor != 'E') goto end;
                    }

                    if (distr > 1 && distc < -1) {
                        for (int i = 1;sr + i < dr;i++)
                            if (B1.boxes[sr + i][sci - i].goti.goticolor != 'E') goto end;
                    }
                    if (distr < -1 && distc < -1) {
                        for (int i = 1;sc + i > dci;i++)
                            if (B1.boxes[sr - i][sci - i].goti.goticolor != 'E') goto end;
                    }
                    return 1;

                }
                if (dr == sr) {
                    int dist = dci - sci - 1;
                    if (dist > 0) {
                        for (int i = sci + 1;i < dci;i++)
                            if (B1.boxes[dr][i].goti.goticolor != 'E') goto end;
                    }
                    if (dist < 0) {
                        for (int i = dci + 1;i < sci;i++)
                            if (B1.boxes[dr][i].goti.goticolor != 'E') goto end;
                    }

                    return 1;
                }




                if (dci == sci) {
                    int dist = dr - sr - 1;
                    if (dist > 0) {
                        for (int i = sr + 1;i < dr;i++)
                            if (B1.boxes[i][dci].goti.goticolor != 'E') goto end;
                    }
                    if (dist < 0) {
                        for (int i = dr + 1;i < sr;i++)
                            if (B1.boxes[i][dci].goti.goticolor != 'E') goto end;
                    }

                    return 1;
                }

            }

        }
        end:

        return 0;

    }



};





class display {

    int page =0;
public:
    void displayboard(Board  &board) {
        for (int i = 7;i >= 0;i--) {
            cout << '\n' << '\n' << i+1 << "  ";
            for (int j = 0;j <= 7;j++) cout << "    " << board.boxes[i][j].goti.goticolor;

        };
        cout << '\n' << '\n' << '\n' << "   ";
        string abc = "abcdefgh";
        for (int i = 0;i <= 7;i++) cout << "    " << abc[i];







	int gr = DETECT, gm;
int	val=50;
	int r, c, x = val, y = val, w = 0;
setactivepage(page);

cleardevice();




                for (int j=0;j<8;j++){
                for(int i=0;i<8;i++){
				if(w==1) {
                        setcolor(WHITE);

				setfillstyle(SOLID_FILL, WHITE);


				rectangle(x, y, x + val, y + val);

				floodfill(x + 1, y + 1, WHITE);
				x=x+val;
				w=0;
                }
				else {

				setcolor(WHITE);



				setfillstyle(SOLID_FILL, GREEN);


				rectangle(x, y, x + val, y + val);

                floodfill(x + 1, y + 1, WHITE);

               x = x + val;
               w=1;
                }


                }
if(w==0) w =1; else w=0;
                x=val;
                y=y+val;

                }






              x = 40;
   y =70;

    // font style
    int font = 8;

    // font direction
    int direction = 1;

    // font size
    int font_size = 2;



             settextstyle(font, direction, font_size);

    // for printing text in graphics window
    outtextxy(x, y, "1   2    3   4   5   6   7    8");
    direction =0;

    settextstyle(font, direction, font_size);


       x = 430;
   y =475;

    outtextxy(x, y, "a   b   c   d    e   f   g   h");


        char dp[7];


        setcolor(WHITE);
        setfillstyle(SOLID_FILL, GREEN);

x = 430;
y = 90;
char cl='W';

for(int i=7;i>=0;i--){
for(int j=7;j>=0;j--){

char chay[0];


chay[0]=board.boxes[i][j].goti.gotiname;
chay[1]=NULL;
if(board.boxes[i][j].goti.goticolor=='W') setcolor(WHITE);
if(board.boxes[i][j].goti.goticolor=='B') setcolor(YELLOW);



outtextxy(x, y, chay);
x-=50;
}
x= 430;
y+=50;
}


  for (int i = 7;i >= 0;i--)
  dp[i]=board.boxes[0][i].goti.gotiname;

delay(10);

setvisualpage(page);

page = 1 - page;


    }

};

  /*
class getinput {


public:
    input takeinput(Board board)
    {
        string abc = "abcdefgh";
        string num = "12345679";
        char src[2];
        char dst[2];
        input input;

        cin>> src;
        cin>> dst;


        for (int i = 0;i <= 7;i++)
        {
            if (src[1] = abc[i]) input.source.row = abc[i];


            if (dst[1] = abc[i]) input.destination.row = abc[i];
        }


        for (int i = 0;i <= 7;i++)
        {
            if (src[0] = num[i]) input.source.column = num[i];


            if (dst[0] = num[i]) input.destination.column = num[i];
        }





        return input;

    };
    */







class window {

 private:
    input inputs;

    display display;
   // getinput gi;
    public:

   void takeboard(Board &B1) {
initwindow(getmaxwidth( ), getmaxheight( ),"CHESS");

       label:
       system("CLS");

           display.displayboard(B1);

       inputs.takeinput();

       if (inputs.validinput1()) {

           cout << "aaaaa";

           inputs.inpptr(B1);
           if (inputs.validinput2(B1)) {
                if(inputs.validinputt()){
               inputs.executeinput(B1);
                }

           }

       }

       goto label;
   };




};








    int main()
{
    setup setup;
    window windows;
    Board B1 = setup.initialsetup();



    windows.takeboard(B1);










}
