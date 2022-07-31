#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <iomanip>
#include<list>
#include<iterator>
#include<vector>
#include <bits/stdc++.h>


using namespace std;
const int N = 7;
void addEdge(int graph[][7],int u,int v);
void displayAdjList(list<int> adj_list[], int v);
void add_edge(list<int> adj_list[], int u, int v);
vector<pair<int, int> > adj[N];
namespace station_list
{
	
    string m1_line[23] = {	"OSB-Törekent:none", "GOP:none", "Fatih:none", "Harikalar Diyarý:none", "Devlet Mahallesi:none", "Eryaman5:none",
                            "Eryaman1:none", "Ýstanbul yolu:none", "Botanik:none", "Mesa:none", "Batý merkezi:none",
                            "Batýkent:none", "ostim:none ", "Macunköy:none", "Hastane:none", "Demetevler:none",
                            "yenimahalle:Teleferik", "Ývedik:none", "Akköprü:none", "Atatürk Kültür Merkezi:M4 line", "Ulus:none","Sihhiye:none","15 temmuz kýzýlay:A1 line or M2 line"};

    string a1_line[10] = {	"Aþti:none", "Emek:none","Bahçelievler:none", "Anadolu:none",
    							"Maltepe:none", "Demirtepe:none", "15 temmuz kýzýlay :M1 line or M2 line or contiune line", "Kolej:none", "Kurtuluþ:none",
    							"Dikmenevi:none"};
    							
    string m2_line[11] = {	"Koru:none", "Çayyolu:none","Ümitköy:none", "Beytepe:none",
    							"Tarým Bakanlýðý Danýþtay:none", "ODTÜ:none", "MTA:none", "Söðütözü:none", "Milli Kütüphane:none",
    							"Necatibey:none","15 temmuz kýzýlay :M1 line or a1 line "};
								
	string m4_line[9] = {	"Þehitler:none", "Dutluk:none","Kuyubaþý:none", "Mecidiye:none",
    							"Belediye:none", "Meteroloji:none", "Dýþkapý:none", "ASKÝ:none", "Atatürk Kültür Merkezi:M1 line"};							
															
}

void clrscr()
{
	system("cls");
}
class station
{
	string name;
	string connection;

	public:													
	//specifies if the station is connected to some other line

	void getdata(string nameConnection)
	{
		int pos = nameConnection.find(":");
		name = nameConnection.substr(0,pos);
		connection = nameConnection.substr(pos+1);
	}

	string return_name()
	{
	    return name;
	}
	string return_connection()
	{
        return connection;
	}
};

class metroline
{
	string color;
    char condition;
    station stations[50];
    station test;

public:

	metroline(const char* clr)
	{
	    if(clr == "m1")
        {
            color = clr;
            condition = 'k';
            for(int i=0; i<23; i++)
            {
                stations[i].getdata(station_list::m1_line[i]);
            }
		}
		else if (clr == "a1")
		{
			color = clr;
			condition = 'k';

			for(int i=0; i<10; i++)
            {
                stations[i].getdata(station_list::a1_line[i]);
            }
		}
		else if (clr == "m2")
		{
			color = clr;
			condition = 'k';

			for(int i=0; i<11; i++)
            {
                stations[i].getdata(station_list::m2_line[i]);
            }
		}
		else if (clr == "m4")
		{
			color = clr;
			condition = 'k';

			for(int i=0; i<9; i++)
            {
                stations[i].getdata(station_list::m4_line[i]);
            }
		}
		
	}

	void display_color()
	{
		cout<<color;
	}

	void display_condition()
	{
		if(condition == 'k')
			cout<<"The "<<color<<" line is functioning properly!"<<endl;
		else
			cout<<"The "<<color<<" line is currently being investigated for technical faults!"<<endl;
	}

	void show_station(int num)
	{
	    cout<<setw(10)<<left<<num+1<<setw(30)<<left<<stations[num].return_name()<<setw(70)<<left<<stations[num].return_connection()<<endl;
	}


};
class matrix{
	public:
	
	void addEdge(int graph[][7],int u,int v){
	
	graph[u][v] = 1;
	
}
//draw adjancency matrix for a graph
int main(){

	int graph[7][7] = {0};
	addEdge(graph,0,1);
	addEdge(graph,1,0);
	addEdge(graph,1,2);
	addEdge(graph,1,3);
	addEdge(graph,2,1);
	addEdge(graph,3,1);
	addEdge(graph,3,4);
	addEdge(graph,3,5);
	addEdge(graph,3,6);
	addEdge(graph,4,3);
	
	
	addEdge(graph,5,3);
	addEdge(graph,6,3);
	
	
	for(int i=0;i<7;i++){
	   
		cout<<"\t";
		cout<<"|";
		for(int j=0;j<7;j++){
			
			cout<<graph[i][j]<<" ";
		    	cout<<"|";
		   
		}
		cout<<endl;
	
	}
	return 0;
}
};

class listed{
	public:
		void displayAdjList(list<int> adj_list[], int v) {
   for(int i = 0; i<v; i++) {
      cout << i << "--->";
      list<int> :: iterator it;
      for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
         cout << *it << ",";
      }
      cout << endl;
   }
}
void add_edge(list<int> adj_list[], int u, int v) {    //add v into the list u, and u into list v
   adj_list[u].push_back(v);
   adj_list[v].push_back(u);
}
int main() {
   int v = 7;    //there are 7 vertices in the graph
   //create an array of lists whose size is 7
   
   
   list<int> adj_list[v];
   add_edge(adj_list, 0, 1);
   add_edge(adj_list, 1, 2);
   add_edge(adj_list, 1, 3);
   add_edge(adj_list, 3, 4);
   add_edge(adj_list, 5, 3);
   add_edge(adj_list, 6, 3);
  
   displayAdjList(adj_list, v);
}
	
};
	
class weight{
	public:

vector<pair<int, int> > adj[N];
 
int main(){
     
  
 
 
    // build the graph
    adj[0].push_back(make_pair(1, 40));
    adj[1].push_back(make_pair(0, 40));
	adj[1].push_back(make_pair(2, 18));
	adj[1].push_back(make_pair(3, 8));
    adj[2].push_back(make_pair(1, 18));
    adj[3].push_back(make_pair(4, 8));
    adj[3].push_back(make_pair(5, 24));
    adj[3].push_back(make_pair(6, 36));
    adj[4].push_back(make_pair(3, 8));
    adj[5].push_back(make_pair(3,24));
 
    adj[6].push_back(make_pair(3, 36));
    
 
    // print the graph
    int v, w,u;
    
    for (int u=0; u<N; u++) {
        cout << "Node " << u << " has the following neighbors:\n";
 
        for (auto it=adj[u].begin(); it!=adj[u].end(); it++) {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight w=" << w <<"minute"<< "\n";
        }
 
        cout << "\n";
    }
    
    return 0;
}
};
	

int main()
{

	setlocale(LC_ALL, "Turkish");
	clrscr();
	metroline m1("m1"),m2("m2"),m4("m4"),a1("a1");
	matrix b1;
	listed c1;
	weight w1;
	int choice,ch;
	char char_choice;

	do
	{
	
		clrscr();
		system("color 0A"); 
		cout<<"\t\t\t\t\t::::::::MAKE BY ELÝF NUR ASLIHAN CELEPOÐLU:::::::::::\n\t\t ->BEYKOZ UNIVERSITY  \n\t\t ->COMPUTER ENGINEERÝNG \n\t\t ->DÝSCRETE COMPUTATIONAL STRUCTURES \n \t\t ->PROJECT 2  "<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t\t\t#################### MENU ####################"<<endl;
		cout<<"\t1. Show Station List."<<endl;
		cout<<"\t2. Show operating metro lines."<<endl;
		cout<<"\t3. Show matrix."<<endl;
	    cout<<"\t4.Show adcanceny list."<<endl;
	    cout<<"\t5.Show weight graph."<<endl;
		cout<<"\tEnter your choice: ";
		cin>>choice;
		

		switch(choice)
		{
			case 1: clrscr();
			        cout<<"Ankara rail systems and the names of the stops of the lines"<<endl;
			        cout<<"Total four lines"<<endl;
			        cout<<"These are m1/a1/m2/m4"<<endl;
					cout<<"Show station list for: "<<endl;
					cout<<"1. m1 line"<<endl;
					cout<<"2. a1 line"<<endl;
					cout<<"3. m2 line"<<endl;
					cout<<"4. m4 line"<<endl;
					cout<<"Enter your choice: ";
					cin>>ch;
                    cout<<endl;
                    cout<<setw(10)<<left<<"S. No."<<setw(30)<<left<<"Station Name"<<setw(50)<<left<<"Connects to"<<endl;
					if(ch == 1)
	                {
	                    for(int i=0; i<21; i++)
                            m1.show_station(i);
	                }
	                else if(ch == 2)
	                {
	                    for(int i=0; i<10; i++)
                            a1.show_station(i);
	                }
	                else if(ch == 3)
	                {
	                    for(int i=0; i<11; i++)
                            m2.show_station(i);
	                }
	                else if(ch == 4)
	                {
	                    for(int i=0; i<9; i++)
                            m4.show_station(i);
	                }
	                
					break;

			case 2: clrscr();
			        
			        cout<<"Ankara rail systems and the names of the stops of the lines"<<endl;
			        cout<<"Total four lines"<<endl;
			        cout<<"These are m1/a1/m2/m4"<<endl;
					cout<<"Show operating conditions for: "<<endl;
					cout<<"1. m1 line"<<endl;
					cout<<"2. a1 line"<<endl;
					cout<<"3. m2 line"<<endl;
					cout<<"4. m4 line"<<endl;
					cout<<"Enter your choice: ";
					cin>>ch;
					
					if(ch == 1)
	                {
	                    for(int i=0; i<21; i++)
                            m1.show_station(i);
	                }
	                else if(ch == 2)
	                {
	                    for(int i=0; i<10; i++)
                            a1.show_station(i);
	                }
	                else if(ch == 3)
	                {
	                    for(int i=0; i<11; i++)
                            m2.show_station(i);
	                }
	                else if(ch == 4)
	                {
	                    for(int i=0; i<9; i++)
                            m4.show_station(i);
	                }
	                
					break;
           case 3: clrscr();
                cout<<"\t\t::::::::::::::::::::::::::::::Adjacency matrix::::::::::::::::::::::::::::::::::::::"<<endl;
              
                cout<<"\t\tCode number system showed"<<endl;
                cout<<"____________________________________________"<<endl;
                cout<<"0->OSB station\n1->Atatürk kültür merkezi station\n2->Þehitler station\n3->15 temmuz kýzýlay milli iradesi\n4->Dikmenevi station\n5->Aþti station\n6->Koru station"<<endl;
                cout<<endl<<endl;
                cout<<"_______________________________________________"<<endl;
				cout<<"v={0,1,2,3,4,5,6} E={(0,1),(1,2),(1,3),(3,4),(5,3),(6,3)}"<<endl<<endl;
				cout<<"=Undirected graph\n=Symetric\n=Diognal=0"<<endl<<endl;
				cout<<"\t\tShow matrix"<<endl;
				cout<<"_______________________________________________"<<endl<<endl<<endl;
	
				
				
			b1.main();
			break;
			case 4: clrscr();
                cout<<"\t\t\t\t:::::::::::::::::::::Adjacency List representation::::::::::::::::"<<endl;
                cout<<"\t\tCode number system showed"<<endl;
                cout<<"____________________________________________"<<endl;
                cout<<"0->OSB station\n1->Atatürk kültür merkezi station\n2->Þehitler station\n3->15 temmuz kýzýlay milli iradesi\n4->Dikmenevi station\n5->Aþti station\n6->Koru station"<<endl;
                cout<<endl<<endl;
                cout<<"_______________________________________________"<<endl;
				cout<<"v={0,1,2,3,4,5,6} E={0->1 ,  1->0,2,3,   3->1,4,5,6,   4->3,   5->3,   6->3}";
		    c1.main();
			break;
			case 5: clrscr();
                 cout<<"\t\t:::::::::::::::::::::::::::::::::::: weight graph ::::::::::::::::::::::::::::::::::::::"<<endl<<endl;
                 cout<<"\t\tCode number system showed"<<endl;
                 cout<<"____________________________________________"<<endl;
                 cout<<"0->OSB station\n1->Atatürk kültür merkezi station\n2->Þehitler station\n3->15 temmuz kýzýlay milli iradesi\n4->Dikmenevi station\n5->Aþti station\n6->Koru station"<<endl;
                cout<<endl<<endl;
                cout<<"_______________________________________________"<<endl;
				cout<<"        v={0,1,2,3,4,5,6}          E={(0,1),(1,2),(1,3),(3,4),(5,3),(6,3)}"<<endl;
				cout<<endl<<endl;
				cout<<"\t\tCalculate weight(time)"<<endl;
				cout<<"_________________________________________________"<<endl;
                cout<<"0<->1=2*20=40 minute\n1<->=9*2=18 minute\n1<->3=4*2=8 minute\n3<->4=4*2=8 minute\n5<->3=8*3=24 minute\n6<->3=12*3=36 minute"<<endl;
                cout<<endl<<endl;
                cout<<"\t\tShowed weight graph"<<endl;
                cout<<"_______________________________________________________"<<endl;
		   w1.main();
			break;

			
					

					
		}

		cout<<"\nWould you rather continue?: ";
		cin>>char_choice;

	} while(char_choice == 'y' || char_choice == 'Y');
	return 0;
}
