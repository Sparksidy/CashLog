            #include <iostream>
            #include <stdlib.h>
            #include <string>
            #include <fstream>

            #include <SQLAPI.h>
            #include <ctime>

            using namespace std;

            void intro();
            void Eateries();
            void HomeExpenditure();
            void Travel();
            void Extras();
            void ReasonEntry(int a);
            void DisplayLog();
            void DisplayEateries();
            void DisplayHomeExpenditure();
            void DisplayTravel();
            void DisplayExtras();
            void ClearLog();
            void ManageExpenses();




            int main()
            {



                int flag=1;
                char ch;

                 cout<<"**************CASHLOG APPLICATION*************"<<endl<<endl;


                do{



                 cout<<"Manage your Expenditures ?  (y/n) "<<endl;

                 cin>>ch;
                 switch(ch){
                    case 'y': system("CLS");
                              intro();
                              break;
                    case 'n': system("CLS");
                              cout<<"That's like it. Please save money"<<endl;
                              break;
                    default:  system("CLS");
                              cout<<"Please press y for yes and n for no"<<endl;
                              break;

                 }

                }while(flag && ch != 'n');


                return 0;
            }

                void intro(){

                    int number;
                    cout<<"Enter the reason of expenditure through a number"<<endl;
                    cout<<"1. Expenses"<<endl<<endl;
                    cout<<"2. Display Log"<<endl<<endl;
                    cout<<"3. Clear Log"<<endl<<endl;
                    cin>>number;

                    switch(number){

                        case 1: system("CLS");
                                ManageExpenses();
                                break;
                        case 2: system("CLS");
                                DisplayLog();
                                break;
                        case 3: system("CLS");
                                ClearLog();
                                break;

                       default: cout<<"Please enter the correct number"<<endl;
                                break;



                    }


                }

                void ManageExpenses(){

                    int number;
                    cout<<"Enter the reason of expenditure through a number"<<endl;
                    cout<<"1. Out Expenses"<<endl<<endl;
                    cout<<"2. Home Expenses"<<endl<<endl;
                    cout<<"3. Travel Expenses"<<endl<<endl;
                    cout<<"4. Extra Expenses"<<endl<<endl;

                    cin>>number;

                    switch(number){

                        case 1: system("CLS");
                                Eateries();
                                break;
                        case 2: system("CLS");
                                HomeExpenditure();
                                break;
                        case 3: system("CLS");
                                Travel();
                                break;
                        case 4: system("CLS");
                                Extras();
                                break;

                       default: cout<<"Please enter the correct number"<<endl;
                                break;



                    }


                }


                void ClearLog(){
                    int number;


                    SAConnection con;
                    SACommand cmd;

                    con.Connect("cashlog","root","sidystan",SA_MySQL_Client);
                    //cout<<"We are connected"<<endl;
                    cmd.setConnection(&con);

                    cout<<"Enter which Log you wish to clear ?"<<endl;
                    cout<<"1. Eateries "<<endl;
                    cout<<"2. Home "<<endl;
                    cout<<"3. Travel "<<endl;
                    cout<<"4. Extras "<<endl;

                    cin>>number;




                    switch(number){
                        case 1: system("CLS");
                                cmd.setCommandText("truncate eateries");
                                cmd.Execute();
                                cout<<"Your log has been cleared"<<endl;
                                break;
                        case 2: system("CLS");
                                cmd.setCommandText("truncate homeexpenditures");
                                cmd.Execute();

                                break;
                        case 3: system("CLS");
                                cmd.setCommandText("truncate travel");
                                cmd.Execute();
                                break;
                        case 4: system("CLS");
                                cmd.setCommandText("truncate extras");
                                cmd.Execute();
                                break;
                        default: cout<<"Please enter the correct number"<<endl;
                                break;

                    }

                }



                void DisplayLog(){
                    int number;

                    cout<<"Enter which Log you wish to analyse ?"<<endl;
                    cout<<"1. Eateries "<<endl;
                    cout<<"2. Home "<<endl;
                    cout<<"3. Travel "<<endl;
                    cout<<"4. Extras "<<endl;

                    cin>>number;




                    switch(number){
                        case 1: system("CLS");
                                DisplayEateries();
                                break;
                        case 2: system("CLS");
                                DisplayHomeExpenditure();
                                break;
                        case 3: system("CLS");
                                DisplayTravel();
                                break;
                        case 4: system("CLS");
                                DisplayExtras();
                                break;
                        default: cout<<"Please enter the correct number"<<endl;
                                break;



                    }



                }


                void DisplayEateries(){
                    SAConnection con;
                    SACommand cmd;

                    con.Connect("cashlog","root","sidystan",SA_MySQL_Client);
                    //cout<<"We are connected"<<endl;
                    cmd.setConnection(&con);


                    cmd.setCommandText("select* from eateries");
                    cmd.Execute();
                    bool is_Result = cmd.isResultSet();

                    //long col_count = cmd.FieldCount();

                    cout<<"Your Expenditures for Outside Eateries are as follows: "<<endl<<endl;
                    cout<<"----------------------------------------------------------------------"<<endl;




                    if(is_Result){
                        while(cmd.FetchNext()){
                             string Reason =  (const char*)cmd.Field("Reason").asString();
                             string Amount =  (const char*)cmd.Field("Amount").asString();
                             string DateTime = (const char*)cmd.Field("Date").asString();

                            cout<<"Date and Time: "<<DateTime<<"   "<<"Reason: "<<Reason <<"   "<<"Amount: "<< Amount <<"  "<<endl<<endl;
                            cout<<"----------------------------------------------------------------------"<<endl;

                        }


                    }

                }

                void DisplayHomeExpenditure(){
                     SAConnection con;
                    SACommand cmd;

                    con.Connect("cashlog","root","sidystan",SA_MySQL_Client);
                    //cout<<"We are connected"<<endl;
                    cmd.setConnection(&con);


                    cmd.setCommandText("select* from homeexpenditure");
                    cmd.Execute();
                    bool is_Result = cmd.isResultSet();

                    if(is_Result){
                        while(cmd.FetchNext()){
                             string Reason =  (const char*)cmd.Field("Reason").asString();
                             string Amount =  (const char*)cmd.Field("Amount").asString();
                             string DateTime = (const char*)cmd.Field("Date").asString();

                            cout<<"Date and Time: "<<DateTime<<"   "<<"Reason: "<<Reason <<"   "<<"Amount: "<< Amount <<"  "<<endl<<endl<<endl;


                        }


                    }



                }

                void DisplayTravel(){
             SAConnection con;
                    SACommand cmd;

                    con.Connect("cashlog","root","sidystan",SA_MySQL_Client);
                    //cout<<"We are connected"<<endl;
                    cmd.setConnection(&con);


                    cmd.setCommandText("select* from travel");
                    cmd.Execute();
                    bool is_Result = cmd.isResultSet();

                    //long col_count = cmd.FieldCount();

                    if(is_Result){
                        while(cmd.FetchNext()){
                             string Reason =  (const char*)cmd.Field("Reason").asString();
                             string Amount =  (const char*)cmd.Field("Amount").asString();

                             string DateTime = (const char*)cmd.Field("Date").asString();

                             cout<<"Date and Time: "<<DateTime<<"   "<<"Reason: "<<Reason <<"   "<<"Amount: "<< Amount <<"  "<<endl<<endl<<endl;

                        }


                    }

                }

                void DisplayExtras(){

                     SAConnection con;
                    SACommand cmd;

                    con.Connect("cashlog","root","sidystan",SA_MySQL_Client);
                    //cout<<"We are connected"<<endl;
                    cmd.setConnection(&con);


                    cmd.setCommandText("select* from extras");
                    cmd.Execute();
                    bool is_Result = cmd.isResultSet();

                    //long col_count = cmd.FieldCount();

                    if(is_Result){
                        while(cmd.FetchNext()){
                             string Reason =  (const char*)cmd.Field("Reason").asString();
                             string Amount =  (const char*)cmd.Field("Amount").asString();

                             string DateTime = (const char*)cmd.Field("Date").asString();

                             cout<<"Date and Time: "<<DateTime<<"   "<<"Reason: "<<Reason <<"   "<<"Amount: "<< Amount <<"  "<<endl<<endl<<endl;

                        }


                    }


                }



                void Eateries(){

                    int flag =1;
                    char ch;


                    cout<<"This is eatery section: "<<endl;

                    do{
                         cout<<"You wish to enter to the log (y/n)"<<endl;
                         cin>>ch;

                         switch(ch){
                            case 'y': system("CLS");
                                      ReasonEntry(1);
                                      break;

                            case 'n': cout<<"Okay"<<endl;
                                      break;


                         }
                       // break;

                    }while(flag && ch!='n');



                }

                void ReasonEntry(int a){
                    char r[30];
                    char amt[20];
                    char dateTime[100];

                    SAConnection con;
                    SACommand cmd;

                    con.Connect("cashlog","root","sidystan",SA_MySQL_Client);
                    //cout<<"We are connected"<<endl;
                    cmd.setConnection(&con);






                    switch(a){
                        case 1:{ ofstream out("Eateries.txt",ios::app);
                                if(!out){
                                cout<<"Cannot open the file"<<endl;
                                }
                                time_t now = time (0);
                                char* dt = ctime(&now);
                                strcpy(dateTime,dt);




                                cout<<"Enter your reason"<<endl;
                                cin>>r;
                                out<<r<<" ";
                                cout<<"Enter the amount"<<endl;
                                cin>>amt;
                                out<<amt<<endl;



                                // Inserting into the Database
                                cmd.setCommandText("insert into eateries(Reason,Amount,Date)values (:1,:2,:3)");

                                cmd.Param(1).setAsString() = r;
                                cmd.Param(2).setAsString() = amt;
                                cmd.Param(3).setAsString() = dateTime;

                                cmd.Execute();
                                con.Commit();
                                con.Disconnect();

                                }
                                break;

                        case 2: { ofstream out1("HomeExpenditures.txt",ios::app);
                                if(!out1){
                                cout<<"Cannot open the file"<<endl;
                                }
                                 time_t now = time (0);
                                 char* dt = ctime(&now);
                                 strcpy(dateTime,dt);



                                cout<<"Enter your reason"<<endl;
                                cin>>r;
                                out1<<r<<" ";
                                cout<<"Enter the amount"<<endl;
                                cin>>amt;
                                out1<<amt<<endl;

                                cmd.setCommandText("insert into homeexpenditure(Reason,Amount,Date)values (:1,:2,:3)");

                                cmd.Param(1).setAsString() = r;
                                cmd.Param(2).setAsString() = amt;
                                cmd.Param(3).setAsString() = dateTime;

                                cmd.Execute();
                                con.Commit();
                                con.Disconnect();




                                }
                                break;

                        case 3:{ofstream out2("Travel.txt",ios::app);
                               if(!out2){
                                cout<<"Cannot open the file"<<endl;
                                }
                                time_t now = time (0);
                                char* dt = ctime(&now);
                                strcpy(dateTime,dt);


                                cout<<"Enter your reason"<<endl;
                                cin>>r;
                                out2<<r<<" ";
                                cout<<"Enter the amount"<<endl;
                                cin>>amt;
                                out2<<amt<<endl;

                                cmd.setCommandText("insert into travel(Reason,Amount,Date)values (:1,:2,:3)");

                                cmd.Param(1).setAsString() = r;
                                cmd.Param(2).setAsString() = amt;
                                cmd.Param(3).setAsString() = dateTime;

                                cmd.Execute();
                                con.Commit();
                                con.Disconnect();



                               }
                                break;

                        case 4:{ofstream out3("Extras.txt",ios::app);
                                if(!out3){
                                cout<<"Cannot open the file"<<endl;
                                }
                                time_t now = time (0);
                                char* dt = ctime(&now);
                                strcpy(dateTime,dt);


                                cout<<"Enter your reason"<<endl;
                                cin>>r;
                                out3<<r<<" ";
                                cout<<"Enter the amount"<<endl;
                                cin>>amt;
                                out3<<amt<<endl;


                                cmd.setCommandText("insert into extras(Reason,Amount,Date)values (:1,:2)");

                                cmd.Param(1).setAsString() = r;
                                cmd.Param(2).setAsString() = amt;
                                cmd.Param(3).setAsString() = dateTime;

                                cmd.Execute();
                                con.Commit();
                                con.Disconnect();





                               }
                                break;


                    }
                }

                void HomeExpenditure(){

                    int flag =1;
                    char ch;


                    cout<<"This is home expenditure section:  "<<endl;

                    do{
                         cout<<"You wish to enter to the log (y/n)"<<endl;
                         cin>>ch;

                         switch(ch){
                            case 'y': system("CLS");
                                      ReasonEntry(2);
                                      break;

                            case 'n': cout<<"Okay"<<endl;
                                      break;


                         }
                       // break;

                    }while(flag && ch!='n');





                }

                void Travel(){
                    cout<<"This is travel"<<endl;

                    int flag =1;
                    char ch;


                      do{
                         cout<<"You wish to enter to the log (y/n)"<<endl;
                         cin>>ch;

                         switch(ch){
                            case 'y': system("CLS");
                                      ReasonEntry(3);
                                      break;

                            case 'n': cout<<"Okay"<<endl;
                                      break;


                         }
                       // break;

                    }while(flag && ch!='n');





                }

                void Extras(){
                    cout<<"This is extras"<<endl;

                    int flag =1;
                    char ch;



                      do{
                         cout<<"You wish to enter to the log (y/n)"<<endl;
                         cin>>ch;

                         switch(ch){
                            case 'y': system("CLS");
                                      ReasonEntry(4);
                                      break;

                            case 'n': cout<<"Okay"<<endl;
                                      break;


                         }
                       // break;

                    }while(flag && ch!='n');



                }


