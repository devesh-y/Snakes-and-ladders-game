#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class players
{
    private:
        int number;
        char name[20];
        int score;
        int snakebites;
        int ladderuse;
    public:
        players():score(1),snakebites(0),ladderuse(0)
        {}
        void getname()
        {
            cin>>name;
        }
        void printname()
        {
            cout<<name;
        }
        void getnumber(int num)
        {
            number=num;
        }
        int getscore()
        {
            return score;
        }
        void incscore(int x)
        {
            score+=x;
        }
        int retnum()
        {
            return number;
        }
        void setscore(int value)
        {
            score=value;
        }
        void incsnakebites()
        {
            snakebites++;
        }
        void incladderuse()
        {
            ladderuse++;
        }
        int retsnakebites()
        {
            return snakebites;
        }
        int retladderuse()
        {
            return ladderuse;
        }
};
void toss(int n,players p[])
{
    int arr[n];
    int arr2[n];
    cout<<"\npress any key to toss first     ";
    
    
    getch();
    system("cls");
    for(int i=0;i<n;i++)
    {
        int x=0;
        cout<<"\npress any key to throw the dice---player "<<i+1<<"\n";
        getch();
        arr[i]=(rand()%6)+1;
        cout<<"player "<<i+1<<" you got "<<arr[i]<<endl;
        arr2[i]=arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                x=1;
                break;
            }
        }
        if(x==1)
        {
            cout<<"\nthrow the dice once again\n";
            i--;
        } 
    }
    cout<<"\npress any key to continue;  ";
    getch();
    sort(arr,arr+n);
    int position=n;
    system("cls");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr2[j])
            {
                p[j].getnumber(position);
                cout<<"\nplayer "<<j+1<<" is at place number "<<position;
                position--;
                break;
            }
        }
    }
}
void snakeladdercheck(int i, int n, players p[])
{
    int s=0;
    int l=0;
    int prevscore=p[i].getscore();
    switch(p[i].getscore())
    {
        case 99:
        {
            s=1;
            p[i].setscore(78);
            break;
        }
        case 95:
        {
            s=1;
            p[i].setscore(75);
            break;
        }
        case 93:
        {
            s=1;
            p[i].setscore(73);
            break;
        }
        case 62:
        {
            s=1;
            p[i].setscore(19);
            break;
        }
        case 64:
        {
            s=1;
            p[i].setscore(60);
            break;
        }
        case 87:
        {
            s=1;
            p[i].setscore(24);
            break;
        }
        case 17:
        {
            s=1;
            p[i].setscore(7);
            break;
        }
        case 54:
        {
            s=1;
            p[i].setscore(34);
            break;
        }
        case 4:
        {
            l=1;
            p[i].setscore(14);
            break;
        }
        case 20:
        {
            l=1;
            p[i].setscore(38);
            break;
        }
        case 9:
        {
            l=1;
            p[i].setscore(31);
            break;
        }
        case 40:
        {
            l=1;
            p[i].setscore(59);
            break;
        }
        case 28:
        {
            l=1;
            p[i].setscore(84);
            break;
        }
        case 63:
        {
            l=1;
            p[i].setscore(81);
            break;
        }
        case 51:
        {
            l=1;
            p[i].setscore(67);
            break;
        }
        case 71:
        {
            l=1;
            p[i].setscore(91);
            break;
        }
    }
    if(s==1)
    {
        cout<<"\nsnake encountered at "<<prevscore;
        p[i].incsnakebites();
    }
    if(l==1)
    {
        cout<<"\nthere is a ladder at "<<prevscore;
        p[i].incladderuse();
    }
}
int checkvalid(float x)
{
    int y=x;
    if((x-y)>0 || (x-y)<0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    srand(time(0));
    float numberofplayers;
    int n;
    comeback:
        cout<<"\n\nenter the number of players:  ";
        cin>>numberofplayers;
        n=numberofplayers;
        if(n<=1 || n>6 || checkvalid(numberofplayers)==0)
        {
            cout<<"\nyou have entered invalid number to play the game\n";
            cout<<"press any key to go back..";
            getch();
            system("cls");
            goto comeback;
        }
        
        class players p[n];
        for(int i=0;i<n;i++)
        {
            cout<<"\nenter player "<<i+1 <<" name:  ";
            p[i].getname();
            cout<<endl;
        }
        toss(n,p);
        cout<<"\n\npress any key to continue..   ";
        
        getch();
        system("cls");
        int check=1;
        
        int position=1;
        int rank=1;
        while(check!=0)
        {
            check=0;
            int x=0;
            for(int i=0;i<n;i++)
            {
            
                if(p[i].retnum()==position && p[i].getscore()<100)
                {
                
                    x=1;
                    system("cls");
                    for(int m=0;m<n;m++)
                    {
                        p[m].printname();
                        cout<<" is at "<<p[m].getscore()<<endl;
                    }
                    position++;
                    cout<<"\n";
                    p[i].printname();
                    cout<< " your turn...\npress any key to continue.....";
                    
                    getch();
                    int s=(rand()%6)+1;
                    cout<<"\nyou got "<<s;
                    if((p[i].getscore()+s)>100)
                    {

                        cout<<"\ninvalid number to win";
                        cout<<"\nyou are at "<<p[i].getscore();
                        cout<<"\npress any key to continue....";
                        
                        getch();
                        if(position==n+1)
                        {
                            position=1;
                        }
                        continue;
                    }
                    p[i].incscore(s);
                    snakeladdercheck(i,n,p);
                    
                    if(s==6)
                    {
                        cout<<"\nyou got 1 extra throw...\n";
                        position--;
                        
                        cout<<"\nyou are at "<<p[i].getscore();
                        i--;
                        cout<<"\npress any key to continue....";
                        
                        getch();
                        continue;
                    }
                    if(position==n+1)
                    {
                        position=1;
                    }
                    
                    if(p[i].getscore()==100)
                    {
                        if(rank==1 && n==2)
                        {
                            cout<<"\nCongratulation ";
                            p[i].printname(); 
                            cout<<" you won the game ";
                            cout<<"\n\ntotal number of snake bites are "<<p[i].retsnakebites()<<" and ladder are used by about "<<p[i].retladderuse()<<" times";
                            cout<<"\npress any key to exit";
                            
                            getch();
                            exit(0);
                        }
                        if(rank==(n-1))
                        {
                            cout<<"\nCongratulation ";
                            p[i].printname(); 
                            cout<<" your rank is "<<rank;
                            cout<<"\n\ntotal number of snake bites are "<<p[i].retsnakebites()<<" and ladder are used by about "<<p[i].retladderuse()<<" times";
                            cout<<"\npress any key to exit";
                        
                            
                            getch();
                            exit(0);
                        }
                        if(rank>=1 && rank<n-1)
                        {
                            cout<<"\nCongratulation ";
                            p[i].printname(); 

                            cout<<" your rank is "<<rank;
                            cout<<"\n\ntotal number of snake bites are "<<p[i].retsnakebites()<<" and ladder are used by about "<<p[i].retladderuse()<<" times";
                            cout<<"\npress any key to continue";
                            rank++;
                            
                            getch();
                            continue;
                        }
                        
    
                    }
                    cout<<"\nnow you are at "<<p[i].getscore();
                    cout<<"\npress any key to continue....";
                    
                    getch();

                }
            }
            for(int i=0;i<n;i++)
            {
                if(p[i].getscore()<100)
                    check++;
            }
            if(position==n+1)
            {
                position=1;
                continue;
            }
            if(x==0)
            {
                position++;
            }
        

        }
}