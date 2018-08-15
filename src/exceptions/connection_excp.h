#ifndef CONNECTION_EXCEPTION_H
#define CONNECTION_EXCEPTION_H

#include <exception>
#include<string>
#include<iostream>


/*
 
    Class for signalizing problems with 
    connection
 
*/


class connection_exception: public std::exception{

   std::string message;

public:
   connection_exception( std::string msg="Connection excpetion"):message(msg){}

   const char * what() const throw(){ return (char *)message.c_str(); }

   friend std::ostream& operator<<( std::ostream& os, connection_exception const conn_excpt ){
        os << conn_excpt.message;
        return os;
   }


};



#endif






