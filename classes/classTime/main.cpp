#include <iostream>
#include "time.h"

/*bool IsAfternoonTime(const chron::Time& time){
	
	return time.GetHours() >= 12;	
}*/


int main (){
	chron::Time t1(10 , 18 , -5);
	chron::Time t2;
	chron::Time t3(586743);
	chron::Time t4;
	
	std::cin>>t4;
	std::cout<<t4<<"\n";
	
	/*if(IsAfternoonTime(t)){
		std::cout<<t.GetHours() - 12<< " PM\n";
	}*/
	std::cout<<t1.GetHours()<<":";
	std::cout<<t1.GetMinutes()<<":";
	std::cout<<t1.GetSeconds()<<" ";
	std::cout<<t1.TotalSeconds()<<"\n";
	
	
	
	t2.AddSeconds(553);
	std::cout<<t2.GetHours()<<":";
	std::cout<<t2.GetMinutes()<<":";
	std::cout<<t2.GetSeconds()<<" ";
	std::cout<<t2.TotalSeconds()<<"\n";
	
	
	
	std::cout<<t3.GetHours()<<":";
	std::cout<<t3.GetMinutes()<<":";
	std::cout<<t3.GetSeconds()<<" ";
	std::cout<<t3.TotalSeconds()<<"\n";

	
	std::cout<<t2 - t1<<"\n";
	
	
}
