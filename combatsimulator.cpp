#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;
int main(){

    default_random_engine randomGenerator(time(NULL));
    uniform_real_distribution<int> attack(0, 100);

    //duck properties
    int duckSoldier;
    int nDuckSoldier;
    int duckAttack = 60;
    int duckSoldierHealt = 100;
    int currentDuckSoldierHealt = duckSoldierHealt;
   
    //bee properties
    int beeSoldier;
    int nBeeSoldier;
    int beeAttack = 4 ;
    int beeSoldierHealt = 50;
    int currentBeeSoldierHealt = beeSoldierHealt;

    int attackResult;    
    char turn = 'D';

    cout<< "Have you how many duck soldier\n";
    cin>>duckSoldier;
    nDuckSoldier = duckSoldier;

    cout<< "Have you how many bee soldier\n";
    cin>>beeSoldier;
    nBeeSoldier = beeSoldier;
    

    while(duckSoldier > 0 && beeSoldier > 0){
        attackResult = attack(randomGenerator);


        if(turn == 'D'){

            if(attackResult <= duckAttack){
                currentBeeSoldierHealt -= duckAttack;

                    if(currentBeeSoldierHealt < 0){
                        beeSoldier--;
                        currentBeeSoldierHealt = beeSoldierHealt;
                    }
            }
            turn = 'B';
        }else{
            if(attackResult <= beeAttack){
                currentDuckSoldierHealt -= beeAttack;

                    if(currentDuckSoldierHealt < 0){
                        duckSoldier--;
                        currentDuckSoldierHealt = duckSoldierHealt;
                    }
            }
            turn = 'D';

        }
    }


    if(duckSoldier > 0){
        cout<<"Ducks win this match\n";
        cout<<"Remaining Number " << duckSoldier <<endl;
    }else{
        cout<<"bee win this match\n";
        cout<<"Remaining Number " << beeSoldier <<endl;
    }


    cout<< nBeeSoldier - beeSoldier << " bee and " <<  nDuckSoldier - duckSoldier  << " duck was die. .";

    return 0;
}