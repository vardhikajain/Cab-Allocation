#include<iostream>
#include<utility>
#include<map>
#include<string>
#include<fstream>
#include<conio.h>
//#include<curses.h>
#include<vector>
#include<windows.h>
#include <algorithm>
#include<sstream>
using namespace std;

void clrscr()
{
   system("cls");
}

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isWordEnd;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}
struct TrieNode* rootTrie = getNode();
void insertTrie(struct TrieNode *root, const string key)
{
	struct TrieNode *pCrawl = root;

	for (int level = 0; level < key.length(); level++)
	{
		int index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isWordEnd = true;
}

bool search(struct TrieNode *root, const string key)
{
	int length = key.length();

	struct TrieNode *pCrawl = root;

	for (int level = 0; level < length; level++)
	{
		int index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isWordEnd);
}
bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

void suggestionsRec(struct TrieNode* root, string currPrefix)
{
	if (root->isWordEnd)
	{
		cout << currPrefix;
		cout << endl;
	}


	if (isLastNode(root))
		return;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			currPrefix.push_back(97 + i);

			suggestionsRec(root->children[i], currPrefix);
		}
	}
}


int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;
	int level;
	int n = query.length();

	for (level = 0; level < n; level++)
	{
		int index = CHAR_TO_INDEX(query[level]);
		if (!pCrawl->children[index])
			return 0;

		pCrawl = pCrawl->children[index];
	}
	bool isWord = (pCrawl->isWordEnd == true);

	bool isLast = isLastNode(pCrawl);

	if (isWord && isLast)
	{
		cout << query << endl;
		return -1;
	}
	if (!isLast)
	{
		string prefix = query;
		suggestionsRec(pCrawl, prefix);
		return 1;
	}
	return 0;
}

void logo();// function is used for print the logo (Swarati)
void log();// this function is use for login swarati account
void signup();// function is use for signup (new user )
void menu(); // function is used for show menu
void mapp(); //map function is used for show the places
void prog(); // prog is used for fetch place and give the shortest path
void details(); // details is used for show you login details
struct stack
{
    int rear;
    vector<string>v;// v is vector which store the location name
};
void isempt(stack *s)
{
    s->rear=-1;
}
int pop(struct stack *s)
{
    if(s->rear==-1)
    {
        //cout<<"stack empty";
        return 0;
    }
    int k=s->rear;
    //cout<<k;
    cout<<s->v[k]<<"";
    s->rear--;
}

void push(struct stack *y,string u)
{
    struct stack *s=y;
    s->rear++;
    //cout<<s->rear;
    s->v.push_back(u);
    //cout<<"xx";
}

struct graph
{
    int v,e;
    int **adj;
};
struct graph *g;
void creategraph(int s)
{
    g=new graph;// dynamically graph
    int i=0;
    int k,j;
    int n1;
    ifstream red;
    red.open("swaratis.txt");// open distance.txt in read mode
    g->adj=new int*[s];
    for(i=0;i<s;i++)
    {
        g->adj[i]=new int[s];
    }
    for(k=0;k<s;k++)
    {
        for(j=0;j<s;j++)
        {
            g->adj[k][j]=0;
        }
    }
      /*for(k=0;k<s;k++)
     {
     for(j=0;j<s;j++)
     {
     cout<<g->adj[k][j]<<" ";
     }
     cout<<endl;
     }*/



    for(k=0;k<s;k++)
    {
        //  loop:
        for(j=0;j<s;j++)
        {
            while(red>>n1)
            {
                g->adj[k][j]=n1;
                break;
            }
        }
    }
    red.close();
      /*for(k=0;k<s;k++)
     {
     for(j=0;j<s;j++)
     {
     cout<<g->adj[k][j]<<" ";
     }
     cout<<endl;
     }*/
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(k=0;k<s;k++)
    {
        for(i=0;i<s;i++)
        {
            for(j=0;j<s;j++)
            {
                if(g->adj[i][k]+g->adj[k][j]<g->adj[i][j])
                {
                    g->adj[i][j]=g->adj[i][k]+g->adj[k][j];

                }
            }
        }
    }//n^3
    /*
     for(k=0;k<s;k++)
     {
     for(j=0;j<s;j++)
     {
     cout<<g->adj[k][j]<<" ";
     }
     cout<<endl;
     }*/
}
void start()
{
    int c;
    logo();
    system("color 1E");//Setting The Color Of Console
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"\tLoAdInG ";
   Sleep(100);//For Pause
   cout<<"<";
   Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
   Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"\n\n\t SuCcEsSFuL\n";

   Sleep(2000);//For Pause
   getch();
   system("CLS");//To Clear The Screen

   system("CLS");
 cout<<"\t********************"<<endl;
 cout<<"\t*CaB BoOkInG SySteM*"<<endl;
 cout<<"\t********************"<<endl;
 cout<<endl;

 cout<<"*************************"<<endl;
 cout<<"*<1>     For Login      *"<<endl;
 cout<<"*************************"<<endl;
 cout<<endl;
 cout<<"**************************"<<endl;
 cout<<"*<2>     For Sign Up     *"<<endl;
 cout<<"**************************"<<endl;
 cout<<endl;
 cout<<"******************"<<endl;
 cout<<"*<3> For Exit    *"<<endl;
 cout<<"******************"<<endl;
 cout<<endl;
 cout<<"SElEct: ";
 cin>>c;
    if(c==1)
    {
        system("cls");
        //logo();
        log();
    }
    else if(c==2)
    {
        system("cls");
        //logo();
        signup();
    }
    else
    {
        cout<<"Exit";
        exit(1);
    }
}


void logo()
{
    char c;
    //int BackC=0;int ForgC=7;
    //wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    cout<<"                                     SADDI GADDI                                                "<<endl;
    cout<<"                  CAB SERVICE WITH SHORTEST PATH AND TRAFFIC FREE                               "<<endl<<endl;
    //BackC=0; ForgC=2;
    //wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
    cout<<"                                      WELCOME!!"<<endl<<endl;

    return;
}

void log()
{
    int c;
    map<string,pair<string,string> > m;
    string id_user, password_user;
    ifstream fin;
    struct login
    {
        long long int pno;
        string user;
        string password;
    };
    struct login logs;
    fin.open("logs.txt");
    while(fin>>logs.user>>logs.password)
    {
        m[logs.user].first=logs.user;
        m[logs.user].second=logs.password;
    }
    cout<<"Enter Username"<<endl;
    cin>>id_user;
    cout<<"Enter password"<<endl;
    cin>>password_user;
    if(m[id_user].second==password_user)
    {
        cout<<endl;
   cout<<endl;
   cout<<"\tLoAdInG ";
   Sleep(100);//For Pause
   cout<<"<";
   Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
   Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"<";
      Sleep(100);//For Pause
   cout<<">";
   Sleep(100);//For Pause
   cout<<"\n\n\t SuCcEsSFuL\n";

   Sleep(2000);//For Pause
   getch();
   system("CLS");
        menu();
    }
    else
    {
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Username or Password is Incorrect!!"<<endl;
        cout<<"Press 1 to Try Again"<<endl;
        cout<<"Press 2 to go to Main Menu"<<endl;
        cout<<"Press 3 New User!! SignUp Now"<<endl;
        cout<<"Press any other key to Exit"<<endl;
        cin>>c;
        if(c==1)
        {
            system("cls");
           // logo();
            log();
        }
        else if(c==2)
        {
            system("cls");
            start();
        }
        else if(c==3)
        {
            system("cls");
            signup();
        }
        else
        {
            exit(1);
        }

    }

    fin.close();
    return;
}

void signup()
{
    int c;
    ofstream fout;
    struct login
    {
        long long int pno;
        string user;
        string password;
    };
    struct login logs;

    fout.open("logs.txt",ios::app);
    cout<<"Enter Phone Number:"<<endl;
    cin>>logs.pno;
    fout.flush();
    cout<<"Enter Username:"<<endl;
    cin>>logs.user;
    fout.flush();
    cout<<"Enter Password"<<endl;
    cin>>logs.password;
    fout.flush();
    //fout<<logs.pno<<endl;
    fout<<logs.user<<endl;
    fout<<logs.password<<endl;
    /*fout<<id<<" ";
     fout<<password<<" ";
     fout<<endl;*/
    fout.close();
    cout<<"Signup Successfull!!"<<endl;
    cout<<"Press 1 to go Login or any other key to EXIT"<<endl;
    cin>>c;
    if(c==1)
    {
        system("cls");
       // logo();
        log();
    }
    else
    {
        exit(1);
    }
    return;
}

void menu()
{
    int c;
    cout<<"Press 1 for a New Ride"<<endl;
    cout<<"Press 2 for Ride Details"<<endl;
    cout<<"Press any other key to EXIT"<<endl;
    cin>>c;
    if(c==1)
    {
        system("cls");
        //logo();
        mapp();
        prog();
    }
    else if(c==2)
    {
        system("cls");
        //logo();
        details();
    }
    else
    {
        exit(1);
    }
}


void mapp()
{
    cout<<"Map of the City!" <<endl;
    int BackC=0;int ForgC=6;
    //wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);


    cout<<"**************************************************************************************************************************************************************************"<<endl;
    cout<<"*  |-------|                   |--------|              |-------|                                            |-------------|                                              *"<<endl;
    cout<<"*  |       |                   |        |              |       |_____________________9______________________|             |                                              *"<<endl;
    cout<<"*  | BAR   |__________5________| SALOON |              | HOME  |_____________6__    ____________6___________|   PARK      |___________________9                          *"<<endl;
    cout<<"*  | (0)   |                   |  (1)   |_______7______| (2)   |                |  |                        |    (3)      |                   |                          *"<<endl;
    cout<<"*  |       |                   |________|              |       |                |  |                        |             |                   |                          *"<<endl;
    cout<<"*  |       |________              |                    |_______|            |-----------|                   |-------------|                   |                          *"<<endl;
    cout<<"*  |-------|        |             |                      |                  | STARBUCKS | (10)                    |                           |    |-------|             *"<<endl;
    cout<<"*      |  |         |             |                      |                  |-----------|                         |                           |____|  MALL |             *"<<endl;
    cout<<"*      |  |         |             |                      2                       |_ _ _ _ _ _ _ _ _               |                                |  (4)  |             *"<<endl;
    cout<<"*      |  |         | _ _ _ _ _ _ | _ _ _ _ _ _ _ _ _ _ _| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |_ _ _         |                                |       |             *"<<endl;
    cout<<"*      |  |_______________________|______________________|____________________________             |    |         |                                |-------|             *"<<endl;
    cout<<"*      4                          |                      |                            |            |    16        16                                   |                 *"<<endl;
    cout<<"*      |                          13                     |                            11           |    |         |                                    |                 *"<<endl;
    cout<<"*      |   |---------|            |               |----------|                        |            5    |______   |                                    12                *"<<endl;
    cout<<"*      |   |         |            |               |          |                        |            |           |  |                                    |                 *"<<endl;
    cout<<"*      |___|   J.P   |            |_______________|          |                  |--------------|   |         |------------|                            |                 *"<<endl;
    cout<<"*          | COLLEGE |                            | COMPANY  |                  |              |   |_________|            |                 |------------------|         *"<<endl;
    cout<<"*          |  (9)    |_______________8____________|  (8)     |                  |  RESTAURANT  |             |   (6)      |________17_______|     THEATER      |         *"<<endl;
    cout<<"*          |         |                            |          |________4_________|     (7)      |_____9_______|  CASINO    |                 |       (5)        |         *"<<endl;
    cout<<"*          |         |                            |          |                  |              |             |            |                 |                  |         * "<<endl;
    cout<<"*          |---------|                            |__________|                  |--------------|             |____________|                 |------------------|         *"<<endl;
    cout<<"**************************************************************************************************************************************************************************"<<endl;
    cout<<endl;



    BackC=0; ForgC=2;
    //wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void prog()
{
    string ch;

    string num;
    double num2;
    int i,r,e;
    int dis;
    int m,h;
    int speed;
    int cash;
    float time;
    string A;
    char a;
    vector<string>s;
    char c;
    string source, destination;
    a='y';
    while(a=='Y'|| a=='y')
        {
    cout<<"Enter Source:";
    cin>>A;
    int comp = printAutoSuggestions(rootTrie,A);

    if (comp == 0)
    {
        cout << "Sorry NO Such Place is There with the given Substring. Wanna Search Again ? (Y/N)";
        cin>>a; }
      else{
        cout << "Wanna Search More Precisely ? (Y/N)\n";
        cin>>a; }
        if(a=='N' || a=='n')
        {
            cout<<"Enter The Source Name";
            cin>>A;
        }
    }
    source=A;
    cout<<"Enter destination"<<endl;
    cin>>destination;
    ifstream fin;
    fin.open("place.txt");
    while(fin>>ch)
    {
        s.push_back(ch);
    }

    std::transform(source.begin(),source.end(),source.begin(), ::tolower);
    std::transform(destination.begin(),destination.end(),destination.begin(), ::tolower);

    int flagsou=0,flagdest=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]==source)
        {
            flagsou=1;
        }
        else if(s[i]==destination)
        {
            flagdest=1;
        }
    }
    if(flagdest==0||flagsou==0)
    {
        int f;
        cout<<"You have entered wrong destination or source"<<endl;
        cout<<"Press 1 to Book Again"<<endl;
        cout<<"Press 2 to go to Menu"<<endl;
        cout<<"Press any other key to exit"<<endl;
        cin>>f;
        if(f==1)
        {
           system("cls");
           // logo();
            mapp();
            prog();
        }
        else if(f==2)
        {
           system("cls");
           // logo();
            menu();
        }
        else
        {
            exit(1);
        }

    }
    cout<<"Press 1 for Economy Ride"<<endl<<"Press 2 for Luxury Ride";
    cin>>c;
    creategraph(s.size());
    for(i=0;i<s.size();i++)
    {
        if(s[i]==source)
        {
            r=i;
        }
        if(s[i]==destination)
        {
            e=i;
        }
    }
    cout<<"SORTEST ROUTE TO REACH YOUR DESTINATION IS : ";
    cout<<g->adj[r][e]<<"  KM"<<endl;
    dis=g->adj[r][e];
    float dis2=dis;
    time=(dis2/40)*60;
    if(c=='e'||c=='E')
    {

        cash=16*dis;

    }
    else if(c=='l'||c=='L')
    {
        cash=25*dis;
    }
    else
    {
        char c2;
        cout<<"You Entered Wrong Car Type"<<endl;
        cout<<"Press T to Book Again"<<endl;
        cout<<"Press M to go to Menu"<<endl;
        cout<<"Press any other key to exit"<<endl;
        cin>>c2;
        if(c2=='t'||c2=='T')
        {
            //system("cls");
            //logo();
            mapp();
            prog();
        }if(c2=='n'||c2=='N')
        {
            //system("cls");
           // logo();
            mapp();
            prog();
        }
        else if(c2=='m'||c2=='M')
        {
           // system("cls");
           // logo();
            menu();
        }
       /* else if(c2=='n'||c2=='N')
        {
            // system("cls");
            // logo();
            newr();
        }*/
        else
        {
            exit(1);
        }
    }
    cout<<"TIME TAKEN BY RIDE TO REACH DESTINATION IS : "<<time<<"  MIN"<<endl;
    cout<<"YOUR RIDE AMOUNT IS                        : " <<cash<<" RUPEES"<<endl;
    //cout<<"      THANK YOU FOR RIDING ,HAVE A NICE DAY ."<<endl;

    ofstream ls;
    ls.open("c.txt",ios::app);
    ls<<source<<" "<<destination<<" "<<cash<<"\n";
    ls.close();
    fin.close();
    char c2;
    cout<<"Press R to Ride Again"<<endl;
    cout<<"Press M to go to Menu"<<endl;
    cout<<"Press any other key to exit"<<endl;
    cin>>c2;
    if(c2=='r'||c2=='R')
    {
       // system("cls");
       // logo();
        mapp();
        prog();
    }
    else if(c2=='m'||c2=='M')
    {
       // system("cls");
       // logo();
        menu();
    }
    else
    {
        exit(1);
    }
}

void details()
{
    struct stack *p=new stack;
    isempt(p);
    string k;
    string n,b;
    int g;
    ifstream lst;
    lst.open("c.txt");
    while(lst>>n>>b>>g)
    {
        stringstream ss;
        ss << g;
        string str = ss.str();
        k=n+"        "+b+"         "+str;
        push(p,k);
    }
    cout<<"LAST RIDE DETAILS"<<endl;
    cout<<"SOURCE\tDESTINATION\tRUPEES"<<endl;
    while(pop(p)!=0)
    {
        cout<<endl;
    }
    char c;
    cout<<endl<<"Press M to go to menu"<<endl;
    cout<<"Press R to book a ride"<<endl;
    cout<<"Press any other key to exit"<<endl;
    cin>>c;
    if(c=='M'||c=='m')
    {
       // system("cls");
       // logo();
        menu();
    }
    else if(c=='r'||c=='R')
    {
       // system("cls");
       // logo();
        mapp();
        prog();
    }
    else
    {
        exit(1);
    }
}
int main()
{
    insertTrie(rootTrie,"college");
    insertTrie(rootTrie,"home");
    insertTrie(rootTrie,"starbucks");
    insertTrie(rootTrie,"company");
    insertTrie(rootTrie,"casino");
    start();

    return 0;
}
