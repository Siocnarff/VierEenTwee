#ifndef CREATESTRATEGY_H
#define CREATESTRATEGY_H

#include <iostream>
#include <string>

namespace rce {
    class CreateStrategy {

    private:
        int risklevel;
        int *tyres = new int[3];// 3 compounds in pairs and a wet compound [soft,meduim,hard]//only 5 pairs per weekend
        int Pitstops;//added
        std::string StratName;
    public:
        virtual CreateStrategy *execute() = 0;

        CreateStrategy();

        void SetRiskLevel(int rl);

        void SetTyres(int *t);

        void SetPitstops(int p);

        void SetStratName(std::string s);

        int getRiskLevel();

        int *getTyres();

        int getPitstops();

        std::string getStratName();
        // need some getters or make some of the members public
    };
}
#endif