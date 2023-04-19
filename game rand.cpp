#include <iostream>
#include <cstdlib>
#include <time.h>

/*Gierka z wykorzystaniem losowych liczb i OOP*/

using namespace std;

class Game {
    private:
        int liczba;
        int i;
        int odp;

    public:
        void granie()
        {
            do
            {
                cin >> odp;
                if (odp < liczba)
                {
                    cout << "liczba jest wieksza!" << endl;
                    i++;
                    odp = 0;
                }
                if (odp > liczba)
                {
                    cout << "Liczba jest mniejsza!" << endl;
                    i++;
                    odp = 0;
                }
                if (odp == liczba)
                {
                    cout << "!!! Wygrales !!!" << endl << "Liczba strzalow:  " << i << endl;
                }

            } while (!(liczba == odp));
        }
        
        Game(int x) //Konstruktor
        {
            liczba = x;
            i = 0;
            granie();
        }
};

int main()
{
    srand(time(NULL));
    int liczba = ((rand() % 1000) + 1);
    Game g1(liczba);
    return 0;
}