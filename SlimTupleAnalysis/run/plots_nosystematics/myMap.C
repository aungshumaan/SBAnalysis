#include  <map>
#include <string>
#include <iostream>

void myMap(){
  std::map< std::string, std::string > m ;
  m["name1"] = "data1";
  m["name2"] = "data2";
  

  typedef std::map<std::string, std::string >::iterator it_type;
  for(it_type iterator = m.begin(); iterator != m.end(); iterator++) {
    // iterator->first = key
    // iterator->second = value
    // Repeat if you also want to iterate through the second map.
    std::cout<<"Inside the map "<<std::endl;
  }
  


}


int main(void)
{
  std::cout << "Hello! This is a C++ program.\n";
  //myMap;

  std::map< std::string, std::string > m ;
  m["name1"] = "data1";
  m["name2"] = "data2";
  

  typedef std::map<std::string, std::string >::iterator it_type;
  for(it_type iterator = m.begin(); iterator != m.end(); iterator++) {
    std::cout<< iterator->first <<std::endl;
    std::cout<< iterator->second <<std::endl;
    // iterator->second = value
    // Repeat if you also want to iterate through the second map.
    std::cout<<"Inside the map "<<std::endl;
  }
  
  
  return 0;
}
