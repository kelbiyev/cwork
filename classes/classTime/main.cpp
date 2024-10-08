#include <iostream>
#include "time.h"

bool IsAfternoonTime(const chron::Time& time){
	
	return time.GetHours() >= 12;	
}


int main (){
	chron::Time t(13 , 30 , 0);\
	if(IsAfternoonTime(t)){
		std::cout<<t.GetHours() - 12<< " PM\n";
	}
	std::cout<<"Hours"<<t.GetHours()<<"\n";
	std::cout<<"Minutes"<<t.GetMinutes()<<"\n";
	std::cout<<"Seconds"<<t.GetSeconds()<<"\n";

}
