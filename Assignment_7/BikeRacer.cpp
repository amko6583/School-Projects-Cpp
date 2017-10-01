//Amanda Koziol
//Homework 7
//Recitation 109
//TA Michael Luzzolino

#include <iostream>
#include <fstream>
#include "BikeRacer.h"
using namespace std;

Racer::Racer(){
	cout << "Enter the mass of the rider :" <<endl;
	cin >> M;
	cout << "Enter the mass of the bike: "  <<endl;
	cin >> Mb;
	cout << "Enter the velocity in m/s: " <<endl;
	cin >> velocity;
	cout << "Enter the coefficient of drafting: " <<endl;
	cin >> K;
	cout << endl;

}

//Gets and set the mass of the bike
int Racer::getBikeMass(){
	return Mb;
}
void Racer::setBikeMass(int Mb){
	Mb = Mb;
}
		
//Gets and sets the coefficienent of friction due to the road
int Racer::getBikeCR(){

	return cr1;
}
void Racer::setBikeCR(int cr1){
	cr1 = cr1;
}


//Gets and sets the Mass of the bike rider
int Racer::getRiderMass(){
	return M;
}
void Racer::setRiderMass(int M){
	M = M;
}


//Gets and sets the coefficient related to drafting
int Racer::getCDraft(){
	return CDraft;
}
void Racer::setCDraft(int CDraft){
	cf = CDraft;
}


//Gets and sets the coefficient related to rider position
int Racer::getK(){
	return K;
}
void Racer::setK(int K){
	k = K;
}


//Gets and sets the velocity in m/s
int Racer::getVelocity(){
	return velocity;
}
void Racer::setVelocity(int velocity){
	v = velocity;

}

//This is using the values from the previous functions to find 
//the total power needed to overcome air and road resistance
float Racer::Power(){
	Power1 = (k * cf * v * v * v) +  (cr1 * g * v) * (M + Mb);
	return Power1;
}

//uses distance to find the energy to travel a given distance
float Racer::TotalEnergy(float distance){
	float TotalEnergy = Power1*(distance*1000)/v;	
	return TotalEnergy;

}

