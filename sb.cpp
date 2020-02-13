//ONLINE SALON BOOKING SYSTEM
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int i;
int pos,count=0;
string sname;
int sid;
void optionmenu();
void mainmenu();
void adduser();
void employermenu();
void addsty();
void name(int );
void check();
struct stylistnode
{
	string styname;
	int styid;
	int slot[5];
	struct stylistnode* next;
}*temp1,*first1,*ptr1,*p1;
struct usernode
{
    string username;
    string password;
    string firstname;
    string lastname;
    string mobileno;
    string emailid;
    int num=0;
    string styn;
    struct usernode* next;
}*temp,*first,*ptr,*p;
int main()
{
	int j;
	cout<<"ENTER YOUR CHOICE"<<endl;
	cout<<"1.>USER PORTAL"<<endl;
	cout<<"2.>EMPLOYER PORTAL(*USERS ARE DENIED ACCESS TO THESE PORTAL*)"<<endl;
	cout<<"*****If you access USER PORTAL you cannot go back to EMPLOYER PORTAL"<<endl;
	cin>>j;
	switch(j)
	{
		case 1:optionmenu();break;
		case 2:employermenu();break;
	}
}
void employermenu()
{
	int y;
	cout<<"ENTER THE ACCESS CODE TO PROCEED(123):";
	cin>>y;
	cout<<"-----------------------------------------------"<<endl;
	if(y==123)
	{
		addsty();
	}
	else
	{
			cout<<"ENTER CORRECT ACCESS CODE"<<endl;
			employermenu();
	}	
}
void optionmenu()
{
	cout<<"WELCOME TO ONLINE SALON BOOKING SYSTEM"<<endl;
	cout<<"1.Existing user"<<endl;
	cout<<"2.New user"<<endl;//Initially enter as new user as no exixting user exist previously
	cin>>i;
	switch(i)
	{
		case 1:mainmenu();break;
		case 2:adduser();break;
	}
}
void addsty()
{
	temp1=new struct stylistnode[1];
	cout<<"ENTER THE NAME OF THE STYLIST:";
	cin>>temp1->styname;
	cout<<"ENTER THE STYLIST ID:";
	cin>>temp1->styid;
	cout<<"ENTER THE RESPECTIVE SLOTS FOR THE STYLIST"<<endl;
	cout<<"##ENTER THE DEFAULT VALUES INTO THE EMPTY SLOT(1-5)"<<endl;
	for(i=0;i<5;i++)
	{
		cin>>temp1->slot[i];
		cout<<"\r";
	}
	temp1->next=NULL;
	if(first1==NULL)
    {
    	
        first1=temp1;
    }
    else
    {
        ptr1=first1;
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
        }
        ptr1->next=temp1;
    }
	int ll;
	cout<<"<1>ENTER AGAIN TO ADDING STYLIST"<<endl;
	cout<<"<2>ENTER TO LOG OUT"<<endl;
	
	cin>>ll;
	switch(ll)
	{
		case 1:addsty();break;
		case 2:main();break;
	}
}
void adduser()
{
    string pass,cpass;
    temp = new struct usernode[1];
    cout<<"Username:";
    cin>>temp->username;
    cout<<"Password:";
    cin>>pass;
    cout<<"Confirm Password:";
    cin>>cpass;
    while(cpass!=pass)
    {
        cout<<"Passwords do not match"<<endl;
        cout<<"Enter the correct password"<<endl;
        cout<<"Password:";
        cin>>pass;
        cout<<"Confirm Password:";
        cin>>cpass;
    }
    if(cpass==pass)
    temp->password=pass;
    cout<<"Firstname:";
    cin>>temp->firstname;
    cout<<"Lastname:";
    cin>>temp->lastname;
    cout<<"Mobile Number:";
    cin>>temp->mobileno;
    cout<<"Emailid:";
    cin>>temp->emailid;
    temp->next=NULL;
    if(first==NULL)
    {
    	
        first=temp;
    }
    else
    {
        ptr=first;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    cout<<"SUCESSFULLY ADDED!"<<endl;
    optionmenu();
}
void mainmenu()
{
    string userid;
	string pw;
	int f,c=0;
	int xz;
    cout<<"ENTER USERNAME:"<<endl;
    cin>>userid;
    cout<<"ENTER PASSWORD:"<<endl;
    cin>>pw;
    p=first;
    while(p!=NULL)
    {
    	if((p->username==userid) && (p->password==pw))
    	{
			cout<<"LOGGED IN SUCCESFULLY"<<endl;
			c=1;
			
			break;
		}
    	p=p->next;
	}
 	if(c!=1)
	{
		cout<<"INVALID USERNAME OR PASSWORD"<<endl;
		cout<<"<1.ENTER VALID USERNAME AND PASSWORD"<<endl;
		cout<<"<2.IF NOT REGISTERED THEN SIGN IN TO THE USER PORTAL"<<endl;
		cin>>xz;
		switch(xz)
		{
			case 1:mainmenu();break;
			case 2:optionmenu();break;
		}
	}
	else if(c==1)
	{
		int t;
		p1=first1;
		if(p->num!=0)
		{
			cout<<"***YOU ARE ALREADY REGISTERED!"<<endl;
			cout<<"YOUR APPROVED SLOT NUMBER-----";
			cout<<p->num<<endl;
			cout<<"WITH HAIR STYLIST----";
			cout<<p->styn<<endl;
			cout<<"1.ENTER TO CANCEL APPOINTMENT"<<endl;
			cout<<"2.ENTER TO LOG OUT"<<endl;
			cout<<"ENTER YOUR CHOICE:";
		    cin>>t;
		    switch(t)
		    {
		    	case 2:optionmenu();break;
		    	case 1:
		    		{
		    		if(p->num!=0)
					{
						p1=first1;
						while(p1!=NULL)
						{
							if(p1->styname==p->styn)
							{
								for(i=0;i<5;i++)
								{
									if(p1->slot[i]==0)
									{
									p1->slot[i]=p->num;
									p->num=0;
									}
								}
								
							}
							p1=p1->next;
						}
						cout<<"YOUR APPROVED APPOINTEMNT IS CANCELLED"<<endl;
						optionmenu();
					}
					else
					{
						cout<<"YOU ARE NOT APPOINTED"<<endl;
						mainmenu();
					}
					break;
					}
			}	
		}
		else 
		{
		int t;
		cout<<"*****WELCOME TO BOOKING PORTAL*****"<<endl;
		cout<<"CHECK FROM THE AVAILABILITY OF THE SLOTS"<<endl;
		p1=first1;
		while(p1!=NULL)
		{
			cout<<"Empty slots for the hair stylist----";
			cout<<p1->styname<<endl;
			cout<<"ID for the stylist----";
			cout<<p1->styid<<endl;
			for(i=0;i<5;i++)
			{
				if(p1->slot[i]!=0)
				{
					cout<<p1->slot[i]<<endl;
				}
			}
			p1=p1->next;
			
		}
		name(c);

				}
}
}
				
void name(int p)
{
	
	if(p==1)
	{
		cout<<"NAME OF THE STYLIST:";
		cin>>sname;
		cout<<"STYLIST ID:";
		cin>>sid;
		check();
	}
}
void check()
{
	int slno;
	int xy=0;
	int flag=0;
	p1=first1;
	while(p1!=NULL)
	{
		if((p1->styname==sname) && (p1->styid==sid))
		{
			p->styn=p1->styname;
			cout<<"*Slot 1 - 8am to 9am"<<endl;
			cout<<"*Slot 2 - 9am to 10am"<<endl;
			cout<<"*Slot 3 - 10am to 11am"<<endl;
			cout<<"*Slot 4 - 4pm to 5pm"<<endl;
			cout<<"*Slot 5 - 5pm to 6pm"<<endl;
			cout<<"ENTER THE SLOT NUMBER(1-5):";
			cin>>slno;
			p->num=slno;
			for(i=0;i<5;i++)
			{
				if(p1->slot[i]==slno)
				{
					p1->slot[i]=0;
					cout<<"______APPOINTMENT SUCCESSFULL_____"<<endl;
					flag=1;
					break;
				}	
			}
			if(flag==0)
			{
				int z;
				cout<<"-----THIS SLOT IS NOT EMPTY-----"<<endl;
				cout<<"!!!!!!PLEASE CHECK FOR ANOTHER SLOT"<<endl;
				cout<<"****AVAILABLE SLOTS FOR THE STYLIST****"<<endl;
				cout<<"1.YOU CAN SELECT FROM THE AVAILABILITY OF THE EMPTY SLOTS FOR THE SAME STYLIST or"<<endl;
				cout<<"2.REGISTER WITH ANOTHER STYLIST"<<endl;
				cout<<"ENTER YOUR CHOICE:";
				cin>>z;
				switch(z)
				{
					case 1:				
					
				{	
					for(i=0;i<5;i++)
					{
					if(p1->slot[i]!=0)
					{
						cout<<"->";
						cout<<p1->slot[i]<<endl;
					}
				}
					check();break;
				}
					case 2:name(1);break;
					
				}
			}
			xy=1;
			break;
		}
		p1=p1->next;
	}
	if(xy!=1)
	{
		cout<<"INVALID NAME OR ID"<<endl;
		cout<<"PLEASE ENTER THE DETAILS CORRECTLY!!!!"<<endl;
		name(1);
	}
	optionmenu();
}