#include <iostream>

using namespace std;

class Israel;

class India
{
private:
    string Brahmos_missile_key;
    string Tejas_missile_key;
    string Rafale_key;

public:
    India()
    {
        Brahmos_missile_key = "MSXXXXRO20";
        Tejas_missile_key = "TJXXX25";
        Rafale_key = "@#$XXXX73K";
    }
    friend bool check_with_Russia();

};

bool check_with_Russia()
{
    India attack;
    cout << "India indegenious in Launching Tejas Key as " << attack.Tejas_missile_key  << " ------> "<< endl;
    cout << "India indegenious  in Launching Brahmos Key as " << attack.Brahmos_missile_key << " ------> " << endl;
    cout << "Russia help in Launching Rafael Key as " << attack.Rafale_key << " ------> " << endl;
    cout << "Russia Drone Ultra Efficient Key as " << 249040 << " ------> " << endl;
    return true;
}


int main()
{
    cout << "##################################  India Attacks Terrorism  ##################################  " << endl;
    India attack;
    

    cout << "##################################  Friend Function check with Russia ##################################  " << endl;
    check_with_Russia();
    
    return 0;
}

/*

##################################  India Attacks Terrorism  ##################################  
##################################  Friend Function check with Russia ##################################  
India indegenious in Launching Tejas Key as TJXXX25 ------> 
India indegenious  in Launching Brahmos Key as MSXXXXRO20 ------> 
Russia help in Launching Rafael Key as @#$XXXX73K ------> 
Russia Drone Ultra Efficient Key as 249040 ------> 

*/
