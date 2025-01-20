#include "Client.h"

void Client::setClientID(){
   this->clientID = randomClientID();
}

void Client::setPTR(){
  // this->ptr = std::make_unique <BankAccount>();
}

int Client::getClientID(){
   return clientID; 
}

Client::Client(){}
Client::~Client(){}