
#include<iostream>
#include<string.h>
using namespace std;

int count=0;
void megbiya();
void fira();
void display();
void deleteid(int x);

struct account {
	int account_num; 
	string f_name;
	string l_name;
	int age;
	string nation;
	string city;
	double kb;
	int phone_num;
    //doubl reg_day;
	double balance;
	string bank_name;
	string bank_branche;
	account*next;
	account*prev;	
};
account *current=NULL;	
account* getinfo(account *p)

{
	cout<<"\n Know Enter The Account Informations!!. \n";
    cout<<" Enter First Name: ";
	cin>> p->f_name;
	cout<<" Enter Last Name: "; 
	cin>> p->l_name;
	cout<<" Enter Age: "; 
	cin>> p->age;
	cout<<" Enter Nationality: ";  
	cin>> p->nation; 
	cout<<" Enter City: "; 
	cin>> p->city;
	cout<<" Enter Kebele: "; 
	cin>> p->kb;
	cout<<" Enter Phone Number: "; 
	cin>> p->phone_num;
	//cout<<"Enter Registerd Day: "; 
	//cin>> p->reg_day;
	cout<<" Enter Balancce: "; 
	cin>> p->balance;
	cout<<" Enter Bank Name: "; 
	cin>> p->bank_name;
	cout<<" Enter Bank Branche: "; 
	cin>> p->bank_branche;
	return p;	
	
}

void ch(int account_num)
{
	while(current->prev!=NULL)current=current->prev;
	account* temp;
    temp=new account;
	while(true)
	{	  
		if (count!=0)     
		{
			if (current->account_num==account_num)
			{
				cout<<" element is exist\n";
				return;   
			}
			else if (account_num < current->account_num)   
			{ 
				temp= getinfo(temp);
				temp->account_num=account_num;  
				if (current->prev==NULL && current->next==NULL)	 
				{
					cout<<"Hell1";
					temp->prev=NULL;
					current->prev=temp;
					temp->next=current;
			    }
				else if(current->prev==NULL)
				{
					cout<<"Hell3";
					temp->prev=NULL;
					temp->next=current;
					current->prev=temp;
				}
			    else
			    {
					cout<<"Hell2";
					temp->prev=current->prev;
					temp->next=current;
					current->prev=temp;
					temp->prev->next=temp;
				}
				count++;
				return;
			}			                                                    
			else if(current->next==NULL)  
			{
				cout<<"Hell4";
				temp= getinfo(temp);
				temp->account_num=account_num;
				temp->next=NULL;
				current->next=temp;
				temp->prev=current;
				++count;
				return;   
							
			}
			current=current->next;
			       	
		}
	}	
}

void deleteid(int account_num)
{ 
	if(current==NULL){ 
		cout<<" element not found, empty list\n";
		return;
	}
	else
	{
		while(current->prev!=NULL)current=current->prev;
		for(account *ptr=current;ptr;ptr=ptr->next)
		{
			if(ptr->account_num==account_num){
				if(ptr->next && ptr->prev) //sera
				{
					current=ptr->prev;
					current->next=ptr->next;
					ptr->next->prev=current;
					delete ptr;
				}				
				else if(ptr->prev && !(ptr->next))//sera
				{
					current=ptr->prev;
					current->next=NULL;
					delete ptr;
				}
				else if(ptr->next && !(ptr->prev))//sera
				{
					 current=current->next;
					 current->prev=NULL;
					 delete ptr;
				}
				else //sera
				{
					delete ptr;
					current=NULL;
				}
				count--; 
				return;
			}
		}
	}
}

void locateid(int account_num)
{
	if(current==NULL)
	{
		cout<<" element not found, empty list";
		return;
	}
	else
	{
		while(current->prev!=NULL)current=current->prev;
		int pos=1;
		account* p;
		for(account *ptr=current;ptr;ptr=ptr->next)
		{
			if(ptr->account_num==account_num)
			{
				cout<<" element found at "<<pos;
				return;
			}
			++pos;
		}
		cout<<" element not found";
	}
}

void display ()
{
	system ("color 07");
				system ("cls");
	cout<<"\n #-#-# ACCOUNT INFORMATION #-#-#\n ==============================="<<endl;
	if(count==0){
	cout<<"\n empty\n";
	return;
	}
	else {
	account*disp=current;
	while(disp->prev!=NULL)
	disp=disp->prev;
	while(disp!=NULL)
	{
		cout<<"\n Account Number = " <<disp->account_num;
		cout<<"\n First Name: " <<disp->f_name;
		cout<<"\n Last Name: " <<disp->l_name;
		cout<<"\n Age: " <<disp->age;
		cout<<"\n Nationality: " <<disp->nation; 
		cout<<"\n City: " <<disp->city;
		cout<<"\n Kebele: " <<disp->kb;
		cout<<"\n Phone Number: " <<disp->phone_num;
		//cout<<"\n Registerd Day: " <<disp->reg_day;
		cout<<"\n Current Balance: " <<disp->balance;
		cout<<"\n Bank Name: " <<disp->bank_name;
		cout<<"\n Banke Branche: "<<disp->bank_branche;
		cout<<"\n----------------------------------";
		cout<<"\n----------------------------------";
		if(disp->next==NULL){
			break;
		}
		disp=disp->next;
	}
}
}
	
int main () 
{
	megbiya();
	start:
		 int m = 0;
	fira();
	int account_num;
	//int inn = 0;
	//cin>>inn;
	char in;
	cin>>in;
	if(in=='A'||in=='a')
		{
			system ("color 07");
				system ("cls");
			cout<<"\n Enter Account Number = ";
			cin>>account_num;
			account*temp;
			temp=new account;
			if(account_num==0)
			goto start;
			if(current==NULL)
			{
				temp= getinfo(temp);  
				temp->account_num=account_num; 
				temp->next=NULL;
				temp->prev=NULL;
				current=temp;
				++count;
			}
			else ch(account_num);
		}
		    else if(in=='D'||in=='d'){ 
		    int account_num;
		    cout<<"\n Account Number = ";
		    cin>>account_num;
		    deleteid(account_num);
		    }
		    else if(in=='S'||in=='s')
		    display();
		    else if(in=='L'||in=='l')
		    {
		    	int account_num;
		    	cout<<"\n Account Number = ";
		    	cin>>account_num;
		    	locateid(account_num);    	
		    }
		    else if(in=='C'||in=='c')
		    {
		    	cout<<count;
		    }
		    else if(in=='H'||in=='h')
		    {
		    	system ("color 6e");
				system ("cls");
				cout <<"\n Help \n";
				cout <<" ----";
				cout<<"\n\n#-#-#- Use the following <-Later-> for accesing the program -#-#-#"<<endl;
		    	cout<<"\n  [A]. To insert new record"<<endl;
		    	cout<<"  [S]. To see all informations in the recordes"<<endl;
				cout<<"  [C]. To see how many datas are inserted"<<endl;
		    	cout<<"  [D]. To delete an item from the record"<<endl;
		    	cout<<"  [L]. To see the location of the inserted record"<<endl;
		    	cout<<"  [F]. To see information about the program"<<endl;
		    	cout<<"  [H]. To get help"<<endl;
				cout<<"  [E]. To exit the program"<<endl;
			}
			else if (in=='F'||in=='f')
			{
				system ("color 6e");
				system ("cls");
				cout <<"\n About \n";
				cout <<" -----";
			    cout <<"\n\n [ program version - 01.4 ]\n";
			    cout <<" Devloped date 13-1-2020 G.C"<<endl;
				cout <<" Last Update 01-20-2020\n";
				cout <<" copy right @2012 E.C / 2020 G.C\n";
				cout <<" Program Devloper <Cool Star Group>\n";
			}
			else if (in!='A'||in!='a'||in!='S'||in!='s'||in!='C'||in!='c'||in!='D'||in!='d'||in!='L'||in!='l'||in!='F'||in!='f'||in!='H'||in!='h'||in!='E'||in!='e')
		    cout <<"\n\a\a\a\a("<<in<<") is Invalid please Choose The later (A-S-C-D-L-F-H-E)!!";
		    if (in=='E'||in=='e')
		    goto chaw;
		    
			//if (inn>=0)
		    //cout <<"\n\a\a\a\ayou can use the lator (A-S-C-D-L-Z-H-E)!! to accsess the program: ";
	
	cout <<"\n\n>> >> Back to MENU Press (1) or Quit (2): ";
    cin >>m;
    if (m==1) 
    goto start;
    else if (m==2)
    goto chaw;	    
	chaw:
		{
			system ("color 3e");
			system ("cls");
			cout <<"\n\n\t\tThank You For Using This Program.\n\t\tCool Star Group.\n\n\n\n"<<endl;
			system ("pause");
		}

}

void fira()
{
	system("title Bank Accout Information System");
	system ("cls");
	system ("color 07");
	cout<<"\n #-#-# ACCOUNT INFORMATION SYSTEM #-#-#\n ======================================"<<endl;
	cout<<"\n\n MENU\n ---- ";
	cout<<"\n\n [A]. [ADD] RECORD TO FILE ";	 cout<<"\t\t [S]. [SHOW] RECORD FROME FILE ";
	cout<<"\n\n [C]. [COUTNT] RECORD ";  cout<<"\t\t\t [D]. [DELETE] RECORD ";
	cout<<"\n\n [L]. RECORD [LOCATION] ";  cout<<"\t\t [F]. ABOUT ";
	cout<<"\n\n [H]. [HELP] ";  cout<<"\t\t\t\t [E]. EXIT ";
	cout<<"\n\n\n>> Select Your Option From Above Latters!!: ";
	
}

void megbiya ()
{
	//char ignore;
	system("color 3e");
	cout<<"\n\n\n\t  ACCOUNT";
	cout<<"\n\n\tINFORMATION";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\n Group Members: \t\t ID:\n --------------\t\t\t ---\n";
	cout <<"\n 1. Firomsa Umer \t\t 0521\n";
	cout <<"\n 2. Abdela Zeynu \t\t 0866\n";
	cout <<"\n 3. Demeke Mkoanent \t\t 0729\n";
	cout <<"\n 4. Natnael Tefera \t\t 0605\n";
	cout <<"\n 5. Muluken ------- \t\t 0072\n";    
	cout<<"\n\n Admas University\n"<<endl;
	cout<<" D.S.&.A.A PROJECT - 01  ";
	cin.ignore();
	
}





