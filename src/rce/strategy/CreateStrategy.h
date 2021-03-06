#ifndef CREATESTRATEGY_H
#define CREATESTRATEGY_H

#include "../log/enums/RiskLevel.h"
#include "../log/enums/WeatherConditions.h"
#include <iostream>
#include <string>
#include "../pr/Doc.h"
namespace rce {
    class CreateStrategy {

    private:

        lg::RiskLevel riskLevel;

        int *tyres = new int[3];// 3 compounds in pairs and a wet compound [soft,meduim,hard]//only 5 pairs per weekend
        int Pitstops;//added
        std::string StratName;
    public:
        virtual CreateStrategy *execute() = 0;

        virtual ~CreateStrategy();

        CreateStrategy();

        void SetRiskLevel(lg::RiskLevel rl);

        void SetTyres(int *t);

        void SetPitstops(int p);

        void SetStratName(std::string s);

        lg::RiskLevel getRiskLevel();

        int *getTyres();

        int getPitstops();

        std::string getStratName();

//        virtual ~CreateStrategy();
        // need some getters or make some of the members public
    };
}
#endif
