#include <iostream>

using namespace std;

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
    friend class Israel;
};

class Israel
{
    string S400_missile_key;
public:
    Israel()
    {
        S400_missile_key = "LXTYUIN77";
    }
    void Launch_All_Missile_to_Enemy(India attack)
    {
        cout << "Launching Tejas Key as " << attack.Tejas_missile_key  << " ------> "<< endl;
        cout << "Launching Brahmos Key as " << attack.Brahmos_missile_key << " ------> " << endl;
        cout << "Launching Rafael Key as " << attack.Rafale_key << " ------> " << endl;
        cout << "Launching S400 Defence Key as " << S400_missile_key << " ------> " << endl;
    }
};

int main()
{
    cout << "India Attacks Terrorism" << endl;
    India attack;
    Israel Is;
    Is.Launch_All_Missile_to_Enemy(attack);

    return 0;
}
