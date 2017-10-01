#include <iostream>
#include <string>
using namespace std;
//Amanda Koziol
//Secion 109
//TA Michael Luzzolinio

//Part A
float p_air(float cf, float v)
{
    float k;                //The coefficient related to rider position
    float air;
    k = 0.18;
    air = k*cf*v*v*v;       //finding the Power to overcome air resistance
}

float proll(float M, float Mb)
{
    float g;                //Gravitation constant
    float v;                //velocity in the m/s
    float cr;
    float roll;             //Coefficient related to rider position
    cr = 0.001;
    g = 9.8;                //gravitation constant
    roll = (cr*g*v)*(M+Mb); //Finding the power needed to exceed roll
}

int printing_a(float v, float cf, float M, float Mb)
{
    float air;
    float roll;
    float total;
    float cf_set;
    air = p_air(cf, v);     //runs the user input through p_air to exceed air resistance
    roll = proll(M, Mb);    //runs the user input throughp roll to exceed roll resistance
    total = air + roll;     //total power needed
    cout <<total <<"W"<<endl;   //prints answer

    cf_set = 0.3;
    while (cf_set <=1.0)    //Finds the power needed for different Cf coefficients between 0.3 and 1
    {

        p_air(cf_set, v);
        int total_set;
        air = p_air(cf_set, v);
        roll = proll(M, Mb);
        total_set = air + roll;
        cf_set = cf_set + 0.1;
        cout <<total_set <<"W"<<endl;


    }
}
//Part B

float timeTravel (float v, float distance)  //calculates the time based on distance traveled
{
    float time;
    time = (distance*1000)/v;
}

//This function calculates and prints outthe total power and energy needed
float printing_b (float v, float cf, float M, float Mb, float distance)
{
    int energy;
    float air;
    float roll;
    float total;
    float cf_set;
    air = p_air(cf, v);
    roll = proll(M, Mb);
    total = air + roll;                  //This value is based on the users input
    energy = total*timeTravel(v, distance);
    cout << total <<"W"<<"total energy for" <<distance<<"K="<<energy <<endl;

    cf_set = 0.1;
    while (cf_set <=1.0)                //This loop is finding the total power and energy using Cf values from .0 to 1
    {

        int total_set;
        p_air(cf_set, v);
        air = p_air(cf_set, v);
        roll = proll(M, Mb);
        total_set = air + roll;
        cf_set = cf_set + 0.1;
        energy = total_set*timeTravel(v, distance);
        cout << total_set <<"W"<<" total energy forv" <<distance<<"K = "<<energy <<endl;
    }

}

int main()
{
    float M;
    float Mb;
    float v;
    float cf;
    float distance;
    int total;
    int energy;
    //Asking user for inputs
    cout << "Mass of the rider: " << endl;
    cin >> M;
    cout << "Mass of the bike:" <<endl;
    cin >> Mb;
    cout << "Velocity: " << endl;
    cin >> v;
    cout << "Draft coefficient:" <<endl;
    cin >> cf;
    printing_a(v, cf, M, Mb);               //This is printing all of part a
    
    cout << "Distance in km:" <<endl;
    cin >> distance;
    printing_b(v, cf, M, Mb, distance);




}
