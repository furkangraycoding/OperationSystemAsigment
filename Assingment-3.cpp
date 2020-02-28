// FURKAN GURCAY
// 150201018
// 21.12.2018
// CS 361
// ASSIGNMENT-3
// ANTALYA BILIM UNIVERSITY

#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
// Create array for comparision
float foo[4];
class cpuschedule
{
	
    int n,Bu[20];
    float R,T,Y,U,Twt,Awt,A[10],Wt[10],w;
public:
    //Getting the No of sensors & burst time
    void Getdata();
    //First come First served Algorithm
    void Fcfs();
    //Shortest job First Algorithm
    void Sjf();
    //Round Robin Algorithm
    void RoundRobin();
    //Priority Algorithm
    void Priority();
    
};
// Implementation file for Cpu scheduling

//Getting no of sensors and Burst time
void cpuschedule::Getdata()
{
    int i;
    cout<<"\nEnter the no of sensors:";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"\nEnter The BurstTime for sensor p"<<i<<"=	";
        cin>>Bu[i];
    }
}

//First come First served Algorithm
void cpuschedule::Fcfs()
{
    int i,B[10];
    Twt=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for sensor p"<<i<<"=	";
        cout<<B[i];
    }
    Wt[1]=0;
    for(i=2; i<=n; i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];
    }

    //Calculating Average Weighting Time
    for(i=1; i<=n; i++)
    {
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    R=Awt;
    foo[0]=R;
    cout<<"\n\nTotal   Weighting Time="<<Twt;
    cout<<"\n\nAverage Weighting Time="<<Awt<<""<<endl;
    
}

//Shortest job First Algorithm
void cpuschedule::Sjf()
{
    int i,j,temp,B[10];
    Twt=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for sensor p"<<i<<"=	";
        cout<<B[i];
    }
    for(i=n; i>=1; i--)
    {
        for(j=1; j<=n; j++)
        {
            if(B[j-1]>B[j])
            {
                temp=B[j-1];
                B[j-1]=B[j];
                B[j]=temp;
            }
        }
    }

    Wt[1]=0;
    for(i=2; i<=n; i++)
    {
        Wt[i]=B[i-1]+Wt[i-1];
    }
    //calculating Average Weighting Time
    for(i=1; i<=n; i++)
    {
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    T=Awt;
    foo[1]=T;
    
    cout<<"\nTotal   Weighting Time="<<Twt;
    cout<<"\nAverage Weighting Time="<<Awt<<"";
}




//Priority Algorithm

void cpuschedule::Priority()
{
    int i,B[10],P[10],j;
    w=0.0;
    int max;
    Twt=0.0;
    max=1;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for sensor p"<<i<<"=	";
        cout<<B[i];
        cout<<"\nEnter the priority for sensor P"<<i<<"=	";
        cin>>P[i];
        if(max<P[i]){
            max=P[i];
        }
    }
    j=1;
    while(j<=max)
    {
        i=1;
        while(i<=n)
        {
            if(P[i]==j)
            {
                Wt[i]=w;
                w=w+B[i];
            }
            i++;
        }
        j++;
    }

    //calculating average weighting Time
    for(i=1; i<=n; i++){
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    Y=Awt;
    foo[2]=Y;
    cout<<"\nTotal   Weighting Time="<<Twt<<""<<endl;
    cout<<"\nAverage Weighting Time="<<Awt<<""<<endl;
}

//Round Robin Algorithm
void cpuschedule::RoundRobin()
{

    int i,j,tq,k,B[10],Rrobin[10][10],count[10];
    int max=0;
    int m;
    Twt=0.0;
    for(i=1; i<=n; i++)
    {
        B[i]=Bu[i];
        cout<<"\nBurst time for sensor p"<<i<<"=	";
        cout<<B[i];
        if(max<B[i])
            max=B[i];
        Wt[i]=0;
    }
    cout<<"\nEnter the Time Quantum=";
    cin>>tq;
    //TO find the dimension of the Rrobin array
    m=max/tq+1;

    //initializing Rrobin array
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            Rrobin[i][j]=0;
        }
    }
    //placing value in the Rrobin array
    i=1;
    while(i<=n)
    {
        j=1;
        while(B[i]>0)
        {
            if(B[i]>=tq)
            {
                B[i]=B[i]-tq;
                Rrobin[i][j]=tq;
                j++;
            }
            else
            {
                Rrobin[i][j]=B[i];
                B[i]=0;
                j++;
            }
        }
        count[i]=j-1;
        i++;
    }

    cout<<"Display";
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cout<<"Rr["<<i<<","<<j<<"]="<<Rrobin[i][j];
            cout<<"	";
        }
        cout<<"";
    }
    //calculating weighting time
    int x=1;
    i=1;
    while(x<=n)
    {
        for(int a=1; a<x; a++)
        {
            Wt[x]=Wt[x]+Rrobin[a][i];
        }
        i=1;
        int z=x;
        j=count[z];
        k=1;
        while(k<=j-1)
        {
            if(i==n+1)
            {
                i=1;
                k++;
            }
            else
            {
                if(i!=z)
                {
                    Wt[z]=Wt[z]+Rrobin[i][k];
                }
                i++;
            }
        }
        x++;
    }
    for(i=1; i<=n; i++) {
        cout<<"\nWeighting Time for sensor P"<<i<<"="<<Wt[i];
    }

    //calculating Average Weighting Time
    for(i=1; i<=n; i++) {
        Twt=Twt+Wt[i];
    }
    Awt=Twt/n;
    U=Awt;
    foo[3]=U;
    cout<<"\nTotal   Weighting Time="<<Twt<<endl;
    cout<<"\nAverage Weighting Time="<<Awt<<""<<endl;
}

//Application file for cpu Scheduling
int main()
{	

    int ch,cho;
    float min;
    cpuschedule c;
    do
    {	cout<< " " << endl;
        cout<<"1.Getting BurstTime"<<endl;
        cout<<"2.FirstComeFirstServed"<<endl;
        cout<<"3.ShortestJobFirst"<<endl;
        cout<<"4.RoundRobin"<<endl;
        cout<<"5.Priority"<<endl;
        cout<<"6.Best Option"<<endl;
        
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            c.Getdata();
            break;
        case 2:
            cout<<"\nFIRST COME FIRST SERVED SCHEDULING"<<endl;
            c.Fcfs();
            break;
        case 3:
            cout<<"\nSHORTEST JOB FIRST SCHEDULING"<<endl;
			c.Sjf();
			break;
        case 4:
            cout<<"\nROUND ROBIN SCHEDULING"<<endl;
            c.RoundRobin();
            break;
        case 5:
            cout<<"\nPRIORITY SCHEDULING"<<endl;
            c.Priority();
            break;
        case 6:
        	cout<<" "<<endl;
        	cout<<"\nBEST OPTION"<<endl;
        	c.Getdata();
			c.Fcfs();
        	c.Priority();
        	c.RoundRobin();
        	c.Sjf();
        
        	cout<<endl;       		  
        	min=foo[0];
        	int index=0;
        	
         	for(int i=0;i<4;i++)
        	 {
             if(foo[i]<min){
			 
			  min=foo[i];
               index=i;
			 }  
			   }
       		   
		   	if(index==0){
       	  	cout<<"Fcfs is best option   = "<<min<<endl;
			 }
		else	if(index==1){
         	cout<<"SJF is best option = "<<min<<endl;
			 }
		else	if(index==3){
         	cout<<"Round robin is best option = "<<min<<endl;
			 }
		else	if(index==2){
         	cout<<"Priority is best option = "<<min<<endl;
		 	}
 
            break;  
       
        }
    }
    while(ch<=5);
}

