#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>



/*Function declarations
===========================*/

void requireEnter();
void administrator();
void customer();
void addItem();
void display();
void savetofile();
void loadfromfile();
void remove();
void modify();
void buy();


using namespace std;


/*Class declaration
=====================*/


class Items{
	public:
	int no;
	string name;
	int price;
};

/*Global declaration
======================*/



int av;
Items product[100];


/*Main part of proramme
=========================*/


int main(){
	char choice;
	do{
    	cout<<"\t\tMENU ::"<<endl;
	    cout<<"\t\t\t1.Administrator"<<endl;
	    cout<<"\t\t\t2.Customer"<<endl;
	    cout<<"\t\t\t3.Exit"<<endl;
	    cout<<"choose an option"<<endl;
        choice=getch();
//		 administrator();
	     switch(choice){
		            case '1':
		            	   administrator();
		            	   break;
		            case '2':
		            	  customer();
		            	  break; 
		            case '3':
		            	 exit(1);
				 }
            requireEnter();
			system("cls");
			
	}while(choice!=27);
}




void requireEnter(){
	cout<<"Click Enter to continue..."<<endl;
	while(getch()!=13);
}



/*Administrator function
====================*/




void administrator(){
   cout<<"Welcome....\nEnter your password to continue..."<<endl;
   int password;
   cin>>password;
   if(password==11703582){
   	 char choice;
   	 do{
   	 	
   	 	fstream file("file.txt");
		if(file.is_open())
		{
			file>>av;
			cout<<"\t\tno of Items available: "<<av<<endl;
		}
   	 	 cout<<"\t\t\t1.Add Item"<<endl;
   	     cout<<"\t\t\t2.Delete Item"<<endl;
    	 cout<<"\t\t\t3.Modify Item"<<endl;
    	 cout<<"\t\t\t4.Display all Items"<<endl;
    	 cout<<"\t\t\t5.Go to back menu"<<endl;
    	 cout<<"Choose an option......"<<endl;
    	  choice=getch();
    	  switch(choice){
    	  	  case '1':
    	  	  	 addItem();
    	  	  	 break;
              case '2':
              	remove();
              	break;
              case '3':
              	  modify();
              	 break;
              case '4':
              	display();
              	break;
              case '5':
              	  main();
              	  break;
		  }
		  
		  requireEnter();
			system("cls");
		  
		}while(choice!=27);
   }	
}




/*Customer function
==================*/

void customer(){
	cout<<":::::Welcome to our place::::"<<endl;
	char choice;
	do{
		
		fstream file("file.txt");
		if(file.is_open())
		{
			file>>av;
			cout<<"\t\tno of Items available: "<<av<<endl;
		}
		cout<<"\t\t\t1.Display all Items"<<endl;
		cout<<"\t\t\t2.Buy an Item"<<endl;
		cout<<"\t\t\t3.Go to back"<<endl;
		 choice=getch();
		   switch(choice){
		   	   case '1':
		   	      display();
                  break;
		   	   case '2':
                    buy();		   	   	
				  break;  	
			  case '3':
			  	 main();
			  	 break;
		   }
		   requireEnter();
			system("cls");
		   
	}while(choice!=27);
	
}




/*AddItems function
===========================*/

void addItem(){
	cout<<"Enter product no of Item: "<<endl;
	cin>>product[av].no;
	cout<<"Name of the Item: "<<endl;
	cin>>product[av].name;
	cout<<"Price of the Item: "<<endl;
	cin>>product[av].price;
	av++;
    savetofile();
}




/*DisplayItems function
==========================*/

void display(){
    loadfromfile();
	if(av>0){
		
		cout<<"Item no \t\t Item name \t\t Item price"<<endl;
		for(int  i=0;i<av;i++){
			cout<<product[i].no<<"\t\t\t\t"<<product[i].name<<"\t\t\t\t"<<product[i].price<<endl;
		}
	}
	else
	  cout<<"There are no items available"<<endl;
}





/*SaveItems to file
======================*/

void savetofile(){
	ofstream file("file.txt");
	if(file.is_open())
	{
		file<<av<<endl;
		for(int i=0;i<av;i++){
//			file<<(i+1)<<endl;
			file<<product[i].no<<endl;
			file<<product[i].name<<endl;
			file<<product[i].price<<endl;
		}
		file.close();
	}
	else
	 cout<<"File opening for saving is failed"<<endl;
}





/*LoadItems to file
========================*/
void loadfromfile(){
	ifstream file("file.txt");
	if(file.is_open()){
		file>>av;
		if(av>0)
		{
		    int i=0;
		    do{
		   	file>>product[i].no;
			file>>product[i].name;
			file>>product[i].price; 
			i++;
				
			 }while(!file.eof());
		    cout<<"people has been loaded properly"<<endl;
		}
		else
		cout<<"file is empty"<<endl;
		
	}
	else
	 cout<<"file opening for loading is failed"<<endl;
	
}



/*RemoveItems
====================*/

void remove(){
	if(av>0)
	{
		int index;
		cout<<"which item do you want to remove"<<endl;
		cin>>index;
		if(av>=index)
		{
			for(int k=index;k<av;k++)
			{
				product[k-1].no=product[k].no;
				product[k-1].name=product[k].name;
				product[k-1].price=product[k].price;
			}
			av--;
			savetofile();
			cout<<"Deleted successfully...."<<endl;
		}
		else
		cout<<"There is no item like that"<<endl;
		 
		
	}
	else
	 cout<<"There is nothing to remove"<<endl;
}




/*ModifyItems
================*/ 

void modify(){
	display();
	if(av>0)
	{
		int index;
		cout<<"which item do you want to modify"<<endl;
		cin>>index;
		cout<<"re enter the details"<<endl;
        for(int i=0;i<av;i++)
        { 
          if(index==product[i].no)
		  { 
		    cout<<"Enter the product no: "<<endl;
		    cin>>product[i].no;
		    cout<<"Enter the product name: "<<endl;
		    cin>>product[i].name;
		    cout<<"Enter the price of the item: "<<endl;
		    cin>>product[i].price;
 		  }	
 		  else
 		  cout<<"there is no item like that index"<<endl;
	  }
     } 
	else
	 cout<<"There is nothing to remove"<<endl;
	savetofile();
	cout<<"Item modified successfully"<<endl;
	display();
}




/*Buy Items
===================*/

void buy(){
	display();
	cout<<"Enter the item no that you want to buy"<<endl;
	int n;
	static int total=0;  
	cin>>n;
	if(av>0)
	{
	for(int i=0;i<av;i++)
	if(n==product[i].no)
	{
		total=total+product[i].price;
		cout<<"total amount: "<<total;
	} 
    }
    else
    cout<<"There are no items available to buy"<<endl;
    
    
    cout<<"\nwant to buy another item (Y/N)?"<<endl;
    char c;
    c=getch();
    if(c=='Y' || c=='y')
    buy();
    else
    cout<<"Thank you.."<<endl;
}
