//Amanda Koziol
//Homework 7
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include "BikeRacer.h"
using namespace std;

//Gets and set the mass of the bike
int Racer::getBikeMass(){
	cin << Mass << endl;
	return Mass;
}
void Racer::setBikeMass(int Mass){
	Mb = Mass;
}
		
//Gets and sets the coefficienent of friction due to the road
int Racer::getBikeCR(){
	cin << Cr1 <<endl;
	return Cr1;
}
void Racer::setBikeCR(int Cr1){
	Cr = Cr1;
}


//Gets and sets the Mass of the bike rider
int Racer::getRiderMass(){
	cin << Mass<<endl;
	return Mass;
}
void Racer::setRiderMass(int Mass){
	M = Mass;
}


//Gets and sets the coefficient related to drafting
int Racer::getCDraft(){
	cin << CDraft << endl;
	return CDraft;
}
void Racer::setCDraft(int CDraft){
	cf = CDraft;
}


//Gets and sets the coefficient related to rider position
int Racer::getK(){
	int K;
	cin << K << endl;
	return K;
}
void Racer::setK(int K){
	k = K;
}


//Gets and sets the velocity in m/s
int Racer::getVelocity(){
	cin << velocity << endl;
	return velocity;
}
void Racer::setVelocity(int velocity){
	v = velocity;

}

//This is using the values from the previous functions to find 
//the total power needed to overcome air and road resistance
float Racer::Power(){
	float Power = (k * cf * v * v * v) +  (cr * g * v) * (M + Mb);
	return Power;
}

//uses distance to find the energy to travel a given distance
float Racer::TotalEnergy(float distance){
	Power();
	float TotalEnergy = Power*(distance*1000)/v;	
	return TotalEnergy;

}

