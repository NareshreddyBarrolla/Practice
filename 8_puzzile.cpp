#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
int count=0,count1=0,c=0;
int in[3][3];
int fin[3][3];
int fin1[3][3];
int compare(int a[][3],int b[][3]);
int check(int a[][3]);
void display( int a[][3]);
void up();
void solve();
void invert(int a[][3],int b[][3]);
int operation();

void main()
{
    int i,j;
    clrscr();
    cout << " please enter the initial configuration of the 3*3 puzzle." << endl;
    cout << " all numbers must be between 0 and 8, 0 being the blank space."<< endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout << "["<<i<<"] ["<<j<<"] : ";
            cin >> in[i][j];
        }
    }
    display(in);

    cout<<endl;
    fin[0][0]=1;
    fin[0][1]=2;
    fin[0][2]=3;
    fin[1][0]=8;
    fin[1][1]=0;
    fin[1][2]=4;
    fin[2][0]=7;
    fin[2][1]=6;
    fin[2][2]=5;
    fin1[0][0]=0;
    fin1[0][1]=1;
    fin1[0][2]=2;
    fin1[1][0]=3;
    fin1[1][1]=4;
    fin1[1][2]=5;
    fin1[2][0]=6;
    fin1[2][1]=7;
    fin1[2][2]=8;

    check(in);
    cout<<count<<endl;
    if((count%2)==0)
    {
        display(fin1);
        compare(in,fin1);
        cout<<count1<<endl;
        while(count1!=0)
        {
            solve();
            //up();
            display(in);
               //   compare(in,fin1);
            cout<<count1<<endl;
        }
    }
    else
    {
        display(fin);
        compare(in,fin);
        cout<<count1<<endl;

    }

    getch();
}

void display(int a[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {

            cout<< a[i][j]<<" ";
        }
        cout<<endl;
    }

}

int compare(int a[3][3],int b[3][3])
{
    count1=0;
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                count1++;
            }
        }
        cout<<endl;
    }
    if(count1==0)
    {
        cout<<endl<<"Puzzel Solved"<<endl;
    }
    return count1;
}
int check(int a[3][3])
{
  int i,j,k,l;
  count=0;

   for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
     {
     for(k=i;k<3;k++)
     {
        for(l=j;l<3;l++)
        {
            if(a[i][j]>a[k][l])
            {
                if(a[k][l]!=0 && a[i][j]!=0)
                    count++;
        //printf("%d",cnt);
            }
        }
     }
     }
   }
   return count;
}
void up()
{
  int i,j,tempi,tempj,temp;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
       if(in[i][j]==0)
       {
      tempi=i;
      tempj=j;
       }
     }
  }

  if(tempi!=0)
  {
      temp=in[tempi][tempj];
      in[tempi][tempj]=in[tempi-1][tempj];
      in[tempi-1][tempj]=temp;
      printf(" After applying UP:\n");
  }
  compare(in,fin1);
}

void right()
{
  int i,j,tempi,tempj,temp;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
       if(in[i][j]==0)
       {
      tempi=i;
      tempj=j;
       }
     }
  }

  if(tempj!=2)
  {
      temp=in[tempi][tempj];
      in[tempi][tempj]=in[tempi][tempj+1];
      in[tempi][tempj+1]=temp;
      printf("After applying Right:\n ");
  }
  compare(in,fin1);
}
void down()
{
  int i,j,tempi,tempj,temp;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
       if(in[i][j]==0)
       {
      tempi=i;
      tempj=j;
       }
     }
  }
  if(tempi!=2)
  {
      temp=in[tempi][tempj];
      in[tempi][tempj]=in[tempi+1][tempj];
      in[tempi+1][tempj]=temp;
      printf("After applying Down:\n ");
  }
  compare(in,fin1);
}
void left()
{
  int i,j,tempi,tempj,temp;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
       if(in[i][j]==0)
       {
      tempi=i;
      tempj=j;
       }
     }
  }

  if(tempj!=0)
  {
      temp=in[tempi][tempj];
      in[tempi][tempj]=in[tempi][tempj-1];
      in[tempi][tempj-1]=temp;
      printf(" After applying left:\n ");
  }
  compare(in,fin1);
}


void solve()
{
    //int i,j,cntu=0,cntd=0,cntl=0,cntr=0,temp[3][3],c=0;
       /*   invert(temp,in);
      // for(i=count1;i>0;i--)
    {
        up();
        cntu=count1;
        invert(in,temp);
        down();
        cntd=count1;
        invert(in,temp);
        left();
        cntl=count1;
        invert(in,temp);
        right();
        cntr=count1;
        invert(in,temp);
        if(cntu<cntd)
        {
            if(cntu<cntl)
            {
                if(cntu<cntr)
                {
                    c=1;
                }
                else
                {
                    c=4;
                }
            }
            else
            {
                if(cntl<cntr)
                {
                    c=3;
                }
                else
                {
                    c=4;
                }
            }
        }
        else
        {
            if(cntd<cntl)
            {
                if(cntd<cntr)
                {
                    c=2;
                }
                else
                {
                    c=4;
                }
            }
            else
            {
                if(cntl<cntr)
                {
                    c=3;
                }
                else
                {
                    c=4;
                }
            }
         }
         operation();  */
         switch(c)
         {
            case1:
                up();
                break;
            case2:
                down();
                break;
            case3:
                left();
                break;
            case4:
                right();
                break;
            default:
                cout<<"invalid!";
             }


}
void invert(int a[3][3], int b[3][3])
{
    int i,j;
        for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=b[i][j];
        }
    }
}
int operation()
{

      // for(i=count1;i>0;i--)

        int i,j,cntu=0,cntd=0,cntl=0,cntr=0,temp[3][3],c=0;
         invert(temp,in);
        up();
        cntu=count1;
        invert(in,temp);
        down();
        cntd=count1;
        invert(in,temp);
        left();
        cntl=count1;
        invert(in,temp);
        right();
        cntr=count1;
        invert(in,temp);
        if(cntu<cntd)
        {
            if(cntu<cntl)
            {
                if(cntu<cntr)
                {
                    c=1;
                }
                else
                {
                    c=4;
                }
            }
            else
            {
                if(cntl<cntr)
                {
                    c=3;
                }
                else
                {
                    c=4;
                }
            }
        }
        else
        {
            if(cntd<cntl)
            {
                if(cntd<cntr)
                {
                    c=2;
                }
                else
                {
                    c=4;
                }
            }
            else
            {
                if(cntl<cntr)
                {
                    c=3;
                }
                else
                {
                    c=4;
                }
            }
         }
    return c;
}
