#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
class Doctor;
class Vaccine;
using namespace std;
class Display{
	public:
		virtual void showdetails()=0;
};
class symptom: public Display{
	
		string arr[10];
		int count;
		public:
			symptom(){
				count=0;
			}
			
		void addsymptoms(){
		string choice;
		string a;
		fflush(stdin);
		cout << "Enter the name of the symptom"<<endl;
		getline(cin,a);
		arr[count]=a;
		count++;
		if(count==10){
			cout << "Cannot Enter more Symptoms on this system!" <<endl;
			return ;
		}
		cout << "Do you want to add more symptoms? ";
		getline(cin,choice);
		if(choice=="yes"){
			addsymptoms();
		}
		else{
			return;
		}
	}
		void showdetails(){
			cout << "BELOW ARE THE LISTED SYMPTOMS:" <<endl;
			for(int i=0; i<count; i++){
				cout<<i+1<<". "<<arr[i]<<endl;
			}
		}
		
		
		
	friend class patient;
			
};
class Identity:public Display{
	int cnic;
	string dob;
	string address;
	string gender;
	int postalcode;
	public:
		void setcnic(int n){
			cnic=n;
		}
		void setdob(string d){
			dob=d;
		}
		void setaddress(string a){
			address=a;
		}
		void setgender(string p){
			gender=p;
		}
		int getcnic(){
			return cnic;
		}
		string getdob(){
			return dob;
		}
		string getaddress(){
			return address;
		}
		string getgender(){
			return gender;
		}
		void setcode(int _code){
			postalcode=_code;
		}
		int getcode(){
			return postalcode;
		}
		void showdetails(){
			cout << "CNIC: "<<cnic<<endl;
			cout << "Date Of Birth: "<<dob<<endl;
			cout << "Address: "<<address<<endl;
			cout << "Gender: "<<gender<<endl;
			cout << "Postal Code: "<< postalcode <<endl;
		}
		
		
		
		friend class patient;
		
		
};

class Center: public Display{
	protected:
		int cenchoice;
	string array[5];
	int code[5];
	public:
		Center(){
			array[0]= "North Nazimabad";
			array[1]= "Gulshan-e-Iqbal";
			array[2]= "Johar";
			array[3]= "Clifton";
			array[4]= "Saddar";	
			code[0]=1212;
			code[1]=1512;
			code[2]=1812;
			code[3]=2012;
			code[4]=2992;
		}
		
		void showdetails(){
			cout <<"Center 1: "<<array[0]<<endl;
			cout <<"Center 2: "<<array[1]<<endl;
			cout <<"Center 3: "<<array[2]<<endl;
			cout <<"Center 4: "<<array[3]<<endl;
			cout <<"Center 5: "<<array[4]<<endl;
		}
	
};
class Vaccine:public Display{
	
		string vaccine[5];
		string dose1;
		bool d1;
		string dose2;
		bool d2;
		public:
			Vaccine(){
				vaccine[0]="Pfizer";
				vaccine[1]="Sinopharm";
				vaccine[2]="Sinovac";
				vaccine[3]="AstraZeneca";
				vaccine[4]="Moderna";
			}
			
		void showdetails(){
			cout << "Available Vaccines" << endl;
			for (int i=0 ; i<5; i++){
				cout << i+1 << ". "<<vaccine[i]<<endl;
			}
			system("pause");
		}
		void setdose1(string dose1){
			this->dose1=dose1;
		}
		void setdose2(string dose2){
			this->dose2=dose2;
		}
	   void setd1(bool d1){
			this->d1=d1;
		}
		void setd2(bool d2){
			this->d2=d2;
		}
		string getdose1(){
			return dose2;
		}
		string getdose2(){
			return dose2;
		}
		bool getd1(){
			return d1;
		}
		bool getd2(){
			return d2;
		}
		friend class patient;
};

class Doctor:public Display{
	
 	
	 string arr[14]= {"Doctor Ahmed","Dr.Tanzeel Adnan","Dr.Hamza Imam", "Dr.Abdullah Hussain","Dr.Saaim Zeeshan","Dr.Saad Hussain","Dr.Sabih Uddin", "Dr.Huzaifa Kashif", "Dr.Farhan Ali", "Dr.Taha Akhtar", "Dr.Huzaifa Farooqi","Dr.Hasnain Aziz","Dr.Khizer Raza","Dr. Zuhair Ahmed"};
	 string Qualifications[13]={"MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)" ,"MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)","MBBS (HARVARD MEDICAL SCHOOL)"};
	 bool available[14] = {0,1,0,0,0,1,1,1,1,0,1,1,0,1};
	string doctor[100];

public:
void showdetails(){
	cout << "ALL DOCTORS" <<endl;
	for (int i=0 ; i<13 ;i++){
		cout << "Doctor "<<i+1 <<": "<<arr[i]<<endl;
	}
	
}
void availabledoctors(){
	cout << "AVAILABLE DOCTORS "<<endl;
	for(int i=0 ; i<13;i++){
		if(available[i]==true){
			cout << "Doctor "<<i+1<<": "<<arr[i]<<endl;
		}
	}
}
void Doctormenu(){
	int choice;
	do{
	cout <<"1.Show All Respective Doctors "<<endl;
	cout <<"2.Show Availabe Doctors " <<endl;	
	cin>>choice;
			fflush(stdin);
			switch(choice){
				case 1:
					system("cls");
					showdetails();
				    system("pause");
				    system("cls");
				    break;
				case 2:
					system("cls");
					availabledoctors();
				    system("pause");
				    system("cls");
			        break;
	}
}while(choice<3);

}
friend class patient;
};




class patient : public Center{
	string name[100] = {"Hamza","Tom", "Michael", "Clarke", "Jimmy", "Anderson", "Rohit", "Sharma"} ;
	int age[100] = {45,38,94,11,43,67,22,45};
	symptom symptoms[100];
	string blood_group[100]= {"B-","A+","B+","B-","A+","B+","B-","A+"};
	Vaccine vacine[100];
	Identity identity[100];
	string cent[100];
	string doc[100];
	int count;
	public:
		patient(){
			count=8;
		}
 void Register(){
	try{
		 
		int _cnic;
		
		string _dob;
		string _address;
		string _gender;
		int _code;
		 	
		fflush(stdin);

    	string choice;
    	cout << "Enter Patient's Name: ";
    	getline(cin,name[count]);
    	cout << "Enter Patient's Age: ";
    	cin>>age[count];
    	if(age[count]<0 || age[count]>150)
    	throw "Invalid Age Entry";
    	fflush(stdin);
    	cout<< "Enter your Gender: " ;
    	getline(cin,_gender);
    	if(_gender != "male" && _gender != "Male" && _gender != "female" && _gender != "Female")
    	throw "Invalid Gender Entry!";
    	identity[count].gender=_gender;
    	fflush(stdin);
        cout << "Enter Blood Group ";
		 getline(cin,blood_group[count]);
		 cout << "Enter your CNIC Number: ";
		 cin>>_cnic;
		 fflush(stdin);
		 identity[count].cnic=_cnic;
		 cout << "Enter you Date of Birth: ";
		 getline(cin,_dob);
		 fflush(stdin);
		 identity[count].dob=_dob;
		 cout << "Enter your Permenant Address : ";
		 getline(cin,_address);
		 identity[count].address=_address;		 
		 fflush(stdin);
		 
		 count++;
	}
	catch(const char* str){
		cout << str <<endl;
		cout <<"Registration Process Failed! Please Re-Register yourself "<<endl;
		system("pause");
		system("cls");
		Register();
	}
}

void showdetails(){
	int _cnic;
	cout << "Enter Patient's CNIC: ";
	cin>>_cnic;
	for (int i=0 ; i< 100 ;i++){
    if(_cnic==identity[i].cnic){
	
	cout << "FINDING PATIENT IN THE DATABASE "<<endl;
	Sleep(3500);
	cout << "Patient Found Successfully!"<<endl;
	Sleep(3000);
	system("cls");
	cout <<"Patient's Name: "<<name[i]<<endl<<endl;
	cout <<"Patient's Age: "<<age[i]<<endl<<endl;
	cout <<"Patient's Gender: "<<identity[i].cnic<<endl<<endl;
	cout <<"Patient's Address: "<<identity[i].address <<endl<<endl;
	cout <<"Patient's Blood Group: "<<blood_group[i] <<endl<<endl;
	cout <<"Patient's Vaccine name for Dose 1: "<<vacine[i].getdose1()<<endl<<endl;
	cout <<"Dose 1 Status: ";
	if (vacine[i].getd1()==false){
		cout << "Not Applied"<<endl;
	}
	else
	cout << "Applied";
	
}
}
}
void addsymptoms(){

  try{
  	int count2=0;
	
	     int _cnic;
	    cout << "Enter Patient's CNIC" ;
	    cin>>_cnic;
		for(int i=0 ;i <100 ; i++)
		if(_cnic==identity[i].cnic){
		
		cout << "Patient Name: " <<name[i]<< " Found! "<<endl;
		string a;
		fflush(stdin);
		for (int i=0 ; i< 10; i++){
		cout << "Describe your symptom "<< i+1 <<endl;
		getline(cin,a);
		symptoms[i].arr[count]=a;
		count2++;
		if(count2==10){
			cout << "Cannot Enter more Symptoms on this system!" <<endl;
			return ;
		}
		 else if (a=="no more symptoms"){
	     throw  "Returning to Menu!";
			
		}
	}
}
}
catch(const char* str){
	cout << str <<endl;
	return;
}
}

		 
	
	void choosevaccinedose1(){
		try{
		
		string n;
		cout << "Enter Patient Name: ";
	fflush(stdin);
		cin>> n;
		fflush(stdin);
		for (int i=0 ; i< 100;i++){
			if(n==name[i]){
			string v;
		    cout << "Enter the name of Vaccine "<<endl;
		    fflush(stdin);
		    cin>>v;
		    fflush(stdin);
		     if(v!="Pfizer" && v!="Sinopharm" && v!="Sinovac" && v!="AstraZeneca" && v!="Moderna")
		     	throw "Invalid Vaccine Name! Please Retry";
		     	
			 	cout << "Vaccine Choosen SuccessFully!"<<endl;
			 	vacine[i].dose1=v;
			 
			
			}
		}
		
	}
	catch(const char* str){
		cout << str <<endl;
		cout << "Please choose your Vaccine Again!"<<endl;
		system("pause");
		system("cls");
		choosevaccinedose1();
		
	}
}
	void applyvaccine1(){
		string choice;
		cout << "Have you chosen the Vaccine First?";
		cin >> choice;
		fflush(stdin);
		if(choice=="no"){
			cout << "First choose Vaccine for the Patient!.."<<endl;
			choosevaccinedose1();
		}
		else{
			string n;
			cout << "Enter the Patient's Name: ";
			cin>>n;
			fflush(stdin);
			for(int i=0; i<100;i++){
				if(n==name[i]){
					vacine[i].setd1(true);
					cout << "First Dose Applied Successfully! Please Visit after 2 months!"<<endl;
				}
			}
			
			
		}
	}
		void allotcenter(){
			int choice;
			int index;
			cout << "Enter your cnic ";
			cin>>choice;
			for(int i=0 ;i<100;i++){
				if(choice==identity[i].getcnic()){
					int _code;
					cout << "Patient : "<<name[i] <<" by the name Found!"<<endl;
					cout << "Enter your Postal Code: ";
		            cin >> _code;
		            identity[i].setcode(_code);
		            for(int i=0; i<5;i++){
					
		            if(_code==code[i]){
		            	cout << "Finding Your Nearest Center!"<<endl;
		            	cout << "Found SuccessFully!"<<endl;
		            	cout << "Your Vaccination Center is: "<<array[i]<<endl;
		            	index=i;
					}
				}
					cent[count]=array[index];
		             
		            	
					
				}
			}
			
		}
		
void alottdoctor(){

try{
Doctor d1;
	int _cnic;
	cout << "Enter Patient's CNIC ";
	cin>>_cnic;
	for (int i=0 ; i<100; i++){
		if(_cnic==identity[i].getcnic()){
			cout << "Patient Name: " <<name[i] << " Found"<<endl;
			d1.showdetails();
			int choice;
			cout <<"Please Select your Preffered Doctor!" <<endl;
			cin >> choice;
			if(choice >13)
			throw "Invalid Doctor Selection! Kindly Pick from the given pool ";
			if(d1.available[choice]==false)
			throw "The Doctor you selected is not Available at the moment";
			cout << "Please Wait while we are assigning you the doctor! "<<endl;
			cout << "Doctor Assigned! Successfull"<<endl;
		   doc[i]=d1.arr[choice];
			
		}
	}
}

catch(const char* str){
	cout << str <<endl;
	system("pause");
	system("cls");
	alottdoctor();
}
}
		
			
	

		void user(){
			int choice;
			do{	
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
		    cout << "*****************************************************************************************************************************************************************************************************************"<<endl<<endl;

			cout <<"\t\t\t\t\t\t\t\t-> REGISTER"<<endl <<endl;
			cout << "\t\t\t\t\t\t\t\t ->ADD SYMPTOMS"<<endl<<endl;
			cout << "\t\t\t\t\t\t\t\t ->SHOW SYMPTOMS"<<endl<<endl;
			cout << "\t\t\t\t\t\t\t\t ->CENTER ALLOTATION " <<endl<<endl;
			cout << "\t\t\t\t\t\t\t\t ->DOCTOR ALLOTATION " <<endl<<endl;
			cout << "\t\t\t\t\t\t\t\t ->CHOOSE VACCINE FOR DOSE ONE"<<endl<<endl;
			cout << "\t\t\t\t\t\t\t\t ->APPLY DOSE ONE"<<endl<<endl;
			cout << "\t\t\t\t\t\t\t\t ->DISPLAY PATIENT'S DETAILS"<<endl<<endl;
			
		    cout << "*****************************************************************************************************************************************************************************************************************"<<endl<<endl;

			cin>>choice;
			
			switch(choice){
				case 1:
					system("cls");
					Register();
				    system("pause");
				    system("cls");
				    break;
				case 2:
					system("cls");
					addsymptoms();
				    system("pause");
				    system("cls");
			        break;
			    case 3:
			    	system("cls");
			    	symptoms[0].showdetails();
			    	system("pause");
			    	system("cls");
			    	break;
			    case 4:
			    	system("cls");
					allotcenter();
				    system("pause");
				    system("cls");
				    break;
				 case 5:
			    	system("cls");
					alottdoctor();
				    system("pause");
				    system("cls");
				    break;   
			    case 6:
			    	system("cls");
					choosevaccinedose1();
				    system("pause");
				    system("cls");
				    break;
				case 7:
			   	system("cls");
				applyvaccine1();
			    system("pause");
			    system("cls");
				    break;
				case 8:
			   	system("cls");
				showdetails();
			    system("pause");
			    system("cls");
				    break;   
			    	
			
	}
		}while(choice<8);
}

friend class Doctor;


};





class covid_management:public Doctor,public Vaccine,public patient{
	public:
		
void loadingAnimation(int seconds) {
	try{
	
	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	       cout << "*****************************************************************************************************************************************************************************************************************"<<endl<<endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t WELCOME TO HAT COVID-19 MANAGEMENT SYSTEM! \n\n ";
            cout << "**************************************************************************************************************************************************************************************************************"<<endl<<endl;
            string password="hat123";
            string username;
            string _password;
	cout << "\t\t\t\t\t\t\t\t\t\t\tUsername: ";
	getline(cin,username);
    cout << "\t\t\t\t\t\t\t\t\t\t\tPassword: ";	
	getline(cin,_password);
	if(_password!="hat123")
	throw "ACCESS DENIED. PROGRAM IS EXITING!";
    const char animation[] = {'|', '/', '-', '\\'};
    int animationIndex = 0;

    for (int i = 0; i < seconds * 10; ++i) { // assuming 10 frames per second
        cout << "\r" << animation[animationIndex];
        cout.flush();
        animationIndex = (animationIndex + 1) % (sizeof(animation) / sizeof(animation[0]));
        this_thread::sleep_for(chrono::milliseconds(100)); 
    }

    cout << "\r"; 
    cout.flush();
}
catch(const char* str){
	cout <<str<<endl;
	cout << "PLEASE TRY AGAIN WITH THE CORRECT PASSWORD";
	Sleep(3500);
	system("cls");
	loadingAnimation(5);
}		
}

void menu()		
{
	int choice;
	loadingAnimation(5);
	cout << "Loading Complete!"<<endl;
            Sleep(3500);
            system("cls");
	do{
//	       cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
//	       cout << "*****************************************************************************************************************************************************************************************************************"<<endl<<endl;
//            cout << "\t\t\t\t\t\t\t\t\t WELCOME TO HAT COVID-19 MANAGEMENT SYSTEM! \n\n ";
//            cout << "**************************************************************************************************************************************************************************************************************"<<endl<<endl;
//            cout << "\t\t\t\t\t\t\t\t\t"
//            cout << "Loading Complete! Press Enter to Continue!"<<endl;
//            system("pause");
//            system("cls");
            cout <<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
         //    cout << "*****************************************************************************************************************************************************************************************************************"<<endl;

            cout << "*****************************************************************************************************************************************************************************************************************"<<endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t M A I N    M E N U\n"<<endl;
            cout << "*****************************************************************************************************************************************************************************************************************"<<endl;
           // cout << "*****************************************************************************************************************************************************************************************************************\n\n\n\n"<<endl;

            cout <<"\t\t\t\t\t\t\t\t\t-> User\n"<<endl;
          	cout <<"\t\t\t\t\t\t\t\t\t-> Doctors\n"<<endl;
            cout <<"\t\t\t\t\t\t\t\t\t-> Vaccine\n" <<endl;
            cout <<"\t\t\t\t\t\t\t\t\t-> Public Service Message\n"<<endl;
            cout <<"\t\t\t\t\t\t\t\t\t-> Exit\n" <<endl;
            
    	cin>>choice;
    	fflush(stdin);
      	switch(choice){
                case 1:
                	system("cls");
	                user();
	                system("pause");
	                system("cls");
	                
	                break;
	            case 2:
	            	system("cls");
	                Doctor::Doctormenu();
	                system("cls");
	                
	                break;
	            case 3:
	            	system("cls");
	            	Vaccine::showdetails();
	            	system("cls");
	            	break;
	            case 4:
	            	system("cls");
	            	cout << "*******This is a Public Service Message BY HAMZA-ABDULLAH-TANZEEL(HAT)*************"<<endl<<endl<<endl<<endl;
	            	cout <<"Kindly maintain social distancing and avoid unsual gatherings. Wear Masks in Public. Stay at home as much as you can. ";
	            	cout << "Use Sanitizers and keep yourself hygenic" <<endl;
	            	system("pause");
	            	system("cls");
	            	break;
	            case 5:
	            	system("cls");
	            	cout << "Exiting! Thankyou for using our Covid Management System!"<<endl;
	            	return ;
		 
}

}while(choice<6);
}
};

int main(){
	covid_management obj;
	obj.menu();
	return 0;
}
