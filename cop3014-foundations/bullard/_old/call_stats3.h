//#include <iostream>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//class call_record
//{
//public:
//    string cell_number;
//    int relays;
//    int call_length;
//    double net_cost;
//    double tax_rate;
//    double call_tax;
//    double total_cost;
//};
//
//void Input(ifstream &, call_record &);
//void Output(ofstream &, const call_record &);
//void Process(call_record &);
//
////Name: Input
////Precondition: the varialbes (formal parameters) have not been initialized.
////the varaibles (formal parameters) have been initialized.
////Get input (ifstream & in, call_record & customer_record)
//void Input(ifstream & in, call_record & customer_record)
//{
//    in>>customer_record.cell_number;
//    in>>customer_record.relays;
//    in>>customer_record.call_length;   
//}
//
//
////Name:Output
////Precondition: State what is true before the function is called.
////Postcondition: State what is true after the function has executed.
////Description: Get output(ofstream & const call_record & customer_record)
//void Output(ofstream & out, const call_record & customer_record)
//{
//    cout.setf(ios::showpoint);
//    cout.precision(2);
//    cout.setf(ios::fixed);
//    /********************************************/
//	out << customer_record.cell_number << "\t" << customer_record.relays << "\t" <<
//		customer_record.call_length << "\t" << customer_record.net_cost << "\t" <<
//		customer_record.tax_rate << "\t" << customer_record.call_tax << "\t" <<
//		customer_record.total_cost << endl;
//}
//
////Name: Process
////Precondition: The state what is true before the function is called.
////Postcondition: State what is true after the function has executed.
////Description:  Get process(call_tax,net_cost,total_cost_of_call).
//void Process(call_record & customer_record)
//{
//    
//    if (customer_record.relays<= 1 && customer_record.relays <=5 )
//    {
//        customer_record.tax_rate = .01;
//    }
//    if (customer_record.relays<= 6 && customer_record.relays <=11 )
//    {
//        customer_record.tax_rate = .03;
//    }
//    if (customer_record.relays<= 12 && customer_record.relays <=20 )
//    {
//        customer_record.tax_rate = .05;
//    }
//    if (customer_record.relays<= 21 && customer_record.relays <=50 )
//    {
//        customer_record.tax_rate = .08;
//    }
//    else
//    {
//        customer_record.tax_rate = .12;
//    }
//
//    customer_record.net_cost = customer_record.relays / 50.0 * .40 * customer_record.call_length;
//    customer_record.call_tax =   customer_record.net_cost * customer_record.tax_rate;
//    customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;
//}
//
//
//int call_stats3()
//{
//    
//    call_record customer_record;    
//    
//	ifstream in;    //declaring an input file stream
//    in.open("call_data.txt");    
//	if (in.fail())
//    {
//        cout<<"Input file did not open correctly"<<endl;
//		exit(1);
//    }
//	
//	
//	ofstream out;   //declaring an output file stream
//	out.open("weekly_call_info.txt");
//	if (out.fail())
//	{
//		cout << "output file did not open correcly" << endl;
//		exit(1);
//	}
//    
//    while (!in.eof())
//    {
//        Input(in,customer_record);
//        Process(customer_record);
//        Output(out, customer_record);
//    }
//
//    in.close();
//	out.close();
//    
//    return 0;
//}
